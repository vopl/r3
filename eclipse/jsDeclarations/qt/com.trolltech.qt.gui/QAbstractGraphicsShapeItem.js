/**
  * @name QAbstractGraphicsShapeItem
  * @constructor
  * @extends QGraphicsItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QAbstractGraphicsShapeItem(parent, scene){return undefined;};

/**
  * @name brush
  * @function
  * @memberOf QAbstractGraphicsShapeItem.prototype
  * @returns {QBrush}
  */
QAbstractGraphicsShapeItem.prototype.brush = function(){return new QBrush();};

/**
  * @name pen
  * @function
  * @memberOf QAbstractGraphicsShapeItem.prototype
  * @returns {QPen}
  */
QAbstractGraphicsShapeItem.prototype.pen = function(){return new QPen();};

/**
  * @name setBrush
  * @function
  * @memberOf QAbstractGraphicsShapeItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QAbstractGraphicsShapeItem.prototype.setBrush = function(brush){return undefined;};

/**
  * @name setPen
  * @function
  * @memberOf QAbstractGraphicsShapeItem.prototype
  * @param {QPen} pen
  * @returns {undefined}
  */
QAbstractGraphicsShapeItem.prototype.setPen = function(pen){return undefined;};

