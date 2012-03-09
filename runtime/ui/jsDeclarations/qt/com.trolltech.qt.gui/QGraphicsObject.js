/**
  * @name QGraphicsObject
  * @constructor
  * @extends QObject
  * @param {QGraphicsItem} parent
  */
function QGraphicsObject(parent){return undefined;};

QGraphicsObject.prototype = new QObject();

/**
  * @name grabGesture
  * @function
  * @memberOf QGraphicsObject.prototype
  * @param {Qt.GestureType} type
  * @param {Qt.GestureFlags} flags
  * @returns {undefined}
  */
QGraphicsObject.prototype.grabGesture = function(type, flags){return undefined;};

/**
  * @name ungrabGesture
  * @function
  * @memberOf QGraphicsObject.prototype
  * @param {Qt.GestureType} type
  * @returns {undefined}
  */
QGraphicsObject.prototype.ungrabGesture = function(type){return undefined;};

/**
  * @name *
  * @memberOf QGraphicsObject.prototype
  * @type QGraphicsObject
  */
QGraphicsObject.prototype['*'] = new QGraphicsObject();

/**
  * @name opacity
  * @memberOf QGraphicsObject.prototype
  * @type Numeric
  */
QGraphicsObject.prototype.opacity = new Numeric();

/**
  * @name enabled
  * @memberOf QGraphicsObject.prototype
  * @type Boolean
  */
QGraphicsObject.prototype.enabled = new Boolean();

/**
  * @name visible
  * @memberOf QGraphicsObject.prototype
  * @type Boolean
  */
QGraphicsObject.prototype.visible = new Boolean();

/**
  * @name pos
  * @memberOf QGraphicsObject.prototype
  * @type QPointF
  */
QGraphicsObject.prototype.pos = new QPointF();

/**
  * @name x
  * @memberOf QGraphicsObject.prototype
  * @type Numeric
  */
QGraphicsObject.prototype.x = new Numeric();

/**
  * @name y
  * @memberOf QGraphicsObject.prototype
  * @type Numeric
  */
QGraphicsObject.prototype.y = new Numeric();

/**
  * @name z
  * @memberOf QGraphicsObject.prototype
  * @type Numeric
  */
QGraphicsObject.prototype.z = new Numeric();

/**
  * @name rotation
  * @memberOf QGraphicsObject.prototype
  * @type Numeric
  */
QGraphicsObject.prototype.rotation = new Numeric();

/**
  * @name scale
  * @memberOf QGraphicsObject.prototype
  * @type Numeric
  */
QGraphicsObject.prototype.scale = new Numeric();

/**
  * @name transformOriginPoint
  * @memberOf QGraphicsObject.prototype
  * @type QPointF
  */
QGraphicsObject.prototype.transformOriginPoint = new QPointF();

/**
  * @name *effect
  * @memberOf QGraphicsObject.prototype
  * @type QGraphicsEffect
  */
QGraphicsObject.prototype['*effect'] = new QGraphicsEffect();


