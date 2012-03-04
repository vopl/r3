/**
  * @name QMatrix
  * @constructor
  */
function QMatrix(){return undefined;};

/**
  * @name QMatrix^1
  * @constructor
  * @param {QMatrix} matrix
  */
function QMatrix(matrix){return undefined;};

/**
  * @name QMatrix^2
  * @constructor
  * @param {Numeric} m11
  * @param {Numeric} m12
  * @param {Numeric} m21
  * @param {Numeric} m22
  * @param {Numeric} dx
  * @param {Numeric} dy
  */
function QMatrix(m11, m12, m21, m22, dx, dy){return undefined;};

/**
  * @name det
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.det = function(){return new Numeric();};

/**
  * @name determinant
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.determinant = function(){return new Numeric();};

/**
  * @name dx
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.dx = function(){return new Numeric();};

/**
  * @name dy
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.dy = function(){return new Numeric();};

/**
  * @name inverted
  * @function
  * @memberOf QMatrix.prototype
  * @param {Boolean} invertible
  * @returns {QMatrix}
  */
QMatrix.prototype.inverted = function(invertible){return new QMatrix();};

/**
  * @name isIdentity
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Boolean}
  */
QMatrix.prototype.isIdentity = function(){return new Boolean();};

/**
  * @name isInvertible
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Boolean}
  */
QMatrix.prototype.isInvertible = function(){return new Boolean();};

/**
  * @name m11
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.m11 = function(){return new Numeric();};

/**
  * @name m12
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.m12 = function(){return new Numeric();};

/**
  * @name m21
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.m21 = function(){return new Numeric();};

/**
  * @name m22
  * @function
  * @memberOf QMatrix.prototype
  * @returns {Numeric}
  */
QMatrix.prototype.m22 = function(){return new Numeric();};

/**
  * @name map
  * @function
  * @memberOf QMatrix.prototype
  * @param {QLine} l
  * @returns {QLine}
  */
QMatrix.prototype.map = function(l){return new QLine();};

/**
  * @name mapRect
  * @function
  * @memberOf QMatrix.prototype
  * @param {QRect} arg__1
  * @returns {QRect}
  */
QMatrix.prototype.mapRect = function(arg__1){return new QRect();};

/**
  * @name mapToPolygon
  * @function
  * @memberOf QMatrix.prototype
  * @param {QRect} r
  * @returns {QPolygon}
  */
QMatrix.prototype.mapToPolygon = function(r){return new QPolygon();};

/**
  * @name operator_equal
  * @function
  * @memberOf QMatrix.prototype
  * @param {QMatrix} arg__1
  * @returns {Boolean}
  */
QMatrix.prototype.operator_equal = function(arg__1){return new Boolean();};

/**
  * @name operator_multiply
  * @function
  * @memberOf QMatrix.prototype
  * @param {QMatrix} o
  * @returns {QMatrix}
  */
QMatrix.prototype.operator_multiply = function(o){return new QMatrix();};

/**
  * @name operator_multiply_assign
  * @function
  * @memberOf QMatrix.prototype
  * @param {QMatrix} arg__1
  * @returns {QMatrix}
  */
QMatrix.prototype.operator_multiply_assign = function(arg__1){return new QMatrix();};

/**
  * @name readFrom
  * @function
  * @memberOf QMatrix.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QMatrix.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name reset
  * @function
  * @memberOf QMatrix.prototype
  * @returns {undefined}
  */
QMatrix.prototype.reset = function(){return undefined;};

/**
  * @name rotate_private
  * @function
  * @memberOf QMatrix.prototype
  * @param {Numeric} a
  * @returns {QMatrix}
  */
QMatrix.prototype.rotate_private = function(a){return new QMatrix();};

/**
  * @name scale_private
  * @function
  * @memberOf QMatrix.prototype
  * @param {Numeric} sx
  * @param {Numeric} sy
  * @returns {QMatrix}
  */
QMatrix.prototype.scale_private = function(sx, sy){return new QMatrix();};

/**
  * @name setMatrix
  * @function
  * @memberOf QMatrix.prototype
  * @param {Numeric} m11
  * @param {Numeric} m12
  * @param {Numeric} m21
  * @param {Numeric} m22
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {undefined}
  */
QMatrix.prototype.setMatrix = function(m11, m12, m21, m22, dx, dy){return undefined;};

/**
  * @name shear_private
  * @function
  * @memberOf QMatrix.prototype
  * @param {Numeric} sh
  * @param {Numeric} sv
  * @returns {QMatrix}
  */
QMatrix.prototype.shear_private = function(sh, sv){return new QMatrix();};

/**
  * @name translate_private
  * @function
  * @memberOf QMatrix.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {QMatrix}
  */
QMatrix.prototype.translate_private = function(dx, dy){return new QMatrix();};

/**
  * @name writeTo
  * @function
  * @memberOf QMatrix.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QMatrix.prototype.writeTo = function(arg__1){return undefined;};

