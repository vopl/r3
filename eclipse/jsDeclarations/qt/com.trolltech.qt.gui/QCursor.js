/**
  * @name QCursor
  * @constructor
  */
function QCursor(){return undefined;};

/**
  * @name QCursor^1
  * @constructor
  * @param {Qt.CursorShape} shape
  */
function QCursor(shape){return undefined;};

/**
  * @name QCursor^2
  * @constructor
  * @param {QBitmap} bitmap
  * @param {QBitmap} mask
  * @param {Numeric} hotX
  * @param {Numeric} hotY
  */
function QCursor(bitmap, mask, hotX, hotY){return undefined;};

/**
  * @name QCursor^3
  * @constructor
  * @param {QCursor} cursor
  */
function QCursor(cursor){return undefined;};

/**
  * @name QCursor^4
  * @constructor
  * @param {QPixmap} pixmap
  * @param {Numeric} hotX
  * @param {Numeric} hotY
  */
function QCursor(pixmap, hotX, hotY){return undefined;};

/**
  * @name pos
  * @function
  * @memberOf QCursor
  * @returns {QPoint}
  */
QCursor.pos = function(){return new QPoint();};

/**
  * @name setPos
  * @function
  * @memberOf QCursor
  * @param {QPoint} p
  * @returns {undefined}
  */
QCursor.setPos = function(p){return undefined;};

/**
  * @name bitmap
  * @function
  * @memberOf QCursor.prototype
  * @returns {QBitmap}
  */
QCursor.prototype.bitmap = function(){return new QBitmap();};

/**
  * @name hotSpot
  * @function
  * @memberOf QCursor.prototype
  * @returns {QPoint}
  */
QCursor.prototype.hotSpot = function(){return new QPoint();};

/**
  * @name mask
  * @function
  * @memberOf QCursor.prototype
  * @returns {QBitmap}
  */
QCursor.prototype.mask = function(){return new QBitmap();};

/**
  * @name pixmap
  * @function
  * @memberOf QCursor.prototype
  * @returns {QPixmap}
  */
QCursor.prototype.pixmap = function(){return new QPixmap();};

/**
  * @name readFrom
  * @function
  * @memberOf QCursor.prototype
  * @param {QDataStream} inS
  * @returns {undefined}
  */
QCursor.prototype.readFrom = function(inS){return undefined;};

/**
  * @name setShape
  * @function
  * @memberOf QCursor.prototype
  * @param {Qt.CursorShape} newShape
  * @returns {undefined}
  */
QCursor.prototype.setShape = function(newShape){return undefined;};

/**
  * @name shape
  * @function
  * @memberOf QCursor.prototype
  * @returns {Qt.CursorShape}
  */
QCursor.prototype.shape = function(){return new Qt.CursorShape();};

/**
  * @name writeTo
  * @function
  * @memberOf QCursor.prototype
  * @param {QDataStream} outS
  * @returns {undefined}
  */
QCursor.prototype.writeTo = function(outS){return undefined;};

