/**
  * @name QTransform
  * @constructor
  */
function QTransform(){return undefined;};

/**
  * @name QTransform^1
  * @constructor
  * @param {QMatrix} mtx
  */
function QTransform(mtx){return undefined;};

/**
  * @name QTransform^2
  * @constructor
  * @param {Numeric} h11
  * @param {Numeric} h12
  * @param {Numeric} h13
  * @param {Numeric} h21
  * @param {Numeric} h22
  * @param {Numeric} h23
  * @param {Numeric} h31
  * @param {Numeric} h32
  * @param {Numeric} h33
  */
function QTransform(h11, h12, h13, h21, h22, h23, h31, h32, h33){return undefined;};

/**
  * @name QTransform^3
  * @constructor
  * @param {Numeric} h11
  * @param {Numeric} h12
  * @param {Numeric} h21
  * @param {Numeric} h22
  * @param {Numeric} dx
  * @param {Numeric} dy
  */
function QTransform(h11, h12, h21, h22, dx, dy){return undefined;};

/**
  * @name fromScale
  * @function
  * @memberOf QTransform
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {QTransform}
  */
QTransform.fromScale = function(dx, dy){return new QTransform();};

/**
  * @name fromTranslate
  * @function
  * @memberOf QTransform
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {QTransform}
  */
QTransform.fromTranslate = function(dx, dy){return new QTransform();};

/**
  * @name quadToQuad
  * @function
  * @memberOf QTransform
  * @param {QPolygonF} one
  * @param {QPolygonF} two
  * @param {QTransform} result
  * @returns {Boolean}
  */
QTransform.quadToQuad = function(one, two, result){return new Boolean();};

/**
  * @name quadToSquare
  * @function
  * @memberOf QTransform
  * @param {QPolygonF} quad
  * @param {QTransform} result
  * @returns {Boolean}
  */
QTransform.quadToSquare = function(quad, result){return new Boolean();};

/**
  * @name squareToQuad
  * @function
  * @memberOf QTransform
  * @param {QPolygonF} square
  * @param {QTransform} result
  * @returns {Boolean}
  */
QTransform.squareToQuad = function(square, result){return new Boolean();};

/**
  * @default 0x00
  * @constant
  * @memberOf QTransform
  * @name TxNone
  * @see QTransform#TransformationType
  * @type Number
  */
QTransform.TxNone = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QTransform
  * @name TxTranslate
  * @see QTransform#TransformationType
  * @type Number
  */
QTransform.TxTranslate = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QTransform
  * @name TxScale
  * @see QTransform#TransformationType
  * @type Number
  */
QTransform.TxScale = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QTransform
  * @name TxRotate
  * @see QTransform#TransformationType
  * @type Number
  */
QTransform.TxRotate = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QTransform
  * @name TxShear
  * @see QTransform#TransformationType
  * @type Number
  */
QTransform.TxShear = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QTransform
  * @name TxProject
  * @see QTransform#TransformationType
  * @type Number
  */
QTransform.TxProject = 0x10;

/**
  * @constructor 
  * @memberOf QTransform
  * @name TransformationType
  */
QTransform.TransformationType = function(value){;};



/**
  * @name adjoint
  * @function
  * @memberOf QTransform.prototype
  * @returns {QTransform}
  */
QTransform.prototype.adjoint = function(){return new QTransform();};

/**
  * @name det
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.det = function(){return new Numeric();};

/**
  * @name determinant
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.determinant = function(){return new Numeric();};

/**
  * @name dx
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.dx = function(){return new Numeric();};

/**
  * @name dy
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.dy = function(){return new Numeric();};

/**
  * @name inverted
  * @function
  * @memberOf QTransform.prototype
  * @param {Boolean} invertible
  * @returns {QTransform}
  */
QTransform.prototype.inverted = function(invertible){return new QTransform();};

/**
  * @name isAffine
  * @function
  * @memberOf QTransform.prototype
  * @returns {Boolean}
  */
QTransform.prototype.isAffine = function(){return new Boolean();};

/**
  * @name isIdentity
  * @function
  * @memberOf QTransform.prototype
  * @returns {Boolean}
  */
QTransform.prototype.isIdentity = function(){return new Boolean();};

/**
  * @name isInvertible
  * @function
  * @memberOf QTransform.prototype
  * @returns {Boolean}
  */
QTransform.prototype.isInvertible = function(){return new Boolean();};

/**
  * @name isRotating
  * @function
  * @memberOf QTransform.prototype
  * @returns {Boolean}
  */
QTransform.prototype.isRotating = function(){return new Boolean();};

/**
  * @name isScaling
  * @function
  * @memberOf QTransform.prototype
  * @returns {Boolean}
  */
QTransform.prototype.isScaling = function(){return new Boolean();};

/**
  * @name isTranslating
  * @function
  * @memberOf QTransform.prototype
  * @returns {Boolean}
  */
QTransform.prototype.isTranslating = function(){return new Boolean();};

/**
  * @name m11
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m11 = function(){return new Numeric();};

/**
  * @name m12
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m12 = function(){return new Numeric();};

/**
  * @name m13
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m13 = function(){return new Numeric();};

/**
  * @name m21
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m21 = function(){return new Numeric();};

/**
  * @name m22
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m22 = function(){return new Numeric();};

/**
  * @name m23
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m23 = function(){return new Numeric();};

/**
  * @name m31
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m31 = function(){return new Numeric();};

/**
  * @name m32
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m32 = function(){return new Numeric();};

/**
  * @name m33
  * @function
  * @memberOf QTransform.prototype
  * @returns {Numeric}
  */
QTransform.prototype.m33 = function(){return new Numeric();};

/**
  * @name map
  * @function
  * @memberOf QTransform.prototype
  * @param {QLine} l
  * @returns {QLine}
  */
QTransform.prototype.map = function(l){return new QLine();};

/**
  * @name mapRect
  * @function
  * @memberOf QTransform.prototype
  * @param {QRect} arg__1
  * @returns {QRect}
  */
QTransform.prototype.mapRect = function(arg__1){return new QRect();};

/**
  * @name mapToPolygon
  * @function
  * @memberOf QTransform.prototype
  * @param {QRect} r
  * @returns {QPolygon}
  */
QTransform.prototype.mapToPolygon = function(r){return new QPolygon();};

/**
  * @name multiplied
  * @function
  * @memberOf QTransform.prototype
  * @param {QTransform} o
  * @returns {QTransform}
  */
QTransform.prototype.multiplied = function(o){return new QTransform();};

/**
  * @name operator_add_assign
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} div
  * @returns {QTransform}
  */
QTransform.prototype.operator_add_assign = function(div){return new QTransform();};

/**
  * @name operator_divide_assign
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} div
  * @returns {QTransform}
  */
QTransform.prototype.operator_divide_assign = function(div){return new QTransform();};

/**
  * @name operator_equal
  * @function
  * @memberOf QTransform.prototype
  * @param {QTransform} arg__1
  * @returns {Boolean}
  */
QTransform.prototype.operator_equal = function(arg__1){return new Boolean();};

/**
  * @name operator_multiply_assign
  * @function
  * @memberOf QTransform.prototype
  * @param {QTransform} arg__1
  * @returns {QTransform}
  */
QTransform.prototype.operator_multiply_assign = function(arg__1){return new QTransform();};

/**
  * @name operator_subtract_assign
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} div
  * @returns {QTransform}
  */
QTransform.prototype.operator_subtract_assign = function(div){return new QTransform();};

/**
  * @name readFrom
  * @function
  * @memberOf QTransform.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QTransform.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name reset
  * @function
  * @memberOf QTransform.prototype
  * @returns {undefined}
  */
QTransform.prototype.reset = function(){return undefined;};

/**
  * @name rotate
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} a
  * @param {Qt.Axis} axis
  * @returns {QTransform}
  */
QTransform.prototype.rotate = function(a, axis){return new QTransform();};

/**
  * @name rotateRadians
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} a
  * @param {Qt.Axis} axis
  * @returns {QTransform}
  */
QTransform.prototype.rotateRadians = function(a, axis){return new QTransform();};

/**
  * @name scale
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} sx
  * @param {Numeric} sy
  * @returns {QTransform}
  */
QTransform.prototype.scale = function(sx, sy){return new QTransform();};

/**
  * @name setMatrix
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} m11
  * @param {Numeric} m12
  * @param {Numeric} m13
  * @param {Numeric} m21
  * @param {Numeric} m22
  * @param {Numeric} m23
  * @param {Numeric} m31
  * @param {Numeric} m32
  * @param {Numeric} m33
  * @returns {undefined}
  */
QTransform.prototype.setMatrix = function(m11, m12, m13, m21, m22, m23, m31, m32, m33){return undefined;};

/**
  * @name shear
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} sh
  * @param {Numeric} sv
  * @returns {QTransform}
  */
QTransform.prototype.shear = function(sh, sv){return new QTransform();};

/**
  * @name toAffine
  * @function
  * @memberOf QTransform.prototype
  * @returns {QMatrix}
  */
QTransform.prototype.toAffine = function(){return new QMatrix();};

/**
  * @name translate
  * @function
  * @memberOf QTransform.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {QTransform}
  */
QTransform.prototype.translate = function(dx, dy){return new QTransform();};

/**
  * @name transposed
  * @function
  * @memberOf QTransform.prototype
  * @returns {QTransform}
  */
QTransform.prototype.transposed = function(){return new QTransform();};

/**
  * @name type
  * @function
  * @memberOf QTransform.prototype
  * @returns {QTransform.TransformationType}
  */
QTransform.prototype.type = function(){return new QTransform.TransformationType();};

/**
  * @name writeTo
  * @function
  * @memberOf QTransform.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QTransform.prototype.writeTo = function(arg__1){return undefined;};

