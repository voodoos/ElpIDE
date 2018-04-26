type elpi = {
  .
  [@bs.meth]
  "compile":
    array(
      {
        .
        "name": string,
        "content": string,
      },
    ) =>
    unit,
  [@bs.meth] "queryAll": (string, (string, string) => unit) => unit,
  [@bs.meth] "restart": unit => unit,
};

[@bs.new] [@bs.module "elpi-js"]
/* Logging callback */
external create :
  (
    (string, string, string) => unit,
    /* Answers callback */
    array(
      {
        .
        "arg": string,
        "ass": string,
      },
    ) =>
    unit,
    /* Start callback */
    (bool, string) => unit
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