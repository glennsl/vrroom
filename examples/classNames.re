open Vrroom;

let maybeErrorClass = Some("is-oops");
let isHovered = true;

let instance = ReasonReact.statelessComponent("ClassName example");
let make = (_:childless) => {
  ...instance,
  render: _self =>
    <div>
      {
        let className = 
          ClassName.(join([
            "tooltip",
            "s-hovered" |> if_(isHovered),
            maybeErrorClass |> fromOption
          ]));

        <div className>
          {"Hello world!" |> text}
        </div>
      }

      <div className=ClassName.(join(["tooltip", "s-hovered" |> if_(isHovered)]))>
        {"Hello world!" |> text}
      </div>
    </div>
};
