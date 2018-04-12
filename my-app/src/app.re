[%bs.raw {|require('./css/app.css')|}];

[%bs.raw {|require('./css/panels.css')|}];

[%bs.raw {|require('semantic-ui-css/semantic.min.css')|}];

[%bs.raw {|require('./css/ui.css')|}];

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

/* Initiallizing the Golden Layout */
let config =
  GoldenLayout.(
    make_config([|
      make_row(
        "main",
        [|
          make_react_component(
            "ace",
            [],
            [
              ("file", Js.Json.string("POUET1")),
              ("value", Js.Json.string("Contenu Pouet 1")),
            ],
          ),
          make_react_component("log", [], []),
        |],
      ),
    |])
  );

let glSavedState =
  Dom.Storage.getItem("glSavedState", Dom.Storage.localStorage);

/* If the state of the layout is saved in local storage we resume it */
let glayout =
  switch (glSavedState) {
  | None =>
    Js.log("newconf");
    GoldenLayout.create_gl(config, "#gl_container");
  | Some(state) =>
    Js.log("fromLSconf");
    GoldenLayout.create_gl(Js.Json.parseExn(state), "#gl_container");
  };

let make = (~message, _children) => {
  ...component,
  didMount: self => {
    /** Here we initialize the GoldenLayout
      */
    GoldenLayout.registerComponent(glayout, "ace", Editor.default);
    GoldenLayout.registerComponent(glayout, "log", Log.default);
    GoldenLayout.init(glayout);
    ReasonReact.NoUpdate;
  },
  render: _self =>
    <div id="app">
      <Toolbar brand=message glayout />
      <div id="gl_container" />
    </div>,
};

%raw
{| window.glayout = glayout;
|};

/* TODO : un-dirty the following... */
%raw
{|glayout.on('initialised',
	    () => window.addEventListener('resize',
					  () => glayout.updateSize()
					 )
     )|};

%raw
{|glayout.on( 'stateChanged', function(){
    if(glayout.isInitialised
        && (glayout.openPopouts.every(function(popout) { return popout.isInitialised })))   {
        var state = JSON.stringify( glayout.toConfig() );
        localStorage.setItem( 'glSavedState', state );
  }

  });
|};