/**
  * @name QBuffer
  * @constructor
  * @extends QIODevice
  * @param {QByteArray} buf
  * @param {QObject} parent
  */
function QBuffer(buf, parent){return undefined;};

/**
  * @name QBuffer^1
  * @constructor
  * @extends QIODevice
  * @param {QObject} parent
  */
function QBuffer(parent){return undefined;};

QBuffer.prototype = new QIODevice();

/**
  * @name setBuffer
  * @function
  * @memberOf QBuffer.prototype
  * @param {QByteArray} a
  * @returns {undefined}
  */
QBuffer.prototype.setBuffer = function(a){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QBuffer.prototype
  * @param {QByteArray} data
  * @returns {undefined}
  */
QBuffer.prototype.setData = function(data){return undefined;};

