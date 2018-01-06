module Page = {
  let instance = ReasonReact.statelessComponent("Page");
  let make = _children => {
    ...instance,

    render: _self =>
      <div>
        <Pure />
        <Fragment />
        <ControlMap />
        <ControlMapList />
        <ControlIf />
        <ControlIfSome />
      </div>
  }
};

ReactDOMRe.renderToElementWithId(<Page />, "index");
