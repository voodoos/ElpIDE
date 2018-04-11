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

/* The sub-component for log rows */
module Row = {
  let component = ReasonReact.statelessComponent("Row");

  let make = (~lvl, ~text, _children) => {
    ...component, /* spread the template's other defaults into here  */
    render: _self => {
      SemanticUi.(
      <Table.Row> <Table.Cell> text </Table.Cell> </Table.Row>
    );
    } 
  };
};

/* The main log component */
let component = ReasonReact.reducerComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let make = (~glContainer, ~glEventHub : GoldenLayout.eventEmitter, _children) => {
  /* glEventHub and glContainer are props given by Golden Layout */
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
    let rec renderMessages = 
      (~acc=[], messages) =>
        switch (messages) {
        | [] => Array.of_list(acc) /* We need an Array of Children, not a list */
        | [message, ...rest] =>
          renderMessages(
            ~acc=[
              <Row key=(string_of_int(List.length(acc))) text=(message.text) lvl=(message.lvl) />,
              ...acc,
            ],
            rest,
          )
        };
    glEventHub##on("testEvent", (_j) => Js.log("totoEvent"));
    /* The log is a basic table */
    <div className="p-console fullpanel">
      SemanticUi.(
        <Table basic=`True compact=`Very>
          <Table.Body> (renderMessages(self.state.messages)) </Table.Body>
        </Table>
      )
    </div>;
  },
};

/* We need a way to give this component to goldenlayout : */
let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~glContainer=jsProps##glContainer, ~glEventHub=jsProps##glEventHub, [||])
  );