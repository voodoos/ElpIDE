open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "List";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~animated: bool=?,
    ~_as: js=?,
    ~bulleted: bool=?,
    ~celled: bool=?,
    ~className: string=?,
    ~content: ReasonReact.reactElement=?,
    ~divided: bool=?,
    ~floated: string=?,
    ~horizontal: bool=?,
    ~inverted: bool=?,
    ~items: array('a)=?,
    ~link: bool=?,
    /* TODO: onItemClick */
    ~ordered: bool=?,
    ~relaxed: js=?,
    ~selection: bool=?,
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
        ~animated?,
        ~_as=?fromStringOrReactClass(_as),
        ~bulleted?,
        ~celled?,
        ~className?,
        ~content?,
        ~divided?,
        ~floated=?fromLeftOrRight(floated),
        ~horizontal?,
        ~inverted?,
        ~items?,
        ~link?,
        ~ordered?,
        ~relaxed=?fromBoolOrVery(relaxed),
        ~selection?,
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
      ~active: bool=?,
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~description: ReasonReact.reactElement=?,
      ~disabled: bool=?,
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
          ~active?,
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~description?,
          ~disabled?,
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