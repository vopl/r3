/**
  * @name QPanGesture
  * @constructor
  * @extends QGesture
  * @param {QObject} parent
  */
function QPanGesture(parent){return undefined;};

QPanGesture.prototype = new QGesture();

/**
  * @name lastOffset
  * @memberOf QPanGesture.prototype
  * @type QPointF
  */
QPanGesture.prototype.lastOffset = new QPointF();

/**
  * @name offset
  * @memberOf QPanGesture.prototype
  * @type QPointF
  */
QPanGesture.prototype.offset = new QPointF();

/**
  * @name delta
  * @memberOf QPanGesture.prototype
  * @type QPointF
  */
QPanGesture.prototype.delta = new QPointF();

/**
  * @name acceleration
  * @memberOf QPanGesture.prototype
  * @type Numeric
  */
QPanGesture.prototype.acceleration = new Numeric();


