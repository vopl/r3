/**
  * @name QXmlLexicalHandler
  * @constructor
  */
function QXmlLexicalHandler(){return undefined;};

/**
  * @name comment
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @param {String} ch
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.comment = function(ch){return new Boolean();};

/**
  * @name endCDATA
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.endCDATA = function(){return new Boolean();};

/**
  * @name endDTD
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.endDTD = function(){return new Boolean();};

/**
  * @name endEntity
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.endEntity = function(name){return new Boolean();};

/**
  * @name errorString
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @returns {String}
  */
QXmlLexicalHandler.prototype.errorString = function(){return new String();};

/**
  * @name startCDATA
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.startCDATA = function(){return new Boolean();};

/**
  * @name startDTD
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @param {String} name
  * @param {String} publicId
  * @param {String} systemId
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.startDTD = function(name, publicId, systemId){return new Boolean();};

/**
  * @name startEntity
  * @function
  * @memberOf QXmlLexicalHandler.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QXmlLexicalHandler.prototype.startEntity = function(name){return new Boolean();};

