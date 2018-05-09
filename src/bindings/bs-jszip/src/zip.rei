type jszip;

type zipObject;

type wOptions;

type cOptions;

type compression = [ | `STORE | `DEFLATE];

let create: unit => jszip;

/** "read" replaces the two reading cases of
 * the jszip overloaded method "file".
 *
 * Use it with a string or a regex, piping is recommended :
 *      let zip = create();
 *      zip |. read(`name("toto"))
 *      zip |. read(`regex([%re "/toto/"]))
 */
let read: (jszip, [ | `name(string) | `regex(Js.Re.t)]) => zipObject;

/** "write" replace the writing case of
 * the jszip overloaded method "file".
 *
 *  It takes an optionnal "options" argument.
 *  To prepare these options a "makeWriteOptions"
 *  helper is provided (see below)
 *
 *   Ex :
 *     zip |. write(
 *             "name",
 *             `str("data"),
 *             ~options=makeWriteOptions(~base64=false, ()),
 *           );
 *
 *  TODO: second argument can be :
 *      String/ArrayBuffer/Uint8Array/Buffer/Blob/Promise/Nodejs stream
 */
let write:
  (jszip, ~options: wOptions=?, string, [ | `str(string) | `trustme('a)]) =>
  jszip;

/** "makeWriteOptions" allows one to build the optionnal options
 *  that the write function accepts. Don't forget the trailing unit !
 *
 *   Ex : makeWriteOptions(~base64=true, ())
 *
 * TODO: should check that unixPermissions it 16bit number
 * and dosPermissions is 6 bits nnumber...
 *
 */
let makeWriteOptions:
  (
    ~base64: bool=?,
    ~binary: bool=?,
    ~date: string=?,
    ~compression: compression=?,
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
 *  Example :
 * zip
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