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
    ~disableBeacon: Js.boolean=?,
    ~event: string=?,
    ~isFixed: Js.boolean=?,
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
    ~disableBeacon=?fromBool(disableBeacon),
    ~event=?fromEvt(event),
    ~isFixed=?fromBool(isFixed),
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
    ~continuous: Js.boolean=?,
    ~debug: Js.boolean=?,
    ~disableCloseOnEsc: Js.boolean=?,
    ~disableOverlay: Js.boolean=?,
    ~disableOverlayClose: Js.boolean=?,
    ~disableScrolling: Js.boolean=?,
    ~floaterProps: {..}=?, /* TODO: specialize */
    ~hideBackButton: Js.boolean=?,
    ~locale: locale=?,
    ~run: Js.boolean=?,
    ~scrollOffset: int=?,
    ~scrollToFirstStep: Js.boolean=?,
    ~showProgress: Js.boolean=?,
    ~showSkipButton: Js.boolean=?,
    ~spotlightClicks: Js.boolean=?,
    ~spotlightPadding: Js.boolean=?,
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
        ~continuous=?fromBool(continuous),
        ~debug=?fromBool(debug),
        ~disableCloseOnEsc=?fromBool(disableCloseOnEsc),
        ~disableOverlay=?fromBool(disableOverlay),
        ~disableOverlayClose=?fromBool(disableOverlayClose),
        ~disableScrolling=?fromBool(disableScrolling),
        ~floaterProps?,
        ~hideBackButton=?fromBool(hideBackButton),
        ~locale?,
        ~run=?fromBool(run),
        ~scrollOffset?,
        ~scrollToFirstStep=?fromBool(scrollToFirstStep),
        ~showProgress=?fromBool(showProgress),
        ~showSkipButton=?fromBool(showSkipButton),
        ~spotlightClicks=?fromBool(spotlightClicks),
        ~spotlightPadding=?fromBool(spotlightPadding),
        ~stepIndex?,
        ~styles?,
        ~steps,
        (),
      ),
  );