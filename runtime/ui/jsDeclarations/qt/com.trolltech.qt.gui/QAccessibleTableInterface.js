/**
  * @name QAccessibleTableInterface
  * @constructor
  * @extends QAccessible2Interface
  */
function QAccessibleTableInterface(){return undefined;};

QAccessibleTableInterface.prototype = new QAccessible2Interface();

/**
  * @name accessibleAt
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QAccessibleInterface}
  */
QAccessibleTableInterface.prototype.accessibleAt = function(row, column){return new QAccessibleInterface();};

/**
  * @name caption
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {QAccessibleInterface}
  */
QAccessibleTableInterface.prototype.caption = function(){return new QAccessibleInterface();};

/**
  * @name cellAtIndex
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} index
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Numeric} rowSpan
  * @param {Numeric} columnSpan
  * @param {Boolean} isSelected
  * @returns {undefined}
  */
QAccessibleTableInterface.prototype.cellAtIndex = function(index, row, column, rowSpan, columnSpan, isSelected){return undefined;};

/**
  * @name childIndex
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} rowIndex
  * @param {Numeric} columnIndex
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.childIndex = function(rowIndex, columnIndex){return new Numeric();};

/**
  * @name columnCount
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.columnCount = function(){return new Numeric();};

/**
  * @name columnDescription
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} column
  * @returns {String}
  */
QAccessibleTableInterface.prototype.columnDescription = function(column){return new String();};

/**
  * @name columnHeader
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {QAccessibleInterface}
  */
QAccessibleTableInterface.prototype.columnHeader = function(){return new QAccessibleInterface();};

/**
  * @name columnIndex
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} childIndex
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.columnIndex = function(childIndex){return new Numeric();};

/**
  * @name columnSpan
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.columnSpan = function(row, column){return new Numeric();};

/**
  * @name isColumnSelected
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} column
  * @returns {Boolean}
  */
QAccessibleTableInterface.prototype.isColumnSelected = function(column){return new Boolean();};

/**
  * @name isRowSelected
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @returns {Boolean}
  */
QAccessibleTableInterface.prototype.isRowSelected = function(row){return new Boolean();};

/**
  * @name isSelected
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {Boolean}
  */
QAccessibleTableInterface.prototype.isSelected = function(row, column){return new Boolean();};

/**
  * @name rowCount
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.rowCount = function(){return new Numeric();};

/**
  * @name rowDescription
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @returns {String}
  */
QAccessibleTableInterface.prototype.rowDescription = function(row){return new String();};

/**
  * @name rowHeader
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {QAccessibleInterface}
  */
QAccessibleTableInterface.prototype.rowHeader = function(){return new QAccessibleInterface();};

/**
  * @name rowIndex
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} childIndex
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.rowIndex = function(childIndex){return new Numeric();};

/**
  * @name rowSpan
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.rowSpan = function(row, column){return new Numeric();};

/**
  * @name selectColumn
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} column
  * @returns {undefined}
  */
QAccessibleTableInterface.prototype.selectColumn = function(column){return undefined;};

/**
  * @name selectRow
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @returns {undefined}
  */
QAccessibleTableInterface.prototype.selectRow = function(row){return undefined;};

/**
  * @name selectedColumnCount
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.selectedColumnCount = function(){return new Numeric();};

/**
  * @name selectedColumns
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} maxColumns
  * @param {Array} columns
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.selectedColumns = function(maxColumns, columns){return new Numeric();};

/**
  * @name selectedRowCount
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.selectedRowCount = function(){return new Numeric();};

/**
  * @name selectedRows
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} maxRows
  * @param {Array} rows
  * @returns {Numeric}
  */
QAccessibleTableInterface.prototype.selectedRows = function(maxRows, rows){return new Numeric();};

/**
  * @name summary
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @returns {QAccessibleInterface}
  */
QAccessibleTableInterface.prototype.summary = function(){return new QAccessibleInterface();};

/**
  * @name unselectColumn
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} column
  * @returns {undefined}
  */
QAccessibleTableInterface.prototype.unselectColumn = function(column){return undefined;};

/**
  * @name unselectRow
  * @function
  * @memberOf QAccessibleTableInterface.prototype
  * @param {Numeric} row
  * @returns {undefined}
  */
QAccessibleTableInterface.prototype.unselectRow = function(row){return undefined;};

