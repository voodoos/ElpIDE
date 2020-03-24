open Sui_tools;

[@bs.module "semantic-ui-react"] external react : ReasonReact.reactClass = "Message";

[@bs.obj]
external makeProps :
  (
    ~list: array('a)=?,
    ~onDismiss: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~size: string=?,
    ~icon: ReasonReact.reactElement=?,
    ~color: string=?,
    ~attached: js=?,
    ~_as: js=?,
    ~header: ReasonReact.reactElement=?,
    ~content: ReasonReact.reactElement=?,
    ~children: ReasonReact.reactElement=?,
    ~className: string=?,
    ~compact: bool=?,
    ~error: bool=?,
    ~floating: bool=?,
    ~hidden: bool=?,
    ~info: bool=?,
    ~negative: bool=?,
    ~success: bool=?,
    ~visible: bool=?,
    ~warning: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~list=?,
      ~onDismiss=?,
      ~size=?,
      ~icon=?,
      ~color=?,
      ~attached=?,
      ~_as=?,
      ~header=?,
      ~content=?,
      ~className=?,
      ~compact=?,
      ~error=?,
      ~floating=?,
      ~hidden=?,
      ~info=?,
      ~negative=?,
      ~success=?,
      ~visible=?,
      ~warning=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~list?,
        ~onDismiss?,
        ~size=?fromSizeHeader(size),
        ~icon?,
        ~color=?fromColor(color),
        ~attached=?fromBoolOrTopOrBottom(attached),
        ~_as=?fromStringOrReactClass(_as),
        ~header?,
        ~content?,
        ~className?,
        ~compact?,
        ~error?,
        ~floating?,
        ~hidden?,
        ~info?,
        ~negative?,
        ~success?,
        ~visible?,
        ~warning?,
        (),
      ),
    children,
  );

module Content = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Message"] external react : ReasonReact.reactClass = "Content";
  [@bs.obj]
  external makeProps : (~_as: js=?, ~className: string=?, ~content: ReasonReact.reactElement=?, unit) => _ = "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ~content?, ()),
      children,
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Message"] external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps : (~_as: js=?, ~className: string=?, ~content: ReasonReact.reactElement=?, unit) => _ = "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ~content?, ()),
      children,
    );
};

module Item = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Message"] external react : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps : (~_as: js=?, ~className: string=?, ~content: ReasonReact.reactElement=?, unit) => _ = "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ~content?, ()),
      children,
    );
};

module List = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Message"] external react : ReasonReact.reactClass = "List";
  [@bs.obj]
  external makeProps :
    (~_as: js=?, ~className: string=?, ~content: ReasonReact.reactElement=?, ~items: array('a)=?, unit) => _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, ~items=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ~content?, ~items?, ()),
      children,
    );
};
