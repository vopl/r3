/**
  * @name QSqlQueryModel
  * @constructor
  * @extends QAbstractTableModel
  * @param {QObject} parent
  */
function QSqlQueryModel(parent){return undefined;};

QSqlQueryModel.prototype = new QAbstractTableModel();

/**
  * @name clear
  * @function
  * @memberOf QSqlQueryModel.prototype
  * @returns {undefined}
  */
QSqlQueryModel.prototype.clear = function(){return undefined;};

/**
  * @name lastError
  * @function
  * @memberOf QSqlQueryModel.prototype
  * @returns {QSqlError}
  */
QSqlQueryModel.prototype.lastError = function(){return new QSqlError();};

/**
  * @name query
  * @function
  * @memberOf QSqlQueryModel.prototype
  * @returns {QSqlQuery}
  */
QSqlQueryModel.prototype.query = function(){return new QSqlQuery();};

/**
  * @name record
  * @function
  * @memberOf QSqlQueryModel.prototype
  * @returns {QSqlRecord}
  */
QSqlQueryModel.prototype.record = function(){return new QSqlRecord();};

/**
  * @name setQuery
  * @function
  * @memberOf QSqlQueryModel.prototype
  * @param {QSqlQuery} query
  * @returns {undefined}
  */
QSqlQueryModel.prototype.setQuery = function(query){return undefined;};

