open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Header";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~_as: string=?, /* TODO: Can also be a function ! */
    ~attached: js=?,
    ~block: Js.boolean=?,
    ~className: string=?,
    ~color: string=?,
    ~content: ReasonReact.reactElement=?,
    ~disabled: Js.boolean=?,
    ~dividing: Js.boolean=?,
    ~floated: string=?,
    ~icon: ReasonReact.reactElement=?,
    ~image: ReasonReact.reactElement=?,
    ~inverted: Js.boolean=?,
    ~size: string=?,
    ~sub: Js.boolean=?,
    /* TODO: subHeader */
    ~textAlign: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?, /* TODO: Can also be a function ! */
      ~attached=?,
      ~block=?,
      ~className=?,
      ~color=?,
      ~content=?,
      ~disabled=?,
      ~dividing=?,
      ~floated=?,
      ~icon=?,
      ~image=?,
      ~inverted=?,
      ~size=?,
      ~sub=?,
      /* TODO: subHeader */
      ~textAlign=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~_as?,
        ~attached=?fromBoolOrTopOrBottom(attached),
        ~block=?fromBool(block),
        ~className?,
        ~color=?fromColor(color),
        ~content?,
        ~disabled=?fromBool(disabled),
        ~dividing=?fromBool(dividing),
        ~floated=?fromLeftOrRight(floated),
        ~icon?,
        ~image?,
        ~inverted=?fromBool(inverted),
        ~size=?fromSizeHeader(size),
        ~sub=?fromBool(sub),
        ~textAlign=?fromTextAlign(textAlign),
        (),
      ),
    children,
  );

module Content = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Header"]
  external react : ReasonReact.reactClass = "Content";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as?, ~className?, ~content?, ()),
      children,
    );
};

module Subheader = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Header"]
  external react : ReasonReact.reactClass = "Subheader";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as?, ~className?, ~content?, ()),
      children,
    );
};