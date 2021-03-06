/* TODO: patch the monaco-editor-sample wrong example... */
type todo;
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
  type t = {
    .
    "changes": array(IModelContentChange.t),
    "isFlush": bool,
  };
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
                  "preserveBOM": bool,
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

/*******************
 **** LANGUAGES ****
 *******************/
[@bs.send] external register : (languages, Js.t(_)) => unit = "";

[@bs.send]
external setMonarchTokensProvider : (languages, string, 'a) => IDisposable.t =
  "";

/******************
 ***** EDITOR *****
 ******************/
[@bs.send]
external create : (editor, Dom.element, 'a) => IStandaloneCodeEditor.t = "";

[@bs.send]
external createModel :
  (editor, /* value */ string, ~language: string=?, ~uri: todo=?, unit) =>
  ITextModel.t =
  "";

/******************
 ***** WORKER *****
 ******************/
type worker;

[@bs.new] external newWorker : string => worker = "Worker";

type self;

[@bs.val] external self : self = "self";

[@bs.set]
external setMonacoEnvironment :
  (self, {. "getWorker": (string, string) => 'a}) => unit =
  "MonacoEnvironment";

let require = () => {
  let monaco: monaco =
    BaseJs.requireAs("monaco-editor/esm/vs/editor/editor.main.js");
  setMonacoEnvironment(
    self,
    {
      "getWorker": (_moduleId, label) =>
        /* TODO: weirdly only editor worker seems to work */
        switch (label) {
        | "json" => newWorker("./workers/json.worker.js")
        | "css" => newWorker("./workers/css.worker.js")
        | "html" => newWorker("./workers/html.worker.js")
        | "typescript"
        | "javascript" => newWorker("./workers/ts.worker.js")
        | _ => newWorker("./workers/editor.worker.js")
        },
    },
  );
  monaco;
};

let rec getMonaco = () =>
  switch (monacoRef^) {
  | Some(m) => m
  | None =>
    monacoRef := Some(require());
    getMonaco();
  };
/*
   // (1) Desired editor features:
 import 'monaco-editor/esm/vs/editor/browser/controller/coreCommands.js';
 // import 'monaco-editor/esm/vs/editor/browser/widget/codeEditorWidget.js';
 // import 'monaco-editor/esm/vs/editor/browser/widget/diffEditorWidget.js';
 // import 'monaco-editor/esm/vs/editor/browser/widget/diffNavigator.js';
 // import 'monaco-editor/esm/vs/editor/contrib/bracketMatching/bracketMatching.js';
 // import 'monaco-editor/esm/vs/editor/contrib/caretOperations/caretOperations.js';
 // import 'monaco-editor/esm/vs/editor/contrib/caretOperations/transpose.js';
 // import 'monaco-editor/esm/vs/editor/contrib/clipboard/clipboard.js';
 // import 'monaco-editor/esm/vs/editor/contrib/codelens/codelensController.js';
 // import 'monaco-editor/esm/vs/editor/contrib/colorPicker/colorDetector.js';
 // import 'monaco-editor/esm/vs/editor/contrib/comment/comment.js';
 // import 'monaco-editor/esm/vs/editor/contrib/contextmenu/contextmenu.js';
 // import 'monaco-editor/esm/vs/editor/contrib/cursorUndo/cursorUndo.js';
 // import 'monaco-editor/esm/vs/editor/contrib/dnd/dnd.js';
 import 'monaco-editor/esm/vs/editor/contrib/find/findController.js';
 // import 'monaco-editor/esm/vs/editor/contrib/folding/folding.js';
 // import 'monaco-editor/esm/vs/editor/contrib/format/formatActions.js';
 // import 'monaco-editor/esm/vs/editor/contrib/goToDeclaration/goToDeclarationCommands.js';
 // import 'monaco-editor/esm/vs/editor/contrib/goToDeclaration/goToDeclarationMouse.js';
 // import 'monaco-editor/esm/vs/editor/contrib/gotoError/gotoError.js';
 // import 'monaco-editor/esm/vs/editor/contrib/hover/hover.js';
 // import 'monaco-editor/esm/vs/editor/contrib/inPlaceReplace/inPlaceReplace.js';
 // import 'monaco-editor/esm/vs/editor/contrib/linesOperations/linesOperations.js';
 // import 'monaco-editor/esm/vs/editor/contrib/links/links.js';
 // import 'monaco-editor/esm/vs/editor/contrib/multicursor/multicursor.js';
 // import 'monaco-editor/esm/vs/editor/contrib/parameterHints/parameterHints.js';
 // import 'monaco-editor/esm/vs/editor/contrib/quickFix/quickFixCommands.js';
 // import 'monaco-editor/esm/vs/editor/contrib/referenceSearch/referenceSearch.js';
 // import 'monaco-editor/esm/vs/editor/contrib/rename/rename.js';
 // import 'monaco-editor/esm/vs/editor/contrib/smartSelect/smartSelect.js';
 // import 'monaco-editor/esm/vs/editor/contrib/snippet/snippetController2.js';
 // import 'monaco-editor/esm/vs/editor/contrib/suggest/suggestController.js';
 // import 'monaco-editor/esm/vs/editor/contrib/toggleTabFocusMode/toggleTabFocusMode.js';
 // import 'monaco-editor/esm/vs/editor/contrib/wordHighlighter/wordHighlighter.js';
 // import 'monaco-editor/esm/vs/editor/contrib/wordOperations/wordOperations.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/accessibilityHelp/accessibilityHelp.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/inspectTokens/inspectTokens.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/iPadShowKeyboard/iPadShowKeyboard.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/quickOpen/quickOutline.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/quickOpen/gotoLine.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/quickOpen/quickCommand.js';
 // import 'monaco-editor/esm/vs/editor/standalone/browser/toggleHighContrast/toggleHighContrast.js';
 import * as monaco from 'monaco-editor/esm/vs/editor/editor.api.js';

 // (2) Desired languages:
 // import 'monaco-editor/esm/vs/language/typescript/monaco.contribution';
 // import 'monaco-editor/esm/vs/language/css/monaco.contribution';
 // import 'monaco-editor/esm/vs/language/json/monaco.contribution';
 // import 'monaco-editor/esm/vs/language/html/monaco.contribution';
 // import 'monaco-editor/esm/vs/basic-languages/bat/bat.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/coffee/coffee.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/cpp/cpp.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/csharp/csharp.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/csp/csp.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/css/css.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/dockerfile/dockerfile.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/fsharp/fsharp.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/go/go.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/handlebars/handlebars.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/html/html.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/ini/ini.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/java/java.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/less/less.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/lua/lua.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/markdown/markdown.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/msdax/msdax.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/mysql/mysql.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/objective-c/objective-c.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/pgsql/pgsql.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/php/php.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/postiats/postiats.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/powershell/powershell.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/pug/pug.contribution.js';
 import 'monaco-editor/esm/vs/basic-languages/python/python.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/r/r.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/razor/razor.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/redis/redis.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/redshift/redshift.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/ruby/ruby.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/sb/sb.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/scss/scss.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/solidity/solidity.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/sql/sql.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/swift/swift.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/vb/vb.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/xml/xml.contribution.js';
 // import 'monaco-editor/esm/vs/basic-languages/yaml/yaml.contribution.js';

 */