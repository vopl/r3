/**
  * @name QTextTableFormat
  * @constructor
  * @extends QTextFrameFormat
  */
function QTextTableFormat(){return undefined;};

QTextTableFormat.prototype = new QTextFrameFormat();

/**
  * @name alignment
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {Qt.Alignment}
  */
QTextTableFormat.prototype.alignment = function(){return new Qt.Alignment();};

/**
  * @name cellPadding
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {Numeric}
  */
QTextTableFormat.prototype.cellPadding = function(){return new Numeric();};

/**
  * @name cellSpacing
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {Numeric}
  */
QTextTableFormat.prototype.cellSpacing = function(){return new Numeric();};

/**
  * @name clearColumnWidthConstraints
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {undefined}
  */
QTextTableFormat.prototype.clearColumnWidthConstraints = function(){return undefined;};

/**
  * @name columnWidthConstraints
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {Array}
  */
QTextTableFormat.prototype.columnWidthConstraints = function(){return new Array();};

/**
  * @name columns
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {Numeric}
  */
QTextTableFormat.prototype.columns = function(){return new Numeric();};

/**
  * @name headerRowCount
  * @function
  * @memberOf QTextTableFormat.prototype
  * @returns {Numeric}
  */
QTextTableFormat.prototype.headerRowCount = function(){return new Numeric();};

/**
  * @name setAlignment
  * @function
  * @memberOf QTextTableFormat.prototype
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QTextTableFormat.prototype.setAlignment = function(alignment){return undefined;};

/**
  * @name setCellPadding
  * @function
  * @memberOf QTextTableFormat.prototype
  * @param {Numeric} padding
  * @returns {undefined}
  */
QTextTableFormat.prototype.setCellPadding = function(padding){return undefined;};

/**
  * @name setCellSpacing
  * @function
  * @memberOf QTextTableFormat.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QTextTableFormat.prototype.setCellSpacing = function(spacing){return undefined;};

/**
  * @name setColumnWidthConstraints
  * @function
  * @memberOf QTextTableFormat.prototype
  * @param {Array} constraints
  * @returns {undefined}
  */
QTextTableFormat.prototype.setColumnWidthConstraints = function(constraints){return undefined;};

/**
  * @name setColumns
  * @function
  * @memberOf QTextTableFormat.prototype
  * @param {Numeric} columns
  * @returns {undefined}
  */
QTextTableFormat.prototype.setColumns = function(columns){return undefined;};

/**
  * @name setHeaderRowCount
  * @function
  * @memberOf QTextTableFormat.prototype
  * @param {Numeric} count
  * @returns {undefined}
  */
QTextTableFormat.prototype.setHeaderRowCount = function(count){return undefined;};

