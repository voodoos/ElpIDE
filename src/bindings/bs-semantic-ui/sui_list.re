open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "List";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~animated: Js.boolean=?,
    ~_as: js=?,
    ~bulleted: Js.boolean=?,
    ~celled: Js.boolean=?,
    ~className: string=?,
    ~content: ReasonReact.reactElement=?,
    ~divided: Js.boolean=?,
    ~floated: string=?,
    ~horizontal: Js.boolean=?,
    ~inverted: Js.boolean=?,
    ~items: array('a)=?,
    ~link: Js.boolean=?,
    /* TODO: onItemClick */
    ~ordered: Js.boolean=?,
    ~relaxed: js=?,
    ~selection: Js.boolean=?,
    ~size: string=?,
    ~verticalAlign: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~animated=?,
      ~_as=?,
      ~bulleted=?,
      ~celled=?,
      ~className=?,
      ~content=?,
      ~divided=?,
      ~floated=?,
      ~horizontal=?,
      ~inverted=?,
      ~items=?,
      ~link=?,
      ~ordered=?,
      ~relaxed=?,
      ~selection=?,
      ~size=?,
      ~verticalAlign=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~animated=?fromBool(animated),
        ~_as=?fromStringOrReactClass(_as),
        ~bulleted=?fromBool(bulleted),
        ~celled=?fromBool(celled),
        ~className?,
        ~content?,
        ~divided=?fromBool(divided),
        ~floated=?fromLeftOrRight(floated),
        ~horizontal=?fromBool(horizontal),
        ~inverted=?fromBool(inverted),
        ~items?,
        ~link=?fromBool(link),
        ~ordered=?fromBool(ordered),
        ~relaxed=?fromBoolOrVery(relaxed),
        ~selection=?fromBool(selection),
        ~size=?fromSize(size),
        ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
        (),
      ),
    children,
  );

module Description = {
  [@bs.module "semantic-ui-react"] [@bs.scope "List"]
  external react : ReasonReact.reactClass = "Description";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          (),
        ),
      children,
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "List"]
  external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          (),
        ),
      children,
    );
};

module Icon = {
  [@bs.module "semantic-ui-react"] [@bs.scope "List"]
  external react : ReasonReact.reactClass = "Icon";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~name: string=?,
      ~size: string=?,
      ~verticalAlign: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~className=?, ~name=?, ~size=?, ~verticalAlign=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~className?,
          ~name?,
          ~size=?fromSize(size),
          ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
          (),
        ),
      children,
    );
};

module Content = {
  [@bs.module "semantic-ui-react"] [@bs.scope "List"]
  external react : ReasonReact.reactClass = "Content";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~description: ReasonReact.reactElement=?,
      ~floated: string=?,
      ~header: ReasonReact.reactElement=?,
      ~verticalAlign: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_as=?,
        ~className=?,
        ~content=?,
        ~description=?,
        ~floated=?,
        ~header=?,
        ~verticalAlign=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~description?,
          ~floated=?fromLeftOrRight(floated),
          ~header?,
          ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
          (),
        ),
      children,
    );
};

module Item = {
  [@bs.module "semantic-ui-react"] [@bs.scope "List"]
  external react : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~description: ReasonReact.reactElement=?,
      ~disabled: Js.boolean=?,
      ~header: ReasonReact.reactElement=?,
      ~icon: string=?,
      ~image: ReasonReact.reactElement=?,
      ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
      ~value: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active=?,
        ~_as=?,
        ~className=?,
        ~content=?,
        ~description=?,
        ~disabled=?,
        ~header=?,
        ~icon=?,
        ~image=?,
        ~onClick=?,
        ~value=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~active=?fromBool(active),
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~description?,
          ~disabled=?fromBool(disabled),
          ~header?,
          ~icon?,
          ~image?,
          ~onClick?,
          ~value?,
          (),
        ),
      children,
    );
};

module List = {
  [@bs.module "semantic-ui-react"] [@bs.scope "List"]
  external react : ReasonReact.reactClass = "List";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      /* TODO: content */
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ()),
      children,
    );
};