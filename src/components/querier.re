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
  history: list(string),
  pos: /* in history */ int,
};

type retainedProps = {messages: array(Log.message)};

type action =
  | SetVal(string)
  | AddHist(string)
  | Back
  | Forth;

let component = ReasonReact.reducerComponentWithRetainedProps("Querier");

let make = (~elpi, ~messages, _children) => {
  let change = (event, self) => {
    let newVal = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
    self.ReasonReact.send(SetVal(newVal));
  };
  let submit = (event, self) => {
    let v = self.ReasonReact.state.input_val;
    ReactEventRe.Synthetic.preventDefault(event);
    switch (elpi) {
    | None => ()
    | Some(e) =>
      e##queryAll(v);
      self.ReasonReact.send(SetVal(""));
      self.ReasonReact.send(AddHist(v));
    };
  };
  let keyDown = (event: ReactEventRe.Keyboard.t, self) =>
    switch (ReactEventRe.Keyboard.keyCode(event)) {
    | 38 =>
      /* 38 or ArrowUp: go back in history */
      self.ReasonReact.send(Back)
    | 40 =>
      /* 40 or ArrowDown: go forth in history */
      self.ReasonReact.send(Forth)
    | _ => ()
    };
  {
    ...component,
    initialState: () => {input_val: "", history: [], pos: 0},
    retainedProps: {
      messages: messages,
    },
    reducer: (action, state) =>
      switch (action) {
      | SetVal(v) => ReasonReact.Update({...state, input_val: v})
      | AddHist(v) =>
        ReasonReact.Update({
          ...state,
          history:
            if (List.length(state.history) > 0 && v == List.hd(state.history)) {
              state.history;
            } else {
              [v, ...state.history];
            },
          pos: (-1),
        })
      | Back =>
        Js.log(state.pos + 1);
        try (
          ReasonReact.Update({
            ...state,
            pos: state.pos + 1,
            input_val: List.nth(state.history, state.pos + 1),
          })
        ) {
        | _ => ReasonReact.NoUpdate
        };
      | Forth =>
        try (
          ReasonReact.Update({
            ...state,
            pos: state.pos - 1,
            input_val: List.nth(state.history, state.pos - 1),
          })
        ) {
        | _ => ReasonReact.Update({...state, pos: (-1), input_val: ""})
        }
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
              placeholder={|Query...|}
              value=self.state.input_val
              onChange=(self.handle(change))
              onKeyDown=(self.handle(keyDown))
            />
          </Form>
        )
      </div>,
  };
};