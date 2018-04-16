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

let message = (lvl, text) => {lvl, text};

type state = {
  level: logLevel,
  messages: array(message),
};

module State = {
  type t = {
    level: logLevel,
    messages: array(message),
  };
  let initialState = {
    let level = Info;
    Js.log("Log level initially set to: Info");
    {
      level,
      messages: [|
        {lvl: Info, text: "Message initial test"},
        {lvl: Info, text: "Message 2 test"},
      |],
    };
  };
};

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
let component = ReasonReact.statelessComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let make = (~level, ~messages, _children) => {
  ...component,
  didMount: _self => ReasonReact.NoUpdate,
  willUnmount: _self => (),
  render: _self =>
    /* The log is a basic table */
    <div className="p-console fullpanel"> <List messages /> </div>,
};
/* We need a way to give this component to goldenlayout :
   let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));*/