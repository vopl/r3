/**
  * @name QStateMachine_WrappedEvent
  * @constructor
  * @extends QEvent
  * @param {QObject} object
  * @param {QEvent} event
  */
function QStateMachine_WrappedEvent(object, event){return undefined;};

QStateMachine_WrappedEvent.prototype = new QEvent();

/**
  * @name event
  * @function
  * @memberOf QStateMachine_WrappedEvent.prototype
  * @returns {QEvent}
  */
QStateMachine_WrappedEvent.prototype.event = function(){return new QEvent();};

/**
  * @name object
  * @function
  * @memberOf QStateMachine_WrappedEvent.prototype
  * @returns {QObject}
  */
QStateMachine_WrappedEvent.prototype.object = function(){return new QObject();};

