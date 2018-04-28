let component = ReasonReact.statelessComponent("NewFileModal");

let make = _children => {
  ...component, /* spread the template's other defaults into here  */
  render: _self =>
    SemanticUi.(
      <Modal trigger={<Button> "Show Modal" </Button>}>
        <Modal.Header> "Select a Photo" </Modal.Header>
        <Modal.Content>
          <Modal.Description>
            <Header> "Default Profile Image" </Header>
            <p>
              (
                ReasonReact.stringToElement(
                  "We've found the following gravatar image associated with your e-mail address.",
                )
              )
            </p>
            <p>
              (ReasonReact.stringToElement("Is it okay to use this photo?"))
            </p>
          </Modal.Description>
        </Modal.Content>
      </Modal>
    ),
};