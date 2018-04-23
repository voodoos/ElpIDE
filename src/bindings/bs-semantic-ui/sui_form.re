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
    ~widths: string=?,
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
      ~widths=?,
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
        ~widths=?fromWidth(widths),
        (),
      ),
    children,
  );


module Field = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Field";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~inline: Js.boolean=?,
      ~label: ReasonReact.reactElement=?, /* TODO : check */
      ~required: Js.boolean=?,
      ~type_: string=?, /* TODO : custom ? */
      ~width: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~className=?, ~content=?, ~control=?, ~disabled=?, ~error=?, ~inline=?, ~label=?, ~required=?, ~type_=?, ~width=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps( ~as_?, 
                        ~className?, 
                        ~content?, 
                        ~control?,
                        ~disabled=?fromBool(disabled),
                        ~error=?fromBool(error),
                        ~inline=?fromBool(inline),
                        ~label?,
                        ~required=?fromBool(required),
                        ~type_?,
                        ~width=?fromWidth(width),
                        ()),
      children,
    );
};

module Group = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Group";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      /* TODO : grouped, inline */
      ~unstackable: Js.boolean=?,
      ~widths: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~className=?, ~unstackable=?, ~widths=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps( ~as_?, 
                        ~className?, 
                        ~unstackable=?fromBool(unstackable),
                        ~widths=?fromWidth(widths),
                        ()),
      children,
    );
};

/* TODO

module Button = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Button";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};

module Checkbox = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Checkbox";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};

module Dropdown = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Dropdown";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};

module Input = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Input";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};

module Radio = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Radio";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};

module Select = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "Select";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};

module TextArea = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Form"]
  external sui : ReasonReact.reactClass = "TextArea";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~control: ReasonReact.reactElement=?, /* TODO ? can also be a string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~control=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~as_?, ~control?, ()),
      children,
    );
};
*/