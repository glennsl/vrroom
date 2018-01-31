open Vrroom;

module Item = {
  let instance = ReasonReact.statelessComponent("Item");
  let make = (~label, _children) => {
    ...instance,
    render: _self =>
      <li> (label |> text) </li>
  }
};

let items = [
  "pears",
  "mangos",
  "persimon"
];
let noItems = [];

let instance = ReasonReact.statelessComponent("Control.MapList example");
let make = (_:childless) => {
  ...instance,
  render: _self =>
    <div>

      /* Before */
      <ul>
        {
          items |> List.map(name => <Item label=name />)
                |> Array.of_list
                |> ReasonReact.arrayToElement
        }
      </ul>

      /* After */
      <ul>
        <Control.MapList items>
          ...(name => <Item label=name />)
        </Control.MapList>
      </ul>


      /* Before - Special case empty */
      <ul>
        {
          switch noItems {
          | [] => <Item label="." />
          | items => 
            items |> List.map(name => <Item label=name />)
                  |> Array.of_list
                  |> ReasonReact.arrayToElement
          }  
        }
      </ul>

      /* After - Special case empty*/
      <ul>
        <Control.MapList items=noItems empty=<Item label="-"/> >
          ...(name => <Item label=name />)
        </Control.MapList>
      </ul>

    </div>
};
