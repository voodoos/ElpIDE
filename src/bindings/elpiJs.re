external exnOfError : Js.Promise.error => Js.Exn.t = "%identity";

type assignement = {
  .
  "arg": string,
  "ass": string,
};

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
<<<<<<< HEAD
    Js.Promise.t(string),
  [@bs.meth] "queryAll": string => Js.Promise.t(array(assignement)),
  [@bs.meth] "restart": unit => Js.Promise.t(string),
  "start": Js.Promise.t(string),
=======
    unit,
  [@bs.meth] "queryAll": (string, (string, string) => unit) => unit,
  [@bs.meth] "restart": unit => unit,
>>>>>>> Working on adding "loading" state to querier input
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
    unit
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