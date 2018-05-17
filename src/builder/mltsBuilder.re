exception MltsError;

let translate = (logCB, code) => {
   let mlts = MltsJs.create(logCB);
    Js.Promise.make(
        (~resolve, ~reject) => 
            mlts##start
            |> Js.Promise.then_(mess => {
                mlts##transpile(code)
                |> Js.Promise.then_(res => {
                    mlts##kill();
                    /* If we got an answer we return the result
                     in the resolved promise */
                    resolve(. res);
                    Js.Promise.resolve(mess);
                    })
                |> Js.Promise.catch(_err => {
                    mlts##kill();
                    reject(. raise(MltsError));
                    Js.Promise.resolve("arg");
                })
                |> ignore;
                logCB("info", "mlts", mess);
                Js.Promise.resolve(mess);
            })

            |> Js.Promise.catch(_err => {
                mlts##kill();
                reject(. raise(MltsError));
                Js.Promise.resolve("arg");
            })
            |> ignore
    )
};