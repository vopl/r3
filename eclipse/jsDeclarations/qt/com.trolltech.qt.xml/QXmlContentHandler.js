/**
  * @name QXmlContentHandler
  * @constructor
  */
function QXmlContentHandler(){return undefined;};

/**
  * @name characters
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} ch
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.characters = function(ch){return new Boolean();};

/**
  * @name endDocument
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.endDocument = function(){return new Boolean();};

/**
  * @name endElement
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} namespaceURI
  * @param {String} localName
  * @param {String} qName
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.endElement = function(namespaceURI, localName, qName){return new Boolean();};

/**
  * @name endPrefixMapping
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} prefix
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.endPrefixMapping = function(prefix){return new Boolean();};

/**
  * @name errorString
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @returns {String}
  */
QXmlContentHandler.prototype.errorString = function(){return new String();};

/**
  * @name ignorableWhitespace
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} ch
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.ignorableWhitespace = function(ch){return new Boolean();};

/**
  * @name processingInstruction
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} target
  * @param {String} data
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.processingInstruction = function(target, data){return new Boolean();};

/**
  * @name setDocumentLocator
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {QXmlLocator} locator
  * @returns {undefined}
  */
QXmlContentHandler.prototype.setDocumentLocator = function(locator){return undefined;};

/**
  * @name skippedEntity
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.skippedEntity = function(name){return new Boolean();};

/**
  * @name startDocument
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.startDocument = function(){return new Boolean();};

/**
  * @name startElement
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} namespaceURI
  * @param {String} localName
  * @param {String} qName
  * @param {QXmlAttributes} atts
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.startElement = function(namespaceURI, localName, qName, atts){return new Boolean();};

/**
  * @name startPrefixMapping
  * @function
  * @memberOf QXmlContentHandler.prototype
  * @param {String} prefix
  * @param {String} uri
  * @returns {Boolean}
  */
QXmlContentHandler.prototype.startPrefixMapping = function(prefix, uri){return new Boolean();};

