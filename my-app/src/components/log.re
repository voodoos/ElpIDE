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

type state = {level: logLevel};

type action =
  | Change(logLevel);

let component = ReasonReact.reducerComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let make = _children => {
  ...component,
  initialState: () => {
    Js.log("Log level initially set to: Info");
    {level: Info};
  },
  reducer: (action, _state) =>
    switch (action) {
    | Change(lvl) =>
      Js.log("Log level set to " ++ stringOfLogLevel(lvl) ++ ".");
      ReasonReact.Update({level: lvl});
    },
  render: self => {
    let txt = "Pouet la console " ++ stringOfLogLevel(self.state.level);
    <div className="p-console fullpanel">
      SemanticUi.(
        <Table>
          <Table.Body>
            <Table.Row>
              <Table.Cell> (ReasonReact.stringToElement(txt)) </Table.Cell>
            </Table.Row>
          </Table.Body>
        </Table>
      )
    </div>;
  },
};

/* We need a way to give this component to goldenlayout : */
let default = ReasonReact.wrapReasonForJs(~component, jsProps => make([||]));