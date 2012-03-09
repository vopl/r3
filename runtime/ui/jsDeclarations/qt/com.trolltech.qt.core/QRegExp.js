/**
  * @name QRegExp
  * @constructor
  */
function QRegExp(){return undefined;};

/**
  * @name QRegExp^1
  * @constructor
  * @param {QRegExp} rx
  */
function QRegExp(rx){return undefined;};

/**
  * @name QRegExp^2
  * @constructor
  * @param {String} pattern
  * @param {Qt.CaseSensitivity} cs
  * @param {QRegExp.PatternSyntax} syntax
  */
function QRegExp(pattern, cs, syntax){return undefined;};

/**
  * @name escape
  * @function
  * @memberOf QRegExp
  * @param {String} str
  * @returns {String}
  */
QRegExp.escape = function(str){return new String();};

/**
  * @default 0x0
  * @constant
  * @memberOf QRegExp
  * @name RegExp
  * @see QRegExp#PatternSyntax
  * @type Number
  */
QRegExp.RegExp = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QRegExp
  * @name Wildcard
  * @see QRegExp#PatternSyntax
  * @type Number
  */
QRegExp.Wildcard = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QRegExp
  * @name FixedString
  * @see QRegExp#PatternSyntax
  * @type Number
  */
QRegExp.FixedString = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QRegExp
  * @name RegExp2
  * @see QRegExp#PatternSyntax
  * @type Number
  */
QRegExp.RegExp2 = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QRegExp
  * @name WildcardUnix
  * @see QRegExp#PatternSyntax
  * @type Number
  */
QRegExp.WildcardUnix = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QRegExp
  * @name W3CXmlSchema11
  * @see QRegExp#PatternSyntax
  * @type Number
  */
QRegExp.W3CXmlSchema11 = 0x5;

/**
  * @constructor 
  * @memberOf QRegExp
  * @name PatternSyntax
  */
QRegExp.PatternSyntax = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QRegExp
  * @name CaretAtZero
  * @see QRegExp#CaretMode
  * @type Number
  */
QRegExp.CaretAtZero = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QRegExp
  * @name CaretAtOffset
  * @see QRegExp#CaretMode
  * @type Number
  */
QRegExp.CaretAtOffset = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QRegExp
  * @name CaretWontMatch
  * @see QRegExp#CaretMode
  * @type Number
  */
QRegExp.CaretWontMatch = 0x2;

/**
  * @constructor 
  * @memberOf QRegExp
  * @name CaretMode
  */
QRegExp.CaretMode = function(value){;};



/**
  * @name cap
  * @function
  * @memberOf QRegExp.prototype
  * @param {Numeric} nth
  * @returns {String}
  */
QRegExp.prototype.cap = function(nth){return new String();};

/**
  * @name captureCount
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Numeric}
  */
QRegExp.prototype.captureCount = function(){return new Numeric();};

/**
  * @name capturedTexts
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Array}
  */
QRegExp.prototype.capturedTexts = function(){return new Array();};

/**
  * @name caseSensitivity
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Qt.CaseSensitivity}
  */
QRegExp.prototype.caseSensitivity = function(){return new Qt.CaseSensitivity();};

/**
  * @name errorString
  * @function
  * @memberOf QRegExp.prototype
  * @returns {String}
  */
QRegExp.prototype.errorString = function(){return new String();};

/**
  * @name exactMatch
  * @function
  * @memberOf QRegExp.prototype
  * @param {String} str
  * @returns {Boolean}
  */
QRegExp.prototype.exactMatch = function(str){return new Boolean();};

/**
  * @name indexIn
  * @function
  * @memberOf QRegExp.prototype
  * @param {String} str
  * @param {Numeric} offset
  * @param {QRegExp.CaretMode} caretMode
  * @returns {Numeric}
  */
QRegExp.prototype.indexIn = function(str, offset, caretMode){return new Numeric();};

/**
  * @name isEmpty
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Boolean}
  */
QRegExp.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name isMinimal
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Boolean}
  */
QRegExp.prototype.isMinimal = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Boolean}
  */
QRegExp.prototype.isValid = function(){return new Boolean();};

/**
  * @name lastIndexIn
  * @function
  * @memberOf QRegExp.prototype
  * @param {String} str
  * @param {Numeric} offset
  * @param {QRegExp.CaretMode} caretMode
  * @returns {Numeric}
  */
QRegExp.prototype.lastIndexIn = function(str, offset, caretMode){return new Numeric();};

/**
  * @name matchedLength
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Numeric}
  */
QRegExp.prototype.matchedLength = function(){return new Numeric();};

/**
  * @name numCaptures
  * @function
  * @memberOf QRegExp.prototype
  * @returns {Numeric}
  */
QRegExp.prototype.numCaptures = function(){return new Numeric();};

/**
  * @name operator_equal
  * @function
  * @memberOf QRegExp.prototype
  * @param {QRegExp} rx
  * @returns {Boolean}
  */
QRegExp.prototype.operator_equal = function(rx){return new Boolean();};

/**
  * @name pattern
  * @function
  * @memberOf QRegExp.prototype
  * @returns {String}
  */
QRegExp.prototype.pattern = function(){return new String();};

/**
  * @name patternSyntax
  * @function
  * @memberOf QRegExp.prototype
  * @returns {QRegExp.PatternSyntax}
  */
QRegExp.prototype.patternSyntax = function(){return new QRegExp.PatternSyntax();};

/**
  * @name pos
  * @function
  * @memberOf QRegExp.prototype
  * @param {Numeric} nth
  * @returns {Numeric}
  */
QRegExp.prototype.pos = function(nth){return new Numeric();};

/**
  * @name readFrom
  * @function
  * @memberOf QRegExp.prototype
  * @param {QDataStream} _in
  * @returns {undefined}
  */
QRegExp.prototype.readFrom = function(_in){return undefined;};

/**
  * @name setCaseSensitivity
  * @function
  * @memberOf QRegExp.prototype
  * @param {Qt.CaseSensitivity} cs
  * @returns {undefined}
  */
QRegExp.prototype.setCaseSensitivity = function(cs){return undefined;};

/**
  * @name setMinimal
  * @function
  * @memberOf QRegExp.prototype
  * @param {Boolean} minimal
  * @returns {undefined}
  */
QRegExp.prototype.setMinimal = function(minimal){return undefined;};

/**
  * @name setPattern
  * @function
  * @memberOf QRegExp.prototype
  * @param {String} pattern
  * @returns {undefined}
  */
QRegExp.prototype.setPattern = function(pattern){return undefined;};

/**
  * @name setPatternSyntax
  * @function
  * @memberOf QRegExp.prototype
  * @param {QRegExp.PatternSyntax} syntax
  * @returns {undefined}
  */
QRegExp.prototype.setPatternSyntax = function(syntax){return undefined;};

/**
  * @name swap
  * @function
  * @memberOf QRegExp.prototype
  * @param {QRegExp} other
  * @returns {undefined}
  */
QRegExp.prototype.swap = function(other){return undefined;};

/**
  * @name writeTo
  * @function
  * @memberOf QRegExp.prototype
  * @param {QDataStream} out
  * @returns {undefined}
  */
QRegExp.prototype.writeTo = function(out){return undefined;};

