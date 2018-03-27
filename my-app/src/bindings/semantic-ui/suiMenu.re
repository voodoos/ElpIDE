[@bs.module "semantic-ui-react"]
external suiMenu : ReasonReact.reactClass = "Menu";

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
      "inverted": inverted
    },
    children
  );