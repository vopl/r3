/**
  * @name QInputEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  * @param {Qt.KeyboardModifiers} modifiers
  */
function QInputEvent(type, modifiers){return undefined;};

QInputEvent.prototype = new QEvent();

/**
  * @name modifiers
  * @function
  * @memberOf QInputEvent.prototype
  * @returns {Qt.KeyboardModifiers}
  */
QInputEvent.prototype.modifiers = function(){return new Qt.KeyboardModifiers();};

/**
  * @name setModifiers
  * @function
  * @memberOf QInputEvent.prototype
  * @param {Qt.KeyboardModifiers} amodifiers
  * @returns {undefined}
  */
QInputEvent.prototype.setModifiers = function(amodifiers){return undefined;};

