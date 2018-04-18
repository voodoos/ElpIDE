type state = {
  cursor: option(Treebeard.data),
  data: Treebeard.data,
};

type action =
  | SetCursor(Treebeard.data);

let component = ReasonReact.reducerComponent("FileBrowser");

let make = _children => {
  ...component,
  initialState: () => {
    cursor: None,
    data:
      Treebeard.makeNode(
        "root",
        ~toggled=false,
        ~children=[|
          Treebeard.makeNode("leaf1"),
          Treebeard.makeNode("leaf2"),
        |],
      ),
  },
  reducer: (action, state) =>
    switch (action) {
    | SetCursor(cursor) =>
      Js.log("changiiing");
      ReasonReact.Update({...state, cursor: Some(cursor)});
    },
  render: self => {
    let change = (node: Treebeard.data, toggled) => {
      /*self.handle(
          (couple, self) => {
        let (node, toggled) = couple;*/
      switch (self.state.cursor) {
      | None => ()
      | Some(node) =>
        self.send(SetCursor(Treebeard.setActive(node, false)))
      };
      let tnode =
        switch (Js.Undefined.toOption(node##children)) {
        | None => node
        | Some(_) => Treebeard.setToggled(node, toggled)
        };
      self.send(SetCursor(Treebeard.setActive(tnode, true)));
      /*
       if(this.state.cursor){this.state.cursor.active = false;}
       node.active = true;
       if(node.children){ node.toggled = toggled; }
       this.setState({ cursor: node });
       */
      Js.log(node);
      Js.log(toggled);
      Js.log(self.state.cursor);
      /*},
        (node, toggled),
        )*/
    };
    let data = self.state.data;
    <Treebeard data onToggle=change />;
  },
};