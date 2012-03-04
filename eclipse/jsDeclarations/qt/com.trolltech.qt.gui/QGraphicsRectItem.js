/**
  * @name QGraphicsRectItem
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsRectItem(parent, scene){return undefined;};

/**
  * @name QGraphicsRectItem^1
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QRectF} rect
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsRectItem(rect, parent, scene){return undefined;};

/**
  * @name QGraphicsRectItem^2
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsRectItem(x, y, w, h, parent, scene){return undefined;};

QGraphicsRectItem.prototype = new QAbstractGraphicsShapeItem();

/**
  * @name rect
  * @function
  * @memberOf QGraphicsRectItem.prototype
  * @returns {QRectF}
  */
QGraphicsRectItem.prototype.rect = function(){return new QRectF();};

/**
  * @name setRect
  * @function
  * @memberOf QGraphicsRectItem.prototype
  * @param {QRectF} rect
  * @returns {undefined}
  */
QGraphicsRectItem.prototype.setRect = function(rect){return undefined;};

