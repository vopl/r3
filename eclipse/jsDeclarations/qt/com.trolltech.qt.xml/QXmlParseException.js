/**
  * @name QXmlParseException
  * @constructor
  * @param {String} name
  * @param {Numeric} c
  * @param {Numeric} l
  * @param {String} p
  * @param {String} s
  */
function QXmlParseException(name, c, l, p, s){return undefined;};

/**
  * @name QXmlParseException^1
  * @constructor
  * @param {QXmlParseException} other
  */
function QXmlParseException(other){return undefined;};

/**
  * @name columnNumber
  * @function
  * @memberOf QXmlParseException.prototype
  * @returns {Numeric}
  */
QXmlParseException.prototype.columnNumber = function(){return new Numeric();};

/**
  * @name lineNumber
  * @function
  * @memberOf QXmlParseException.prototype
  * @returns {Numeric}
  */
QXmlParseException.prototype.lineNumber = function(){return new Numeric();};

/**
  * @name message
  * @function
  * @memberOf QXmlParseException.prototype
  * @returns {String}
  */
QXmlParseException.prototype.message = function(){return new String();};

/**
  * @name publicId
  * @function
  * @memberOf QXmlParseException.prototype
  * @returns {String}
  */
QXmlParseException.prototype.publicId = function(){return new String();};

/**
  * @name systemId
  * @function
  * @memberOf QXmlParseException.prototype
  * @returns {String}
  */
QXmlParseException.prototype.systemId = function(){return new String();};

