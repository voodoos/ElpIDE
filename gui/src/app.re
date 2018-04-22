[%bs.raw {|require('./css/app.css')|}];

[%bs.raw {|require('./css/panels.css')|}];

[%bs.raw {|require('semantic-ui-css/semantic.min.css')|}];

[%bs.raw {|require('./css/ui.css')|}];

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
  editors: array(Editor.State.t)
};

type action =
  | LayoutChange
  | SetElpi(ElpiJs.elpi)
  | LogMessage(Log.message)
  | NewAnswer(Log.message);

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {

  /** Callback used when the "run" button is pressed
   *  It asks Elpi to compile all the files.
   */
  let clickPlay = (event, self) => {
    switch self.ReasonReact.state.elpi {
    | Some(e) => {
        e##compile(self.ReasonReact.state.editors);
        e##queryAll("world A.");
      }
    | None => ()
    }
  };

  {
    ...component,
    initialState: () => 
      {
        layout_update: 0, 
        log: Log.State.initialState, 
        editors: [|Editor.State.initialState|],
        answers: [||],
        elpi: None
      } 
    ,
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
      },
    didMount: self => {
      /* We launch Elpi with appropriate callbacks
      * for logs and answers */
      let elpi = ElpiJs.create(
        (l, p, t) => { 
          let prefix = switch p {
            | "" => []
            | "Elpi" => []
            | p => [p]
          };
          self.send(LogMessage( 
          Log.message(Log.logLevelOfString(l), ["Elpi", ...prefix], t)
        )) },
        (argass) => { 
          self.send(NewAnswer(Querier.answer(argass)))
        },
      ); 

      ReasonReact.Update({...self.state, elpi: Some(elpi)})
    },
    render: self =>
      <div id="app">
        <Toolbar brand=message onClickPlay={self.handle(clickPlay)} />
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
                    <List.Header>"src"</List.Header>
                    <List.Description>"Source files for project"</List.Description>
                    <List.List>
                      <List.Item>
                        <List.Icon name="file" />
                        <List.Content>
                          <List.Header>"test.elpi"</List.Header>
                          <List.Description>"Elpi source file"</List.Description>
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
            <Pane> <Editor file=self.state.editors[0]##name 
                          value=self.state.editors[0]##content /> </Pane>
            <Pane>
              <SplitPane
              className="bottom-right-split"
              split=`vertical
              onDragFinished=(() => self.send(LayoutChange))>
                <Pane>
                  <Log level=self.state.log.level messages=self.state.log.messages />
                </Pane>
                <Pane>
                  <Querier messages=self.state.answers />
                </Pane>
              </SplitPane>
            </Pane>
          </SplitPane>
        </SplitPane>
      </div>,
    }
  };
/*

 <Treebeard
   data=(Treebeard.makeNode("root", ~toggled=true, ~children=[|
   Treebeard.makeNode( "leaf1"),
   Treebeard.makeNode( "leaf2")
     |]))
   onToggle=((_n, _t) => Js.log("togllle"))

 />
   {
     name: "root",
     toggled: Some(true),
     children: [|
       {name: "sub1", toggled: None, children: [||]},
       {name: "sub2", toggled: None, children: [||]},
     |],
   }
   */