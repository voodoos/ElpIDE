open Sui_enums;

/* Unsafe type and functions for handling "polymorphic" jsprops : */
type js;

external jsOfBool : Js.boolean => js = "%identity";

external jsOfString : string => js = "%identity";

external jsOfReactClass : ReasonReact.reactClass => js = "%identity";

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

let fromTextAlign = makeJsOptionMap(textAlignToJs);

let fromTopOrBottom = makeJsOptionMap(topOrBottomToJs);

let fromTopOrMiddleOrBottom = makeJsOptionMap(topOrMiddleOrBottomToJs);

/* For size enums props */
let fromSize = makeJsOptionMap(sizeToJs);

let fromSizeHeader = makeJsOptionMap(sizeHeaderToJs);

let fromSizeModal = makeJsOptionMap(sizeModalToJs);

let fromSizePopup = makeJsOptionMap(sizePopupToJs);

let fromSmallOrLarge = makeJsOptionMap(smallOrLargeToJs);

let fromPos = makeJsOptionMap(posToJs);

let fromLabelPos = makeJsOptionMap(labelPosToJs);

/* For width enums props */
let fromWidth = makeJsOptionMap(widthToJs);

let fromSBWidth = makeJsOptionMap(sbWidthToJs);

let fromSBAnimation = makeJsOptionMap(sbAnimationToJs);

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

let fromBoolOrStringAux = bORe =>
  switch (bORe) {
  | `Bool(b) => jsOfBool(Js.Boolean.to_js_boolean(b))
  | `String(s) => jsOfString(s)
  };

let fromBoolOrString = b =>
  Js.Option.map((. a) => fromBoolOrStringAux(a), b);

let fromNumAux = bORe =>
  switch (bORe) {
  | `Int(i) => jsOfInt(i)
  | `Float(f) => jsOfFloat(f)
  };

let fromNum = b => Js.Option.map((. a) => fromNumAux(a), b);

let fromBoolOrVeryAux = bORe =>
  switch (bORe) {
  | `true_ => jsOfBool(Js.true_)
  | `false_ => jsOfBool(Js.true_)
  | `very => jsOfString("very")
  };

let fromBoolOrVery = b => Js.Option.map((. a) => fromBoolOrVeryAux(a), b);

let fromBoolOrCenteredAux = bORe =>
  switch (bORe) {
  | `true_ => jsOfBool(Js.true_)
  | `false_ => jsOfBool(Js.true_)
  | `centered => jsOfString("centered")
  };

let fromBoolOrCentered = b =>
  Js.Option.map((. a) => fromBoolOrCenteredAux(a), b);

let fromEqualAux = a =>
  switch (a) {
  | `equal => jsOfString("equal")
  };

let fromEqual = b => Js.Option.map((. a) => fromEqualAux(a), b);

let fromComponentOrStringAux = a =>
  switch (a) {
  | `Comp(r) => r
  | `String(s) => jsOfString(s)
  };

let fromComponentOrString = b =>
  Js.Option.map((. a) => fromComponentOrStringAux(a), b);

let fromBoolOrInvertedOrBlurringAux = bORe =>
  switch (bORe) {
  | `true_ => jsOfBool(Js.true_)
  | `false_ => jsOfBool(Js.true_)
  | `inverted => jsOfString("inverted")
  | `blurring => jsOfString("blurring")
  };

let fromBoolOrInvertedOrBlurring = b =>
  Js.Option.map((. a) => fromBoolOrInvertedOrBlurringAux(a), b);

let fromBoolOrTopOrBottomAux = bORe =>
  switch (bORe) {
  | `true_ => jsOfBool(Js.true_)
  | `false_ => jsOfBool(Js.true_)
  | `top => jsOfString("top")
  | `bottom => jsOfString("bottom")
  };

let fromBoolOrTopOrBottom = b =>
  Js.Option.map((. a) => fromBoolOrTopOrBottomAux(a), b);

let fromStringOrReactClassAux = a =>
  switch (a) {
  | `react(r) => jsOfReactClass(r)
  | `str(s) => jsOfString(s)
  };

let fromStringOrReactClass = b =>
  Js.Option.map((. a) => fromStringOrReactClassAux(a), b);