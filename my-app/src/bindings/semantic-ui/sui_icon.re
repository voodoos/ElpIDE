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
      "inverted": Tools.to_js_bool(inverted),
      "name": name
    },
    children
  );
