type logLevel =
  | Success
  | Info
  | Warning
  | Error;

let stringOfLogLevel = lvl =>
  switch (lvl) {
  | Success => "success"
  | Info => "info"
  | Warning => "warning"
  | Error => "error"
  };

let logLevelOfString = lvl =>
  switch (lvl) {
  | "success" => Success
  | "warning" => Warning
  | "error" => Error
  | _ => Info
  };

type message = {
  lvl: logLevel,
  prefix: list(string),
  text: string,
};

let message = (lvl, prefix, text) => {lvl, prefix, text};

let info = (~prefix=[], text) => message(Info, prefix, text);

let warn = (~prefix=[], text) => message(Warning, prefix, text);

let err = (~prefix=[], text) => message(Error, prefix, text);

let success = (~prefix=[], text) => message(Success, prefix, text);

module State = {
  type t = {
    level: logLevel,
    messages: array(message),
  };
  let initialState = {
    let level = Info;
    {level, messages: [||]};
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
        let prefix = List.map(p => "[" ++ p ++ "]", prefix);
        let txt =
          if (prefix != []) {
            String.concat("", prefix) ++ " " ++ text;
          } else {
            text;
          };
        SemanticUi.(
          <Table.Row
            warning=(lvl == Warning)
            error=(lvl == Error)
            positive=(lvl == Success)>
            <Table.Cell> <pre> (ReasonReact.string(txt)) </pre> </Table.Cell>
          </Table.Row>
        );
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
          <Table basic=`true_ compact=`very className="log-table">
            <Table.Body>
              (
                Array.mapi(
                  (k, m) =>
                    <Row
                      key=(string_of_int(k))
                      lvl=m.lvl
                      prefix=m.prefix
                      text=m.text
                    />,
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

type state = {
  level: logLevel,
  messages: array(message),
};

type action =
  | SetLevel(logLevel);

let component = ReasonReact.reducerComponent("Log");

let make = (~messages, _children) => {
  ...component,
  initialState: () => {level: Info, messages},
  reducer: (action, state) =>
    switch (action) {
    | SetLevel(level) => ReasonReact.Update({...state, level})
    },
  willReceiveProps: self => {...self.state, messages},
  shouldUpdate: ({oldSelf, newSelf}) => {
    let differentLvl = oldSelf.state.level !== newSelf.state.level;
    let differentMess = oldSelf.state.messages !== newSelf.state.messages;
    differentLvl || differentMess;
  },
  render: self =>
    /* The log is a basic table */
    <div className="p-console">
      SemanticUi.(
        <Menu size=`tiny inverted=false borderless=true className="p-log-menu">
          <Menu.Item header=true icon="unordered list" />
          <Menu.Menu position=`right>
            <Button icon=true className="no-border" basic=true>
              <Icon name="trash" />
            </Button>
            <Dropdown
              className="no-border"
              button=true
              placeholder="level"
              selection=true
              value=(stringOfLogLevel(self.state.level))
              onChange=(
                (_e, d) => self.send(SetLevel(logLevelOfString(d##value)))
              )
              options=[|
                {"text": "Info", "value": "info"},
                {"text": "Warning", "value": "warning"},
                {"text": "Error", "value": "error"},
              |]
            />
          </Menu.Menu>
        </Menu>
      )
      <AlwaysBottom className="p-log-messages fullpanel">
        <List level=self.state.level messages />
      </AlwaysBottom>
    </div>,
};
/* We need a way to give this component to goldenlayout :
   let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));*/