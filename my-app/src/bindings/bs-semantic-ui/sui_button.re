open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiButton : ReasonReact.reactClass = "Button";

[@bs.module "semantic-ui-react"][@bs.scope "Button"]
external suiButtonGroup : ReasonReact.reactClass = 
  "Group";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj] external makeButtonProps : (
  ~className: string=?, 
  ~inverted: Js.boolean=?, 
  ~icon: Js.boolean=?, 
  ~color: string=?, 
  ~onClick: (unit => unit)=?, 
  unit
  ) => _ = "";

[@bs.obj] external makeButtonGroupProps : (
  ~className: string=?, 
  ~inverted: Js.boolean=?, 
  ~basic: Js.boolean=?,
  unit
  ) => _ = "";
  

/* Bindings for *Button* */
let make =
    (
      ~className=?,
      ~inverted=?,
      ~icon=?,
      ~onClick=?,
      ~color=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButton,
    ~props=makeButtonProps(
      ~className?, /* There is punning hapenning here (~className=?className) */
      ~inverted=?toJsOptionBool(inverted),
      ~icon=?toJsOptionBool(icon),
      ~color=?toJsOptionColor(color),
      ~onClick?,
      ()
    ),
    children
  );

/* Bindings for *Button.Group* */
module Group = {
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
      ~inverted=?toJsOptionBool(inverted),
      ~basic=?toJsOptionBool(basic),
      ()
    ),
    children
  );
}


/* Bindings for *Button.Content* */


/* Bindings for *Button.Or* */