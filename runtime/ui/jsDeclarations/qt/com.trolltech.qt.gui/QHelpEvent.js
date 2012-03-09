/**
  * @name QHelpEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  * @param {QPoint} pos
  * @param {QPoint} globalPos
  */
function QHelpEvent(type, pos, globalPos){return undefined;};

QHelpEvent.prototype = new QEvent();

/**
  * @name globalPos
  * @function
  * @memberOf QHelpEvent.prototype
  * @returns {QPoint}
  */
QHelpEvent.prototype.globalPos = function(){return new QPoint();};

/**
  * @name globalX
  * @function
  * @memberOf QHelpEvent.prototype
  * @returns {Numeric}
  */
QHelpEvent.prototype.globalX = function(){return new Numeric();};

/**
  * @name globalY
  * @function
  * @memberOf QHelpEvent.prototype
  * @returns {Numeric}
  */
QHelpEvent.prototype.globalY = function(){return new Numeric();};

/**
  * @name pos
  * @function
  * @memberOf QHelpEvent.prototype
  * @returns {QPoint}
  */
QHelpEvent.prototype.pos = function(){return new QPoint();};

/**
  * @name x
  * @function
  * @memberOf QHelpEvent.prototype
  * @returns {Numeric}
  */
QHelpEvent.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QHelpEvent.prototype
  * @returns {Numeric}
  */
QHelpEvent.prototype.y = function(){return new Numeric();};

