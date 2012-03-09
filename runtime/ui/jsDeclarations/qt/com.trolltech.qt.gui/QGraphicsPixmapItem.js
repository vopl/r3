/**
  * @name QGraphicsPixmapItem
  * @constructor
  * @extends QGraphicsItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsPixmapItem(parent, scene){return undefined;};

/**
  * @name QGraphicsPixmapItem^1
  * @constructor
  * @extends QGraphicsItem
  * @param {QPixmap} pixmap
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsPixmapItem(pixmap, parent, scene){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsPixmapItem
  * @name MaskShape
  * @see QGraphicsPixmapItem#ShapeMode
  * @type Number
  */
QGraphicsPixmapItem.MaskShape = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsPixmapItem
  * @name BoundingRectShape
  * @see QGraphicsPixmapItem#ShapeMode
  * @type Number
  */
QGraphicsPixmapItem.BoundingRectShape = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsPixmapItem
  * @name HeuristicMaskShape
  * @see QGraphicsPixmapItem#ShapeMode
  * @type Number
  */
QGraphicsPixmapItem.HeuristicMaskShape = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsPixmapItem
  * @name ShapeMode
  */
QGraphicsPixmapItem.ShapeMode = function(value){;};



/**
  * @name offset
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @returns {QPointF}
  */
QGraphicsPixmapItem.prototype.offset = function(){return new QPointF();};

/**
  * @name pixmap
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @returns {QPixmap}
  */
QGraphicsPixmapItem.prototype.pixmap = function(){return new QPixmap();};

/**
  * @name setOffset
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @param {QPointF} offset
  * @returns {undefined}
  */
QGraphicsPixmapItem.prototype.setOffset = function(offset){return undefined;};

/**
  * @name setPixmap
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @param {QPixmap} pixmap
  * @returns {undefined}
  */
QGraphicsPixmapItem.prototype.setPixmap = function(pixmap){return undefined;};

/**
  * @name setShapeMode
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @param {QGraphicsPixmapItem.ShapeMode} mode
  * @returns {undefined}
  */
QGraphicsPixmapItem.prototype.setShapeMode = function(mode){return undefined;};

/**
  * @name setTransformationMode
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @param {Qt.TransformationMode} mode
  * @returns {undefined}
  */
QGraphicsPixmapItem.prototype.setTransformationMode = function(mode){return undefined;};

/**
  * @name shapeMode
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @returns {QGraphicsPixmapItem.ShapeMode}
  */
QGraphicsPixmapItem.prototype.shapeMode = function(){return new QGraphicsPixmapItem.ShapeMode();};

/**
  * @name transformationMode
  * @function
  * @memberOf QGraphicsPixmapItem.prototype
  * @returns {Qt.TransformationMode}
  */
QGraphicsPixmapItem.prototype.transformationMode = function(){return new Qt.TransformationMode();};

