open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeMenuProps :
  (
    ~_as: string=?, /* TODO: Can also be a function ! */
    ~attached: string=?,
    ~borderless: Js.boolean=?,
    ~className: string=?,
    ~color: string=?,
    ~compact: Js.boolean=?,
    ~defaultActiveIndex: js=?,
    ~fixed: string=?,
    /* TODO: floated */
    ~fluid: Js.boolean=?,
    /* TODO: icon */
    ~inverted: Js.boolean=?,
    /* TODO: items */
    /* TODO: onItemClick */
    ~pagination: Js.boolean=?,
    ~pointing: Js.boolean=?,
    ~secondary: Js.boolean=?,
    ~size: string=?,
    ~stackable: Js.boolean=?,
    /* TODO: tabular */
    ~text: Js.boolean=?,
    ~vertical: Js.boolean=?,
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
    ~reactClass=suiMenu,
    ~props=
      makeMenuProps(
        ~_as?,
        ~attached=?fromAllDir(attached),
        ~borderless=?fromBool(borderless),
        ~className?,
        ~color=?fromColor(color),
        ~compact=?fromBool(compact),
        ~defaultActiveIndex=?fromNumOrString(defaultActiveIndex),
        ~fixed=?fromAllDir(fixed),
        ~fluid=?fromBool(fluid),
        ~inverted=?fromBool(inverted),
        ~pagination=?fromBool(pagination),
        ~pointing=?fromBool(pointing),
        ~secondary=?fromBool(secondary),
        ~size=?fromSize(size),
        ~stackable=?fromBool(stackable),
        ~text=?fromBool(text),
        ~vertical=?fromBool(vertical),
        ~widths=?fromWidth(widths),
        (),
      ),
    children,
  );

module Item = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Menu"]
  external suiMenuItem : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeMenuItemProps :
    (
      ~active: Js.boolean=?,
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~color: string=?,
      ~content: string=?, /* TODO: is this only string ? */
      ~disabled: Js.boolean=?,
      /* TODO: fitted */
      ~header: Js.boolean=?,
      /* TODO: icon */
      ~index: js=?,
      ~link: Js.boolean=?,
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
        ~index=?,
        ~link=?,
        ~name=?,
        ~onClick=?,
        ~position=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=suiMenuItem,
      ~props=
        makeMenuItemProps(
          ~active=?fromBool(active),
          ~_as?,
          ~className?,
          ~color=?fromColor(color),
          ~content?,
          ~disabled=?fromBool(disabled),
          ~header=?fromBool(header),
          ~index=?fromNum(index),
          ~link=?fromBool(link),
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
  external suiMenuHeader : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: string=?, /* TODO: is this only string ? */
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=suiMenuHeader,
      ~props=makeProps(~_as?, ~className?, ~content?, ()),
      children,
    );
};

module Menu = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Menu"]
  external suiMenuMenu : ReasonReact.reactClass = "Menu";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: string=?, /* TODO: is this only string ? */
      ~position: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, ~position=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=suiMenuMenu,
      ~props=
        makeProps(
          ~_as?,
          ~className?,
          ~content?,
          ~position=?fromLeftOrRight(position),
          (),
        ),
      children,
    );
};