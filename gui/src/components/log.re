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
  /* wondering about Js.Nullable.to_opt? See the note below */
  let component = ReasonReact.statelessComponent("List");
  let make = (~messages, _children) => {
    ...component, /* spread the template's other defaults into here  */
    render: self =>
      <div>
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
        )
      </div>,
  };
};

/* The main log component */
type state = {bottomRef: ref(option(Dom.element))};

type action = int;

let component = ReasonReact.reducerComponent("Log");

let handleClick = (_event, _self) => Js.log("clickedlog");

let setBottomRef = (theRef, {ReasonReact.state}) =>
  /* We need a ref to the div marking the bottom of the console to keep it scrolled */
  state.bottomRef := Js.Nullable.toOption(theRef);

let make = (~level, ~messages, _children) => {
  ...component,
  initialState: () => {bottomRef: ref(None)},
  reducer: (_action: action, _state) => ReasonReact.NoUpdate,
  didUpdate: ({oldSelf, newSelf}) =>
    /* Scrolling to bottom on update
     * Thanks to the Bottom div */
    switch (newSelf.state.bottomRef^) {
    | Some(r) =>
      ReactDOMRe.domElementToObj(r)##scrollIntoView({"behavior": "smooth"})
    | _ => ()
    },
  willUnmount: _self => (),
  render: self =>
    /* The log is a basic table */
    <div className="p-console fullpanel">
      <List messages />
      <div ref=(self.handle(setBottomRef)) />
    </div>,
};
/* We need a way to give this component to goldenlayout :
   let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));*/