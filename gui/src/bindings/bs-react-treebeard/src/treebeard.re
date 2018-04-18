[@bs.module "react-treebeard"]
external treebeard : ReasonReact.reactClass = "Treebeard";

type data = {.
  "id": Js.undefined(string),
  "name": string,
  "toggled": Js.undefined(Js.boolean),
  "active": Js.undefined(Js.boolean),
  "loading": Js.undefined(Js.boolean),
  "children": Js.undefined(array(data)),
};

let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);
let fromBool = makeJsOptionMap(Js.Boolean.to_js_boolean);

[@bs.obj] external makeNodeExt : (~id: string=?, ~name: string, 
~toggled: Js.boolean=?, ~active: Js.boolean=?, ~loading: Js.boolean=?, 
~children: array(data)=?, unit) => data = "";

/* For convenience, use this function to build data props */
let makeNode = (~id=?, ~toggled=?, ~active=?, ~loading=?, ~children=?, name) => {
    makeNodeExt(~id?, 
    ~name=name, 
    ~toggled=?fromBool(toggled), 
    ~active=?fromBool(active), 
    ~loading=?fromBool(loading), 
    ~children?, 
    ())
};

let setActive = (node: data, active: bool) =>
    makeNodeExt(
        ~id=?Js.Undefined.toOption(node##id),
        ~name=node##name,
        ~toggled=?Js.Undefined.toOption(node##toggled),
        ~loading=?Js.Undefined.toOption(node##loading),
        ~children=?Js.Undefined.toOption(node##children),
        ~active=Js.Boolean.to_js_boolean(active),
        ()
    )
;

let setToggled = (node: data, toggled: bool) =>
    makeNodeExt(
        ~id=?Js.Undefined.toOption(node##id),
        ~name=node##name,
        ~active=?Js.Undefined.toOption(node##active),
        ~loading=?Js.Undefined.toOption(node##loading),
        ~children=?Js.Undefined.toOption(node##children),
        ~toggled=Js.Boolean.to_js_boolean(toggled),
        ()
    )
;

/*let makeNode = (~name: string, ~toggled: bool=?, ~children: array(bool)) =>
{
    "name": name,
    "toggled": Js.Nullable.t(bool),
    "children": array(data),
  };
*/
let make = (~data: data, ~onToggle: option((data, bool) => unit)=?, children) =>
    ReasonReact.wrapJsForReason(
    ~reactClass=treebeard,
    ~props={"data": data,
            "onToggle": Js.Nullable.fromOption(onToggle)},
    children,
  );