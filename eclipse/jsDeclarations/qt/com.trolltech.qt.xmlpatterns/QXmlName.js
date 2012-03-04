/**
  * @name QXmlName
  * @constructor
  */
function QXmlName(){return undefined;};

/**
  * @name QXmlName^1
  * @constructor
  * @param {QXmlNamePool} namePool
  * @param {String} localName
  * @param {String} namespaceURI
  * @param {String} prefix
  */
function QXmlName(namePool, localName, namespaceURI, prefix){return undefined;};

/**
  * @name fromClarkName
  * @function
  * @memberOf QXmlName
  * @param {String} clarkName
  * @param {QXmlNamePool} namePool
  * @returns {QXmlName}
  */
QXmlName.fromClarkName = function(clarkName, namePool){return new QXmlName();};

/**
  * @name isNCName
  * @function
  * @memberOf QXmlName
  * @param {String} candidate
  * @returns {Boolean}
  */
QXmlName.isNCName = function(candidate){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QXmlName.prototype
  * @returns {Boolean}
  */
QXmlName.prototype.isNull = function(){return new Boolean();};

/**
  * @name localName
  * @function
  * @memberOf QXmlName.prototype
  * @param {QXmlNamePool} query
  * @returns {String}
  */
QXmlName.prototype.localName = function(query){return new String();};

/**
  * @name namespaceUri
  * @function
  * @memberOf QXmlName.prototype
  * @param {QXmlNamePool} query
  * @returns {String}
  */
QXmlName.prototype.namespaceUri = function(query){return new String();};

/**
  * @name operator_equal
  * @function
  * @memberOf QXmlName.prototype
  * @param {QXmlName} other
  * @returns {Boolean}
  */
QXmlName.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name prefix
  * @function
  * @memberOf QXmlName.prototype
  * @param {QXmlNamePool} query
  * @returns {String}
  */
QXmlName.prototype.prefix = function(query){return new String();};

/**
  * @name toClarkName
  * @function
  * @memberOf QXmlName.prototype
  * @param {QXmlNamePool} query
  * @returns {String}
  */
QXmlName.prototype.toClarkName = function(query){return new String();};

