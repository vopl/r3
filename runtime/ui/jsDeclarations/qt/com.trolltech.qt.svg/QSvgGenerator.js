/**
  * @name QSvgGenerator
  * @constructor
  * @extends QPaintDevice
  */
function QSvgGenerator(){return undefined;};

/**
  * @name setViewBox
  * @function
  * @memberOf QSvgGenerator.prototype
  * @param {QRect} viewBox
  * @returns {undefined}
  */
QSvgGenerator.prototype.setViewBox = function(viewBox){return undefined;};

/**
  * @name viewBox
  * @function
  * @memberOf QSvgGenerator.prototype
  * @returns {QRect}
  */
QSvgGenerator.prototype.viewBox = function(){return new QRect();};

/**
  * @name size
  * @memberOf QSvgGenerator.prototype
  * @type QSize
  */
QSvgGenerator.prototype.size = new QSize();

/**
  * @name viewBox
  * @memberOf QSvgGenerator.prototype
  * @type QRectF
  */
QSvgGenerator.prototype.viewBox = new QRectF();

/**
  * @name title
  * @memberOf QSvgGenerator.prototype
  * @type String
  */
QSvgGenerator.prototype.title = new String();

/**
  * @name description
  * @memberOf QSvgGenerator.prototype
  * @type String
  */
QSvgGenerator.prototype.description = new String();

/**
  * @name fileName
  * @memberOf QSvgGenerator.prototype
  * @type String
  */
QSvgGenerator.prototype.fileName = new String();

/**
  * @name outputDevice
  * @memberOf QSvgGenerator.prototype
  * @type QIODevice
  */
QSvgGenerator.prototype.outputDevice = new QIODevice();

/**
  * @name resolution
  * @memberOf QSvgGenerator.prototype
  * @type Numeric
  */
QSvgGenerator.prototype.resolution = new Numeric();


