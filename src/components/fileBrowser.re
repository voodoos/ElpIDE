type node = {
  handle: int,
  name: string,
  children: list(node),
};

let test = {
  handle: 1,
  name: "root",
  children: [
    {handle: 2, name: "child1", children: []},
    {handle: 3, name: "child2", children: []},
  ],
};

let rec stringOfNode = node =>
  switch (node.children) {
  | [] => node.name
  | [child, ...tail] =>
    node.name
    ++ stringOfNode(child)
    ++ "\n"
    ++ stringOfNode({...node, children: tail})
  };

type state = {active: node};

type action =
  | SetActive(node);

let component = ReasonReact.reducerComponent("FileBrowser");

let make = (~data, _children) => {
  ...component,
  initialState: () => {active: data},
  reducer: (action, state) =>
    switch (action) {
    | SetActive(node) => ReasonReact.Update({active: node})
    },
  render: self => ReasonReact.stringToElement(stringOfNode(data)),
};