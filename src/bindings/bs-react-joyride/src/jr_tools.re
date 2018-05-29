type js;

[@bs.deriving jsConverter]
type evt = [ | `click | `hover];

[@bs.deriving jsConverter]
type plcmt = [ | `top | `bottom | `left | `right | `auto | `center];

[@bs.deriving jsConverter]
type plcmtB = [ | `top | `bottom | `left | `right];

/* For maximum code factorization (and unreadability) the following lines make use of *partial function application* */
let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);

let fromEvt = makeJsOptionMap(evtToJs);

let fromPlcmt = makeJsOptionMap(plcmtToJs);

let fromPlcmtB = makeJsOptionMap(plcmtBToJs);

external jsOfReactClass : ReasonReact.reactClass => js = "%identity";

external jsOfReactElt : ReasonReact.reactElement => js = "%identity";

external jsOfString : string => js = "%identity";

let fromStringOrReactClassAux = a =>
  switch (a) {
  | `react(r) => jsOfReactClass(r)
  | `str(s) => jsOfString(s)
  };

let fromStringOrReactClass = b =>
  Js.Option.map((. a) => fromStringOrReactClassAux(a), b);

let fromStringOrReactEltAux = a =>
  switch (a) {
  | `react(r) => jsOfReactElt(r)
  | `str(s) => jsOfString(s)
  };

let fromStringOrReactElt = b =>
  Js.Option.map((. a) => fromStringOrReactEltAux(a), b);