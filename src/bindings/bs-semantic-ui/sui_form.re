open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Form";

[@bs.obj]
external makeProps :
  (
    ~action: string=?,
    ~as_: string=?, /* TODO: Can also be a function ! */
    ~className: string=?,
    ~error: Js.boolean=?,
    ~inverted: Js.boolean=?,
    ~loading: Js.boolean=?,
    ~onSubmit: ReactEventRe.Form.t => unit=?,
    ~reply: Js.boolean=?,
    ~size: string=?,
    ~success: Js.boolean=?,
    ~unstackable: Js.boolean=?,
    ~warning: Js.boolean=?,
    ~width: js=?,
    unit
  ) =>
  _ =
  "";

/* Bindings for *Button* */
let make =
    (
      ~action=?,
      ~as_=?,
      ~className=?,
      ~error=?,
      ~inverted=?,
      ~loading=?,
      ~onSubmit=?,
      ~reply=?,
      ~size=?,
      ~success=?,
      ~unstackable=?,
      ~warning=?,
      ~width=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=sui,
    ~props=
      makeProps(
        ~action?,
        ~as_?,
        ~className?,
        ~error=?fromBool(error),
        ~inverted=?fromBool(inverted),
        ~loading=?fromBool(loading),
        ~onSubmit?,
        ~reply=?fromBool(reply),
        ~size=?fromSize(size),
        ~success=?fromBool(success),
        ~unstackable=?fromBool(unstackable),
        ~warning=?fromBool(warning),
        ~width=?fromEqual(width),
        (),
      ),
    children,
  );