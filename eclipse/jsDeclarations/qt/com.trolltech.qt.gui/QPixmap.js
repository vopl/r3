/**
  * @name QPixmap
  * @constructor
  * @extends QPaintDevice
  */
function QPixmap(){return undefined;};

/**
  * @name QPixmap^1
  * @constructor
  * @extends QPaintDevice
  * @param {QPixmap} arg__1
  */
function QPixmap(arg__1){return undefined;};

/**
  * @name QPixmap^2
  * @constructor
  * @extends QPaintDevice
  * @param {QSize} arg__1
  */
function QPixmap(arg__1){return undefined;};

/**
  * @name QPixmap^3
  * @constructor
  * @extends QPaintDevice
  * @param {String} fileName
  * @param {String} format
  * @param {Qt.ImageConversionFlags} flags
  */
function QPixmap(fileName, format, flags){return undefined;};

/**
  * @name QPixmap^4
  * @constructor
  * @extends QPaintDevice
  * @param {String} xpm
  */
function QPixmap(xpm){return undefined;};

/**
  * @name QPixmap^5
  * @constructor
  * @extends QPaintDevice
  * @param {Numeric} w
  * @param {Numeric} h
  */
function QPixmap(w, h){return undefined;};

/**
  * @name defaultDepth
  * @function
  * @memberOf QPixmap
  * @returns {Numeric}
  */
QPixmap.defaultDepth = function(){return new Numeric();};

/**
  * @name fromImage
  * @function
  * @memberOf QPixmap
  * @param {QImage} image
  * @param {Qt.ImageConversionFlags} flags
  * @returns {QPixmap}
  */
QPixmap.fromImage = function(image, flags){return new QPixmap();};

/**
  * @name fromImageReader
  * @function
  * @memberOf QPixmap
  * @param {QImageReader} imageReader
  * @param {Qt.ImageConversionFlags} flags
  * @returns {QPixmap}
  */
QPixmap.fromImageReader = function(imageReader, flags){return new QPixmap();};

/**
  * @name grabWidget
  * @function
  * @memberOf QPixmap
  * @param {QWidget} widget
  * @param {QRect} rect
  * @returns {QPixmap}
  */
QPixmap.grabWidget = function(widget, rect){return new QPixmap();};

/**
  * @name grabWindow
  * @function
  * @memberOf QPixmap
  * @param {String} arg__1
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {QPixmap}
  */
QPixmap.grabWindow = function(arg__1, x, y, w, h){return new QPixmap();};

/**
  * @name trueMatrix
  * @function
  * @memberOf QPixmap
  * @param {QMatrix} m
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {QMatrix}
  */
QPixmap.trueMatrix = function(m, w, h){return new QMatrix();};

/**
  * @name alphaChannel
  * @function
  * @memberOf QPixmap.prototype
  * @returns {QPixmap}
  */
QPixmap.prototype.alphaChannel = function(){return new QPixmap();};

/**
  * @name cacheKey
  * @function
  * @memberOf QPixmap.prototype
  * @returns {Numeric}
  */
QPixmap.prototype.cacheKey = function(){return new Numeric();};

/**
  * @name convertFromImage
  * @function
  * @memberOf QPixmap.prototype
  * @param {QImage} img
  * @param {Qt.ImageConversionFlags} flags
  * @returns {Boolean}
  */
QPixmap.prototype.convertFromImage = function(img, flags){return new Boolean();};

/**
  * @name copy
  * @function
  * @memberOf QPixmap.prototype
  * @param {QRect} rect
  * @returns {QPixmap}
  */
QPixmap.prototype.copy = function(rect){return new QPixmap();};

/**
  * @name createHeuristicMask
  * @function
  * @memberOf QPixmap.prototype
  * @param {Boolean} clipTight
  * @returns {QBitmap}
  */
QPixmap.prototype.createHeuristicMask = function(clipTight){return new QBitmap();};

/**
  * @name createMaskFromColor
  * @function
  * @memberOf QPixmap.prototype
  * @param {QColor} maskColor
  * @returns {QBitmap}
  */
QPixmap.prototype.createMaskFromColor = function(maskColor){return new QBitmap();};

/**
  * @name fill
  * @function
  * @memberOf QPixmap.prototype
  * @param {QColor} fillColor
  * @returns {undefined}
  */
QPixmap.prototype.fill = function(fillColor){return undefined;};

/**
  * @name hasAlpha
  * @function
  * @memberOf QPixmap.prototype
  * @returns {Boolean}
  */
QPixmap.prototype.hasAlpha = function(){return new Boolean();};

/**
  * @name hasAlphaChannel
  * @function
  * @memberOf QPixmap.prototype
  * @returns {Boolean}
  */
QPixmap.prototype.hasAlphaChannel = function(){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QPixmap.prototype
  * @returns {Boolean}
  */
QPixmap.prototype.isNull = function(){return new Boolean();};

/**
  * @name isQBitmap
  * @function
  * @memberOf QPixmap.prototype
  * @returns {Boolean}
  */
QPixmap.prototype.isQBitmap = function(){return new Boolean();};

/**
  * @name load
  * @function
  * @memberOf QPixmap.prototype
  * @param {String} fileName
  * @param {String} format
  * @param {Qt.ImageConversionFlags} flags
  * @returns {Boolean}
  */
QPixmap.prototype.load = function(fileName, format, flags){return new Boolean();};

/**
  * @name loadFromData
  * @function
  * @memberOf QPixmap.prototype
  * @param {QByteArray} data
  * @param {String} format
  * @param {Qt.ImageConversionFlags} flags
  * @returns {Boolean}
  */
QPixmap.prototype.loadFromData = function(data, format, flags){return new Boolean();};

/**
  * @name mask
  * @function
  * @memberOf QPixmap.prototype
  * @returns {QBitmap}
  */
QPixmap.prototype.mask = function(){return new QBitmap();};

/**
  * @name readFrom
  * @function
  * @memberOf QPixmap.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QPixmap.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name rect
  * @function
  * @memberOf QPixmap.prototype
  * @returns {QRect}
  */
QPixmap.prototype.rect = function(){return new QRect();};

/**
  * @name save
  * @function
  * @memberOf QPixmap.prototype
  * @param {QIODevice} device
  * @param {String} format
  * @param {Numeric} quality
  * @returns {Boolean}
  */
QPixmap.prototype.save = function(device, format, quality){return new Boolean();};

/**
  * @name scaled
  * @function
  * @memberOf QPixmap.prototype
  * @param {QSize} s
  * @param {Qt.AspectRatioMode} aspectMode
  * @param {Qt.TransformationMode} mode
  * @returns {QPixmap}
  */
QPixmap.prototype.scaled = function(s, aspectMode, mode){return new QPixmap();};

/**
  * @name scaledToHeight
  * @function
  * @memberOf QPixmap.prototype
  * @param {Numeric} h
  * @param {Qt.TransformationMode} mode
  * @returns {QPixmap}
  */
QPixmap.prototype.scaledToHeight = function(h, mode){return new QPixmap();};

/**
  * @name scaledToWidth
  * @function
  * @memberOf QPixmap.prototype
  * @param {Numeric} w
  * @param {Qt.TransformationMode} mode
  * @returns {QPixmap}
  */
QPixmap.prototype.scaledToWidth = function(w, mode){return new QPixmap();};

/**
  * @name scroll
  * @function
  * @memberOf QPixmap.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @param {QRect} rect
  * @param {QRegion} exposed
  * @returns {undefined}
  */
QPixmap.prototype.scroll = function(dx, dy, rect, exposed){return undefined;};

/**
  * @name setAlphaChannel
  * @function
  * @memberOf QPixmap.prototype
  * @param {QPixmap} arg__1
  * @returns {undefined}
  */
QPixmap.prototype.setAlphaChannel = function(arg__1){return undefined;};

/**
  * @name setMask
  * @function
  * @memberOf QPixmap.prototype
  * @param {QBitmap} arg__1
  * @returns {undefined}
  */
QPixmap.prototype.setMask = function(arg__1){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QPixmap.prototype
  * @returns {QSize}
  */
QPixmap.prototype.size = function(){return new QSize();};

/**
  * @name swap
  * @function
  * @memberOf QPixmap.prototype
  * @param {QPixmap} other
  * @returns {undefined}
  */
QPixmap.prototype.swap = function(other){return undefined;};

/**
  * @name toImage
  * @function
  * @memberOf QPixmap.prototype
  * @returns {QImage}
  */
QPixmap.prototype.toImage = function(){return new QImage();};

/**
  * @name transformed
  * @function
  * @memberOf QPixmap.prototype
  * @param {QMatrix} arg__1
  * @param {Qt.TransformationMode} mode
  * @returns {QPixmap}
  */
QPixmap.prototype.transformed = function(arg__1, mode){return new QPixmap();};

/**
  * @name writeTo
  * @function
  * @memberOf QPixmap.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QPixmap.prototype.writeTo = function(arg__1){return undefined;};

