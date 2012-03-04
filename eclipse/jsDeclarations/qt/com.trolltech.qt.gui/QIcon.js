/**
  * @name QIcon
  * @constructor
  */
function QIcon(){return undefined;};

/**
  * @name QIcon^1
  * @constructor
  * @param {QIconEngine} engine
  */
function QIcon(engine){return undefined;};

/**
  * @name QIcon^2
  * @constructor
  * @param {Object} engine
  */
function QIcon(engine){return undefined;};

/**
  * @name QIcon^3
  * @constructor
  * @param {QIcon} other
  */
function QIcon(other){return undefined;};

/**
  * @name QIcon^4
  * @constructor
  * @param {QPixmap} pixmap
  */
function QIcon(pixmap){return undefined;};

/**
  * @name QIcon^5
  * @constructor
  * @param {String} fileName
  */
function QIcon(fileName){return undefined;};

/**
  * @name fromTheme
  * @function
  * @memberOf QIcon
  * @param {String} name
  * @param {QIcon} fallback
  * @returns {QIcon}
  */
QIcon.fromTheme = function(name, fallback){return new QIcon();};

/**
  * @name hasThemeIcon
  * @function
  * @memberOf QIcon
  * @param {String} name
  * @returns {Boolean}
  */
QIcon.hasThemeIcon = function(name){return new Boolean();};

/**
  * @name setThemeName
  * @function
  * @memberOf QIcon
  * @param {String} path
  * @returns {undefined}
  */
QIcon.setThemeName = function(path){return undefined;};

/**
  * @name setThemeSearchPaths
  * @function
  * @memberOf QIcon
  * @param {Array} searchpath
  * @returns {undefined}
  */
QIcon.setThemeSearchPaths = function(searchpath){return undefined;};

/**
  * @name themeName
  * @function
  * @memberOf QIcon
  * @returns {String}
  */
QIcon.themeName = function(){return new String();};

/**
  * @name themeSearchPaths
  * @function
  * @memberOf QIcon
  * @returns {Array}
  */
QIcon.themeSearchPaths = function(){return new Array();};

/**
  * @default 0x0
  * @constant
  * @memberOf QIcon
  * @name Normal
  * @see QIcon#Mode
  * @type Number
  */
QIcon.Normal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QIcon
  * @name Disabled
  * @see QIcon#Mode
  * @type Number
  */
QIcon.Disabled = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QIcon
  * @name Active
  * @see QIcon#Mode
  * @type Number
  */
QIcon.Active = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QIcon
  * @name Selected
  * @see QIcon#Mode
  * @type Number
  */
QIcon.Selected = 0x3;

/**
  * @constructor 
  * @memberOf QIcon
  * @name Mode
  */
QIcon.Mode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QIcon
  * @name On
  * @see QIcon#State
  * @type Number
  */
QIcon.On = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QIcon
  * @name Off
  * @see QIcon#State
  * @type Number
  */
QIcon.Off = 0x1;

/**
  * @constructor 
  * @memberOf QIcon
  * @name State
  */
QIcon.State = function(value){;};



/**
  * @name actualSize
  * @function
  * @memberOf QIcon.prototype
  * @param {QSize} size
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {QSize}
  */
QIcon.prototype.actualSize = function(size, mode, state){return new QSize();};

/**
  * @name addFile
  * @function
  * @memberOf QIcon.prototype
  * @param {String} fileName
  * @param {QSize} size
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {undefined}
  */
QIcon.prototype.addFile = function(fileName, size, mode, state){return undefined;};

/**
  * @name addPixmap
  * @function
  * @memberOf QIcon.prototype
  * @param {QPixmap} pixmap
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {undefined}
  */
QIcon.prototype.addPixmap = function(pixmap, mode, state){return undefined;};

/**
  * @name availableSizes
  * @function
  * @memberOf QIcon.prototype
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {Array}
  */
QIcon.prototype.availableSizes = function(mode, state){return new Array();};

/**
  * @name cacheKey
  * @function
  * @memberOf QIcon.prototype
  * @returns {Numeric}
  */
QIcon.prototype.cacheKey = function(){return new Numeric();};

/**
  * @name isNull
  * @function
  * @memberOf QIcon.prototype
  * @returns {Boolean}
  */
QIcon.prototype.isNull = function(){return new Boolean();};

/**
  * @name name
  * @function
  * @memberOf QIcon.prototype
  * @returns {String}
  */
QIcon.prototype.name = function(){return new String();};

/**
  * @name paint
  * @function
  * @memberOf QIcon.prototype
  * @param {QPainter} painter
  * @param {QRect} rect
  * @param {Qt.Alignment} alignment
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {undefined}
  */
QIcon.prototype.paint = function(painter, rect, alignment, mode, state){return undefined;};

/**
  * @name pixmap
  * @function
  * @memberOf QIcon.prototype
  * @param {QSize} size
  * @param {QLCDNumber.Mode} mode
  * @param {QTimeLine.State} state
  * @returns {QPixmap}
  */
QIcon.prototype.pixmap = function(size, mode, state){return new QPixmap();};

/**
  * @name readFrom
  * @function
  * @memberOf QIcon.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QIcon.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name swap
  * @function
  * @memberOf QIcon.prototype
  * @param {QIcon} other
  * @returns {undefined}
  */
QIcon.prototype.swap = function(other){return undefined;};

/**
  * @name writeTo
  * @function
  * @memberOf QIcon.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QIcon.prototype.writeTo = function(arg__1){return undefined;};

