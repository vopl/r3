/**
  * @class QAbstractState from package com.trolltech.qt.core
  * @extends QObject
  */
var QAbstractState = {};

QAbstractState.prototype = new QObject();

/**
  * @name machine
  * @function
  * @memberOf QAbstractState.prototype
  * @returns {QStateMachine}
  */
QAbstractState.prototype.machine = function(){return new QStateMachine();};

/**
  * @name parentState
  * @function
  * @memberOf QAbstractState.prototype
  * @returns {QState}
  */
QAbstractState.prototype.parentState = function(){return new QState();};

