/**
  * @name QSimpleXmlNodeModel
  * @constructor
  * @extends QAbstractXmlNodeModel
  * @param {QXmlNamePool} namePool
  */
function QSimpleXmlNodeModel(namePool){return undefined;};

QSimpleXmlNodeModel.prototype = new QAbstractXmlNodeModel();

/**
  * @name namePool
  * @function
  * @memberOf QSimpleXmlNodeModel.prototype
  * @returns {QXmlNamePool}
  */
QSimpleXmlNodeModel.prototype.namePool = function(){return new QXmlNamePool();};

