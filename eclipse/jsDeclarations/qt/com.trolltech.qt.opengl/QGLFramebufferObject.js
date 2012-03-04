/**
  * @name QGLFramebufferObject
  * @constructor
  * @extends QPaintDevice
  * @param {QSize} size
  * @param {QGLFramebufferObjectFormat} format
  */
function QGLFramebufferObject(size, format){return undefined;};

/**
  * @name QGLFramebufferObject^1
  * @constructor
  * @extends QPaintDevice
  * @param {Numeric} width
  * @param {Numeric} height
  * @param {QGLFramebufferObjectFormat} format
  */
function QGLFramebufferObject(width, height, format){return undefined;};

/**
  * @name bindDefault
  * @function
  * @memberOf QGLFramebufferObject
  * @returns {Boolean}
  */
QGLFramebufferObject.bindDefault = function(){return new Boolean();};

/**
  * @name hasOpenGLFramebufferBlit
  * @function
  * @memberOf QGLFramebufferObject
  * @returns {Boolean}
  */
QGLFramebufferObject.hasOpenGLFramebufferBlit = function(){return new Boolean();};

/**
  * @name hasOpenGLFramebufferObjects
  * @function
  * @memberOf QGLFramebufferObject
  * @returns {Boolean}
  */
QGLFramebufferObject.hasOpenGLFramebufferObjects = function(){return new Boolean();};

/**
  * @default 0x0
  * @constant
  * @memberOf QGLFramebufferObject
  * @name NoAttachment
  * @see QGLFramebufferObject#Attachment
  * @type Number
  */
QGLFramebufferObject.NoAttachment = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGLFramebufferObject
  * @name CombinedDepthStencil
  * @see QGLFramebufferObject#Attachment
  * @type Number
  */
QGLFramebufferObject.CombinedDepthStencil = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGLFramebufferObject
  * @name Depth
  * @see QGLFramebufferObject#Attachment
  * @type Number
  */
QGLFramebufferObject.Depth = 0x2;

/**
  * @constructor 
  * @memberOf QGLFramebufferObject
  * @name Attachment
  */
QGLFramebufferObject.Attachment = function(value){;};



/**
  * @name attachment
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {QGLFramebufferObject.Attachment}
  */
QGLFramebufferObject.prototype.attachment = function(){return new QGLFramebufferObject.Attachment();};

/**
  * @name bind
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {Boolean}
  */
QGLFramebufferObject.prototype.bind = function(){return new Boolean();};

/**
  * @name format
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {QGLFramebufferObjectFormat}
  */
QGLFramebufferObject.prototype.format = function(){return new QGLFramebufferObjectFormat();};

/**
  * @name isBound
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {Boolean}
  */
QGLFramebufferObject.prototype.isBound = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {Boolean}
  */
QGLFramebufferObject.prototype.isValid = function(){return new Boolean();};

/**
  * @name release
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {Boolean}
  */
QGLFramebufferObject.prototype.release = function(){return new Boolean();};

/**
  * @name size
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {QSize}
  */
QGLFramebufferObject.prototype.size = function(){return new QSize();};

/**
  * @name toImage
  * @function
  * @memberOf QGLFramebufferObject.prototype
  * @returns {QImage}
  */
QGLFramebufferObject.prototype.toImage = function(){return new QImage();};

