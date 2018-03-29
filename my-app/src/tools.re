let to_js_bool = (b) => switch b {
| true => Js.true_
| false => Js.false_
};


let toJsOptionBool = (b) => Js.Option.map([@bs](a => Js.Boolean.to_js_boolean(a)), b);