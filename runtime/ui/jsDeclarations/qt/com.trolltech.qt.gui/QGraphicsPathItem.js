/**
  * @name QGraphicsPathItem
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsPathItem(parent, scene){return undefined;};

/**
  * @name QGraphicsPathItem^1
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QPainterPath} path
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsPathItem(path, parent, scene){return undefined;};

QGraphicsPathItem.prototype = new QAbstractGraphicsShapeItem();

/**
  * @name path
  * @function
  * @memberOf QGraphicsPathItem.prototype
  * @returns {QPainterPath}
  */
QGraphicsPathItem.prototype.path = function(){return new QPainterPath();};

/**
  * @name setPath
  * @function
  * @memberOf QGraphicsPathItem.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QGraphicsPathItem.prototype.setPath = function(path){return undefined;};

