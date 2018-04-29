open Sui_tools;

[@bs.module "semantic-ui-react"]
external suiTable : ReasonReact.reactClass = "Table";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeTableProps :
  (
    ~_as: string=?, /* TODO: Can also be a function ! */
    ~attached: string=?,
    ~basic: js=?,
    ~celled: Js.boolean=?,
    ~className: string=?,
    ~collapsing: Js.boolean=?,
    ~color: string=?,
    ~columns: string=?,
    ~compact: js=?,
    ~definition: Js.boolean=?,
    ~fixed: Js.boolean=?,
    /* TODO: footerRow, headerRow */
    ~inverted: Js.boolean=?,
    ~padded: js=?,
    /* TODO: renderBodyRow */
    ~selectable: Js.boolean=?,
    ~singleLine: Js.boolean=?,
    ~size: string=?,
    ~sortable: Js.boolean=?,
    ~stackable: Js.boolean=?,
    ~striped: Js.boolean=?,
    ~structured: Js.boolean=?,
    /* TODO: TableData */
    ~textAlign: string=?,
    ~unstackable: Js.boolean=?,
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
    ~reactClass=suiTable,
    ~props=
      makeTableProps(
        ~_as?,
        ~attached=?fromTopOrBottom(attached),
        ~basic=?fromBoolOrVery(basic),
        ~celled=?fromBool(celled),
        ~className?,
        ~collapsing=?fromBool(collapsing),
        ~color=?fromColor(color),
        ~columns=?fromWidth(columns),
        ~compact=?fromBoolOrVery(compact),
        ~definition=?fromBool(definition),
        ~fixed=?fromBool(fixed),
        ~inverted=?fromBool(inverted),
        ~padded=?fromBoolOrVery(padded),
        ~selectable=?fromBool(selectable),
        ~singleLine=?fromBool(singleLine),
        ~size=?fromSmallOrLarge(size),
        ~sortable=?fromBool(sortable),
        ~stackable=?fromBool(stackable),
        ~striped=?fromBool(striped),
        ~structured=?fromBool(structured),
        ~textAlign=?fromLeftOrCenterOrRight(textAlign),
        ~unstackable=?fromBool(unstackable),
        ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
        (),
      ),
    children,
  );

module Body = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Table"]
  external sui : ReasonReact.reactClass = "Body";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=sui,
      ~props=makeProps(~_as?, ~className?, ()),
      children,
    );
};

module Cell = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Table"]
  external sui : ReasonReact.reactClass = "Cell";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~_as: string=?, /* TODO: Can also be a function ! */
      /* TODO : cellAs, cells */
      ~className: string=?,
      ~collapsing: Js.boolean=?,
      /* TODO : content */
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      /* TODO : icon */
      ~negative: Js.boolean=?,
      ~positive: Js.boolean=?,
      ~selectable: Js.boolean=?,
      ~singleLine: Js.boolean=?,
      ~textAlign: string=?,
      ~verticalAlign: string=?,
      ~warning: Js.boolean=?,
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
      ~reactClass=sui,
      ~props=
        makeProps(
          ~active=?fromBool(active),
          ~_as?,
          ~className?,
          ~collapsing=?fromBool(collapsing),
          ~disabled=?fromBool(disabled),
          ~error=?fromBool(error),
          ~negative=?fromBool(negative),
          ~positive=?fromBool(positive),
          ~selectable=?fromBool(selectable),
          ~singleLine=?fromBool(singleLine),
          ~textAlign=?fromLeftOrCenterOrRight(textAlign),
          ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
          ~warning=?fromBool(warning),
          (),
        ),
      children,
    );
};

module Row = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Table"]
  external sui : ReasonReact.reactClass = "Row";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~_as: string=?, /* TODO: Can also be a function ! */
      /* TODO : cellAs, cells */
      ~className: string=?,
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~negative: Js.boolean=?,
      ~positive: Js.boolean=?,
      ~textAlign: string=?,
      ~verticalAlign: string=?,
      ~warning: Js.boolean=?,
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
      ~reactClass=sui,
      ~props=
        makeProps(
          ~active=?fromBool(active),
          ~_as?,
          ~className?,
          ~disabled=?fromBool(disabled),
          ~error=?fromBool(error),
          ~negative=?fromBool(negative),
          ~positive=?fromBool(positive),
          ~textAlign=?fromLeftOrCenterOrRight(textAlign),
          ~verticalAlign=?fromTopOrMiddleOrBottom(verticalAlign),
          ~warning=?fromBool(warning),
          ~width=?fromWidth(width),
          (),
        ),
      children,
    );
};