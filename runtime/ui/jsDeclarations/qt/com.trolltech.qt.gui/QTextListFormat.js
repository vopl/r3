/**
  * @name QTextListFormat
  * @constructor
  * @extends QTextFormat
  */
function QTextListFormat(){return undefined;};

QTextListFormat.prototype = new QTextFormat();

/**
  * @default -8
  * @constant
  * @memberOf QTextListFormat
  * @name ListUpperRoman
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListUpperRoman = 0xfffffff8;

/**
  * @default -7
  * @constant
  * @memberOf QTextListFormat
  * @name ListLowerRoman
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListLowerRoman = 0xfffffff9;

/**
  * @default -6
  * @constant
  * @memberOf QTextListFormat
  * @name ListUpperAlpha
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListUpperAlpha = 0xfffffffa;

/**
  * @default -5
  * @constant
  * @memberOf QTextListFormat
  * @name ListLowerAlpha
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListLowerAlpha = 0xfffffffb;

/**
  * @default -4
  * @constant
  * @memberOf QTextListFormat
  * @name ListDecimal
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListDecimal = 0xfffffffc;

/**
  * @default -3
  * @constant
  * @memberOf QTextListFormat
  * @name ListSquare
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListSquare = 0xfffffffd;

/**
  * @default -2
  * @constant
  * @memberOf QTextListFormat
  * @name ListCircle
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListCircle = 0xfffffffe;

/**
  * @default -1
  * @constant
  * @memberOf QTextListFormat
  * @name ListDisc
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListDisc = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf QTextListFormat
  * @name ListStyleUndefined
  * @see QTextListFormat#Style
  * @type Number
  */
QTextListFormat.ListStyleUndefined = 0x0;

/**
  * @constructor 
  * @memberOf QTextListFormat
  * @name Style
  */
QTextListFormat.Style = function(value){;};



/**
  * @name indent
  * @function
  * @memberOf QTextListFormat.prototype
  * @returns {Numeric}
  */
QTextListFormat.prototype.indent = function(){return new Numeric();};

/**
  * @name numberPrefix
  * @function
  * @memberOf QTextListFormat.prototype
  * @returns {String}
  */
QTextListFormat.prototype.numberPrefix = function(){return new String();};

/**
  * @name numberSuffix
  * @function
  * @memberOf QTextListFormat.prototype
  * @returns {String}
  */
QTextListFormat.prototype.numberSuffix = function(){return new String();};

/**
  * @name setIndent
  * @function
  * @memberOf QTextListFormat.prototype
  * @param {Numeric} indent
  * @returns {undefined}
  */
QTextListFormat.prototype.setIndent = function(indent){return undefined;};

/**
  * @name setNumberPrefix
  * @function
  * @memberOf QTextListFormat.prototype
  * @param {String} numberPrefix
  * @returns {undefined}
  */
QTextListFormat.prototype.setNumberPrefix = function(numberPrefix){return undefined;};

/**
  * @name setNumberSuffix
  * @function
  * @memberOf QTextListFormat.prototype
  * @param {String} numberSuffix
  * @returns {undefined}
  */
QTextListFormat.prototype.setNumberSuffix = function(numberSuffix){return undefined;};

/**
  * @name setStyle
  * @function
  * @memberOf QTextListFormat.prototype
  * @param {QTextListFormat.Style} style
  * @returns {undefined}
  */
QTextListFormat.prototype.setStyle = function(style){return undefined;};

/**
  * @name style
  * @function
  * @memberOf QTextListFormat.prototype
  * @returns {QTextListFormat.Style}
  */
QTextListFormat.prototype.style = function(){return new QTextListFormat.Style();};

