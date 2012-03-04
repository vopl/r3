/**
  * @name QStylePainter
  * @constructor
  * @extends QPainter
  */
function QStylePainter(){return undefined;};

/**
  * @name QStylePainter^1
  * @constructor
  * @extends QPainter
  * @param {QPaintDevice} pd
  * @param {QWidget} w
  */
function QStylePainter(pd, w){return undefined;};

/**
  * @name QStylePainter^2
  * @constructor
  * @extends QPainter
  * @param {QWidget} w
  */
function QStylePainter(w){return undefined;};

QStylePainter.prototype = new QPainter();

/**
  * @name begin
  * @function
  * @memberOf QStylePainter.prototype
  * @param {QPaintDevice} pd
  * @param {QWidget} w
  * @returns {Boolean}
  */
QStylePainter.prototype.begin = function(pd, w){return new Boolean();};

/**
  * @name drawComplexControl
  * @function
  * @memberOf QStylePainter.prototype
  * @param {QStyle.ComplexControl} cc
  * @param {QStyleOptionComplex} opt
  * @returns {undefined}
  */
QStylePainter.prototype.drawComplexControl = function(cc, opt){return undefined;};

/**
  * @name drawControl
  * @function
  * @memberOf QStylePainter.prototype
  * @param {QStyle.ControlElement} ce
  * @param {QStyleOption} opt
  * @returns {undefined}
  */
QStylePainter.prototype.drawControl = function(ce, opt){return undefined;};

/**
  * @name drawItemPixmap
  * @function
  * @memberOf QStylePainter.prototype
  * @param {QRect} r
  * @param {Numeric} flags
  * @param {QPixmap} pixmap
  * @returns {undefined}
  */
QStylePainter.prototype.drawItemPixmap = function(r, flags, pixmap){return undefined;};

/**
  * @name drawItemText
  * @function
  * @memberOf QStylePainter.prototype
  * @param {QRect} r
  * @param {Numeric} flags
  * @param {QPalette} pal
  * @param {Boolean} enabled
  * @param {String} text
  * @param {QPalette.ColorRole} textRole
  * @returns {undefined}
  */
QStylePainter.prototype.drawItemText = function(r, flags, pal, enabled, text, textRole){return undefined;};

/**
  * @name drawPrimitive
  * @function
  * @memberOf QStylePainter.prototype
  * @param {QStyle.PrimitiveElement} pe
  * @param {QStyleOption} opt
  * @returns {undefined}
  */
QStylePainter.prototype.drawPrimitive = function(pe, opt){return undefined;};

/**
  * @name style
  * @function
  * @memberOf QStylePainter.prototype
  * @returns {QStyle}
  */
QStylePainter.prototype.style = function(){return new QStyle();};

