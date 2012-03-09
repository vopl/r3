/**
  * @name QCryptographicHash
  * @constructor
  * @param {QCryptographicHash.Algorithm} method
  */
function QCryptographicHash(method){return undefined;};

/**
  * @name hash
  * @function
  * @memberOf QCryptographicHash
  * @param {QByteArray} data
  * @param {QCryptographicHash.Algorithm} method
  * @returns {QByteArray}
  */
QCryptographicHash.hash = function(data, method){return new QByteArray();};

/**
  * @default 0x0
  * @constant
  * @memberOf QCryptographicHash
  * @name Md4
  * @see QCryptographicHash#Algorithm
  * @type Number
  */
QCryptographicHash.Md4 = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCryptographicHash
  * @name Md5
  * @see QCryptographicHash#Algorithm
  * @type Number
  */
QCryptographicHash.Md5 = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QCryptographicHash
  * @name Sha1
  * @see QCryptographicHash#Algorithm
  * @type Number
  */
QCryptographicHash.Sha1 = 0x2;

/**
  * @constructor 
  * @memberOf QCryptographicHash
  * @name Algorithm
  */
QCryptographicHash.Algorithm = function(value){;};



/**
  * @name addData
  * @function
  * @memberOf QCryptographicHash.prototype
  * @param {QByteArray} data
  * @returns {undefined}
  */
QCryptographicHash.prototype.addData = function(data){return undefined;};

/**
  * @name reset
  * @function
  * @memberOf QCryptographicHash.prototype
  * @returns {undefined}
  */
QCryptographicHash.prototype.reset = function(){return undefined;};

/**
  * @name result
  * @function
  * @memberOf QCryptographicHash.prototype
  * @returns {QByteArray}
  */
QCryptographicHash.prototype.result = function(){return new QByteArray();};

