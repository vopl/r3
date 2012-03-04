/**
  * @name QQuaternion
  * @constructor
  */
function QQuaternion(){return undefined;};

/**
  * @name QQuaternion^1
  * @constructor
  * @param {QVector4D} vector
  */
function QQuaternion(vector){return undefined;};

/**
  * @name QQuaternion^2
  * @constructor
  * @param {Numeric} scalar
  * @param {QVector3D} vector
  */
function QQuaternion(scalar, vector){return undefined;};

/**
  * @name QQuaternion^3
  * @constructor
  * @param {Numeric} scalar
  * @param {Numeric} xpos
  * @param {Numeric} ypos
  * @param {Numeric} zpos
  */
function QQuaternion(scalar, xpos, ypos, zpos){return undefined;};

/**
  * @name fromAxisAndAngle
  * @function
  * @memberOf QQuaternion
  * @param {QVector3D} axis
  * @param {Numeric} angle
  * @returns {QQuaternion}
  */
QQuaternion.fromAxisAndAngle = function(axis, angle){return new QQuaternion();};

/**
  * @name nlerp
  * @function
  * @memberOf QQuaternion
  * @param {QQuaternion} q1
  * @param {QQuaternion} q2
  * @param {Numeric} t
  * @returns {QQuaternion}
  */
QQuaternion.nlerp = function(q1, q2, t){return new QQuaternion();};

/**
  * @name slerp
  * @function
  * @memberOf QQuaternion
  * @param {QQuaternion} q1
  * @param {QQuaternion} q2
  * @param {Numeric} t
  * @returns {QQuaternion}
  */
QQuaternion.slerp = function(q1, q2, t){return new QQuaternion();};

/**
  * @name conjugate
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {QQuaternion}
  */
QQuaternion.prototype.conjugate = function(){return new QQuaternion();};

/**
  * @name isIdentity
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Boolean}
  */
QQuaternion.prototype.isIdentity = function(){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Boolean}
  */
QQuaternion.prototype.isNull = function(){return new Boolean();};

/**
  * @name length
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Numeric}
  */
QQuaternion.prototype.length = function(){return new Numeric();};

/**
  * @name lengthSquared
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Numeric}
  */
QQuaternion.prototype.lengthSquared = function(){return new Numeric();};

/**
  * @name normalize
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {undefined}
  */
QQuaternion.prototype.normalize = function(){return undefined;};

/**
  * @name normalized
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {QQuaternion}
  */
QQuaternion.prototype.normalized = function(){return new QQuaternion();};

/**
  * @name operator_add_assign
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QQuaternion} quaternion
  * @returns {QQuaternion}
  */
QQuaternion.prototype.operator_add_assign = function(quaternion){return new QQuaternion();};

/**
  * @name operator_divide_assign
  * @function
  * @memberOf QQuaternion.prototype
  * @param {Numeric} divisor
  * @returns {QQuaternion}
  */
QQuaternion.prototype.operator_divide_assign = function(divisor){return new QQuaternion();};

/**
  * @name operator_equal
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QQuaternion} q2
  * @returns {Boolean}
  */
QQuaternion.prototype.operator_equal = function(q2){return new Boolean();};

/**
  * @name operator_multiply_assign
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QQuaternion} quaternion
  * @returns {QQuaternion}
  */
QQuaternion.prototype.operator_multiply_assign = function(quaternion){return new QQuaternion();};

/**
  * @name operator_subtract_assign
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QQuaternion} quaternion
  * @returns {QQuaternion}
  */
QQuaternion.prototype.operator_subtract_assign = function(quaternion){return new QQuaternion();};

/**
  * @name readFrom
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QQuaternion.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name rotatedVector
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QVector3D} vector
  * @returns {QVector3D}
  */
QQuaternion.prototype.rotatedVector = function(vector){return new QVector3D();};

/**
  * @name scalar
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Numeric}
  */
QQuaternion.prototype.scalar = function(){return new Numeric();};

/**
  * @name setScalar
  * @function
  * @memberOf QQuaternion.prototype
  * @param {Numeric} scalar
  * @returns {undefined}
  */
QQuaternion.prototype.setScalar = function(scalar){return undefined;};

/**
  * @name setVector
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QVector3D} vector
  * @returns {undefined}
  */
QQuaternion.prototype.setVector = function(vector){return undefined;};

/**
  * @name setX
  * @function
  * @memberOf QQuaternion.prototype
  * @param {Numeric} x
  * @returns {undefined}
  */
QQuaternion.prototype.setX = function(x){return undefined;};

/**
  * @name setY
  * @function
  * @memberOf QQuaternion.prototype
  * @param {Numeric} y
  * @returns {undefined}
  */
QQuaternion.prototype.setY = function(y){return undefined;};

/**
  * @name setZ
  * @function
  * @memberOf QQuaternion.prototype
  * @param {Numeric} z
  * @returns {undefined}
  */
QQuaternion.prototype.setZ = function(z){return undefined;};

/**
  * @name toVector4D
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {QVector4D}
  */
QQuaternion.prototype.toVector4D = function(){return new QVector4D();};

/**
  * @name vector
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {QVector3D}
  */
QQuaternion.prototype.vector = function(){return new QVector3D();};

/**
  * @name writeTo
  * @function
  * @memberOf QQuaternion.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QQuaternion.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name x
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Numeric}
  */
QQuaternion.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Numeric}
  */
QQuaternion.prototype.y = function(){return new Numeric();};

/**
  * @name z
  * @function
  * @memberOf QQuaternion.prototype
  * @returns {Numeric}
  */
QQuaternion.prototype.z = function(){return new Numeric();};

