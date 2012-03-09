/**
  * @name QVector3D
  * @constructor
  */
function QVector3D(){return undefined;};

/**
  * @name QVector3D^1
  * @constructor
  * @param {QPoint} point
  */
function QVector3D(point){return undefined;};

/**
  * @name QVector3D^2
  * @constructor
  * @param {QPointF} point
  */
function QVector3D(point){return undefined;};

/**
  * @name QVector3D^3
  * @constructor
  * @param {QVector2D} vector
  */
function QVector3D(vector){return undefined;};

/**
  * @name QVector3D^4
  * @constructor
  * @param {QVector2D} vector
  * @param {Numeric} zpos
  */
function QVector3D(vector, zpos){return undefined;};

/**
  * @name QVector3D^5
  * @constructor
  * @param {QVector4D} vector
  */
function QVector3D(vector){return undefined;};

/**
  * @name QVector3D^6
  * @constructor
  * @param {Numeric} xpos
  * @param {Numeric} ypos
  * @param {Numeric} zpos
  */
function QVector3D(xpos, ypos, zpos){return undefined;};

/**
  * @name crossProduct
  * @function
  * @memberOf QVector3D
  * @param {QVector3D} v1
  * @param {QVector3D} v2
  * @returns {QVector3D}
  */
QVector3D.crossProduct = function(v1, v2){return new QVector3D();};

/**
  * @name dotProduct
  * @function
  * @memberOf QVector3D
  * @param {QVector3D} v1
  * @param {QVector3D} v2
  * @returns {Numeric}
  */
QVector3D.dotProduct = function(v1, v2){return new Numeric();};

/**
  * @name normal
  * @function
  * @memberOf QVector3D
  * @param {QVector3D} v1
  * @param {QVector3D} v2
  * @returns {QVector3D}
  */
QVector3D.normal = function(v1, v2){return new QVector3D();};

/**
  * @name distanceToLine
  * @function
  * @memberOf QVector3D.prototype
  * @param {QVector3D} point
  * @param {QVector3D} direction
  * @returns {Numeric}
  */
QVector3D.prototype.distanceToLine = function(point, direction){return new Numeric();};

/**
  * @name distanceToPlane
  * @function
  * @memberOf QVector3D.prototype
  * @param {QVector3D} plane
  * @param {QVector3D} normal
  * @returns {Numeric}
  */
QVector3D.prototype.distanceToPlane = function(plane, normal){return new Numeric();};

/**
  * @name isNull
  * @function
  * @memberOf QVector3D.prototype
  * @returns {Boolean}
  */
QVector3D.prototype.isNull = function(){return new Boolean();};

/**
  * @name length
  * @function
  * @memberOf QVector3D.prototype
  * @returns {Numeric}
  */
QVector3D.prototype.length = function(){return new Numeric();};

/**
  * @name lengthSquared
  * @function
  * @memberOf QVector3D.prototype
  * @returns {Numeric}
  */
QVector3D.prototype.lengthSquared = function(){return new Numeric();};

/**
  * @name normalize
  * @function
  * @memberOf QVector3D.prototype
  * @returns {undefined}
  */
QVector3D.prototype.normalize = function(){return undefined;};

/**
  * @name normalized
  * @function
  * @memberOf QVector3D.prototype
  * @returns {QVector3D}
  */
QVector3D.prototype.normalized = function(){return new QVector3D();};

/**
  * @name operator_add_assign
  * @function
  * @memberOf QVector3D.prototype
  * @param {QVector3D} vector
  * @returns {QVector3D}
  */
QVector3D.prototype.operator_add_assign = function(vector){return new QVector3D();};

/**
  * @name operator_divide_assign
  * @function
  * @memberOf QVector3D.prototype
  * @param {Numeric} divisor
  * @returns {QVector3D}
  */
QVector3D.prototype.operator_divide_assign = function(divisor){return new QVector3D();};

/**
  * @name operator_equal
  * @function
  * @memberOf QVector3D.prototype
  * @param {QVector3D} v2
  * @returns {Boolean}
  */
QVector3D.prototype.operator_equal = function(v2){return new Boolean();};

/**
  * @name operator_multiply_assign
  * @function
  * @memberOf QVector3D.prototype
  * @param {QVector3D} vector
  * @returns {QVector3D}
  */
QVector3D.prototype.operator_multiply_assign = function(vector){return new QVector3D();};

/**
  * @name operator_subtract_assign
  * @function
  * @memberOf QVector3D.prototype
  * @param {QVector3D} vector
  * @returns {QVector3D}
  */
QVector3D.prototype.operator_subtract_assign = function(vector){return new QVector3D();};

/**
  * @name readFrom
  * @function
  * @memberOf QVector3D.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QVector3D.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setX
  * @function
  * @memberOf QVector3D.prototype
  * @param {Numeric} x
  * @returns {undefined}
  */
QVector3D.prototype.setX = function(x){return undefined;};

/**
  * @name setY
  * @function
  * @memberOf QVector3D.prototype
  * @param {Numeric} y
  * @returns {undefined}
  */
QVector3D.prototype.setY = function(y){return undefined;};

/**
  * @name setZ
  * @function
  * @memberOf QVector3D.prototype
  * @param {Numeric} z
  * @returns {undefined}
  */
QVector3D.prototype.setZ = function(z){return undefined;};

/**
  * @name toPoint
  * @function
  * @memberOf QVector3D.prototype
  * @returns {QPoint}
  */
QVector3D.prototype.toPoint = function(){return new QPoint();};

/**
  * @name toPointF
  * @function
  * @memberOf QVector3D.prototype
  * @returns {QPointF}
  */
QVector3D.prototype.toPointF = function(){return new QPointF();};

/**
  * @name toVector2D
  * @function
  * @memberOf QVector3D.prototype
  * @returns {QVector2D}
  */
QVector3D.prototype.toVector2D = function(){return new QVector2D();};

/**
  * @name toVector4D
  * @function
  * @memberOf QVector3D.prototype
  * @returns {QVector4D}
  */
QVector3D.prototype.toVector4D = function(){return new QVector4D();};

/**
  * @name writeTo
  * @function
  * @memberOf QVector3D.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QVector3D.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name x
  * @function
  * @memberOf QVector3D.prototype
  * @returns {Numeric}
  */
QVector3D.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QVector3D.prototype
  * @returns {Numeric}
  */
QVector3D.prototype.y = function(){return new Numeric();};

/**
  * @name z
  * @function
  * @memberOf QVector3D.prototype
  * @returns {Numeric}
  */
QVector3D.prototype.z = function(){return new Numeric();};

