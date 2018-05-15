/**
 * Bucklescript bindings for JSZip
 *
 * Please check the docs on https://stuk.github.io/jszip/
 */
open Options;

module Object = ZipObject;

type jszip;

/**
 * If the browser supports them, JSZip can take advantage of some “new” features : ArrayBuffer, Blob, Uint8Array. To know if JSZip can use them, you can check the JSZip.support object. It contains the following boolean properties :

    arraybuffer : true if JSZip can read and generate ArrayBuffer, false otherwise.
    uint8array : true if JSZip can read and generate Uint8Array, false otherwise.
    blob : true if JSZip can generate Blob, false otherwise.
    nodebuffer : true if JSZip can read and generate nodejs Buffer, false otherwise.
    nodestream : true if JSZip can read and generate nodejs stream, false otherwise.
 */
let support: {
  .
  "arraybuffer": Js.boolean,
  "uint8array": Js.boolean,
  "blob": Js.boolean,
  "nodebuffer": Js.boolean,
  "nodestream": Js.boolean,
};

/**
 * TODO? JSZip.external
 */
/**
 * The version of JSZip as a string.
 */
let version: string;

/**
 * Create a new JSZip instance.
 */
let create: unit => jszip;

/** `read` replaces the two reading cases of
    the JSZip overloaded method `file`.

    Use it with a string or a regex, piping is recommended :

    let zip = create();
    zip |. read(`name("toto"))
    zip |. read(`regex([%re "/toto/"]))
 */
let read:
  (jszip, [ | `name(string) | `regex(Js.Re.t)]) => Js.nullable(ZipObject.t);

/** `write` replace the writing case of
    the JSZip overloaded method `file`.

    It takes an optionnal "options" argument.
    To prepare these options a "makeWriteOptions"
    helper is provided (see below) :

    zip |. write(
            "name",
            `str("data"),
            ~options=makeWriteOptions(~base64=false, ()),
        );

    TODO: second argument can be :
       String/ArrayBuffer/Uint8Array/Buffer/Blob/Promise/Nodejs stream
 */
let write:
  (
    jszip,
    ~options: Options.wOptions=?,
    string,
    [ | `str(string) | `trustme('a)]
  ) =>
  jszip;

/**
 * Create a directory if it doesn’t exist, return a new JSZip object with the new folder as root.
 */
let folder: (jszip, [ | `name(string) | `regex(Js.Re.t)]) => ZipObject.t;

/**
 * Call a callback function for each entry at this folder level.
 * The callback has the following signature :
 *  function (relativePath: string, file: zipObject) {...}
 *
 * Ex: zip |. Zip.forEach((p, z) => Js.log2(p, z));
 */
let forEach: (jszip, (string, ZipObject.t) => unit) => unit;

/**
 * Filter nested files/folders with the specified function.
 */
let filter: (jszip, (string, ZipObject.t) => bool) => array(ZipObject.t);

/**
 * Delete a file or folder (recursively).
 */
let remove: (jszip, string) => jszip;

/**
 * Generates the complete zip file at the current folder level.
 *
 * TODO: other types, securize options (should be string for string etc)
 */
let generateAsyncUint8:
  (jszip, ~onUpdate: Converters.metadata => unit=?, asyncUint8Options) =>
  Js.Promise.t(Js.Typed_array.Uint8Array.t);

let generateAsyncBlob:
  (jszip, ~onUpdate: Converters.metadata => unit=?, asyncBlobOptions) =>
  Js.Promise.t(Blob.t);

/**
 * Generates the complete zip file as a nodejs stream.
 *
 * The type parameter has here the default value of nodebuffer.
 * Only nodebuffer is currently supported.
 *
 * TODO: node stream3 ?
 */
/*
 let generateNodeStream:
   (jszip, ~onUpdate: metadata => unit=?, asyncOptions) => Js.Promise.t('a);
 */
/**
 * Generates the complete zip file with the internal stream implementation.
 *
 * TODO: do other types
 * TODO:  securize options (should be string for string etc)
 */
let generateInternalStreamString:
  (jszip, asyncStringOptions) => StreamHelper.t(string);

let generateInternalStreamUint8:
  (jszip, asyncUint8Options) => StreamHelper.t(Js.Typed_array.Uint8Array.t);

/**
 * Read an existing zip and merge the data in
 * the current JSZip object at the current folder level.
 * This technique has some limitations, see here.
 * If the JSZip object already contains entries,
 * new entries will be merged. If two have the same name,
 * the loaded one will replace the other.
 *
 * Returns : A Promise with the updated zip object.
 * The promise can fail if the loaded data is not valid zip data
 * or if it uses unsupported features (multi volume,
 * password protected, etc).
 *
 * TODO: Test ! Are these the right types ?
 */
let loadAsync:
  (
    jszip,
    ~options: loadOptions=?,
    [
      | `str(string)
      | `uint8(Js.Typed_array.Uint8Array.t)
      | `buffers(Js.Typed_array.array_buffer)
      | `promise(Js.Promise.t('a))
      | `blob(Blob.t)
      | `unsafe('a)
    ]
  ) =>
  Js.Promise.t(jszip);

/** `makeWriteOptions` allows one to build the optionnal options
   that the write function accepts. Don't forget the trailing unit !

    Ex : makeWriteOptions(~base64=true, ())

  TODO: should check that unixPermissions it 16bit number
  and dosPermissions is 6 bits nnumber...

 */
let makeWriteOptions:
  (
    ~base64: bool=?,
    ~binary: bool=?,
    ~date: string=?,
    ~compression: Converters.compression=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~optimizedBinaryString: bool=?,
    ~createFolders: bool=?,
    ~unixPermissions: int=?,
    ~dosPermissions: int=?,
    ~dir: bool=?,
    unit
  ) =>
  Options.wOptions;

/** For now the only compression option is the level
   Example :
  zip
    |. Zip.write(
        "name",
        `str("data"),
        ~options=
        Zip.makeWriteOptions(
            ~compression=`STORE,
            ~compressionOptions=Zip.makeCompressionOptions(6),
            (),
        ),
    );
*/
let makeCompressionOptions: int => cOptions;

let makeAsyncBlobOptions:
  /*~type_: Converters.types=?,*/
  (
    ~compression: Converters.compression=?,
    ~compressionOptions: Options.cOptions=?,
    ~comment: string=?,
    ~mimeType: Mime.types=?,
    ~platform: Converters.platforms=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncBlobOptions;

let makeAsyncStringOptions:
  /*~type_: Converters.types=?,*/
  (
    ~compression: Converters.compression=?,
    ~compressionOptions: Options.cOptions=?,
    ~comment: string=?,
    ~mimeType: Mime.types=?,
    ~platform: Converters.platforms=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncStringOptions;

let makeAsyncUint8Options:
  /*~type_: Converters.types=?,*/
  (
    ~compression: Converters.compression=?,
    ~compressionOptions: Options.cOptions=?,
    ~comment: string=?,
    ~mimeType: Mime.types=?,
    ~platform: Converters.platforms=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncUint8Options;

let makeLoadOptions:
  (
    ~base64: bool=?,
    ~checkCRC32: bool=?,
    ~optimizedBinaryString: bool=?,
    ~createFolders: bool=?,
    ~decodeFileName: Js.Typed_array.Uint8Array.t => string=?,
    unit
  ) =>
  loadOptions;