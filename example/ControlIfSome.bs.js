// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Curry         = require("bs-platform/lib/js/curry.js");
var React         = require("react");
var ReasonReact   = require("reason-react/src/ReasonReact.js");
var Vrroom$Vrroom = require("../src/Vrroom.bs.js");

var maybeError = /* Some */["oops!"];

var instance = ReasonReact.statelessComponent("Control.IfSome example");

function make() {
  var newrecord = instance.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, maybeError ? Vrroom$Vrroom.Helpers[/* text */0]("oops!") : null, ReasonReact.element(/* None */0, /* None */0, Curry._2(Vrroom$Vrroom.Control[/* IfSome */3][/* make */1], maybeError, (function (error) {
                            return Vrroom$Vrroom.Helpers[/* text */0](error);
                          }))));
    });
  return newrecord;
}

exports.maybeError = maybeError;
exports.instance   = instance;
exports.make       = make;
/* instance Not a pure module */
