type action = unit;

let editor: ref(option(MonacoEditor.IStandaloneCodeEditor.t)) = ref(None);

let component = ReasonReact.statelessComponent("Monaco");

let handleClick = (_event, _self) => Js.log("clickedtoto!");

let make = (~file: File.t, ~onChange, _children) => {
  ...component,
  didMount: _self => {
    /* Here we initialize the Monaco editor */
    editor :=
      (
        switch (ReactDOMRe._getElementById("monaco")) {
        | Some(elt) =>
          open MonacoEditor;
          let mon = getMonaco();
          mon##languages |. register({"id": "lprolog"});
          mon##languages
          |. setMonarchTokensProvider(
               "lprolog",
               BaseJs.requireAs("./monarch/lprolog.js"),
             )
          |. ignore;
          let editor =
            mon##editor
            |. create(
                 elt,
                 {
                   "value": file.content,
                   "language": "lprolog",
                   "theme": "vs-dark",
                   "automaticLayout": true,
                 },
               );
          /*editor
            |. IStandaloneCodeEditor.onDidChangeModelContent(e =>
                 if (! Js.to_bool(e##isFlush)) {
                   onChange(editor |. IStandaloneCodeEditor.getValue());
                 }
               )
            |. ignore;*/
          Some(editor);
        | None => None
        }
      );
    ReasonReact.NoUpdate;
  },
  /*didUpdate: ({oldSelf, newSelf}) =>
    switch (editor^) {
    | None => ()
    | Some(e) => e |. MonacoEditor.IStandaloneCodeEditor.setValue(value)
    },*/
  render: self =>
    <div
      id="monaco"
      style=(ReactDOMRe.Style.make(~height="100%", ~overflow="hidden", ()))
    />,
};