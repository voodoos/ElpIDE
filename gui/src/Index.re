
/*

[@bs.module] external myJSReactClass : ReasonReact.reactClass =
  "react-ace";

let make = (~message: string, ~theme: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
  ~reactClass=myJSReactClass,
  ~props={"name": message,
          "theme": Js.Nullable.fromOption(theme)},
  children
);




*/




/* Initiallizing the Golden Layout */
let config =
  /* We locally open the Js.Json module for convenience */
  Js.Json.(object_(
  Js_dict.fromList(
    [("type", string("row")),
     ("content", array(
      [|  |]
    ))]
  )
)
);

let glayout = GoldenLayout.create_gl(config, "body");
GoldenLayout.init_gl(glayout);

ReactDOMRe.renderToElementWithId(
  <AceEditor
    mode="ocaml"
    theme="monokai"
    name="test"
    /*
    onChange={(n) => this.valChanged(n)}
    name={ this.props.file}
    width="100%"
    height="100%"
    setOptions={{
  enableBasicAutocompletion: true,
  enableLiveAutocompletion: true,
  enableSnippets: false,
  showLineNumbers: true,
  tabSize: 4,
}}*/
    />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");

