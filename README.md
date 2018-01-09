# vRRoom - Turbo-charged ReasonReact!

A collection of mostly experimental tools and utilities for effective ReasonReact development.

## Installation

Run `npm install --save glennsl/vrroom` and add `vrroom` to `bs-dependencies` in `bsconfig.json`. 

## Examples

#### Control.Map
```reason
/* Without Control.Map */
<ul>
  {
    switch noItems {
    | [||] => <Item label="." />
    | items => 
      items |> Array.map(name => <Item label=name />)
            |> ReasonReact.arrayToElement
    }  
  }
</ul>

/* With Control.Map */
<ul>
  <Map items=noItems empty=<Item label="-"/> >
    ...(name => <Item label=name />)
  </Map>
</ul>
```

#### Control.IfSome
```reason
/* Without Control.IfSome */
{
  switch maybeError {
  | Some(error) => {error |> text}
  | None => ReasonReact.nullElement
  }
}

/* With Control.IfSome */
<IfSome option=maybeError>
  ...(error => error |> text)
</IfSome>
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
  let make = Vrroom.pure((render, ~label) => render(
    <li> (label |> text) </li>
  ));
};
```

See more examples in [the examples folder](https://github.com/glennsl/vrroom/tree/master/examples)