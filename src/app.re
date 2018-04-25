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
  editors: array(Editor.State.t),
};

type action =
  | LayoutChange
  | SetElpi(ElpiJs.elpi)
  | LogMessage(Log.message)
  | NewAnswer(Log.message)
  | ChangeEditorValue(int, string);

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  /** Callback used when the "run" button is pressed
   *  It asks Elpi to compile all the files.
   */
  let clickPlay = (_event, self) =>
    switch (self.ReasonReact.state.elpi) {
    | Some(e) => e##compile(self.ReasonReact.state.editors)
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
      editors: [|Editor.State.initialState|],
      answers: [||],
      elpi: None,
    },
    reducer: (action, state) =>
      switch (action) {
      | LayoutChange =>
        ReasonReact.Update({...state, layout_update: state.layout_update + 1})
      | SetElpi(e) => ReasonReact.Update({...state, elpi: Some(e)})
      | LogMessage(message) =>
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
        let copy = Array.copy(state.editors);
        copy[id] = {"name": copy[id]##name, "content": content};
        ReasonReact.Update({...state, editors: copy});
      },
    didMount: self => {
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
              LogMessage(
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
              LogMessage(
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
              self.send(LogMessage(Log.message(Info, [], "totoro")));
            }
          )>
          <Pane initialSize="200px">
            SemanticUi.(
              <List>
                <List.Item>
                  <List.Icon name="folder" />
                  <List.Content>
                    <List.Header> "src" </List.Header>
                    <List.Description>
                      "Source files for project"
                    </List.Description>
                    <List.List>
                      <List.Item>
                        <List.Icon name="file" />
                        <List.Content>
                          <List.Header> "test.elpi" </List.Header>
                          <List.Description>
                            "Elpi source file"
                          </List.Description>
                        </List.Content>
                      </List.Item>
                    </List.List>
                  </List.Content>
                </List.Item>
              </List>
            )
          </Pane>
          <SplitPane
            className="right-split"
            split=`horizontal
            onDragFinished=(() => self.send(LayoutChange))>
            <Pane>
              <Editor
                file=self.state.editors[0]##name
                value=self.state.editors[0]##content
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