/**
  * @name QSqlError
  * @constructor
  * @param {QSqlError} other
  */
function QSqlError(other){return undefined;};

/**
  * @name QSqlError^1
  * @constructor
  * @param {String} driverText
  * @param {String} databaseText
  * @param {Phonon.ErrorType} type
  * @param {Numeric} number
  */
function QSqlError(driverText, databaseText, type, number){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QSqlError
  * @name NoError
  * @see QSqlError#ErrorType
  * @type Number
  */
QSqlError.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSqlError
  * @name ConnectionError
  * @see QSqlError#ErrorType
  * @type Number
  */
QSqlError.ConnectionError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSqlError
  * @name StatementError
  * @see QSqlError#ErrorType
  * @type Number
  */
QSqlError.StatementError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSqlError
  * @name TransactionError
  * @see QSqlError#ErrorType
  * @type Number
  */
QSqlError.TransactionError = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSqlError
  * @name UnknownError
  * @see QSqlError#ErrorType
  * @type Number
  */
QSqlError.UnknownError = 0x4;

/**
  * @constructor 
  * @memberOf QSqlError
  * @name ErrorType
  */
QSqlError.ErrorType = function(value){;};



/**
  * @name databaseText
  * @function
  * @memberOf QSqlError.prototype
  * @returns {String}
  */
QSqlError.prototype.databaseText = function(){return new String();};

/**
  * @name driverText
  * @function
  * @memberOf QSqlError.prototype
  * @returns {String}
  */
QSqlError.prototype.driverText = function(){return new String();};

/**
  * @name isValid
  * @function
  * @memberOf QSqlError.prototype
  * @returns {Boolean}
  */
QSqlError.prototype.isValid = function(){return new Boolean();};

/**
  * @name number
  * @function
  * @memberOf QSqlError.prototype
  * @returns {Numeric}
  */
QSqlError.prototype.number = function(){return new Numeric();};

/**
  * @name setDatabaseText
  * @function
  * @memberOf QSqlError.prototype
  * @param {String} databaseText
  * @returns {undefined}
  */
QSqlError.prototype.setDatabaseText = function(databaseText){return undefined;};

/**
  * @name setDriverText
  * @function
  * @memberOf QSqlError.prototype
  * @param {String} driverText
  * @returns {undefined}
  */
QSqlError.prototype.setDriverText = function(driverText){return undefined;};

/**
  * @name setNumber
  * @function
  * @memberOf QSqlError.prototype
  * @param {Numeric} number
  * @returns {undefined}
  */
QSqlError.prototype.setNumber = function(number){return undefined;};

/**
  * @name setType
  * @function
  * @memberOf QSqlError.prototype
  * @param {Phonon.ErrorType} type
  * @returns {undefined}
  */
QSqlError.prototype.setType = function(type){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QSqlError.prototype
  * @returns {String}
  */
QSqlError.prototype.text = function(){return new String();};

/**
  * @name type
  * @function
  * @memberOf QSqlError.prototype
  * @returns {Phonon.ErrorType}
  */
QSqlError.prototype.type = function(){return new Phonon.ErrorType();};

