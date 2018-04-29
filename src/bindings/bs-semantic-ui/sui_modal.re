open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Modal";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~actions: array(ReasonReact.reactElement)=?,
    ~_as: string=? /* TODO: actions */, /* TODO: Can also be a function ! */
    ~basic: Js.boolean=?,
    ~className: string=?,
    /* TODO: closeIcon */
    ~closeOnDimmerClick: Js.boolean=?,
    ~closeOnDocumentClick: Js.boolean=?,
    ~content: ReasonReact.reactElement=?,
    ~dimmer: js=?, /* bool or inverted or blurring */
    ~eventPool: string=?,
    ~header: ReasonReact.reactElement=?,
    /* TODO: mountNode */
    ~onActionClick: (ReactEventRe.Mouse.t, Js.t(Js.Types.obj_val)) => unit=?,
    ~onClose: (ReactEventRe.Synthetic.t, Js.t(Js.Types.obj_val)) => unit=?,
    ~onMount: unit => unit=?,
    ~onOpen: (ReactEventRe.Synthetic.t, Js.t(Js.Types.obj_val)) => unit=?,
    ~onUnmount: unit => unit=?,
    ~_open: Js.boolean=?,
    ~size: string=?, /* fullscreen large mini small tiny */
    /* TODO: style */
    ~trigger: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~actions=?,
      ~_as=?,
      ~basic=?,
      ~className=?,
      ~closeOnDimmerClick=?,
      ~closeOnDocumentClick=?,
      ~content=?,
      ~dimmer=?,
      ~eventPool=?,
      ~header=?,
      ~onActionClick=?,
      ~onClose=?,
      ~onMount=?,
      ~onOpen=?,
      ~onUnmount=?,
      ~_open=?,
      ~size=?,
      ~trigger=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~actions?,
        ~_as?,
        ~basic=?fromBool(basic),
        ~className?,
        ~closeOnDimmerClick=?fromBool(closeOnDimmerClick),
        ~closeOnDocumentClick=?fromBool(closeOnDocumentClick),
        ~content?,
        ~dimmer=?fromBoolOrInvertedOrBlurring(dimmer),
        ~eventPool?,
        ~header?,
        ~onActionClick?,
        ~onClose?,
        ~onMount?,
        ~onOpen?,
        ~onUnmount?,
        ~_open=?fromBool(_open),
        ~size=?fromSizeModal(size),
        ~trigger?,
        (),
      ),
    children
  );

module Actions = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Modal"]
  external react : ReasonReact.reactClass = "Actions";
  [@bs.obj]
  external makeProps :
    (
      ~actions: array(ReasonReact.reactElement)=?,
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~onActionClick: (ReactEventRe.Mouse.t, Js.t(Js.Types.obj_val)) => unit=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~actions=?,
        ~_as=?,
        ~className=?,
        ~content=?,
        ~onActionClick=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~actions?,
          ~_as?,
          ~className?,
          ~content?,
          ~onActionClick?,
          (),
        ),
      children,
    );
};

module Content = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Modal"]
  external react : ReasonReact.reactClass = "Content";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~image: Js.boolean=?,
      ~scrolling: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (~_as=?, ~className=?, ~content=?, ~image=?, ~scrolling=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~_as?,
          ~className?,
          ~content?,
          ~image=?fromBool(image),
          ~scrolling=?fromBool(scrolling),
          (),
        ),
      children,
    );
};

module Description = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Modal"]
  external react : ReasonReact.reactClass = "Description";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as?, ~className?, ~content?, ()),
      children,
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Modal"]
  external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~_as: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~_as=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~_as?, ~className?, ~content?, ()),
      children,
    );
};