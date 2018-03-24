

[@bs.new][@bs.module] external react  :
  unit => unit =
  "react";


[%%raw "var React = require('react')"];
[%%raw "var ReactDOM = require('react-dom')"];
[%%raw "window.React = React"];
[%%raw "window.ReactDOM = ReactDOM"];

/*
[%%raw {|require('golden-layout/dist/goldenlayout.min.js')|}];
[%%raw {|require('golden-layout/src/css/goldenlayout-base.css')|}];
[%%raw {|require('golden-layout/src/css/goldenlayout-dark-theme.css')|}];
*/

/*

var React = require('react');
var ReactDOM = require('react-dom');

window.React = React;
window.ReactDOM = ReactDOM;

*/


/* Initiallizing the Golden Layout */
let config =
  /* We locally open the Js.Json module for convenience */
  Js.Json.(object_(
  Js_dict.fromList(
    [("type", string("row")),
     ("content", array(
      [| object_(
       Js_dict.fromList(
        [("type", string("react-component")),
         ("component", string("ace"))]
        )
       )|]
    ))]
  )
)
);

let glayout = GoldenLayout.create_gl(config, "body");


GoldenLayout.registerComponent(glayout, "ace", Ace.default);

GoldenLayout.init(glayout);


ReactDOMRe.renderToElementWithId(
  <AceEditor
    mode="ocaml" 
    theme="monokai"
    name="test"
    /*
    onChange={(n) => this.valChanged(n)}
    name={ this.props.file}
    width="100%"
    height="100%"
    setOptions={{
  enableBasicAutocompletion: true,
  enableLiveAutocompletion: true,
  enableSnippets: false,
  showLineNumbers: true,
  tabSize: 4,
}}*/
    />, "index1");

ReactDOMRe.renderToElementWithId(<Ace message="bababa" />, "index2");

