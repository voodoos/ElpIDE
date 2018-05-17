exception MltsError;

let translate = (logCB, files) => {
  let mlts = MltsJs.create(logCB);
  Js.Promise.make((~resolve, ~reject) =>
    mlts##start
    |> Js.Promise.then_(mess => {
         Js.Promise.all(Array.map(f => mlts##transpile(f##content), files))
         |> Js.Promise.then_(vals => {
              Js.log(vals);
              Js.Promise.resolve(vals);
            })
         |> ignore;
         resolve(. [||]);
         logCB("info", "Mlts", mess);
         Js.Promise.resolve(mess);
       })
    |> Js.Promise.catch(_err => {
         mlts##kill();
         reject(. raise(MltsError));
         Js.Promise.resolve("Mlts translation failed");
       })
    |> ignore
  );
};