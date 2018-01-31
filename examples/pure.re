open Vrroom;

/* Before */
module ItemBefore = {
  let instance = ReasonReact.statelessComponent("Item");
  let make = (~label, _:childless) => {
    ...instance,
    render: _self =>
      <li> (label |> text) </li>
  }
};

/* After */
module Item = {
  let make = pure((render, ~label) => render(
    <li> (label |> text) </li>
  ));
};

let instance = ReasonReact.statelessComponent("Pure example");
let make = (_:childless) => {
  ...instance,

  render: _self =>
    <ul>
      <Item label="apples" />
      <Item label="bananas" />
      <Item label="coconuts" />
    </ul>
};