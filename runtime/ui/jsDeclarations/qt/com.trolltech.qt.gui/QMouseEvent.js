/**
  * @name QMouseEvent
  * @constructor
  * @extends QInputEvent
  * @param {QApplication.Type} type
  * @param {QPoint} pos
  * @param {Qt.MouseButton} button
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  */
function QMouseEvent(type, pos, button, buttons, modifiers){return undefined;};

/**
  * @name QMouseEvent^1
  * @constructor
  * @extends QInputEvent
  * @param {QApplication.Type} type
  * @param {QPoint} pos
  * @param {QPoint} globalPos
  * @param {Qt.MouseButton} button
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  */
function QMouseEvent(type, pos, globalPos, button, buttons, modifiers){return undefined;};

QMouseEvent.prototype = new QInputEvent();

/**
  * @name createExtendedMouseEvent
  * @function
  * @memberOf QMouseEvent
  * @param {QApplication.Type} type
  * @param {QPointF} pos
  * @param {QPoint} globalPos
  * @param {Qt.MouseButton} button
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  * @returns {QMouseEvent}
  */
QMouseEvent.createExtendedMouseEvent = function(type, pos, globalPos, button, buttons, modifiers){return new QMouseEvent();};

/**
  * @name button
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Qt.MouseButton}
  */
QMouseEvent.prototype.button = function(){return new Qt.MouseButton();};

/**
  * @name buttons
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Qt.MouseButtons}
  */
QMouseEvent.prototype.buttons = function(){return new Qt.MouseButtons();};

/**
  * @name globalPos
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {QPoint}
  */
QMouseEvent.prototype.globalPos = function(){return new QPoint();};

/**
  * @name globalX
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Numeric}
  */
QMouseEvent.prototype.globalX = function(){return new Numeric();};

/**
  * @name globalY
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Numeric}
  */
QMouseEvent.prototype.globalY = function(){return new Numeric();};

/**
  * @name hasExtendedInfo
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Boolean}
  */
QMouseEvent.prototype.hasExtendedInfo = function(){return new Boolean();};

/**
  * @name pos
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {QPoint}
  */
QMouseEvent.prototype.pos = function(){return new QPoint();};

/**
  * @name posF
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {QPointF}
  */
QMouseEvent.prototype.posF = function(){return new QPointF();};

/**
  * @name x
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Numeric}
  */
QMouseEvent.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QMouseEvent.prototype
  * @returns {Numeric}
  */
QMouseEvent.prototype.y = function(){return new Numeric();};

