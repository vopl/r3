/**
  * @name QReadWriteLock
  * @constructor
  */
function QReadWriteLock(){return undefined;};

/**
  * @name QReadWriteLock^1
  * @constructor
  * @param {QMutex.RecursionMode} recursionMode
  */
function QReadWriteLock(recursionMode){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QReadWriteLock
  * @name NonRecursive
  * @see QReadWriteLock#RecursionMode
  * @type Number
  */
QReadWriteLock.NonRecursive = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QReadWriteLock
  * @name Recursive
  * @see QReadWriteLock#RecursionMode
  * @type Number
  */
QReadWriteLock.Recursive = 0x1;

/**
  * @constructor 
  * @memberOf QReadWriteLock
  * @name RecursionMode
  */
QReadWriteLock.RecursionMode = function(value){;};



/**
  * @name lockForRead
  * @function
  * @memberOf QReadWriteLock.prototype
  * @returns {undefined}
  */
QReadWriteLock.prototype.lockForRead = function(){return undefined;};

/**
  * @name lockForWrite
  * @function
  * @memberOf QReadWriteLock.prototype
  * @returns {undefined}
  */
QReadWriteLock.prototype.lockForWrite = function(){return undefined;};

/**
  * @name tryLockForRead
  * @function
  * @memberOf QReadWriteLock.prototype
  * @returns {Boolean}
  */
QReadWriteLock.prototype.tryLockForRead = function(){return new Boolean();};

/**
  * @name tryLockForWrite
  * @function
  * @memberOf QReadWriteLock.prototype
  * @returns {Boolean}
  */
QReadWriteLock.prototype.tryLockForWrite = function(){return new Boolean();};

/**
  * @name unlock
  * @function
  * @memberOf QReadWriteLock.prototype
  * @returns {undefined}
  */
QReadWriteLock.prototype.unlock = function(){return undefined;};

