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
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButton,
    ~props={
      "className": className,
      "inverted": inverted,
      "icon": icon
    },
    children
  );


module Group = {
  let make =
  (
    ~className="",
    ~inverted=false,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonGroup,
    ~props={
      "className": className,
      "inverted": inverted
    },
    children
  );
}