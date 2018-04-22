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

/*
elpi##compile([|{ "name":"toto.elpi", "content":"hello \"world\"." }|]);
elpi##queryAll("hello A.");
*/
[@bs.module] external logo : string = "./logo.svg";

type state = {
  /* The following is a dummy to trigger re-rendering when layout is dragged */
  layout_update: int,
  log: Log.State.t,
  elpi: option(ElpiJs.elpi),
};

type action =
  | LayoutChange
  | SetElpi(ElpiJs.elpi)
  | LogMessage(Log.message);

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  ...component,
  initialState: () => 
    {
      layout_update: 0, 
      log: Log.State.initialState, 
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
    },
  didMount: self => {
    let elpi = ElpiJs.create(
      (l, p, t) => { self.send(LogMessage(
        Log.message(Log.logLevelOfString(l), p, t)
      )) },
      (arg, ass) => { Js.log(arg); Js.log(ass) },
    ); 
    /*self.send(SetElpi(elpi));*/
    ReasonReact.Update({...self.state, elpi: Some(elpi)})
  },
  render: self =>
    <div id="app">
      <Toolbar brand=message />
      <SplitPane
        className="main-split"
        split=`vertical
        defaultSize=200
        onDragFinished=(
          () => {
            self.send(LayoutChange);
            self.send(LogMessage(Log.message(Info, "", "totoro")));
          }
        )>
        <Pane initialSize="200px">
          SemanticUi.(
            <List divided=true relaxed=`True>
              <List.Item>
                <List.Icon name="github" size=`large verticalAlign=`middle />
                <List.Content>
                  <List.Header as_="a">
                    "Semantic-Org/Semantic-UI"
                  </List.Header>
                  <List.Description as_="a">
                    "Updated 10 mins ago"
                  </List.Description>
                </List.Content>
              </List.Item>
              <List.Item>
                <List.Icon name="github" size=`large verticalAlign=`middle />
                <List.Content>
                  <List.Header as_="a">
                    "Semantic-Org/Semantic-UI-Docs"
                  </List.Header>
                  <List.Description as_="a">
                    "Updated 22 mins ago"
                  </List.Description>
                </List.Content>
              </List.Item>
            </List>
          )
        </Pane>
        <SplitPane
          className="right-split"
          split=`horizontal
          onDragFinished=(() => self.send(LayoutChange))>
          <Pane> <Editor file="Testfile" value="testval" /> </Pane>
          <Pane>
            <Log level=self.state.log.level messages=self.state.log.messages />
          </Pane>
        </SplitPane>
      </SplitPane>
    </div>,
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