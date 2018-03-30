open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

[@bs.module "semantic-ui-react"][@bs.scope "Menu"]
external suiMenuItem : ReasonReact.reactClass = 
  "Item";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj] external makeMenuProps : (
  ~as_: string=?, /* TODO: Can also be a function ! */
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
  ) => _ = "";

let make =
    (
      ~as_=?,
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
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenu,
    ~props=makeMenuProps(
      ~as_?,
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
      ()
    ),
    children
  );


module Item = {
  [@bs.obj] external makeMenuItemProps : (
    ~as_: string=?, /* TODO: Can also be a function ! */
    ~header: Js.boolean=?, 
    unit
    ) => _ = "";

  let make =
  (
    ~as_=?,
    ~header=?,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenuItem,
    ~props=makeMenuItemProps(
      ~as_?,
      ~header=?fromBool(header),
      ()
    ),
    children
  );
}