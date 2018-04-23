type elpi = {.
  [@bs.meth] "compile": array({. "name": string, "content": string}) => unit,
  [@bs.meth] "queryAll": string => unit,
  [@bs.meth] "restart": unit => unit,
};

[@bs.new] [@bs.module "elpi-js"]
external create :
  (
    (string, string, string) => unit,
    (array({. "arg": string, "ass": string})) => unit
  ) =>
  elpi =
  "default";

/*

let elpi = ElpiJs.create(
  (l, p, t) => { Js.log(l);Js.log(p); Js.log(t) },
  (arg, ass) => { Js.log(arg); Js.log(ass) },
);

elpi##compile([|{ "name":"toto.elpi", "content":"hello \"world\"." }|]);
elpi##queryAll("hello A.");

*/