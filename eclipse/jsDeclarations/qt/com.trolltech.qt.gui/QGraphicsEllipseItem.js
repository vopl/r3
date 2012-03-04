/**
  * @name QGraphicsEllipseItem
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsEllipseItem(parent, scene){return undefined;};

/**
  * @name QGraphicsEllipseItem^1
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QRectF} rect
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsEllipseItem(rect, parent, scene){return undefined;};

/**
  * @name QGraphicsEllipseItem^2
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsEllipseItem(x, y, w, h, parent, scene){return undefined;};

QGraphicsEllipseItem.prototype = new QAbstractGraphicsShapeItem();

/**
  * @name rect
  * @function
  * @memberOf QGraphicsEllipseItem.prototype
  * @returns {QRectF}
  */
QGraphicsEllipseItem.prototype.rect = function(){return new QRectF();};

/**
  * @name setRect
  * @function
  * @memberOf QGraphicsEllipseItem.prototype
  * @param {QRectF} rect
  * @returns {undefined}
  */
QGraphicsEllipseItem.prototype.setRect = function(rect){return undefined;};

/**
  * @name setSpanAngle
  * @function
  * @memberOf QGraphicsEllipseItem.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QGraphicsEllipseItem.prototype.setSpanAngle = function(angle){return undefined;};

/**
  * @name setStartAngle
  * @function
  * @memberOf QGraphicsEllipseItem.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QGraphicsEllipseItem.prototype.setStartAngle = function(angle){return undefined;};

/**
  * @name spanAngle
  * @function
  * @memberOf QGraphicsEllipseItem.prototype
  * @returns {Numeric}
  */
QGraphicsEllipseItem.prototype.spanAngle = function(){return new Numeric();};

/**
  * @name startAngle
  * @function
  * @memberOf QGraphicsEllipseItem.prototype
  * @returns {Numeric}
  */
QGraphicsEllipseItem.prototype.startAngle = function(){return new Numeric();};

