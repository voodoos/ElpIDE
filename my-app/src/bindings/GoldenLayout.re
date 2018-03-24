type golden;

[%%raw {|require('golden-layout/dist/goldenlayout.min.js')|}];
[%%raw {|require('golden-layout/dist/goldenlayout-base.js')|}];
[%%raw {|require('golden-layout/dist/goldenlayout-dark-theme.js')|}];

[@bs.new] [@bs.module] external create_gl  :
  Js.Json.t => string => golden =
  "golden-layout";

[@bs.send] external init : golden => unit = "init";

[@bs.send] external registerComponent :
  golden => string => ReasonReact.reactClass => unit =
  "registerComponent";

