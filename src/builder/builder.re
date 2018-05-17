exception ElpiStartFailed;

exception NoElpi;

let elpiWorker: ref(option(ElpiJs.elpi)) = ref(None);

let getElpi = () =>
  switch (elpiWorker^) {
  | None => raise(NoElpi)
  | Some(e) => e
  };

let restartElpi = () => getElpi()##restart();

let launch = (logger, answer) =>
  switch (elpiWorker^) {
  | Some(_) => restartElpi()
  | None =>
    let elpi = ElpiJs.create(logger, answer);
    Js.Promise.make((~resolve, ~reject) =>
      elpi##start
      |> Js.Promise.then_(mess => {
           elpiWorker := Some(elpi);
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

let build = files => getElpi()##compile(files);

let queryAll = v => getElpi()##queryAll(v);