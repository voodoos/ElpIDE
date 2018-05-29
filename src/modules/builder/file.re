[@bs.deriving jsConverter]
type t = {
  name: string,
  content: string,
};

let toJs = tToJs;

let initialState = {
  name: "example.elpi",
  content: {|kind nat type.
  type z nat.
  type s nat -> nat.

  type plus nat -> nat -> nat -> prop.

  plus z M M.
  plus (s N) M (s P) :- plus N M P.

  % Hello world
  world "hello".
  world "world2".|},
};

let make = (name, content) => {name, content};

let newFile = name => {name, content: "% File " ++ name ++ "\n"};

/* Some changes to the way files are stored could require
 * a wipe of local storage or a specific update, the following
 * function is wiping localStorage when the schemaVersion
 * mismatchs. A method applying an appropriate update
 * without destroying data would be of course preferable... */
let schemaVersion = 1;

let check_version = () =>
  Js.Promise.make((~resolve as res, ~reject as rej) =>
    Js.Promise.(
      LocalForage.getItem("schemaVersion")
      |> then_(sv => {
           let pass =
             switch (Js.Null.toOption(sv)) {
             | None =>
               Js.log("No version");
               false;
             | Some(v) =>
               Js.log2("SchemaVersion:", v);
               v == schemaVersion;
             };
           if (! pass) {
             /* If versions mismatch we delete all local storage
                and add version number with default files */
             Js.log("Resetting local forage");
             LocalForage.clear()
             |> then_(() => {
                  LocalForage.setItem("schemaVersion", schemaVersion)
                  |> then_(a => {
                       LocalForage.setItem("files", [|initialState|])
                       |> then_(a => {
                            res(. true);
                            resolve(a);
                          })
                       |> ignore;
                       resolve(a);
                     })
                  |> ignore;
                  resolve();
                })
             |> ignore;
             resolve(sv);
           } else {
             res(. false);
             resolve(sv);
           };
         })
      |> ignore
    )
  );