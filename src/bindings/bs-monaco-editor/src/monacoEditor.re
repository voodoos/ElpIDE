type editor;

type languages;

type iDisposable;

type monaco = {
  .
  "editor": editor,
  "languages": languages,
};

let monacoRef: ref(option(monaco)) = ref(None);

[@bs.send] external register : (languages, Js.t(_)) => unit = "";

[@bs.send]
external setMonarchTokensProvider : (languages, string, 'a) => iDisposable =
  "";

[@bs.send] external create : (editor, Dom.element, 'a) => unit = "";

let require = () => {
  BaseJs.require(
    "monaco-editor/esm/vs/editor/browser/controller/coreCommands.js",
  );
  BaseJs.require(
    "monaco-editor/esm/vs/editor/contrib/bracketMatching/bracketMatching.js",
  );
  BaseJs.require("monaco-editor/esm/vs/editor/contrib/folding/folding.js");
  BaseJs.require(
    "monaco-editor/esm/vs/editor/contrib/find/findController.js",
  );
  let monaco: monaco =
    BaseJs.requireAs("monaco-editor/esm/vs/editor/editor.api.js");
  monaco;
};

let rec getMonaco = () =>
  switch (monacoRef^) {
  | Some(m) => m
  | None =>
    monacoRef := Some(require());
    getMonaco();
  };