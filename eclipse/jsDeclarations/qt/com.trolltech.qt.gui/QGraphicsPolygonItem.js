/**
  * @name QGraphicsPolygonItem
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsPolygonItem(parent, scene){return undefined;};

/**
  * @name QGraphicsPolygonItem^1
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QPolygonF} polygon
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsPolygonItem(polygon, parent, scene){return undefined;};

QGraphicsPolygonItem.prototype = new QAbstractGraphicsShapeItem();

/**
  * @name fillRule
  * @function
  * @memberOf QGraphicsPolygonItem.prototype
  * @returns {Qt.FillRule}
  */
QGraphicsPolygonItem.prototype.fillRule = function(){return new Qt.FillRule();};

/**
  * @name polygon
  * @function
  * @memberOf QGraphicsPolygonItem.prototype
  * @returns {QPolygonF}
  */
QGraphicsPolygonItem.prototype.polygon = function(){return new QPolygonF();};

/**
  * @name setFillRule
  * @function
  * @memberOf QGraphicsPolygonItem.prototype
  * @param {Qt.FillRule} rule
  * @returns {undefined}
  */
QGraphicsPolygonItem.prototype.setFillRule = function(rule){return undefined;};

/**
  * @name setPolygon
  * @function
  * @memberOf QGraphicsPolygonItem.prototype
  * @param {QPolygonF} polygon
  * @returns {undefined}
  */
QGraphicsPolygonItem.prototype.setPolygon = function(polygon){return undefined;};

