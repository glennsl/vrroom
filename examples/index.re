open Vrroom;

module Page = {
  let instance = ReasonReact.statelessComponent("Page");
  let make = (_:childless) => {
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
