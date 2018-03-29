let to_js_bool = (b) => switch b {
| true => Js.true_
| false => Js.false_
};