/**
  * @name QRect
  * @constructor
  */
function QRect(){return undefined;};

/**
  * @name QRect^1
  * @constructor
  * @param {QPoint} topleft
  * @param {QPoint} bottomright
  */
function QRect(topleft, bottomright){return undefined;};

/**
  * @name QRect^2
  * @constructor
  * @param {QPoint} topleft
  * @param {QSize} size
  */
function QRect(topleft, size){return undefined;};

/**
  * @name QRect^3
  * @constructor
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} width
  * @param {Numeric} height
  */
function QRect(left, top, width, height){return undefined;};

/**
  * @name adjust
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  * @returns {undefined}
  */
QRect.prototype.adjust = function(x1, y1, x2, y2){return undefined;};

/**
  * @name adjusted
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  * @returns {QRect}
  */
QRect.prototype.adjusted = function(x1, y1, x2, y2){return new QRect();};

/**
  * @name bottom
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.bottom = function(){return new Numeric();};

/**
  * @name bottomLeft
  * @function
  * @memberOf QRect.prototype
  * @returns {QPoint}
  */
QRect.prototype.bottomLeft = function(){return new QPoint();};

/**
  * @name bottomRight
  * @function
  * @memberOf QRect.prototype
  * @returns {QPoint}
  */
QRect.prototype.bottomRight = function(){return new QPoint();};

/**
  * @name center
  * @function
  * @memberOf QRect.prototype
  * @returns {QPoint}
  */
QRect.prototype.center = function(){return new QPoint();};

/**
  * @name contains
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @param {Boolean} proper
  * @returns {Boolean}
  */
QRect.prototype.contains = function(p, proper){return new Boolean();};

/**
  * @name height
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.height = function(){return new Numeric();};

/**
  * @name intersected
  * @function
  * @memberOf QRect.prototype
  * @param {QRect} other
  * @returns {QRect}
  */
QRect.prototype.intersected = function(other){return new QRect();};

/**
  * @name intersects
  * @function
  * @memberOf QRect.prototype
  * @param {QRect} r
  * @returns {Boolean}
  */
QRect.prototype.intersects = function(r){return new Boolean();};

/**
  * @name isEmpty
  * @function
  * @memberOf QRect.prototype
  * @returns {Boolean}
  */
QRect.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QRect.prototype
  * @returns {Boolean}
  */
QRect.prototype.isNull = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QRect.prototype
  * @returns {Boolean}
  */
QRect.prototype.isValid = function(){return new Boolean();};

/**
  * @name left
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.left = function(){return new Numeric();};

/**
  * @name moveBottom
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.moveBottom = function(pos){return undefined;};

/**
  * @name moveBottomLeft
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.moveBottomLeft = function(p){return undefined;};

/**
  * @name moveBottomRight
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.moveBottomRight = function(p){return undefined;};

/**
  * @name moveCenter
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.moveCenter = function(p){return undefined;};

/**
  * @name moveLeft
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.moveLeft = function(pos){return undefined;};

/**
  * @name moveRight
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.moveRight = function(pos){return undefined;};

/**
  * @name moveTo
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.moveTo = function(p){return undefined;};

/**
  * @name moveTop
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.moveTop = function(pos){return undefined;};

/**
  * @name moveTopLeft
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.moveTopLeft = function(p){return undefined;};

/**
  * @name moveTopRight
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.moveTopRight = function(p){return undefined;};

/**
  * @name normalized
  * @function
  * @memberOf QRect.prototype
  * @returns {QRect}
  */
QRect.prototype.normalized = function(){return new QRect();};

/**
  * @name operator_equal
  * @function
  * @memberOf QRect.prototype
  * @param {QRect} arg__2
  * @returns {Boolean}
  */
QRect.prototype.operator_equal = function(arg__2){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QRect.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QRect.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name right
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.right = function(){return new Numeric();};

/**
  * @name setBottom
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.setBottom = function(pos){return undefined;};

/**
  * @name setBottomLeft
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.setBottomLeft = function(p){return undefined;};

/**
  * @name setBottomRight
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.setBottomRight = function(p){return undefined;};

/**
  * @name setCoords
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} x1
  * @param {Numeric} y1
  * @param {Numeric} x2
  * @param {Numeric} y2
  * @returns {undefined}
  */
QRect.prototype.setCoords = function(x1, y1, x2, y2){return undefined;};

/**
  * @name setHeight
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} h
  * @returns {undefined}
  */
QRect.prototype.setHeight = function(h){return undefined;};

/**
  * @name setLeft
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.setLeft = function(pos){return undefined;};

/**
  * @name setRect
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QRect.prototype.setRect = function(x, y, w, h){return undefined;};

/**
  * @name setRight
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.setRight = function(pos){return undefined;};

/**
  * @name setSize
  * @function
  * @memberOf QRect.prototype
  * @param {QSize} s
  * @returns {undefined}
  */
QRect.prototype.setSize = function(s){return undefined;};

/**
  * @name setTop
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} pos
  * @returns {undefined}
  */
QRect.prototype.setTop = function(pos){return undefined;};

/**
  * @name setTopLeft
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.setTopLeft = function(p){return undefined;};

/**
  * @name setTopRight
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.setTopRight = function(p){return undefined;};

/**
  * @name setWidth
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} w
  * @returns {undefined}
  */
QRect.prototype.setWidth = function(w){return undefined;};

/**
  * @name setX
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} x
  * @returns {undefined}
  */
QRect.prototype.setX = function(x){return undefined;};

/**
  * @name setY
  * @function
  * @memberOf QRect.prototype
  * @param {Numeric} y
  * @returns {undefined}
  */
QRect.prototype.setY = function(y){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QRect.prototype
  * @returns {QSize}
  */
QRect.prototype.size = function(){return new QSize();};

/**
  * @name top
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.top = function(){return new Numeric();};

/**
  * @name topLeft
  * @function
  * @memberOf QRect.prototype
  * @returns {QPoint}
  */
QRect.prototype.topLeft = function(){return new QPoint();};

/**
  * @name topRight
  * @function
  * @memberOf QRect.prototype
  * @returns {QPoint}
  */
QRect.prototype.topRight = function(){return new QPoint();};

/**
  * @name translate
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRect.prototype.translate = function(p){return undefined;};

/**
  * @name translated
  * @function
  * @memberOf QRect.prototype
  * @param {QPoint} p
  * @returns {QRect}
  */
QRect.prototype.translated = function(p){return new QRect();};

/**
  * @name united
  * @function
  * @memberOf QRect.prototype
  * @param {QRect} other
  * @returns {QRect}
  */
QRect.prototype.united = function(other){return new QRect();};

/**
  * @name width
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.width = function(){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QRect.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QRect.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name x
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QRect.prototype
  * @returns {Numeric}
  */
QRect.prototype.y = function(){return new Numeric();};

