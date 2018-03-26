[%bs.raw {|require('./app.css')|}];

%raw
{|require('golden-layout/dist/goldenlayout.min.js')|};

%raw
{|require('golden-layout/src/css/goldenlayout-base.css')|};

%raw
{|require('golden-layout/src/css/goldenlayout-dark-theme.css')|};

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
  render: _self =>
    <div id="app">
      <div id="navbar">
        <h2> (ReasonReact.stringToElement(message)) </h2>
      </div>
      <div id="gl_container" />
    </div>,
};

/* Initiallizing the Golden Layout */
let config =
  /* We locally open the GoldenLayout module for convenience */
  GoldenLayout.(
    make_config([|
      make_row([|
        make_react_component(
          "ace",
          [("value", Js.Json.string("A"))],
          [("file", Js.Json.string("POUET1"))],
        ),
        make_react_component(
          "ace",
          [],
          [("file", Js.Json.string("POUET2"))],
        ),
      |]),
    |])
  );

/*
var myLayout,
    savedState = localStorage.getItem( 'savedState' );

if( savedState !== null ) {
    myLayout = new GoldenLayout( JSON.parse( savedState ) );
} else {
    myLayout = new GoldenLayout( config );
}

*/

let glSavedState = Dom.Storage.getItem("glSavedState", Dom.Storage.localStorage);

let glayout = switch glSavedState {
              | None => Js.log("newconf"); GoldenLayout.create_gl(config, "#gl_container");
              | Some(state) => Js.log("fromLSconf");GoldenLayout.create_gl(Js.Json.parseExn(state), "#gl_container");
              };

GoldenLayout.registerComponent(glayout, "ace", Ace.rjs);

GoldenLayout.init(glayout);

/* TODO : un-dirty the following... */
%raw
{|glayout.on('initialised',
	    () => window.addEventListener('resize',
					  () => glayout.updateSize()
					 )
     )|};
     
%raw
{|glayout.on( 'stateChanged', function(){
      var state = JSON.stringify( glayout.toConfig() );
      localStorage.setItem( 'glSavedState', state );
  });
|}