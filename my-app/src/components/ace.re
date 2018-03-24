/* This is the basic component. */
let component = ReasonReact.statelessComponent("Ace");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clickedtoto!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (~message, _children) => {
  ...component,
  render: self =>
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
    /> ,
};

/* We need a way to give this component to goldenlayout : */
let default =
  ReasonReact.wrapReasonForJs(
  ~component,
  (jsProps) => make(~message=jsProps##message,
                    [||])
);
