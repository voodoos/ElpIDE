open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Segment";

[@bs.obj]
external makeProps :
  (
    ~_as: js=?,
    ~attached: js=?,
    ~basic: bool=?,
    ~circular: bool=?,
    ~className: string=?,
    ~clearing: bool=?,
    ~color: string=?,
    ~compact: bool=?,
    ~content: ReasonReact.reactElement=?,
    ~disabled: bool=?,
    ~floated: string=?,
    ~inverted: bool=?,
    ~loading: bool=?,
    ~padded: js=?,
    ~piled: bool=?,
    ~raised: bool=?,
    ~secondary: bool=?,
    ~size: string=?,
    ~stacked: bool=?,
    ~tertiary: bool=?,
    ~textAlign: string=?,
    ~vertical: bool=?,
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
        ~basic?,
        ~circular?,
        ~className?,
        ~clearing?,
        ~color=?fromColor(color),
        ~compact?,
        ~content?,
        ~disabled?,
        ~floated=?fromLeftOrRight(floated),
        ~inverted?,
        ~loading?,
        ~padded=?fromBoolOrVery(padded),
        ~piled?,
        ~raised?,
        ~secondary?,
        ~size=?fromSize(size),
        ~stacked?,
        ~tertiary?,
        ~textAlign=?fromLeftOrCenterOrRight(textAlign),
        ~vertical?,
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
      ~compact: bool=?,
      ~content: ReasonReact.reactElement=?,
      ~horizontal: bool=?,
      ~piled: bool=?,
      ~raised: bool=?,
      ~size: string=?,
      ~stacked: bool=?,
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
          ~compact?,
          ~className?,
          ~content?,
          ~horizontal?,
          ~piled?,
          ~raised?,
          ~size=?fromSize(size),
          ~stacked?,
          (),
        ),
      children,
    );
};