type state = {value: string};

type action = Change(string);

/* This is the basic component. */
let component = ReasonReact.reducerComponent("Editor");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clickedtoto!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (~file, ~value, _children) => {
  ...component,

  initialState: () => { Js.log(value); {value: value} },

  reducer: (action, state) =>
    switch (action) {
    | Change(newVal) => ReasonReact.Update({ value: newVal })
    },

    render: self =>
    <AceEditor
      mode="ocaml"
      theme="monokai"
      name=file
      width="100%"
      height="100%"
      value=self.state.value
      setOptions=Js.Json.(
                   object_(
                     Js_dict.fromList([
                       ("enableBasicAutocompletion", boolean(Js.true_)),
                       ("enableLiveAutocompletion", boolean(Js.true_)),
                       ("enableSnippets", boolean(Js.false_)),
                       ("showLineNumbers", boolean(Js.true_)),
                       ("tabSize", number(4.)),
                     ]),
                   )
                 )
      /*
       onChange={(n) => this.valChanged(n)}}*/
    />,
};

/* We need a way to give this component to goldenlayout : */
let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~file=jsProps##file,
         ~value=jsProps##value, [||])
  );