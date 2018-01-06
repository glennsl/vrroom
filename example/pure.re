open Vrroom.Helpers;

/* Before */
module ItemBefore = {
  let instance = ReasonReact.statelessComponent("Item");
  let make = (~label, _children) => {
    ...instance,
    render: _self =>
      <li> (label |> text) </li>
  }
};

/* After */
module Item = {
  let make = Vrroom.pure((render, ~label) => render(
    <li> (label |> text) </li>
  ));
};

let instance = ReasonReact.statelessComponent("Pure example");
let make = _children => {
  ...instance,

  render: _self =>
    <ul>
      <Item label="apples" />
      <Item label="bananas" />
      <Item label="coconuts" />
    </ul>
};