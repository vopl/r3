/**
  * @name QImageWriter
  * @constructor
  */
function QImageWriter(){return undefined;};

/**
  * @name QImageWriter^1
  * @constructor
  * @param {QIODevice} device
  * @param {QByteArray} format
  */
function QImageWriter(device, format){return undefined;};

/**
  * @name QImageWriter^2
  * @constructor
  * @param {String} fileName
  * @param {QByteArray} format
  */
function QImageWriter(fileName, format){return undefined;};

/**
  * @name supportedImageFormats
  * @function
  * @memberOf QImageWriter
  * @returns {Array}
  */
QImageWriter.supportedImageFormats = function(){return new Array();};

/**
  * @default 0x0
  * @constant
  * @memberOf QImageWriter
  * @name UnknownError
  * @see QImageWriter#ImageWriterError
  * @type Number
  */
QImageWriter.UnknownError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QImageWriter
  * @name DeviceError
  * @see QImageWriter#ImageWriterError
  * @type Number
  */
QImageWriter.DeviceError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QImageWriter
  * @name UnsupportedFormatError
  * @see QImageWriter#ImageWriterError
  * @type Number
  */
QImageWriter.UnsupportedFormatError = 0x2;

/**
  * @constructor 
  * @memberOf QImageWriter
  * @name ImageWriterError
  */
QImageWriter.ImageWriterError = function(value){;};



/**
  * @name canWrite
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {Boolean}
  */
QImageWriter.prototype.canWrite = function(){return new Boolean();};

/**
  * @name compression
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {Numeric}
  */
QImageWriter.prototype.compression = function(){return new Numeric();};

/**
  * @name device
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {QIODevice}
  */
QImageWriter.prototype.device = function(){return new QIODevice();};

/**
  * @name error
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {QImageWriter.ImageWriterError}
  */
QImageWriter.prototype.error = function(){return new QImageWriter.ImageWriterError();};

/**
  * @name errorString
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {String}
  */
QImageWriter.prototype.errorString = function(){return new String();};

/**
  * @name fileName
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {String}
  */
QImageWriter.prototype.fileName = function(){return new String();};

/**
  * @name format
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {QByteArray}
  */
QImageWriter.prototype.format = function(){return new QByteArray();};

/**
  * @name gamma
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {Numeric}
  */
QImageWriter.prototype.gamma = function(){return new Numeric();};

/**
  * @name quality
  * @function
  * @memberOf QImageWriter.prototype
  * @returns {Numeric}
  */
QImageWriter.prototype.quality = function(){return new Numeric();};

/**
  * @name setCompression
  * @function
  * @memberOf QImageWriter.prototype
  * @param {Numeric} compression
  * @returns {undefined}
  */
QImageWriter.prototype.setCompression = function(compression){return undefined;};

/**
  * @name setDevice
  * @function
  * @memberOf QImageWriter.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QImageWriter.prototype.setDevice = function(device){return undefined;};

/**
  * @name setFileName
  * @function
  * @memberOf QImageWriter.prototype
  * @param {String} fileName
  * @returns {undefined}
  */
QImageWriter.prototype.setFileName = function(fileName){return undefined;};

/**
  * @name setFormat
  * @function
  * @memberOf QImageWriter.prototype
  * @param {QByteArray} format
  * @returns {undefined}
  */
QImageWriter.prototype.setFormat = function(format){return undefined;};

/**
  * @name setGamma
  * @function
  * @memberOf QImageWriter.prototype
  * @param {Numeric} gamma
  * @returns {undefined}
  */
QImageWriter.prototype.setGamma = function(gamma){return undefined;};

/**
  * @name setQuality
  * @function
  * @memberOf QImageWriter.prototype
  * @param {Numeric} quality
  * @returns {undefined}
  */
QImageWriter.prototype.setQuality = function(quality){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QImageWriter.prototype
  * @param {String} key
  * @param {String} text
  * @returns {undefined}
  */
QImageWriter.prototype.setText = function(key, text){return undefined;};

/**
  * @name supportsOption
  * @function
  * @memberOf QImageWriter.prototype
  * @param {QImageIOHandler.ImageOption} option
  * @returns {Boolean}
  */
QImageWriter.prototype.supportsOption = function(option){return new Boolean();};

/**
  * @name write
  * @function
  * @memberOf QImageWriter.prototype
  * @param {QImage} image
  * @returns {Boolean}
  */
QImageWriter.prototype.write = function(image){return new Boolean();};

