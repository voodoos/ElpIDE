type state = {
  opened: bool,
  selectedFiles: list((ReasonReact.reactElement, File.t)),
};

type action =
  | Opened(bool)
  | EmptyFiles
  | AddFile(string, string);

let component = ReasonReact.reducerComponent("LoadModal");

let make = (~trigger, ~onOk, _children) => {
  let validate = name =>
    Js.Re.test(name, [%bs.re "/^[^\\.]+\\.(?:elpi|mlts|mod|sig)$/gm"]);
  let openM = (_e, self) => self.ReasonReact.send(Opened(true));
  let addMlts = (_e, self) => {
    open Js.Promise;
    /* weird trick to please Parcel */
    let t = BaseJs.requireAs("../../examples/coremlts.zip");
    Fetch.fetch(t)
    |> then_(Fetch.Response.blob)
    |> then_(f => Zip.(
          create()
          |. loadAsync(`blob(BaseJs.fromFetchBlob(f)))
          |> Js.Promise.then_(zip => {
              zip
              |. forEach((_relativePath, zipEntry) =>
                    if (validate(zipEntry##name)) {
                      zipEntry
                      |. Object.asyncString()
                      |> Js.Promise.then_(content => {
                          self.ReasonReact.send(
                            AddFile(zipEntry##name, content),
                          );
                          Js.Promise.resolve(content);
                        })
                      |> ignore;
                    }
                  );
              /*Js.log(zipEntry##name));*/
              Js.Promise.resolve(zip);
            })
          |> ignore
    ) |> resolve)
    |> ignore;
  };
  let closeM = (_e, self) => {
    self.ReasonReact.send(EmptyFiles);
    self.send(Opened(false));
  };
  let submit = (e, self) => {
    onOk(
      Array.of_list(List.rev_map(snd, self.ReasonReact.state.selectedFiles)),
    );
    self.send(EmptyFiles);
    closeM(e, self);
  };
  let change = (event, self) => {
    self.ReasonReact.send(EmptyFiles);
    let readZip = f =>
      Zip.(
        create()
        |. loadAsync(`blob(f))
        |> Js.Promise.then_(zip => {
             zip
             |. forEach((_relativePath, zipEntry) =>
                  if (validate(zipEntry##name)) {
                    zipEntry
                    |. Object.asyncString()
                    |> Js.Promise.then_(content => {
                         self.ReasonReact.send(
                           AddFile(zipEntry##name, content),
                         );
                         Js.Promise.resolve(content);
                       })
                    |> ignore;
                  }
                );
             /*Js.log(zipEntry##name));*/
             Js.Promise.resolve(zip);
           })
        |> ignore
      );
    let files = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##files;
    /** Files should be a "filelist" */
    let n: int = files##length;
    for (i in 0 to n - 1) {
      let f = files[i];
      Js.log(f);
      if (Tools.isMimeZip(f##_type)) {
        readZip(f);
      } else if (validate(f##name)) {
        let fr = FileReader.create();
        fr
        |. FileReader.setOnload(_e =>
             self.ReasonReact.send(
               AddFile(f##name, fr |. FileReader.getResultString),
             )
           );
        fr |. FileReader.readAsText(f);
      };
    };
  };
  {
    ...component, /* spread the template's other defaults into here  */
    initialState: () => {opened: false, selectedFiles: []},
    reducer: (action, state) =>
      switch (action) {
      | Opened(opened) => ReasonReact.Update({...state, opened})
      | EmptyFiles => ReasonReact.Update({...state, selectedFiles: []})
      | AddFile(name, content) =>
        ReasonReact.Update({
          ...state,
          selectedFiles: [
            (
              SemanticUi.(
                <List.Item
                  icon="file"
                  content=(ReasonReact.string(name))
                  key=name
                />
              ),
              File.make(name, content),
            ),
            ...state.selectedFiles,
          ],
        })
      },
    render: self => {
      module OList = List;
      SemanticUi.(
        <Modal
          trigger=(trigger((e, _d) => self.handle(openM, e)))
          _open=self.state.opened
          basic=true
          dimmer=`blurring
          size=`tiny
          onClose=((e, _d) => self.handle(closeM, e))>
          <Header
            icon={<Icon name="folder open" />}
            size=`huge
            content=(ReasonReact.string("Load file from disk"))
          />
          <Modal.Content>
            <Form.Field>
              <Input
                _type="file"
                fluid=true
                size=`large
                onChange=(self.handle(change))
                multiple=true
              />
            </Form.Field>
            <List
              items=(Array.of_list(OList.map(fst, self.state.selectedFiles)))
            />
          </Modal.Content>
          <Modal.Actions>
            <Button
              color=`blue
              basic=true
              inverted=true
              onClick=((e, _d) => self.handle(addMlts, e))>
              <Icon name="plus" />
              (ReasonReact.string("Add MTLS kernel"))
            </Button>
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
              disabled=(self.state.selectedFiles == [])>
              <Icon name="checkmark" />
              (ReasonReact.string("Comfirm"))
            </Button>
          </Modal.Actions>
        </Modal>
      );
    },
  };
};