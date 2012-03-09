/**
  * @name QGraphicsRotation
  * @constructor
  * @extends QGraphicsTransform
  * @param {QObject} parent
  */
function QGraphicsRotation(parent){return undefined;};

QGraphicsRotation.prototype = new QGraphicsTransform();

/**
  * @name setAxis
  * @function
  * @memberOf QGraphicsRotation.prototype
  * @param {Qt.Axis} axis
  * @returns {undefined}
  */
QGraphicsRotation.prototype.setAxis = function(axis){return undefined;};

/**
  * @name origin
  * @memberOf QGraphicsRotation.prototype
  * @type QVector3D
  */
QGraphicsRotation.prototype.origin = new QVector3D();

/**
  * @name angle
  * @memberOf QGraphicsRotation.prototype
  * @type Numeric
  */
QGraphicsRotation.prototype.angle = new Numeric();

/**
  * @name axis
  * @memberOf QGraphicsRotation.prototype
  * @type QVector3D
  */
QGraphicsRotation.prototype.axis = new QVector3D();


