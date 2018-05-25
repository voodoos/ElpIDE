/**
 * For documentation go to :
 * https://localforage.github.io/localForage/
 */
type localforage;

[@bs.deriving jsConverter]
type driver = [
  | [@bs.as "localforage.INDEXEDDB"] `indexeddb
  | [@bs.as "localforage.WEBSQL"] `websql
  | [@bs.as "localforage.LOCALSTORAGE"] `localstorage
];

[@bs.val] [@bs.module "localforage"]
external getItem : string => Js.Promise.t('a) = "";

[@bs.val] [@bs.module "localforage"]
external setItem : (string, 'a) => Js.Promise.t('b) = "";

[@bs.val] [@bs.module "localforage"]
external removeItem : string => Js.Promise.t(unit) = "";

[@bs.val] [@bs.module "localforage"]
external clear : unit => Js.Promise.t(unit) = "";

[@bs.val] [@bs.module "localforage"]
external length : unit => Js.Promise.t(int) = "";

[@bs.val] [@bs.module "localforage"]
external key : int => Js.Promise.t(string) = "";

[@bs.val] [@bs.module "localforage"]
external keys : unit => Js.Promise.t(array(string)) = "";

[@bs.val] [@bs.module "localforage"]
external iterate :
  ((~value: 'a, ~key: string, ~iterationNumber: int) => unit) =>
  Js.Promise.t(unit) =
  "";

[@bs.val] [@bs.module "localforage"] external setDriver : driver => unit = "";

[@bs.val] [@bs.module "localforage"]
external setDrivers : array(driver) => unit = "setDriver";
/* TODO: config */
/* TODO: driverAPI */
/* TODO: multiple instances */
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