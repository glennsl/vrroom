open Vrroom;

let maybeError = Some("oops!");

let instance = ReasonReact.statelessComponent("Control.IfSome example");
let make = (_:childless) => {
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
      <Control.IfSome option=maybeError>
        ...(error => error |> text)
      </Control.IfSome>

    </div>
};
