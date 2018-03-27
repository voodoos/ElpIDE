[@bs.module "semantic-ui-react"]
external suiButton : ReasonReact.reactClass = "Button";

[@bs.module "semantic-ui-react"][@bs.scope "Button"]
external suiButtonGroup : ReasonReact.reactClass = 
  "Group";
  
let make =
    (
      ~className: string,
      ~inverted=false,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButton,
    ~props={
      "className": className,
      "inverted": inverted
    },
    children
  );


module Group = {
  let make =
  (
    ~header=true,
    children
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiButtonGroup,
    ~props={
      "header": header
    },
    children
  );
}