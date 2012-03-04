/**
  * @name QXmlSerializer
  * @constructor
  * @extends QAbstractXmlReceiver
  * @param {QXmlQuery} query
  * @param {QIODevice} outputDevice
  */
function QXmlSerializer(query, outputDevice){return undefined;};

QXmlSerializer.prototype = new QAbstractXmlReceiver();

/**
  * @name codec
  * @function
  * @memberOf QXmlSerializer.prototype
  * @returns {QTextCodec}
  */
QXmlSerializer.prototype.codec = function(){return new QTextCodec();};

/**
  * @name outputDevice
  * @function
  * @memberOf QXmlSerializer.prototype
  * @returns {QIODevice}
  */
QXmlSerializer.prototype.outputDevice = function(){return new QIODevice();};

/**
  * @name setCodec
  * @function
  * @memberOf QXmlSerializer.prototype
  * @param {QTextCodec} codec
  * @returns {undefined}
  */
QXmlSerializer.prototype.setCodec = function(codec){return undefined;};

