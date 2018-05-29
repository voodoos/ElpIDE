exception Error(string);

let handleFailure =
  [@bs.open]
  (
    fun
    | Error(s) => s
  );

let translate = (logCB, files: array(File.t)) => {
  let mlts = MltsJs.create(logCB);
  Js.Promise.make((~resolve, ~reject) =>
    switch (files) {
    | [||] => resolve(. [||])
    | _ =>
      mlts##start
      |> Js.Promise.then_(mess => {
           logCB("info", "Mlts", mess);
           Js.Promise.all(
             Array.map((f: File.t) => mlts##transpile(f.content), files),
           )
           |> Js.Promise.then_(vals => {
                mlts##kill();
                let code =
                  Array.fold_left(
                    (acc, p) => acc ++ p##types ++ p##typesEval ++ p##prog,
                    "",
                    vals,
                  );
                resolve(. [|
                  File.toJs({File.name: "prog.mlts", content: code}),
                |]);
                Js.Promise.resolve(vals);
              })
           |> Js.Promise.catch(err => {
                let exn = MltsJs.exnOfError(err);
                let mess =
                  switch (Js.Exn.message(exn)) {
                  | Some(s) => s
                  | _ => "Unknown (mlts) translation error"
                  };
                mlts##kill();
                Js.log2("tranlsatefail", mess);
                reject(. Error(mess));
                Js.Promise.reject(Error(mess));
              })
           |> ignore;
           Js.Promise.resolve(mess);
         })
      |> Js.Promise.catch(_err => {
           mlts##kill();
           Js.log("badstart");
           reject(. Error("Mlts translation failed"));
           Js.Promise.reject(Error("Mlts translation failed"));
         })
      |> ignore
    }
  );
};