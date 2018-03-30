open Sui_enums;

/* Unsafe type and functions for handling "polymorphic" jsprops : */
type js;
external jsOfBool : Js.boolean => js = "%identity";
external jsOfString : string => js = "%identity";
external jsOfInt : int => js = "%identity";
external jsOfFloat : float => js = "%identity";

/* For maximum code factorization (and unreadability) the following lines make use of *partial function application* */
let makeJsOptionMap = (f, b) =>Js.Option.map([@bs](a => f(a)), b);

/* For boolean props */
let fromBool = makeJsOptionMap(Js.Boolean.to_js_boolean);

/* For color enums props */
let fromColor = makeJsOptionMap(colorToJs);

/* For attached enums props */
let fromAttached = makeJsOptionMap(attachedToJs);
/* equivalent to : let toJsOptionAttached = (c) => Js.Option.map([@bs](a => attachedToJs(a)), c); */

/* For floated enums props */
let fromFloated = makeJsOptionMap(floatedToJs);

/* For size enums props */
let fromSize = makeJsOptionMap(sizeToJs);

/* For width enums props */
let fromWidth = makeJsOptionMap(widthToJs);

/* For button animation enums props */
let toAnimButaux = (bORe) =>
    switch bORe {
    | `Bool(b) => jsOfBool(Js.Boolean.to_js_boolean(b))
    | `Enum(e) => jsOfString(animButtonToJs(e))
    };
let fromAnimBut = (b) => Js.Option.map([@bs](a => toAnimButaux(a)), b);

/* For tabindex props */
let toNumOrStringAux = (bORe) =>
    switch bORe {
    | `Int(i) => jsOfInt(i)
    | `Float(f) => jsOfFloat(f)
    | `String(s) => jsOfString(s)
    };
let fromNumOrString = (b) => Js.Option.map([@bs](a => toNumOrStringAux(a)), b);