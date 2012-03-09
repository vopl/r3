/**
  * @name QTimerEvent
  * @constructor
  * @extends QEvent
  * @param {Numeric} timerId
  */
function QTimerEvent(timerId){return undefined;};

QTimerEvent.prototype = new QEvent();

/**
  * @name timerId
  * @function
  * @memberOf QTimerEvent.prototype
  * @returns {Numeric}
  */
QTimerEvent.prototype.timerId = function(){return new Numeric();};

