[%bs.raw {|require('./app.css')|}];


[%%raw {|require('golden-layout/dist/goldenlayout.min.js')|}];
[%%raw {|require('golden-layout/src/css/goldenlayout-base.css')|}];
[%%raw {|require('golden-layout/src/css/goldenlayout-dark-theme.css')|}];

[%%raw "var React = require('react')"];
[%%raw "var ReactDOM = require('react-dom')"];
[%%raw "window.React = React"];
[%%raw "window.ReactDOM = ReactDOM"];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: (_self) =>
    <div id="app">
      <div id="navbar">
        <h2> (ReasonReact.stringToElement(message)) </h2>
      </div>
      <div id="gl_container">
    </div>
  </div>
};




/* Initiallizing the Golden Layout */
let config =
/* We locally open the Js.Json module for convenience */
  Js.Json.(object_(
  Js_dict.fromList(
    [("content", array([| object_(
    Js_dict.fromList(
      [("type", string("row")),
       ("content", array(
        [| object_(
         Js_dict.fromList(
          [("type", string("react-component")),
           ("component", string("ace")),
           ("props", object_(
            Js_dict.fromList(
             [("file", string("POUET1"))]
           )
          ))]
        )
       ),
         object_(
          Js_dict.fromList(
           [("type", string("react-component")),
            ("component", string("ace")),
            ("props", object_(
             Js_dict.fromList(
              [("file", string("POUET2"))]
            )
           ))]
         )
        )|]
      ))]
    ))
                        |]) )]
  )
)
);

let glayout = GoldenLayout.create_gl(config, "#gl_container");


GoldenLayout.registerComponent(glayout, "ace", Ace.rjs);

GoldenLayout.init(glayout);


/* TODO : un-dirty the following... */
[%%raw {|glayout.on('initialised',
	    () => window.addEventListener('resize',
					  () => glayout.updateSize()
					 )
	   )|}];
