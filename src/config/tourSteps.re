let first =
  Joyride.(
    [|
      stepStr(
        ".jr-editor",
        {js|Use the editor to write some λ-prolog incantations.|js},
      ),
      stepStr(
        ".jr-build",
        "Then press this button to typecheck and build your code (you can also press ctrl+b or cmd+b).",
      ),
      stepStr(
        ~placement=`top,
        ".jr-query",
        "After a succesful build you can use this panel to query your code. Try 'world A.' for example.",
      ),
      stepStr(
        ~placement=`top,
        ".jr-load",
        "Working on a big project ? Load your files directly from your computer.",
      ),
      stepStr(
        ~placement=`top,
        ".jr-save",
        "Your code is automatically saved to internal storage but you can also download it by clicking this button.",
      ),
      stepStr(
        ~placement=`top,
        ".jr-help",
        {js|Examples and tutorials to learn λ-prolog are available in the help panel !|js},
      ),
    |]
  );

let callback = (onEnd, s) =>
  try (
    switch (s##step##target) {
    | ".jr-build" => Js.log("build")
    | s => ()
    }
  ) {
  | _ => onEnd()
  };