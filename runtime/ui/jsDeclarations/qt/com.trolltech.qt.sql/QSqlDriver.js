/**
  * @name QSqlDriver
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QSqlDriver(parent){return undefined;};

QSqlDriver.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QSqlDriver
  * @name WhereStatement
  * @see QSqlDriver#StatementType
  * @type Number
  */
QSqlDriver.WhereStatement = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSqlDriver
  * @name SelectStatement
  * @see QSqlDriver#StatementType
  * @type Number
  */
QSqlDriver.SelectStatement = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSqlDriver
  * @name UpdateStatement
  * @see QSqlDriver#StatementType
  * @type Number
  */
QSqlDriver.UpdateStatement = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSqlDriver
  * @name InsertStatement
  * @see QSqlDriver#StatementType
  * @type Number
  */
QSqlDriver.InsertStatement = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSqlDriver
  * @name DeleteStatement
  * @see QSqlDriver#StatementType
  * @type Number
  */
QSqlDriver.DeleteStatement = 0x4;

/**
  * @constructor 
  * @memberOf QSqlDriver
  * @name StatementType
  */
QSqlDriver.StatementType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSqlDriver
  * @name FieldName
  * @see QSqlDriver#IdentifierType
  * @type Number
  */
QSqlDriver.FieldName = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSqlDriver
  * @name TableName
  * @see QSqlDriver#IdentifierType
  * @type Number
  */
QSqlDriver.TableName = 0x1;

/**
  * @constructor 
  * @memberOf QSqlDriver
  * @name IdentifierType
  */
QSqlDriver.IdentifierType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSqlDriver
  * @name Transactions
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.Transactions = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSqlDriver
  * @name QuerySize
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.QuerySize = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSqlDriver
  * @name BLOB
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.BLOB = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSqlDriver
  * @name Unicode
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.Unicode = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSqlDriver
  * @name PreparedQueries
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.PreparedQueries = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QSqlDriver
  * @name NamedPlaceholders
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.NamedPlaceholders = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QSqlDriver
  * @name PositionalPlaceholders
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.PositionalPlaceholders = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QSqlDriver
  * @name LastInsertId
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.LastInsertId = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QSqlDriver
  * @name BatchOperations
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.BatchOperations = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QSqlDriver
  * @name SimpleLocking
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.SimpleLocking = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QSqlDriver
  * @name LowPrecisionNumbers
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.LowPrecisionNumbers = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QSqlDriver
  * @name EventNotifications
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.EventNotifications = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QSqlDriver
  * @name FinishQuery
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.FinishQuery = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QSqlDriver
  * @name MultipleResultSets
  * @see QSqlDriver#DriverFeature
  * @type Number
  */
QSqlDriver.MultipleResultSets = 0xd;

/**
  * @constructor 
  * @memberOf QSqlDriver
  * @name DriverFeature
  */
QSqlDriver.DriverFeature = function(value){;};



/**
  * @name beginTransaction
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Boolean}
  */
QSqlDriver.prototype.beginTransaction = function(){return new Boolean();};

/**
  * @name close
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {undefined}
  */
QSqlDriver.prototype.close = function(){return undefined;};

/**
  * @name commitTransaction
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Boolean}
  */
QSqlDriver.prototype.commitTransaction = function(){return new Boolean();};

/**
  * @name createResult
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {QSqlResult}
  */
QSqlDriver.prototype.createResult = function(){return new QSqlResult();};

/**
  * @name escapeIdentifier
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} identifier
  * @param {QSqlDriver.IdentifierType} type
  * @returns {String}
  */
QSqlDriver.prototype.escapeIdentifier = function(identifier, type){return new String();};

/**
  * @name formatValue
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {QSqlField} field
  * @param {Boolean} trimStrings
  * @returns {String}
  */
QSqlDriver.prototype.formatValue = function(field, trimStrings){return new String();};

/**
  * @name handle
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Object}
  */
QSqlDriver.prototype.handle = function(){return new Object();};

/**
  * @name hasFeature
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {QSqlDriver.DriverFeature} f
  * @returns {Boolean}
  */
QSqlDriver.prototype.hasFeature = function(f){return new Boolean();};

/**
  * @name isIdentifierEscaped
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} identifier
  * @param {QSqlDriver.IdentifierType} type
  * @returns {Boolean}
  */
QSqlDriver.prototype.isIdentifierEscaped = function(identifier, type){return new Boolean();};

/**
  * @name isOpen
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Boolean}
  */
QSqlDriver.prototype.isOpen = function(){return new Boolean();};

/**
  * @name isOpenError
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Boolean}
  */
QSqlDriver.prototype.isOpenError = function(){return new Boolean();};

/**
  * @name lastError
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {QSqlError}
  */
QSqlDriver.prototype.lastError = function(){return new QSqlError();};

/**
  * @name numericalPrecisionPolicy
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {QSql.NumericalPrecisionPolicy}
  */
QSqlDriver.prototype.numericalPrecisionPolicy = function(){return new QSql.NumericalPrecisionPolicy();};

/**
  * @name open
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} db
  * @param {String} user
  * @param {String} password
  * @param {String} host
  * @param {Numeric} port
  * @param {String} connOpts
  * @returns {Boolean}
  */
QSqlDriver.prototype.open = function(db, user, password, host, port, connOpts){return new Boolean();};

/**
  * @name primaryIndex
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} tableName
  * @returns {QSqlIndex}
  */
QSqlDriver.prototype.primaryIndex = function(tableName){return new QSqlIndex();};

/**
  * @name record
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} tableName
  * @returns {QSqlRecord}
  */
QSqlDriver.prototype.record = function(tableName){return new QSqlRecord();};

/**
  * @name rollbackTransaction
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Boolean}
  */
QSqlDriver.prototype.rollbackTransaction = function(){return new Boolean();};

/**
  * @name setNumericalPrecisionPolicy
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {QSql.NumericalPrecisionPolicy} precisionPolicy
  * @returns {undefined}
  */
QSqlDriver.prototype.setNumericalPrecisionPolicy = function(precisionPolicy){return undefined;};

/**
  * @name sqlStatement
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {QSqlDriver.StatementType} type
  * @param {String} tableName
  * @param {QSqlRecord} rec
  * @param {Boolean} preparedStatement
  * @returns {String}
  */
QSqlDriver.prototype.sqlStatement = function(type, tableName, rec, preparedStatement){return new String();};

/**
  * @name stripDelimiters
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} identifier
  * @param {QSqlDriver.IdentifierType} type
  * @returns {String}
  */
QSqlDriver.prototype.stripDelimiters = function(identifier, type){return new String();};

/**
  * @name subscribeToNotification
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QSqlDriver.prototype.subscribeToNotification = function(name){return new Boolean();};

/**
  * @name subscribedToNotifications
  * @function
  * @memberOf QSqlDriver.prototype
  * @returns {Array}
  */
QSqlDriver.prototype.subscribedToNotifications = function(){return new Array();};

/**
  * @name tables
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {QSql.TableType} tableType
  * @returns {Array}
  */
QSqlDriver.prototype.tables = function(tableType){return new Array();};

/**
  * @name unsubscribeFromNotification
  * @function
  * @memberOf QSqlDriver.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QSqlDriver.prototype.unsubscribeFromNotification = function(name){return new Boolean();};

