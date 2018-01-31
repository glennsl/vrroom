open Vrroom.Helpers;

module ThreeItems = {
  let instance = ReasonReact.statelessComponent("ThreeItems");
  let make = (_:childless) => {
    ...instance,
    render: _self =>
      <Vrroom.Fragment>
        <li> {"Item 1" |> text} </li>
        <li> {"Item 2" |> text} </li>
        <li> {"Item 3" |> text} </li>
      </Vrroom.Fragment>
  }
};

let instance = ReasonReact.statelessComponent("Fragment example");
let make = (_:childless) => {
  ...instance,
  render: _self =>
    <ol>
      <li> {"Item 0" |> text} </li>
      <ThreeItems />
      <li> {"Item 4" |> text} </li>
    </ol>
};
