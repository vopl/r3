/**
  * @name QStateMachine_SignalEvent
  * @constructor
  * @extends QEvent
  * @param {QObject} sender
  * @param {Numeric} signalIndex
  * @param {Array} arguments
  */
function QStateMachine_SignalEvent(sender, signalIndex, arguments){return undefined;};

QStateMachine_SignalEvent.prototype = new QEvent();

/**
  * @name arguments
  * @function
  * @memberOf QStateMachine_SignalEvent.prototype
  * @returns {Array}
  */
QStateMachine_SignalEvent.prototype.arguments = function(){return new Array();};

/**
  * @name sender
  * @function
  * @memberOf QStateMachine_SignalEvent.prototype
  * @returns {QObject}
  */
QStateMachine_SignalEvent.prototype.sender = function(){return new QObject();};

/**
  * @name signalIndex
  * @function
  * @memberOf QStateMachine_SignalEvent.prototype
  * @returns {Numeric}
  */
QStateMachine_SignalEvent.prototype.signalIndex = function(){return new Numeric();};

