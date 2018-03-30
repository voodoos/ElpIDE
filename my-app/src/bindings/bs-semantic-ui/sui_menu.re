open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

[@bs.module "semantic-ui-react"][@bs.scope "Menu"]
external suiMenuItem : ReasonReact.reactClass = 
  "Item";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj] external makeMenuProps : (
  ~className: string=?, 
  ~inverted: Js.boolean=?, 
  ~borderless: Js.boolean=?, 
  unit
  ) => _ = "";

[@bs.obj] external makeMenuItemProps : (
  ~header: Js.boolean=?, 
  unit
  ) => _ = "";
  
let make =
    (
      ~className=?,
      ~inverted=?,
      ~borderless=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenu,
    ~props=makeMenuProps(
      ~className?,
      ~inverted=?toBool(inverted),
      ~borderless=?toBool(borderless),
      ()
    ),
    children
  );


module Item = {
  let make =
  (
    ~header=?,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenuItem,
    ~props=makeMenuItemProps(
      ~header=?toBool(header),
      ()
    ),
    children
  );
}