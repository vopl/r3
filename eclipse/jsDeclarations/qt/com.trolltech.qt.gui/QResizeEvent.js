/**
  * @name QResizeEvent
  * @constructor
  * @extends QEvent
  * @param {QSize} size
  * @param {QSize} oldSize
  */
function QResizeEvent(size, oldSize){return undefined;};

QResizeEvent.prototype = new QEvent();

/**
  * @name oldSize
  * @function
  * @memberOf QResizeEvent.prototype
  * @returns {QSize}
  */
QResizeEvent.prototype.oldSize = function(){return new QSize();};

/**
  * @name size
  * @function
  * @memberOf QResizeEvent.prototype
  * @returns {QSize}
  */
QResizeEvent.prototype.size = function(){return new QSize();};

