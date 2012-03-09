/**
  * @name QStandardItemModel
  * @constructor
  * @extends QAbstractItemModel
  * @param {QObject} parent
  */
function QStandardItemModel(parent){return undefined;};

/**
  * @name QStandardItemModel^1
  * @constructor
  * @extends QAbstractItemModel
  * @param {Numeric} rows
  * @param {Numeric} columns
  * @param {QObject} parent
  */
function QStandardItemModel(rows, columns, parent){return undefined;};

QStandardItemModel.prototype = new QAbstractItemModel();

/**
  * @name appendColumn
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Array} items
  * @returns {undefined}
  */
QStandardItemModel.prototype.appendColumn = function(items){return undefined;};

/**
  * @name appendRow
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItemModel.prototype.appendRow = function(item){return undefined;};

/**
  * @name clear
  * @function
  * @memberOf QStandardItemModel.prototype
  * @returns {undefined}
  */
QStandardItemModel.prototype.clear = function(){return undefined;};

/**
  * @name findItems
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {String} text
  * @param {Qt.MatchFlags} flags
  * @param {Numeric} column
  * @returns {Array}
  */
QStandardItemModel.prototype.findItems = function(text, flags, column){return new Array();};

/**
  * @name horizontalHeaderItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} column
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.horizontalHeaderItem = function(column){return new QStandardItem();};

/**
  * @name indexFromItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {QStandardItem} item
  * @returns {QModelIndex}
  */
QStandardItemModel.prototype.indexFromItem = function(item){return new QModelIndex();};

/**
  * @name insertColumn
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} column
  * @param {Array} items
  * @returns {undefined}
  */
QStandardItemModel.prototype.insertColumn = function(column, items){return undefined;};

/**
  * @name insertRow
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItemModel.prototype.insertRow = function(row, item){return undefined;};

/**
  * @name invisibleRootItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.invisibleRootItem = function(){return new QStandardItem();};

/**
  * @name item
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.item = function(row, column){return new QStandardItem();};

/**
  * @name itemFromIndex
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {QModelIndex} index
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.itemFromIndex = function(index){return new QStandardItem();};

/**
  * @name itemPrototype
  * @function
  * @memberOf QStandardItemModel.prototype
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.itemPrototype = function(){return new QStandardItem();};

/**
  * @name setColumnCount
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} columns
  * @returns {undefined}
  */
QStandardItemModel.prototype.setColumnCount = function(columns){return undefined;};

/**
  * @name setHorizontalHeaderItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} column
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItemModel.prototype.setHorizontalHeaderItem = function(column, item){return undefined;};

/**
  * @name setHorizontalHeaderLabels
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Array} labels
  * @returns {undefined}
  */
QStandardItemModel.prototype.setHorizontalHeaderLabels = function(labels){return undefined;};

/**
  * @name setItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItemModel.prototype.setItem = function(row, item){return undefined;};

/**
  * @name setItemPrototype
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItemModel.prototype.setItemPrototype = function(item){return undefined;};

/**
  * @name setRowCount
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} rows
  * @returns {undefined}
  */
QStandardItemModel.prototype.setRowCount = function(rows){return undefined;};

/**
  * @name setVerticalHeaderItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItemModel.prototype.setVerticalHeaderItem = function(row, item){return undefined;};

/**
  * @name setVerticalHeaderLabels
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Array} labels
  * @returns {undefined}
  */
QStandardItemModel.prototype.setVerticalHeaderLabels = function(labels){return undefined;};

/**
  * @name takeColumn
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} column
  * @returns {Array}
  */
QStandardItemModel.prototype.takeColumn = function(column){return new Array();};

/**
  * @name takeHorizontalHeaderItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} column
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.takeHorizontalHeaderItem = function(column){return new QStandardItem();};

/**
  * @name takeItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.takeItem = function(row, column){return new QStandardItem();};

/**
  * @name takeRow
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @returns {Array}
  */
QStandardItemModel.prototype.takeRow = function(row){return new Array();};

/**
  * @name takeVerticalHeaderItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.takeVerticalHeaderItem = function(row){return new QStandardItem();};

/**
  * @name verticalHeaderItem
  * @function
  * @memberOf QStandardItemModel.prototype
  * @param {Numeric} row
  * @returns {QStandardItem}
  */
QStandardItemModel.prototype.verticalHeaderItem = function(row){return new QStandardItem();};

/**
  * @name sortRole
  * @memberOf QStandardItemModel.prototype
  * @type Numeric
  */
QStandardItemModel.prototype.sortRole = new Numeric();


