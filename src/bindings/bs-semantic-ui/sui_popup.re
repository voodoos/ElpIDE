open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Popup";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~_as: js=?,
    ~basic: Js.boolean=?,
    ~className: string=?,
    ~content: ReasonReact.reactElement=?,
    ~flowing: Js.boolean=?,
    ~header: ReasonReact.reactElement=?,
    ~hideOnScroll: Js.boolean=?,
    ~horizontalOffset: int=?,
    ~hoverable: Js.boolean=?,
    ~inverted: Js.boolean=?,
    ~keepInViewPort: Js.boolean=?,
    ~on: array(string)=?,
    ~onClose: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onMount: unit => unit=?,
    ~onOpen: (ReactEventRe.Synthetic.t, Js.t({..})) => unit=?,
    ~onUnmount: unit => unit=?,
    ~position: string=?,
    ~size: string=?,
    /* TODO: style */
    ~trigger: ReasonReact.reactElement=?,
    ~verticalOffset: int=?,
    ~wide: js=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_as=?,
      ~basic=?,
      ~className=?,
      ~content=?,
      ~flowing=?,
      ~header=?,
      ~hideOnScroll=?,
      ~horizontalOffset=?,
      ~hoverable=?,
      ~inverted=?,
      ~keepInViewPort=?,
      ~on=?,
      ~onClose=?,
      ~onMount=?,
      ~onOpen=?,
      ~onUnmount=?,
      ~position=?,
      ~size=?,
      ~trigger=?,
      ~verticalOffset=?,
      ~wide=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~_as=?fromStringOrReactClass(_as),
        ~basic=?fromBool(basic),
        ~className?,
        ~content?,
        ~flowing=?fromBool(flowing),
        ~header?,
        ~hideOnScroll=?fromBool(hideOnScroll),
        ~horizontalOffset?,
        ~hoverable=?fromBool(hoverable),
        ~inverted=?fromBool(inverted),
        ~keepInViewPort=?fromBool(keepInViewPort),
        ~on?, /* TODO: enum for on */
        ~onClose?,
        ~onMount?,
        ~onOpen?,
        ~onUnmount?,
        ~position=?fromPos(position),
        ~size=?fromSizeModal(size),
        ~trigger?,
        ~verticalOffset?,
        ~wide=?fromBoolOrVery(wide),
        (),
      ),
    children,
  );

module Content = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Popup"]
  external react : ReasonReact.reactClass = "Content";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          (),
        ),
      children,
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Popup"]
  external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: js=?,
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as=?fromStringOrReactClass(_as),
          ~className?,
          ~content?,
          (),
        ),
      children,
    );
};