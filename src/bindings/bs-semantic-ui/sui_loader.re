open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Loader";

[@bs.obj]
external makeProps :
  (
    ~active: Js.boolean=?,
    ~_as: js=?,
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
      ~_as=?,
      ~className=?,
      ~disabled=?,
      ~indeterminate=?,
      ~inline=?,
      ~inverted=?,
      ~size=?,
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
        ~indeterminate=?fromBool(indeterminate),
        ~inline=?fromBoolOrCentered(inline),
        ~inverted=?fromBool(inverted),
        ~size=?fromSize(size),
        (),
      ),
    children,
  );