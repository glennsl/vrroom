open Vrroom;

let showHello = true;

let instance = ReasonReact.statelessComponent("Control.If example");
let make = (_:childless) => {
  ...instance,
  render: _self =>
    <div>

      /* Before */
      {
        if (showHello) {
          ReasonReact.string("Hello")
        } else {
          ReasonReact.null
        }
      }

      /* After */
      <Control.If cond=showHello>
          ...(() => "Hello" |> text)
      </Control.If>

    </div>
};
