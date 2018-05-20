[@bs.deriving jsConverter]
type kmod = [ | `shift | `ctrl | `alt | `option | `command | `meta];

[@bs.deriving jsConverter]
type kspecial = [
  | `backspace
  | `tab
  | `enter
  | `return
  | `capslock
  | `esc
  | `escape
  | `space
  | `pageup
  | `pagedown
  | `end_
  | `home
  | `left
  | `up
  | `right
  | `down
  | `ins
  | `del
  | `plus
];

type key =
  | K(string)
  | S(kspecial)
  | M(kmod);

type keySeq =
  | Key(key)
  | Plus(keySeq, keySeq)
  | Space(keySeq, keySeq);

[@bs.deriving jsConverter]
type action = [ | `keypress | `keydown | `keyup];

type keys =
  | Seq(array(keySeq))
  | SeqAction(array(keySeq), action);

exception NoKeys;

/** Some utilities to build usual keybindings */
let simple = l =>
  switch (l) {
  | [] => raise(NoKeys)
  | [h, ...tl] =>
    /* todo: check if the first one is a command ? */
    Seq([|List.fold_left((acc, k) => Plus(acc, Key(k)), Key(h), tl)|])
  };

let simpleSuite = l =>
  switch (l) {
  | [] => raise(NoKeys)
  | [h, ...tl] =>
    /* todo: check if the first one is a command ? */
    Seq([|List.fold_left((acc, k) => Space(acc, Key(k)), Key(h), tl)|])
  };

let konami =
  simpleSuite([
    S(`up),
    S(`up),
    S(`down),
    S(`down),
    S(`left),
    S(`right),
    S(`left),
    S(`right),
    K("b"),
    K("a"),
  ]);