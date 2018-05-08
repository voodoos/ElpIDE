[%bs.raw {|require('./css/main.css')|}];

%raw
"var React = require('react')";

%raw
"var ReactDOM = require('react-dom')";

%raw
"window.React = React";

%raw
"window.ReactDOM = ReactDOM";

let zip = Zip.create();

Js.log(zip |. Zip.read(`name("totto")));

module SUI = SemanticUi;

exception ElpiCompileError;

type state = {
  /* The following is a dummy to trigger re-rendering when layout is dragged */
  layout_update: int,
  log: Log.State.t,
  answers: array(Log.message),
  elpi: option(ElpiJs.elpi),
  files: array(Editor.State.t),
  activeFile: int,
  flags: Hashtbl.t(string, bool),
  types: list(ElpiJs.typ),
};

type action =
  | LayoutChange
  | SetActiveFile(int)
  | SetElpi(ElpiJs.elpi)
  | SetFiles(array(Editor.State.t))
  | SetFlag(string, bool)
  | SetTypes(array(ElpiJs.typ))
  | Log(Log.message)
  | NewAnswer(Log.message)
  | NewFile(string)
  | DeleteFile(int)
  | ChangeEditorValue(int, string);

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  /** Callback used when the "run" button is pressed
   *  It asks Elpi to compile all the files.
   */
  let clickPlay = (_event, self) =>
    switch (self.ReasonReact.state.elpi) {
    | Some(e) =>
      e##compile(self.ReasonReact.state.files)
      |> Js.Promise.then_(types => {
           self.send(SetTypes(types));
           self.send(Log(Log.info("Ready")));
           Js.Promise.resolve(types);
         })
      |> Js.Promise.catch(err => {
           let m = Js.Exn.message(ElpiJs.exnOfError(err));
           switch (m) {
           | Some(t) => self.send(Log(Log.err(t)))
           | _ => ()
           };
           self.send(
             Log(
               Log.err(
                 {j|Ook, looks like something went wrong... Here, have a 🍌|j},
               ),
             ),
           );
           Js.Promise.reject(raise(ElpiCompileError));
         })
      |> ignore
    | None => ()
    };
  let clickRestart = (_event, self) => {
    self.ReasonReact.send(SetFlag("elpi_started", false));
    switch (self.state.elpi) {
    | Some(e) =>
      e##restart()
      |> Js.Promise.then_(mess => {
           self.send(SetFlag("elpi_started", true));
           self.send(Log(Log.info("Elpi restarted")));
           Js.Promise.resolve(mess);
         })
      |> ignore
    | None => ()
    };
  };
  let clickSave = (_event, self) => {
    ();
    ();
  };
  let changeEditorValue = (id, content, self) =>
    self.ReasonReact.send(ChangeEditorValue(id, content));
  let keyDown = (event: ReactEventRe.Keyboard.t, _self) =>
    switch (ReactEventRe.Keyboard.keyCode(event)) {
    | _ => ()
    };
  {
    ...component,
    initialState: () => {
      let flags = Hashtbl.create(10);
      Hashtbl.add(flags, "elpi_started", false);
      {
        layout_update: 0,
        log: Log.State.initialState,
        files: [|
          Editor.State.initialState,
          {"name": "test2.elpi", "content": "world \"totoro\"."},
        |],
        activeFile: 0,
        answers: [||],
        elpi: None,
        flags,
        types: [],
      };
    },
    reducer: (action, state) =>
      switch (action) {
      | LayoutChange =>
        ReasonReact.Update({...state, layout_update: state.layout_update + 1})
      | SetFiles(files) => ReasonReact.Update({...state, files})
      | SetActiveFile(activeFile) =>
        ReasonReact.Update({...state, activeFile})
      | SetElpi(e) => ReasonReact.Update({...state, elpi: Some(e)})
      | SetFlag(k, b) =>
        let flags = Hashtbl.copy(state.flags);
        Hashtbl.replace(flags, k, b);
        ReasonReact.Update({...state, flags});
      | SetTypes(types) =>
        ReasonReact.Update({...state, types: Array.to_list(types)})
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
      | NewFile(name) =>
        let files =
          Array.append(state.files, [|Editor.State.newFile(name)|]);
        /* Saving to local storage */
        ignore(LocalForage.setItem("files", files));
        ReasonReact.Update({...state, files});
      | DeleteFile(i) =>
        let l = Array.length(state.files);
        let files =
          if (l > 1) {
            Array.append(
              Array.sub(state.files, 0, i),
              Array.sub(state.files, i + 1, l - i - 1),
            );
          } else {
            state.files;
          };
        let activeFile =
          if (state.activeFile >= Array.length(files)) {
            state.activeFile - 1;
          } else {
            state.activeFile;
          };
        /* Saving to local storage */
        ignore(LocalForage.setItem("files", files));
        ReasonReact.Update({...state, files, activeFile});
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
          /* Log callback */
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
          /* Answers callback */
          argass => self.send(NewAnswer(Querier.answer(argass))),
        );
      elpi##start
      |> Js.Promise.then_(mess => {
           self.send(SetFlag("elpi_started", true));
           self.send(Log(Log.message(Info, [], mess)));
           Js.Promise.resolve(mess);
         })
      |> Js.Promise.catch(_err => {
           self.send(Log(Log.err("Elpi failed to start.")));
           Js.Promise.resolve("arg");
         })
      |> ignore;
      ReasonReact.Update({...self.state, elpi: Some(elpi)});
    },
    render: self =>
      <div id="app" onKeyDown=(self.handle(keyDown))>
        <Toolbar
          brand=message
          onClickPlay=(self.handle(clickPlay))
          onClickRestart=(self.handle(clickRestart))
          onClickSave=(self.handle(clickSave))
          playDisabled=(! Hashtbl.find(self.state.flags, "elpi_started"))
        />
        <SplitPane
          className="main-split"
          split=`vertical
          defaultSize=200
          onDragFinished=(() => self.send(LayoutChange))>
          <Pane initialSize="200px">
            <FileBrowser
              files=self.state.files
              onClickFile=(i => self.send(SetActiveFile(i)))
              onClickNew=(name => self.send(NewFile(name)))
              onDeleteFile=(i => self.send(DeleteFile(i)))
            />
          </Pane>
          <SplitPane
            className="right-split"
            split=`horizontal
            onDragFinished=(() => self.send(LayoutChange))>
            <Pane>
              <Editor
                file=self.state.files[self.state.activeFile]##name
                value=self.state.files[self.state.activeFile]##content
                onChange=(
                  self.handle(changeEditorValue(self.state.activeFile))
                )
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
                  <Querier
                    elpi=self.state.elpi
                    messages=self.state.answers
                    suggestions=self.state.types
                  />
                </Pane>
              </SplitPane>
            </Pane>
          </SplitPane>
        </SplitPane>
      </div>,
  };
};