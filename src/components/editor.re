type state = {editorRef: ref(option(ReasonReact.reactRef))};

type action = unit;

module State = {
  type t = {
    .
    "name": string,
    "content": string,
  };
  let initialState = {
    "name": "test.elpi",
    "content": {|kind nat type.
type z nat.
type s nat -> nat.

type plus nat -> nat -> nat -> prop.

plus z M M.
plus (s N) M (s P) :- plus N M P.

% Hello world
world "hello".
world "pussycat".|},
  };
  let newFile = (name) =>
    {
      "name": name,
      "content": "% File " ++ name ++ "\n"
    }
};

/* This is the basic component. */
let component = ReasonReact.reducerComponent("Editor");

let handleClick = (_event, _self) => Js.log("clickedtoto!");

let setEditorRef = (theRef, {ReasonReact.state}) =>
  state.editorRef := Js.Nullable.toOption(theRef);

let make = (~file, ~value, ~onChange, _children) => {
  ...component,
  initialState: () => {editorRef: ref(None)},
  reducer: ((), _s) => ReasonReact.NoUpdate,
  didUpdate: ({oldSelf, newSelf}) =>
    /* We need to resize the editor when the layout is changed */
    switch (newSelf.state.editorRef^) {
    | None => ()
    | Some(r) => ReasonReact.refToJsObj(r)##editor##resize() /* Unsafe magic*/
    },
  render: self =>
    <AceEditor
      ref=(self.handle(setEditorRef))
      onChange
      mode="prolog"
      theme="monokai"
      name=file
      width="100%"
      height="100%"
      value
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
    />,
};
/* We need a way to give this component to goldenlayout :
   let default =
     ReasonReact.wrapReasonForJs(~component, jsProps =>
       make(~file=jsProps##file, ~value=jsProps##value, ~value=jsProps##value, [||])
     );*/