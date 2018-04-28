type file = Editor.State.t;

type state = {active: file};

type action =
  | SetActive(file);

let component = ReasonReact.reducerComponent("FileBrowser");

let make = (~files, ~onClickFile, ~onClickNew, _children) => {
  let fileList = files =>
    Array.mapi(
      (i, f) =>
        SemanticUi.(
          <List.Item
            key=(string_of_int(i)) onClick=((_e, _d) => onClickFile(i))>
            <List.Icon name="file" />
            <List.Content>
              <List.Header as_="a">
                <b> (ReasonReact.stringToElement(f##name)) </b>
              </List.Header>
              <List.Description as_="a"> "Elpi source file" </List.Description>
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
          <NewFileModal />
          <Menu inverted=false borderless=true>
            <Menu.Item header=true> "Project" </Menu.Item>
            <Menu.Menu position=`right>
              <Button
                className="no-border"
                icon=true
                basic=true
                onClick=((_e, _d) => onClickNew())>
                <Icon name="file outline" />
              </Button>
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
/*

 <List.Item>
                   <List.Icon name="file" />
                   <List.Content>
                     <List.Header> "test.elpi" </List.Header>
                     <List.Description> "Elpi source file" </List.Description>
                   </List.Content>
                 </List.Item>

               */