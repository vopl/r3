/**
  * @name QSqlDatabase
  * @constructor
  */
function QSqlDatabase(){return undefined;};

/**
  * @name QSqlDatabase^1
  * @constructor
  * @param {QSqlDatabase} other
  */
function QSqlDatabase(other){return undefined;};

/**
  * @name addDatabase
  * @function
  * @memberOf QSqlDatabase
  * @param {QSqlDriver} driver
  * @param {String} connectionName
  * @returns {QSqlDatabase}
  */
QSqlDatabase.addDatabase = function(driver, connectionName){return new QSqlDatabase();};

/**
  * @name cloneDatabase
  * @function
  * @memberOf QSqlDatabase
  * @param {QSqlDatabase} other
  * @param {String} connectionName
  * @returns {QSqlDatabase}
  */
QSqlDatabase.cloneDatabase = function(other, connectionName){return new QSqlDatabase();};

/**
  * @name connectionNames
  * @function
  * @memberOf QSqlDatabase
  * @returns {Array}
  */
QSqlDatabase.connectionNames = function(){return new Array();};

/**
  * @name contains
  * @function
  * @memberOf QSqlDatabase
  * @param {String} connectionName
  * @returns {Boolean}
  */
QSqlDatabase.contains = function(connectionName){return new Boolean();};

/**
  * @name database
  * @function
  * @memberOf QSqlDatabase
  * @param {String} connectionName
  * @param {Boolean} open
  * @returns {QSqlDatabase}
  */
QSqlDatabase.database = function(connectionName, open){return new QSqlDatabase();};

/**
  * @name drivers
  * @function
  * @memberOf QSqlDatabase
  * @returns {Array}
  */
QSqlDatabase.drivers = function(){return new Array();};

/**
  * @name isDriverAvailable
  * @function
  * @memberOf QSqlDatabase
  * @param {String} name
  * @returns {Boolean}
  */
QSqlDatabase.isDriverAvailable = function(name){return new Boolean();};

/**
  * @name registerSqlDriver
  * @function
  * @memberOf QSqlDatabase
  * @param {String} name
  * @param {QSqlDriverCreatorBase} creator
  * @returns {undefined}
  */
QSqlDatabase.registerSqlDriver = function(name, creator){return undefined;};

/**
  * @name removeDatabase
  * @function
  * @memberOf QSqlDatabase
  * @param {String} connectionName
  * @returns {undefined}
  */
QSqlDatabase.removeDatabase = function(connectionName){return undefined;};

/**
  * @name close
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {undefined}
  */
QSqlDatabase.prototype.close = function(){return undefined;};

/**
  * @name commit
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.commit = function(){return new Boolean();};

/**
  * @name connectOptions
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.connectOptions = function(){return new String();};

/**
  * @name connectionName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.connectionName = function(){return new String();};

/**
  * @name databaseName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.databaseName = function(){return new String();};

/**
  * @name driver
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {QSqlDriver}
  */
QSqlDatabase.prototype.driver = function(){return new QSqlDriver();};

/**
  * @name driverName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.driverName = function(){return new String();};

/**
  * @name exec
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} query
  * @returns {QSqlQuery}
  */
QSqlDatabase.prototype.exec = function(query){return new QSqlQuery();};

/**
  * @name hostName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.hostName = function(){return new String();};

/**
  * @name isOpen
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.isOpen = function(){return new Boolean();};

/**
  * @name isOpenError
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.isOpenError = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.isValid = function(){return new Boolean();};

/**
  * @name lastError
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {QSqlError}
  */
QSqlDatabase.prototype.lastError = function(){return new QSqlError();};

/**
  * @name numericalPrecisionPolicy
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {QSql.NumericalPrecisionPolicy}
  */
QSqlDatabase.prototype.numericalPrecisionPolicy = function(){return new QSql.NumericalPrecisionPolicy();};

/**
  * @name open
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.open = function(){return new Boolean();};

/**
  * @name password
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.password = function(){return new String();};

/**
  * @name port
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Numeric}
  */
QSqlDatabase.prototype.port = function(){return new Numeric();};

/**
  * @name primaryIndex
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} tablename
  * @returns {QSqlIndex}
  */
QSqlDatabase.prototype.primaryIndex = function(tablename){return new QSqlIndex();};

/**
  * @name record
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} tablename
  * @returns {QSqlRecord}
  */
QSqlDatabase.prototype.record = function(tablename){return new QSqlRecord();};

/**
  * @name rollback
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.rollback = function(){return new Boolean();};

/**
  * @name setConnectOptions
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} options
  * @returns {undefined}
  */
QSqlDatabase.prototype.setConnectOptions = function(options){return undefined;};

/**
  * @name setDatabaseName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} name
  * @returns {undefined}
  */
QSqlDatabase.prototype.setDatabaseName = function(name){return undefined;};

/**
  * @name setHostName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} host
  * @returns {undefined}
  */
QSqlDatabase.prototype.setHostName = function(host){return undefined;};

/**
  * @name setNumericalPrecisionPolicy
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {QSql.NumericalPrecisionPolicy} precisionPolicy
  * @returns {undefined}
  */
QSqlDatabase.prototype.setNumericalPrecisionPolicy = function(precisionPolicy){return undefined;};

/**
  * @name setPassword
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} password
  * @returns {undefined}
  */
QSqlDatabase.prototype.setPassword = function(password){return undefined;};

/**
  * @name setPort
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {Numeric} p
  * @returns {undefined}
  */
QSqlDatabase.prototype.setPort = function(p){return undefined;};

/**
  * @name setUserName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {String} name
  * @returns {undefined}
  */
QSqlDatabase.prototype.setUserName = function(name){return undefined;};

/**
  * @name tables
  * @function
  * @memberOf QSqlDatabase.prototype
  * @param {QSql.TableType} type
  * @returns {Array}
  */
QSqlDatabase.prototype.tables = function(type){return new Array();};

/**
  * @name transaction
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {Boolean}
  */
QSqlDatabase.prototype.transaction = function(){return new Boolean();};

/**
  * @name userName
  * @function
  * @memberOf QSqlDatabase.prototype
  * @returns {String}
  */
QSqlDatabase.prototype.userName = function(){return new String();};

