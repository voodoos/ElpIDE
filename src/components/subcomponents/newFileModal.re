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
          <Button basic=true color=`red inverted=true>
            <Icon name="remove" />
            (ReasonReact.stringToElement("Cancel"))
          </Button>
          <Button color=`green inverted=true>
            <Icon name="checkmark" />
            (ReasonReact.stringToElement("Comfirm"))
          </Button>
        </Modal.Actions>
      </Modal>
    ),
  /*
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
   ),*/
};