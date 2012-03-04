/**
  * @name QMutex
  * @constructor
  * @param {QMutex.RecursionMode} mode
  */
function QMutex(mode){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QMutex
  * @name NonRecursive
  * @see QMutex#RecursionMode
  * @type Number
  */
QMutex.NonRecursive = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QMutex
  * @name Recursive
  * @see QMutex#RecursionMode
  * @type Number
  */
QMutex.Recursive = 0x1;

/**
  * @constructor 
  * @memberOf QMutex
  * @name RecursionMode
  */
QMutex.RecursionMode = function(value){;};



/**
  * @name lock
  * @function
  * @memberOf QMutex.prototype
  * @returns {undefined}
  */
QMutex.prototype.lock = function(){return undefined;};

/**
  * @name lockInline
  * @function
  * @memberOf QMutex.prototype
  * @returns {undefined}
  */
QMutex.prototype.lockInline = function(){return undefined;};

/**
  * @name tryLock
  * @function
  * @memberOf QMutex.prototype
  * @returns {Boolean}
  */
QMutex.prototype.tryLock = function(){return new Boolean();};

/**
  * @name tryLockInline
  * @function
  * @memberOf QMutex.prototype
  * @returns {Boolean}
  */
QMutex.prototype.tryLockInline = function(){return new Boolean();};

/**
  * @name unlock
  * @function
  * @memberOf QMutex.prototype
  * @returns {undefined}
  */
QMutex.prototype.unlock = function(){return undefined;};

/**
  * @name unlockInline
  * @function
  * @memberOf QMutex.prototype
  * @returns {undefined}
  */
QMutex.prototype.unlockInline = function(){return undefined;};

