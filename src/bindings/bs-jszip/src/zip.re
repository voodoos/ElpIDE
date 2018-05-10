open Converters;

type jszip;

type zipObject;

type wOptions;

type cOptions;

type asyncOptions;

type compression = Converters.compression;

type metadata = {
  .
  "percent": float,
  "currentFile": string,
};

/** EXTERNALS */ [@bs.new] [@bs.module]
external create : unit => jszip = "JSZip";

[@bs.send]
external read :
  (jszip, [@bs.unwrap] [ | `name(string) | `regex(Js.Re.t)]) =>
  Js.nullable(zipObject) =
  "file";

[@bs.send]
external writeAux :
  (
    jszip,
    string,
    [@bs.unwrap] [ | `str(string) | `trustme('a)],
    ~options: wOptions=?,
    unit
  ) =>
  jszip =
  "file";

[@bs.send]
external folder :
  (jszip, [@bs.unwrap] [ | `name(string) | `regex(Js.Re.t)]) => zipObject =
  "folder";

[@bs.send]
external forEach : (jszip, (string, zipObject) => unit) => unit = "forEach";

[@bs.send]
external filter : (jszip, (string, zipObject) => bool) => array(zipObject) =
  "filter";

[@bs.send] external remove : (jszip, string) => jszip = "remove";

[@bs.send]
external generateAsyncAux :
  (jszip, asyncOptions, ~onUpdate: metadata => unit=?, unit) =>
  Js.Promise.t('a) =
  "generateAsync";

[@bs.send]
external generateNodeStreamAux :
(jszip, asyncOptions, ~onUpdate: metadata => unit=?, unit) =>
Js.Promise.t('a) =
"generateNodeStream";

[@bs.send]
external generateInternalStream :
(jszip, asyncOptions) =>
Js.Promise.t('a) =
"generateInternalStream";

/** UTILITIES */
let write = (jszip, ~options=?, name, data) =>
  writeAux(jszip, name, data, ~options?, ());

let generateAsync = (jszip, ~onUpdate=?, options) =>
  generateAsyncAux(jszip, options, ~onUpdate?, ());


let generateNodeStream = (jszip, ~onUpdate=?, options) =>
  generateNodeStreamAux(jszip, options, ~onUpdate?, ());

/* Utilities to build the options */
[@bs.obj]
external makeWriteOptionsAux :
  (
    ~base64: Js.boolean=?,
    ~binary: Js.boolean=?,
    ~date: Js.Date.t=?,
    ~compression: string=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~optimizedBinaryString: Js.boolean=?,
    ~createFolders: Js.boolean=?,
    ~unixPermissions: int=?,
    ~dosPermissions: int=?,
    ~dir: Js.boolean=?,
    unit
  ) =>
  wOptions =
  "";

[@bs.obj]
external makeCompressionOptionsAux : (~level: int=?, unit) => cOptions = "";

let makeWriteOptions =
    (
      ~base64=?,
      ~binary=?,
      ~date=?,
      ~compression=?,
      ~compressionOptions=?,
      ~comment=?,
      ~optimizedBinaryString=?,
      ~createFolders=?,
      ~unixPermissions=?,
      ~dosPermissions=?,
      ~dir=?,
      (),
    ) =>
  makeWriteOptionsAux(
    ~base64=?fromBool(base64),
    ~binary=?fromBool(binary),
    ~date=?dateFromString(date),
    ~compression=?fromCompression(compression),
    ~compressionOptions?,
    ~comment?,
    ~optimizedBinaryString=?fromBool(optimizedBinaryString),
    ~createFolders=?fromBool(createFolders),
    ~unixPermissions?,
    ~dosPermissions?,
    ~dir=?fromBool(dir),
    (),
  );

let makeCompressionOptions = lvl => makeCompressionOptionsAux(~level=lvl, ());

/* Utilities to build the options
       TODO: should not use 'a
   */
[@bs.obj]
external makeAsyncOptionsAux :
  (
    ~type_: string=?,
    ~compression: string=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~mimeType: string=?,
    ~platform: string=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: Js.boolean=?,
    ~createFolders: Js.boolean=?,
    unit
  ) =>
  asyncOptions =
  "";

 let makeAsyncOptions =
  (
    ~type_=?,
    ~compression=?,
    ~compressionOptions=?,
    ~comment=?,
    ~mimeType=?,
    ~platform=?,
    ~encodeFileName=?,
    ~streamFiles=?,
    ~createFolders=?,
    (),
  ) =>
makeAsyncOptionsAux(
  ~type_=?fromTypes(type_),
  ~compression=?fromCompression(compression),
  ~compressionOptions?,
  ~comment?,
  ~mimeType=?fromMimeTypes(mimeType),
  ~platform=?fromPlatforms(platform),
  ~encodeFileName?,
  ~streamFiles=?fromBool(streamFiles),
  ~createFolders=?fromBool(createFolders),
  (),
);