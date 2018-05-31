open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Dropdown";

[@bs.obj]
/* TODO: additionLabel, additionPosition, allowAdditions */
external makeProps :
  (
    ~_as: js=?,
    ~basic: bool=?,
    ~button: bool=?,
    ~className: string=?,
    ~closeOnBlur: bool=?,
    ~closeOnChange: bool=?,
    ~compact: bool=?,
    ~deburr: bool=?,
    ~defaultOpen: bool=?,
    ~defaultSearchQuery: string=?,
    /* TODO: defaultSelectedLabel */
    ~defaultValue: 'a=?, /* TODO: narrow this type... */
    ~direction: string=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~floating: bool=?,
    ~fluid: bool=?, /* TODO: header */
    ~icon: string=?,
    ~inline: bool=?,
    ~item: bool=?,
    ~labeled: bool=?,
    ~loading: bool=?,
    ~minCharacters: int=?,
    ~multiple: bool=?,
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
    ~_open: bool=?,
    ~openOnFocus: bool=?,
    ~options: array(Js.t({..}))=?,
    ~placeholder: string=?, /* TODO: pointing, renderLabel, search, searchInput */
    ~searchQuery: string=?,
    ~selectOnBlur: bool=?,
    ~selectOnNavigation: bool=?,
    ~selection: bool=?,
    /* TODO: selectedLabel, selection */
    ~simple: bool=?, /* TODO: tabIndex */
    ~text: string=?, /* TODO: trigger */
    ~upward: bool=?,
    ~value: 'a=?,
    ~wrapSelection: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?,
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
      ~selection=?,
      /* TODO: selectedLabel, selection */
      ~simple=?, /* TODO: tabIndex */
      ~text=?, /* TODO: trigger */
      ~upward=?,
      ~value=?,
      ~wrapSelection=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~_as=?fromStringOrReactClass(_as),
        ~basic?,
        ~button?,
        ~className?,
        ~closeOnBlur?,
        ~closeOnChange?,
        ~compact?,
        ~deburr?,
        ~defaultOpen?,
        ~defaultSearchQuery?,
        /* TODO: defaultSelectedLabel */
        ~defaultValue?,
        ~direction=?fromLeftOrRight(direction),
        ~disabled?,
        ~error?,
        ~floating?,
        ~fluid?, /* TODO: header */
        ~icon?,
        ~inline?,
        ~item?,
        ~labeled?,
        ~loading?,
        ~minCharacters?,
        ~multiple?,
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
        ~_open?,
        ~openOnFocus?,
        ~options?,
        ~placeholder?, /* TODO: pointing, renderLabel, search, searchInput */
        ~searchQuery?,
        ~selectOnBlur?,
        ~selectOnNavigation?,
        ~selection?,
        /* TODO: selectedLabel */
        ~simple?, /* TODO: tabIndex */
        ~text?, /* TODO: trigger */
        ~upward?,
        ~value?,
        ~wrapSelection?,
        (),
      ),
    children,
  );

module Divider = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external react : ReasonReact.reactClass = "Divider";
  [@bs.obj]
  external makeProps : (~_as: js=?, ~className: string=?, unit) => _ = "";
  let make = (~_as=?, ~className=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ()),
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~icon: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, ~icon=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~icon?,
          (),
        ),
      children,
    );
};

module Item = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external react : ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps :
    (
      ~active: bool=?,
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~description: ReasonReact.reactElement=?,
      ~disabled: bool=?,
      ~flag: string=?,
      ~icon: string=?, /* TODO: image, label */
      ~onClick: (ReactEventRe.Mouse.t, Js.t({..})) => unit=?,
      ~selected: bool=?,
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
      ~reactClass=react,
      ~props=
        makeProps(
          ~active?,
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~description?,
          ~disabled?,
          ~flag?,
          ~icon?,
          ~onClick?,
          ~selected?,
          ~text?,
          (),
        ),
      children,
    );
};

module Menu = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external react : ReasonReact.reactClass = "Menu";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~direction: string=?,
      ~_open: bool=?,
      ~scrolling: bool=?,
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
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          ~direction=?fromLeftOrRight(direction),
          ~_open?,
          ~scrolling?,
          (),
        ),
      children,
    );
};

module SearchInput = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Dropdown"]
  external react : ReasonReact.reactClass = "SearchInput";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
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
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
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