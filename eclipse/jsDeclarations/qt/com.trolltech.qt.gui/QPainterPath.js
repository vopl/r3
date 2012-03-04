/**
  * @name QPainterPath
  * @constructor
  */
function QPainterPath(){return undefined;};

/**
  * @name QPainterPath^1
  * @constructor
  * @param {QPainterPath} other
  */
function QPainterPath(other){return undefined;};

/**
  * @name QPainterPath^2
  * @constructor
  * @param {QPointF} startPoint
  */
function QPainterPath(startPoint){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QPainterPath
  * @name MoveToElement
  * @see QPainterPath#ElementType
  * @type Number
  */
QPainterPath.MoveToElement = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPainterPath
  * @name LineToElement
  * @see QPainterPath#ElementType
  * @type Number
  */
QPainterPath.LineToElement = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPainterPath
  * @name CurveToElement
  * @see QPainterPath#ElementType
  * @type Number
  */
QPainterPath.CurveToElement = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPainterPath
  * @name CurveToDataElement
  * @see QPainterPath#ElementType
  * @type Number
  */
QPainterPath.CurveToDataElement = 0x3;

/**
  * @constructor 
  * @memberOf QPainterPath
  * @name ElementType
  */
QPainterPath.ElementType = function(value){;};



/**
  * @name addEllipse
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} center
  * @param {Numeric} rx
  * @param {Numeric} ry
  * @returns {undefined}
  */
QPainterPath.prototype.addEllipse = function(center, rx, ry){return undefined;};

/**
  * @name addPath
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QPainterPath.prototype.addPath = function(path){return undefined;};

/**
  * @name addPolygon
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPolygonF} polygon
  * @returns {undefined}
  */
QPainterPath.prototype.addPolygon = function(polygon){return undefined;};

/**
  * @name addRect
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QRectF} rect
  * @returns {undefined}
  */
QPainterPath.prototype.addRect = function(rect){return undefined;};

/**
  * @name addRegion
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QRegion} region
  * @returns {undefined}
  */
QPainterPath.prototype.addRegion = function(region){return undefined;};

/**
  * @name addRoundRect
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QRectF} rect
  * @param {Numeric} roundness
  * @returns {undefined}
  */
QPainterPath.prototype.addRoundRect = function(rect, roundness){return undefined;};

/**
  * @name addRoundedRect
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QRectF} rect
  * @param {Numeric} xRadius
  * @param {Numeric} yRadius
  * @param {Qt.SizeMode} mode
  * @returns {undefined}
  */
QPainterPath.prototype.addRoundedRect = function(rect, xRadius, yRadius, mode){return undefined;};

/**
  * @name addText
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} point
  * @param {QFont} f
  * @param {String} text
  * @returns {undefined}
  */
QPainterPath.prototype.addText = function(point, f, text){return undefined;};

/**
  * @name angleAtPercent
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Numeric} t
  * @returns {Numeric}
  */
QPainterPath.prototype.angleAtPercent = function(t){return new Numeric();};

/**
  * @name arcMoveTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QRectF} rect
  * @param {Numeric} angle
  * @returns {undefined}
  */
QPainterPath.prototype.arcMoveTo = function(rect, angle){return undefined;};

/**
  * @name arcTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QRectF} rect
  * @param {Numeric} startAngle
  * @param {Numeric} arcLength
  * @returns {undefined}
  */
QPainterPath.prototype.arcTo = function(rect, startAngle, arcLength){return undefined;};

/**
  * @name boundingRect
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {QRectF}
  */
QPainterPath.prototype.boundingRect = function(){return new QRectF();};

/**
  * @name closeSubpath
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {undefined}
  */
QPainterPath.prototype.closeSubpath = function(){return undefined;};

/**
  * @name connectPath
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QPainterPath.prototype.connectPath = function(path){return undefined;};

/**
  * @name contains
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} p
  * @returns {Boolean}
  */
QPainterPath.prototype.contains = function(p){return new Boolean();};

/**
  * @name controlPointRect
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {QRectF}
  */
QPainterPath.prototype.controlPointRect = function(){return new QRectF();};

/**
  * @name cubicTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} ctrlPt1
  * @param {QPointF} ctrlPt2
  * @param {QPointF} endPt
  * @returns {undefined}
  */
QPainterPath.prototype.cubicTo = function(ctrlPt1, ctrlPt2, endPt){return undefined;};

/**
  * @name currentPosition
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {QPointF}
  */
QPainterPath.prototype.currentPosition = function(){return new QPointF();};

/**
  * @name elementAt
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Numeric} i
  * @returns {Object}
  */
QPainterPath.prototype.elementAt = function(i){return new Object();};

/**
  * @name elementCount
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {Numeric}
  */
QPainterPath.prototype.elementCount = function(){return new Numeric();};

/**
  * @name fillRule
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {Qt.FillRule}
  */
QPainterPath.prototype.fillRule = function(){return new Qt.FillRule();};

/**
  * @name intersected
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} r
  * @returns {QPainterPath}
  */
QPainterPath.prototype.intersected = function(r){return new QPainterPath();};

/**
  * @name intersects
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} p
  * @returns {Boolean}
  */
QPainterPath.prototype.intersects = function(p){return new Boolean();};

/**
  * @name isEmpty
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {Boolean}
  */
QPainterPath.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name length
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {Numeric}
  */
QPainterPath.prototype.length = function(){return new Numeric();};

/**
  * @name lineTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} p
  * @returns {undefined}
  */
QPainterPath.prototype.lineTo = function(p){return undefined;};

/**
  * @name moveTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} p
  * @returns {undefined}
  */
QPainterPath.prototype.moveTo = function(p){return undefined;};

/**
  * @name operator_add
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_add = function(other){return new QPainterPath();};

/**
  * @name operator_add_assign
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_add_assign = function(other){return new QPainterPath();};

/**
  * @name operator_and
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_and = function(other){return new QPainterPath();};

/**
  * @name operator_and_assign
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_and_assign = function(other){return new QPainterPath();};

/**
  * @name operator_equal
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {Boolean}
  */
QPainterPath.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name operator_or
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_or = function(other){return new QPainterPath();};

/**
  * @name operator_or_assign
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_or_assign = function(other){return new QPainterPath();};

/**
  * @name operator_subtract
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_subtract = function(other){return new QPainterPath();};

/**
  * @name operator_subtract_assign
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {QPainterPath}
  */
QPainterPath.prototype.operator_subtract_assign = function(other){return new QPainterPath();};

/**
  * @name percentAtLength
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Numeric} t
  * @returns {Numeric}
  */
QPainterPath.prototype.percentAtLength = function(t){return new Numeric();};

/**
  * @name pointAtPercent
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Numeric} t
  * @returns {QPointF}
  */
QPainterPath.prototype.pointAtPercent = function(t){return new QPointF();};

/**
  * @name quadTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} ctrlPt
  * @param {QPointF} endPt
  * @returns {undefined}
  */
QPainterPath.prototype.quadTo = function(ctrlPt, endPt){return undefined;};

/**
  * @name readFrom
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QPainterPath.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setElementPositionAt
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Numeric} i
  * @param {Numeric} x
  * @param {Numeric} y
  * @returns {undefined}
  */
QPainterPath.prototype.setElementPositionAt = function(i, x, y){return undefined;};

/**
  * @name setFillRule
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Qt.FillRule} fillRule
  * @returns {undefined}
  */
QPainterPath.prototype.setFillRule = function(fillRule){return undefined;};

/**
  * @name simplified
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {QPainterPath}
  */
QPainterPath.prototype.simplified = function(){return new QPainterPath();};

/**
  * @name slopeAtPercent
  * @function
  * @memberOf QPainterPath.prototype
  * @param {Numeric} t
  * @returns {Numeric}
  */
QPainterPath.prototype.slopeAtPercent = function(t){return new Numeric();};

/**
  * @name subtracted
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} r
  * @returns {QPainterPath}
  */
QPainterPath.prototype.subtracted = function(r){return new QPainterPath();};

/**
  * @name subtractedInverted
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} r
  * @returns {QPainterPath}
  */
QPainterPath.prototype.subtractedInverted = function(r){return new QPainterPath();};

/**
  * @name swap
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} other
  * @returns {undefined}
  */
QPainterPath.prototype.swap = function(other){return undefined;};

/**
  * @name toFillPolygon
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QMatrix} matrix
  * @returns {QPolygonF}
  */
QPainterPath.prototype.toFillPolygon = function(matrix){return new QPolygonF();};

/**
  * @name toFillPolygons
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QMatrix} matrix
  * @returns {Array}
  */
QPainterPath.prototype.toFillPolygons = function(matrix){return new Array();};

/**
  * @name toReversed
  * @function
  * @memberOf QPainterPath.prototype
  * @returns {QPainterPath}
  */
QPainterPath.prototype.toReversed = function(){return new QPainterPath();};

/**
  * @name toSubpathPolygons
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QMatrix} matrix
  * @returns {Array}
  */
QPainterPath.prototype.toSubpathPolygons = function(matrix){return new Array();};

/**
  * @name translate
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} offset
  * @returns {undefined}
  */
QPainterPath.prototype.translate = function(offset){return undefined;};

/**
  * @name translated
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPointF} offset
  * @returns {QPainterPath}
  */
QPainterPath.prototype.translated = function(offset){return new QPainterPath();};

/**
  * @name united
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QPainterPath} r
  * @returns {QPainterPath}
  */
QPainterPath.prototype.united = function(r){return new QPainterPath();};

/**
  * @name writeTo
  * @function
  * @memberOf QPainterPath.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QPainterPath.prototype.writeTo = function(arg__1){return undefined;};

