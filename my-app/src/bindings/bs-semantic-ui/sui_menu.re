[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

[@bs.module "semantic-ui-react"][@bs.scope "Menu"]
external suiMenuItem : ReasonReact.reactClass = 
  "Item";
  
let make =
    (
      ~className: string,
      ~inverted=false,
      ~borderless=false,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenu,
    ~props={
      "className": className,
      "inverted": Js.Boolean.to_js_boolean(inverted),
      "borderless": Js.Boolean.to_js_boolean(borderless)
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
      "header": Js.Boolean.to_js_boolean(header)
    },
    children
  );
}