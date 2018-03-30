open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiButton : ReasonReact.reactClass = "Button";

[@bs.module "semantic-ui-react"][@bs.scope "Button"]
external suiButtonGroup : ReasonReact.reactClass = 
  "Group";


[@bs.module "semantic-ui-react"][@bs.scope "Button"]
external suiButtonContent : ReasonReact.reactClass = 
  "Content";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */

[@bs.obj] external makeButtonProps : (
  ~active: Js.boolean=?, 
  ~animated: Sui_tools.js=?,
  ~as_: string=?, /* TODO: Can also be a function ! */
  ~attached: string=?,
  ~basic: Js.boolean=?,
  ~circular: Js.boolean=?,
  ~className: string=?, 
  ~color: string=?, 
  ~compact: Js.boolean=?,
  ~content: string=?, /* TODO: is this only string ? */
  ~disabled: Js.boolean=?,
  ~floated: string=?,
  ~fluid: Js.boolean=?,
  ~icon: Js.boolean=?, 
  ~inverted: Js.boolean=?, 
  /* TODO: label: label {custom} Add a Label by text, props object, or pass a <Label />. */
  ~labelPosition: string=?,
  ~loading: Js.boolean=?, 
  ~negative: Js.boolean=?, 
  ~onClick: (ReactEventRe.Synthetic.t,  Js.t(Js.Types.obj_val)) => unit=?,
  ~primary: Js.boolean=?, 
  ~secondary: Js.boolean=?, 
  ~size: string=?,
  ~tabIndex: Sui_tools.js=?,
  ~toggle: Js.boolean=?, 
  unit
  ) => _ = "";

/* Bindings for *Button* */
let make =
    (
      ~active=?,
      ~animated=?,
      ~as_=?,
      ~attached=?,
      ~basic=?,
      ~circular=?,
      ~className=?,
      ~color=?,
      ~compact=?,
      ~content=?,
      ~disabled=?,
      ~floated=?,
      ~fluid=?,
      ~icon=?,
      ~inverted=?,
      ~labelPosition=?,
      ~loading=?,
      ~negative=?,
      ~primary=?,
      ~secondary=?,
      ~size=?,
      ~tabIndex=?,
      ~toggle=?,
      ~onClick=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButton,
    ~props=makeButtonProps(
      ~active=?fromBool(active),
      ~as_?,
      ~attached=?fromAllDir(attached),
      ~animated=?fromAnimBut(animated),
      ~basic=?fromBool(basic),
      ~circular=?fromBool(circular),
      ~className?, /* There is punning hapenning here (~className=?className) */
      ~color=?fromColor(color),
      ~compact=?fromBool(compact),
      ~content?,
      ~disabled=?fromBool(disabled),
      ~floated=?fromLeftOrRight(floated),
      ~fluid=?fromBool(fluid),
      ~icon=?fromBool(icon),
      ~inverted=?fromBool(inverted),
      ~labelPosition=?fromLeftOrRight(labelPosition),
      ~loading=?fromBool(loading),
      ~negative=?fromBool(negative),
      ~primary=?fromBool(primary),
      ~secondary=?fromBool(secondary),
      ~size=?fromSize(size),
      ~tabIndex=?fromNumOrString(tabIndex),
      ~toggle=?fromBool(toggle),
      ~onClick?,
      ()
    ),
    children
  );

/* Bindings for *Button.Group* */
module Group = {
  [@bs.obj] external makeButtonGroupProps : (
    ~as_: string=?, /* TODO: Can also be a function ! */
    ~attached: string=?,
    ~basic: Js.boolean=?,
    /* TODO: buttons 	{custom} Array of shorthand Button values. */
    ~className: string=?, 
    ~color: string=?,   
    ~compact: Js.boolean=?,
    ~content: string=?, /* TODO: is this only string ? */
    ~floated: string=?,
    ~fluid: Js.boolean=?,
    ~icon: Js.boolean=?, 
    ~inverted: Js.boolean=?, 
    ~labeled: Js.boolean=?, 
    ~negative: Js.boolean=?, 
    ~positive: Js.boolean=?,
    ~primary: Js.boolean=?, 
    ~secondary: Js.boolean=?, 
    ~size: string=?,
    ~toggle: Js.boolean=?, 
    ~vertical: Js.boolean=?,
    ~widths: string=?,
    unit
    ) => _ = "";

  let make =
  (
    ~as_=?,
    ~attached=?,
    ~basic=?,
    ~color=?, 
    ~className=?,
    ~compact=?,
    ~content=?,
    ~floated=?,
    ~fluid=?,
    ~icon=?,
    ~inverted=?,
    ~labeled=?,
    ~negative=?,
    ~positive=?,
    ~secondary=?,
    ~size=?,
    ~toggle=?,
    ~vertical=?,
    ~widths=?,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonGroup,
    ~props=makeButtonGroupProps(
      ~as_?,
      ~attached=?fromAllDir(attached),
      ~basic=?fromBool(basic),
      ~className?, /* There is punning hapenning here (~className=?className) */
      ~color=?fromColor(color),
      ~compact=?fromBool(compact),
      ~floated=?fromLeftOrRight(floated),
      ~fluid=?fromBool(fluid),
      ~icon=?fromBool(icon),
      ~content?,
      ~inverted=?fromBool(inverted),
      ~labeled=?fromBool(labeled),
      ~negative=?fromBool(negative),
      ~positive=?fromBool(positive),
      ~secondary=?fromBool(secondary),
      ~size=?fromSize(size),
      ~toggle=?fromBool(toggle),
      ~vertical=?fromBool(vertical),
      ~widths=?fromWidth(widths),
      ()
    ),
    children
  );
};


/* Bindings for *Button.Group* */
module Content = {
  [@bs.obj] external makeProps : (
    ~as_: string=?, /* TODO: Can also be a function ! */
    ~className: string=?, 
    ~content: string=?, /* TODO: is this only string ? */
    ~hidden: Js.boolean=?, 
    ~visible: Js.boolean=?,
    unit
    ) => _ = "";

  let make =
  (
    ~as_=?,
    ~className=?,
    ~content=?,
    ~hidden=?,
    ~visible=?,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonContent,
    ~props=makeProps(
      ~as_?,
      ~className?, 
      ~content?,
      ~hidden=?fromBool(hidden),
      ~visible=?fromBool(visible),
      ()
    ),
    children
  );
};


/* Bindings for *Button.Or* */
module Or = {
  [@bs.obj] external makeProps : (
    ~as_: string=?, /* TODO: Can also be a function ! */
    ~className: string=?, 
    ~text: Sui_tools.js=?,
    unit
    ) => _ = "";

  let make =
  (
    ~as_=?,
    ~className=?,
    ~text=?,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonContent,
    ~props=makeProps(
      ~as_?,
      ~className?, 
      ~text=?fromNumOrString(text),
      ()
    ),
    children
  );
};