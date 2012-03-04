/**
  * @name QGLContext
  * @constructor
  * @param {Object} format
  */
function QGLContext(format){return undefined;};

/**
  * @name QGLContext^1
  * @constructor
  * @param {Object} format
  * @param {QPaintDevice} device
  */
function QGLContext(format, device){return undefined;};

/**
  * @name areSharing
  * @function
  * @memberOf QGLContext
  * @param {QGLContext} context1
  * @param {QGLContext} context2
  * @returns {Boolean}
  */
QGLContext.areSharing = function(context1, context2){return new Boolean();};

/**
  * @name currentContext
  * @function
  * @memberOf QGLContext
  * @returns {QGLContext}
  */
QGLContext.currentContext = function(){return new QGLContext();};

/**
  * @name setTextureCacheLimit
  * @function
  * @memberOf QGLContext
  * @param {Numeric} size
  * @returns {undefined}
  */
QGLContext.setTextureCacheLimit = function(size){return undefined;};

/**
  * @name textureCacheLimit
  * @function
  * @memberOf QGLContext
  * @returns {Numeric}
  */
QGLContext.textureCacheLimit = function(){return new Numeric();};

/**
  * @default 0x0000
  * @constant
  * @memberOf QGLContext
  * @name NoBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.NoBindOption = 0x0;

/**
  * @default 0x0001
  * @constant
  * @memberOf QGLContext
  * @name InvertedYBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.InvertedYBindOption = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QGLContext
  * @name MipmapBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.MipmapBindOption = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QGLContext
  * @name PremultipliedAlphaBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.PremultipliedAlphaBindOption = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QGLContext
  * @name LinearFilteringBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.LinearFilteringBindOption = 0x8;

/**
  * @default LinearFilteringBindOption|InvertedYBindOption|MipmapBindOption
  * @constant
  * @memberOf QGLContext
  * @name DefaultBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.DefaultBindOption = 0xb;

/**
  * @default 0x0010
  * @constant
  * @memberOf QGLContext
  * @name MemoryManagedBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.MemoryManagedBindOption = 0x10;

/**
  * @default MemoryManagedBindOption|PremultipliedAlphaBindOption
  * @constant
  * @memberOf QGLContext
  * @name InternalBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.InternalBindOption = 0x14;

/**
  * @default 0x0020
  * @constant
  * @memberOf QGLContext
  * @name CanFlipNativePixmapBindOption
  * @see QGLContext#BindOptions
  * @see QGLContext#BindOption
  * @type Number
  */
QGLContext.CanFlipNativePixmapBindOption = 0x20;

/**
  * @constructor 
  * @memberOf QGLContext
  * @name BindOption
  */
QGLContext.BindOption = function(value){;};

/**
  * @constructor 
  * @memberOf QGLContext
  * @name BindOptions
  */
QGLContext.BindOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name create
  * @function
  * @memberOf QGLContext.prototype
  * @param {QGLContext} shareContext
  * @returns {Boolean}
  */
QGLContext.prototype.create = function(shareContext){return new Boolean();};

/**
  * @name device
  * @function
  * @memberOf QGLContext.prototype
  * @returns {QPaintDevice}
  */
QGLContext.prototype.device = function(){return new QPaintDevice();};

/**
  * @name doneCurrent
  * @function
  * @memberOf QGLContext.prototype
  * @returns {undefined}
  */
QGLContext.prototype.doneCurrent = function(){return undefined;};

/**
  * @name format
  * @function
  * @memberOf QGLContext.prototype
  * @returns {Object}
  */
QGLContext.prototype.format = function(){return new Object();};

/**
  * @name isSharing
  * @function
  * @memberOf QGLContext.prototype
  * @returns {Boolean}
  */
QGLContext.prototype.isSharing = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QGLContext.prototype
  * @returns {Boolean}
  */
QGLContext.prototype.isValid = function(){return new Boolean();};

/**
  * @name makeCurrent
  * @function
  * @memberOf QGLContext.prototype
  * @returns {undefined}
  */
QGLContext.prototype.makeCurrent = function(){return undefined;};

/**
  * @name overlayTransparentColor
  * @function
  * @memberOf QGLContext.prototype
  * @returns {QColor}
  */
QGLContext.prototype.overlayTransparentColor = function(){return new QColor();};

/**
  * @name requestedFormat
  * @function
  * @memberOf QGLContext.prototype
  * @returns {Object}
  */
QGLContext.prototype.requestedFormat = function(){return new Object();};

/**
  * @name reset
  * @function
  * @memberOf QGLContext.prototype
  * @returns {undefined}
  */
QGLContext.prototype.reset = function(){return undefined;};

/**
  * @name setFormat
  * @function
  * @memberOf QGLContext.prototype
  * @param {Object} format
  * @returns {undefined}
  */
QGLContext.prototype.setFormat = function(format){return undefined;};

/**
  * @name swapBuffers
  * @function
  * @memberOf QGLContext.prototype
  * @returns {undefined}
  */
QGLContext.prototype.swapBuffers = function(){return undefined;};

