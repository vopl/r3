/**
  * @name QImageIOHandler
  * @constructor
  */
function QImageIOHandler(){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QImageIOHandler
  * @name Size
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Size = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QImageIOHandler
  * @name ClipRect
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.ClipRect = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QImageIOHandler
  * @name Description
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Description = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QImageIOHandler
  * @name ScaledClipRect
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.ScaledClipRect = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QImageIOHandler
  * @name ScaledSize
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.ScaledSize = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QImageIOHandler
  * @name CompressionRatio
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.CompressionRatio = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QImageIOHandler
  * @name Gamma
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Gamma = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QImageIOHandler
  * @name Quality
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Quality = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QImageIOHandler
  * @name Name
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Name = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QImageIOHandler
  * @name SubType
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.SubType = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QImageIOHandler
  * @name IncrementalReading
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.IncrementalReading = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QImageIOHandler
  * @name Endianness
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Endianness = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QImageIOHandler
  * @name Animation
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.Animation = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QImageIOHandler
  * @name BackgroundColor
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.BackgroundColor = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QImageIOHandler
  * @name ImageFormat
  * @see QImageIOHandler#ImageOption
  * @type Number
  */
QImageIOHandler.ImageFormat = 0xe;

/**
  * @constructor 
  * @memberOf QImageIOHandler
  * @name ImageOption
  */
QImageIOHandler.ImageOption = function(value){;};



/**
  * @name canRead
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {Boolean}
  */
QImageIOHandler.prototype.canRead = function(){return new Boolean();};

/**
  * @name currentImageNumber
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {Numeric}
  */
QImageIOHandler.prototype.currentImageNumber = function(){return new Numeric();};

/**
  * @name currentImageRect
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {QRect}
  */
QImageIOHandler.prototype.currentImageRect = function(){return new QRect();};

/**
  * @name device
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {QIODevice}
  */
QImageIOHandler.prototype.device = function(){return new QIODevice();};

/**
  * @name format
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {QByteArray}
  */
QImageIOHandler.prototype.format = function(){return new QByteArray();};

/**
  * @name imageCount
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {Numeric}
  */
QImageIOHandler.prototype.imageCount = function(){return new Numeric();};

/**
  * @name jumpToImage
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {Numeric} imageNumber
  * @returns {Boolean}
  */
QImageIOHandler.prototype.jumpToImage = function(imageNumber){return new Boolean();};

/**
  * @name jumpToNextImage
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {Boolean}
  */
QImageIOHandler.prototype.jumpToNextImage = function(){return new Boolean();};

/**
  * @name loopCount
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {Numeric}
  */
QImageIOHandler.prototype.loopCount = function(){return new Numeric();};

/**
  * @name nextImageDelay
  * @function
  * @memberOf QImageIOHandler.prototype
  * @returns {Numeric}
  */
QImageIOHandler.prototype.nextImageDelay = function(){return new Numeric();};

/**
  * @name option
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QImageIOHandler.ImageOption} option
  * @returns {Object}
  */
QImageIOHandler.prototype.option = function(option){return new Object();};

/**
  * @name read
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QImage} image
  * @returns {Boolean}
  */
QImageIOHandler.prototype.read = function(image){return new Boolean();};

/**
  * @name setDevice
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QImageIOHandler.prototype.setDevice = function(device){return undefined;};

/**
  * @name setFormat
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QByteArray} format
  * @returns {undefined}
  */
QImageIOHandler.prototype.setFormat = function(format){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QImageIOHandler.ImageOption} option
  * @param {Object} value
  * @returns {undefined}
  */
QImageIOHandler.prototype.setOption = function(option, value){return undefined;};

/**
  * @name supportsOption
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QImageIOHandler.ImageOption} option
  * @returns {Boolean}
  */
QImageIOHandler.prototype.supportsOption = function(option){return new Boolean();};

/**
  * @name write
  * @function
  * @memberOf QImageIOHandler.prototype
  * @param {QImage} image
  * @returns {Boolean}
  */
QImageIOHandler.prototype.write = function(image){return new Boolean();};

