/**
  * @name QSqlTableModel
  * @constructor
  * @extends QSqlQueryModel
  * @param {QObject} parent
  * @param {QSqlDatabase} db
  */
function QSqlTableModel(parent, db){return undefined;};

QSqlTableModel.prototype = new QSqlQueryModel();

/**
  * @default 0x0
  * @constant
  * @memberOf QSqlTableModel
  * @name OnFieldChange
  * @see QSqlTableModel#EditStrategy
  * @type Number
  */
QSqlTableModel.OnFieldChange = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSqlTableModel
  * @name OnRowChange
  * @see QSqlTableModel#EditStrategy
  * @type Number
  */
QSqlTableModel.OnRowChange = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSqlTableModel
  * @name OnManualSubmit
  * @see QSqlTableModel#EditStrategy
  * @type Number
  */
QSqlTableModel.OnManualSubmit = 0x2;

/**
  * @constructor 
  * @memberOf QSqlTableModel
  * @name EditStrategy
  */
QSqlTableModel.EditStrategy = function(value){;};



/**
  * @name database
  * @function
  * @memberOf QSqlTableModel.prototype
  * @returns {QSqlDatabase}
  */
QSqlTableModel.prototype.database = function(){return new QSqlDatabase();};

/**
  * @name editStrategy
  * @function
  * @memberOf QSqlTableModel.prototype
  * @returns {QSqlTableModel.EditStrategy}
  */
QSqlTableModel.prototype.editStrategy = function(){return new QSqlTableModel.EditStrategy();};

/**
  * @name fieldIndex
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {String} fieldName
  * @returns {Numeric}
  */
QSqlTableModel.prototype.fieldIndex = function(fieldName){return new Numeric();};

/**
  * @name filter
  * @function
  * @memberOf QSqlTableModel.prototype
  * @returns {String}
  */
QSqlTableModel.prototype.filter = function(){return new String();};

/**
  * @name insertRecord
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {Numeric} row
  * @param {QSqlRecord} record
  * @returns {Boolean}
  */
QSqlTableModel.prototype.insertRecord = function(row, record){return new Boolean();};

/**
  * @name isDirty
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {QModelIndex} index
  * @returns {Boolean}
  */
QSqlTableModel.prototype.isDirty = function(index){return new Boolean();};

/**
  * @name primaryKey
  * @function
  * @memberOf QSqlTableModel.prototype
  * @returns {QSqlIndex}
  */
QSqlTableModel.prototype.primaryKey = function(){return new QSqlIndex();};

/**
  * @name revertRow
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {Numeric} row
  * @returns {undefined}
  */
QSqlTableModel.prototype.revertRow = function(row){return undefined;};

/**
  * @name select
  * @function
  * @memberOf QSqlTableModel.prototype
  * @returns {Boolean}
  */
QSqlTableModel.prototype.select = function(){return new Boolean();};

/**
  * @name setEditStrategy
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {QSqlTableModel.EditStrategy} strategy
  * @returns {undefined}
  */
QSqlTableModel.prototype.setEditStrategy = function(strategy){return undefined;};

/**
  * @name setFilter
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {String} filter
  * @returns {undefined}
  */
QSqlTableModel.prototype.setFilter = function(filter){return undefined;};

/**
  * @name setRecord
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {Numeric} row
  * @param {QSqlRecord} record
  * @returns {Boolean}
  */
QSqlTableModel.prototype.setRecord = function(row, record){return new Boolean();};

/**
  * @name setSort
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QSqlTableModel.prototype.setSort = function(column, order){return undefined;};

/**
  * @name setTable
  * @function
  * @memberOf QSqlTableModel.prototype
  * @param {String} tableName
  * @returns {undefined}
  */
QSqlTableModel.prototype.setTable = function(tableName){return undefined;};

/**
  * @name tableName
  * @function
  * @memberOf QSqlTableModel.prototype
  * @returns {String}
  */
QSqlTableModel.prototype.tableName = function(){return new String();};

