[@bs.module "react-ace"] external
  reactAceEditor : ReasonReact.reactClass = "default";

[%bs.raw {|require('brace/mode/ocaml')|}];
[%bs.raw {|require('brace/theme/monokai')|}];
[%bs.raw {|require('brace/ext/language_tools')|}];
[%bs.raw {|require('brace/ext/searchbox')|}];


let make = (~mode: string,
            ~theme: string,
            ~name: string,
            ~width: string,
            ~height: string,
            ~setOptions: Js.Json.t,
            children) =>
  ReasonReact.wrapJsForReason(
  ~reactClass=reactAceEditor,
  ~props={"mode": mode,
          "theme": theme,
          "name": name,
          "width": width,
          "height": height,
          "setOptions": setOptions
          
  },
  children
);
