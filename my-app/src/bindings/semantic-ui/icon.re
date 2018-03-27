[@bs.module "semantic-ui-react"]
external suiIcon : ReasonReact.reactClass = "Icon";

let make =
    (
      ~name,
      ~className="",
      ~inverted=false,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=suiIcon,
    ~props={
      "className": className,
      "inverted": inverted,
      "name": name
    },
    children
  );
