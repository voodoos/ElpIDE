type monaco;

[@bs.val]
[@bs.module "monaco-editor"]
[@bs.scope "editor"]
external create_monaco : (Dom.element, 'a) => unit = "create";
