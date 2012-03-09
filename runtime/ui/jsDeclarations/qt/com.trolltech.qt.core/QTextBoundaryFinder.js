/**
  * @name QTextBoundaryFinder
  * @constructor
  */
function QTextBoundaryFinder(){return undefined;};

/**
  * @name QTextBoundaryFinder^1
  * @constructor
  * @param {QTextBoundaryFinder.BoundaryType} type
  * @param {String} string
  */
function QTextBoundaryFinder(type, string){return undefined;};

/**
  * @name QTextBoundaryFinder^2
  * @constructor
  * @param {QTextBoundaryFinder} other
  */
function QTextBoundaryFinder(other){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name NotAtBoundary
  * @see QTextBoundaryFinder#BoundaryReasons
  * @see QTextBoundaryFinder#BoundaryReason
  * @type Number
  */
QTextBoundaryFinder.NotAtBoundary = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name StartWord
  * @see QTextBoundaryFinder#BoundaryReasons
  * @see QTextBoundaryFinder#BoundaryReason
  * @type Number
  */
QTextBoundaryFinder.StartWord = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name EndWord
  * @see QTextBoundaryFinder#BoundaryReasons
  * @see QTextBoundaryFinder#BoundaryReason
  * @type Number
  */
QTextBoundaryFinder.EndWord = 0x2;

/**
  * @constructor 
  * @memberOf QTextBoundaryFinder
  * @name BoundaryReason
  */
QTextBoundaryFinder.BoundaryReason = function(value){;};

/**
  * @constructor 
  * @memberOf QTextBoundaryFinder
  * @name BoundaryReasons
  */
QTextBoundaryFinder.BoundaryReasons = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name Grapheme
  * @see QTextBoundaryFinder#BoundaryType
  * @type Number
  */
QTextBoundaryFinder.Grapheme = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name Word
  * @see QTextBoundaryFinder#BoundaryType
  * @type Number
  */
QTextBoundaryFinder.Word = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name Line
  * @see QTextBoundaryFinder#BoundaryType
  * @type Number
  */
QTextBoundaryFinder.Line = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextBoundaryFinder
  * @name Sentence
  * @see QTextBoundaryFinder#BoundaryType
  * @type Number
  */
QTextBoundaryFinder.Sentence = 0x3;

/**
  * @constructor 
  * @memberOf QTextBoundaryFinder
  * @name BoundaryType
  */
QTextBoundaryFinder.BoundaryType = function(value){;};



/**
  * @name boundaryReasons
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {QTextBoundaryFinder.BoundaryReasons}
  */
QTextBoundaryFinder.prototype.boundaryReasons = function(){return new QTextBoundaryFinder.BoundaryReasons();};

/**
  * @name isAtBoundary
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {Boolean}
  */
QTextBoundaryFinder.prototype.isAtBoundary = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {Boolean}
  */
QTextBoundaryFinder.prototype.isValid = function(){return new Boolean();};

/**
  * @name position
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {Numeric}
  */
QTextBoundaryFinder.prototype.position = function(){return new Numeric();};

/**
  * @name setPosition
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @param {Numeric} position
  * @returns {undefined}
  */
QTextBoundaryFinder.prototype.setPosition = function(position){return undefined;};

/**
  * @name string
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {String}
  */
QTextBoundaryFinder.prototype.string = function(){return new String();};

/**
  * @name toEnd
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {undefined}
  */
QTextBoundaryFinder.prototype.toEnd = function(){return undefined;};

/**
  * @name toNextBoundary
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {Numeric}
  */
QTextBoundaryFinder.prototype.toNextBoundary = function(){return new Numeric();};

/**
  * @name toPreviousBoundary
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {Numeric}
  */
QTextBoundaryFinder.prototype.toPreviousBoundary = function(){return new Numeric();};

/**
  * @name toStart
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {undefined}
  */
QTextBoundaryFinder.prototype.toStart = function(){return undefined;};

/**
  * @name type
  * @function
  * @memberOf QTextBoundaryFinder.prototype
  * @returns {QTextBoundaryFinder.BoundaryType}
  */
QTextBoundaryFinder.prototype.type = function(){return new QTextBoundaryFinder.BoundaryType();};

