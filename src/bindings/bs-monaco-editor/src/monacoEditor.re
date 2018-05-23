type monaco;

[@bs.val]
[@bs.module "monaco-editor/min/vs/editor/editor.main"]
[@bs.scope "editor"]
external create_monaco : (Dom.element, 'a) => unit = "create";