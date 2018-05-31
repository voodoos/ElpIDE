open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Table";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeTableProps :
  (
    ~_as: js=?,
    ~attached: string=?,
    ~basic: js=?,
    ~celled: bool=?,
    ~className: string=?,
    ~collapsing: bool=?,
    ~color: string=?,
    ~columns: string=?,
    ~compact: js=?,
    ~definition: bool=?,
    ~fixed: bool=?,
    /* TODO: footerRow, headerRow */
    ~inverted: bool=?,
    ~padded: js=?,
    /* TODO: renderBodyRow */
    ~selectable: bool=?,
    ~singleLine: bool=?,
    ~size: string=?,
    ~sortable: bool=?,
    ~stackable: bool=?,
    ~striped: bool=?,
    ~structured: bool=?,
    /* TODO: TableData */
    ~textAlign: string=?,
    ~unstackable: bool=?,
    ~verticalAlign: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?,
      ~attached=?,
      ~basic=?,
      ~celled=?,
      ~className=?,
      ~collapsing=?,
      ~color=?,
      ~columns=?,
      ~compact=?,
      ~definition=?,
      ~fixed=?,
      ~inverted=?,
      ~padded=?,
      ~selectable=?,
      ~singleLine=?,
      ~size=?,
      ~sortable=?,
      ~stackable=?,
      ~striped=?,
      ~structured=?,
      ~textAlign=?,
      ~unstackable=?,
      ~verticalAlign=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeTableProps(
        ~_as=?fromStringOrReactClass(_as),
        ~attached=?fromTopOrBottom(attached),
        ~basic=?fromBoolOrVery(basic),
        ~celled?,
        ~className?,
        ~collapsing?,
        ~color=?fromColor(color),
        ~columns=?fromWidth(columns),
        ~compact=?fromBoolOrVery(compact),
        ~definition?,
        ~fixed?,
        ~inverted?,
        ~padded=?fromBoolOrVery(padded),
        ~selectable?,
        ~singleLine?,
        ~size=?fromSmallOrLarge(size),
        ~sortable?,
        ~stackable?,
        ~striped?,
        ~structured?,
        ~textAlign=?fromLeftOrCenterOrRight(textAlign),
        ~unstackable?,
        ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
        (),
      ),
    children,
  );

module Body = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Table"]
  external react : ReasonReact.reactClass = "Body";
  [@bs.obj]
  external makeProps : (~_as: js=?, ~className: string=?, unit) => _ = "";
  let make = (~_as=?, ~className=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as=?fromStringOrReactClass(_as), ~className?, ()),
      children,
    );
};

module Cell = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Table"]
  external react : ReasonReact.reactClass = "Cell";
  [@bs.obj]
  external makeProps :
    (
      ~active: bool=?,
      ~_as: js=?,
      /* TODO : cellAs, cells */
      ~className: string=?,
      ~collapsing: bool=?,
      /* TODO : content */
      ~disabled: bool=?,
      ~error: bool=?,
      /* TODO : icon */
      ~negative: bool=?,
      ~positive: bool=?,
      ~selectable: bool=?,
      ~singleLine: bool=?,
      ~textAlign: string=?,
      ~verticalAlign: string=?,
      ~warning: bool=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active=?,
        ~_as=?,
        ~className=?,
        ~collapsing=?,
        ~disabled=?,
        ~error=?,
        ~negative=?,
        ~positive=?,
        ~selectable=?,
        ~singleLine=?,
        ~textAlign=?,
        ~verticalAlign=?,
        ~warning=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~active?,
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~collapsing?,
          ~disabled?,
          ~error?,
          ~negative?,
          ~positive?,
          ~selectable?,
          ~singleLine?,
          ~textAlign=?fromLeftOrCenterOrRight(textAlign),
          ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
          ~warning?,
          (),
        ),
      children,
    );
};

module Row = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Table"]
  external react : ReasonReact.reactClass = "Row";
  [@bs.obj]
  external makeProps :
    (
      ~active: bool=?,
      ~_as: js=?,
      /* TODO : cellAs, cells */
      ~className: string=?,
      ~disabled: bool=?,
      ~error: bool=?,
      ~negative: bool=?,
      ~positive: bool=?,
      ~textAlign: string=?,
      ~verticalAlign: string=?,
      ~warning: bool=?,
      ~width: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active=?,
        ~_as=?,
        ~className=?,
        ~disabled=?,
        ~error=?,
        ~negative=?,
        ~positive=?,
        ~textAlign=?,
        ~verticalAlign=?,
        ~warning=?,
        ~width=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~active?,
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~disabled?,
          ~error?,
          ~negative?,
          ~positive?,
          ~textAlign=?fromLeftOrCenterOrRight(textAlign),
          ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
          ~warning?,
          ~width=?fromWidth(width),
          (),
        ),
      children,
    );
};