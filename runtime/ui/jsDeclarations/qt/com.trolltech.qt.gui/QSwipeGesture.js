/**
  * @name QSwipeGesture
  * @constructor
  * @extends QGesture
  * @param {QObject} parent
  */
function QSwipeGesture(parent){return undefined;};

QSwipeGesture.prototype = new QGesture();

/**
  * @default 0x0
  * @constant
  * @memberOf QSwipeGesture
  * @name NoDirection
  * @see QSwipeGesture#SwipeDirection
  * @type Number
  */
QSwipeGesture.NoDirection = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSwipeGesture
  * @name Left
  * @see QSwipeGesture#SwipeDirection
  * @type Number
  */
QSwipeGesture.Left = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSwipeGesture
  * @name Right
  * @see QSwipeGesture#SwipeDirection
  * @type Number
  */
QSwipeGesture.Right = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSwipeGesture
  * @name Up
  * @see QSwipeGesture#SwipeDirection
  * @type Number
  */
QSwipeGesture.Up = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSwipeGesture
  * @name Down
  * @see QSwipeGesture#SwipeDirection
  * @type Number
  */
QSwipeGesture.Down = 0x4;

/**
  * @constructor 
  * @memberOf QSwipeGesture
  * @name SwipeDirection
  */
QSwipeGesture.SwipeDirection = function(value){;};



/**
  * @name horizontalDirection
  * @memberOf QSwipeGesture.prototype
  * @type QSwipeGesture.SwipeDirection
  */
QSwipeGesture.prototype.horizontalDirection = new QSwipeGesture.SwipeDirection();

/**
  * @name verticalDirection
  * @memberOf QSwipeGesture.prototype
  * @type QSwipeGesture.SwipeDirection
  */
QSwipeGesture.prototype.verticalDirection = new QSwipeGesture.SwipeDirection();

/**
  * @name swipeAngle
  * @memberOf QSwipeGesture.prototype
  * @type Numeric
  */
QSwipeGesture.prototype.swipeAngle = new Numeric();


