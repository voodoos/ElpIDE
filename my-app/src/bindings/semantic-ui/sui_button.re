[@bs.module "semantic-ui-react"]
external suiButton : ReasonReact.reactClass = "Button";

[@bs.module "semantic-ui-react"][@bs.scope "Button"]
external suiButtonGroup : ReasonReact.reactClass = 
  "Group";
  
let make =
    (
      ~className="",
      ~inverted=false,
      ~icon=false,
      ~onClick={() => ()},
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButton,
    ~props={
      "className": className,
      "inverted": Js.Boolean.to_js_boolean(inverted),
      "icon": Js.Boolean.to_js_boolean(icon),
      "onClick": onClick
    },
    children
  );


module Group = {
  let make =
  (
    ~className="",
    ~inverted=false,
    ~basic=false,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonGroup,
    ~props={
      "className": className,
      "inverted": Js.Boolean.to_js_boolean(inverted), 
      "basic": Js.Boolean.to_js_boolean(basic)
    },
    children
  );
}