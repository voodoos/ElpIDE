open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Sidebar";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~animation: string=?,
    ~_as: js=?,
    ~className: string=?,
    ~content: ReasonReact.reactElement=?,
    ~defaultVisible: Js.boolean=?,
    ~direction: string=?,
    ~icon: string=?,
    ~inverted: Js.boolean=?,
    ~vertical: Js.boolean=?,
    ~visible: Js.boolean=?,
    ~width: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~animation=?,
      ~_as=?,
      ~className=?,
      ~content=?,
      ~defaultVisible=?,
      ~direction=?,
      ~icon=?,
      ~inverted=?,
      ~vertical=?,
      ~visible=?,
      ~width=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=sui,
    ~props=
      makeProps(
        ~animation=?fromSBAnimation(animation),
        ~_as=?fromStringOrReactClass(_as),
        ~className?,
        ~content?,
        ~defaultVisible=?fromBool(defaultVisible),
        ~direction=?fromAllDir(direction),
        ~icon?,
        ~inverted=?fromBool(inverted),
        ~vertical=?fromBool(vertical),
        ~visible=?fromBool(visible),
        ~width=?fromSBWidth(width),
        (),
      ),
    children,
  );

module Pushable = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Sidebar"]
  external sui : ReasonReact.reactClass = "Pushable";
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
      ~reactClass=sui,
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

module Pusher = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Sidebar"]
  external sui : ReasonReact.reactClass = "Pusher";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~dimmed: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, ~dimmed=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~dimmed=?fromBool(dimmed),
          (),
        ),
      children,
    );
};