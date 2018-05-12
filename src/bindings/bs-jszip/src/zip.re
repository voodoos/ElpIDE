module Object = ZipObject;

type jszip;

type metadata = Converters.metadata;

/** EXTERNALS */ [@bs.new] [@bs.module]
external create : unit => jszip = "jszip";

[@bs.val] [@bs.module "jszip"]
external support : {
  .
  "arraybuffer": Js.boolean,
  "uint8array": Js.boolean,
  "blob": Js.boolean,
  "nodebuffer": Js.boolean,
  "nodestream": Js.boolean,
} =
  "support";

[@bs.val] [@bs.module "jszip"] external version : string = "version";

[@bs.send]
external read :
  (jszip, [@bs.unwrap] [ | `name(string) | `regex(Js.Re.t)]) =>
  Js.nullable(ZipObject.t) =
  "file";

[@bs.send]
external writeAux :
  (
    jszip,
    string,
    [@bs.unwrap] [ | `str(string) | `trustme('a)],
    ~options: Options.wOptions=?,
    unit
  ) =>
  jszip =
  "file";

[@bs.send]
external folder :
  (jszip, [@bs.unwrap] [ | `name(string) | `regex(Js.Re.t)]) => ZipObject.t =
  "folder";

[@bs.send]
external forEach : (jszip, (string, ZipObject.t) => unit) => unit = "forEach";

[@bs.send]
external filter : (jszip, (string, ZipObject.t) => bool) => array(ZipObject.t) =
  "filter";

[@bs.send] external remove : (jszip, string) => jszip = "remove";

[@bs.send]
external generateAsyncUint8Aux :
  (jszip, Options.asyncUint8Options, ~onUpdate: metadata => unit=?, unit) =>
  Js.Promise.t(Js.Typed_array.Uint8Array.t) =
  "generateAsync";

[@bs.send]
external generateAsyncBlobAux :
  (jszip, Options.asyncBlobOptions, ~onUpdate: metadata => unit=?, unit) =>
  Js.Promise.t(Blob.t) =
  "generateAsync";

[@bs.send]
external generateInternalStreamString :
  (jszip, Options.asyncStringOptions) => StreamHelper.t(string) =
  "generateInternalStream";

[@bs.send]
external generateInternalStreamUint8 :
  (jszip, Options.asyncUint8Options) =>
  StreamHelper.t(Js.Typed_array.Uint8Array.t) =
  "generateInternalStream";

[@bs.send]
external loadAsyncAux :
  (
    jszip,
    /* TODO: test, are these the correct types ? */
    [@bs.unwrap] [
      | `str(string)
      | `uint8(Js.Typed_array.Uint8Array.t)
      | `buffers(Js.Typed_array.array_buffer)
      | `promise(Js.Promise.t('a))
      | `blob(Blob.t)
      | `unsafe('a)
    ],
    ~options: Options.loadOptions=?,
    unit
  ) =>
  Js.Promise.t(jszip) =
  "loadAsync";

/** UTILITIES */
let write = (jszip, ~options=?, name, data) =>
  writeAux(jszip, name, data, ~options?, ());

let generateAsyncUint8 = (jszip, ~onUpdate=?, options) =>
  generateAsyncUint8Aux(jszip, options, ~onUpdate?, ());

let generateAsyncBlob = (jszip, ~onUpdate=?, options) =>
  generateAsyncBlobAux(jszip, options, ~onUpdate?, ());

let loadAsync = (jszip, ~options=?, data) =>
  loadAsyncAux(jszip, data, ~options?, ());

let makeLoadOptions = Options.makeLoadOptions;

let makeWriteOptions = Options.makeWriteOptions;

let makeAsyncBlobOptions = Options.makeAsyncBlobOptions;

let makeAsyncStringOptions = Options.makeAsyncStringOptions;

let makeAsyncUint8Options = Options.makeAsyncUint8Options;

let makeCompressionOptions = Options.makeCompressionOptions;