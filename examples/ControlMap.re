open Vrroom;

module Item = {
  let instance = ReasonReact.statelessComponent("Item");
  let make = (~label, _children) => {
    ...instance,
    render: _self =>
      <li> (label |> text) </li>
  }
};

let items = [|
  "pears",
  "mangos",
  "persimon"
|];
let noItems = [||];

let instance = ReasonReact.statelessComponent("Control.Map example");
let make = (_:childless) => {
  ...instance,
  render: _self =>
    <div>

      /* Before */
      <ul>
        {
          items |> Array.map(name => <Item label=name />)
                |> ReasonReact.array
        }
      </ul>

      /* After */
      <ul>
        <Control.Map items>
          ...(name => <Item label=name />)
        </Control.Map>
      </ul>


      /* Before - Special case empty */
      <ul>
        {
          switch noItems {
          | [||] => <Item label="." />
          | items => 
            items |> Array.map(name => <Item label=name />)
                  |> ReasonReact.array
          }  
        }
      </ul>

      /* After - Special case empty*/
      <ul>
        <Control.Map items=noItems empty=<Item label="-"/> >
          ...(name => <Item label=name />)
        </Control.Map>
      </ul>

    </div>
};
