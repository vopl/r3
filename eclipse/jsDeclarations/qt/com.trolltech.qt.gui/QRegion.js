/**
  * @name QRegion
  * @constructor
  */
function QRegion(){return undefined;};

/**
  * @name QRegion^1
  * @constructor
  * @param {QBitmap} bitmap
  */
function QRegion(bitmap){return undefined;};

/**
  * @name QRegion^2
  * @constructor
  * @param {QPolygon} pa
  * @param {Qt.FillRule} fillRule
  */
function QRegion(pa, fillRule){return undefined;};

/**
  * @name QRegion^3
  * @constructor
  * @param {QRect} r
  * @param {QRegion.RegionType} t
  */
function QRegion(r, t){return undefined;};

/**
  * @name QRegion^4
  * @constructor
  * @param {QRegion} region
  */
function QRegion(region){return undefined;};

/**
  * @name QRegion^5
  * @constructor
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @param {QRegion.RegionType} t
  */
function QRegion(x, y, w, h, t){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QRegion
  * @name Rectangle
  * @see QRegion#RegionType
  * @type Number
  */
QRegion.Rectangle = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QRegion
  * @name Ellipse
  * @see QRegion#RegionType
  * @type Number
  */
QRegion.Ellipse = 0x1;

/**
  * @constructor 
  * @memberOf QRegion
  * @name RegionType
  */
QRegion.RegionType = function(value){;};



/**
  * @name boundingRect
  * @function
  * @memberOf QRegion.prototype
  * @returns {QRect}
  */
QRegion.prototype.boundingRect = function(){return new QRect();};

/**
  * @name contains
  * @function
  * @memberOf QRegion.prototype
  * @param {QPoint} p
  * @returns {Boolean}
  */
QRegion.prototype.contains = function(p){return new Boolean();};

/**
  * @name intersect
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {QRegion}
  */
QRegion.prototype.intersect = function(r){return new QRegion();};

/**
  * @name intersected
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {QRegion}
  */
QRegion.prototype.intersected = function(r){return new QRegion();};

/**
  * @name intersects
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {Boolean}
  */
QRegion.prototype.intersects = function(r){return new Boolean();};

/**
  * @name isEmpty
  * @function
  * @memberOf QRegion.prototype
  * @returns {Boolean}
  */
QRegion.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name numRects
  * @function
  * @memberOf QRegion.prototype
  * @returns {Numeric}
  */
QRegion.prototype.numRects = function(){return new Numeric();};

/**
  * @name operator_add
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {QRegion}
  */
QRegion.prototype.operator_add = function(r){return new QRegion();};

/**
  * @name operator_and
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {QRegion}
  */
QRegion.prototype.operator_and = function(r){return new QRegion();};

/**
  * @name operator_equal
  * @function
  * @memberOf QRegion.prototype
  * @param {QRegion} r
  * @returns {Boolean}
  */
QRegion.prototype.operator_equal = function(r){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QRegion.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QRegion.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name rectCount
  * @function
  * @memberOf QRegion.prototype
  * @returns {Numeric}
  */
QRegion.prototype.rectCount = function(){return new Numeric();};

/**
  * @name rects
  * @function
  * @memberOf QRegion.prototype
  * @returns {Array}
  */
QRegion.prototype.rects = function(){return new Array();};

/**
  * @name setRects
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} rect
  * @param {Numeric} num
  * @returns {undefined}
  */
QRegion.prototype.setRects = function(rect, num){return undefined;};

/**
  * @name subtracted
  * @function
  * @memberOf QRegion.prototype
  * @param {QRegion} r
  * @returns {QRegion}
  */
QRegion.prototype.subtracted = function(r){return new QRegion();};

/**
  * @name swap
  * @function
  * @memberOf QRegion.prototype
  * @param {QRegion} other
  * @returns {undefined}
  */
QRegion.prototype.swap = function(other){return undefined;};

/**
  * @name translate
  * @function
  * @memberOf QRegion.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRegion.prototype.translate = function(p){return undefined;};

/**
  * @name translated
  * @function
  * @memberOf QRegion.prototype
  * @param {QPoint} p
  * @returns {QRegion}
  */
QRegion.prototype.translated = function(p){return new QRegion();};

/**
  * @name unite
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {QRegion}
  */
QRegion.prototype.unite = function(r){return new QRegion();};

/**
  * @name united
  * @function
  * @memberOf QRegion.prototype
  * @param {QRect} r
  * @returns {QRegion}
  */
QRegion.prototype.united = function(r){return new QRegion();};

/**
  * @name writeTo
  * @function
  * @memberOf QRegion.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QRegion.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name xored
  * @function
  * @memberOf QRegion.prototype
  * @param {QRegion} r
  * @returns {QRegion}
  */
QRegion.prototype.xored = function(r){return new QRegion();};

