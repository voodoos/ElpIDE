/**
 * Bucklescript bindings for JSZip
 * 
 * Please check the docs on https://stuk.github.io/jszip/ !
 */

type jszip;

type zipObject;

type wOptions;

type cOptions;

type asyncOptions;

let create: unit => jszip;

type metadata = {
  .
  "percent": float,
  "currentFile": string,
};

/** `read` replaces the two reading cases of
    the JSZip overloaded method `file`.

    Use it with a string or a regex, piping is recommended :

    let zip = create();
    zip |. read(`name("toto"))
    zip |. read(`regex([%re "/toto/"]))


    TODO: returns nullable !
 */
let read:
  (jszip, [ | `name(string) | `regex(Js.Re.t)]) => Js.nullable(zipObject);

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
  (jszip, ~options: wOptions=?, string, [ | `str(string) | `trustme('a)]) =>
  jszip;

/**
 * Create a directory if it doesn’t exist, return a new JSZip object with the new folder as root.
 */
let folder: (jszip, [ | `name(string) | `regex(Js.Re.t)]) => zipObject;

/**
 * Call a callback function for each entry at this folder level.
 * The callback has the following signature :
 *  function (relativePath: string, file: zipObject) {...}
 *
 * Ex: zip |. Zip.forEach((p, z) => Js.log2(p, z));
 */
let forEach: (jszip, (string, zipObject) => unit) => unit;

/**
 * Filter nested files/folders with the specified function.
 */
let filter: (jszip, (string, zipObject) => bool) => array(zipObject);

/**
 * Delete a file or folder (recursively).
 */
let remove: (jszip, string) => jszip;

/**
 * Generates the complete zip file at the current folder level.
 * 
 * TODO: is the return type ok ?
 * TODO: make safe versions for specific cases of type
 */
let generateAsync: (jszip, ~onUpdate: metadata => unit=?, asyncOptions) => Js.Promise.t('a);

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
  wOptions;

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


let makeAsyncOptions:
  (
    ~type_: Converters.types=?,
    ~compression: Converters.compression=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~mimeType: Mime.types=?,
    ~platform: Converters.platforms=?,
    ~encodeFileName: (string => Js.Typed_array.Uint8Array.t)=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncOptions;