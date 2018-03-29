open Sui_enums;

/* For maximum code factorization (and unreadability) the following lines make use of *partial function application* */
let makeJsOptionMap = (f, b) =>Js.Option.map([@bs](a => f(a)), b);

/* For boolean props */
let toJsOptionBool = makeJsOptionMap(Js.Boolean.to_js_boolean);

/* For color enums props */
let toJsOptionColor = makeJsOptionMap(colorToJs);

/* For attached enums props */
let toJsOptionAttached = makeJsOptionMap(attachedToJs);
/* equivalent to : let toJsOptionAttached = (c) => Js.Option.map([@bs](a => attachedToJs(a)), c); */

/* For floated enums props */
let toJsOptionFloated = makeJsOptionMap(floatedToJs);

/* For size enums props */
let toJsOptionSize = makeJsOptionMap(sizeToJs);