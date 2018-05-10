type t('typ);

[@bs.send]
external onData :
  (t('typ), [@bs.as "data"] _, ('typ, 'metadata) => unit) => t('typ) =
  "on";

[@bs.send]
external onEnd : (t('typ), [@bs.as "end"] _, unit => unit) => t('typ) = "on";

[@bs.send]
external onError : (t('typ), [@bs.as "error"] _, Js.Exn.t => unit) => t('typ) =
  "on";

[@bs.send]
external accumulate : (t('typ), Converters.metadata => unit) => t('typ) =
  "accumulate";

[@bs.send] external pause : (t('typ), unit) => t('typ) = "pause";

[@bs.send] external resume : (t('typ), unit) => t('typ) = "resume";