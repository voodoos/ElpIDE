type state = {bottomRef: ref(option(Dom.element))};

type action = unit; /* We don't need actions, but we need state for refs */

type retainedProps = {childs: array(ReasonReact.reactElement)};

let component = ReasonReact.reducerComponentWithRetainedProps("AlwaysBottom");

let setBottomRef = (theRef, {ReasonReact.state}) =>
  /* We need a ref to the div marking the bottom of the console to keep it scrolled */
  state.bottomRef := Js.Nullable.toOption(theRef);

let make = (~className, children: array(ReasonReact.reactElement)) => {
  ...component,
  initialState: () => {bottomRef: ref(None)},
  retainedProps: {
    childs: children,
  },
  reducer: (_action: action, _state) => ReasonReact.NoUpdate,
  willUpdate: ({oldSelf, newSelf}) => {
    /* Scrolling to bottom on update ugly-fix...
     * TODO : This is wrong, works but trigger warnings :
     *  Warning: Can't call setState (or forceUpdate) on an unmounted component.
     * This is a no-op, but it indicates a memory leak in your application.
     * To fix, cancel all subscriptions and asynchronous tasks in the componentWillUnmount method.
     * */
    ignore(oldSelf);
    switch (newSelf.state.bottomRef^) {
    | Some(r) =>
      ReactDOMRe.domElementToObj(r)##scrollIntoView({"behavior": "smooth"}) /* unsafe */
    | _ => ()
    };
  },
  didUpdate: ({oldSelf, newSelf}) => {
    /* Scrolling to bottom on update
     * Thanks to the Bottom div */
    ignore(oldSelf);
    switch (newSelf.state.bottomRef^) {
    | Some(r) =>
      ReactDOMRe.domElementToObj(r)##scrollIntoView({"behavior": "smooth"}) /* unsafe */
    | _ => ()
    };
  },
  shouldUpdate: ({oldSelf, newSelf}) =>
    oldSelf.retainedProps.childs !== newSelf.retainedProps.childs,
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