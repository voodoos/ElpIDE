let first =
  Joyride.(
    [|
      stepStr(
        ".jr-editor",
        {js|Use the editor to write some λ-prolog incantations.|js},
      ),
      stepStr(
        ".jr-build",
        "Check and build your code (you can also press ctrl+b or cmd+b).",
      ),
      stepStr(
        ~placement=`top,
        ".jr-query",
        "If the build is succesful you can use this panel to query  your code. Try 'world A.' for example.",
      ),
    |]
  );

let callback = s =>
  try (
    switch (s##step##target) {
    | ".jr-build" => Js.log("build")
    | s => Js.log(s)
    }
  ) {
  | _ => Js.log("No more step")
  };