/**
  * @name QGesture
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QGesture(parent){return undefined;};

QGesture.prototype = new QObject();

/**
  * @default 0
  * @constant
  * @memberOf QGesture
  * @name CancelNone
  * @see QGesture#GestureCancelPolicy
  * @type Number
  */
QGesture.CancelNone = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGesture
  * @name CancelAllInContext
  * @see QGesture#GestureCancelPolicy
  * @type Number
  */
QGesture.CancelAllInContext = 0x1;

/**
  * @constructor 
  * @memberOf QGesture
  * @name GestureCancelPolicy
  */
QGesture.GestureCancelPolicy = function(value){;};



/**
  * @name unsetHotSpot
  * @function
  * @memberOf QGesture.prototype
  * @returns {undefined}
  */
QGesture.prototype.unsetHotSpot = function(){return undefined;};

/**
  * @name state
  * @memberOf QGesture.prototype
  * @type Qt.GestureState
  */
QGesture.prototype.state = new Qt.GestureState();

/**
  * @name gestureType
  * @memberOf QGesture.prototype
  * @type Qt.GestureType
  */
QGesture.prototype.gestureType = new Qt.GestureType();

/**
  * @name gestureCancelPolicy
  * @memberOf QGesture.prototype
  * @type QGesture.GestureCancelPolicy
  */
QGesture.prototype.gestureCancelPolicy = new QGesture.GestureCancelPolicy();

/**
  * @name hotSpot
  * @memberOf QGesture.prototype
  * @type QPointF
  */
QGesture.prototype.hotSpot = new QPointF();

/**
  * @name hasHotSpot
  * @memberOf QGesture.prototype
  * @type Boolean
  */
QGesture.prototype.hasHotSpot = new Boolean();


