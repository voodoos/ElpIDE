type golden;

/*
  [@@bs unwrap] may be a way to make a nice type (polymorphic) for config !
  "Polymorphic variants with [@bs.unwrap] will "unwrap" the variant at the call site so that the JavaScript function is called with the underlying value."
*/

/*

 [%%raw {|require('golden-layout/dist/goldenlayout.min.js')|}];
 [%%raw {|require('golden-layout/dist/goldenlayout-base.js')|}];
 [%%raw {|require('golden-layout/dist/goldenlayout-dark-theme.js')|}];
  */
[@bs.new] [@bs.module]
external create_gl : (Js.Json.t, string) => golden = "golden-layout";

[@bs.send] external init : golden => unit = "init";

[@bs.send]
external registerComponent : (golden, string, ReasonReact.reactClass) => unit =
  "registerComponent";

/* Some utility functions to create config for gl */
let make_config = content =>
  Js.Json.(object_(Js_dict.fromList([("content", array(content))])));

let make_row = content =>
  Js.Json.(
    object_(
      Js_dict.fromList([
        ("type", string("row")),
        ("isClosable", boolean(Js.false_)),
        ("content", array(content))
      ]),
    )
  );

let make_column = content =>
  Js.Json.(
    object_(
      Js_dict.fromList([
        ("type", string("column")),
        ("isClosable", boolean(Js.false_)),
        ("content", array(content))
      ]),
    )
  );

let make_react_component = (name, state, props) =>
  Js.Json.(
    object_(
      Js_dict.fromList([
        ("type", string("react-component")),
        ("component", string(name)),
        ("componentState", object_(Js_dict.fromList(state))),
        ("props", object_(Js_dict.fromList(props)))
      ]),
    )
  );