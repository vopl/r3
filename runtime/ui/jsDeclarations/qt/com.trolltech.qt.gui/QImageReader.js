/**
  * @name QImageReader
  * @constructor
  */
function QImageReader(){return undefined;};

/**
  * @name QImageReader^1
  * @constructor
  * @param {QIODevice} device
  * @param {QByteArray} format
  */
function QImageReader(device, format){return undefined;};

/**
  * @name QImageReader^2
  * @constructor
  * @param {String} fileName
  * @param {QByteArray} format
  */
function QImageReader(fileName, format){return undefined;};

/**
  * @name imageFormat
  * @function
  * @memberOf QImageReader
  * @param {QIODevice} device
  * @returns {QByteArray}
  */
QImageReader.imageFormat = function(device){return new QByteArray();};

/**
  * @name supportedImageFormats
  * @function
  * @memberOf QImageReader
  * @returns {Array}
  */
QImageReader.supportedImageFormats = function(){return new Array();};

/**
  * @default 0x0
  * @constant
  * @memberOf QImageReader
  * @name UnknownError
  * @see QImageReader#ImageReaderError
  * @type Number
  */
QImageReader.UnknownError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QImageReader
  * @name FileNotFoundError
  * @see QImageReader#ImageReaderError
  * @type Number
  */
QImageReader.FileNotFoundError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QImageReader
  * @name DeviceError
  * @see QImageReader#ImageReaderError
  * @type Number
  */
QImageReader.DeviceError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QImageReader
  * @name UnsupportedFormatError
  * @see QImageReader#ImageReaderError
  * @type Number
  */
QImageReader.UnsupportedFormatError = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QImageReader
  * @name InvalidDataError
  * @see QImageReader#ImageReaderError
  * @type Number
  */
QImageReader.InvalidDataError = 0x4;

/**
  * @constructor 
  * @memberOf QImageReader
  * @name ImageReaderError
  */
QImageReader.ImageReaderError = function(value){;};



/**
  * @name autoDetectImageFormat
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Boolean}
  */
QImageReader.prototype.autoDetectImageFormat = function(){return new Boolean();};

/**
  * @name backgroundColor
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QColor}
  */
QImageReader.prototype.backgroundColor = function(){return new QColor();};

/**
  * @name canRead
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Boolean}
  */
QImageReader.prototype.canRead = function(){return new Boolean();};

/**
  * @name clipRect
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QRect}
  */
QImageReader.prototype.clipRect = function(){return new QRect();};

/**
  * @name currentImageNumber
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Numeric}
  */
QImageReader.prototype.currentImageNumber = function(){return new Numeric();};

/**
  * @name currentImageRect
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QRect}
  */
QImageReader.prototype.currentImageRect = function(){return new QRect();};

/**
  * @name decideFormatFromContent
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Boolean}
  */
QImageReader.prototype.decideFormatFromContent = function(){return new Boolean();};

/**
  * @name device
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QIODevice}
  */
QImageReader.prototype.device = function(){return new QIODevice();};

/**
  * @name error
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QImageReader.ImageReaderError}
  */
QImageReader.prototype.error = function(){return new QImageReader.ImageReaderError();};

/**
  * @name errorString
  * @function
  * @memberOf QImageReader.prototype
  * @returns {String}
  */
QImageReader.prototype.errorString = function(){return new String();};

/**
  * @name fileName
  * @function
  * @memberOf QImageReader.prototype
  * @returns {String}
  */
QImageReader.prototype.fileName = function(){return new String();};

/**
  * @name format
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QByteArray}
  */
QImageReader.prototype.format = function(){return new QByteArray();};

/**
  * @name imageCount
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Numeric}
  */
QImageReader.prototype.imageCount = function(){return new Numeric();};

/**
  * @name imageFormat
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QSettings.Format}
  */
QImageReader.prototype.imageFormat = function(){return new QSettings.Format();};

/**
  * @name jumpToImage
  * @function
  * @memberOf QImageReader.prototype
  * @param {Numeric} imageNumber
  * @returns {Boolean}
  */
QImageReader.prototype.jumpToImage = function(imageNumber){return new Boolean();};

/**
  * @name jumpToNextImage
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Boolean}
  */
QImageReader.prototype.jumpToNextImage = function(){return new Boolean();};

/**
  * @name loopCount
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Numeric}
  */
QImageReader.prototype.loopCount = function(){return new Numeric();};

/**
  * @name nextImageDelay
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Numeric}
  */
QImageReader.prototype.nextImageDelay = function(){return new Numeric();};

/**
  * @name quality
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Numeric}
  */
QImageReader.prototype.quality = function(){return new Numeric();};

/**
  * @name read
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QImage}
  */
QImageReader.prototype.read = function(){return new QImage();};

/**
  * @name scaledClipRect
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QRect}
  */
QImageReader.prototype.scaledClipRect = function(){return new QRect();};

/**
  * @name scaledSize
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QSize}
  */
QImageReader.prototype.scaledSize = function(){return new QSize();};

/**
  * @name setAutoDetectImageFormat
  * @function
  * @memberOf QImageReader.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QImageReader.prototype.setAutoDetectImageFormat = function(enabled){return undefined;};

/**
  * @name setBackgroundColor
  * @function
  * @memberOf QImageReader.prototype
  * @param {QColor} color
  * @returns {undefined}
  */
QImageReader.prototype.setBackgroundColor = function(color){return undefined;};

/**
  * @name setClipRect
  * @function
  * @memberOf QImageReader.prototype
  * @param {QRect} rect
  * @returns {undefined}
  */
QImageReader.prototype.setClipRect = function(rect){return undefined;};

/**
  * @name setDecideFormatFromContent
  * @function
  * @memberOf QImageReader.prototype
  * @param {Boolean} ignored
  * @returns {undefined}
  */
QImageReader.prototype.setDecideFormatFromContent = function(ignored){return undefined;};

/**
  * @name setDevice
  * @function
  * @memberOf QImageReader.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QImageReader.prototype.setDevice = function(device){return undefined;};

/**
  * @name setFileName
  * @function
  * @memberOf QImageReader.prototype
  * @param {String} fileName
  * @returns {undefined}
  */
QImageReader.prototype.setFileName = function(fileName){return undefined;};

/**
  * @name setFormat
  * @function
  * @memberOf QImageReader.prototype
  * @param {QByteArray} format
  * @returns {undefined}
  */
QImageReader.prototype.setFormat = function(format){return undefined;};

/**
  * @name setQuality
  * @function
  * @memberOf QImageReader.prototype
  * @param {Numeric} quality
  * @returns {undefined}
  */
QImageReader.prototype.setQuality = function(quality){return undefined;};

/**
  * @name setScaledClipRect
  * @function
  * @memberOf QImageReader.prototype
  * @param {QRect} rect
  * @returns {undefined}
  */
QImageReader.prototype.setScaledClipRect = function(rect){return undefined;};

/**
  * @name setScaledSize
  * @function
  * @memberOf QImageReader.prototype
  * @param {QSize} size
  * @returns {undefined}
  */
QImageReader.prototype.setScaledSize = function(size){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QImageReader.prototype
  * @returns {QSize}
  */
QImageReader.prototype.size = function(){return new QSize();};

/**
  * @name supportsAnimation
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Boolean}
  */
QImageReader.prototype.supportsAnimation = function(){return new Boolean();};

/**
  * @name supportsOption
  * @function
  * @memberOf QImageReader.prototype
  * @param {QImageIOHandler.ImageOption} option
  * @returns {Boolean}
  */
QImageReader.prototype.supportsOption = function(option){return new Boolean();};

/**
  * @name text
  * @function
  * @memberOf QImageReader.prototype
  * @param {String} key
  * @returns {String}
  */
QImageReader.prototype.text = function(key){return new String();};

/**
  * @name textKeys
  * @function
  * @memberOf QImageReader.prototype
  * @returns {Array}
  */
QImageReader.prototype.textKeys = function(){return new Array();};

