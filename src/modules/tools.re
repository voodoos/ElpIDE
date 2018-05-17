let to_js_bool = b => b ? Js.true_ : Js.false_;

let isElpiFile = name =>
  Js.Re.test(name, [%bs.re "/^[^\\.]+\\.(?:elpi|mod|sig)$/gm"]);

let isMltsFile = name =>
  Js.Re.test(name, [%bs.re "/^[^\\.]+\\.(?:mlts)$/gm"]);

let isSupportedFile = name => isElpiFile(name) || isMltsFile(name);