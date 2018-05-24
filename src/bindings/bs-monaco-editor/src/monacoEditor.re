type editor;

type languages;

type monaco = {
  .
  "editor": editor,
  "languages": languages,
};

module IDisposable = {
  type t;
};

module IModelContentChange = {
  type t = {. "text": string};
};

module IModelContentChangedEvent = {
  type t = {. "changes": array(IModelContentChange.t)};
};

module IStandaloneCodeEditor = {
  type t;
  [@bs.send]
  external getValue :
    (
      t,
      ~options: {
                  .
                  "lineEnding": string,
                  "preserveBOM": Js.boolean,
                }
                  =?,
      unit
    ) =>
    string =
    "";
  [@bs.send] external setValue : (t, string) => unit = "";
  [@bs.send]
  external onDidChangeModelContent :
    (t, IModelContentChangedEvent.t => unit) => IDisposable.t =
    "";
};

module ITextModel = {
  type t;
};

let monacoRef: ref(option(monaco)) = ref(None);

[@bs.send] external register : (languages, Js.t(_)) => unit = "";

[@bs.send]
external setMonarchTokensProvider : (languages, string, 'a) => IDisposable.t =
  "";

[@bs.send]
external create : (editor, Dom.element, 'a) => IStandaloneCodeEditor.t = "";

[@bs.send] external getModel : editor => ITextModel.t = "";

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