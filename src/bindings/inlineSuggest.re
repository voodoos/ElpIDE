[@bs.module "react-inline-suggest"]
external react : ReasonReact.reactClass = "InlineSuggest";

[@bs.obj]
external makeProps :
  (
    ~value: string,
    ~haystack: array('a),
    ~onChange: ReactEventRe.Form.t => unit,
    ~onMatch: unit => unit=?,
    ~getFn: 'a => string=?,
    ~ignoreCase: Js.boolean=?,
    ~shouldRenderSuggestion: 'a => unit=?,
    ~switchBetweenSuggestions: Js.boolean=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~value,
      ~haystack,
      ~onChange,
      ~onMatch=?,
      ~getFn=?,
      ~ignoreCase=?,
      ~shouldRenderSuggestion=?,
      ~switchBetweenSuggestions=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~value,
        ~haystack,
        ~onChange,
        ~onMatch?,
        ~getFn?,
        ~ignoreCase?,
        ~shouldRenderSuggestion?,
        ~switchBetweenSuggestions?,
        (),
      ),
    children,
  );