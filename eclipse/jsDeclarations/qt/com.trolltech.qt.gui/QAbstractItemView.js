/**
  * @name QAbstractItemView
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QWidget} parent
  */
function QAbstractItemView(parent){return undefined;};

QAbstractItemView.prototype = new QAbstractScrollArea();

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractItemView
  * @name NoDragDrop
  * @see QAbstractItemView#DragDropMode
  * @type Number
  */
QAbstractItemView.NoDragDrop = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractItemView
  * @name DragOnly
  * @see QAbstractItemView#DragDropMode
  * @type Number
  */
QAbstractItemView.DragOnly = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractItemView
  * @name DropOnly
  * @see QAbstractItemView#DragDropMode
  * @type Number
  */
QAbstractItemView.DropOnly = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractItemView
  * @name DragDrop
  * @see QAbstractItemView#DragDropMode
  * @type Number
  */
QAbstractItemView.DragDrop = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAbstractItemView
  * @name InternalMove
  * @see QAbstractItemView#DragDropMode
  * @type Number
  */
QAbstractItemView.InternalMove = 0x4;

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name DragDropMode
  */
QAbstractItemView.DragDropMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractItemView
  * @name SelectItems
  * @see QAbstractItemView#SelectionBehavior
  * @type Number
  */
QAbstractItemView.SelectItems = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractItemView
  * @name SelectRows
  * @see QAbstractItemView#SelectionBehavior
  * @type Number
  */
QAbstractItemView.SelectRows = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractItemView
  * @name SelectColumns
  * @see QAbstractItemView#SelectionBehavior
  * @type Number
  */
QAbstractItemView.SelectColumns = 0x2;

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name SelectionBehavior
  */
QAbstractItemView.SelectionBehavior = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QAbstractItemView
  * @name NoEditTriggers
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.NoEditTriggers = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QAbstractItemView
  * @name CurrentChanged
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.CurrentChanged = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QAbstractItemView
  * @name DoubleClicked
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.DoubleClicked = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf QAbstractItemView
  * @name SelectedClicked
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.SelectedClicked = 0x4;

/**
  * @default 8
  * @constant
  * @memberOf QAbstractItemView
  * @name EditKeyPressed
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.EditKeyPressed = 0x8;

/**
  * @default 16
  * @constant
  * @memberOf QAbstractItemView
  * @name AnyKeyPressed
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.AnyKeyPressed = 0x10;

/**
  * @default 31
  * @constant
  * @memberOf QAbstractItemView
  * @name AllEditTriggers
  * @see QAbstractItemView#EditTriggers
  * @see QAbstractItemView#EditTrigger
  * @type Number
  */
QAbstractItemView.AllEditTriggers = 0x1f;

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name EditTrigger
  */
QAbstractItemView.EditTrigger = function(value){;};

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name EditTriggers
  */
QAbstractItemView.EditTriggers = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractItemView
  * @name ScrollPerItem
  * @see QAbstractItemView#ScrollMode
  * @type Number
  */
QAbstractItemView.ScrollPerItem = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractItemView
  * @name ScrollPerPixel
  * @see QAbstractItemView#ScrollMode
  * @type Number
  */
QAbstractItemView.ScrollPerPixel = 0x1;

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name ScrollMode
  */
QAbstractItemView.ScrollMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractItemView
  * @name EnsureVisible
  * @see QAbstractItemView#ScrollHint
  * @type Number
  */
QAbstractItemView.EnsureVisible = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractItemView
  * @name PositionAtTop
  * @see QAbstractItemView#ScrollHint
  * @type Number
  */
QAbstractItemView.PositionAtTop = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractItemView
  * @name PositionAtBottom
  * @see QAbstractItemView#ScrollHint
  * @type Number
  */
QAbstractItemView.PositionAtBottom = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractItemView
  * @name PositionAtCenter
  * @see QAbstractItemView#ScrollHint
  * @type Number
  */
QAbstractItemView.PositionAtCenter = 0x3;

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name ScrollHint
  */
QAbstractItemView.ScrollHint = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractItemView
  * @name NoSelection
  * @see QAbstractItemView#SelectionMode
  * @type Number
  */
QAbstractItemView.NoSelection = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractItemView
  * @name SingleSelection
  * @see QAbstractItemView#SelectionMode
  * @type Number
  */
QAbstractItemView.SingleSelection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractItemView
  * @name MultiSelection
  * @see QAbstractItemView#SelectionMode
  * @type Number
  */
QAbstractItemView.MultiSelection = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractItemView
  * @name ExtendedSelection
  * @see QAbstractItemView#SelectionMode
  * @type Number
  */
QAbstractItemView.ExtendedSelection = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAbstractItemView
  * @name ContiguousSelection
  * @see QAbstractItemView#SelectionMode
  * @type Number
  */
QAbstractItemView.ContiguousSelection = 0x4;

/**
  * @constructor 
  * @memberOf QAbstractItemView
  * @name SelectionMode
  */
QAbstractItemView.SelectionMode = function(value){;};



/**
  * @name closePersistentEditor
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QAbstractItemView.prototype.closePersistentEditor = function(index){return undefined;};

/**
  * @name currentIndex
  * @function
  * @memberOf QAbstractItemView.prototype
  * @returns {QModelIndex}
  */
QAbstractItemView.prototype.currentIndex = function(){return new QModelIndex();};

/**
  * @name indexAt
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QPoint} point
  * @returns {QModelIndex}
  */
QAbstractItemView.prototype.indexAt = function(point){return new QModelIndex();};

/**
  * @name indexWidget
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @returns {QWidget}
  */
QAbstractItemView.prototype.indexWidget = function(index){return new QWidget();};

/**
  * @name itemDelegate
  * @function
  * @memberOf QAbstractItemView.prototype
  * @returns {QAbstractItemDelegate}
  */
QAbstractItemView.prototype.itemDelegate = function(){return new QAbstractItemDelegate();};

/**
  * @name itemDelegateForColumn
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {Numeric} column
  * @returns {QAbstractItemDelegate}
  */
QAbstractItemView.prototype.itemDelegateForColumn = function(column){return new QAbstractItemDelegate();};

/**
  * @name itemDelegateForRow
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {Numeric} row
  * @returns {QAbstractItemDelegate}
  */
QAbstractItemView.prototype.itemDelegateForRow = function(row){return new QAbstractItemDelegate();};

/**
  * @name keyboardSearch
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {String} search
  * @returns {undefined}
  */
QAbstractItemView.prototype.keyboardSearch = function(search){return undefined;};

/**
  * @name model
  * @function
  * @memberOf QAbstractItemView.prototype
  * @returns {QAbstractItemModel}
  */
QAbstractItemView.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name openPersistentEditor
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QAbstractItemView.prototype.openPersistentEditor = function(index){return undefined;};

/**
  * @name rootIndex
  * @function
  * @memberOf QAbstractItemView.prototype
  * @returns {QModelIndex}
  */
QAbstractItemView.prototype.rootIndex = function(){return new QModelIndex();};

/**
  * @name scrollTo
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @param {QAbstractItemView.ScrollHint} hint
  * @returns {undefined}
  */
QAbstractItemView.prototype.scrollTo = function(index, hint){return undefined;};

/**
  * @name selectionModel
  * @function
  * @memberOf QAbstractItemView.prototype
  * @returns {QItemSelectionModel}
  */
QAbstractItemView.prototype.selectionModel = function(){return new QItemSelectionModel();};

/**
  * @name setIndexWidget
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @param {QWidget} widget
  * @returns {undefined}
  */
QAbstractItemView.prototype.setIndexWidget = function(index, widget){return undefined;};

/**
  * @name setItemDelegate
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QAbstractItemDelegate} delegate
  * @returns {undefined}
  */
QAbstractItemView.prototype.setItemDelegate = function(delegate){return undefined;};

/**
  * @name setItemDelegateForColumn
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {Numeric} column
  * @param {QAbstractItemDelegate} delegate
  * @returns {undefined}
  */
QAbstractItemView.prototype.setItemDelegateForColumn = function(column, delegate){return undefined;};

/**
  * @name setItemDelegateForRow
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {Numeric} row
  * @param {QAbstractItemDelegate} delegate
  * @returns {undefined}
  */
QAbstractItemView.prototype.setItemDelegateForRow = function(row, delegate){return undefined;};

/**
  * @name setModel
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QAbstractItemModel} model
  * @returns {undefined}
  */
QAbstractItemView.prototype.setModel = function(model){return undefined;};

/**
  * @name setSelectionModel
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QItemSelectionModel} selectionModel
  * @returns {undefined}
  */
QAbstractItemView.prototype.setSelectionModel = function(selectionModel){return undefined;};

/**
  * @name sizeHintForColumn
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QAbstractItemView.prototype.sizeHintForColumn = function(column){return new Numeric();};

/**
  * @name sizeHintForIndex
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @returns {QSize}
  */
QAbstractItemView.prototype.sizeHintForIndex = function(index){return new QSize();};

/**
  * @name sizeHintForRow
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {Numeric} row
  * @returns {Numeric}
  */
QAbstractItemView.prototype.sizeHintForRow = function(row){return new Numeric();};

/**
  * @name visualRect
  * @function
  * @memberOf QAbstractItemView.prototype
  * @param {QModelIndex} index
  * @returns {QRect}
  */
QAbstractItemView.prototype.visualRect = function(index){return new QRect();};

/**
  * @name autoScroll
  * @memberOf QAbstractItemView.prototype
  * @type Boolean
  */
QAbstractItemView.prototype.autoScroll = new Boolean();

/**
  * @name autoScrollMargin
  * @memberOf QAbstractItemView.prototype
  * @type Numeric
  */
QAbstractItemView.prototype.autoScrollMargin = new Numeric();

/**
  * @name editTriggers
  * @memberOf QAbstractItemView.prototype
  * @type QAbstractItemView.EditTriggers
  */
QAbstractItemView.prototype.editTriggers = new QAbstractItemView.EditTriggers();

/**
  * @name tabKeyNavigation
  * @memberOf QAbstractItemView.prototype
  * @type Boolean
  */
QAbstractItemView.prototype.tabKeyNavigation = new Boolean();

/**
  * @name showDropIndicator
  * @memberOf QAbstractItemView.prototype
  * @type Boolean
  */
QAbstractItemView.prototype.showDropIndicator = new Boolean();

/**
  * @name dragEnabled
  * @memberOf QAbstractItemView.prototype
  * @type Boolean
  */
QAbstractItemView.prototype.dragEnabled = new Boolean();

/**
  * @name dragDropOverwriteMode
  * @memberOf QAbstractItemView.prototype
  * @type Boolean
  */
QAbstractItemView.prototype.dragDropOverwriteMode = new Boolean();

/**
  * @name dragDropMode
  * @memberOf QAbstractItemView.prototype
  * @type QAbstractItemView.DragDropMode
  */
QAbstractItemView.prototype.dragDropMode = new QAbstractItemView.DragDropMode();

/**
  * @name defaultDropAction
  * @memberOf QAbstractItemView.prototype
  * @type Qt.DropAction
  */
QAbstractItemView.prototype.defaultDropAction = new Qt.DropAction();

/**
  * @name alternatingRowColors
  * @memberOf QAbstractItemView.prototype
  * @type Boolean
  */
QAbstractItemView.prototype.alternatingRowColors = new Boolean();

/**
  * @name selectionMode
  * @memberOf QAbstractItemView.prototype
  * @type QAbstractItemView.SelectionMode
  */
QAbstractItemView.prototype.selectionMode = new QAbstractItemView.SelectionMode();

/**
  * @name selectionBehavior
  * @memberOf QAbstractItemView.prototype
  * @type QAbstractItemView.SelectionBehavior
  */
QAbstractItemView.prototype.selectionBehavior = new QAbstractItemView.SelectionBehavior();

/**
  * @name iconSize
  * @memberOf QAbstractItemView.prototype
  * @type QSize
  */
QAbstractItemView.prototype.iconSize = new QSize();

/**
  * @name textElideMode
  * @memberOf QAbstractItemView.prototype
  * @type Qt.TextElideMode
  */
QAbstractItemView.prototype.textElideMode = new Qt.TextElideMode();

/**
  * @name verticalScrollMode
  * @memberOf QAbstractItemView.prototype
  * @type QAbstractItemView.ScrollMode
  */
QAbstractItemView.prototype.verticalScrollMode = new QAbstractItemView.ScrollMode();

/**
  * @name horizontalScrollMode
  * @memberOf QAbstractItemView.prototype
  * @type QAbstractItemView.ScrollMode
  */
QAbstractItemView.prototype.horizontalScrollMode = new QAbstractItemView.ScrollMode();


