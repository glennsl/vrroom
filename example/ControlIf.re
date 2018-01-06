open Vrroom.Helpers;
open Vrroom.Control;

let showHello = true;

let instance = ReasonReact.statelessComponent("Control.If example");
let make = _children => {
  ...instance,
  render: _self =>
    <div>

      /* Before */
      {
        if (showHello) {
          {"Hello" |> text}
        } else {
          ReasonReact.nullElement
        }
      }

      /* After */
      <If cond=showHello>
          ...(() => "Hello" |> text)
      </If>

    </div>
};
