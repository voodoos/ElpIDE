

let answer = (argsassignements) => {
    let l = List.map ((argass) => argass##arg ++ ": " ++ argass##ass, Array.to_list(argsassignements));
    Js.log(String.concat("\n", l));
    Log.message(Log.Info, [], String.concat("\n", l));
};


/* The main log component */
type state = {
    input_val: string
};

type action = SetVal(string);

let component = ReasonReact.reducerComponent("Querier");

let make = (~elpi, ~messages, _children) => {
  let change = (event, self) => {
      let newVal = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
      self.ReasonReact.send(SetVal(newVal));
  };
  let submit = (event, self) => {
    ReactEventRe.Synthetic.preventDefault(event);
    switch elpi {
    | None => ()
    | Some(e) => {
        e##queryAll(self.ReasonReact.state.input_val);
        self.ReasonReact.send(SetVal(""));
    }
    }
  };
  {
    ...component,
    initialState: () => {
        input_val: "ini"
    },
    reducer: (action, _state) =>
        switch action {
        | SetVal(v) => ReasonReact.Update({ input_val: v });
    },
    render: self =>
        /* The log is a basic table */
        <div id="querier">
            <AlwaysBottom className="p-console fullpanel">
            <Log.List level=Log.Info messages />
            </AlwaysBottom>
            <form onSubmit={self.handle(submit)}>
                <input _type="text" name="query" value={self.state.input_val}
                    onChange={self.handle(change)}  />
            </form>
        </div>,
  }
};