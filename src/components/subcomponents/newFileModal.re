let component = ReasonReact.statelessComponent("NewFileModal");

let make = _children => {
  ...component, /* spread the template's other defaults into here  */
  render: _self =>
    SemanticUi.(
      <Modal
        trigger={
          <Button className="no-border" icon=true basic=true>
            <Icon name="file outline" />
          </Button>
        }
        basic=true
        dimmer=`blurring
        size=`tiny>
        <Header
          icon={<Icon name="file outline" />}
          size=`huge
          content=(ReasonReact.stringToElement("New source file"))
        />
        <Modal.Content>
          <Input
            placeholder="Choose a name"
            label=(ReasonReact.stringToElement(".elpi"))
            labelPosition=`right
            fluid=true
            size=`large
            inverted=true
          />
        </Modal.Content>
        <Modal.Actions>
          <Button color=`red basic=true inverted=true >
            <Icon name="remove" />
            (ReasonReact.stringToElement("Cancel"))
          </Button>
          <Button color=`green >
            <Icon name="checkmark" />
            (ReasonReact.stringToElement("Comfirm"))
          </Button>
        </Modal.Actions>
      </Modal>
    ),
};