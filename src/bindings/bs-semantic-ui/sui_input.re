open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Input";

[@bs.obj]
external makeProps :
  (
    /* TODO : Action, ActionPosition */
    ~as_: string=?, /* TODO: Can also be a function ! */
    ~className: string=?,
    ~disabled: Js.boolean=?,
    ~error: Js.boolean=?,
    ~fluid: Js.boolean=?,
    ~focus: Js.boolean=?,
    ~icon: js=?, /* fromBoolOrString */
    /* TODO : iconPosition */
    /* TODO : input */
    ~inverted: Js.boolean=?,
    /* TODO: label: label {custom} Add a Label by text, props object, or pass a <Label />. */
    /* TODO : ~labelPosition: string=?, */
    ~loading: Js.boolean=?,
    ~onChange: (ReactEventRe.Synthetic.t, Js.t(Js.Types.obj_val)) => unit=?,
    ~size: string=?,
    ~tabIndex: js=?,
    ~transparent: Js.boolean=?,
    ~type_: string=?,

    /* Usual <input props */
    
    unit
  ) =>
  _ =
  "";
let make =
    (
      ~as_=?,
      ~className=?,
      ~disabled=?,
      ~error=?,
      ~fluid=?,
      ~focus=?,
      ~icon=?,
      ~inverted=?,
      /*~labelPosition=?,*/
      ~loading=?,
      ~onChange=?,
      ~size=?,
      ~tabIndex=?,
      ~transparent=?,
      ~type_=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=sui,
    ~props=
      makeProps(
        ~as_?,
        ~className?,
        ~disabled=?fromBool(disabled),
        ~error=?fromBool(error),
        ~fluid=?fromBool(fluid),
        ~icon=?fromBoolOrString(icon),
        ~inverted=?fromBool(inverted),
       /* ~labelPosition=?fromLeftOrRightOrLeftCornerOrRightCorner(labelPosition), */
        ~loading=?fromBool(loading),
        ~onChange?,
        ~size=?fromSize(size),
        ~tabIndex=?fromNumOrString(tabIndex),
        ~transparent=?fromBool(transparent),
        ~type_?,
        (),
      ),
    children,
  );