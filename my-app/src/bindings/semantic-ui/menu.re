[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

[@bs.module "semantic-ui-react"][@bs.scope "Menu"]
external suiMenuItem : ReasonReact.reactClass = 
  "Item";
  
let make =
    (
      ~className: string,
      ~inverted=false,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenu,
    ~props={
      "className": className,
      "inverted": Tools.from_bool(inverted)
    },
    children
  );


module Item = {
  let make =
  (
    ~header=false,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenuItem,
    ~props={
      "header": Tools.from_bool(header)
    },
    children
  );
}