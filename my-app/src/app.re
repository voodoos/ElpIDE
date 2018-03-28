[%bs.raw {|require('./css/app.css')|}];
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

let make = (~message, _children) => {
  ...component,
  render: _self =>
  SemanticUi.(
    <div id="app">
      <div id="navbar">
        <Menu className="header" inverted=false borderless=true>
          <Menu.Item header=true>
            (ReasonReact.stringToElement(message))
          </Menu.Item>
          <Menu.Item>
            <Button.Group basic=true inverted=false >
              <Button icon=true onClick={ () => Js.log("totoClick") }>
                <Icon name="file outline" />
              </Button>
              <Button icon=true>
                <Icon name="play" />
              </Button>
            </Button.Group>
          </Menu.Item>
        </Menu>
      </div> 
      <div id="gl_container" />
    </div>),
};

/* Initiallizing the Golden Layout */
let config = {
  GoldenLayout.(
    make_config([|
      make_row([|
        make_react_component(
          "ace",
          [],
          [("file", Js.Json.string("POUET1")),
           ("value", Js.Json.string("Contenu Pouet 1"))],
        ),
        make_react_component(
          "ace",
          [],
          [("file", Js.Json.string("POUET2")),
           ("value", Js.Json.string("COntenu Pouet 2"))],
        ),
      |]),
    |])
  )
};

let glSavedState = Dom.Storage.getItem("glSavedState", Dom.Storage.localStorage);

/* If the state of the layout is saved in local storage we resume it */
let glayout = switch glSavedState {
              | None => Js.log("newconf"); GoldenLayout.create_gl(config, "#gl_container");
              | Some(state) => Js.log("fromLSconf");GoldenLayout.create_gl(Js.Json.parseExn(state), "#gl_container");
              };

GoldenLayout.registerComponent(glayout, "ace", Editor.default);

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