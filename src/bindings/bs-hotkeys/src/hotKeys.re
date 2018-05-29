open Hk_tools;

module K = Hk_keys;

[@bs.module "react-hotkeys"]
external react : ReasonReact.reactClass = "HotKeys";

[@bs.obj]
external makeProps :
  (
    ~keyMap: keymap=?,
    ~handlers: handlers=?, /* todo: Not satisfying */
    ~focused: bool=?,
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
        ~focused?,
        ~attach?,
        ~onFocus?,
        ~onBlur?,
        (),
      ),
    children,
  );