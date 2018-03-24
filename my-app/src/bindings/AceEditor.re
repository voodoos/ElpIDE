[@bs.module "react-ace"] external
  reactAceEditor : ReasonReact.reactClass = "default";

[%bs.raw {|require('brace/mode/ocaml')|}];
[%bs.raw {|require('brace/theme/monokai')|}];


let make = (~mode: string,
            ~theme: string,
            ~name: string,
            children) =>
  ReasonReact.wrapJsForReason(
  ~reactClass=reactAceEditor,
  ~props={"mode": mode,
          "theme": theme,
          "name": name
  },
  children
);
