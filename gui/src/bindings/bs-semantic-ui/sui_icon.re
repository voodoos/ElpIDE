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
      "inverted": Js.Boolean.to_js_boolean(inverted),
      "name": name
    },
    children
  );
