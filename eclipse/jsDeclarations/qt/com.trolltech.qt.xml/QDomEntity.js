/**
  * @name QDomEntity
  * @constructor
  * @extends QDomNode
  */
function QDomEntity(){return undefined;};

/**
  * @name QDomEntity^1
  * @constructor
  * @extends QDomNode
  * @param {QDomEntity} x
  */
function QDomEntity(x){return undefined;};

QDomEntity.prototype = new QDomNode();

/**
  * @name notationName
  * @function
  * @memberOf QDomEntity.prototype
  * @returns {String}
  */
QDomEntity.prototype.notationName = function(){return new String();};

/**
  * @name publicId
  * @function
  * @memberOf QDomEntity.prototype
  * @returns {String}
  */
QDomEntity.prototype.publicId = function(){return new String();};

/**
  * @name systemId
  * @function
  * @memberOf QDomEntity.prototype
  * @returns {String}
  */
QDomEntity.prototype.systemId = function(){return new String();};

