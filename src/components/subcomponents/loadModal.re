type state = {opened: bool};

type action =
  | Opened(bool);

let component = ReasonReact.reducerComponent("LoadModal");

let make = (~trigger, ~message, ~onOk, _children) => {
  let openM = (_e, self) => self.ReasonReact.send(Opened(true));
  let closeM = (_e, self) => self.ReasonReact.send(Opened(false));
  let submit = (e, self) => {
    onOk();
    closeM(e, self);
  };
  let change = (event, self) => {
    let readZip = f => {
      open Zip;
      let z = create();
      z
      |. loadAsync(`blob(f))
      |> Js.Promise.then_(zip => {
           zip |. forEach((relativePath, zipEntry) => Js.log(zipEntry##name));
           Js.Promise.resolve(zip);
         })
      |> ignore;
    };
    let files = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##files;
    /** Files should be a "filelist" */
    let n: int = files##length;
    for (i in 0 to n - 1) {
      let f = files[i];
      if (f##_type == "application/zip") {
        readZip(f);
      };
    };
  };
  {
    ...component, /* spread the template's other defaults into here  */
    initialState: () => {opened: false},
    reducer: (action, state) =>
      switch (action) {
      | Opened(opened) => ReasonReact.Update({opened: opened})
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
            icon={<Icon name="upload" />}
            size=`huge
            content=(ReasonReact.stringToElement("Load file from disk"))
          />
          <Modal.Content>
            <Form.Field>
              <Input
                _type="file"
                fluid=true
                size=`large
                onChange=(self.handle(change))
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