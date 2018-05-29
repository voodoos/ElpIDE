open Hk_keys;

/* Tools for keys */
let keyToString = k =>
  switch (k) {
  | K(s) => s
  | S(kspecial) => kspecialToJs(kspecial)
  | M(kmod) => kmodToJs(kmod)
  };

let rec keySeqToString = ks =>
  switch (ks) {
  | Key(key) => keyToString(key)
  | Plus(ks1, ks2) =>
    String.concat("+", [keySeqToString(ks1), keySeqToString(ks2)])
  | Space(ks1, ks2) =>
    String.concat(" ", [keySeqToString(ks1), keySeqToString(ks2)])
  };

let keySeqToStrings = ks => Array.map(keySeqToString, ks);

type js;

external unsafeJs : 'a => js = "%identity";

let keysToJs = k =>
  switch (k) {
  | Seq(arr) => unsafeJs(keySeqToStrings(arr))
  | SeqAction(seq, act) =>
    unsafeJs({"sequence": keySeqToStrings(seq), "action": actionToJs(act)})
  };

let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);

/** Tool to make lists or pairs into object
 * In these bindings a keymap is a list of pairs :
 * list((string, keySequence))
 *
 * But the react-hotkeys expects a
 * { [key: string]: KeySequence } object
*/
type keymap;

[@bs.new] external create_km : keymap = "Object";

[@bs.set_index] external set_km : (keymap, string, js) => unit = "";

let listToKeyMap = lkm => {
  let km = create_km;
  List.iter(((name, kseq)) => set_km(km, name, keysToJs(kseq)), lkm);
  km;
};

/** Same for handlers */
type handlers;

[@bs.new] external create_hl : handlers = "Object";

[@bs.set_index]
external set_hl : (handlers, string, ReactEventRe.Keyboard.t => unit) => unit =
  "";

let listToHandlers = lhl => {
  let hl = create_hl;
  List.iter(((name, f)) => set_hl(hl, name, f), lhl);
  hl;
};

let fromListKM = makeJsOptionMap(listToKeyMap);

let fromListHL = makeJsOptionMap(listToHandlers);
/*
 Js.log2(
   listToKeyMap([
     ("test", Seq([|Plus(Key(Special(`tab)), Key(Str("E")))|])),
   ]),
   listToKeyMap([
     (
       "test",
       SeqAction([|Plus(Key(Special(`tab)), Key(Str("E")))|], `keydown),
     ),
   ]),
 );
 */