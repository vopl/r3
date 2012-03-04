/**
  * @name QXmlDeclHandler
  * @constructor
  */
function QXmlDeclHandler(){return undefined;};

/**
  * @name attributeDecl
  * @function
  * @memberOf QXmlDeclHandler.prototype
  * @param {String} eName
  * @param {String} aName
  * @param {String} type
  * @param {String} valueDefault
  * @param {String} value
  * @returns {Boolean}
  */
QXmlDeclHandler.prototype.attributeDecl = function(eName, aName, type, valueDefault, value){return new Boolean();};

/**
  * @name errorString
  * @function
  * @memberOf QXmlDeclHandler.prototype
  * @returns {String}
  */
QXmlDeclHandler.prototype.errorString = function(){return new String();};

/**
  * @name externalEntityDecl
  * @function
  * @memberOf QXmlDeclHandler.prototype
  * @param {String} name
  * @param {String} publicId
  * @param {String} systemId
  * @returns {Boolean}
  */
QXmlDeclHandler.prototype.externalEntityDecl = function(name, publicId, systemId){return new Boolean();};

/**
  * @name internalEntityDecl
  * @function
  * @memberOf QXmlDeclHandler.prototype
  * @param {String} name
  * @param {String} value
  * @returns {Boolean}
  */
QXmlDeclHandler.prototype.internalEntityDecl = function(name, value){return new Boolean();};

