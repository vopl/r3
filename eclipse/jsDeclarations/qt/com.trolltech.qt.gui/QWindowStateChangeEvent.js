/**
  * @name QWindowStateChangeEvent
  * @constructor
  * @extends QEvent
  * @param {Qt.WindowStates} aOldState
  */
function QWindowStateChangeEvent(aOldState){return undefined;};

/**
  * @name QWindowStateChangeEvent^1
  * @constructor
  * @extends QEvent
  * @param {Qt.WindowStates} aOldState
  * @param {Boolean} isOverride
  */
function QWindowStateChangeEvent(aOldState, isOverride){return undefined;};

QWindowStateChangeEvent.prototype = new QEvent();

/**
  * @name isOverride
  * @function
  * @memberOf QWindowStateChangeEvent.prototype
  * @returns {Boolean}
  */
QWindowStateChangeEvent.prototype.isOverride = function(){return new Boolean();};

/**
  * @name oldState
  * @function
  * @memberOf QWindowStateChangeEvent.prototype
  * @returns {Qt.WindowStates}
  */
QWindowStateChangeEvent.prototype.oldState = function(){return new Qt.WindowStates();};

