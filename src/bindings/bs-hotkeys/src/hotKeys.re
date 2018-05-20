open Hk_tools;

module K = Hk_keys;

exception NoKeys;

/** Some utilities to build usual keybindings */
let simple = l =>
  switch (l) {
  | [] => raise(NoKeys)
  | [h, ...tl] =>
    /* todo: check if the first one is a command ? */
    K.Seq([|
      List.fold_left((acc, k) => K.Plus(acc, Key(k)), Key(h), tl),
    |])
  };

[@bs.module "react-hotkeys"]
external react : ReasonReact.reactClass = "HotKeys";

[@bs.obj]
external makeProps :
  (
    ~keyMap: keymap=?,
    ~handlers: handlers=?, /* todo: Not satisfying */
    ~focused: Js.boolean=?,
    ~attach: 'a=?, /* todo: dangerous */
    ~onFocus: unit => unit=?,
    ~onBlur: unit => unit=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~keyMap=?,
      ~handlers=?,
      ~focused=?,
      ~attach=?,
      ~onFocus=?,
      ~onBlur=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~keyMap=?fromListKM(keyMap),
        ~handlers=?fromListHL(handlers),
        ~focused=?fromBool(focused),
        ~attach?,
        ~onFocus?,
        ~onBlur?,
        (),
      ),
    children,
  );