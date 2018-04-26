open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Loader";

[@bs.obj]
external makeProps :
  (
    ~active: Js.boolean=?,
    ~as_: string=? /* TODO: Can also be a function ! */,
    ~className: string=? /* TODO: content */,
    ~disabled: Js.boolean=?,
    ~indeterminate: Js.boolean=?,
    ~inline: js=?,
    ~inverted: Js.boolean=?,
    ~size: string=?,
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
      ~indeterminate=?,
      ~inline=?,
      ~inverted=?,
      ~size=?,
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
        ~indeterminate=?fromBool(indeterminate),
        ~inline=?fromBoolOrCentered(inline),
        ~inverted=?fromBool(inverted),
        ~size=?fromSize(size),
        (),
      ),
    children,
  );