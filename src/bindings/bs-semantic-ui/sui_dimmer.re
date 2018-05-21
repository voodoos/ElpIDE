open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Dimmer";

[@bs.obj]
external makeProps :
  (
    ~active: Js.boolean=?,
    ~_as: js=?,
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
    ~reactClass=react,
    ~props=
      makeProps(
        ~active=?fromBool(active),
        ~_as=?fromStringOrReactClass(_as),
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
  external react : ReasonReact.reactClass = "Dimmable";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~blurring: Js.boolean=?,
      ~className: string=? /* TODO: content */,
      ~dimmed: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~blurring=?, ~className=?, ~dimmed=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~blurring=?fromBool(blurring),
          ~className?,
          ~dimmed=?fromBool(dimmed),
          (),
        ),
      children,
    );
};