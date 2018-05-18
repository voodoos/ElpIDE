let to_js_bool = b => b ? Js.true_ : Js.false_;

let isMimeZip = mime =>
  switch mime {
    | "application/x-compressed"| "application/x-zip-compressed" | "application/zip" | "multipart/x-zip" | "application/zip-compressed" 
  => true
  | _ => false
  };

let isElpiFile = name =>
  Js.Re.test(name, [%bs.re "/^[^\\.]+\\.(?:elpi|mod|sig)$/gm"]);

let isMltsFile = name =>
  Js.Re.test(name, [%bs.re "/^[^\\.]+\\.(?:mlts)$/gm"]);

let isSupportedFile = name => isElpiFile(name) || isMltsFile(name);

let notAlreadyLoadedMess = name =>
  ! Js.Re.test(name, [%bs.re "/(?:already loaded)/gm"]);