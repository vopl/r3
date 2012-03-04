/**
  * @name QDomDocumentType
  * @constructor
  * @extends QDomNode
  */
function QDomDocumentType(){return undefined;};

/**
  * @name QDomDocumentType^1
  * @constructor
  * @extends QDomNode
  * @param {QDomDocumentType} x
  */
function QDomDocumentType(x){return undefined;};

QDomDocumentType.prototype = new QDomNode();

/**
  * @name entities
  * @function
  * @memberOf QDomDocumentType.prototype
  * @returns {QDomNamedNodeMap}
  */
QDomDocumentType.prototype.entities = function(){return new QDomNamedNodeMap();};

/**
  * @name internalSubset
  * @function
  * @memberOf QDomDocumentType.prototype
  * @returns {String}
  */
QDomDocumentType.prototype.internalSubset = function(){return new String();};

/**
  * @name name
  * @function
  * @memberOf QDomDocumentType.prototype
  * @returns {String}
  */
QDomDocumentType.prototype.name = function(){return new String();};

/**
  * @name notations
  * @function
  * @memberOf QDomDocumentType.prototype
  * @returns {QDomNamedNodeMap}
  */
QDomDocumentType.prototype.notations = function(){return new QDomNamedNodeMap();};

/**
  * @name publicId
  * @function
  * @memberOf QDomDocumentType.prototype
  * @returns {String}
  */
QDomDocumentType.prototype.publicId = function(){return new String();};

/**
  * @name systemId
  * @function
  * @memberOf QDomDocumentType.prototype
  * @returns {String}
  */
QDomDocumentType.prototype.systemId = function(){return new String();};

