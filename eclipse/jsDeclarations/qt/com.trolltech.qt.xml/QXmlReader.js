/**
  * @name QXmlReader
  * @constructor
  */
function QXmlReader(){return undefined;};

/**
  * @name DTDHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @returns {QXmlDTDHandler}
  */
QXmlReader.prototype.DTDHandler = function(){return new QXmlDTDHandler();};

/**
  * @name contentHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @returns {QXmlContentHandler}
  */
QXmlReader.prototype.contentHandler = function(){return new QXmlContentHandler();};

/**
  * @name declHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @returns {QXmlDeclHandler}
  */
QXmlReader.prototype.declHandler = function(){return new QXmlDeclHandler();};

/**
  * @name entityResolver
  * @function
  * @memberOf QXmlReader.prototype
  * @returns {QXmlEntityResolver}
  */
QXmlReader.prototype.entityResolver = function(){return new QXmlEntityResolver();};

/**
  * @name errorHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @returns {QXmlErrorHandler}
  */
QXmlReader.prototype.errorHandler = function(){return new QXmlErrorHandler();};

/**
  * @name feature
  * @function
  * @memberOf QXmlReader.prototype
  * @param {String} name
  * @param {Boolean} ok
  * @returns {Boolean}
  */
QXmlReader.prototype.feature = function(name, ok){return new Boolean();};

/**
  * @name hasFeature
  * @function
  * @memberOf QXmlReader.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QXmlReader.prototype.hasFeature = function(name){return new Boolean();};

/**
  * @name hasProperty
  * @function
  * @memberOf QXmlReader.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QXmlReader.prototype.hasProperty = function(name){return new Boolean();};

/**
  * @name lexicalHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @returns {QXmlLexicalHandler}
  */
QXmlReader.prototype.lexicalHandler = function(){return new QXmlLexicalHandler();};

/**
  * @name parse
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlInputSource} input
  * @returns {Boolean}
  */
QXmlReader.prototype.parse = function(input){return new Boolean();};

/**
  * @name property
  * @function
  * @memberOf QXmlReader.prototype
  * @param {String} name
  * @param {Boolean} ok
  * @returns {undefined}
  */
QXmlReader.prototype.property = function(name, ok){return undefined;};

/**
  * @name setContentHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlContentHandler} handler
  * @returns {undefined}
  */
QXmlReader.prototype.setContentHandler = function(handler){return undefined;};

/**
  * @name setDTDHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlDTDHandler} handler
  * @returns {undefined}
  */
QXmlReader.prototype.setDTDHandler = function(handler){return undefined;};

/**
  * @name setDeclHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlDeclHandler} handler
  * @returns {undefined}
  */
QXmlReader.prototype.setDeclHandler = function(handler){return undefined;};

/**
  * @name setEntityResolver
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlEntityResolver} handler
  * @returns {undefined}
  */
QXmlReader.prototype.setEntityResolver = function(handler){return undefined;};

/**
  * @name setErrorHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlErrorHandler} handler
  * @returns {undefined}
  */
QXmlReader.prototype.setErrorHandler = function(handler){return undefined;};

/**
  * @name setFeature
  * @function
  * @memberOf QXmlReader.prototype
  * @param {String} name
  * @param {Boolean} value
  * @returns {undefined}
  */
QXmlReader.prototype.setFeature = function(name, value){return undefined;};

/**
  * @name setLexicalHandler
  * @function
  * @memberOf QXmlReader.prototype
  * @param {QXmlLexicalHandler} handler
  * @returns {undefined}
  */
QXmlReader.prototype.setLexicalHandler = function(handler){return undefined;};

/**
  * @name setProperty
  * @function
  * @memberOf QXmlReader.prototype
  * @param {String} name
  * @param {undefined} value
  * @returns {undefined}
  */
QXmlReader.prototype.setProperty = function(name, value){return undefined;};

