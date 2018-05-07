let component = ReasonReact.statelessComponent("InlineSuggest");

let make =
    (
      ~value: string,
      ~suggestions: list('a),
      ~read=(v => v: 'a => string),
      ~onKeyDown=?,
      ~onChange,
      ~props,
      _children,
    ) => {
  let suggest = () =>
    if (value == "") {
      "";
    } else {
      try (
        List.find(
          str =>
            try (value == String.sub(read(str), 0, String.length(value))) {
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
        <div className="inline-suggest">
          (
            ReasonReact.cloneElement(
              <Input value onChange ?onKeyDown />,
              ~props,
              [||],
            )
          )
          <div className="suggestion"> (ReasonReact.stringToElement(s)) </div>
        </div>
      );
    },
  };
};