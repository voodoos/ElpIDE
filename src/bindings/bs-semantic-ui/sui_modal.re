open Sui_tools;

[@bs.module "semantic-ui-react"]
external react : ReasonReact.reactClass = "Modal";

/* Using BS Special Creation Function help us with optionnal properties */
/* See https://khoanguyen.me/writing-reason-react-bindings-the-right-way */
[@bs.obj]
external makeProps :
  (
    ~actions: array(ReasonReact.reactElement)=?,
    ~as_: string=? /* TODO: actions */, /* TODO: Can also be a function ! */
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
    ~open_: Js.boolean=?,
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
      ~as_=?,
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
      ~open_=?,
      ~size=?,
      ~trigger=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~actions?,
        ~as_?,
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
        ~open_=?fromBool(open_),
        ~size=?fromSizeModal(size),
        ~trigger?,
        (),
      ),
    children,
  );

module Actions = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Modal"]
  external react : ReasonReact.reactClass = "Actions";
  [@bs.obj]
  external makeProps :
    (
      ~actions: array(ReasonReact.reactElement)=?,
      ~as_: string=?, /* TODO: Can also be a function ! */
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
        ~as_=?,
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
          ~as_?,
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
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      ~image: Js.boolean=?,
      ~scrolling: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (~as_=?, ~className=?, ~content=?, ~image=?, ~scrolling=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=
        makeProps(
          ~as_?,
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
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~as_?, ~className?, ~content?, ()),
      children,
    );
};

module Header = {
  [@bs.module "semantic-ui-react"] [@bs.scope "Modal"]
  external react : ReasonReact.reactClass = "Header";
  [@bs.obj]
  external makeProps :
    (
      ~as_: string=?, /* TODO: Can also be a function ! */
      ~className: string=?,
      ~content: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make = (~as_=?, ~className=?, ~content=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=react,
      ~props=makeProps(~as_?, ~className?, ~content?, ()),
      children,
    );
};