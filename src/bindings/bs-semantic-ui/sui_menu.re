open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Menu";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~_as: js=?,
    ~attached: string=?,
    ~borderless: bool=?,
    ~className: string=?,
    ~color: string=?,
    ~compact: bool=?,
    ~defaultActiveIndex: js=?,
    ~fixed: string=?,
    /* TODO: floated */
    ~fluid: bool=?,
    /* TODO: icon */
    ~inverted: bool=?,
    /* TODO: items */
    /* TODO: onItemClick */
    ~pagination: bool=?,
    ~pointing: bool=?,
    ~secondary: bool=?,
    ~size: string=?,
    ~stackable: bool=?,
    /* TODO: tabular */
    ~text: bool=?,
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
      ~borderless=?,
      ~className=?,
      ~color=?,
      ~compact=?,
      ~defaultActiveIndex=?,
      ~fixed=?,
      ~fluid=?,
      ~inverted=?,
      ~pagination=?,
      ~pointing=?,
      ~secondary=?,
      ~size=?,
      ~stackable=?,
      ~text=?,
      ~vertical=?,
      ~widths=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~_as=?fromStringOrReactClass(_as),
        ~attached=?fromAllDir(attached),
        ~borderless?,
        ~className?,
        ~color=?fromColor(color),
        ~compact?,
        ~defaultActiveIndex=?fromNumOrString(defaultActiveIndex),
        ~fixed=?fromAllDir(fixed),
        ~fluid?,
        ~inverted?,
        ~pagination?,
        ~pointing?,
        ~secondary?,
        ~size=?fromSize(size),
        ~stackable?,
        ~text?,
        ~vertical?,
        ~widths=?fromWidth(widths),
        (),
      ),
    children,
  );

module Item = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Menu"]
  external react : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeMenuItemProps :
    (
      ~active: bool=?,
      ~_as: js=?,
      ~className: string=?,
      ~color: string=?,
      ~content: string=?, /* TODO: is this only string ? */
      ~disabled: bool=?,
      /* TODO: fitted */
      ~header: bool=?,
      ~icon: string=?,
      ~index: js=?,
      ~link: bool=?,
      ~name: string=?,
      ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
      ~position: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active=?,
        ~_as=?,
        ~className=?,
        ~color=?,
        ~content=?,
        ~disabled=?,
        ~header=?,
        ~icon=?,
        ~index=?,
        ~link=?,
        ~name=?,
        ~onClick=?,
        ~position=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeMenuItemProps(
          ~active?,
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~color=?fromColor(color),
          ~content?,
          ~disabled?,
          ~header?,
          ~icon?,
          ~index=?fromNum(index),
          ~link?,
          ~position=?fromLeftOrRight(position),
          ~name?,
          ~onClick?,
          (),
        ),
      children,
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Menu"]
  external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: string=?, /* TODO: is this only string ? */
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

module Menu = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Menu"]
  external react : ReasonReact.reactClass = "Menu";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: string=?, /* TODO: is this only string ? */
      ~position: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, ~position=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~position=?fromLeftOrRight(position),
          (),
        ),
      children,
    );
};