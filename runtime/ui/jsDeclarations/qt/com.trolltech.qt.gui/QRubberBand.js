/**
  * @name QRubberBand
  * @constructor
  * @extends QWidget
  * @param {QTabBar.Shape} arg__1
  * @param {QWidget} arg__2
  */
function QRubberBand(arg__1, arg__2){return undefined;};

QRubberBand.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QRubberBand
  * @name Line
  * @see QRubberBand#Shape
  * @type Number
  */
QRubberBand.Line = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QRubberBand
  * @name Rectangle
  * @see QRubberBand#Shape
  * @type Number
  */
QRubberBand.Rectangle = 0x1;

/**
  * @constructor 
  * @memberOf QRubberBand
  * @name Shape
  */
QRubberBand.Shape = function(value){;};



/**
  * @name moveRubberBand
  * @function
  * @memberOf QRubberBand.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QRubberBand.prototype.moveRubberBand = function(p){return undefined;};

/**
  * @name resizeRubberBand
  * @function
  * @memberOf QRubberBand.prototype
  * @param {QSize} s
  * @returns {undefined}
  */
QRubberBand.prototype.resizeRubberBand = function(s){return undefined;};

/**
  * @name setRubberBandGeometry
  * @function
  * @memberOf QRubberBand.prototype
  * @param {QRect} r
  * @returns {undefined}
  */
QRubberBand.prototype.setRubberBandGeometry = function(r){return undefined;};

/**
  * @name shape
  * @function
  * @memberOf QRubberBand.prototype
  * @returns {QTabBar.Shape}
  */
QRubberBand.prototype.shape = function(){return new QTabBar.Shape();};

