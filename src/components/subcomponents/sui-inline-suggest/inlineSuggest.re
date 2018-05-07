let component = ReasonReact.statelessComponent("InlineSuggest");

let make =
    (
      ~value: string,
      ~suggestions,
      ~read,
      ~onComplete,
      ~shouldSuggest=v => ! (v == ""),
      ~onKeyDown=?,
      ~onChange,
      ~props,
      _children,
    ) => {
  let suggest = () =>
    if (shouldSuggest(value)) {
      try (
        read(
          List.find(
            str =>
              try (value == String.sub(read(str), 0, String.length(value))) {
              | Invalid_argument(_e) => false
              },
            suggestions,
          ),
        )
      ) {
      | Not_found => ""
      };
    } else {
      "";
    };
  let keyDown = (s, e: ReactEventRe.Keyboard.t) => {
    switch (ReactEventRe.Keyboard.keyCode(e)) {
    | 9 =>
      ReactEventRe.Synthetic.preventDefault(e);
      if (s != "") {
        onComplete(s ++ " ");
      };
    | _ => ()
    };
    /* If necessary, we forward the event */
    switch (onKeyDown) {
    | None => ()
    | Some(cb) => cb(e)
    };
    ();
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
              <Input value onChange onKeyDown=(keyDown(s)) />,
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