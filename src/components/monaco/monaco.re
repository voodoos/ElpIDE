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
world "world".|},
  };
  let makeFile = (name, content) => {"name": name, "content": content};
  let newFile = name => {"name": name, "content": "% File " ++ name ++ "\n"};
};

let component = ReasonReact.statelessComponent("Monaco");

let handleClick = (_event, _self) => Js.log("clickedtoto!");

let make = (~file, ~value, ~onChange, _children) => {
  ...component,
  didMount: self => {
    /* Here we initialize the Monaco editor */
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
      mon##editor
      |. create(
           elt,
           {
             "value": value,
             "language": "lprolog",
             "theme": "vs-dark",
             "automaticLayout": true,
           },
         );
    | None => Js.log("Elt not found")
    };
    ReasonReact.NoUpdate;
  },
  render: self =>
    <div
      id="monaco"
      style=(ReactDOMRe.Style.make(~height="100%", ~overflow="hidden", ()))
    />,
};