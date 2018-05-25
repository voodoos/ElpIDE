exception MltsError;

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
                Js.log(code);
                resolve(. [|
                  File.toJs({File.name: "prog.mlts", content: code}),
                |]);
                Js.Promise.resolve(vals);
              })
           |> Js.Promise.catch(_err => {
                mlts##kill();
                reject(. raise(MltsError));
                Js.Promise.resolve(raise(MltsError));
              })
           |> ignore;
           Js.Promise.resolve(mess);
         })
      |> Js.Promise.catch(_err => {
           mlts##kill();
           reject(. raise(MltsError));
           Js.Promise.resolve("Mlts translation failed");
         })
      |> ignore
    }
  );
};