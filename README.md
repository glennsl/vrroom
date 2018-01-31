# vRRoom - Turbo-charged ReasonReact!

A collection of mostly experimental tools and utilities for effective ReasonReact development.

## Installation

Run `npm install --save glennsl/vrroom` and add `vrroom` to `bs-dependencies` in `bsconfig.json`. 

## Examples

#### Control.Map
```reason
/* Without Control.Map */
{
  switch noItems {
  | [||] => <Item label="." />
  | items => 
    items |> Array.map(name => <Item label=name />)
          |> ReasonReact.arrayToElement
  }  
}

/* With Control.Map */
<Control.Map items=noItems empty=<Item label="-"/> >
  ...(name => <Item label=name />)
</Control.Map>
```

#### Control.IfSome
```reason
/* Without Control.IfSome */
{
  switch maybeError {
  | Some(error) => error |> text
  | None        => nothing
  }
}

/* With Control.IfSome */
<Control.IfSome option=maybeError>
  ...(error => error |> text)
</Control.IfSome>
```

#### pure
```reason
/* Without pure */
module ItemBefore = {
  let instance = ReasonReact.statelessComponent("Item");
  let make = (~label, _children) => {
    ...instance,
    render: _self =>
      <li> (label |> text) </li>
  }
};

/* With pure */
module Item = {
  let make = pure((render, ~label) => render(
    <li> (label |> text) </li>
  ));
};
```

See more examples in [the examples folder](https://github.com/glennsl/vrroom/tree/master/examples)
