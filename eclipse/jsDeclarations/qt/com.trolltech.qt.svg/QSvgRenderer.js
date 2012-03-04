/**
  * @name QSvgRenderer
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QSvgRenderer(parent){return undefined;};

/**
  * @name QSvgRenderer^1
  * @constructor
  * @extends QObject
  * @param {QXmlStreamReader} contents
  * @param {QObject} parent
  */
function QSvgRenderer(contents, parent){return undefined;};

/**
  * @name QSvgRenderer^2
  * @constructor
  * @extends QObject
  * @param {QByteArray} contents
  * @param {QObject} parent
  */
function QSvgRenderer(contents, parent){return undefined;};

/**
  * @name QSvgRenderer^3
  * @constructor
  * @extends QObject
  * @param {String} filename
  * @param {QObject} parent
  */
function QSvgRenderer(filename, parent){return undefined;};

QSvgRenderer.prototype = new QObject();

/**
  * @name animated
  * @function
  * @memberOf QSvgRenderer.prototype
  * @returns {Boolean}
  */
QSvgRenderer.prototype.animated = function(){return new Boolean();};

/**
  * @name animationDuration
  * @function
  * @memberOf QSvgRenderer.prototype
  * @returns {Numeric}
  */
QSvgRenderer.prototype.animationDuration = function(){return new Numeric();};

/**
  * @name boundsOnElement
  * @function
  * @memberOf QSvgRenderer.prototype
  * @param {String} id
  * @returns {QRectF}
  */
QSvgRenderer.prototype.boundsOnElement = function(id){return new QRectF();};

/**
  * @name defaultSize
  * @function
  * @memberOf QSvgRenderer.prototype
  * @returns {QSize}
  */
QSvgRenderer.prototype.defaultSize = function(){return new QSize();};

/**
  * @name elementExists
  * @function
  * @memberOf QSvgRenderer.prototype
  * @param {String} id
  * @returns {Boolean}
  */
QSvgRenderer.prototype.elementExists = function(id){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QSvgRenderer.prototype
  * @returns {Boolean}
  */
QSvgRenderer.prototype.isValid = function(){return new Boolean();};

/**
  * @name matrixForElement
  * @function
  * @memberOf QSvgRenderer.prototype
  * @param {String} id
  * @returns {QMatrix}
  */
QSvgRenderer.prototype.matrixForElement = function(id){return new QMatrix();};

/**
  * @name setViewBox
  * @function
  * @memberOf QSvgRenderer.prototype
  * @param {QRect} viewbox
  * @returns {undefined}
  */
QSvgRenderer.prototype.setViewBox = function(viewbox){return undefined;};

/**
  * @name viewBox
  * @function
  * @memberOf QSvgRenderer.prototype
  * @returns {QRect}
  */
QSvgRenderer.prototype.viewBox = function(){return new QRect();};

/**
  * @name viewBox
  * @memberOf QSvgRenderer.prototype
  * @type QRectF
  */
QSvgRenderer.prototype.viewBox = new QRectF();

/**
  * @name framesPerSecond
  * @memberOf QSvgRenderer.prototype
  * @type Numeric
  */
QSvgRenderer.prototype.framesPerSecond = new Numeric();

/**
  * @name currentFrame
  * @memberOf QSvgRenderer.prototype
  * @type Numeric
  */
QSvgRenderer.prototype.currentFrame = new Numeric();


