let answer = argsassignements => {
  let l =
    List.map(
      argass => argass##arg ++ ": " ++ argass##ass,
      Array.to_list(argsassignements),
    );
  Log.message(Log.Info, [], String.concat("\n", l));
};

/* The main log component */
type state = {
  input_val: string,
  history: array(string),
  pos/* in history */: int,
};

type retainedProps = {messages: array(Log.message)};

type action =
  | SetVal(string)
  | Back 
;

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
    initialState: () => {
      input_val: "",
      history: [||],
      pos: 0
    },
    retainedProps: {
      messages: messages,
    },
    reducer: (action, state) =>
      switch (action) {
      | SetVal(v) => ReasonReact.Update({...state, input_val: v})
    },
    shouldUpdate: ({oldSelf, newSelf}) =>
      oldSelf.state.input_val !== newSelf.state.input_val
      || oldSelf.retainedProps.messages !== newSelf.retainedProps.messages,
    render: self =>
      /* The log is a basic table */
      <div id="querier" className="p-querier">
        <AlwaysBottom className="fullpanel">
          <Log.List level=Log.Info messages />
        </AlwaysBottom>
        SemanticUi.(
          <Form onSubmit=(self.handle(submit))>
          <input
          _type="text"
          name="query"
          placeholder="Query..."
          value=self.state.input_val
          onChange=(self.handle(change))
        />
          </Form>
        )
      </div>,
  };
};