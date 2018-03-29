open Sui_enums;

/* For boolean props */
let toJsOptionBool = (b) => Js.Option.map([@bs](a => Js.Boolean.to_js_boolean(a)), b);

/* For color enums props */
let toJsOptionColor = (c) => Js.Option.map([@bs](a => colorToJs(a)), c);