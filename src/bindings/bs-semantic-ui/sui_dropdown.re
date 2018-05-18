open Sui_tools;

[@bs.module "semantic-ui-react"]
external sui : ReasonReact.reactClass = "Dropdown";

[@bs.obj]
/* TODO: additionLabel, additionPosition, allowAdditions */
external makeProps :
  (
    ~_as: string=? /* TODO: Can also be a function ! */,
    ~basic: Js.boolean=?,
    ~button: Js.boolean=?,
    ~className: string=?,
    ~closeOnBlur: Js.boolean=?,
    ~closeOnChange: Js.boolean=?,
    ~compact: Js.boolean=?,
    ~deburr: Js.boolean=?,
    ~defaultOpen: Js.boolean=?,
    ~defaultSearchQuery: string=?,
    /* TODO: defaultSelectedLabel */
    ~defaultValue: 'a=?, /* TODO: narrow this type... */
    ~direction: string=?,
    ~disabled: Js.boolean=?,
    ~error: Js.boolean=?,
    ~floating: Js.boolean=?,
    ~fluid: Js.boolean=?, /* TODO: header */
    ~icon: string=?,
    ~inline: Js.boolean=?,
    ~item: Js.boolean=?,
    ~labeled: Js.boolean=?,
    ~loading: Js.boolean=?,
    ~minCharacters: int=?,
    ~multiple: Js.boolean=?,
    ~noResultsMessage: string=?,
    ~onAddItem: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onBlur: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onChange: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~onClose: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onFocus: (ReactEventRe.Focus.t, Js.t({..})) => unit=?,
    ~onLabelClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~onMouseDown: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
    ~onOpen: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onSearchChange: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~_open: Js.boolean=?,
    ~openOnFocus: Js.boolean=?,
    ~options: array(Js.t({..}))=?,
    ~placeholder: string=?, /* TODO: pointing, renderLabel, search, searchInput */
    ~searchQuery: string=?,
    ~selectOnBlur: Js.boolean=?,
    ~selectOnNavigation: Js.boolean=?,
    /* TODO: selectedLabel, selection */
    ~simple: Js.boolean=?, /* TODO: tabIndex */
    ~text: string=?, /* TODO: trigger */
    ~upward: Js.boolean=?, /* TODO: value */
    ~wrapSelection: Js.boolean=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=? /* TODO: Can also be a function ! */,
      ~basic=?,
      ~button=?,
      ~className=?,
      ~closeOnBlur=?,
      ~closeOnChange=?,
      ~compact=?,
      ~deburr=?,
      ~defaultOpen=?,
      ~defaultSearchQuery=?,
      /* TODO: defaultSelectedLabel */
      ~defaultValue=?,
      ~direction=?,
      ~disabled=?,
      ~error=?,
      ~floating=?,
      ~fluid=?, /* TODO: header */
      ~icon=?,
      ~inline=?,
      ~item=?,
      ~labeled=?,
      ~loading=?,
      ~minCharacters=?,
      ~multiple=?,
      ~noResultsMessage=?,
      ~onAddItem=?,
      ~onBlur=?,
      ~onChange=?,
      ~onClick=?,
      ~onClose=?,
      ~onFocus=?,
      ~onLabelClick=?,
      ~onMouseDown=?,
      ~onOpen=?,
      ~onSearchChange=?,
      ~_open=?,
      ~openOnFocus=?,
      ~options=?,
      ~placeholder=?, /* TODO: pointing, renderLabel, search, searchInput */
      ~searchQuery=?,
      ~selectOnBlur=?,
      ~selectOnNavigation=?,
      /* TODO: selectedLabel, selection */
      ~simple=?, /* TODO: tabIndex */
      ~text=?, /* TODO: trigger */
      ~upward=?, /* TODO: value */
      ~wrapSelection=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=sui,
    ~props=
      makeProps(
        ~_as? /* TODO: Can also be a function ! */,
        ~basic=?fromBool(basic),
        ~button=?fromBool(button),
        ~className?,
        ~closeOnBlur=?fromBool(closeOnBlur),
        ~closeOnChange=?fromBool(closeOnChange),
        ~compact=?fromBool(compact),
        ~deburr=?fromBool(deburr),
        ~defaultOpen=?fromBool(defaultOpen),
        ~defaultSearchQuery?,
        /* TODO: defaultSelectedLabel */
        ~defaultValue?,
        ~direction=?fromLeftOrRight(direction),
        ~disabled=?fromBool(disabled),
        ~error=?fromBool(error),
        ~floating=?fromBool(floating),
        ~fluid=?fromBool(fluid), /* TODO: header */
        ~icon?,
        ~inline=?fromBool(inline),
        ~item=?fromBool(item),
        ~labeled=?fromBool(labeled),
        ~loading=?fromBool(loading),
        ~minCharacters?,
        ~multiple=?fromBool(multiple),
        ~noResultsMessage?,
        ~onAddItem?,
        ~onBlur?,
        ~onChange?,
        ~onClick?,
        ~onClose?,
        ~onFocus?,
        ~onLabelClick?,
        ~onMouseDown?,
        ~onOpen?,
        ~onSearchChange?,
        ~_open=?fromBool(_open),
        ~openOnFocus=?fromBool(openOnFocus),
        ~options?,
        ~placeholder?, /* TODO: pointing, renderLabel, search, searchInput */
        ~searchQuery?,
        ~selectOnBlur=?fromBool(selectOnBlur),
        ~selectOnNavigation=?fromBool(selectOnNavigation),
        /* TODO: selectedLabel, selection */
        ~simple=?fromBool(simple), /* TODO: tabIndex */
        ~text?, /* TODO: trigger */
        ~upward=?fromBool(upward), /* TODO: value */
        ~wrapSelection=?fromBool(wrapSelection),
        (),
      ),
    children,
  );

module Divider = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external sui : ReasonReact.reactClass = "Divider";
  [@bs.obj]
  external makeProps : (~_as: string=?, ~className: string=?, unit) => _ = "";
  let make = (~_as=?, ~className=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~_as?, ~className?, ()),
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external sui : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~icon: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, ~icon=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~_as?, ~className?, ~content?, ~icon?, ()),
      children,
    );
};

module Item = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external sui : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~_as: string=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~description: ReasonReact.reactElement=?,
      ~disabled: Js.boolean=?,
      ~flag: string=?,
      ~icon: string=?, /* TODO: image, label */
      ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
      ~selected: Js.boolean=?,
      ~text: string=?, /* TODO: value */
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active=?,
        ~_as=?,
        ~className=?,
        ~content=?,
        ~description=?,
        ~disabled=?,
        ~flag=?,
        ~icon=?,
        ~onClick=?,
        ~selected=?,
        ~text=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=
        makeProps(
          ~active?,
          ~_as?,
          ~className?,
          ~content?,
          ~description?,
          ~disabled=?fromBool(disabled),
          ~flag?,
          ~icon?,
          ~onClick?,
          ~selected=?fromBool(selected),
          ~text?,
          (),
        ),
      children,
    );
};

module Menu = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external sui : ReasonReact.reactClass = "Menu";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~direction: string=?,
      ~_open: Js.boolean=?,
      ~scrolling: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_as=?,
        ~className=?,
        ~content=?,
        ~direction=?,
        ~_open=?,
        ~scrolling=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=
        makeProps(
          ~_as?,
          ~className?,
          ~content?,
          ~direction=?fromLeftOrRight(direction),
          ~_open=?fromBool(_open),
          ~scrolling=?fromBool(scrolling),
          (),
        ),
      children,
    );
};

module SearchInput = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external sui : ReasonReact.reactClass = "SearchInput";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?,
      ~autoComplete: string=?,
      ~className: string=?, /* TODO: inputRef */
      ~tabIndex: int=?, /* Also string ? */
      ~_type: string=?,
      ~value: string=?, /* Also number ? */
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_as=?,
        ~autoComplete=?,
        ~className=?,
        ~tabIndex=?,
        ~_type=?,
        ~value=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=
        makeProps(
          ~_as?,
          ~autoComplete?,
          ~className?,
          ~tabIndex?,
          ~_type?,
          ~value?,
          (),
        ),
      children,
    );
};