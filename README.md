# vRRoom - Turbo-charged ReasonReact!

A collection of mostly experimental tools and utilities for effective ReasonReact development.

## Installation

Run `npm install --save glennsl/vrroom` and add `vrroom` to `bs-dependencies` in `bsconfig.json`. 

## Usage

If you're not too afraid of polluting your namespace, the most convenient way to use Vrroom is to `open Vrroom` at the
top of the module. Otherwise, to avoid polluting the namespace, using `module V = Vrroom` is recommended.

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

## Documentation

#### type childless = array(nothing)

Used to indicate and enforce a childless component by making it impossible to add children without circumventing the type system, since `nothing` is an abstract type with no way to construct a value.

Example:
```reason
let make = (_:childless) => ...
```

#### let text : string => ReasonReact.reactElement

Alias for `Text.string` and therefore `ReasonReact.stringToElement`.

Example:
```reason
<div> {"Hello!" |> text} </div>
```

#### let nothing : ReasonReact.reactElement

Alias for `ReasonReact.nullElement`.

Example:
```reason
<div> {isAwkward ? nothing : text("Hello!")} </div>
```

#### let nbsp : ReasonReact.reactElement

Insert a `&nbsp;` (actually the unicode equivalent since React escapes HTML entities). Useful to avoid some elements mysteriously disappearing when empty (or more likely containing `nothing`).

Example:
```reason
<div> {isAwkward ? nbsp : text("Hello!")} </div>
```

#### let pure : (((ReasonReact.reactElement, childless) => ReasonReact.component(ReasonReact.stateless ReasonReact.noRetainedProps, ReasonReact.actionless)) => 'a) => 'a

An experimental convenience function for creating a "functional" stateless component.

Example:
```reason
modul Item = {
  let make = pure((render, ~label) => render(
    <li> (label |> text) </li>
  ));
};
```

### module Text

#### let Text.string : string => ReasonReact.reactElement

Alias for `ReasonReact.stringToElement`.

Example:
```reason
<div> {"Hello!" |> Text.string} </div>
```

#### let Text.int : int => ReasonReact.reactElement

Would be an alias for `ReasonReact.intToElement` if it had existed.

Example:
```reason
<div> {42 |> Text.int} </div>
```

#### let Text.float : float => ReasonReact.reactElement

Would be an alias for `ReasonReact.floatToElement` if it had existed.

Example:
```reason
<div> {4.2 |> Text.float} </div>
```

#### let Text.any : _ => ReasonReact.reactElement

Converts anything to a string, then casts it as an element.

Example:
```reason
<div> {["Hello", "brother!"] |> Text.any} </div>
```

### module ClassName

#### let ClassName.join : list(string) => string

Joins a list of strings into a single space-separated string, ignoring empty string.

Example:
```reason
<div className=ClassName.join(["button", "primary"])> ... </div>
```

#### let ClassName.if_ : (bool, string) => string

Returns the given string if condition is true, otherwise an empty string. Most useful in conjunction with thje `join` function.

Example:
```reason
<div className=ClassName.(join(["button", "s-hover" |> if_(isHovered))])> ... </div>
```

#### let ClassName.fromOption : option(string) => string

Returns the contained string if any, otherwise an empty string. Most useful in conjunction with thje `join` function.

Example:
```reason
<div className=ClassName.(join(["button", maybeError |> fromOption]))> ... </div>
```

#### &lt;Fragment&gt; array(ReasonReact.reactElement) &lt;/Fragment&gt;

Binding to the standard [React Fragment](https://reactjs.org/docs/fragments.html) component. Renders its children without a surrounding DOM element.

Example:
```reason
<tr> ... </tr>
<Fragment>
  <tr> ... </tr>
  <tr> ... </tr>
</Fragment>
<tr> ... </tr>
```

#### <Control.Map items=array('a) ?empty=ReasonReact.reactElement> ...('a => ReasonReact.reactElement) </Control.Map>

Renders each item in `items` using the given render function, or if the array is empty, the given `empty` element or `nothing` if oomitted.

Example:
```reason
<Control.Map items=[|"apple", "banana"|] empty=<Item label="-"/> >
  ...(name => <Item label=name />)
</Control.Map>
```

#### <Control.MapList items=list('a) ?empty=ReasonReact.reactElement> ...('a => ReasonReact.reactElement) </Control.MapList>

Renders each item in `items` using the given render function, or if the list is empty, the given `empty` element or `nothing` if oomitted.

Example:
```reason
<Control.MapList items=["apple", "banana"] empty=<Item label="-"/> >
  ...(name => <Item label=name />)
</Control.MapList>
```

#### <Control.If cond=bool> ...(unit => ReasonReact.reactElement) </Control.If>

Renders the element returned by the render function if `cond` is true, otherwise `nothing`.

Example:
```reason
<Control.If cond=showHello>
    ...(() => "Hello" |> text)
</Control.If>
```

#### <Control.IfSome option=option('a)> ...('a => ReasonReact.reactElement) </Control.IfSome>

Calls the render function with the contained item in `option`  if any, and renders the returned element, otherwise `nothing`.

Example:
```reason
<Control.IfSome option=maybeError>
  ...(error => error |> text)
</Control.IfSome>
```