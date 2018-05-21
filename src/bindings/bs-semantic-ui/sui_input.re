open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Input";

[@bs.obj] /* TODO : Action, ActionPosition */
external makeProps :
  (
    ~_as: js=?,
    ~autoComplete: string=?,
    ~className: string=?,
    ~disabled: Js.boolean=?,
    ~error: Js.boolean=?,
    ~fluid: Js.boolean=?,
    ~focus: Js.boolean=?,
    ~icon: js=? /* TODO : input */ /* TODO : iconPosition */ /* fromBoolOrString */,
    ~inverted: Js.boolean=? /* TODO: label: label {custom} Add a Label by text, props object, or pass a <Label />. */,
    ~label: ReasonReact.reactElement=?,
    ~labelPosition: string=?,
    ~loading: Js.boolean=?,
    ~multiple: Js.boolean=?,
    ~onChange: ReactEventRe.Form.t => unit=?,
    ~size: string=?,
    ~tabIndex: js=?,
    ~transparent: Js.boolean=? /* Usual <input props */,
    ~name: string=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~placeholder: string=?,
    ~_type: string=?,
    ~value: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?,
      ~autoComplete=?,
      ~className=?,
      ~disabled=?,
      ~error=?,
      ~fluid=?,
      ~focus=?,
      ~icon=?,
      ~inverted=?,
      ~label=?,
      ~labelPosition=?,
      ~loading=?,
      ~multiple=?,
      ~onChange=?,
      ~size=?,
      ~tabIndex=?,
      ~transparent=?,
      ~name=?,
      ~onKeyDown=?,
      ~placeholder=?,
      ~_type=?,
      ~value=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~_as=?fromStringOrReactClass(_as),
        ~autoComplete?,
        ~className?,
        ~disabled=?fromBool(disabled),
        ~error=?fromBool(error),
        ~focus=?fromBool(focus),
        ~fluid=?fromBool(fluid),
        ~icon=?fromBoolOrString(icon),
        ~inverted=?fromBool(inverted),
        ~label?,
        ~labelPosition=?fromLabelPos(labelPosition),
        ~loading=?fromBool(loading),
        ~multiple=?fromBool(multiple),
        ~onChange?,
        ~size=?fromSize(size),
        ~tabIndex=?fromNumOrString(tabIndex),
        ~transparent=?fromBool(transparent),
        ~name?,
        ~onKeyDown?,
        ~placeholder?,
        ~_type?,
        ~value?,
        (),
      ),
    children,
  );