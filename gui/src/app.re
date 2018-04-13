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

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  didMount: _self => ReasonReact.NoUpdate,
  render: _self =>
    <div id="app"> <Toolbar brand=message /> <div id="gl_container" /> </div>,
};