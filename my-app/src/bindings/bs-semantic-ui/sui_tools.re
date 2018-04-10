open Sui_enums;

/* Unsafe type and functions for handling "polymorphic" jsprops : */
type js;

external jsOfBool : Js.boolean => js = "%identity";

external jsOfString : string => js = "%identity";

external jsOfInt : int => js = "%identity";

external jsOfFloat : float => js = "%identity";

/* For maximum code factorization (and unreadability) the following lines make use of *partial function application* */
let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);

/* For boolean props */
let fromBool = makeJsOptionMap(Js.Boolean.to_js_boolean);

/* For color enums props */
let fromColor = makeJsOptionMap(colorToJs);

let fromAllDir = makeJsOptionMap(allDirToJs);

let fromLeftOrRight = makeJsOptionMap(leftOrRightToJs);

let fromLeftOrCenterOrRight = makeJsOptionMap(leftOrCenterOrRightToJs);

let fromTopOrBottom = makeJsOptionMap(topOrBottomToJs);

let fromTopOrMiddleOrBottom = makeJsOptionMap(topOrMiddleOrBottomToJs);

/* For size enums props */
let fromSize = makeJsOptionMap(sizeToJs);

let fromSmallOrLarge = makeJsOptionMap(smallOrLargeToJs);

/* For width enums props */
let fromWidth = makeJsOptionMap(widthToJs);

/* For button animation enums props */
let toAnimButaux = bORe =>
  switch (bORe) {
  | `Bool(b) => jsOfBool(Js.Boolean.to_js_boolean(b))
  | `Enum(e) => jsOfString(animButtonToJs(e))
  };

let fromAnimBut = b => Js.Option.map((. a) => toAnimButaux(a), b);

/* For tabindex props */
let toNumOrStringAux = bORe =>
  switch (bORe) {
  | `Int(i) => jsOfInt(i)
  | `Float(f) => jsOfFloat(f)
  | `String(s) => jsOfString(s)
  };

let fromNumOrString = b => Js.Option.map((. a) => toNumOrStringAux(a), b);

let fromNumAux = bORe =>
  switch (bORe) {
  | `Int(i) => jsOfInt(i)
  | `Float(f) => jsOfFloat(f)
  };

let fromNum = b => Js.Option.map((. a) => fromNumAux(a), b);

let fromBoolOrVeryAux = bORe =>
  switch (bORe) {
  | `Bool(b) => jsOfBool(Js.Boolean.to_js_boolean(b))
  | `Very => jsOfString("very")
  };

let fromBoolOrVery = b => Js.Option.map((. a) => fromBoolOrVeryAux(a), b);