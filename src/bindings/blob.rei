type t;

type blobOptions;

type endings = [ | `native | `transparent];

let create: (~options: blobOptions=?, array('a)) => t;

let makeOptions:
  (~type_: Mime.types=?, ~endings: endings=?, unit) => blobOptions;

let isClosed: t => Js.boolean;

let size: t => int;

let type_: t => string;

let close: (t, unit) => unit;

/**
 * TODO: inexact
 */
let slice: (t, int, int) => t;