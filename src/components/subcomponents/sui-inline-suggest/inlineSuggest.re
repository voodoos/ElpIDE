let component = ReasonReact.statelessComponent("InlineSuggest");

let make = (~value, ~suggestions, ~onKeyDown=?, ~onChange, ~props, _children) => {
  let suggest = () =>
    if (value == "") {
      "";
    } else {
      try (
        List.find(
          str =>
            try (value == String.sub(str, 0, String.length(value))) {
            | Invalid_argument(_e) => false
            },
          suggestions,
        )
      ) {
      | Not_found => ""
      };
    };
  {
    /*let onChange = e => onChange(e);*/
    ...component,
    render: _self => {
      let s = suggest();
      SemanticUi.(
        <div id="inline-suggets">
          (
            ReasonReact.cloneElement(
              <Input value onChange ?onKeyDown />,
              ~props,
              [||],
            )
          )
          <div className="suggestions">
            (ReasonReact.stringToElement(s))
          </div>
        </div>
      );
    },
  };
};