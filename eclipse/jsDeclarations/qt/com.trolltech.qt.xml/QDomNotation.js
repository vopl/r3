/**
  * @name QDomNotation
  * @constructor
  * @extends QDomNode
  */
function QDomNotation(){return undefined;};

/**
  * @name QDomNotation^1
  * @constructor
  * @extends QDomNode
  * @param {QDomNotation} x
  */
function QDomNotation(x){return undefined;};

QDomNotation.prototype = new QDomNode();

/**
  * @name publicId
  * @function
  * @memberOf QDomNotation.prototype
  * @returns {String}
  */
QDomNotation.prototype.publicId = function(){return new String();};

/**
  * @name systemId
  * @function
  * @memberOf QDomNotation.prototype
  * @returns {String}
  */
QDomNotation.prototype.systemId = function(){return new String();};

