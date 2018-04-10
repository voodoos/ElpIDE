type logLevel =
  | Info
  | Warning
  | Error;

let stringOfLogLevel = lvl =>
  switch (lvl) {
  | Info => "Info"
  | Warning => "Warning"
  | Error => "Error"
  };

type message = {
  lvl: logLevel,
  text: string,
};

type state = {
  level: logLevel,
  messages: list(message),
};

type action =
  | Change(logLevel);

let component = ReasonReact.reducerComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let make = _children => {
  ...component,
  initialState: () => {
    Js.log("Log level initially set to: Info");
    {
      level: Info,
      messages: [
        {lvl: Info, text: "Message 2"},
        {lvl: Info, text: "Message initial"},
      ],
    };
  },
  reducer: (action, state) =>
    switch (action) {
    | Change(lvl) =>
      Js.log("Log level set to " ++ stringOfLogLevel(lvl) ++ ".");
      ReasonReact.Update({...state, level: lvl}); /* ...state means other state fields are unchanged */
    },
  render: self => {
    /* Auxilliary that renders the rows of the log table */
    let rec renderMessages = {
      /* Auxilliary function that renders one row of the log table */
      let renderOne = (key, text) =>
        SemanticUi.(
          <Table.Row key> <Table.Cell> text </Table.Cell> </Table.Row>
        );
      (~acc=[], messages) =>
        switch (messages) {
        | [] => Array.of_list(acc) /* We need an Array of Children, not a list */
        | [message, ...rest] =>
          renderMessages(
            ~acc=[
              renderOne(string_of_int(List.length(acc)), message.text),
              ...acc,
            ],
            rest,
          )
        };
    };
    /* The log is a table */
    <div className="p-console fullpanel">
      SemanticUi.(
        <Table>
          <Table.Body> (renderMessages(self.state.messages)) </Table.Body>
        </Table>
      )
    </div>;
  },
};

/* We need a way to give this component to goldenlayout : */
let default = ReasonReact.wrapReasonForJs(~component, jsProps => make([||]));