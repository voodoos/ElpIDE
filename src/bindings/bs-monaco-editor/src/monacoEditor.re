

type monaco;

[@bs.val]
[@bs.scope  ("monaco","editor")]
external create_monaco : (Dom.element, 'a) => unit = "create";
