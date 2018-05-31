open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Dimmer";

[@bs.obj]
external makeProps :
  (
    ~active: bool=?,
    ~_as: js=?,
    ~className: string=? /* TODO: content */,
    ~disabled: bool=?,
    ~inverted: bool=?,
    ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~onClickOutside: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~page: bool=?,
    ~simple: bool=?,
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
        ~active?,
        ~_as=?fromStringOrReactClass(_as),
        ~className?,
        ~disabled?,
        ~inverted?,
        ~onClick?,
        ~onClickOutside?,
        ~page?,
        ~simple?,
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
      ~blurring: bool=?,
      ~className: string=? /* TODO: content */,
      ~dimmed: bool=?,
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
          ~blurring?,
          ~className?,
          ~dimmed?,
          (),
        ),
      children,
    );
};