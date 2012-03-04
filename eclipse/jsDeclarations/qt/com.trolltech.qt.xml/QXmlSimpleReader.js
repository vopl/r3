/**
  * @name QXmlSimpleReader
  * @constructor
  * @extends QXmlReader
  */
function QXmlSimpleReader(){return undefined;};

QXmlSimpleReader.prototype = new QXmlReader();

/**
  * @name parse
  * @function
  * @memberOf QXmlSimpleReader.prototype
  * @param {QXmlInputSource} input
  * @param {Boolean} incremental
  * @returns {Boolean}
  */
QXmlSimpleReader.prototype.parse = function(input, incremental){return new Boolean();};

/**
  * @name parseContinue
  * @function
  * @memberOf QXmlSimpleReader.prototype
  * @returns {Boolean}
  */
QXmlSimpleReader.prototype.parseContinue = function(){return new Boolean();};

