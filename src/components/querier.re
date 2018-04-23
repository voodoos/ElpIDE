let answer = argsassignements => {
  let l =
    List.map(
      argass => argass##arg ++ ": " ++ argass##ass,
      Array.to_list(argsassignements),
    );
  Log.message(Log.Info, [], String.concat("\n", l));
};

/* The main log component */
type state = {input_val: string};

type retainedProps = {messages: array(Log.message)};

type action =
  | SetVal(string);

let component = ReasonReact.reducerComponentWithRetainedProps("Querier");

let make = (~elpi, ~messages, _children) => {
  let change = (event, self) => {
    let newVal = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
    self.ReasonReact.send(SetVal(newVal));
  };
  let submit = (event, self) => {
    ReactEventRe.Synthetic.preventDefault(event);
    switch (elpi) {
    | None => ()
    | Some(e) =>
      e##queryAll(self.ReasonReact.state.input_val);
      self.ReasonReact.send(SetVal(""));
    };
  };
  {
    ...component,
    initialState: () => {input_val: "After build enter query here"},
    retainedProps: {
      messages: messages,
    },
    reducer: (action, _state) =>
      switch (action) {
      | SetVal(v) => ReasonReact.Update({input_val: v})
      },
    shouldUpdate: ({oldSelf, newSelf}) =>
      oldSelf.state.input_val !== newSelf.state.input_val
      || oldSelf.retainedProps.messages !== newSelf.retainedProps.messages,
    render: self =>
      /* The log is a basic table */
      <div id="querier">
        <AlwaysBottom className="p-console fullpanel">
          <Log.List level=Log.Info messages />
        </AlwaysBottom>
        <form onSubmit=(self.handle(submit))>
          <input
            _type="text"
            name="query"
            value=self.state.input_val
            onChange=(self.handle(change))
          />
        </form>
      </div>,
  };
};