open Sui_enums;

/* Unsafe type and functions for handling "polymorphic" jsprops : */
type js;
external jsOfBool : Js.boolean => js = "%identity";
external jsOfString : string => js = "%identity";

/* For maximum code factorization (and unreadability) the following lines make use of *partial function application* */
let makeJsOptionMap = (f, b) =>Js.Option.map([@bs](a => f(a)), b);

/* For boolean props */
let toBool = makeJsOptionMap(Js.Boolean.to_js_boolean);

/* For color enums props */
let toColor = makeJsOptionMap(colorToJs);

/* For attached enums props */
let toAttached = makeJsOptionMap(attachedToJs);
/* equivalent to : let toJsOptionAttached = (c) => Js.Option.map([@bs](a => attachedToJs(a)), c); */

/* For floated enums props */
let toFloated = makeJsOptionMap(floatedToJs);

/* For size enums props */
let toSize = makeJsOptionMap(sizeToJs);

/* For button animation enums props */
let toAnimButaux = (bORe) =>
    switch bORe {
    | `Bool(b) => jsOfBool(Js.Boolean.to_js_boolean(b))
    | `Enum(e) => jsOfString(animButtonToJs(e))
    };
let toAnimBut = (b) => Js.Option.map([@bs](a => toAnimButaux(a)), b);
