/**
  * @name QGridLayout
  * @constructor
  * @extends QLayout
  */
function QGridLayout(){return undefined;};

/**
  * @name QGridLayout^1
  * @constructor
  * @extends QLayout
  * @param {QWidget} parent
  */
function QGridLayout(parent){return undefined;};

QGridLayout.prototype = new QLayout();

/**
  * @name addItem
  * @function
  * @memberOf QGridLayout.prototype
  * @param {QLayoutItem} item
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Numeric} rowSpan
  * @param {Numeric} columnSpan
  * @param {Qt.Alignment} arg__6
  * @returns {undefined}
  */
QGridLayout.prototype.addItem = function(item, row, column, rowSpan, columnSpan, arg__6){return undefined;};

/**
  * @name addLayout
  * @function
  * @memberOf QGridLayout.prototype
  * @param {QLayout} arg__1
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Qt.Alignment} arg__4
  * @returns {undefined}
  */
QGridLayout.prototype.addLayout = function(arg__1, row, column, arg__4){return undefined;};

/**
  * @name addWidget
  * @function
  * @memberOf QGridLayout.prototype
  * @param {QWidget} arg__1
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Qt.Alignment} arg__4
  * @returns {undefined}
  */
QGridLayout.prototype.addWidget = function(arg__1, row, column, arg__4){return undefined;};

/**
  * @name cellRect
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QRect}
  */
QGridLayout.prototype.cellRect = function(row, column){return new QRect();};

/**
  * @name columnCount
  * @function
  * @memberOf QGridLayout.prototype
  * @returns {Numeric}
  */
QGridLayout.prototype.columnCount = function(){return new Numeric();};

/**
  * @name columnMinimumWidth
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGridLayout.prototype.columnMinimumWidth = function(column){return new Numeric();};

/**
  * @name columnStretch
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGridLayout.prototype.columnStretch = function(column){return new Numeric();};

/**
  * @name getItemPosition
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} idx
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Numeric} rowSpan
  * @param {Numeric} columnSpan
  * @returns {undefined}
  */
QGridLayout.prototype.getItemPosition = function(idx, row, column, rowSpan, columnSpan){return undefined;};

/**
  * @name horizontalSpacing
  * @function
  * @memberOf QGridLayout.prototype
  * @returns {Numeric}
  */
QGridLayout.prototype.horizontalSpacing = function(){return new Numeric();};

/**
  * @name itemAtPosition
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QLayoutItem}
  */
QGridLayout.prototype.itemAtPosition = function(row, column){return new QLayoutItem();};

/**
  * @name originCorner
  * @function
  * @memberOf QGridLayout.prototype
  * @returns {Qt.Corner}
  */
QGridLayout.prototype.originCorner = function(){return new Qt.Corner();};

/**
  * @name rowCount
  * @function
  * @memberOf QGridLayout.prototype
  * @returns {Numeric}
  */
QGridLayout.prototype.rowCount = function(){return new Numeric();};

/**
  * @name rowMinimumHeight
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGridLayout.prototype.rowMinimumHeight = function(row){return new Numeric();};

/**
  * @name rowStretch
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGridLayout.prototype.rowStretch = function(row){return new Numeric();};

/**
  * @name setColumnMinimumWidth
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} minSize
  * @returns {undefined}
  */
QGridLayout.prototype.setColumnMinimumWidth = function(column, minSize){return undefined;};

/**
  * @name setColumnStretch
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QGridLayout.prototype.setColumnStretch = function(column, stretch){return undefined;};

/**
  * @name setDefaultPositioning
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} n
  * @param {QPrinter.Orientation} orient
  * @returns {undefined}
  */
QGridLayout.prototype.setDefaultPositioning = function(n, orient){return undefined;};

/**
  * @name setHorizontalSpacing
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGridLayout.prototype.setHorizontalSpacing = function(spacing){return undefined;};

/**
  * @name setOriginCorner
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Qt.Corner} arg__1
  * @returns {undefined}
  */
QGridLayout.prototype.setOriginCorner = function(arg__1){return undefined;};

/**
  * @name setRowMinimumHeight
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} minSize
  * @returns {undefined}
  */
QGridLayout.prototype.setRowMinimumHeight = function(row, minSize){return undefined;};

/**
  * @name setRowStretch
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QGridLayout.prototype.setRowStretch = function(row, stretch){return undefined;};

/**
  * @name setSpacing
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGridLayout.prototype.setSpacing = function(spacing){return undefined;};

/**
  * @name setVerticalSpacing
  * @function
  * @memberOf QGridLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGridLayout.prototype.setVerticalSpacing = function(spacing){return undefined;};

/**
  * @name spacing
  * @function
  * @memberOf QGridLayout.prototype
  * @returns {Numeric}
  */
QGridLayout.prototype.spacing = function(){return new Numeric();};

/**
  * @name verticalSpacing
  * @function
  * @memberOf QGridLayout.prototype
  * @returns {Numeric}
  */
QGridLayout.prototype.verticalSpacing = function(){return new Numeric();};

