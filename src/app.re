[%bs.raw {|require('./css/main.css')|}];

%raw
"var React = require('react')";

%raw
"var ReactDOM = require('react-dom')";

%raw
"window.React = React";

%raw
"window.ReactDOM = ReactDOM";

[@bs.module] external logo : string = "./logo.svg";

type state = {
  /* The following is a dummy to trigger re-rendering when layout is dragged */
  layout_update: int,
  log: Log.State.t,
  answers: array(Log.message),
  elpi: option(ElpiJs.elpi),
  files: array(Editor.State.t),
};

type action =
  | LayoutChange
  | SetFiles(array(Editor.State.t))
  | SetElpi(ElpiJs.elpi)
  | Log(Log.message)
  | NewAnswer(Log.message)
  | ChangeEditorValue(int, string);

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  /** Callback used when the "run" button is pressed
   *  It asks Elpi to compile all the files.
   */
  let clickPlay = (_event, self) =>
    switch (self.ReasonReact.state.elpi) {
    | Some(e) => e##compile(self.ReasonReact.state.files)
    | None => ()
    };
  let changeEditorValue = (id, content, self) =>
    self.ReasonReact.send(ChangeEditorValue(id, content));
  let keyDown = (event: ReactEventRe.Keyboard.t, self) =>
    switch (ReactEventRe.Keyboard.keyCode(event)) {
    | _ => ()
    };
  {
    ...component,
    initialState: () => {
      layout_update: 0,
      log: Log.State.initialState,
      files: [|
        Editor.State.initialState,
        {"name": "test2.elpi", "content": "world \"totoro\"."},
      |],
      answers: [||],
      elpi: None,
    },
    reducer: (action, state) =>
      switch (action) {
      | LayoutChange =>
        ReasonReact.Update({...state, layout_update: state.layout_update + 1})
      | SetFiles(files) => ReasonReact.Update({...state, files})
      | SetElpi(e) => ReasonReact.Update({...state, elpi: Some(e)})
      | Log(message) =>
        ReasonReact.Update({
          ...state,
          log: {
            ...state.log,
            messages: Array.append(state.log.messages, [|message|]),
          },
        })
      | NewAnswer(message) =>
        ReasonReact.Update({
          ...state,
          answers: Array.append(state.answers, [|message|]),
        })
      | ChangeEditorValue(id, content) =>
        let copy = Array.copy(state.files);
        copy[id] = {"name": copy[id]##name, "content": content};
        /* Saving to local storage */
        ignore(LocalForage.setItem("files", copy));
        /* Updating state */
        ReasonReact.Update({...state, files: copy});
      },
    didMount: self => {
      /* We load files from local storage if availible */
      Js.Promise.(
        ignore(
          LocalForage.getItem("files")
          |> then_(files => {
               switch (Js.Null.toOption(files)) {
               | None => self.send(Log(Log.info("Starting new session")))
               | Some(f) =>
                 self.send(
                   Log(Log.info("Session restored from local storage")),
                 );
                 self.send(SetFiles(f));
               };
               resolve(files);
             }),
        )
      );
      /* We launch Elpi with appropriate callbacks
       * for logs and answers */
      let elpi =
        ElpiJs.create(
          (l, p, t) => {
            let prefix =
              switch (p) {
              | "" => []
              | "Elpi" => []
              | p => [p]
              };
            self.send(
              Log(
                Log.message(
                  Log.logLevelOfString(l),
                  ["Elpi", ...prefix],
                  t,
                ),
              ),
            );
          },
          argass => self.send(NewAnswer(Querier.answer(argass))),
          (success, mess) =>
            self.send(
              Log(
                if (success) {
                  Log.message(Info, [], "Elpi Worker succesfully started.");
                } else {
                  Log.message(Error, [], "Elpi Worker failed to start.");
                },
              ),
            ),
        );
      ReasonReact.Update({...self.state, elpi: Some(elpi)});
    },
    render: self =>
      <div id="app" onKeyDown=(self.handle(keyDown))>
        <Toolbar brand=message onClickPlay=(self.handle(clickPlay)) />
        <SplitPane
          className="main-split"
          split=`vertical
          defaultSize=200
          onDragFinished=(
            () => {
              self.send(LayoutChange);
              self.send(Log(Log.message(Info, [], "totoro")));
            }
          )>
          <Pane initialSize="200px">
            <FileBrowser files=self.state.files />
          </Pane>
          <SplitPane
            className="right-split"
            split=`horizontal
            onDragFinished=(() => self.send(LayoutChange))>
            <Pane>
              <Editor
                file=self.state.files[0]##name
                value=self.state.files[0]##content
                onChange=(self.handle(changeEditorValue(0)))
              />
            </Pane>
            <Pane>
              <SplitPane
                className="bottom-right-split"
                split=`vertical
                onDragFinished=(() => self.send(LayoutChange))>
                <Pane className="scroll">
                  <Log
                    level=self.state.log.level
                    messages=self.state.log.messages
                  />
                </Pane>
                <Pane className="scroll">
                  <Querier elpi=self.state.elpi messages=self.state.answers />
                </Pane>
              </SplitPane>
            </Pane>
          </SplitPane>
        </SplitPane>
      </div>,
  };
};