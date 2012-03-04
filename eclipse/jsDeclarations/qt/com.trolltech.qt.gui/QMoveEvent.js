/**
  * @name QMoveEvent
  * @constructor
  * @extends QEvent
  * @param {QPoint} pos
  * @param {QPoint} oldPos
  */
function QMoveEvent(pos, oldPos){return undefined;};

QMoveEvent.prototype = new QEvent();

/**
  * @name oldPos
  * @function
  * @memberOf QMoveEvent.prototype
  * @returns {QPoint}
  */
QMoveEvent.prototype.oldPos = function(){return new QPoint();};

/**
  * @name pos
  * @function
  * @memberOf QMoveEvent.prototype
  * @returns {QPoint}
  */
QMoveEvent.prototype.pos = function(){return new QPoint();};

