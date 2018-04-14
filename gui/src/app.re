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
  layout_update: int
};

type action =
  | LayoutChange
;

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  ...component,
  initialState: () => {
    {
      layout_update: 0
    };
  },
  reducer: (action, state) =>
    switch (action) {
    | LayoutChange =>
      ReasonReact.Update({...state, layout_update: (state.layout_update + 1)}); 
    },
  didMount: _self => ReasonReact.NoUpdate,
  render: self => {
    <div id="app">
      <Toolbar brand=message />
      <SplitPane className="main-split" split=`vertical defaultSize=200  onDragFinished=(() => self.send(LayoutChange))>
        <Pane initialSize="200px">
          (ReasonReact.stringToElement("toto"))
        </Pane>
        <SplitPane className="right-split" split=`horizontal onDragFinished=(() => self.send(LayoutChange))>
          <Pane> <Editor file="Testfile" value="testval" /> </Pane>
          <div> (ReasonReact.stringToElement("titi")) </div>
        </SplitPane>
      </SplitPane>
    </div>},
};