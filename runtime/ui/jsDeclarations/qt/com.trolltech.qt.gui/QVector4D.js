/**
  * @name QVector4D
  * @constructor
  */
function QVector4D(){return undefined;};

/**
  * @name QVector4D^1
  * @constructor
  * @param {QPoint} point
  */
function QVector4D(point){return undefined;};

/**
  * @name QVector4D^2
  * @constructor
  * @param {QPointF} point
  */
function QVector4D(point){return undefined;};

/**
  * @name QVector4D^3
  * @constructor
  * @param {QVector2D} vector
  */
function QVector4D(vector){return undefined;};

/**
  * @name QVector4D^4
  * @constructor
  * @param {QVector2D} vector
  * @param {Numeric} zpos
  * @param {Numeric} wpos
  */
function QVector4D(vector, zpos, wpos){return undefined;};

/**
  * @name QVector4D^5
  * @constructor
  * @param {QVector3D} vector
  */
function QVector4D(vector){return undefined;};

/**
  * @name QVector4D^6
  * @constructor
  * @param {QVector3D} vector
  * @param {Numeric} wpos
  */
function QVector4D(vector, wpos){return undefined;};

/**
  * @name QVector4D^7
  * @constructor
  * @param {Numeric} xpos
  * @param {Numeric} ypos
  * @param {Numeric} zpos
  * @param {Numeric} wpos
  */
function QVector4D(xpos, ypos, zpos, wpos){return undefined;};

/**
  * @name dotProduct
  * @function
  * @memberOf QVector4D
  * @param {QVector4D} v1
  * @param {QVector4D} v2
  * @returns {Numeric}
  */
QVector4D.dotProduct = function(v1, v2){return new Numeric();};

/**
  * @name isNull
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Boolean}
  */
QVector4D.prototype.isNull = function(){return new Boolean();};

/**
  * @name length
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Numeric}
  */
QVector4D.prototype.length = function(){return new Numeric();};

/**
  * @name lengthSquared
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Numeric}
  */
QVector4D.prototype.lengthSquared = function(){return new Numeric();};

/**
  * @name normalize
  * @function
  * @memberOf QVector4D.prototype
  * @returns {undefined}
  */
QVector4D.prototype.normalize = function(){return undefined;};

/**
  * @name normalized
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QVector4D}
  */
QVector4D.prototype.normalized = function(){return new QVector4D();};

/**
  * @name operator_add_assign
  * @function
  * @memberOf QVector4D.prototype
  * @param {QVector4D} vector
  * @returns {QVector4D}
  */
QVector4D.prototype.operator_add_assign = function(vector){return new QVector4D();};

/**
  * @name operator_divide_assign
  * @function
  * @memberOf QVector4D.prototype
  * @param {Numeric} divisor
  * @returns {QVector4D}
  */
QVector4D.prototype.operator_divide_assign = function(divisor){return new QVector4D();};

/**
  * @name operator_equal
  * @function
  * @memberOf QVector4D.prototype
  * @param {QVector4D} v2
  * @returns {Boolean}
  */
QVector4D.prototype.operator_equal = function(v2){return new Boolean();};

/**
  * @name operator_multiply_assign
  * @function
  * @memberOf QVector4D.prototype
  * @param {QVector4D} vector
  * @returns {QVector4D}
  */
QVector4D.prototype.operator_multiply_assign = function(vector){return new QVector4D();};

/**
  * @name operator_subtract_assign
  * @function
  * @memberOf QVector4D.prototype
  * @param {QVector4D} vector
  * @returns {QVector4D}
  */
QVector4D.prototype.operator_subtract_assign = function(vector){return new QVector4D();};

/**
  * @name readFrom
  * @function
  * @memberOf QVector4D.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QVector4D.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setW
  * @function
  * @memberOf QVector4D.prototype
  * @param {Numeric} w
  * @returns {undefined}
  */
QVector4D.prototype.setW = function(w){return undefined;};

/**
  * @name setX
  * @function
  * @memberOf QVector4D.prototype
  * @param {Numeric} x
  * @returns {undefined}
  */
QVector4D.prototype.setX = function(x){return undefined;};

/**
  * @name setY
  * @function
  * @memberOf QVector4D.prototype
  * @param {Numeric} y
  * @returns {undefined}
  */
QVector4D.prototype.setY = function(y){return undefined;};

/**
  * @name setZ
  * @function
  * @memberOf QVector4D.prototype
  * @param {Numeric} z
  * @returns {undefined}
  */
QVector4D.prototype.setZ = function(z){return undefined;};

/**
  * @name toPoint
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QPoint}
  */
QVector4D.prototype.toPoint = function(){return new QPoint();};

/**
  * @name toPointF
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QPointF}
  */
QVector4D.prototype.toPointF = function(){return new QPointF();};

/**
  * @name toVector2D
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QVector2D}
  */
QVector4D.prototype.toVector2D = function(){return new QVector2D();};

/**
  * @name toVector2DAffine
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QVector2D}
  */
QVector4D.prototype.toVector2DAffine = function(){return new QVector2D();};

/**
  * @name toVector3D
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QVector3D}
  */
QVector4D.prototype.toVector3D = function(){return new QVector3D();};

/**
  * @name toVector3DAffine
  * @function
  * @memberOf QVector4D.prototype
  * @returns {QVector3D}
  */
QVector4D.prototype.toVector3DAffine = function(){return new QVector3D();};

/**
  * @name w
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Numeric}
  */
QVector4D.prototype.w = function(){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QVector4D.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QVector4D.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name x
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Numeric}
  */
QVector4D.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Numeric}
  */
QVector4D.prototype.y = function(){return new Numeric();};

/**
  * @name z
  * @function
  * @memberOf QVector4D.prototype
  * @returns {Numeric}
  */
QVector4D.prototype.z = function(){return new Numeric();};

