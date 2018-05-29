type state = {active: int};

type retainedProps = {files: array(File.t)};

type action =
  | SetActive(int);

let component = ReasonReact.reducerComponentWithRetainedProps("FileBrowser");

let make = (~files, ~onClickFile, ~onClickNew, ~onDeleteFile, _children) => {
  let fileList = files => {
    let lnth = Array.length(files);
    Array.mapi(
      (i, f: File.t) =>
        SemanticUi.(
          <List.Item key=(string_of_int(i))>
            <List.Icon name="file" />
            <List.Content>
              <a onClick=(_e => onClickFile(i))>
                <b> (ReasonReact.string(f.name)) </b>
              </a>
              (
                if (lnth > 1) {
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
                  />;
                } else {
                  ReasonReact.null;
                }
              )
            </List.Content>
          </List.Item>
        ),
      files,
    );
  };
  {
    ...component,
    initialState: () => {active: (-1)},
    retainedProps: {
      files: files,
    },
    reducer: (action, _state) =>
      switch (action) {
      | SetActive(file) => ReasonReact.Update({active: file})
      },
    shouldUpdate: ({oldSelf, newSelf}) =>
      /* Warning: this may be too aggressive */
      Array.length(oldSelf.retainedProps.files)
      !== Array.length(newSelf.retainedProps.files),
    render: _self =>
      SemanticUi.(
        <div className="p-fbrowser">
          <Menu inverted=false borderless=true className="p-fbrowser-menu">
            <Menu.Item header=true> "Project" </Menu.Item>
            <Menu.Menu position=`right>
              <NewFileModal onSubmit=onClickNew />
            </Menu.Menu>
          </Menu>
          <List className="p-fbrowser-list">
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