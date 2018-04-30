type file = Editor.State.t;

type state = {active: file};

type action =
  | SetActive(file);

let component = ReasonReact.reducerComponent("FileBrowser");

let make = (~files, ~onClickFile, ~onClickNew, ~onDeleteFile, _children) => {
  let fileList = files =>
    Array.mapi(
      (i, f) =>
        SemanticUi.(
          <List.Item key=(string_of_int(i))>
            <List.Icon name="file" />
            <List.Content>
              <a onClick=(_e => onClickFile(i))>
                <b> (ReasonReact.stringToElement(f##name)) </b>
              </a>
              <ConfirmationModal
                trigger=(
                  onClick =>
                    <Button
                      className="no-border trash-btn"
                      compact=true
                      icon=true
                      floated=`right
                      basic=true
                      size=`small
                      onClick>
                      <Icon name="trash" />
                    </Button>
                )
                message="Are you sure you want to delete this file ?"
                onOk=(() => onDeleteFile(i))
              />
            </List.Content>
          </List.Item>
        ),
      files,
    );
  {
    ...component,
    initialState: () => {active: files[0]},
    reducer: (action, _state) =>
      switch (action) {
      | SetActive(file) => ReasonReact.Update({active: file})
      },
    render: _self =>
      SemanticUi.(
        <div>
          <Menu inverted=false borderless=true>
            <Menu.Item header=true> "Project" </Menu.Item>
            <Menu.Menu position=`right>
              <NewFileModal onSubmit=onClickNew />
            </Menu.Menu>
          </Menu>
          <List className="p-fbrowser">
            <List.Item>
              <List.Icon name="folder" />
              <List.Content>
                <List.Header> "src" </List.Header>
                <List.Description> "Source files" </List.Description>
                <List.List> (fileList(files)) </List.List>
              </List.Content>
            </List.Item>
          </List>
        </div>
      ),
  };
};