/**
  * @name QDomElement
  * @constructor
  * @extends QDomNode
  */
function QDomElement(){return undefined;};

/**
  * @name QDomElement^1
  * @constructor
  * @extends QDomNode
  * @param {QDomElement} x
  */
function QDomElement(x){return undefined;};

QDomElement.prototype = new QDomNode();

/**
  * @name attribute
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} name
  * @param {String} defValue
  * @returns {String}
  */
QDomElement.prototype.attribute = function(name, defValue){return new String();};

/**
  * @name attributeNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} nsURI
  * @param {String} localName
  * @param {String} defValue
  * @returns {String}
  */
QDomElement.prototype.attributeNS = function(nsURI, localName, defValue){return new String();};

/**
  * @name attributeNode
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} name
  * @returns {QDomAttr}
  */
QDomElement.prototype.attributeNode = function(name){return new QDomAttr();};

/**
  * @name attributeNodeNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} nsURI
  * @param {String} localName
  * @returns {QDomAttr}
  */
QDomElement.prototype.attributeNodeNS = function(nsURI, localName){return new QDomAttr();};

/**
  * @name attributes
  * @function
  * @memberOf QDomElement.prototype
  * @returns {QDomNamedNodeMap}
  */
QDomElement.prototype.attributes = function(){return new QDomNamedNodeMap();};

/**
  * @name elementsByTagName
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} tagname
  * @returns {QDomNodeList}
  */
QDomElement.prototype.elementsByTagName = function(tagname){return new QDomNodeList();};

/**
  * @name elementsByTagNameNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} nsURI
  * @param {String} localName
  * @returns {QDomNodeList}
  */
QDomElement.prototype.elementsByTagNameNS = function(nsURI, localName){return new QDomNodeList();};

/**
  * @name hasAttribute
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QDomElement.prototype.hasAttribute = function(name){return new Boolean();};

/**
  * @name hasAttributeNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} nsURI
  * @param {String} localName
  * @returns {Boolean}
  */
QDomElement.prototype.hasAttributeNS = function(nsURI, localName){return new Boolean();};

/**
  * @name removeAttribute
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} name
  * @returns {undefined}
  */
QDomElement.prototype.removeAttribute = function(name){return undefined;};

/**
  * @name removeAttributeNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} nsURI
  * @param {String} localName
  * @returns {undefined}
  */
QDomElement.prototype.removeAttributeNS = function(nsURI, localName){return undefined;};

/**
  * @name removeAttributeNode
  * @function
  * @memberOf QDomElement.prototype
  * @param {QDomAttr} oldAttr
  * @returns {QDomAttr}
  */
QDomElement.prototype.removeAttributeNode = function(oldAttr){return new QDomAttr();};

/**
  * @name setAttribute
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} name
  * @param {String} value
  * @returns {undefined}
  */
QDomElement.prototype.setAttribute = function(name, value){return undefined;};

/**
  * @name setAttributeNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} nsURI
  * @param {String} qName
  * @param {String} value
  * @returns {undefined}
  */
QDomElement.prototype.setAttributeNS = function(nsURI, qName, value){return undefined;};

/**
  * @name setAttributeNode
  * @function
  * @memberOf QDomElement.prototype
  * @param {QDomAttr} newAttr
  * @returns {QDomAttr}
  */
QDomElement.prototype.setAttributeNode = function(newAttr){return new QDomAttr();};

/**
  * @name setAttributeNodeNS
  * @function
  * @memberOf QDomElement.prototype
  * @param {QDomAttr} newAttr
  * @returns {QDomAttr}
  */
QDomElement.prototype.setAttributeNodeNS = function(newAttr){return new QDomAttr();};

/**
  * @name setTagName
  * @function
  * @memberOf QDomElement.prototype
  * @param {String} name
  * @returns {undefined}
  */
QDomElement.prototype.setTagName = function(name){return undefined;};

/**
  * @name tagName
  * @function
  * @memberOf QDomElement.prototype
  * @returns {String}
  */
QDomElement.prototype.tagName = function(){return new String();};

/**
  * @name text
  * @function
  * @memberOf QDomElement.prototype
  * @returns {String}
  */
QDomElement.prototype.text = function(){return new String();};

