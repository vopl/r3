/**
  * @name QTableView
  * @constructor
  * @extends QAbstractItemView
  * @param {QWidget} parent
  */
function QTableView(parent){return undefined;};

QTableView.prototype = new QAbstractItemView();

/**
  * @name clearSpans
  * @function
  * @memberOf QTableView.prototype
  * @returns {undefined}
  */
QTableView.prototype.clearSpans = function(){return undefined;};

/**
  * @name columnAt
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} x
  * @returns {Numeric}
  */
QTableView.prototype.columnAt = function(x){return new Numeric();};

/**
  * @name columnSpan
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTableView.prototype.columnSpan = function(row, column){return new Numeric();};

/**
  * @name columnViewportPosition
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTableView.prototype.columnViewportPosition = function(column){return new Numeric();};

/**
  * @name columnWidth
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTableView.prototype.columnWidth = function(column){return new Numeric();};

/**
  * @name horizontalHeader
  * @function
  * @memberOf QTableView.prototype
  * @returns {QHeaderView}
  */
QTableView.prototype.horizontalHeader = function(){return new QHeaderView();};

/**
  * @name isColumnHidden
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} column
  * @returns {Boolean}
  */
QTableView.prototype.isColumnHidden = function(column){return new Boolean();};

/**
  * @name isRowHidden
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @returns {Boolean}
  */
QTableView.prototype.isRowHidden = function(row){return new Boolean();};

/**
  * @name rowAt
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} y
  * @returns {Numeric}
  */
QTableView.prototype.rowAt = function(y){return new Numeric();};

/**
  * @name rowHeight
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QTableView.prototype.rowHeight = function(row){return new Numeric();};

/**
  * @name rowSpan
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTableView.prototype.rowSpan = function(row, column){return new Numeric();};

/**
  * @name rowViewportPosition
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QTableView.prototype.rowViewportPosition = function(row){return new Numeric();};

/**
  * @name setColumnHidden
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} column
  * @param {Boolean} hide
  * @returns {undefined}
  */
QTableView.prototype.setColumnHidden = function(column, hide){return undefined;};

/**
  * @name setColumnWidth
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} column
  * @param {Numeric} width
  * @returns {undefined}
  */
QTableView.prototype.setColumnWidth = function(column, width){return undefined;};

/**
  * @name setHorizontalHeader
  * @function
  * @memberOf QTableView.prototype
  * @param {QHeaderView} header
  * @returns {undefined}
  */
QTableView.prototype.setHorizontalHeader = function(header){return undefined;};

/**
  * @name setRowHeight
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @param {Numeric} height
  * @returns {undefined}
  */
QTableView.prototype.setRowHeight = function(row, height){return undefined;};

/**
  * @name setRowHidden
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @param {Boolean} hide
  * @returns {undefined}
  */
QTableView.prototype.setRowHidden = function(row, hide){return undefined;};

/**
  * @name setSpan
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Numeric} rowSpan
  * @param {Numeric} columnSpan
  * @returns {undefined}
  */
QTableView.prototype.setSpan = function(row, column, rowSpan, columnSpan){return undefined;};

/**
  * @name setVerticalHeader
  * @function
  * @memberOf QTableView.prototype
  * @param {QHeaderView} header
  * @returns {undefined}
  */
QTableView.prototype.setVerticalHeader = function(header){return undefined;};

/**
  * @name sortByColumn
  * @function
  * @memberOf QTableView.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QTableView.prototype.sortByColumn = function(column, order){return undefined;};

/**
  * @name verticalHeader
  * @function
  * @memberOf QTableView.prototype
  * @returns {QHeaderView}
  */
QTableView.prototype.verticalHeader = function(){return new QHeaderView();};

/**
  * @name showGrid
  * @memberOf QTableView.prototype
  * @type Boolean
  */
QTableView.prototype.showGrid = new Boolean();

/**
  * @name gridStyle
  * @memberOf QTableView.prototype
  * @type Qt.PenStyle
  */
QTableView.prototype.gridStyle = new Qt.PenStyle();

/**
  * @name sortingEnabled
  * @memberOf QTableView.prototype
  * @type Boolean
  */
QTableView.prototype.sortingEnabled = new Boolean();

/**
  * @name wordWrap
  * @memberOf QTableView.prototype
  * @type Boolean
  */
QTableView.prototype.wordWrap = new Boolean();

/**
  * @name cornerButtonEnabled
  * @memberOf QTableView.prototype
  * @type Boolean
  */
QTableView.prototype.cornerButtonEnabled = new Boolean();


