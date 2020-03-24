[@bs.module] external react : ReasonReact.reactClass = "react-markdown";

let make = (~source: string, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props={"source": source},
    children,
  );