/**
  * @name QMovie
  * @constructor
  * @extends QObject
  * @param {QIODevice} device
  * @param {QByteArray} format
  * @param {QObject} parent
  */
function QMovie(device, format, parent){return undefined;};

/**
  * @name QMovie^1
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QMovie(parent){return undefined;};

/**
  * @name QMovie^2
  * @constructor
  * @extends QObject
  * @param {String} fileName
  * @param {QByteArray} format
  * @param {QObject} parent
  */
function QMovie(fileName, format, parent){return undefined;};

QMovie.prototype = new QObject();

/**
  * @name supportedFormats
  * @function
  * @memberOf QMovie
  * @returns {Array}
  */
QMovie.supportedFormats = function(){return new Array();};

/**
  * @default 0x0
  * @constant
  * @memberOf QMovie
  * @name CacheNone
  * @see QMovie#CacheMode
  * @type Number
  */
QMovie.CacheNone = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QMovie
  * @name CacheAll
  * @see QMovie#CacheMode
  * @type Number
  */
QMovie.CacheAll = 0x1;

/**
  * @constructor 
  * @memberOf QMovie
  * @name CacheMode
  */
QMovie.CacheMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QMovie
  * @name NotRunning
  * @see QMovie#MovieState
  * @type Number
  */
QMovie.NotRunning = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QMovie
  * @name Paused
  * @see QMovie#MovieState
  * @type Number
  */
QMovie.Paused = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QMovie
  * @name Running
  * @see QMovie#MovieState
  * @type Number
  */
QMovie.Running = 0x2;

/**
  * @constructor 
  * @memberOf QMovie
  * @name MovieState
  */
QMovie.MovieState = function(value){;};



/**
  * @name backgroundColor
  * @function
  * @memberOf QMovie.prototype
  * @returns {QColor}
  */
QMovie.prototype.backgroundColor = function(){return new QColor();};

/**
  * @name currentFrameNumber
  * @function
  * @memberOf QMovie.prototype
  * @returns {Numeric}
  */
QMovie.prototype.currentFrameNumber = function(){return new Numeric();};

/**
  * @name currentImage
  * @function
  * @memberOf QMovie.prototype
  * @returns {QImage}
  */
QMovie.prototype.currentImage = function(){return new QImage();};

/**
  * @name currentPixmap
  * @function
  * @memberOf QMovie.prototype
  * @returns {QPixmap}
  */
QMovie.prototype.currentPixmap = function(){return new QPixmap();};

/**
  * @name device
  * @function
  * @memberOf QMovie.prototype
  * @returns {QIODevice}
  */
QMovie.prototype.device = function(){return new QIODevice();};

/**
  * @name fileName
  * @function
  * @memberOf QMovie.prototype
  * @returns {String}
  */
QMovie.prototype.fileName = function(){return new String();};

/**
  * @name format
  * @function
  * @memberOf QMovie.prototype
  * @returns {QByteArray}
  */
QMovie.prototype.format = function(){return new QByteArray();};

/**
  * @name frameCount
  * @function
  * @memberOf QMovie.prototype
  * @returns {Numeric}
  */
QMovie.prototype.frameCount = function(){return new Numeric();};

/**
  * @name frameRect
  * @function
  * @memberOf QMovie.prototype
  * @returns {QRect}
  */
QMovie.prototype.frameRect = function(){return new QRect();};

/**
  * @name isValid
  * @function
  * @memberOf QMovie.prototype
  * @returns {Boolean}
  */
QMovie.prototype.isValid = function(){return new Boolean();};

/**
  * @name jumpToFrame
  * @function
  * @memberOf QMovie.prototype
  * @param {Numeric} frameNumber
  * @returns {Boolean}
  */
QMovie.prototype.jumpToFrame = function(frameNumber){return new Boolean();};

/**
  * @name loopCount
  * @function
  * @memberOf QMovie.prototype
  * @returns {Numeric}
  */
QMovie.prototype.loopCount = function(){return new Numeric();};

/**
  * @name nextFrameDelay
  * @function
  * @memberOf QMovie.prototype
  * @returns {Numeric}
  */
QMovie.prototype.nextFrameDelay = function(){return new Numeric();};

/**
  * @name scaledSize
  * @function
  * @memberOf QMovie.prototype
  * @returns {QSize}
  */
QMovie.prototype.scaledSize = function(){return new QSize();};

/**
  * @name setBackgroundColor
  * @function
  * @memberOf QMovie.prototype
  * @param {QColor} color
  * @returns {undefined}
  */
QMovie.prototype.setBackgroundColor = function(color){return undefined;};

/**
  * @name setDevice
  * @function
  * @memberOf QMovie.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QMovie.prototype.setDevice = function(device){return undefined;};

/**
  * @name setFileName
  * @function
  * @memberOf QMovie.prototype
  * @param {String} fileName
  * @returns {undefined}
  */
QMovie.prototype.setFileName = function(fileName){return undefined;};

/**
  * @name setFormat
  * @function
  * @memberOf QMovie.prototype
  * @param {QByteArray} format
  * @returns {undefined}
  */
QMovie.prototype.setFormat = function(format){return undefined;};

/**
  * @name setScaledSize
  * @function
  * @memberOf QMovie.prototype
  * @param {QSize} size
  * @returns {undefined}
  */
QMovie.prototype.setScaledSize = function(size){return undefined;};

/**
  * @name state
  * @function
  * @memberOf QMovie.prototype
  * @returns {QMovie.MovieState}
  */
QMovie.prototype.state = function(){return new QMovie.MovieState();};

/**
  * @name speed
  * @memberOf QMovie.prototype
  * @type Numeric
  */
QMovie.prototype.speed = new Numeric();

/**
  * @name cacheMode
  * @memberOf QMovie.prototype
  * @type QGraphicsView.CacheMode
  */
QMovie.prototype.cacheMode = new QGraphicsView.CacheMode();


