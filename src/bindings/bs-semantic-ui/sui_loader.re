open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Loader";

[@bs.obj]
external makeProps :
  (
    ~active: bool=?,
    ~_as: js=?,
    ~className: string=? /* TODO: content */,
    ~disabled: bool=?,
    ~indeterminate: bool=?,
    ~inline: js=?,
    ~inverted: bool=?,
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
        ~active?,
        ~_as=?fromStringOrReactClass(_as),
        ~className?,
        ~disabled?,
        ~indeterminate?,
        ~inline=?fromBoolOrCentered(inline),
        ~inverted?,
        ~size=?fromSize(size),
        (),
      ),
    children,
  );