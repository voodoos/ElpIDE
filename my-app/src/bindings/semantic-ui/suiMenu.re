[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

let make =
    (
      ~className: string,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiMenu,
    ~props={
      "className": className
    },
    children
  );