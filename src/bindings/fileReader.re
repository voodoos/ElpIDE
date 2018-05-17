/**
 * https://developer.mozilla.org/fr/docs/Web/API/FileReader
 */
type t;

/* = {. [@bs.set] "onload": ReactEventRe.Synthetic.t => unit};*/
[@bs.new] external create : unit => t = "FileReader";

/**
 * TODO: can also be an ArrayBuffer
 */ [@bs.get]
external getResultString : t => string = "result";

[@bs.set]
external setOnload : (t, ReactEventRe.Synthetic.t => unit) => unit = "onload";

[@bs.send] external readAsText : (t, 'a) => unit = "readAsText";