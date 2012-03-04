/**
  * @name QLineF
  * @constructor
  */
function QLineF(){return undefined;};

/**
  * @name QLineF^1
  * @constructor
  * @param {QLine} line
  */
function QLineF(line){return undefined;};

/**
  * @name QLineF^2
  * @constructor
  * @param {QPointF} pt1
  * @param {QPointF} pt2
  */
function QLineF(pt1, pt2){return undefined;};

/**
  * @name QLineF^3
  * @constructor
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  */
function QLineF(x1, y1, x2, y2){return undefined;};

/**
  * @name fromPolar
  * @function
  * @memberOf QLineF
  * @param {Numeric} length
  * @param {Numeric} angle
  * @returns {QLineF}
  */
QLineF.fromPolar = function(length, angle){return new QLineF();};

/**
  * @default 0x0
  * @constant
  * @memberOf QLineF
  * @name NoIntersection
  * @see QLineF#IntersectType
  * @type Number
  */
QLineF.NoIntersection = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLineF
  * @name BoundedIntersection
  * @see QLineF#IntersectType
  * @type Number
  */
QLineF.BoundedIntersection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QLineF
  * @name UnboundedIntersection
  * @see QLineF#IntersectType
  * @type Number
  */
QLineF.UnboundedIntersection = 0x2;

/**
  * @constructor 
  * @memberOf QLineF
  * @name IntersectType
  */
QLineF.IntersectType = function(value){;};



/**
  * @name angle
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.angle = function(){return new Numeric();};

/**
  * @name angleTo
  * @function
  * @memberOf QLineF.prototype
  * @param {QLineF} l
  * @returns {Numeric}
  */
QLineF.prototype.angleTo = function(l){return new Numeric();};

/**
  * @name dx
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.dx = function(){return new Numeric();};

/**
  * @name dy
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.dy = function(){return new Numeric();};

/**
  * @name intersect
  * @function
  * @memberOf QLineF.prototype
  * @param {QLineF} l
  * @param {QPointF} intersectionPoint
  * @returns {QLineF.IntersectType}
  */
QLineF.prototype.intersect = function(l, intersectionPoint){return new QLineF.IntersectType();};

/**
  * @name isNull
  * @function
  * @memberOf QLineF.prototype
  * @returns {Boolean}
  */
QLineF.prototype.isNull = function(){return new Boolean();};

/**
  * @name length
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.length = function(){return new Numeric();};

/**
  * @name normalVector
  * @function
  * @memberOf QLineF.prototype
  * @returns {QLineF}
  */
QLineF.prototype.normalVector = function(){return new QLineF();};

/**
  * @name operator_equal
  * @function
  * @memberOf QLineF.prototype
  * @param {QLineF} d
  * @returns {Boolean}
  */
QLineF.prototype.operator_equal = function(d){return new Boolean();};

/**
  * @name p1
  * @function
  * @memberOf QLineF.prototype
  * @returns {QPointF}
  */
QLineF.prototype.p1 = function(){return new QPointF();};

/**
  * @name p2
  * @function
  * @memberOf QLineF.prototype
  * @returns {QPointF}
  */
QLineF.prototype.p2 = function(){return new QPointF();};

/**
  * @name pointAt
  * @function
  * @memberOf QLineF.prototype
  * @param {Numeric} t
  * @returns {QPointF}
  */
QLineF.prototype.pointAt = function(t){return new QPointF();};

/**
  * @name readFrom
  * @function
  * @memberOf QLineF.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QLineF.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setAngle
  * @function
  * @memberOf QLineF.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QLineF.prototype.setAngle = function(angle){return undefined;};

/**
  * @name setLength
  * @function
  * @memberOf QLineF.prototype
  * @param {Numeric} len
  * @returns {undefined}
  */
QLineF.prototype.setLength = function(len){return undefined;};

/**
  * @name setLine
  * @function
  * @memberOf QLineF.prototype
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  * @returns {undefined}
  */
QLineF.prototype.setLine = function(x1, y1, x2, y2){return undefined;};

/**
  * @name setP1
  * @function
  * @memberOf QLineF.prototype
  * @param {QPointF} p1
  * @returns {undefined}
  */
QLineF.prototype.setP1 = function(p1){return undefined;};

/**
  * @name setP2
  * @function
  * @memberOf QLineF.prototype
  * @param {QPointF} p2
  * @returns {undefined}
  */
QLineF.prototype.setP2 = function(p2){return undefined;};

/**
  * @name setPoints
  * @function
  * @memberOf QLineF.prototype
  * @param {QPointF} p1
  * @param {QPointF} p2
  * @returns {undefined}
  */
QLineF.prototype.setPoints = function(p1, p2){return undefined;};

/**
  * @name toLine
  * @function
  * @memberOf QLineF.prototype
  * @returns {QLine}
  */
QLineF.prototype.toLine = function(){return new QLine();};

/**
  * @name translate
  * @function
  * @memberOf QLineF.prototype
  * @param {QPointF} p
  * @returns {undefined}
  */
QLineF.prototype.translate = function(p){return undefined;};

/**
  * @name translated
  * @function
  * @memberOf QLineF.prototype
  * @param {QPointF} p
  * @returns {QLineF}
  */
QLineF.prototype.translated = function(p){return new QLineF();};

/**
  * @name unitVector
  * @function
  * @memberOf QLineF.prototype
  * @returns {QLineF}
  */
QLineF.prototype.unitVector = function(){return new QLineF();};

/**
  * @name writeTo
  * @function
  * @memberOf QLineF.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QLineF.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name x1
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.x1 = function(){return new Numeric();};

/**
  * @name x2
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.x2 = function(){return new Numeric();};

/**
  * @name y1
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.y1 = function(){return new Numeric();};

/**
  * @name y2
  * @function
  * @memberOf QLineF.prototype
  * @returns {Numeric}
  */
QLineF.prototype.y2 = function(){return new Numeric();};

