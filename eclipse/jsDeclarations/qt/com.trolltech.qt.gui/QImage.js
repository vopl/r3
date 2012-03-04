/**
  * @name QImage
  * @constructor
  * @extends QPaintDevice
  */
function QImage(){return undefined;};

/**
  * @name QImage^1
  * @constructor
  * @extends QPaintDevice
  * @param {QImage} arg__1
  */
function QImage(arg__1){return undefined;};

/**
  * @name QImage^2
  * @constructor
  * @extends QPaintDevice
  * @param {QSize} size
  * @param {QSettings.Format} format
  */
function QImage(size, format){return undefined;};

/**
  * @name QImage^3
  * @constructor
  * @extends QPaintDevice
  * @param {String} fileName
  * @param {String} format
  */
function QImage(fileName, format){return undefined;};

/**
  * @name QImage^4
  * @constructor
  * @extends QPaintDevice
  * @param {Numeric} width
  * @param {Numeric} height
  * @param {QSettings.Format} format
  */
function QImage(width, height, format){return undefined;};

/**
  * @name fromData
  * @function
  * @memberOf QImage
  * @param {QByteArray} data
  * @param {String} format
  * @returns {QImage}
  */
QImage.fromData = function(data, format){return new QImage();};

/**
  * @name trueMatrix
  * @function
  * @memberOf QImage
  * @param {QMatrix} arg__1
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {QMatrix}
  */
QImage.trueMatrix = function(arg__1, w, h){return new QMatrix();};

/**
  * @default 0x0
  * @constant
  * @memberOf QImage
  * @name InvertRgb
  * @see QImage#InvertMode
  * @type Number
  */
QImage.InvertRgb = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QImage
  * @name InvertRgba
  * @see QImage#InvertMode
  * @type Number
  */
QImage.InvertRgba = 0x1;

/**
  * @constructor 
  * @memberOf QImage
  * @name InvertMode
  */
QImage.InvertMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QImage
  * @name Format_Invalid
  * @see QImage#Format
  * @type Number
  */
QImage.Format_Invalid = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QImage
  * @name Format_Mono
  * @see QImage#Format
  * @type Number
  */
QImage.Format_Mono = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QImage
  * @name Format_MonoLSB
  * @see QImage#Format
  * @type Number
  */
QImage.Format_MonoLSB = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QImage
  * @name Format_Indexed8
  * @see QImage#Format
  * @type Number
  */
QImage.Format_Indexed8 = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QImage
  * @name Format_RGB32
  * @see QImage#Format
  * @type Number
  */
QImage.Format_RGB32 = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QImage
  * @name Format_ARGB32
  * @see QImage#Format
  * @type Number
  */
QImage.Format_ARGB32 = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QImage
  * @name Format_ARGB32_Premultiplied
  * @see QImage#Format
  * @type Number
  */
QImage.Format_ARGB32_Premultiplied = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QImage
  * @name Format_RGB16
  * @see QImage#Format
  * @type Number
  */
QImage.Format_RGB16 = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QImage
  * @name Format_ARGB8565_Premultiplied
  * @see QImage#Format
  * @type Number
  */
QImage.Format_ARGB8565_Premultiplied = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QImage
  * @name Format_RGB666
  * @see QImage#Format
  * @type Number
  */
QImage.Format_RGB666 = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QImage
  * @name Format_ARGB6666_Premultiplied
  * @see QImage#Format
  * @type Number
  */
QImage.Format_ARGB6666_Premultiplied = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QImage
  * @name Format_RGB555
  * @see QImage#Format
  * @type Number
  */
QImage.Format_RGB555 = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QImage
  * @name Format_ARGB8555_Premultiplied
  * @see QImage#Format
  * @type Number
  */
QImage.Format_ARGB8555_Premultiplied = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QImage
  * @name Format_RGB888
  * @see QImage#Format
  * @type Number
  */
QImage.Format_RGB888 = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QImage
  * @name Format_RGB444
  * @see QImage#Format
  * @type Number
  */
QImage.Format_RGB444 = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QImage
  * @name Format_ARGB4444_Premultiplied
  * @see QImage#Format
  * @type Number
  */
QImage.Format_ARGB4444_Premultiplied = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QImage
  * @name NImageFormats
  * @see QImage#Format
  * @type Number
  */
QImage.NImageFormats = 0x10;

/**
  * @constructor 
  * @memberOf QImage
  * @name Format
  */
QImage.Format = function(value){;};



/**
  * @name allGray
  * @function
  * @memberOf QImage.prototype
  * @returns {Boolean}
  */
QImage.prototype.allGray = function(){return new Boolean();};

/**
  * @name alphaChannel
  * @function
  * @memberOf QImage.prototype
  * @returns {QImage}
  */
QImage.prototype.alphaChannel = function(){return new QImage();};

/**
  * @name bitPlaneCount
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.bitPlaneCount = function(){return new Numeric();};

/**
  * @name byteCount
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.byteCount = function(){return new Numeric();};

/**
  * @name bytesPerLine
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.bytesPerLine = function(){return new Numeric();};

/**
  * @name cacheKey
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.cacheKey = function(){return new Numeric();};

/**
  * @name color
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} i
  * @returns {Numeric}
  */
QImage.prototype.color = function(i){return new Numeric();};

/**
  * @name colorTable
  * @function
  * @memberOf QImage.prototype
  * @returns {Array}
  */
QImage.prototype.colorTable = function(){return new Array();};

/**
  * @name constBits
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.constBits = function(){return new Numeric();};

/**
  * @name constScanLine
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} arg__1
  * @returns {Numeric}
  */
QImage.prototype.constScanLine = function(arg__1){return new Numeric();};

/**
  * @name convertToFormat
  * @function
  * @memberOf QImage.prototype
  * @param {QSettings.Format} f
  * @param {Qt.ImageConversionFlags} flags
  * @returns {QImage}
  */
QImage.prototype.convertToFormat = function(f, flags){return new QImage();};

/**
  * @name copy
  * @function
  * @memberOf QImage.prototype
  * @param {QRect} rect
  * @returns {QImage}
  */
QImage.prototype.copy = function(rect){return new QImage();};

/**
  * @name createAlphaMask
  * @function
  * @memberOf QImage.prototype
  * @param {Qt.ImageConversionFlags} flags
  * @returns {QImage}
  */
QImage.prototype.createAlphaMask = function(flags){return new QImage();};

/**
  * @name createHeuristicMask
  * @function
  * @memberOf QImage.prototype
  * @param {Boolean} clipTight
  * @returns {QImage}
  */
QImage.prototype.createHeuristicMask = function(clipTight){return new QImage();};

/**
  * @name createMaskFromColor
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} color
  * @param {Qt.MaskMode} mode
  * @returns {QImage}
  */
QImage.prototype.createMaskFromColor = function(color, mode){return new QImage();};

/**
  * @name dotsPerMeterX
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.dotsPerMeterX = function(){return new Numeric();};

/**
  * @name dotsPerMeterY
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.dotsPerMeterY = function(){return new Numeric();};

/**
  * @name fill
  * @function
  * @memberOf QImage.prototype
  * @param {Qt.GlobalColor} color
  * @returns {undefined}
  */
QImage.prototype.fill = function(color){return undefined;};

/**
  * @name format
  * @function
  * @memberOf QImage.prototype
  * @returns {QSettings.Format}
  */
QImage.prototype.format = function(){return new QSettings.Format();};

/**
  * @name hasAlphaChannel
  * @function
  * @memberOf QImage.prototype
  * @returns {Boolean}
  */
QImage.prototype.hasAlphaChannel = function(){return new Boolean();};

/**
  * @name invertPixels
  * @function
  * @memberOf QImage.prototype
  * @param {QImage.InvertMode} arg__1
  * @returns {undefined}
  */
QImage.prototype.invertPixels = function(arg__1){return undefined;};

/**
  * @name isGrayscale
  * @function
  * @memberOf QImage.prototype
  * @returns {Boolean}
  */
QImage.prototype.isGrayscale = function(){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QImage.prototype
  * @returns {Boolean}
  */
QImage.prototype.isNull = function(){return new Boolean();};

/**
  * @name load
  * @function
  * @memberOf QImage.prototype
  * @param {QIODevice} device
  * @param {String} format
  * @returns {Boolean}
  */
QImage.prototype.load = function(device, format){return new Boolean();};

/**
  * @name loadFromData
  * @function
  * @memberOf QImage.prototype
  * @param {QByteArray} data
  * @param {String} aformat
  * @returns {Boolean}
  */
QImage.prototype.loadFromData = function(data, aformat){return new Boolean();};

/**
  * @name mirrored
  * @function
  * @memberOf QImage.prototype
  * @param {Boolean} horizontally
  * @param {Boolean} vertically
  * @returns {QImage}
  */
QImage.prototype.mirrored = function(horizontally, vertically){return new QImage();};

/**
  * @name numBytes
  * @function
  * @memberOf QImage.prototype
  * @returns {Numeric}
  */
QImage.prototype.numBytes = function(){return new Numeric();};

/**
  * @name offset
  * @function
  * @memberOf QImage.prototype
  * @returns {QPoint}
  */
QImage.prototype.offset = function(){return new QPoint();};

/**
  * @name operator_equal
  * @function
  * @memberOf QImage.prototype
  * @param {QImage} arg__1
  * @returns {Boolean}
  */
QImage.prototype.operator_equal = function(arg__1){return new Boolean();};

/**
  * @name pixel
  * @function
  * @memberOf QImage.prototype
  * @param {QPoint} pt
  * @returns {Numeric}
  */
QImage.prototype.pixel = function(pt){return new Numeric();};

/**
  * @name pixelIndex
  * @function
  * @memberOf QImage.prototype
  * @param {QPoint} pt
  * @returns {Numeric}
  */
QImage.prototype.pixelIndex = function(pt){return new Numeric();};

/**
  * @name readFrom
  * @function
  * @memberOf QImage.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QImage.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name rect
  * @function
  * @memberOf QImage.prototype
  * @returns {QRect}
  */
QImage.prototype.rect = function(){return new QRect();};

/**
  * @name rgbSwapped
  * @function
  * @memberOf QImage.prototype
  * @returns {QImage}
  */
QImage.prototype.rgbSwapped = function(){return new QImage();};

/**
  * @name save
  * @function
  * @memberOf QImage.prototype
  * @param {QIODevice} device
  * @param {String} format
  * @param {Numeric} quality
  * @returns {Boolean}
  */
QImage.prototype.save = function(device, format, quality){return new Boolean();};

/**
  * @name scaled
  * @function
  * @memberOf QImage.prototype
  * @param {QSize} s
  * @param {Qt.AspectRatioMode} aspectMode
  * @param {Qt.TransformationMode} mode
  * @returns {QImage}
  */
QImage.prototype.scaled = function(s, aspectMode, mode){return new QImage();};

/**
  * @name scaledToHeight
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} h
  * @param {Qt.TransformationMode} mode
  * @returns {QImage}
  */
QImage.prototype.scaledToHeight = function(h, mode){return new QImage();};

/**
  * @name scaledToWidth
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} w
  * @param {Qt.TransformationMode} mode
  * @returns {QImage}
  */
QImage.prototype.scaledToWidth = function(w, mode){return new QImage();};

/**
  * @name setAlphaChannel
  * @function
  * @memberOf QImage.prototype
  * @param {QImage} alphaChannel
  * @returns {undefined}
  */
QImage.prototype.setAlphaChannel = function(alphaChannel){return undefined;};

/**
  * @name setColor
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} i
  * @param {Numeric} c
  * @returns {undefined}
  */
QImage.prototype.setColor = function(i, c){return undefined;};

/**
  * @name setColorCount
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QImage.prototype.setColorCount = function(arg__1){return undefined;};

/**
  * @name setDotsPerMeterX
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QImage.prototype.setDotsPerMeterX = function(arg__1){return undefined;};

/**
  * @name setDotsPerMeterY
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QImage.prototype.setDotsPerMeterY = function(arg__1){return undefined;};

/**
  * @name setNumColors
  * @function
  * @memberOf QImage.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QImage.prototype.setNumColors = function(arg__1){return undefined;};

/**
  * @name setOffset
  * @function
  * @memberOf QImage.prototype
  * @param {QPoint} arg__1
  * @returns {undefined}
  */
QImage.prototype.setOffset = function(arg__1){return undefined;};

/**
  * @name setPixel
  * @function
  * @memberOf QImage.prototype
  * @param {QPoint} pt
  * @param {Numeric} index_or_rgb
  * @returns {undefined}
  */
QImage.prototype.setPixel = function(pt, index_or_rgb){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QImage.prototype
  * @param {String} key
  * @param {String} value
  * @returns {undefined}
  */
QImage.prototype.setText = function(key, value){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QImage.prototype
  * @returns {QSize}
  */
QImage.prototype.size = function(){return new QSize();};

/**
  * @name swap
  * @function
  * @memberOf QImage.prototype
  * @param {QImage} other
  * @returns {undefined}
  */
QImage.prototype.swap = function(other){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QImage.prototype
  * @param {String} key
  * @returns {String}
  */
QImage.prototype.text = function(key){return new String();};

/**
  * @name textKeys
  * @function
  * @memberOf QImage.prototype
  * @returns {Array}
  */
QImage.prototype.textKeys = function(){return new Array();};

/**
  * @name transformed
  * @function
  * @memberOf QImage.prototype
  * @param {QMatrix} matrix
  * @param {Qt.TransformationMode} mode
  * @returns {QImage}
  */
QImage.prototype.transformed = function(matrix, mode){return new QImage();};

/**
  * @name valid
  * @function
  * @memberOf QImage.prototype
  * @param {QPoint} pt
  * @returns {Boolean}
  */
QImage.prototype.valid = function(pt){return new Boolean();};

/**
  * @name writeTo
  * @function
  * @memberOf QImage.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QImage.prototype.writeTo = function(arg__1){return undefined;};

