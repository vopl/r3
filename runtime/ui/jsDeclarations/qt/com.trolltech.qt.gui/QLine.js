/**
  * @name QLine
  * @constructor
  */
function QLine(){return undefined;};

/**
  * @name QLine^1
  * @constructor
  * @param {QPoint} pt1
  * @param {QPoint} pt2
  */
function QLine(pt1, pt2){return undefined;};

/**
  * @name QLine^2
  * @constructor
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  */
function QLine(x1, y1, x2, y2){return undefined;};

/**
  * @name dx
  * @function
  * @memberOf QLine.prototype
  * @returns {Numeric}
  */
QLine.prototype.dx = function(){return new Numeric();};

/**
  * @name dy
  * @function
  * @memberOf QLine.prototype
  * @returns {Numeric}
  */
QLine.prototype.dy = function(){return new Numeric();};

/**
  * @name isNull
  * @function
  * @memberOf QLine.prototype
  * @returns {Boolean}
  */
QLine.prototype.isNull = function(){return new Boolean();};

/**
  * @name operator_equal
  * @function
  * @memberOf QLine.prototype
  * @param {QLine} d
  * @returns {Boolean}
  */
QLine.prototype.operator_equal = function(d){return new Boolean();};

/**
  * @name p1
  * @function
  * @memberOf QLine.prototype
  * @returns {QPoint}
  */
QLine.prototype.p1 = function(){return new QPoint();};

/**
  * @name p2
  * @function
  * @memberOf QLine.prototype
  * @returns {QPoint}
  */
QLine.prototype.p2 = function(){return new QPoint();};

/**
  * @name readFrom
  * @function
  * @memberOf QLine.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QLine.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setLine
  * @function
  * @memberOf QLine.prototype
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  * @returns {undefined}
  */
QLine.prototype.setLine = function(x1, y1, x2, y2){return undefined;};

/**
  * @name setP1
  * @function
  * @memberOf QLine.prototype
  * @param {QPoint} p1
  * @returns {undefined}
  */
QLine.prototype.setP1 = function(p1){return undefined;};

/**
  * @name setP2
  * @function
  * @memberOf QLine.prototype
  * @param {QPoint} p2
  * @returns {undefined}
  */
QLine.prototype.setP2 = function(p2){return undefined;};

/**
  * @name setPoints
  * @function
  * @memberOf QLine.prototype
  * @param {QPoint} p1
  * @param {QPoint} p2
  * @returns {undefined}
  */
QLine.prototype.setPoints = function(p1, p2){return undefined;};

/**
  * @name translate
  * @function
  * @memberOf QLine.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QLine.prototype.translate = function(p){return undefined;};

/**
  * @name translated
  * @function
  * @memberOf QLine.prototype
  * @param {QPoint} p
  * @returns {QLine}
  */
QLine.prototype.translated = function(p){return new QLine();};

/**
  * @name writeTo
  * @function
  * @memberOf QLine.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QLine.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name x1
  * @function
  * @memberOf QLine.prototype
  * @returns {Numeric}
  */
QLine.prototype.x1 = function(){return new Numeric();};

/**
  * @name x2
  * @function
  * @memberOf QLine.prototype
  * @returns {Numeric}
  */
QLine.prototype.x2 = function(){return new Numeric();};

/**
  * @name y1
  * @function
  * @memberOf QLine.prototype
  * @returns {Numeric}
  */
QLine.prototype.y1 = function(){return new Numeric();};

/**
  * @name y2
  * @function
  * @memberOf QLine.prototype
  * @returns {Numeric}
  */
QLine.prototype.y2 = function(){return new Numeric();};

