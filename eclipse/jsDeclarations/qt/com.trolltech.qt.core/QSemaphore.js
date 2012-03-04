/**
  * @name QSemaphore
  * @constructor
  * @param {Numeric} n
  */
function QSemaphore(n){return undefined;};

/**
  * @name acquire
  * @function
  * @memberOf QSemaphore.prototype
  * @param {Numeric} n
  * @returns {undefined}
  */
QSemaphore.prototype.acquire = function(n){return undefined;};

/**
  * @name available
  * @function
  * @memberOf QSemaphore.prototype
  * @returns {Numeric}
  */
QSemaphore.prototype.available = function(){return new Numeric();};

/**
  * @name release
  * @function
  * @memberOf QSemaphore.prototype
  * @param {Numeric} n
  * @returns {undefined}
  */
QSemaphore.prototype.release = function(n){return undefined;};

/**
  * @name tryAcquire
  * @function
  * @memberOf QSemaphore.prototype
  * @param {Numeric} n
  * @returns {Boolean}
  */
QSemaphore.prototype.tryAcquire = function(n){return new Boolean();};

