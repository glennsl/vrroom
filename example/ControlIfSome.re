open Vrroom.Helpers;
open Vrroom.Control;

let maybeError = Some("oops!");

let instance = ReasonReact.statelessComponent("Control.IfSome example");
let make = _children => {
  ...instance,
  render: _self =>
    <div>

      /* Before */
      {
        switch maybeError {
        | Some(error) => {error |> text}
        | None => ReasonReact.nullElement
        }
      }

      /* After */
      <IfSome option=maybeError>
        ...(error => error |> text)
      </IfSome>

    </div>
};
