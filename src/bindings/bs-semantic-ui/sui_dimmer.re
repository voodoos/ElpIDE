open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Dimmer";

[@bs.obj]
external makeProps :
  (
    ~active: Js.boolean=?,
    ~_as: string=? /* TODO: Can also be a function ! */,
    ~className: string=? /* TODO: content */,
    ~disabled: Js.boolean=?,
    ~inverted: Js.boolean=?,
    ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~onClickOutside: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~page: Js.boolean=?,
    ~simple: Js.boolean=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~active=?,
      ~_as=?,
      ~className=?,
      ~disabled=?,
      ~inverted=?,
      ~onClick=?,
      ~onClickOutside=?,
      ~page=?,
      ~simple=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=sui,
    ~props=
      makeProps(
        ~active=?fromBool(active),
        ~_as?,
        ~className?,
        ~disabled=?fromBool(disabled),
        ~inverted=?fromBool(inverted),
        ~onClick?,
        ~onClickOutside?,
        ~page=?fromBool(page),
        ~simple=?fromBool(simple),
        (),
      ),
    children,
  );

module Dimmable = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dimmer"]
  external sui : ReasonReact.reactClass = "Dimmable";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=? /* TODO: Can also be a function ! */,
      ~blurring: Js.boolean=?,
      ~className: string=? /* TODO: content */,
      ~dimmed: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~blurring=?, ~className=?, ~dimmed=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=
        makeProps(
          ~_as?,
          ~blurring=?fromBool(blurring),
          ~className?,
          ~dimmed=?fromBool(dimmed),
          (),
        ),
      children,
    );
};