/**
  * @name QMatrix4x4
  * @constructor
  */
function QMatrix4x4(){return undefined;};

/**
  * @name QMatrix4x4^1
  * @constructor
  * @param {QMatrix} matrix
  */
function QMatrix4x4(matrix){return undefined;};

/**
  * @name QMatrix4x4^2
  * @constructor
  * @param {QTransform} transform
  */
function QMatrix4x4(transform){return undefined;};

/**
  * @name QMatrix4x4^3
  * @constructor
  * @param {Numeric} values
  */
function QMatrix4x4(values){return undefined;};

/**
  * @name QMatrix4x4^4
  * @constructor
  * @param {Numeric} values
  * @param {Numeric} cols
  * @param {Numeric} rows
  */
function QMatrix4x4(values, cols, rows){return undefined;};

/**
  * @name QMatrix4x4^5
  * @constructor
  * @param {Numeric} m11
  * @param {Numeric} m12
  * @param {Numeric} m13
  * @param {Numeric} m14
  * @param {Numeric} m21
  * @param {Numeric} m22
  * @param {Numeric} m23
  * @param {Numeric} m24
  * @param {Numeric} m31
  * @param {Numeric} m32
  * @param {Numeric} m33
  * @param {Numeric} m34
  * @param {Numeric} m41
  * @param {Numeric} m42
  * @param {Numeric} m43
  * @param {Numeric} m44
  */
function QMatrix4x4(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44){return undefined;};

/**
  * @name column
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} index
  * @returns {QVector4D}
  */
QMatrix4x4.prototype.column = function(index){return new QVector4D();};

/**
  * @name constData
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {Numeric}
  */
QMatrix4x4.prototype.constData = function(){return new Numeric();};

/**
  * @name copyDataTo
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} values
  * @returns {undefined}
  */
QMatrix4x4.prototype.copyDataTo = function(values){return undefined;};

/**
  * @name data
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {Numeric}
  */
QMatrix4x4.prototype.data = function(){return new Numeric();};

/**
  * @name determinant
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {Numeric}
  */
QMatrix4x4.prototype.determinant = function(){return new Numeric();};

/**
  * @name fill
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} value
  * @returns {undefined}
  */
QMatrix4x4.prototype.fill = function(value){return undefined;};

/**
  * @name flipCoordinates
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {undefined}
  */
QMatrix4x4.prototype.flipCoordinates = function(){return undefined;};

/**
  * @name frustum
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} left
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @param {Numeric} top
  * @param {Numeric} nearPlane
  * @param {Numeric} farPlane
  * @returns {undefined}
  */
QMatrix4x4.prototype.frustum = function(left, right, bottom, top, nearPlane, farPlane){return undefined;};

/**
  * @name inverted
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Boolean} invertible
  * @returns {QMatrix4x4}
  */
QMatrix4x4.prototype.inverted = function(invertible){return new QMatrix4x4();};

/**
  * @name isIdentity
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {Boolean}
  */
QMatrix4x4.prototype.isIdentity = function(){return new Boolean();};

/**
  * @name lookAt
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QVector3D} eye
  * @param {QVector3D} center
  * @param {QVector3D} up
  * @returns {undefined}
  */
QMatrix4x4.prototype.lookAt = function(eye, center, up){return undefined;};

/**
  * @name map
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QPoint} point
  * @returns {QPoint}
  */
QMatrix4x4.prototype.map = function(point){return new QPoint();};

/**
  * @name mapRect
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QRect} rect
  * @returns {QRect}
  */
QMatrix4x4.prototype.mapRect = function(rect){return new QRect();};

/**
  * @name mapVector
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QVector3D} vector
  * @returns {QVector3D}
  */
QMatrix4x4.prototype.mapVector = function(vector){return new QVector3D();};

/**
  * @name normalMatrix
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {QMatrix3x3}
  */
QMatrix4x4.prototype.normalMatrix = function(){return new QMatrix3x3();};

/**
  * @name operator_add_assign
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QMatrix4x4} other
  * @returns {QMatrix4x4}
  */
QMatrix4x4.prototype.operator_add_assign = function(other){return new QMatrix4x4();};

/**
  * @name operator_cast_
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {Numeric}
  */
QMatrix4x4.prototype.operator_cast_ = function(row, column){return new Numeric();};

/**
  * @name operator_divide_assign
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} divisor
  * @returns {QMatrix4x4}
  */
QMatrix4x4.prototype.operator_divide_assign = function(divisor){return new QMatrix4x4();};

/**
  * @name operator_equal
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QMatrix4x4} other
  * @returns {Boolean}
  */
QMatrix4x4.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name operator_multiply_assign
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QMatrix4x4} other
  * @returns {QMatrix4x4}
  */
QMatrix4x4.prototype.operator_multiply_assign = function(other){return new QMatrix4x4();};

/**
  * @name operator_subtract_assign
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QMatrix4x4} other
  * @returns {QMatrix4x4}
  */
QMatrix4x4.prototype.operator_subtract_assign = function(other){return new QMatrix4x4();};

/**
  * @name optimize
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {undefined}
  */
QMatrix4x4.prototype.optimize = function(){return undefined;};

/**
  * @name ortho
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QRect} rect
  * @returns {undefined}
  */
QMatrix4x4.prototype.ortho = function(rect){return undefined;};

/**
  * @name perspective
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} angle
  * @param {Numeric} aspect
  * @param {Numeric} nearPlane
  * @param {Numeric} farPlane
  * @returns {undefined}
  */
QMatrix4x4.prototype.perspective = function(angle, aspect, nearPlane, farPlane){return undefined;};

/**
  * @name readFrom
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QMatrix4x4.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name rotate
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QQuaternion} quaternion
  * @returns {undefined}
  */
QMatrix4x4.prototype.rotate = function(quaternion){return undefined;};

/**
  * @name row
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} index
  * @returns {QVector4D}
  */
QMatrix4x4.prototype.row = function(index){return new QVector4D();};

/**
  * @name scale
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QVector3D} vector
  * @returns {undefined}
  */
QMatrix4x4.prototype.scale = function(vector){return undefined;};

/**
  * @name setColumn
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} index
  * @param {QVector4D} value
  * @returns {undefined}
  */
QMatrix4x4.prototype.setColumn = function(index, value){return undefined;};

/**
  * @name setRow
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {Numeric} index
  * @param {QVector4D} value
  * @returns {undefined}
  */
QMatrix4x4.prototype.setRow = function(index, value){return undefined;};

/**
  * @name setToIdentity
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {undefined}
  */
QMatrix4x4.prototype.setToIdentity = function(){return undefined;};

/**
  * @name toAffine
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {QMatrix}
  */
QMatrix4x4.prototype.toAffine = function(){return new QMatrix();};

/**
  * @name toTransform
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {QTransform}
  */
QMatrix4x4.prototype.toTransform = function(){return new QTransform();};

/**
  * @name translate
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QVector3D} vector
  * @returns {undefined}
  */
QMatrix4x4.prototype.translate = function(vector){return undefined;};

/**
  * @name transposed
  * @function
  * @memberOf QMatrix4x4.prototype
  * @returns {QMatrix4x4}
  */
QMatrix4x4.prototype.transposed = function(){return new QMatrix4x4();};

/**
  * @name writeTo
  * @function
  * @memberOf QMatrix4x4.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QMatrix4x4.prototype.writeTo = function(arg__1){return undefined;};

