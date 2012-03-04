/**
  * @name QThreadPool
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QThreadPool(parent){return undefined;};

QThreadPool.prototype = new QObject();

/**
  * @name globalInstance
  * @function
  * @memberOf QThreadPool
  * @returns {QThreadPool}
  */
QThreadPool.globalInstance = function(){return new QThreadPool();};

/**
  * @name releaseThread
  * @function
  * @memberOf QThreadPool.prototype
  * @returns {undefined}
  */
QThreadPool.prototype.releaseThread = function(){return undefined;};

/**
  * @name reserveThread
  * @function
  * @memberOf QThreadPool.prototype
  * @returns {undefined}
  */
QThreadPool.prototype.reserveThread = function(){return undefined;};

/**
  * @name start
  * @function
  * @memberOf QThreadPool.prototype
  * @param {QRunnable} runnable
  * @param {Numeric} priority
  * @returns {undefined}
  */
QThreadPool.prototype.start = function(runnable, priority){return undefined;};

/**
  * @name tryStart
  * @function
  * @memberOf QThreadPool.prototype
  * @param {QRunnable} runnable
  * @returns {Boolean}
  */
QThreadPool.prototype.tryStart = function(runnable){return new Boolean();};

/**
  * @name waitForDone
  * @function
  * @memberOf QThreadPool.prototype
  * @returns {undefined}
  */
QThreadPool.prototype.waitForDone = function(){return undefined;};

/**
  * @name expiryTimeout
  * @memberOf QThreadPool.prototype
  * @type Numeric
  */
QThreadPool.prototype.expiryTimeout = new Numeric();

/**
  * @name maxThreadCount
  * @memberOf QThreadPool.prototype
  * @type Numeric
  */
QThreadPool.prototype.maxThreadCount = new Numeric();

/**
  * @name activeThreadCount
  * @memberOf QThreadPool.prototype
  * @type Numeric
  */
QThreadPool.prototype.activeThreadCount = new Numeric();


