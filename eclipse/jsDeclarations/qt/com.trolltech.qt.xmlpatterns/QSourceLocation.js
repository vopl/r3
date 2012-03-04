/**
  * @name QSourceLocation
  * @constructor
  */
function QSourceLocation(){return undefined;};

/**
  * @name QSourceLocation^1
  * @constructor
  * @param {QSourceLocation} other
  */
function QSourceLocation(other){return undefined;};

/**
  * @name QSourceLocation^2
  * @constructor
  * @param {QUrl} uri
  * @param {Numeric} line
  * @param {Numeric} column
  */
function QSourceLocation(uri, line, column){return undefined;};

/**
  * @name column
  * @function
  * @memberOf QSourceLocation.prototype
  * @returns {Numeric}
  */
QSourceLocation.prototype.column = function(){return new Numeric();};

/**
  * @name isNull
  * @function
  * @memberOf QSourceLocation.prototype
  * @returns {Boolean}
  */
QSourceLocation.prototype.isNull = function(){return new Boolean();};

/**
  * @name line
  * @function
  * @memberOf QSourceLocation.prototype
  * @returns {Numeric}
  */
QSourceLocation.prototype.line = function(){return new Numeric();};

/**
  * @name operator_equal
  * @function
  * @memberOf QSourceLocation.prototype
  * @param {QSourceLocation} other
  * @returns {Boolean}
  */
QSourceLocation.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name setColumn
  * @function
  * @memberOf QSourceLocation.prototype
  * @param {Numeric} newColumn
  * @returns {undefined}
  */
QSourceLocation.prototype.setColumn = function(newColumn){return undefined;};

/**
  * @name setLine
  * @function
  * @memberOf QSourceLocation.prototype
  * @param {Numeric} newLine
  * @returns {undefined}
  */
QSourceLocation.prototype.setLine = function(newLine){return undefined;};

/**
  * @name setUri
  * @function
  * @memberOf QSourceLocation.prototype
  * @param {QUrl} newUri
  * @returns {undefined}
  */
QSourceLocation.prototype.setUri = function(newUri){return undefined;};

/**
  * @name uri
  * @function
  * @memberOf QSourceLocation.prototype
  * @returns {QUrl}
  */
QSourceLocation.prototype.uri = function(){return new QUrl();};

