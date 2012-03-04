/**
  * @name QGraphicsScale
  * @constructor
  * @extends QGraphicsTransform
  * @param {QObject} parent
  */
function QGraphicsScale(parent){return undefined;};

QGraphicsScale.prototype = new QGraphicsTransform();

/**
  * @name origin
  * @memberOf QGraphicsScale.prototype
  * @type QVector3D
  */
QGraphicsScale.prototype.origin = new QVector3D();

/**
  * @name xScale
  * @memberOf QGraphicsScale.prototype
  * @type Numeric
  */
QGraphicsScale.prototype.xScale = new Numeric();

/**
  * @name yScale
  * @memberOf QGraphicsScale.prototype
  * @type Numeric
  */
QGraphicsScale.prototype.yScale = new Numeric();

/**
  * @name zScale
  * @memberOf QGraphicsScale.prototype
  * @type Numeric
  */
QGraphicsScale.prototype.zScale = new Numeric();


