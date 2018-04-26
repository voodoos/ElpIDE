open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Dimmer";

[@bs.obj]
external makeProps :
  (
    ~active: Js.boolean=?,
    ~as_: string=? /* TODO: Can also be a function ! */,
    ~className: string=? /* TODO: content */,
    ~disabled: Js.boolean=?,
    ~inverted: Js.boolean=?,
    ~onClick: (ReactEventRe.Synthetic.t, Js.t(Js.Types.obj_val)) => unit=?,
    ~onClickOutside: (ReactEventRe.Synthetic.t, Js.t(Js.Types.obj_val)) =>
                     unit
                       =?,
    ~page: Js.boolean=?,
    ~simple: Js.boolean=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~active=?,
      ~as_=?,
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
        ~as_?,
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
      ~as_: string=? /* TODO: Can also be a function ! */,
      ~blurring: Js.boolean=?,
      ~className: string=? /* TODO: content */,
      ~dimmed: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~blurring=?, ~className=?, ~dimmed=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=
        makeProps(
          ~as_?,
          ~blurring=?fromBool(blurring),
          ~className?,
          ~dimmed=?fromBool(dimmed),
          (),
        ),
      children,
    );
};