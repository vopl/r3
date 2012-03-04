/**
  * @name QWaitCondition
  * @constructor
  */
function QWaitCondition(){return undefined;};

/**
  * @name wait
  * @function
  * @memberOf QWaitCondition.prototype
  * @param {QMutex} mutex
  * @param {Numeric} time
  * @returns {Boolean}
  */
QWaitCondition.prototype.wait = function(mutex, time){return new Boolean();};

/**
  * @name wakeAll
  * @function
  * @memberOf QWaitCondition.prototype
  * @returns {undefined}
  */
QWaitCondition.prototype.wakeAll = function(){return undefined;};

/**
  * @name wakeOne
  * @function
  * @memberOf QWaitCondition.prototype
  * @returns {undefined}
  */
QWaitCondition.prototype.wakeOne = function(){return undefined;};

