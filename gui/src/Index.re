
type gl_config =
  {.
   "type" : int,
   "content" : string
};
type golden;


[@bs.new] [@bs.module] external create_gl  :
  gl_config => string => golden =
  "golden-layout";

/*
[@bs.val] [@bs.module "golden-layout"] external create_gl :
  gl_config => string => golden =
  "";
*/

/*
[@bs.new] external create_golden : gl_config => string => golden =
  "GoldenLayout"; */

[@bs.module "path"] external dirname : string => string = "dirname";

/*let toto = create_golden({"type":3, "content":"toto"}, "");*/
let toto = create_gl({"type":3, "content":"toto"}, "");

let root = dirname("/user/chenglou");

ReactDOMRe.renderToElementWithId(<Component1 message="Hello!" />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");
