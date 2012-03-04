/**
  * @name QSqlQuery
  * @constructor
  * @param {QSqlDatabase} db
  */
function QSqlQuery(db){return undefined;};

/**
  * @name QSqlQuery^1
  * @constructor
  * @param {QSqlResult} r
  */
function QSqlQuery(r){return undefined;};

/**
  * @name QSqlQuery^2
  * @constructor
  * @param {QSqlQuery} other
  */
function QSqlQuery(other){return undefined;};

/**
  * @name QSqlQuery^3
  * @constructor
  * @param {String} query
  * @param {QSqlDatabase} db
  */
function QSqlQuery(query, db){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QSqlQuery
  * @name ValuesAsRows
  * @see QSqlQuery#BatchExecutionMode
  * @type Number
  */
QSqlQuery.ValuesAsRows = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSqlQuery
  * @name ValuesAsColumns
  * @see QSqlQuery#BatchExecutionMode
  * @type Number
  */
QSqlQuery.ValuesAsColumns = 0x1;

/**
  * @constructor 
  * @memberOf QSqlQuery
  * @name BatchExecutionMode
  */
QSqlQuery.BatchExecutionMode = function(value){;};



/**
  * @name addBindValue
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {Object} val
  * @param {QSql.ParamType} type
  * @returns {undefined}
  */
QSqlQuery.prototype.addBindValue = function(val, type){return undefined;};

/**
  * @name at
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Numeric}
  */
QSqlQuery.prototype.at = function(){return new Numeric();};

/**
  * @name bindValue
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {String} placeholder
  * @param {Object} val
  * @param {QSql.ParamType} type
  * @returns {undefined}
  */
QSqlQuery.prototype.bindValue = function(placeholder, val, type){return undefined;};

/**
  * @name boundValue
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {String} placeholder
  * @returns {Object}
  */
QSqlQuery.prototype.boundValue = function(placeholder){return new Object();};

/**
  * @name boundValues
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Object}
  */
QSqlQuery.prototype.boundValues = function(){return new Object();};

/**
  * @name clear
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {undefined}
  */
QSqlQuery.prototype.clear = function(){return undefined;};

/**
  * @name driver
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {QSqlDriver}
  */
QSqlQuery.prototype.driver = function(){return new QSqlDriver();};

/**
  * @name exec
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.exec = function(){return new Boolean();};

/**
  * @name execBatch
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {QSqlQuery.BatchExecutionMode} mode
  * @returns {Boolean}
  */
QSqlQuery.prototype.execBatch = function(mode){return new Boolean();};

/**
  * @name executedQuery
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {String}
  */
QSqlQuery.prototype.executedQuery = function(){return new String();};

/**
  * @name finish
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {undefined}
  */
QSqlQuery.prototype.finish = function(){return undefined;};

/**
  * @name first
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.first = function(){return new Boolean();};

/**
  * @name isActive
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.isActive = function(){return new Boolean();};

/**
  * @name isForwardOnly
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.isForwardOnly = function(){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {Numeric} field
  * @returns {Boolean}
  */
QSqlQuery.prototype.isNull = function(field){return new Boolean();};

/**
  * @name isSelect
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.isSelect = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.isValid = function(){return new Boolean();};

/**
  * @name last
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.last = function(){return new Boolean();};

/**
  * @name lastError
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {QSqlError}
  */
QSqlQuery.prototype.lastError = function(){return new QSqlError();};

/**
  * @name lastInsertId
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Object}
  */
QSqlQuery.prototype.lastInsertId = function(){return new Object();};

/**
  * @name lastQuery
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {String}
  */
QSqlQuery.prototype.lastQuery = function(){return new String();};

/**
  * @name next
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.next = function(){return new Boolean();};

/**
  * @name nextResult
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.nextResult = function(){return new Boolean();};

/**
  * @name numRowsAffected
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Numeric}
  */
QSqlQuery.prototype.numRowsAffected = function(){return new Numeric();};

/**
  * @name numericalPrecisionPolicy
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {QSql.NumericalPrecisionPolicy}
  */
QSqlQuery.prototype.numericalPrecisionPolicy = function(){return new QSql.NumericalPrecisionPolicy();};

/**
  * @name prepare
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {String} query
  * @returns {Boolean}
  */
QSqlQuery.prototype.prepare = function(query){return new Boolean();};

/**
  * @name previous
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Boolean}
  */
QSqlQuery.prototype.previous = function(){return new Boolean();};

/**
  * @name record
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {QSqlRecord}
  */
QSqlQuery.prototype.record = function(){return new QSqlRecord();};

/**
  * @name result
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {QSqlResult}
  */
QSqlQuery.prototype.result = function(){return new QSqlResult();};

/**
  * @name seek
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {Numeric} i
  * @param {Boolean} relative
  * @returns {Boolean}
  */
QSqlQuery.prototype.seek = function(i, relative){return new Boolean();};

/**
  * @name setForwardOnly
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {Boolean} forward
  * @returns {undefined}
  */
QSqlQuery.prototype.setForwardOnly = function(forward){return undefined;};

/**
  * @name setNumericalPrecisionPolicy
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {QSql.NumericalPrecisionPolicy} precisionPolicy
  * @returns {undefined}
  */
QSqlQuery.prototype.setNumericalPrecisionPolicy = function(precisionPolicy){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QSqlQuery.prototype
  * @returns {Numeric}
  */
QSqlQuery.prototype.size = function(){return new Numeric();};

/**
  * @name value
  * @function
  * @memberOf QSqlQuery.prototype
  * @param {Numeric} i
  * @returns {Object}
  */
QSqlQuery.prototype.value = function(i){return new Object();};

