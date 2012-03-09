/**
  * @name QPlainTextDocumentLayout
  * @constructor
  * @param {QTextDocument} document
  */
function QPlainTextDocumentLayout(document){return undefined;};

/**
  * @name blockBoundingRect
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @param {QTextBlock} block
  * @returns {QRectF}
  */
QPlainTextDocumentLayout.prototype.blockBoundingRect = function(block){return new QRectF();};

/**
  * @name documentSize
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @returns {QSizeF}
  */
QPlainTextDocumentLayout.prototype.documentSize = function(){return new QSizeF();};

/**
  * @name draw
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @param {QPainter} arg__1
  * @param {Object} arg__2
  * @returns {undefined}
  */
QPlainTextDocumentLayout.prototype.draw = function(arg__1, arg__2){return undefined;};

/**
  * @name ensureBlockLayout
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @param {QTextBlock} block
  * @returns {undefined}
  */
QPlainTextDocumentLayout.prototype.ensureBlockLayout = function(block){return undefined;};

/**
  * @name frameBoundingRect
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @param {QTextFrame} arg__1
  * @returns {QRectF}
  */
QPlainTextDocumentLayout.prototype.frameBoundingRect = function(arg__1){return new QRectF();};

/**
  * @name hitTest
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @param {QPointF} arg__1
  * @param {Qt.HitTestAccuracy} arg__2
  * @returns {Numeric}
  */
QPlainTextDocumentLayout.prototype.hitTest = function(arg__1, arg__2){return new Numeric();};

/**
  * @name pageCount
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @returns {Numeric}
  */
QPlainTextDocumentLayout.prototype.pageCount = function(){return new Numeric();};

/**
  * @name requestUpdate
  * @function
  * @memberOf QPlainTextDocumentLayout.prototype
  * @returns {undefined}
  */
QPlainTextDocumentLayout.prototype.requestUpdate = function(){return undefined;};

/**
  * @name cursorWidth
  * @memberOf QPlainTextDocumentLayout.prototype
  * @type Numeric
  */
QPlainTextDocumentLayout.prototype.cursorWidth = new Numeric();


