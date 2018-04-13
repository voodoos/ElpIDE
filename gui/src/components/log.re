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
  messages: array(message),
};

type action =
  | Change(logLevel)
  | NewMessage(logLevel, string);

/**
 * <Log>
 *  <Log.List>
 *    <Log.List.Row />
 *    <Log.List.Row />
 *    ...
 *  </Log.List>
 * </Log>
 */
/* The sub-component for log List */
module List = {
  /* The sub-component for log rows */
  module Row = {
    let component = ReasonReact.statelessComponent("Row");
    let make = (~lvl, ~text, _children) => {
      ...component, /* spread the template's other defaults into here  */
      render: _self =>
        SemanticUi.(
          <Table.Row warning=(lvl == Warning) error=(lvl == Error)>
            <Table.Cell> text </Table.Cell>
          </Table.Row>
        ),
    };
  };
  /* The List component */
  let component = ReasonReact.statelessComponent("List");
  let make = (~messages, _children) => {
    ...component, /* spread the template's other defaults into here  */
    render: _self =>
      SemanticUi.(
        <Table basic=`True compact=`Very>
          <Table.Body>
            (
              Array.mapi(
                (k, m) =>
                  <Row key=(string_of_int(k)) lvl=m.lvl text=m.text />,
                messages,
              )
            )
          </Table.Body>
        </Table>
      ),
  };
};

/* The main log component */
let component = ReasonReact.reducerComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let make = (~glContainer, ~glEventHub, _children) => {
  /* glEventHub and glContainer are props given by Golden Layout */
  ...component,
  initialState: () => {
    /* GoldenLayout has it's own persistence mecanism (relaying on localstorage) */
    let gls = glContainer##_config##componentState;
    if (Array.length(Js.Obj.keys(gls)) > 0) {
      glContainer##_config##componentState##reasonState;
    } else {
      let level = Info;
      Js.log("Log level initially set to: Info");
      {
        level,
        messages: [|
          {lvl: Info, text: "Message initial"},
          {lvl: Info, text: "Message 2"},
        |],
      };
    };
  },
  reducer: (action, state) =>
    switch (action) {
    | Change(lvl) =>
      Js.log("Log level set to " ++ stringOfLogLevel(lvl) ++ ".");
      ReasonReact.Update({...state, level: lvl}); /* ...state means other state fields are unchanged */
    | NewMessage(lvl, text) =>
      ReasonReact.Update({
        ...state,
        messages: Array.append(state.messages, [|{lvl, text}|]),
      })
    },
  didMount: self => {
    /** The GoldenLayout EventHub is used to send and receive message from and to
      * the various components off the App. This is not in sync with ReactJs
      * philosophy but allows for communication to work accross windows
      */
    glEventHub##on("logMessage", j => {
      Js.log(j);
      self.send(NewMessage(Info, j##text));
    });
    ReasonReact.NoUpdate;
  },
  willUnmount: _self => glEventHub##unbind("logMessage"),
  render: self =>
    /* The log is a basic table */
    <div className="p-console fullpanel">
      <List messages=self.state.messages />
    </div>,
};

/* We need a way to give this component to goldenlayout : */
let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~glContainer=jsProps##glContainer,
      ~glEventHub=jsProps##glEventHub,
      [||],
    )
  );