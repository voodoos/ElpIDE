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
  world "world".|},
};

let make = (name, content) => {name, content};

let newFile = name => {name, content: "% File " ++ name ++ "\n"};