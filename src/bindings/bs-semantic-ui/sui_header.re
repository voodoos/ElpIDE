open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Header";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~_as: js=?,
    ~attached: js=?,
    ~block: bool=?,
    ~className: string=?,
    ~color: string=?,
    ~content: ReasonReact.reactElement=?,
    ~disabled: bool=?,
    ~dividing: bool=?,
    ~floated: string=?,
    ~icon: ReasonReact.reactElement=?,
    ~image: ReasonReact.reactElement=?,
    ~inverted: bool=?,
    ~size: string=?,
    ~sub: bool=?,
    /* TODO: subHeader */
    ~textAlign: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?,
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
        ~_as=?fromStringOrReactClass(_as),
        ~attached=?fromBoolOrTopOrBottom(attached),
        ~block?,
        ~className?,
        ~color=?fromColor(color),
        ~content?,
        ~disabled?,
        ~dividing?,
        ~floated=?fromLeftOrRight(floated),
        ~icon?,
        ~image?,
        ~inverted?,
        ~size=?fromSizeHeader(size),
        ~sub?,
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
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          (),
        ),
      children,
    );
};

module Subheader = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Header"]
  external react : ReasonReact.reactClass = "Subheader";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          (),
        ),
      children,
    );
};