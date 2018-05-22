open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Segment";

[@bs.obj]
external makeProps :
  (
    ~_as: js=?,
    ~attached: js=?,
    ~basic: Js.boolean=?,
    ~circular: Js.boolean=?,
    ~className: string=?,
    ~clearing: Js.boolean=?,
    ~color: string=?,
    ~compact: Js.boolean=?,
    ~content: ReasonReact.reactElement=?,
    ~disabled: Js.boolean=?,
    ~floated: string=?,
    ~inverted: Js.boolean=?,
    ~loading: Js.boolean=?,
    ~padded: js=?,
    ~piled: Js.boolean=?,
    ~raised: Js.boolean=?,
    ~secondary: Js.boolean=?,
    ~size: string=?,
    ~stacked: Js.boolean=?,
    ~tertiary: Js.boolean=?,
    ~textAlign: string=?,
    ~vertical: Js.boolean=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?,
      ~attached=?,
      ~basic=?,
      ~circular=?,
      ~className=?,
      ~clearing=?,
      ~color=?,
      ~compact=?,
      ~content=?,
      ~disabled=?,
      ~floated=?,
      ~inverted=?,
      ~loading=?,
      ~padded=?,
      ~piled=?,
      ~raised=?,
      ~secondary=?,
      ~size=?,
      ~stacked=?,
      ~tertiary=?,
      ~textAlign=?,
      ~vertical=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~_as=?fromStringOrReactClass(_as),
        ~attached=?fromBoolOrTopOrBottom(attached),
        ~basic=?fromBool(basic),
        ~className?,
        ~clearing=?fromBool(clearing),
        ~color=?fromColor(color),
        ~compact=?fromBool(compact),
        ~content?,
        ~disabled=?fromBool(disabled),
        ~floated=?fromLeftOrRight(floated),
        ~inverted=?fromBool(inverted),
        ~loading=?fromBool(loading),
        ~padded=?fromBoolOrVery(padded),
        ~piled=?fromBool(piled),
        ~raised=?fromBool(raised),
        ~secondary=?fromBool(secondary),
        ~size=?fromSize(size),
        ~stacked=?fromBool(stacked),
        ~tertiary=?fromBool(tertiary),
        ~textAlign=?fromLeftOrCenterOrRight(textAlign),
        ~vertical=?fromBool(vertical),
        (),
      ),
    children,
  );

module Group = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Segment"]
  external react : ReasonReact.reactClass = "Group";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~compact: Js.boolean=?,
      ~content: ReasonReact.reactElement=?,
      ~horizontal: Js.boolean=?,
      ~piled: Js.boolean=?,
      ~raised: Js.boolean=?,
      ~size: string=?,
      ~stacked: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_as=?,
        ~className=?,
        ~compact=?,
        ~content=?,
        ~horizontal=?,
        ~piled=?,
        ~raised=?,
        ~size=?,
        ~stacked=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~compact=?fromBool(compact),
          ~className?,
          ~content?,
          ~horizontal=?fromBool(horizontal),
          ~piled=?fromBool(piled),
          ~raised=?fromBool(raised),
          ~size=?fromSize(size),
          ~stacked=?fromBool(stacked),
          (),
        ),
      children,
    );
};