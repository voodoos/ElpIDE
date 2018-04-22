type state = {value: string,
  editorRef: ref(option(ReasonReact.reactRef))};

type action =
  | Change(string);


module State = {
  type t = {.
    "name": string,
    "content": string,
  };
  let initialState = {
    {
      "name": "test.elpi",
      "content": "world \"hello\".\nworld \"pussycat\"."
    };
  };
};


/* This is the basic component. */
let component = ReasonReact.reducerComponent("Editor");

let handleClick = (_event, _self) => Js.log("clickedtoto!");

let setEditorRef = (theRef, {ReasonReact.state}) => {
  state.editorRef := Js.Nullable.to_opt(theRef);
};


let make = (~file, ~value, _children) => {
  ...component,
  initialState: () => {
    Js.log(value);
    {value: value, editorRef: ref(None)};
  },
  reducer: (action, state) =>
    switch (action) {
    | Change(newVal) => ReasonReact.Update({...state, value: newVal})
    },
  didUpdate: ({oldSelf, newSelf}) => { 
    /* We need to resize the editor when the layout is changed */
  Js.log("editor render3");
  switch (newSelf.state.editorRef^) {
    | None => ()
    | Some(r) => ReasonReact.refToJsObj(r)##editor##resize() /* Unsafe magic*/
    }
  },
  render: self => {
    <AceEditor
      ref={self.handle(setEditorRef)}
      onChange=(v => self.send(Change(v)))
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
    />},
};

/* We need a way to give this component to goldenlayout : 
let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~file=jsProps##file, ~value=jsProps##value, ~value=jsProps##value, [||])
  );*/