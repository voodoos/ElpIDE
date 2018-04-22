

let answer = (argsassignements) => {
    let l = List.map ((argass) => argass##arg ++ argass##ass, Array.to_list(argsassignements));
    Js.log(String.concat("\n", l));
    Log.message(Log.Info, [], String.concat("\n", l));
};


/* The main log component */
let component = ReasonReact.statelessComponent("Querier");

let make = (~messages, _children) => {
  ...component,
  render: _self =>
    /* The log is a basic table */
    <AlwaysBottom className="p-console fullpanel">
      <Log.List level=Log.Info messages />
    </AlwaysBottom>,
};