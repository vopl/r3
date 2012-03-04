/**
  * @name QGraphicsEffect
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QGraphicsEffect(parent){return undefined;};

QGraphicsEffect.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsEffect
  * @name NoPad
  * @see QGraphicsEffect#PixmapPadMode
  * @type Number
  */
QGraphicsEffect.NoPad = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsEffect
  * @name PadToTransparentBorder
  * @see QGraphicsEffect#PixmapPadMode
  * @type Number
  */
QGraphicsEffect.PadToTransparentBorder = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsEffect
  * @name PadToEffectiveBoundingRect
  * @see QGraphicsEffect#PixmapPadMode
  * @type Number
  */
QGraphicsEffect.PadToEffectiveBoundingRect = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsEffect
  * @name PixmapPadMode
  */
QGraphicsEffect.PixmapPadMode = function(value){;};



/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsEffect
  * @name SourceAttached
  * @see QGraphicsEffect#ChangeFlags
  * @see QGraphicsEffect#ChangeFlag
  * @type Number
  */
QGraphicsEffect.SourceAttached = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsEffect
  * @name SourceDetached
  * @see QGraphicsEffect#ChangeFlags
  * @see QGraphicsEffect#ChangeFlag
  * @type Number
  */
QGraphicsEffect.SourceDetached = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QGraphicsEffect
  * @name SourceBoundingRectChanged
  * @see QGraphicsEffect#ChangeFlags
  * @see QGraphicsEffect#ChangeFlag
  * @type Number
  */
QGraphicsEffect.SourceBoundingRectChanged = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QGraphicsEffect
  * @name SourceInvalidated
  * @see QGraphicsEffect#ChangeFlags
  * @see QGraphicsEffect#ChangeFlag
  * @type Number
  */
QGraphicsEffect.SourceInvalidated = 0x8;

/**
  * @constructor 
  * @memberOf QGraphicsEffect
  * @name ChangeFlag
  */
QGraphicsEffect.ChangeFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QGraphicsEffect
  * @name ChangeFlags
  */
QGraphicsEffect.ChangeFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name boundingRect
  * @function
  * @memberOf QGraphicsEffect.prototype
  * @returns {QRectF}
  */
QGraphicsEffect.prototype.boundingRect = function(){return new QRectF();};

/**
  * @name boundingRectFor
  * @function
  * @memberOf QGraphicsEffect.prototype
  * @param {QRectF} sourceRect
  * @returns {QRectF}
  */
QGraphicsEffect.prototype.boundingRectFor = function(sourceRect){return new QRectF();};

/**
  * @name source
  * @function
  * @memberOf QGraphicsEffect.prototype
  * @returns {Object}
  */
QGraphicsEffect.prototype.source = function(){return new Object();};

/**
  * @name enabled
  * @memberOf QGraphicsEffect.prototype
  * @type Boolean
  */
QGraphicsEffect.prototype.enabled = new Boolean();


