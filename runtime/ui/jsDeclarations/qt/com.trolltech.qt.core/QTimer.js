/**
  * @name QTimer
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QTimer(parent){return undefined;};

QTimer.prototype = new QObject();

/**
  * @name timerId
  * @function
  * @memberOf QTimer.prototype
  * @returns {Numeric}
  */
QTimer.prototype.timerId = function(){return new Numeric();};

/**
  * @name singleShot
  * @memberOf QTimer.prototype
  * @type Boolean
  */
QTimer.prototype.singleShot = new Boolean();

/**
  * @name interval
  * @memberOf QTimer.prototype
  * @type Numeric
  */
QTimer.prototype.interval = new Numeric();

/**
  * @name active
  * @memberOf QTimer.prototype
  * @type Boolean
  */
QTimer.prototype.active = new Boolean();


