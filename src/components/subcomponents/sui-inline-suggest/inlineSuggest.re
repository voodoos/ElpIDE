let component = ReasonReact.statelessComponent("InlineSuggest");

let make =
    (
      ~value: string,
      ~suggestions,
      ~read,
      ~info=?,
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
        {
          let v =
            List.find(
              str =>
                try (
                  value == String.sub(read(str), 0, String.length(value))
                ) {
                | Invalid_argument(_e) => false
                },
              suggestions,
            );
          let suggestion = read(v);
          switch (info) {
          | None => (suggestion, "")
          | Some(f) => (suggestion, f(v))
          };
        }
      ) {
      | Not_found => ("", "")
      };
    } else {
      ("", "");
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
      let (suggestion, info) = suggest();
      SemanticUi.(
        <div className="inline-suggest">
          (
            ReasonReact.cloneElement(
              <Input value onChange onKeyDown=(keyDown(suggestion)) />,
              ~props,
              [||],
            )
          )
          <div className="is-suggestion">
            (ReasonReact.stringToElement(suggestion))
            <span className="is-info">
              (ReasonReact.stringToElement(info))
            </span>
          </div>
        </div>
      );
    },
  };
};