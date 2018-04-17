type state = {bottomRef: ref(option(Dom.element))};

type action = unit; /* We don't need actions, but we need state for refs */

let component = ReasonReact.reducerComponent("AlwaysBottom");

let setBottomRef = (theRef, {ReasonReact.state}) =>
  /* We need a ref to the div marking the bottom of the console to keep it scrolled */
  state.bottomRef := Js.Nullable.toOption(theRef);

let make = (~className, children: array(ReasonReact.reactElement)) => {
  ...component,
  initialState: () => {bottomRef: ref(None)},
  reducer: (_action: action, _state) => ReasonReact.NoUpdate,
  didUpdate: ({oldSelf, newSelf}) =>
    /* Scrolling to bottom on update
     * Thanks to the Bottom div */
    switch (newSelf.state.bottomRef^) {
    | Some(r) =>
      ReactDOMRe.domElementToObj(r)##scrollIntoView({"behavior": "smooth"}) /* unsafe */
    | _ => ()
    },
  render: self => {
    let childs =
      ReasonReact.createDomElement(
        "div",
        ~props={"className": ""},
        children,
      );
    <div className=(className ++ " r-always-bottom")>
      childs
      <div ref=(self.handle(setBottomRef)) />
    </div>;
  },
};