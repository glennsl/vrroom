module Helpers = {
  let text = ReasonReact.stringToElement;
  let null = ReasonReact.nullElement;
  let nbsp = [%raw "'\u00a0'"];

  module ClassName = {
    let join = items =>
      items |> List.filter((!==)(""))
            |> String.concat(" ");
    
    let if_   = (cond, cls) =>
      cond ? cls : "";

    let fromOption =
      fun | Some(cls) => cls
          | None      => ""
  };
};

module Fragment = {
  [@bs.module "react"] external reactClass : ReasonReact.reactClass = "Fragment";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module Control = {
  module Map = {
    let component = ReasonReact.statelessComponent("Control.Map");
    let make = (~items: array('a),
                ~empty: ReasonReact.reactElement=ReasonReact.nullElement,
                render: 'a => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
        <Fragment>
          {
            switch items {
            | [||] => empty
            | _    => items |> Array.map(render)
                            |> ReasonReact.arrayToElement
            }
          }
        </Fragment>
    };
  };

  module MapList = {
    let component = ReasonReact.statelessComponent("Control.MapList");
    let make = (~items: list('a),
                ~empty: ReasonReact.reactElement=ReasonReact.nullElement,
                render: 'a => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
      <Map items=(items |> Array.of_list) empty>
        ...render
      </Map>
    };
  };

  module If = {
    let component = ReasonReact.statelessComponent("Control.If");
    let make = (~cond: bool,
                render: unit => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
        cond ? render() : ReasonReact.nullElement
    };
  };

  module IfSome = {
    let component = ReasonReact.statelessComponent("Control.IfSome");
    let make = (~option: option('a),
                render: 'a => ReasonReact.reactElement) => {
      ...component,

      render: _self =>
        switch option {
        | Some(value) => render(value)
        | None        => ReasonReact.nullElement
        }
    };
  };
};

let pure = make => {
  let instance = ReasonReact.statelessComponent("Pure");
  make((element, _children:array(unit)) => {
    ...instance,
    render: _self => element
  });
};