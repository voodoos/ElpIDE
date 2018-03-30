open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiButton : ReasonReact.reactClass = "Button";

[@bs.module "semantic-ui-react"][@bs.scope "Button"]
external suiButtonGroup : ReasonReact.reactClass = 
  "Group";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */

[@bs.obj] external makeButtonProps : (
  ~active: Js.boolean=?, 
  ~animated: Sui_tools.js=?,
  /* TODO: as */
  ~attached: string=?,
  ~basic: Js.boolean=?,
  ~circular: Js.boolean=?,
  ~className: string=?, 
  ~color: string=?, 
  ~compact: Js.boolean=?,
  /* TODO: content */
  ~disabled: Js.boolean=?,
  ~floated: string=?,
  ~fluid: Js.boolean=?,
  ~icon: Js.boolean=?, 
  ~inverted: Js.boolean=?, 
  /* TODO: label, labelPosition */
  ~loading: Js.boolean=?, 
  ~negative: Js.boolean=?, 
  ~primary: Js.boolean=?, 
  ~secondary: Js.boolean=?, 
  ~size: string=?,
  /* TODO: tabIndex */
  ~toggle: Js.boolean=?, 
 
      
  ~onClick: (ReactEventRe.Synthetic.t,  Js.t(Js.Types.obj_val)) => unit=?,
  unit
  ) => _ = "";

/* Bindings for *Button* */
let make =
    (
      ~active=?,
      ~attached=?,
      ~animated=?,
      ~basic=?,
      ~circular=?,
      ~className=?,
      ~color=?,
      ~compact=?,
      ~disabled=?,
      ~floated=?,
      ~fluid=?,
      ~icon=?,
      ~inverted=?,
      ~loading=?,
      ~negative=?,
      ~primary=?,
      ~secondary=?,
      ~size=?,
      ~toggle=?,
      ~onClick=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButton,
    ~props=makeButtonProps(
      ~active=?toBool(active),
      ~attached=?toAttached(attached),
      ~animated=?toAnimBut(animated),
      ~basic=?toBool(basic),
      ~circular=?toBool(circular),
      ~className?, /* There is punning hapenning here (~className=?className) */
      ~color=?toColor(color),
      ~compact=?toBool(compact),
      ~disabled=?toBool(disabled),
      ~floated=?toFloated(floated),
      ~fluid=?toBool(fluid),
      ~icon=?toBool(icon),
      ~inverted=?toBool(inverted),
      ~loading=?toBool(loading),
      ~negative=?toBool(negative),
      ~primary=?toBool(primary),
      ~secondary=?toBool(secondary),
      ~size=?toSize(size),
      ~toggle=?toBool(toggle),
      ~onClick?,
      ()
    ),
    children
  );

/* Bindings for *Button.Group* */
module Group = {


  [@bs.obj] external makeButtonGroupProps : (
    ~className: string=?, 
    ~inverted: Js.boolean=?, 
    ~basic: Js.boolean=?,
    unit
    ) => _ = "";

  let make =
  (
    ~className=?,
    ~inverted=?,
    ~basic=?,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonGroup,
    ~props=makeButtonGroupProps(
      ~className?, /* There is punning hapenning here (~className=?className) */
      ~inverted=?toBool(inverted),
      ~basic=?toBool(basic),
      ()
    ),
    children
  );
}


/* Bindings for *Button.Content* */


/* Bindings for *Button.Or* */