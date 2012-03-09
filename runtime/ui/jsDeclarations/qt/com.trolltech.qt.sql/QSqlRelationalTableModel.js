/**
  * @name QSqlRelationalTableModel
  * @constructor
  * @extends QSqlTableModel
  * @param {QObject} parent
  * @param {QSqlDatabase} db
  */
function QSqlRelationalTableModel(parent, db){return undefined;};

QSqlRelationalTableModel.prototype = new QSqlTableModel();

/**
  * @name relation
  * @function
  * @memberOf QSqlRelationalTableModel.prototype
  * @param {Numeric} column
  * @returns {QSqlRelation}
  */
QSqlRelationalTableModel.prototype.relation = function(column){return new QSqlRelation();};

/**
  * @name relationModel
  * @function
  * @memberOf QSqlRelationalTableModel.prototype
  * @param {Numeric} column
  * @returns {QSqlTableModel}
  */
QSqlRelationalTableModel.prototype.relationModel = function(column){return new QSqlTableModel();};

/**
  * @name setRelation
  * @function
  * @memberOf QSqlRelationalTableModel.prototype
  * @param {Numeric} column
  * @param {QSqlRelation} relation
  * @returns {undefined}
  */
QSqlRelationalTableModel.prototype.setRelation = function(column, relation){return undefined;};

