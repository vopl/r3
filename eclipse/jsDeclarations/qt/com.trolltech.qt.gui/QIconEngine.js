/**
  * @name QIconEngine
  * @constructor
  */
function QIconEngine(){return undefined;};

/**
  * @name actualSize
  * @function
  * @memberOf QIconEngine.prototype
  * @param {QSize} size
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {QSize}
  */
QIconEngine.prototype.actualSize = function(size, mode, state){return new QSize();};

/**
  * @name addFile
  * @function
  * @memberOf QIconEngine.prototype
  * @param {String} fileName
  * @param {QSize} size
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {undefined}
  */
QIconEngine.prototype.addFile = function(fileName, size, mode, state){return undefined;};

/**
  * @name addPixmap
  * @function
  * @memberOf QIconEngine.prototype
  * @param {QPixmap} pixmap
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {undefined}
  */
QIconEngine.prototype.addPixmap = function(pixmap, mode, state){return undefined;};

/**
  * @name paint
  * @function
  * @memberOf QIconEngine.prototype
  * @param {QPainter} painter
  * @param {QRect} rect
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {undefined}
  */
QIconEngine.prototype.paint = function(painter, rect, mode, state){return undefined;};

/**
  * @name pixmap
  * @function
  * @memberOf QIconEngine.prototype
  * @param {QSize} size
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {QPixmap}
  */
QIconEngine.prototype.pixmap = function(size, mode, state){return new QPixmap();};

