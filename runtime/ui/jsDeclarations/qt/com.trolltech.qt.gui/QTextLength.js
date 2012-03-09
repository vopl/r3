/**
  * @name QTextLength
  * @constructor
  */
function QTextLength(){return undefined;};

/**
  * @name QTextLength^1
  * @constructor
  * @param {QApplication.Type} type
  * @param {Numeric} value
  */
function QTextLength(type, value){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QTextLength
  * @name VariableLength
  * @see QTextLength#Type
  * @type Number
  */
QTextLength.VariableLength = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextLength
  * @name FixedLength
  * @see QTextLength#Type
  * @type Number
  */
QTextLength.FixedLength = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextLength
  * @name PercentageLength
  * @see QTextLength#Type
  * @type Number
  */
QTextLength.PercentageLength = 0x2;

/**
  * @constructor 
  * @memberOf QTextLength
  * @name Type
  */
QTextLength.Type = function(value){;};



/**
  * @name operator_equal
  * @function
  * @memberOf QTextLength.prototype
  * @param {QTextLength} other
  * @returns {Boolean}
  */
QTextLength.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name rawValue
  * @function
  * @memberOf QTextLength.prototype
  * @returns {Numeric}
  */
QTextLength.prototype.rawValue = function(){return new Numeric();};

/**
  * @name readFrom
  * @function
  * @memberOf QTextLength.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QTextLength.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name type
  * @function
  * @memberOf QTextLength.prototype
  * @returns {QApplication.Type}
  */
QTextLength.prototype.type = function(){return new QApplication.Type();};

/**
  * @name value
  * @function
  * @memberOf QTextLength.prototype
  * @param {Numeric} maximumLength
  * @returns {Numeric}
  */
QTextLength.prototype.value = function(maximumLength){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QTextLength.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QTextLength.prototype.writeTo = function(arg__1){return undefined;};

