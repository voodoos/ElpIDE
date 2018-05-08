type zipObject;

type jszip;

/* = {. 
    [@bs.meth] "read": string => zipObject, 
    [@bs.meth] "readRe": Js.Re.t => zipObject
};*/

[@bs.new] [@bs.module]
/* Logging callback */
external create : unit => jszip = "JSZip";

/** "read" replace the two reading cases of 
 * the jszip overloaded method "file".
 * 
 * Use it with a string or a regex, piping is recommended :
 *      let zip = create();
 *      zip |. read(`name("toto"))
 *      zip |. read(`regex([%re "/toto/"]))
 */
[@bs.send]
external read : jszip => ([@bs.unwrap] [
    | `name(string)
    | `regex(Js.Re.t)
    ]) => zipObject = "file";

/** "write" replace the writing case of 
 * the jszip overloaded method "file".
 * 
 *  TODO: second argument can be :
 *      String/ArrayBuffer/Uint8Array/Buffer/Blob/Promise/Nodejs stream
 */
[@bs.send]
external write : jszip => string => ([@bs.unwrap] [
    | `str(string)
    | `trustme('a)
    ]) => writeOptions => zipObject = "file";
    

create();