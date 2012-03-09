/**
  * @name QConicalGradient
  * @constructor
  * @extends QGradient
  */
function QConicalGradient(){return undefined;};

/**
  * @name QConicalGradient^1
  * @constructor
  * @extends QGradient
  * @param {QPointF} center
  * @param {Numeric} startAngle
  */
function QConicalGradient(center, startAngle){return undefined;};

/**
  * @name QConicalGradient^2
  * @constructor
  * @extends QGradient
  * @param {Numeric} cx
  * @param {Numeric} cy
  * @param {Numeric} startAngle
  */
function QConicalGradient(cx, cy, startAngle){return undefined;};

QConicalGradient.prototype = new QGradient();

/**
  * @name angle
  * @function
  * @memberOf QConicalGradient.prototype
  * @returns {Numeric}
  */
QConicalGradient.prototype.angle = function(){return new Numeric();};

/**
  * @name center
  * @function
  * @memberOf QConicalGradient.prototype
  * @returns {QPointF}
  */
QConicalGradient.prototype.center = function(){return new QPointF();};

/**
  * @name setAngle
  * @function
  * @memberOf QConicalGradient.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QConicalGradient.prototype.setAngle = function(angle){return undefined;};

/**
  * @name setCenter
  * @function
  * @memberOf QConicalGradient.prototype
  * @param {QPointF} center
  * @returns {undefined}
  */
QConicalGradient.prototype.setCenter = function(center){return undefined;};

