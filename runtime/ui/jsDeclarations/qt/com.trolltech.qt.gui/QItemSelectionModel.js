/**
  * @name QItemSelectionModel
  * @constructor
  * @extends QObject
  * @param {QAbstractItemModel} model
  */
function QItemSelectionModel(model){return undefined;};

/**
  * @name QItemSelectionModel^1
  * @constructor
  * @extends QObject
  * @param {QAbstractItemModel} model
  * @param {QObject} parent
  */
function QItemSelectionModel(model, parent){return undefined;};

QItemSelectionModel.prototype = new QObject();

/**
  * @default 0x0000
  * @constant
  * @memberOf QItemSelectionModel
  * @name NoUpdate
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.NoUpdate = 0x0;

/**
  * @default 0x0001
  * @constant
  * @memberOf QItemSelectionModel
  * @name Clear
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Clear = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QItemSelectionModel
  * @name Select
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Select = 0x2;

/**
  * @default Clear|Select
  * @constant
  * @memberOf QItemSelectionModel
  * @name ClearAndSelect
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.ClearAndSelect = 0x3;

/**
  * @default 0x0004
  * @constant
  * @memberOf QItemSelectionModel
  * @name Deselect
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Deselect = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QItemSelectionModel
  * @name Toggle
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Toggle = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QItemSelectionModel
  * @name Current
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Current = 0x10;

/**
  * @default Select|Current
  * @constant
  * @memberOf QItemSelectionModel
  * @name SelectCurrent
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.SelectCurrent = 0x12;

/**
  * @default Toggle|Current
  * @constant
  * @memberOf QItemSelectionModel
  * @name ToggleCurrent
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.ToggleCurrent = 0x18;

/**
  * @default 0x0020
  * @constant
  * @memberOf QItemSelectionModel
  * @name Rows
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Rows = 0x20;

/**
  * @default 0x0040
  * @constant
  * @memberOf QItemSelectionModel
  * @name Columns
  * @see QItemSelectionModel#SelectionFlags
  * @see QItemSelectionModel#SelectionFlag
  * @type Number
  */
QItemSelectionModel.Columns = 0x40;

/**
  * @constructor 
  * @memberOf QItemSelectionModel
  * @name SelectionFlag
  */
QItemSelectionModel.SelectionFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QItemSelectionModel
  * @name SelectionFlags
  */
QItemSelectionModel.SelectionFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name columnIntersectsSelection
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QItemSelectionModel.prototype.columnIntersectsSelection = function(column, parent){return new Boolean();};

/**
  * @name currentIndex
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @returns {QModelIndex}
  */
QItemSelectionModel.prototype.currentIndex = function(){return new QModelIndex();};

/**
  * @name hasSelection
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @returns {Boolean}
  */
QItemSelectionModel.prototype.hasSelection = function(){return new Boolean();};

/**
  * @name isColumnSelected
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {Numeric} column
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QItemSelectionModel.prototype.isColumnSelected = function(column, parent){return new Boolean();};

/**
  * @name isRowSelected
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QItemSelectionModel.prototype.isRowSelected = function(row, parent){return new Boolean();};

/**
  * @name isSelected
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {QModelIndex} index
  * @returns {Boolean}
  */
QItemSelectionModel.prototype.isSelected = function(index){return new Boolean();};

/**
  * @name model
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @returns {QAbstractItemModel}
  */
QItemSelectionModel.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name rowIntersectsSelection
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {Numeric} row
  * @param {QModelIndex} parent
  * @returns {Boolean}
  */
QItemSelectionModel.prototype.rowIntersectsSelection = function(row, parent){return new Boolean();};

/**
  * @name selectedColumns
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {Numeric} row
  * @returns {Array}
  */
QItemSelectionModel.prototype.selectedColumns = function(row){return new Array();};

/**
  * @name selectedIndexes
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @returns {Array}
  */
QItemSelectionModel.prototype.selectedIndexes = function(){return new Array();};

/**
  * @name selectedRows
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @param {Numeric} column
  * @returns {Array}
  */
QItemSelectionModel.prototype.selectedRows = function(column){return new Array();};

/**
  * @name selection
  * @function
  * @memberOf QItemSelectionModel.prototype
  * @returns {QItemSelection}
  */
QItemSelectionModel.prototype.selection = function(){return new QItemSelection();};

