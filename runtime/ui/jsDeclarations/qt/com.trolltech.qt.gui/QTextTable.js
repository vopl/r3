/**
  * @name QTextTable
  * @constructor
  * @extends QTextFrame
  * @param {QTextDocument} doc
  */
function QTextTable(doc){return undefined;};

QTextTable.prototype = new QTextFrame();

/**
  * @name appendColumns
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} count
  * @returns {undefined}
  */
QTextTable.prototype.appendColumns = function(count){return undefined;};

/**
  * @name appendRows
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} count
  * @returns {undefined}
  */
QTextTable.prototype.appendRows = function(count){return undefined;};

/**
  * @name cellAt
  * @function
  * @memberOf QTextTable.prototype
  * @param {QTextCursor} c
  * @returns {QTextTableCell}
  */
QTextTable.prototype.cellAt = function(c){return new QTextTableCell();};

/**
  * @name columns
  * @function
  * @memberOf QTextTable.prototype
  * @returns {Numeric}
  */
QTextTable.prototype.columns = function(){return new Numeric();};

/**
  * @name insertColumns
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} pos
  * @param {Numeric} num
  * @returns {undefined}
  */
QTextTable.prototype.insertColumns = function(pos, num){return undefined;};

/**
  * @name insertRows
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} pos
  * @param {Numeric} num
  * @returns {undefined}
  */
QTextTable.prototype.insertRows = function(pos, num){return undefined;};

/**
  * @name mergeCells
  * @function
  * @memberOf QTextTable.prototype
  * @param {QTextCursor} cursor
  * @returns {undefined}
  */
QTextTable.prototype.mergeCells = function(cursor){return undefined;};

/**
  * @name removeColumns
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} pos
  * @param {Numeric} num
  * @returns {undefined}
  */
QTextTable.prototype.removeColumns = function(pos, num){return undefined;};

/**
  * @name removeRows
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} pos
  * @param {Numeric} num
  * @returns {undefined}
  */
QTextTable.prototype.removeRows = function(pos, num){return undefined;};

/**
  * @name resize
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} rows
  * @param {Numeric} cols
  * @returns {undefined}
  */
QTextTable.prototype.resize = function(rows, cols){return undefined;};

/**
  * @name rowEnd
  * @function
  * @memberOf QTextTable.prototype
  * @param {QTextCursor} c
  * @returns {QTextCursor}
  */
QTextTable.prototype.rowEnd = function(c){return new QTextCursor();};

/**
  * @name rowStart
  * @function
  * @memberOf QTextTable.prototype
  * @param {QTextCursor} c
  * @returns {QTextCursor}
  */
QTextTable.prototype.rowStart = function(c){return new QTextCursor();};

/**
  * @name rows
  * @function
  * @memberOf QTextTable.prototype
  * @returns {Numeric}
  */
QTextTable.prototype.rows = function(){return new Numeric();};

/**
  * @name setFormat
  * @function
  * @memberOf QTextTable.prototype
  * @param {QTextTableFormat} format
  * @returns {undefined}
  */
QTextTable.prototype.setFormat = function(format){return undefined;};

/**
  * @name splitCell
  * @function
  * @memberOf QTextTable.prototype
  * @param {Numeric} row
  * @param {Numeric} col
  * @param {Numeric} numRows
  * @param {Numeric} numCols
  * @returns {undefined}
  */
QTextTable.prototype.splitCell = function(row, col, numRows, numCols){return undefined;};

/**
  * @name tableFormat
  * @function
  * @memberOf QTextTable.prototype
  * @returns {QTextTableFormat}
  */
QTextTable.prototype.tableFormat = function(){return new QTextTableFormat();};

