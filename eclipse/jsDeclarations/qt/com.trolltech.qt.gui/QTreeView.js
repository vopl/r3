/**
  * @name QTreeView
  * @constructor
  * @extends QAbstractItemView
  * @param {QWidget} parent
  */
function QTreeView(parent){return undefined;};

QTreeView.prototype = new QAbstractItemView();

/**
  * @name columnAt
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} x
  * @returns {Numeric}
  */
QTreeView.prototype.columnAt = function(x){return new Numeric();};

/**
  * @name columnViewportPosition
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTreeView.prototype.columnViewportPosition = function(column){return new Numeric();};

/**
  * @name columnWidth
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTreeView.prototype.columnWidth = function(column){return new Numeric();};

/**
  * @name header
  * @function
  * @memberOf QTreeView.prototype
  * @returns {QHeaderView}
  */
QTreeView.prototype.header = function(){return new QHeaderView();};

/**
  * @name indexAbove
  * @function
  * @memberOf QTreeView.prototype
  * @param {QModelIndex} index
  * @returns {QModelIndex}
  */
QTreeView.prototype.indexAbove = function(index){return new QModelIndex();};

/**
  * @name indexBelow
  * @function
  * @memberOf QTreeView.prototype
  * @param {QModelIndex} index
  * @returns {QModelIndex}
  */
QTreeView.prototype.indexBelow = function(index){return new QModelIndex();};

/**
  * @name isColumnHidden
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} column
  * @returns {Boolean}
  */
QTreeView.prototype.isColumnHidden = function(column){return new Boolean();};

/**
  * @name isExpanded
  * @function
  * @memberOf QTreeView.prototype
  * @param {QModelIndex} index
  * @returns {Boolean}
  */
QTreeView.prototype.isExpanded = function(index){return new Boolean();};

/**
  * @name isFirstColumnSpanned
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QTreeView.prototype.isFirstColumnSpanned = function(row, parent){return new Boolean();};

/**
  * @name isRowHidden
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QTreeView.prototype.isRowHidden = function(row, parent){return new Boolean();};

/**
  * @name setColumnHidden
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} column
  * @param {Boolean} hide
  * @returns {undefined}
  */
QTreeView.prototype.setColumnHidden = function(column, hide){return undefined;};

/**
  * @name setColumnWidth
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} column
  * @param {Numeric} width
  * @returns {undefined}
  */
QTreeView.prototype.setColumnWidth = function(column, width){return undefined;};

/**
  * @name setExpanded
  * @function
  * @memberOf QTreeView.prototype
  * @param {QModelIndex} index
  * @param {Boolean} expand
  * @returns {undefined}
  */
QTreeView.prototype.setExpanded = function(index, expand){return undefined;};

/**
  * @name setFirstColumnSpanned
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @param {Boolean} span
  * @returns {undefined}
  */
QTreeView.prototype.setFirstColumnSpanned = function(row, parent, span){return undefined;};

/**
  * @name setHeader
  * @function
  * @memberOf QTreeView.prototype
  * @param {QHeaderView} header
  * @returns {undefined}
  */
QTreeView.prototype.setHeader = function(header){return undefined;};

/**
  * @name setRowHidden
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @param {Boolean} hide
  * @returns {undefined}
  */
QTreeView.prototype.setRowHidden = function(row, parent, hide){return undefined;};

/**
  * @name sortByColumn
  * @function
  * @memberOf QTreeView.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QTreeView.prototype.sortByColumn = function(column, order){return undefined;};

/**
  * @name autoExpandDelay
  * @memberOf QTreeView.prototype
  * @type Numeric
  */
QTreeView.prototype.autoExpandDelay = new Numeric();

/**
  * @name indentation
  * @memberOf QTreeView.prototype
  * @type Numeric
  */
QTreeView.prototype.indentation = new Numeric();

/**
  * @name rootIsDecorated
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.rootIsDecorated = new Boolean();

/**
  * @name uniformRowHeights
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.uniformRowHeights = new Boolean();

/**
  * @name itemsExpandable
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.itemsExpandable = new Boolean();

/**
  * @name sortingEnabled
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.sortingEnabled = new Boolean();

/**
  * @name animated
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.animated = new Boolean();

/**
  * @name allColumnsShowFocus
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.allColumnsShowFocus = new Boolean();

/**
  * @name wordWrap
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.wordWrap = new Boolean();

/**
  * @name headerHidden
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.headerHidden = new Boolean();

/**
  * @name expandsOnDoubleClick
  * @memberOf QTreeView.prototype
  * @type Boolean
  */
QTreeView.prototype.expandsOnDoubleClick = new Boolean();


