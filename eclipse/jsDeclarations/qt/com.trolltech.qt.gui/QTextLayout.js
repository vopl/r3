/**
  * @name QTextLayout
  * @constructor
  */
function QTextLayout(){return undefined;};

/**
  * @name QTextLayout^1
  * @constructor
  * @param {String} text
  */
function QTextLayout(text){return undefined;};

/**
  * @name QTextLayout^2
  * @constructor
  * @param {String} text
  * @param {QFont} font
  * @param {QPaintDevice} paintdevice
  */
function QTextLayout(text, font, paintdevice){return undefined;};

/**
  * @name QTextLayout^3
  * @constructor
  * @param {QTextBlock} b
  */
function QTextLayout(b){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QTextLayout
  * @name SkipCharacters
  * @see QTextLayout#CursorMode
  * @type Number
  */
QTextLayout.SkipCharacters = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextLayout
  * @name SkipWords
  * @see QTextLayout#CursorMode
  * @type Number
  */
QTextLayout.SkipWords = 0x1;

/**
  * @constructor 
  * @memberOf QTextLayout
  * @name CursorMode
  */
QTextLayout.CursorMode = function(value){;};



/**
  * @name additionalFormats
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Array}
  */
QTextLayout.prototype.additionalFormats = function(){return new Array();};

/**
  * @name beginLayout
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {undefined}
  */
QTextLayout.prototype.beginLayout = function(){return undefined;};

/**
  * @name boundingRect
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {QRectF}
  */
QTextLayout.prototype.boundingRect = function(){return new QRectF();};

/**
  * @name cacheEnabled
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Boolean}
  */
QTextLayout.prototype.cacheEnabled = function(){return new Boolean();};

/**
  * @name clearAdditionalFormats
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {undefined}
  */
QTextLayout.prototype.clearAdditionalFormats = function(){return undefined;};

/**
  * @name clearLayout
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {undefined}
  */
QTextLayout.prototype.clearLayout = function(){return undefined;};

/**
  * @name createLine
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {QTextLine}
  */
QTextLayout.prototype.createLine = function(){return new QTextLine();};

/**
  * @name draw
  * @function
  * @memberOf QTextLayout.prototype
  * @param {QPainter} p
  * @param {QPointF} pos
  * @param {Array} selections
  * @param {QRectF} clip
  * @returns {undefined}
  */
QTextLayout.prototype.draw = function(p, pos, selections, clip){return undefined;};

/**
  * @name drawCursor
  * @function
  * @memberOf QTextLayout.prototype
  * @param {QPainter} p
  * @param {QPointF} pos
  * @param {Numeric} cursorPosition
  * @returns {undefined}
  */
QTextLayout.prototype.drawCursor = function(p, pos, cursorPosition){return undefined;};

/**
  * @name endLayout
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {undefined}
  */
QTextLayout.prototype.endLayout = function(){return undefined;};

/**
  * @name font
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {QFont}
  */
QTextLayout.prototype.font = function(){return new QFont();};

/**
  * @name isValidCursorPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} pos
  * @returns {Boolean}
  */
QTextLayout.prototype.isValidCursorPosition = function(pos){return new Boolean();};

/**
  * @name leftCursorPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} oldPos
  * @returns {Numeric}
  */
QTextLayout.prototype.leftCursorPosition = function(oldPos){return new Numeric();};

/**
  * @name lineAt
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} i
  * @returns {QTextLine}
  */
QTextLayout.prototype.lineAt = function(i){return new QTextLine();};

/**
  * @name lineCount
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Numeric}
  */
QTextLayout.prototype.lineCount = function(){return new Numeric();};

/**
  * @name lineForTextPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} pos
  * @returns {QTextLine}
  */
QTextLayout.prototype.lineForTextPosition = function(pos){return new QTextLine();};

/**
  * @name maximumWidth
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Numeric}
  */
QTextLayout.prototype.maximumWidth = function(){return new Numeric();};

/**
  * @name minimumWidth
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Numeric}
  */
QTextLayout.prototype.minimumWidth = function(){return new Numeric();};

/**
  * @name nextCursorPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} oldPos
  * @param {QTextLayout.CursorMode} mode
  * @returns {Numeric}
  */
QTextLayout.prototype.nextCursorPosition = function(oldPos, mode){return new Numeric();};

/**
  * @name position
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {QPointF}
  */
QTextLayout.prototype.position = function(){return new QPointF();};

/**
  * @name preeditAreaPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Numeric}
  */
QTextLayout.prototype.preeditAreaPosition = function(){return new Numeric();};

/**
  * @name preeditAreaText
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {String}
  */
QTextLayout.prototype.preeditAreaText = function(){return new String();};

/**
  * @name previousCursorPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} oldPos
  * @param {QTextLayout.CursorMode} mode
  * @returns {Numeric}
  */
QTextLayout.prototype.previousCursorPosition = function(oldPos, mode){return new Numeric();};

/**
  * @name rightCursorPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} oldPos
  * @returns {Numeric}
  */
QTextLayout.prototype.rightCursorPosition = function(oldPos){return new Numeric();};

/**
  * @name setAdditionalFormats
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Array} overrides
  * @returns {undefined}
  */
QTextLayout.prototype.setAdditionalFormats = function(overrides){return undefined;};

/**
  * @name setCacheEnabled
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
QTextLayout.prototype.setCacheEnabled = function(enable){return undefined;};

/**
  * @name setFlags
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} flags
  * @returns {undefined}
  */
QTextLayout.prototype.setFlags = function(flags){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QTextLayout.prototype
  * @param {QFont} f
  * @returns {undefined}
  */
QTextLayout.prototype.setFont = function(f){return undefined;};

/**
  * @name setPosition
  * @function
  * @memberOf QTextLayout.prototype
  * @param {QPointF} p
  * @returns {undefined}
  */
QTextLayout.prototype.setPosition = function(p){return undefined;};

/**
  * @name setPreeditArea
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Numeric} position
  * @param {String} text
  * @returns {undefined}
  */
QTextLayout.prototype.setPreeditArea = function(position, text){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QTextLayout.prototype
  * @param {String} string
  * @returns {undefined}
  */
QTextLayout.prototype.setText = function(string){return undefined;};

/**
  * @name setTextOption
  * @function
  * @memberOf QTextLayout.prototype
  * @param {Object} option
  * @returns {undefined}
  */
QTextLayout.prototype.setTextOption = function(option){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {String}
  */
QTextLayout.prototype.text = function(){return new String();};

/**
  * @name textOption
  * @function
  * @memberOf QTextLayout.prototype
  * @returns {Object}
  */
QTextLayout.prototype.textOption = function(){return new Object();};

