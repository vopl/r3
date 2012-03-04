/**
  * @name QTableWidget
  * @constructor
  * @extends QTableView
  * @param {QWidget} parent
  */
function QTableWidget(parent){return undefined;};

/**
  * @name QTableWidget^1
  * @constructor
  * @extends QTableView
  * @param {Numeric} rows
  * @param {Numeric} columns
  * @param {QWidget} parent
  */
function QTableWidget(rows, columns, parent){return undefined;};

QTableWidget.prototype = new QTableView();

/**
  * @name cellWidget
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QWidget}
  */
QTableWidget.prototype.cellWidget = function(row, column){return new QWidget();};

/**
  * @name closePersistentEditor
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.closePersistentEditor = function(item){return undefined;};

/**
  * @name column
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {Numeric}
  */
QTableWidget.prototype.column = function(item){return new Numeric();};

/**
  * @name currentColumn
  * @function
  * @memberOf QTableWidget.prototype
  * @returns {Numeric}
  */
QTableWidget.prototype.currentColumn = function(){return new Numeric();};

/**
  * @name currentItem
  * @function
  * @memberOf QTableWidget.prototype
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.currentItem = function(){return new QTableWidgetItem();};

/**
  * @name currentRow
  * @function
  * @memberOf QTableWidget.prototype
  * @returns {Numeric}
  */
QTableWidget.prototype.currentRow = function(){return new Numeric();};

/**
  * @name editItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.editItem = function(item){return undefined;};

/**
  * @name findItems
  * @function
  * @memberOf QTableWidget.prototype
  * @param {String} text
  * @param {Qt.MatchFlags} flags
  * @returns {Array}
  */
QTableWidget.prototype.findItems = function(text, flags){return new Array();};

/**
  * @name horizontalHeaderItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} column
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.horizontalHeaderItem = function(column){return new QTableWidgetItem();};

/**
  * @name item
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.item = function(row, column){return new QTableWidgetItem();};

/**
  * @name itemAt
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QPoint} p
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.itemAt = function(p){return new QTableWidgetItem();};

/**
  * @name itemPrototype
  * @function
  * @memberOf QTableWidget.prototype
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.itemPrototype = function(){return new QTableWidgetItem();};

/**
  * @name openPersistentEditor
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.openPersistentEditor = function(item){return undefined;};

/**
  * @name removeCellWidget
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {undefined}
  */
QTableWidget.prototype.removeCellWidget = function(row, column){return undefined;};

/**
  * @name row
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {Numeric}
  */
QTableWidget.prototype.row = function(item){return new Numeric();};

/**
  * @name selectedItems
  * @function
  * @memberOf QTableWidget.prototype
  * @returns {Array}
  */
QTableWidget.prototype.selectedItems = function(){return new Array();};

/**
  * @name selectedRanges
  * @function
  * @memberOf QTableWidget.prototype
  * @returns {Array}
  */
QTableWidget.prototype.selectedRanges = function(){return new Array();};

/**
  * @name setCellWidget
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {QWidget} widget
  * @returns {undefined}
  */
QTableWidget.prototype.setCellWidget = function(row, column, widget){return undefined;};

/**
  * @name setCurrentCell
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {undefined}
  */
QTableWidget.prototype.setCurrentCell = function(row, column){return undefined;};

/**
  * @name setCurrentItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.setCurrentItem = function(item){return undefined;};

/**
  * @name setHorizontalHeaderItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} column
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.setHorizontalHeaderItem = function(column, item){return undefined;};

/**
  * @name setHorizontalHeaderLabels
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Array} labels
  * @returns {undefined}
  */
QTableWidget.prototype.setHorizontalHeaderLabels = function(labels){return undefined;};

/**
  * @name setItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.setItem = function(row, column, item){return undefined;};

/**
  * @name setItemPrototype
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.setItemPrototype = function(item){return undefined;};

/**
  * @name setRangeSelected
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetSelectionRange} range
  * @param {Boolean} select
  * @returns {undefined}
  */
QTableWidget.prototype.setRangeSelected = function(range, select){return undefined;};

/**
  * @name setVerticalHeaderItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {QTableWidgetItem} item
  * @returns {undefined}
  */
QTableWidget.prototype.setVerticalHeaderItem = function(row, item){return undefined;};

/**
  * @name setVerticalHeaderLabels
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Array} labels
  * @returns {undefined}
  */
QTableWidget.prototype.setVerticalHeaderLabels = function(labels){return undefined;};

/**
  * @name sortItems
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QTableWidget.prototype.sortItems = function(column, order){return undefined;};

/**
  * @name takeHorizontalHeaderItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} column
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.takeHorizontalHeaderItem = function(column){return new QTableWidgetItem();};

/**
  * @name takeItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.takeItem = function(row, column){return new QTableWidgetItem();};

/**
  * @name takeVerticalHeaderItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.takeVerticalHeaderItem = function(row){return new QTableWidgetItem();};

/**
  * @name verticalHeaderItem
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} row
  * @returns {QTableWidgetItem}
  */
QTableWidget.prototype.verticalHeaderItem = function(row){return new QTableWidgetItem();};

/**
  * @name visualColumn
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} logicalColumn
  * @returns {Numeric}
  */
QTableWidget.prototype.visualColumn = function(logicalColumn){return new Numeric();};

/**
  * @name visualItemRect
  * @function
  * @memberOf QTableWidget.prototype
  * @param {QTableWidgetItem} item
  * @returns {QRect}
  */
QTableWidget.prototype.visualItemRect = function(item){return new QRect();};

/**
  * @name visualRow
  * @function
  * @memberOf QTableWidget.prototype
  * @param {Numeric} logicalRow
  * @returns {Numeric}
  */
QTableWidget.prototype.visualRow = function(logicalRow){return new Numeric();};

/**
  * @name rowCount
  * @memberOf QTableWidget.prototype
  * @type Numeric
  */
QTableWidget.prototype.rowCount = new Numeric();

/**
  * @name columnCount
  * @memberOf QTableWidget.prototype
  * @type Numeric
  */
QTableWidget.prototype.columnCount = new Numeric();


