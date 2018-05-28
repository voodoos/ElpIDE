type mlts = {
  .
  [@bs.meth]
  "transpile":
    string =>
    Js.Promise.t(
      {
        .
        "prog": string,
        "types": string,
        "typesEval": string,
      },
    ),
  [@bs.meth] "restart": unit => Js.Promise.t(string),
  "start": Js.Promise.t(string),
  [@bs.meth] "kill": unit => unit,
};

external exnOfError : Js.Promise.error => Js.Exn.t = "%identity";

[@bs.new] [@bs.module "mlts-js"]
/* Logging callback */
external create : ((string, string, string) => unit) => mlts = "default";
/*

 let transpile = (logCB, code) => {
 let mlts = create(logCB);
 mlts##start
 |> Js.Promise.then_(mess => {
      mlts##transpile(code)
      |> Js.Promise.then_(mess => {
       logCB("info", "mlts", mess);
       Js.Promise.resolve(mess);
           })
       |> ignore;
      logCB("info", "mlts", mess);
      Js.Promise.resolve(mess);
    })
 |> ignore;
   }*/