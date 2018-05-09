open Converters;

type jszip;
type zipObject;
type wOptions;
type cOptions;
type compression = Converters.compression;

[@bs.new] [@bs.module]
/* Logging callback */
external create : unit => jszip = "JSZip";

[@bs.send]
external read : jszip => ([@bs.unwrap] [
    | `name(string)
    | `regex(Js.Re.t)
    ]) => zipObject = "file";

[@bs.send]
external writeAux : jszip => string => ([@bs.unwrap] [
    | `str(string)
    | `trustme('a)
    ]) => (~options: wOptions=?) => unit => jszip = "file";
    
let write = (jszip, ~options=?, name, data) =>  writeAux(jszip, name, data, ~options?, ());

/* Utilities to build the options */
[@bs.obj]
external makeWriteOptionsAux:
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
external makeCompressionOptionsAux :
    (
    ~level: int=?,
    unit
    ) =>
    cOptions =
    "";

let makeWriteOptions 
    = (~base64=?, 
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
    ()) 
    => makeWriteOptionsAux(
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
        ()
        );

let makeCompressionOptions = (lvl) => makeCompressionOptionsAux(~level=lvl, ());