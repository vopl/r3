/**
  * @name QWheelEvent
  * @constructor
  * @extends QInputEvent
  * @param {QPoint} pos
  * @param {QPoint} globalPos
  * @param {Numeric} delta
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {QPrinter.Orientation} orient
  */
function QWheelEvent(pos, globalPos, delta, buttons, modifiers, orient){return undefined;};

/**
  * @name QWheelEvent^1
  * @constructor
  * @extends QInputEvent
  * @param {QPoint} pos
  * @param {Numeric} delta
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {QPrinter.Orientation} orient
  */
function QWheelEvent(pos, delta, buttons, modifiers, orient){return undefined;};

QWheelEvent.prototype = new QInputEvent();

/**
  * @name buttons
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {Qt.MouseButtons}
  */
QWheelEvent.prototype.buttons = function(){return new Qt.MouseButtons();};

/**
  * @name delta
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {Numeric}
  */
QWheelEvent.prototype.delta = function(){return new Numeric();};

/**
  * @name globalPos
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {QPoint}
  */
QWheelEvent.prototype.globalPos = function(){return new QPoint();};

/**
  * @name globalX
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {Numeric}
  */
QWheelEvent.prototype.globalX = function(){return new Numeric();};

/**
  * @name globalY
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {Numeric}
  */
QWheelEvent.prototype.globalY = function(){return new Numeric();};

/**
  * @name orientation
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {QPrinter.Orientation}
  */
QWheelEvent.prototype.orientation = function(){return new QPrinter.Orientation();};

/**
  * @name pos
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {QPoint}
  */
QWheelEvent.prototype.pos = function(){return new QPoint();};

/**
  * @name x
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {Numeric}
  */
QWheelEvent.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QWheelEvent.prototype
  * @returns {Numeric}
  */
QWheelEvent.prototype.y = function(){return new Numeric();};

