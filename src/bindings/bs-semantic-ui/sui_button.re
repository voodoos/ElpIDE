open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Button";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeButtonProps :
  (
    ~active: bool=?,
    ~animated: Sui_tools.js=?,
    ~_as: js=?,
    ~attached: string=?,
    ~basic: bool=?,
    ~circular: bool=?,
    ~className: string=?,
    ~color: string=?,
    ~compact: bool=?,
    ~content: ReasonReact.reactElement=?, /* TODO: is this only string ? */
    ~disabled: bool=?,
    ~floated: string=?,
    ~fluid: bool=?,
    ~icon: bool=?,
    ~inverted: bool=?,
    /* TODO: label: label {custom} Add a Label by text, props object, or pass a <Label />. */
    ~labelPosition: string=?,
    ~loading: bool=?,
    ~negative: bool=?,
    ~onClick: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~primary: bool=?,
    ~secondary: bool=?,
    ~size: string=?,
    ~tabIndex: Sui_tools.js=?,
    ~toggle: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~active=?,
      ~animated=?,
      ~_as=?,
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
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeButtonProps(
        ~active?,
        ~_as=?fromStringOrReactClass(_as),
        ~attached=?fromAllDir(attached),
        ~animated=?fromAnimBut(animated),
        ~basic?,
        ~circular?,
        ~className?, /* There is punning hapenning here (~className=?className) */
        ~color=?fromColor(color),
        ~compact?,
        ~content?,
        ~disabled?,
        ~floated=?fromLeftOrRight(floated),
        ~fluid?,
        ~icon?,
        ~inverted?,
        ~labelPosition=?fromLeftOrRight(labelPosition),
        ~loading?,
        ~negative?,
        ~primary?,
        ~secondary?,
        ~size=?fromSize(size),
        ~tabIndex=?fromNumOrString(tabIndex),
        ~toggle?,
        ~onClick?,
        (),
      ),
    children,
  );

/* Bindings for *Button.Group* */
module Group = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Button"]
  external react : ReasonReact.reactClass = "Group";
  [@bs.obj]
  external makeButtonGroupProps :
    (
      ~_as: js=?,
      ~attached: string=?,
      ~basic: bool=?,
      /* TODO: buttons 	{custom} Array of shorthand Button values. */
      ~className: string=?,
      ~color: string=?,
      ~compact: bool=?,
      ~content: ReasonReact.reactElement=?,
      ~floated: string=?,
      ~fluid: bool=?,
      ~icon: bool=?,
      ~inverted: bool=?,
      ~labeled: bool=?,
      ~negative: bool=?,
      ~positive: bool=?,
      ~primary: bool=?,
      ~secondary: bool=?,
      ~size: string=?,
      ~toggle: bool=?,
      ~vertical: bool=?,
      ~widths: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_as=?,
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
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeButtonGroupProps(
          ~_as=?fromStringOrReactClass(_as),
          ~attached=?fromAllDir(attached),
          ~basic?,
          ~className?, /* There is punning hapenning here (~className=?className) */
          ~color=?fromColor(color),
          ~compact?,
          ~floated=?fromLeftOrRight(floated),
          ~fluid?,
          ~icon?,
          ~content?,
          ~inverted?,
          ~labeled?,
          ~negative?,
          ~positive?,
          ~secondary?,
          ~size=?fromSize(size),
          ~toggle?,
          ~vertical?,
          ~widths=?fromWidth(widths),
          (),
        ),
      children,
    );
};

/* Bindings for *Button.Group* */
module Content = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Button"]
  external react : ReasonReact.reactClass = "Content";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~hidden: bool=?,
      ~visible: bool=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (~_as=?, ~className=?, ~content=?, ~hidden=?, ~visible=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~hidden?,
          ~visible?,
          (),
        ),
      children,
    );
};

/* Bindings for *Button.Or* */
module Or = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Button"]
  external react : ReasonReact.reactClass = "Or";
  [@bs.obj]
  external makeProps :
    (~_as: js=?, ~className: string=?, ~text: Sui_tools.js=?, unit) => _ =
    "";
  let make = (~_as=?, ~className=?, ~text=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~text=?fromNumOrString(text),
          (),
        ),
      children,
    );
};