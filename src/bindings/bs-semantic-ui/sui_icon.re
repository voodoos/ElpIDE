[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Icon";

let make =
    (
      ~name,
      ~className="",
      ~inverted=false,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props={
      "className": className,
      "inverted": Js.Boolean.to_js_boolean(inverted),
      "name": name
    },
    children
  );
