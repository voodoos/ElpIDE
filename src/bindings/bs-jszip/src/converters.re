/** This module provides easy conversion from
 * option(non-js-type) types to option(js-type)
 */
let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);

/* For boolean props */
let fromBool = makeJsOptionMap(Js.Boolean.to_js_boolean);

let dateFromString = makeJsOptionMap(Js.Date.fromString);

[@bs.deriving jsConverter]
type compression = [ | `STORE | `DEFLATE];

let fromCompression = makeJsOptionMap(compressionToJs);