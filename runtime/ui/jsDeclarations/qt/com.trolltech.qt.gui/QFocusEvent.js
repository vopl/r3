/**
  * @name QFocusEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  * @param {Qt.FocusReason} reason
  */
function QFocusEvent(type, reason){return undefined;};

QFocusEvent.prototype = new QEvent();

/**
  * @name gotFocus
  * @function
  * @memberOf QFocusEvent.prototype
  * @returns {Boolean}
  */
QFocusEvent.prototype.gotFocus = function(){return new Boolean();};

/**
  * @name lostFocus
  * @function
  * @memberOf QFocusEvent.prototype
  * @returns {Boolean}
  */
QFocusEvent.prototype.lostFocus = function(){return new Boolean();};

/**
  * @name reason
  * @function
  * @memberOf QFocusEvent.prototype
  * @returns {Qt.FocusReason}
  */
QFocusEvent.prototype.reason = function(){return new Qt.FocusReason();};

