type golden;


[@bs.new] [@bs.module] external create_gl  :
  Js.Json.t => string => golden =
  "golden-layout";

[@bs.send] external init_gl : golden => unit = "init";
