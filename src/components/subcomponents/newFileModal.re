type state = {
  input_val: string,
  opened: bool,
  type_: string,
  valid: bool,
};

let defTyp = ".elpi";

type action =
  | SetVal(string)
  | SetType(string)
  | SetOpened(bool)
  | SetValid(bool)
  | Reset;

let validate = name => {
  let regexp = [%bs.re "/^[a-z A-Z][a-z A-Z 0-9 _ -]*$/gm"];
  String.length(name) > 0 && Js.Re.test(name, regexp);
};

let component = ReasonReact.reducerComponent("NewFileModal");

let make = (~onSubmit, _children) => {
  let openM = (_e, self) => self.ReasonReact.send(SetOpened(true));
  let closeM = (_e, self) => self.ReasonReact.send(Reset);
  let change = (event, self) => {
    let newVal = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
    self.ReasonReact.send(SetVal(newVal));
    self.send(SetValid(validate(newVal)));
  };
  let submit = (event, self) => {
    let v = self.ReasonReact.state.input_val;
    let t = self.ReasonReact.state.type_;
    ReactEventRe.Synthetic.preventDefault(event);
    if (self.state.valid) {
      onSubmit(v ++ t);
      closeM(event, self);
    };
    /*self.ReasonReact.send(SetVal(""));*/
  };
  let keyDown = (event: ReactEventRe.Keyboard.t, self) =>
    switch (ReactEventRe.Keyboard.keyCode(event)) {
    | 13 => submit(event, self)
    | _ => ()
    };
  {
    ...component, /* spread the template's other defaults into here  */
    initialState: () => {
      input_val: "",
      opened: false,
      type_: defTyp,
      valid: false,
    },
    reducer: (action, state) =>
      switch (action) {
      | SetOpened(opened) => ReasonReact.Update({...state, opened})
      | SetVal(input_val) => ReasonReact.Update({...state, input_val})
      | SetType(type_) => ReasonReact.Update({...state, type_})
      | SetValid(valid) => ReasonReact.Update({...state, valid})
      | Reset =>
        ReasonReact.Update({
          input_val: "",
          opened: false,
          type_: defTyp,
          valid: false,
        })
      },
    render: self => {
      let options = [|
        {"key": ".elpi", "text": ".elpi", "value": ".elpi"},
        {"key": ".mlts", "text": ".mlts", "value": ".mlts"},
        {"key": ".mod", "text": ".mod", "value": ".mod"},
        {"key": ".sig", "text": ".sig", "value": ".sig"},
      |];
      SemanticUi.(
        <Modal
          trigger={
            <Button
              className="no-border"
              icon=true
              basic=true
              onClick=((e, _d) => self.handle(openM, e))>
              <Icon name="file outline" />
            </Button>
          }
          _open=self.state.opened
          basic=true
          dimmer=`blurring
          size=`tiny
          onClose=((e, _d) => self.handle(closeM, e))>
          <Header
            icon={<Icon name="file outline" />}
            size=`huge
            content=(ReasonReact.string("New source file"))
          />
          <Modal.Content>
            <Form.Field>
              <Input
                placeholder="Choose a name"
                label={
                  <Dropdown
                    defaultValue=".elpi"
                    onChange=((_e, d) => self.send(SetType(d##value)))
                    options
                  />
                }
                labelPosition=`right
                fluid=true
                size=`large
                inverted=true
                onChange=(self.handle(change))
                onKeyDown=(self.handle(keyDown))
              />
            </Form.Field>
          </Modal.Content>
          <Modal.Actions>
            <Button
              color=`red
              basic=true
              inverted=true
              onClick=((e, _d) => self.handle(closeM, e))>
              <Icon name="remove" />
              (ReasonReact.string("Cancel"))
            </Button>
            <Button
              color=`green
              onClick=((e, _d) => self.handle(submit, e))
              disabled=(! self.state.valid)>
              <Icon name="checkmark" />
              (ReasonReact.string("Comfirm"))
            </Button>
          </Modal.Actions>
        </Modal>
      );
    },
  };
};