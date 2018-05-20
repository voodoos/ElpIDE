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
  | Str(string)
  | Special(kspecial)
  | Mod(kmod);

type keySeq =
  | Key(key)
  | Plus(keySeq, keySeq)
  | Space(keySeq, keySeq);

[@bs.deriving jsConverter]
type action = [ | `keypress | `keydown | `keyup];

type keys =
  | Seq(array(keySeq))
  | SeqAction(array(keySeq), action);