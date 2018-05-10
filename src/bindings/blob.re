type t;

type blob = t;

type blobOptions;

[@bs.deriving jsConverter]
type endings = [ | `native | `transparent];

[@bs.new] [@bs.module]
external createAux : (array('a), ~options: blobOptions=?, unit) => blob =
  "Blob";

[@bs.send] external isClosed : blob => Js.boolean = "isClosed";

[@bs.send] external size : blob => int = "size";

[@bs.send] external type_ : blob => string = "type";

[@bs.send] external close : (blob, unit) => unit = "close";

[@bs.send] external slice : (blob, int, int) => blob = "slice";

let create = (~options=?, arr) => createAux(arr, ~options?, ());

[@bs.obj]
external makeBlobOptions :
  (~type_: string=?, ~endings: string=?, unit) => blobOptions =
  "";

let makeJsOptionMap = (f, b) => Js.Option.map((. a) => f(a), b);

let fromMime = makeJsOptionMap(Mime.typesToJs);

let fromEndings = makeJsOptionMap(endingsToJs);

let makeOptions = (~type_=?, ~endings=?, ()) =>
  makeBlobOptions(
    ~type_=?fromMime(type_),
    ~endings=?fromEndings(endings),
    (),
  );