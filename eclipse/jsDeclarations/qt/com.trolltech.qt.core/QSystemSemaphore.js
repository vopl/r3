/**
  * @name QSystemSemaphore
  * @constructor
  * @param {String} key
  * @param {Numeric} initialValue
  * @param {QSystemSemaphore.AccessMode} mode
  */
function QSystemSemaphore(key, initialValue, mode){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QSystemSemaphore
  * @name Open
  * @see QSystemSemaphore#AccessMode
  * @type Number
  */
QSystemSemaphore.Open = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSystemSemaphore
  * @name Create
  * @see QSystemSemaphore#AccessMode
  * @type Number
  */
QSystemSemaphore.Create = 0x1;

/**
  * @constructor 
  * @memberOf QSystemSemaphore
  * @name AccessMode
  */
QSystemSemaphore.AccessMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSystemSemaphore
  * @name NoError
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSystemSemaphore
  * @name PermissionDenied
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.PermissionDenied = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSystemSemaphore
  * @name KeyError
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.KeyError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSystemSemaphore
  * @name AlreadyExists
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.AlreadyExists = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSystemSemaphore
  * @name NotFound
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.NotFound = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QSystemSemaphore
  * @name OutOfResources
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.OutOfResources = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QSystemSemaphore
  * @name UnknownError
  * @see QSystemSemaphore#SystemSemaphoreError
  * @type Number
  */
QSystemSemaphore.UnknownError = 0x6;

/**
  * @constructor 
  * @memberOf QSystemSemaphore
  * @name SystemSemaphoreError
  */
QSystemSemaphore.SystemSemaphoreError = function(value){;};



/**
  * @name acquire
  * @function
  * @memberOf QSystemSemaphore.prototype
  * @returns {Boolean}
  */
QSystemSemaphore.prototype.acquire = function(){return new Boolean();};

/**
  * @name error
  * @function
  * @memberOf QSystemSemaphore.prototype
  * @returns {QSystemSemaphore.SystemSemaphoreError}
  */
QSystemSemaphore.prototype.error = function(){return new QSystemSemaphore.SystemSemaphoreError();};

/**
  * @name errorString
  * @function
  * @memberOf QSystemSemaphore.prototype
  * @returns {String}
  */
QSystemSemaphore.prototype.errorString = function(){return new String();};

/**
  * @name key
  * @function
  * @memberOf QSystemSemaphore.prototype
  * @returns {String}
  */
QSystemSemaphore.prototype.key = function(){return new String();};

/**
  * @name release
  * @function
  * @memberOf QSystemSemaphore.prototype
  * @param {Numeric} n
  * @returns {Boolean}
  */
QSystemSemaphore.prototype.release = function(n){return new Boolean();};

/**
  * @name setKey
  * @function
  * @memberOf QSystemSemaphore.prototype
  * @param {String} key
  * @param {Numeric} initialValue
  * @param {QSystemSemaphore.AccessMode} mode
  * @returns {undefined}
  */
QSystemSemaphore.prototype.setKey = function(key, initialValue, mode){return undefined;};

