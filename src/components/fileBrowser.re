type file = Editor.State.t;

type state = {active: file};

type action =
  | SetActive(file);

let component = ReasonReact.reducerComponent("FileBrowser");

let make = (~files, _children) => {
  let fileList = files =>
    Array.map(
      f =>
        SemanticUi.(
          <List.Item className="active">
            <List.Icon name="file" />
            <List.Content>
              <List.Header>
                <b> (ReasonReact.stringToElement(f##name)) </b>
              </List.Header>
              <List.Description> "Elpi source file" </List.Description>
            </List.Content>
          </List.Item>
        ),
      files,
    );
  {
    ...component,
    initialState: () => {active: files[0]},
    reducer: (action, state) =>
      switch (action) {
      | SetActive(file) => ReasonReact.Update({active: file})
      },
    render: self =>
      SemanticUi.(
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