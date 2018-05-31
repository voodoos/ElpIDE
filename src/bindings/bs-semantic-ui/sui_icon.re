[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Icon";

let make = (~name, ~className="", ~inverted=false, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props={"className": className, "inverted": inverted, "name": name},
    children,
  );