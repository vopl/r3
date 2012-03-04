/**
  * @name QGraphicsGridLayout
  * @constructor
  * @extends QGraphicsLayout
  * @param {QGraphicsLayoutItem} parent
  */
function QGraphicsGridLayout(parent){return undefined;};

QGraphicsGridLayout.prototype = new QGraphicsLayout();

/**
  * @name addItem
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {QGraphicsLayoutItem} item
  * @param {Numeric} row
  * @param {Numeric} column
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.addItem = function(item, row, column, alignment){return undefined;};

/**
  * @name alignment
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {QGraphicsLayoutItem} item
  * @returns {Qt.Alignment}
  */
QGraphicsGridLayout.prototype.alignment = function(item){return new Qt.Alignment();};

/**
  * @name columnAlignment
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @returns {Qt.Alignment}
  */
QGraphicsGridLayout.prototype.columnAlignment = function(column){return new Qt.Alignment();};

/**
  * @name columnCount
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.columnCount = function(){return new Numeric();};

/**
  * @name columnMaximumWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.columnMaximumWidth = function(column){return new Numeric();};

/**
  * @name columnMinimumWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.columnMinimumWidth = function(column){return new Numeric();};

/**
  * @name columnPreferredWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.columnPreferredWidth = function(column){return new Numeric();};

/**
  * @name columnSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.columnSpacing = function(column){return new Numeric();};

/**
  * @name columnStretchFactor
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.columnStretchFactor = function(column){return new Numeric();};

/**
  * @name horizontalSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.horizontalSpacing = function(){return new Numeric();};

/**
  * @name itemAt
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QGraphicsLayoutItem}
  */
QGraphicsGridLayout.prototype.itemAt = function(row, column){return new QGraphicsLayoutItem();};

/**
  * @name removeItem
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {QGraphicsLayoutItem} item
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.removeItem = function(item){return undefined;};

/**
  * @name rowAlignment
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @returns {Qt.Alignment}
  */
QGraphicsGridLayout.prototype.rowAlignment = function(row){return new Qt.Alignment();};

/**
  * @name rowCount
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.rowCount = function(){return new Numeric();};

/**
  * @name rowMaximumHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.rowMaximumHeight = function(row){return new Numeric();};

/**
  * @name rowMinimumHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.rowMinimumHeight = function(row){return new Numeric();};

/**
  * @name rowPreferredHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.rowPreferredHeight = function(row){return new Numeric();};

/**
  * @name rowSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.rowSpacing = function(row){return new Numeric();};

/**
  * @name rowStretchFactor
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.rowStretchFactor = function(row){return new Numeric();};

/**
  * @name setAlignment
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {QGraphicsLayoutItem} item
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setAlignment = function(item, alignment){return undefined;};

/**
  * @name setColumnAlignment
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnAlignment = function(column, alignment){return undefined;};

/**
  * @name setColumnFixedWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} width
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnFixedWidth = function(column, width){return undefined;};

/**
  * @name setColumnMaximumWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} width
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnMaximumWidth = function(column, width){return undefined;};

/**
  * @name setColumnMinimumWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} width
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnMinimumWidth = function(column, width){return undefined;};

/**
  * @name setColumnPreferredWidth
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} width
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnPreferredWidth = function(column, width){return undefined;};

/**
  * @name setColumnSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnSpacing = function(column, spacing){return undefined;};

/**
  * @name setColumnStretchFactor
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} column
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setColumnStretchFactor = function(column, stretch){return undefined;};

/**
  * @name setHorizontalSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setHorizontalSpacing = function(spacing){return undefined;};

/**
  * @name setRowAlignment
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowAlignment = function(row, alignment){return undefined;};

/**
  * @name setRowFixedHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} height
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowFixedHeight = function(row, height){return undefined;};

/**
  * @name setRowMaximumHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} height
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowMaximumHeight = function(row, height){return undefined;};

/**
  * @name setRowMinimumHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} height
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowMinimumHeight = function(row, height){return undefined;};

/**
  * @name setRowPreferredHeight
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} height
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowPreferredHeight = function(row, height){return undefined;};

/**
  * @name setRowSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowSpacing = function(row, spacing){return undefined;};

/**
  * @name setRowStretchFactor
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} row
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setRowStretchFactor = function(row, stretch){return undefined;};

/**
  * @name setSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setSpacing = function(spacing){return undefined;};

/**
  * @name setVerticalSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QGraphicsGridLayout.prototype.setVerticalSpacing = function(spacing){return undefined;};

/**
  * @name verticalSpacing
  * @function
  * @memberOf QGraphicsGridLayout.prototype
  * @returns {Numeric}
  */
QGraphicsGridLayout.prototype.verticalSpacing = function(){return new Numeric();};

