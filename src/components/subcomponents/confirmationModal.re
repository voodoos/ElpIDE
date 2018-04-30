type state = {opened: bool};

type action =
  | Opened(bool);

let component = ReasonReact.reducerComponent("DeleteFileModal");

let make = (~trigger, ~message, ~onOk, ~onNope=() => (), _children) => {
  let openM = (_e, self) => self.ReasonReact.send(Opened(true));
  let closeM = (_e, self) => self.ReasonReact.send(Opened(false));
  let submit = (e, self) => {
    onOk();
    closeM(e, self);
  };
  {
    ...component, /* spread the template's other defaults into here  */
    initialState: () => {opened: false},
    reducer: (action, state) =>
      switch (action) {
      | Opened(opened) => ReasonReact.Update({...state, opened})
      },
    render: self =>
      SemanticUi.(
        <Modal
          trigger=(trigger((e, _d) => self.handle(openM, e)))
          _open=self.state.opened
          basic=true
          dimmer=`blurring
          size=`tiny
          onClose=((e, _d) => self.handle(closeM, e))>
          <Header
            icon={<Icon name="warning" />}
            size=`huge
            content=(ReasonReact.stringToElement("Warning"))
          />
          <Modal.Content>
            <p> (ReasonReact.stringToElement(message)) </p>
          </Modal.Content>
          <Modal.Actions>
            <Button
              color=`red
              basic=true
              inverted=true
              onClick=((e, _d) => self.handle(closeM, e))>
              <Icon name="remove" />
              (ReasonReact.stringToElement("Cancel"))
            </Button>
            <Button color=`green onClick=((e, _d) => self.handle(submit, e))>
              <Icon name="checkmark" />
              (ReasonReact.stringToElement("Comfirm"))
            </Button>
          </Modal.Actions>
        </Modal>
      ),
  };
};