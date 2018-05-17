exception ElpiStartFailed;

exception ElpiFailed;

exception MltsFailed;

exception NoElpi;

exception NoMlts;

let elpiWorker: ref(option(ElpiJs.elpi)) = ref(None);

let mltsTrans = ref(None);

let getElpi = () =>
  switch (elpiWorker^) {
  | None => raise(NoElpi)
  | Some(e) => e
  };

let getMlts = () =>
  switch (mltsTrans^) {
  | None => raise(NoMlts)
  | Some(t) => t
  };

let restartElpi = () => getElpi()##restart();

let launch = (logger, answer) =>
  switch (elpiWorker^) {
  | Some(_) => restartElpi()
  | None =>
    let elpi = ElpiJs.create(logger("Elpi"), answer);
    Js.Promise.make((~resolve, ~reject) =>
      elpi##start
      |> Js.Promise.then_(mess => {
           elpiWorker := Some(elpi);
           mltsTrans := Some(MltsBuilder.translate(logger("Mlts")));
           resolve(. mess);
           Js.Promise.resolve(mess);
         })
      |> Js.Promise.catch(_err => {
           reject(. raise(ElpiStartFailed));
           Js.Promise.resolve("Elpi failed to start");
         })
      |> ignore
    );
  };

let queryAll = v => getElpi()##queryAll(v);

let build = files =>
  Js.Promise.make((~resolve, ~reject) =>
    (getMlts())(
      Array.of_list(
        List.filter(f => Tools.isMltsFile(f##name), Array.to_list(files)),
      ),
    )
    |> Js.Promise.then_(res => {
         getElpi()##compile(
           Array.append(
             Array.of_list(
               List.filter(
                 f => Tools.isElpiFile(f##name),
                 Array.to_list(files),
               ),
             ),
             res,
           ),
         )
         |> Js.Promise.then_(r => {
              switch (res) {
              | [||] => resolve(. r)
              | _ =>
                queryAll("run N _P V T.")
                |> Js.Promise.then_(res => {
                     resolve(. r);
                     Js.Promise.resolve(res);
                   })
                |> Js.Promise.catch(_err => {
                     resolve(. r);
                     Js.Promise.reject(raise(ElpiFailed));
                   })
                |> ignore
              };
              Js.Promise.resolve(r);
            })
         |> Js.Promise.catch(_r => {
              reject(. raise(ElpiFailed));
              Js.Promise.reject(raise(ElpiFailed));
            })
         |> ignore;
         Js.Promise.resolve(res);
       })
    |> Js.Promise.catch(_r => {
         reject(. raise(MltsFailed));
         Js.Promise.reject(raise(MltsFailed));
       })
    |> ignore
  );