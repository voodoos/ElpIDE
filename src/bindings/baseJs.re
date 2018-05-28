[@bs.val] external setTimeout : (unit => unit, int) => unit = "";

[@bs.val] external require : string => unit = "";

[@bs.val] external requireAs : string => 'a = "require";

external fromFetchBlob : Fetch.blob => Blob.t = "%identity";