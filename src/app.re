module SUI = SemanticUi;

type state = {
  log: Log.State.t,
  answers: array(Log.message),
  files: array(File.t),
  activeFile: int,
  flags: Hashtbl.t(string, bool),
  types: list(ElpiJs.typ),
  appClass: string,
  tour: bool,
  help: bool,
};

type action =
  | SetActiveFile(int)
  | SetFiles(array(File.t))
  | AddFiles(array(File.t))
  | SetFlag(string, bool)
  | SetAppClass(string)
  | StartTour
  | EndTour
  | SetTypes(array(ElpiJs.typ))
  | Log(Log.message)
  | NewAnswer(Log.message)
  | NewFile(string)
  | DeleteFile(int)
  | ChangeEditorValue(int, string)
  | ToggleHelp;

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  /** Callback used when the "run" button is pressed
   *  It asks Elpi to compile all the files.
   */
  let clickPlay = (_event, self) => {
    self.ReasonReact.send(SetFlag("building", true));
    Builder.build(self.ReasonReact.state.files)
    |> Js.Promise.then_(types => {
         self.send(SetTypes(types));
         self.send(SetFlag("building", false));
         self.send(Log(Log.success("Ready")));
         Js.Promise.resolve(types);
       })
    |> Js.Promise.catch(err => {
         self.send(SetFlag("building", false));
         switch (Builder.handleFailure(err)) {
         | Some(s) => self.send(Log(Log.err(s)))
         | _ => ()
         };
         /*
          let m = Js.Exn.message(ElpiJs.exnOfError(err));
          switch (m) {
          | Some(t) => self.send(Log(Log.err(t)))
          | _ => ()
          };*/
         self.send(
           Log(
             Log.err(
               {j|Ook, looks like something went wrong... Here, have a 🍌|j},
             ),
           ),
         );
         Js.Promise.reject(Builder.BuildError(""));
       })
    |> ignore;
  };
  let clickRestart = (_event, self) => {
    self.ReasonReact.send(SetFlag("elpi_started", false));
    Builder.restartElpi()
    |> Js.Promise.then_(mess => {
         self.send(SetFlag("elpi_started", true));
         self.send(Log(Log.success("Elpi restarted")));
         Js.Promise.resolve(mess);
       })
    |> ignore;
  };
  let clickSave = (_event, self) => {
    /* Saving means zipping everything
     * and downloading the zip. */

    open Zip;
    /* Building the zip */
    let zip = create();
    Array.iter(
      (file: File.t) =>
        ignore(zip |. write(file.name, `str(file.content))),
      self.ReasonReact.state.files,
    );
    /* Saving the zip */
    zip
    |. Zip.generateAsyncBlob(Zip.makeAsyncBlobOptions())
    |> Js.Promise.then_(content => {
         FileSaver.saveAs(content, "elpide_project.zip");
         Js.Promise.resolve(content);
       })
    |> ignore;
  };
  let changeEditorValue = (content, self) =>
    self.ReasonReact.send(ChangeEditorValue(self.state.activeFile, content));
  let keyDown = (event: ReactEventRe.Keyboard.t, _self) =>
    switch (ReactEventRe.Keyboard.keyCode(event)) {
    | _ => ()
    };
  {
    ...component,
    initialState: () => {
      let flags = Hashtbl.create(10);
      Hashtbl.add(flags, "elpi_started", false);
      Hashtbl.add(flags, "building", false);
      {
        activeFile: (-1),
        answers: [||],
        appClass: "",
        files: [||],
        flags,
        help: false,
        log: Log.State.initialState,
        tour: false,
        types: [],
      };
    },
    reducer: (action, state) =>
      switch (action) {
      | SetFiles(files) => ReasonReact.Update({...state, files})
      | AddFiles(files) =>
        ReasonReact.Update({
          ...state,
          files: Array.append(state.files, files),
        })
      | SetActiveFile(activeFile) =>
        ReasonReact.Update({...state, activeFile})
      | SetFlag(k, b) =>
        let flags = Hashtbl.copy(state.flags);
        Hashtbl.replace(flags, k, b);
        ReasonReact.Update({...state, flags});
      | SetAppClass(appClass) => ReasonReact.Update({...state, appClass})
      | StartTour => ReasonReact.Update({...state, tour: true})
      | EndTour => ReasonReact.Update({...state, tour: false})
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
        let files = Array.append(state.files, [|File.newFile(name)|]);
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
        copy[id] = {name: copy[id].name, content};
        /* Saving to local storage */
        ignore(LocalForage.setItem("files", copy));
        /* Updating state */
        ReasonReact.Update({...state, files: copy});
      | ToggleHelp => ReasonReact.Update({...state, help: ! state.help})
      },
    didMount: self => {
      File.check_version()
      |> Js.Promise.then_(didReset => {
           /* We load files from local storage if availible */

           open Js.Promise;
           LocalForage.getItem("files")
           |> then_(files => {
                switch (Js.Null.toOption(files)) {
                | None =>
                  self.send(
                    Log(Log.err("Failed to load files from local storage.")),
                  )
                | Some(f) =>
                  self.send(
                    Log(
                      Log.info(
                        if (didReset) {"New session"} else {
                          "Session restored from local storage"
                        },
                      ),
                    ),
                  );
                  self.send(SetFiles(f));
                  self.send(SetActiveFile(0));
                };
                resolve(files);
              })
           |> ignore;
           resolve(didReset);
         })
      |> ignore;
      /* We launch Elpi with appropriate callbacks
       * for logs and answers */
      let logger = (name, l, p, t) => {
        let prefix =
          switch (p) {
          | "" => []
          | p =>
            if (p == name) {
              [];
            } else {
              [p];
            }
          };
        if (Tools.notAlreadyLoadedMess(t)) {
          self.send(
            Log(
              Log.message(Log.logLevelOfString(l), [name, ...prefix], t),
            ),
          );
        };
      };
      let answer = argass => self.send(NewAnswer(Querier.answer(argass)));
      Builder.launch(logger, answer)
      |> Js.Promise.then_(mess => {
           self.send(SetFlag("elpi_started", true));
           self.send(Log(Log.success(mess)));
           Js.Promise.resolve(mess);
         })
      |> Js.Promise.catch(_err => {
           self.send(Log(Log.err("Elpi failed to start.")));
           Js.Promise.resolve("arg");
         })
      |> ignore;
    },
    render: self => {
      let keyMap =
        HotKeys.[
          ("restart", K.simple([M(`command), K("r")])),
          ("restart", K.simple([M(`ctrl), K("r")])),
          ("build", K.simple([M(`command), K("b")])),
          ("build", K.simple([M(`ctrl), K("b")])),
          ("konami", K.konami),
        ];
      let handlers = [
        (
          "restart",
          e => {
            ReactEventRe.Synthetic.preventDefault(e);
            self.handle(clickRestart, e);
          },
        ),
        (
          "build",
          e => {
            ReactEventRe.Synthetic.preventDefault(e);
            self.handle(clickPlay, e);
          },
        ),
        (
          "konami",
          e => {
            ReactEventRe.Synthetic.preventDefault(e);
            self.send(SetAppClass("pyro"));
            BaseJs.setTimeout(() => self.send(SetAppClass("")), 5000);
          },
        ),
      ];
      <HotKeys keyMap handlers>
        <Joyride
          steps=TourSteps.first
          callback=(TourSteps.callback(() => self.send(EndTour)))
          run=self.state.tour
          continuous=true
          showProgress=true
          showSkipButton=true
          spotlightClicks=true
        />
        <div
          id="app"
          onKeyDown=(self.handle(keyDown))
          className=self.state.appClass>
          <div className="before" />
          <Toolbar
            brand=message
            onClickHelp=((_e, _d) => self.send(ToggleHelp))
            onClickPlay=(self.handle(clickPlay))
            onClickRestart=(self.handle(clickRestart))
            onClickSave=(self.handle(clickSave))
            onClickTour=((_e, _d) => self.send(StartTour))
            onLoadFiles=(files => self.send(AddFiles(files)))
            playDisabled=(! Hashtbl.find(self.state.flags, "elpi_started"))
            buildInProgress=(Hashtbl.find(self.state.flags, "building"))
          />
          <SplitPane className="main-split" split=`vertical defaultSize=200>
            <Pane initialSize="200px" className="left-column">
              <FileBrowser
                files=self.state.files
                onClickFile=(i => self.send(SetActiveFile(i)))
                onClickNew=(name => self.send(NewFile(name)))
                onDeleteFile=(i => self.send(DeleteFile(i)))
              />
            </Pane>
            <SplitPane className="right-split" split=`horizontal>
              <Pane className="jr-editor">
                <Monaco
                  file=(
                         if (self.state.activeFile >= 0) {
                           self.state.files[self.state.activeFile];
                         } else {
                           {name: "", content: ""};
                         }
                       )
                  onChange=(self.handle(changeEditorValue))
                />
              </Pane>
              <Pane>
                <SplitPane className="bottom-right-split" split=`vertical>
                  <Pane className="scroll">
                    <Log messages=self.state.log.messages />
                  </Pane>
                  <Pane className="scroll">
                    <Querier
                      messages=self.state.answers
                      suggestions=self.state.types
                    />
                  </Pane>
                </SplitPane>
              </Pane>
            </SplitPane>
            /*size=(
                     if (self.state.help) {
                       "300.0";
                     } else {
                       "0.0";
                     }
              )*/
            <Pane maxSize="300px" minSize="0px" className="help-column">
              (ReasonReact.string("help"))
            </Pane>
          </SplitPane>
          <div className="after" />
        </div>
      </HotKeys>;
    },
  };
};