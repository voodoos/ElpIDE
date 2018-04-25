type localforage;

[@bs.val] [@bs.module "localForage"]
external getItem : string => Js.Promise.t('a) = "getItem";

[@bs.val] [@bs.module "localForage"]
external setItem : (string, 'a) => Js.Promise.t('b) = "setItem";
/*

 LocalForage.setItem("toto", "test")
 |> Js.Promise.then_(value => {
      Js.log(value);
      Js.Promise.resolve(value);
    })
 |> Js.Promise.catch(error => {
      Js.log(error);
      Js.Promise.resolve();
    });

 */