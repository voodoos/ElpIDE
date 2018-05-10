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

[@bs.send]
external asyncAuxString :
  (t, [@bs.as "string"] _, ~onUpdate: {. "percent": float} => unit=?, unit) =>
  Js.Promise.t(string) =
  "async";

[@bs.send]
external asyncAuxUint8 :
  (
    t,
    [@bs.as "uint8array"] _,
    ~onUpdate: {. "percent": float} => unit=?,
    unit
  ) =>
  Js.Promise.t(Js.Typed_array.Uint8Array.t) =
  "async";

[@bs.send]
external nodeStreamAux :
  (t, string, ~onUpdate: {. "percent": float} => unit=?, unit) =>
  Js.Promise.t('a) =
  "nodeStream";

[@bs.send]
external internalStreamString :
  (t, [@bs.as "string"] _) => StreamHelper.t(string) =
  "internalStream";

[@bs.send]
external internalStreamUint8 :
  (t, [@bs.as "uint8array"] _) => StreamHelper.t(Js.Typed_array.Uint8Array.t) =
  "internalStream";

let asyncString = (zobj, ~onUpdate=?, ()) =>
  asyncAuxString(zobj, ~onUpdate?, ());

let asyncUint8 = (zobj, ~onUpdate=?, ()) =>
  asyncAuxUint8(zobj, ~onUpdate?, ());

let nodeStream = (zobj, ~onUpdate=?, type_) =>
  nodeStreamAux(zobj, type_, ~onUpdate?, ());