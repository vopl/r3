/**
  * @name QTextFrame
  * @constructor
  * @extends QTextObject
  * @param {QTextDocument} doc
  */
function QTextFrame(doc){return undefined;};

QTextFrame.prototype = new QTextObject();

/**
  * @name begin
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {Object}
  */
QTextFrame.prototype.begin = function(){return new Object();};

/**
  * @name childFrames
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {Array}
  */
QTextFrame.prototype.childFrames = function(){return new Array();};

/**
  * @name end
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {Object}
  */
QTextFrame.prototype.end = function(){return new Object();};

/**
  * @name firstCursorPosition
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {QTextCursor}
  */
QTextFrame.prototype.firstCursorPosition = function(){return new QTextCursor();};

/**
  * @name firstPosition
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {Numeric}
  */
QTextFrame.prototype.firstPosition = function(){return new Numeric();};

/**
  * @name frameFormat
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {QTextFrameFormat}
  */
QTextFrame.prototype.frameFormat = function(){return new QTextFrameFormat();};

/**
  * @name lastCursorPosition
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {QTextCursor}
  */
QTextFrame.prototype.lastCursorPosition = function(){return new QTextCursor();};

/**
  * @name lastPosition
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {Numeric}
  */
QTextFrame.prototype.lastPosition = function(){return new Numeric();};

/**
  * @name parentFrame
  * @function
  * @memberOf QTextFrame.prototype
  * @returns {QTextFrame}
  */
QTextFrame.prototype.parentFrame = function(){return new QTextFrame();};

/**
  * @name setFrameFormat
  * @function
  * @memberOf QTextFrame.prototype
  * @param {QTextFrameFormat} format
  * @returns {undefined}
  */
QTextFrame.prototype.setFrameFormat = function(format){return undefined;};

