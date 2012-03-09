/**
  * @name QTextLine
  * @constructor
  */
function QTextLine(){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QTextLine
  * @name Leading
  * @see QTextLine#Edge
  * @type Number
  */
QTextLine.Leading = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextLine
  * @name Trailing
  * @see QTextLine#Edge
  * @type Number
  */
QTextLine.Trailing = 0x1;

/**
  * @constructor 
  * @memberOf QTextLine
  * @name Edge
  */
QTextLine.Edge = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTextLine
  * @name CursorBetweenCharacters
  * @see QTextLine#CursorPosition
  * @type Number
  */
QTextLine.CursorBetweenCharacters = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextLine
  * @name CursorOnCharacter
  * @see QTextLine#CursorPosition
  * @type Number
  */
QTextLine.CursorOnCharacter = 0x1;

/**
  * @constructor 
  * @memberOf QTextLine
  * @name CursorPosition
  */
QTextLine.CursorPosition = function(value){;};



/**
  * @name ascent
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.ascent = function(){return new Numeric();};

/**
  * @name cursorToX
  * @function
  * @memberOf QTextLine.prototype
  * @param {Numeric} cursorPos
  * @param {QTextLine.Edge} edge
  * @returns {Numeric}
  */
QTextLine.prototype.cursorToX = function(cursorPos, edge){return new Numeric();};

/**
  * @name descent
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.descent = function(){return new Numeric();};

/**
  * @name draw
  * @function
  * @memberOf QTextLine.prototype
  * @param {QPainter} p
  * @param {QPointF} point
  * @param {Object} selection
  * @returns {undefined}
  */
QTextLine.prototype.draw = function(p, point, selection){return undefined;};

/**
  * @name height
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.height = function(){return new Numeric();};

/**
  * @name horizontalAdvance
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.horizontalAdvance = function(){return new Numeric();};

/**
  * @name isValid
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Boolean}
  */
QTextLine.prototype.isValid = function(){return new Boolean();};

/**
  * @name leading
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.leading = function(){return new Numeric();};

/**
  * @name leadingIncluded
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Boolean}
  */
QTextLine.prototype.leadingIncluded = function(){return new Boolean();};

/**
  * @name lineNumber
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.lineNumber = function(){return new Numeric();};

/**
  * @name naturalTextRect
  * @function
  * @memberOf QTextLine.prototype
  * @returns {QRectF}
  */
QTextLine.prototype.naturalTextRect = function(){return new QRectF();};

/**
  * @name naturalTextWidth
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.naturalTextWidth = function(){return new Numeric();};

/**
  * @name position
  * @function
  * @memberOf QTextLine.prototype
  * @returns {QPointF}
  */
QTextLine.prototype.position = function(){return new QPointF();};

/**
  * @name rect
  * @function
  * @memberOf QTextLine.prototype
  * @returns {QRectF}
  */
QTextLine.prototype.rect = function(){return new QRectF();};

/**
  * @name setLeadingIncluded
  * @function
  * @memberOf QTextLine.prototype
  * @param {Boolean} included
  * @returns {undefined}
  */
QTextLine.prototype.setLeadingIncluded = function(included){return undefined;};

/**
  * @name setLineWidth
  * @function
  * @memberOf QTextLine.prototype
  * @param {Numeric} width
  * @returns {undefined}
  */
QTextLine.prototype.setLineWidth = function(width){return undefined;};

/**
  * @name setNumColumns
  * @function
  * @memberOf QTextLine.prototype
  * @param {Numeric} columns
  * @returns {undefined}
  */
QTextLine.prototype.setNumColumns = function(columns){return undefined;};

/**
  * @name setPosition
  * @function
  * @memberOf QTextLine.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QTextLine.prototype.setPosition = function(pos){return undefined;};

/**
  * @name textLength
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.textLength = function(){return new Numeric();};

/**
  * @name textStart
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.textStart = function(){return new Numeric();};

/**
  * @name width
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.width = function(){return new Numeric();};

/**
  * @name x
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.x = function(){return new Numeric();};

/**
  * @name xToCursor
  * @function
  * @memberOf QTextLine.prototype
  * @param {Numeric} x
  * @param {QTextLine.CursorPosition} arg__2
  * @returns {Numeric}
  */
QTextLine.prototype.xToCursor = function(x, arg__2){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QTextLine.prototype
  * @returns {Numeric}
  */
QTextLine.prototype.y = function(){return new Numeric();};

