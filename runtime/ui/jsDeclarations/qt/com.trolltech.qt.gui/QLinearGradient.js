/**
  * @name QLinearGradient
  * @constructor
  * @extends QGradient
  */
function QLinearGradient(){return undefined;};

/**
  * @name QLinearGradient^1
  * @constructor
  * @extends QGradient
  * @param {QPointF} start
  * @param {QPointF} finalStop
  */
function QLinearGradient(start, finalStop){return undefined;};

/**
  * @name QLinearGradient^2
  * @constructor
  * @extends QGradient
  * @param {Numeric} xStart
  * @param {Numeric} yStart
  * @param {Numeric} xFinalStop
  * @param {Numeric} yFinalStop
  */
function QLinearGradient(xStart, yStart, xFinalStop, yFinalStop){return undefined;};

QLinearGradient.prototype = new QGradient();

/**
  * @name finalStop
  * @function
  * @memberOf QLinearGradient.prototype
  * @returns {QPointF}
  */
QLinearGradient.prototype.finalStop = function(){return new QPointF();};

/**
  * @name setFinalStop
  * @function
  * @memberOf QLinearGradient.prototype
  * @param {QPointF} stop
  * @returns {undefined}
  */
QLinearGradient.prototype.setFinalStop = function(stop){return undefined;};

/**
  * @name setStart
  * @function
  * @memberOf QLinearGradient.prototype
  * @param {QPointF} start
  * @returns {undefined}
  */
QLinearGradient.prototype.setStart = function(start){return undefined;};

/**
  * @name start
  * @function
  * @memberOf QLinearGradient.prototype
  * @returns {QPointF}
  */
QLinearGradient.prototype.start = function(){return new QPointF();};

