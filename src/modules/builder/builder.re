exception ElpiStartFailed;

exception ElpiFailed;

exception MltsFailed;

exception NoElpi;

exception NoMlts;

exception BuildError(string);

let handleFailure =
  [@bs.open]
  (
    fun
    | BuildError(s) => s
  );

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
        List.filter(
          (f: File.t) => Tools.isMltsFile(f.name),
          Array.to_list(files),
        ),
      ),
    )
    |> Js.Promise.then_(res => {
         let files =
           Array.append(
             Array.of_list(
               List.map(
                 File.toJs,
                 List.filter(
                   (f: File.t) => Tools.isElpiFile(f.name),
                   Array.to_list(files),
                 ),
               ),
             ),
             res,
           );
         getElpi()##compile(
           files,
           /** If mlts is in use, we don't perform static check
            * on build because an other one will happen right
            * after when the query starts
            **/
           Js.Boolean.to_js_boolean(Array.length(res) <= 0),
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
                     Js.Promise.reject(ElpiFailed);
                   })
                |> ignore
              };
              Js.Promise.resolve(r);
            })
         |> Js.Promise.catch(_r => {
              reject(. ElpiFailed);
              Js.Promise.reject(ElpiFailed);
            })
         |> ignore;
         Js.Promise.resolve(res);
       })
    |> Js.Promise.catch(err => {
         let mess =
           switch (MltsBuilder.handleFailure(err)) {
           | Some(s) => s
           | _ => "Unknown (mlts) translation error"
           };
         reject(. BuildError(mess));
         Js.Promise.reject(BuildError(mess));
       })
    |> ignore
  );