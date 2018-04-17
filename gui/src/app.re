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
};

type action =
  | LayoutChange
  | LogMessage(Log.message);

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  ...component,
  initialState: () => {layout_update: 0, log: Log.State.initialState},
  reducer: (action, state) =>
    switch (action) {
    | LayoutChange =>
      ReasonReact.Update({...state, layout_update: state.layout_update + 1})
    | LogMessage(message) =>
      ReasonReact.Update({
        ...state,
        log: {
          ...state.log,
          messages: Array.append(state.log.messages, [|message|]),
        },
      })
    },
  didMount: _self => ReasonReact.NoUpdate,
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
            self.send(LogMessage(Log.message(Info, "totoro")));
          }
        )>
        <Pane initialSize="200px">
          <Treebeard
            data=(Treebeard.makeNode("root", ~toggled=true, ~children=[| 
            Treebeard.makeNode( "leaf1"),
            Treebeard.makeNode( "leaf2")
              |]))
            
          />
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

            {
              name: "root",
              toggled: Some(true),
              children: [|
                {name: "sub1", toggled: None, children: [||]},
                {name: "sub2", toggled: None, children: [||]},
              |],
            }
            */