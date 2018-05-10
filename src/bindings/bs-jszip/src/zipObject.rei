type t = {
  .
  "name": string,
  "dir": Js.boolean,
  "date": Js.Date.t,
  "comment": string,
  "unixPermissions": int,
  "dosPermissions": int,
  "options": {. "compression": string},
};

/**
 * Return a Promise of the content in the asked type.
 *
 * TODO: Do other types...
 */
let asyncString:
  (t, ~onUpdate: {. "percent": float} => unit=?, unit) =>
  Js.Promise.t(string);

let asyncUint8:
  (t, ~onUpdate: {. "percent": float} => unit=?, unit) =>
  Js.Promise.t(Js.Typed_array.Uint8Array.t);

/**
 * TODO: nodejs Streams3 ?
 */
/*
 let nodeStream:
   (t, ~onUpdate: {. "percent": float} => unit=?, string) => Js.Promise.t('a);
 */
/**
 * Return a StreamHelper of the content in the asked type.
 *
 * TODO: other types: string, binarystring, uint8array,
 *                        arraybuffer, nodebuffer
 */
let internalStreamString: t => StreamHelper.t(string);

let internalStreamUint8: t => StreamHelper.t(Js.Typed_array.Uint8Array.t);