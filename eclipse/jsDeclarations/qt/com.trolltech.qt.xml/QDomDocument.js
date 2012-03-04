/**
  * @name QDomDocument
  * @constructor
  * @extends QDomNode
  */
function QDomDocument(){return undefined;};

/**
  * @name QDomDocument^1
  * @constructor
  * @extends QDomNode
  * @param {QDomDocument} x
  */
function QDomDocument(x){return undefined;};

/**
  * @name QDomDocument^2
  * @constructor
  * @extends QDomNode
  * @param {QDomDocumentType} doctype
  */
function QDomDocument(doctype){return undefined;};

/**
  * @name QDomDocument^3
  * @constructor
  * @extends QDomNode
  * @param {String} name
  */
function QDomDocument(name){return undefined;};

QDomDocument.prototype = new QDomNode();

/**
  * @name createAttribute
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} name
  * @returns {QDomAttr}
  */
QDomDocument.prototype.createAttribute = function(name){return new QDomAttr();};

/**
  * @name createAttributeNS
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} nsURI
  * @param {String} qName
  * @returns {QDomAttr}
  */
QDomDocument.prototype.createAttributeNS = function(nsURI, qName){return new QDomAttr();};

/**
  * @name createCDATASection
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} data
  * @returns {QDomCDATASection}
  */
QDomDocument.prototype.createCDATASection = function(data){return new QDomCDATASection();};

/**
  * @name createComment
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} data
  * @returns {QDomComment}
  */
QDomDocument.prototype.createComment = function(data){return new QDomComment();};

/**
  * @name createDocumentFragment
  * @function
  * @memberOf QDomDocument.prototype
  * @returns {QDomDocumentFragment}
  */
QDomDocument.prototype.createDocumentFragment = function(){return new QDomDocumentFragment();};

/**
  * @name createElement
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} tagName
  * @returns {QDomElement}
  */
QDomDocument.prototype.createElement = function(tagName){return new QDomElement();};

/**
  * @name createElementNS
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} nsURI
  * @param {String} qName
  * @returns {QDomElement}
  */
QDomDocument.prototype.createElementNS = function(nsURI, qName){return new QDomElement();};

/**
  * @name createEntityReference
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} name
  * @returns {QDomEntityReference}
  */
QDomDocument.prototype.createEntityReference = function(name){return new QDomEntityReference();};

/**
  * @name createProcessingInstruction
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} target
  * @param {String} data
  * @returns {QDomProcessingInstruction}
  */
QDomDocument.prototype.createProcessingInstruction = function(target, data){return new QDomProcessingInstruction();};

/**
  * @name createTextNode
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} data
  * @returns {QDomText}
  */
QDomDocument.prototype.createTextNode = function(data){return new QDomText();};

/**
  * @name doctype
  * @function
  * @memberOf QDomDocument.prototype
  * @returns {QDomDocumentType}
  */
QDomDocument.prototype.doctype = function(){return new QDomDocumentType();};

/**
  * @name documentElement
  * @function
  * @memberOf QDomDocument.prototype
  * @returns {QDomElement}
  */
QDomDocument.prototype.documentElement = function(){return new QDomElement();};

/**
  * @name elementById
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} elementId
  * @returns {QDomElement}
  */
QDomDocument.prototype.elementById = function(elementId){return new QDomElement();};

/**
  * @name elementsByTagName
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} tagname
  * @returns {QDomNodeList}
  */
QDomDocument.prototype.elementsByTagName = function(tagname){return new QDomNodeList();};

/**
  * @name elementsByTagNameNS
  * @function
  * @memberOf QDomDocument.prototype
  * @param {String} nsURI
  * @param {String} localName
  * @returns {QDomNodeList}
  */
QDomDocument.prototype.elementsByTagNameNS = function(nsURI, localName){return new QDomNodeList();};

/**
  * @name implementation
  * @function
  * @memberOf QDomDocument.prototype
  * @returns {QDomImplementation}
  */
QDomDocument.prototype.implementation = function(){return new QDomImplementation();};

/**
  * @name importNode
  * @function
  * @memberOf QDomDocument.prototype
  * @param {QDomNode} importedNode
  * @param {Boolean} deep
  * @returns {QDomNode}
  */
QDomDocument.prototype.importNode = function(importedNode, deep){return new QDomNode();};

/**
  * @name setContent
  * @function
  * @memberOf QDomDocument.prototype
  * @param {QIODevice} dev
  * @param {String} errorMsg
  * @param {Numeric} errorLine
  * @param {Numeric} errorColumn
  * @returns {Boolean}
  */
QDomDocument.prototype.setContent = function(dev, errorMsg, errorLine, errorColumn){return new Boolean();};

/**
  * @name toByteArray
  * @function
  * @memberOf QDomDocument.prototype
  * @param {Numeric} arg__1
  * @returns {QByteArray}
  */
QDomDocument.prototype.toByteArray = function(arg__1){return new QByteArray();};

/**
  * @name toString
  * @function
  * @memberOf QDomDocument.prototype
  * @param {Numeric} arg__1
  * @returns {String}
  */
QDomDocument.prototype.toString = function(arg__1){return new String();};

