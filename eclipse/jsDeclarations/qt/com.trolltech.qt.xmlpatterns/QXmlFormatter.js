/**
  * @name QXmlFormatter
  * @constructor
  * @extends QXmlSerializer
  * @param {QXmlQuery} query
  * @param {QIODevice} outputDevice
  */
function QXmlFormatter(query, outputDevice){return undefined;};

QXmlFormatter.prototype = new QXmlSerializer();

/**
  * @name indentationDepth
  * @function
  * @memberOf QXmlFormatter.prototype
  * @returns {Numeric}
  */
QXmlFormatter.prototype.indentationDepth = function(){return new Numeric();};

/**
  * @name setIndentationDepth
  * @function
  * @memberOf QXmlFormatter.prototype
  * @param {Numeric} depth
  * @returns {undefined}
  */
QXmlFormatter.prototype.setIndentationDepth = function(depth){return undefined;};

