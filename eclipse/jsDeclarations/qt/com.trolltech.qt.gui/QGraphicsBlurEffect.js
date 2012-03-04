/**
  * @name QGraphicsBlurEffect
  * @constructor
  * @extends QGraphicsEffect
  * @param {QObject} parent
  */
function QGraphicsBlurEffect(parent){return undefined;};

QGraphicsBlurEffect.prototype = new QGraphicsEffect();

/**
  * @default 0x00
  * @constant
  * @memberOf QGraphicsBlurEffect
  * @name PerformanceHint
  * @see QGraphicsBlurEffect#BlurHints
  * @see QGraphicsBlurEffect#BlurHint
  * @type Number
  */
QGraphicsBlurEffect.PerformanceHint = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QGraphicsBlurEffect
  * @name QualityHint
  * @see QGraphicsBlurEffect#BlurHints
  * @see QGraphicsBlurEffect#BlurHint
  * @type Number
  */
QGraphicsBlurEffect.QualityHint = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QGraphicsBlurEffect
  * @name AnimationHint
  * @see QGraphicsBlurEffect#BlurHints
  * @see QGraphicsBlurEffect#BlurHint
  * @type Number
  */
QGraphicsBlurEffect.AnimationHint = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsBlurEffect
  * @name BlurHint
  */
QGraphicsBlurEffect.BlurHint = function(value){;};

/**
  * @constructor 
  * @memberOf QGraphicsBlurEffect
  * @name BlurHints
  */
QGraphicsBlurEffect.BlurHints = function(value1, value2 /*, ...*/){;};


/**
  * @name blurRadius
  * @memberOf QGraphicsBlurEffect.prototype
  * @type Numeric
  */
QGraphicsBlurEffect.prototype.blurRadius = new Numeric();

/**
  * @name blurHints
  * @memberOf QGraphicsBlurEffect.prototype
  * @type QGraphicsBlurEffect.BlurHints
  */
QGraphicsBlurEffect.prototype.blurHints = new QGraphicsBlurEffect.BlurHints();


