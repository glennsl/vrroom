// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List        = require("bs-platform/lib/js/list.js");
var $$Array     = require("bs-platform/lib/js/array.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Vrroom      = require("../src/Vrroom.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var instance = ReasonReact.statelessComponent("Item");

function make(label, _) {
  var newrecord = instance.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("li", undefined, Vrroom.Helpers[/* text */1](label));
    });
  return newrecord;
}

var Item = /* module */[
  /* instance */instance,
  /* make */make
];

var items = /* :: */[
  "pears",
  /* :: */[
    "mangos",
    /* :: */[
      "persimon",
      /* [] */0
    ]
  ]
];

var instance$1 = ReasonReact.statelessComponent("Control.MapList example");

function make$1() {
  var newrecord = instance$1.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, React.createElement("ul", undefined, $$Array.of_list(List.map((function (name) {
                                return ReasonReact.element(/* None */0, /* None */0, make(name, /* array */[]));
                              }), items))), React.createElement("ul", undefined, ReasonReact.element(/* None */0, /* None */0, Curry._3(Vrroom.Control[/* MapList */1][/* make */1], items, /* None */0, (function (name) {
                                return ReasonReact.element(/* None */0, /* None */0, make(name, /* array */[]));
                              })))), React.createElement("ul", undefined, ReasonReact.element(/* None */0, /* None */0, make(".", /* array */[]))), React.createElement("ul", undefined, ReasonReact.element(/* None */0, /* None */0, Curry._3(Vrroom.Control[/* MapList */1][/* make */1], /* [] */0, /* Some */[ReasonReact.element(/* None */0, /* None */0, make("-", /* array */[]))], (function (name) {
                                return ReasonReact.element(/* None */0, /* None */0, make(name, /* array */[]));
                              })))));
    });
  return newrecord;
}

var noItems = /* [] */0;

exports.Item     = Item;
exports.items    = items;
exports.noItems  = noItems;
exports.instance = instance$1;
exports.make     = make$1;
/* instance Not a pure module */
