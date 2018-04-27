open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Input";

[@bs.obj] /* TODO : Action, ActionPosition */
external makeProps :
  (
    ~as_: string=? /* TODO: Can also be a function ! */,
    ~autoComplete: string=?,
    ~className: string=?,
    ~disabled: Js.boolean=?,
    ~error: Js.boolean=?,
    ~fluid: Js.boolean=?,
    ~focus: Js.boolean=?,
    ~icon: js=? /* TODO : input */ /* TODO : iconPosition */ /* fromBoolOrString */,
    ~inverted: Js.boolean=? /* TODO : ~labelPosition: string=?, */ /* TODO: label: label {custom} Add a Label by text, props object, or pass a <Label />. */,
    ~loading: Js.boolean=?,
    ~onChange: ReactEventRe.Form.t => unit=?,
    ~size: string=?,
    ~tabIndex: js=?,
    ~transparent: Js.boolean=? /* Usual <input props */,
    ~name: string=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~placeholder: string=?,
    ~type_: string=?,
    ~value: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~as_=?,
      ~autoComplete=?,
      ~className=?,
      ~disabled=?,
      ~error=?,
      ~fluid=?,
      ~focus=?,
      ~icon=?,
      ~inverted=? /*~labelPosition=?,*/,
      ~loading=?,
      ~onChange=?,
      ~size=?,
      ~tabIndex=?,
      ~transparent=?,
      ~name=?,
      ~onKeyDown=?,
      ~placeholder=?,
      ~type_=?,
      ~value=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=sui,
    ~props=
      makeProps(
        ~as_?,
        ~autoComplete?,
        ~className?,
        ~disabled=?fromBool(disabled),
        ~error=?fromBool(error),
        ~focus=?fromBool(focus),
        ~fluid=?fromBool(fluid),
        ~icon=?fromBoolOrString(icon),
        ~inverted=?fromBool(inverted) /* ~labelPosition=?fromLeftOrRightOrLeftCornerOrRightCorner(labelPosition), */,
        ~loading=?fromBool(loading),
        ~onChange?,
        ~size=?fromSize(size),
        ~tabIndex=?fromNumOrString(tabIndex),
        ~transparent=?fromBool(transparent),
        ~name?,
        ~onKeyDown?,
        ~placeholder?,
        ~type_?,
        ~value?,
        (),
      ),
    children,
  );