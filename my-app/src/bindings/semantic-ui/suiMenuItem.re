[@bs.module "semantic-ui-react"][@bs.scope "Menu"]
external suiMenuItem : ReasonReact.reactClass = 
  "Item";

let make =
    (
      ~header=true,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenuItem,
    ~props={
      "header": header
    },
    children
  );