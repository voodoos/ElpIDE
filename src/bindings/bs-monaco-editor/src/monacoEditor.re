

type monaco;

let require = () => {
    
BaseJs.require("monaco-editor/esm/vs/editor/browser/controller/coreCommands.js");
BaseJs.require("monaco-editor/esm/vs/editor/contrib/bracketMatching/bracketMatching.js");
BaseJs.require("monaco-editor/esm/vs/editor/contrib/folding/folding.js");
BaseJs.require("monaco-editor/esm/vs/editor/contrib/find/findController.js");
let monaco : monaco = BaseJs.requireAs("monaco-editor/esm/vs/editor/editor.api.js");
monaco
};

[@bs.val]
[@bs.scope  ("monaco","editor")]
external create_monaco : (Dom.element, 'a) => unit = "create";
