// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Vrroom = require("../src/Vrroom.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var instance = ReasonReact.statelessComponent("ThreeItems");

function make() {
  return /* record */[
          /* debugName */instance[/* debugName */0],
          /* reactClassInternal */instance[/* reactClassInternal */1],
          /* handedOffState */instance[/* handedOffState */2],
          /* willReceiveProps */instance[/* willReceiveProps */3],
          /* didMount */instance[/* didMount */4],
          /* didUpdate */instance[/* didUpdate */5],
          /* willUnmount */instance[/* willUnmount */6],
          /* willUpdate */instance[/* willUpdate */7],
          /* shouldUpdate */instance[/* shouldUpdate */8],
          /* render */(function () {
              return ReasonReact.element(/* None */0, /* None */0, Vrroom.Fragment[/* make */0](/* array */[
                              React.createElement("li", undefined, Vrroom.Helpers[/* text */1]("Item 1")),
                              React.createElement("li", undefined, Vrroom.Helpers[/* text */1]("Item 2")),
                              React.createElement("li", undefined, Vrroom.Helpers[/* text */1]("Item 3"))
                            ]));
            }),
          /* initialState */instance[/* initialState */10],
          /* retainedProps */instance[/* retainedProps */11],
          /* reducer */instance[/* reducer */12],
          /* subscriptions */instance[/* subscriptions */13],
          /* jsElementWrapped */instance[/* jsElementWrapped */14]
        ];
}

var ThreeItems = /* module */[
  /* instance */instance,
  /* make */make
];

var instance$1 = ReasonReact.statelessComponent("Fragment example");

function make$1() {
  return /* record */[
          /* debugName */instance$1[/* debugName */0],
          /* reactClassInternal */instance$1[/* reactClassInternal */1],
          /* handedOffState */instance$1[/* handedOffState */2],
          /* willReceiveProps */instance$1[/* willReceiveProps */3],
          /* didMount */instance$1[/* didMount */4],
          /* didUpdate */instance$1[/* didUpdate */5],
          /* willUnmount */instance$1[/* willUnmount */6],
          /* willUpdate */instance$1[/* willUpdate */7],
          /* shouldUpdate */instance$1[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("ol", undefined, React.createElement("li", undefined, Vrroom.Helpers[/* text */1]("Item 0")), ReasonReact.element(/* None */0, /* None */0, make(/* array */[])), React.createElement("li", undefined, Vrroom.Helpers[/* text */1]("Item 4")));
            }),
          /* initialState */instance$1[/* initialState */10],
          /* retainedProps */instance$1[/* retainedProps */11],
          /* reducer */instance$1[/* reducer */12],
          /* subscriptions */instance$1[/* subscriptions */13],
          /* jsElementWrapped */instance$1[/* jsElementWrapped */14]
        ];
}

exports.ThreeItems = ThreeItems;
exports.instance = instance$1;
exports.make = make$1;
/* instance Not a pure module */
