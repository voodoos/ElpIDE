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

let logLevelOfString = lvl =>
  switch (lvl) {
  | "warning" => Warning
  | "error" => Error
  | _ => Info
  };

type message = {
  lvl: logLevel,
  prefix: string,
  text: string,
};

let message = (lvl, prefix, text) => {lvl, prefix, text};

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
        {lvl: Info, prefix: "", text: "Message initial test"},
        {lvl: Info, prefix: "", text: "Message 2 test"},
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
    let make = (~lvl, ~prefix, ~text, _children) => {
      ...component, /* spread the template's other defaults into here  */
      render: _self => {
        let txt = switch prefix {
        | "" => text
        | pre => "[" ++ pre ++ "] " ++ text
        };
        SemanticUi.(
          <Table.Row warning=(lvl == Warning) error=(lvl == Error)>
            <Table.Cell> txt </Table.Cell>
          </Table.Row>
        )
      },
    };
  };
  /* The List component */
  /* wondering about Js.Nullable.to_opt? See the note below */
  let component = ReasonReact.statelessComponent("List");
  let make = (~level, ~messages, _children) => {
    ...component, /* spread the template's other defaults into here  */
    render: _self =>
      <div>
        SemanticUi.(
          <Table basic=`True compact=`Very>
            <Table.Body>
              (
                Array.mapi(
                  (k, m) =>
                    <Row key=(string_of_int(k)) lvl=m.lvl prefix=m.prefix text=m.text />,
                  messages,
                )
              )
            </Table.Body>
          </Table>
        )
      </div>,
  };
};

/* The main log component */
let component = ReasonReact.statelessComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let make = (~level, ~messages, _children) => {
  ...component,
  render: _self =>
    /* The log is a basic table */
    <AlwaysBottom className="p-console fullpanel">
      <List level messages />
    </AlwaysBottom>,
};
/* We need a way to give this component to goldenlayout :
   let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));*/