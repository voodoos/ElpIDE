open Jr_tools;

type locale = {
  .
  "back": string,
  "close": string,
  "last": string,
  "next": string,
  "skip": string,
};

type step;

[@bs.obj]
/* TODO: beaconComponent */
external makeStep :
  (
    ~disableBeacon: bool=?,
    ~event: string=?,
    ~isFixed: bool=?,
    ~offset: int=?,
    ~placement: string=?,
    ~placementBeacon: string=?,
    ~target: js, /* TARGET */
    ~content: js,
    unit
  ) => /* CONTENT */
  step =
  "";

let step =
    (
      ~disableBeacon=?,
      ~event=?,
      ~isFixed=?,
      ~offset=?,
      ~placement=?,
      ~placementBeacon=?,
      target, /* TARGET */
      content,
    ) =>
  /* CONTENT */
  makeStep(
    ~disableBeacon?,
    ~event=?fromEvt(event),
    ~isFixed?,
    ~offset?,
    ~placement=?fromPlcmt(placement),
    ~placementBeacon=?fromPlcmt(placementBeacon),
    ~target=fromStringOrReactEltAux(target), /* TARGET */
    ~content=fromStringOrReactClassAux(content),
    (),
  );

let stepStr =
    (
      ~disableBeacon=?,
      ~event=?,
      ~isFixed=?,
      ~offset=?,
      ~placement=?,
      ~placementBeacon=?,
      target, /* TARGET */
      content,
    ) =>
  /* CONTENT */
  step(
    ~disableBeacon?,
    ~event?,
    ~isFixed?,
    ~offset?,
    ~placement?,
    ~placementBeacon?,
    `str(target), /* TARGET */
    `str(content),
  );

[@bs.module "react-joyride"]
external react : ReasonReact.reactClass = "default";

[@bs.obj]
/* TODO: beaconComponent */
external makeProps :
  (
    ~callback: Js.t(_) => unit=?,
    ~continuous: bool=?,
    ~debug: bool=?,
    ~disableCloseOnEsc: bool=?,
    ~disableOverlay: bool=?,
    ~disableOverlayClose: bool=?,
    ~disableScrolling: bool=?,
    ~floaterProps: {..}=?, /* TODO: specialize */
    ~hideBackButton: bool=?,
    ~locale: locale=?,
    ~run: bool=?,
    ~scrollOffset: int=?,
    ~scrollToFirstStep: bool=?,
    ~showProgress: bool=?,
    ~showSkipButton: bool=?,
    ~spotlightClicks: bool=?,
    ~spotlightPadding: bool=?,
    ~stepIndex: int=?,
    ~steps: array(step),
    ~styles: {..}=?, /* TODO: specialize */ /* TODO: tooltipComponent */
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~callback=?,
      ~continuous=?,
      ~debug=?,
      ~disableCloseOnEsc=?,
      ~disableOverlay=?,
      ~disableOverlayClose=?,
      ~disableScrolling=?,
      ~floaterProps=?,
      ~hideBackButton=?,
      ~locale=?,
      ~run=?,
      ~scrollOffset=?,
      ~scrollToFirstStep=?,
      ~showProgress=?,
      ~showSkipButton=?,
      ~spotlightClicks=?,
      ~spotlightPadding=?,
      ~stepIndex=?,
      ~styles=?,
      ~steps,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=react,
    ~props=
      makeProps(
        ~callback?,
        ~continuous?,
        ~debug?,
        ~disableCloseOnEsc?,
        ~disableOverlay?,
        ~disableOverlayClose?,
        ~disableScrolling?,
        ~floaterProps?,
        ~hideBackButton?,
        ~locale?,
        ~run?,
        ~scrollOffset?,
        ~scrollToFirstStep?,
        ~showProgress?,
        ~showSkipButton?,
        ~spotlightClicks?,
        ~spotlightPadding?,
        ~stepIndex?,
        ~styles?,
        ~steps,
        (),
      ),
  );