/**
  * @name QHoverEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  * @param {QPoint} pos
  * @param {QPoint} oldPos
  */
function QHoverEvent(type, pos, oldPos){return undefined;};

QHoverEvent.prototype = new QEvent();

/**
  * @name oldPos
  * @function
  * @memberOf QHoverEvent.prototype
  * @returns {QPoint}
  */
QHoverEvent.prototype.oldPos = function(){return new QPoint();};

/**
  * @name pos
  * @function
  * @memberOf QHoverEvent.prototype
  * @returns {QPoint}
  */
QHoverEvent.prototype.pos = function(){return new QPoint();};

