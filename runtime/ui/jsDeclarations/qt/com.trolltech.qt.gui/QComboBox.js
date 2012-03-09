/**
  * @name QComboBox
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QComboBox(parent){return undefined;};

QComboBox.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QComboBox
  * @name NoInsert
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.NoInsert = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QComboBox
  * @name InsertAtTop
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.InsertAtTop = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QComboBox
  * @name InsertAtCurrent
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.InsertAtCurrent = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QComboBox
  * @name InsertAtBottom
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.InsertAtBottom = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QComboBox
  * @name InsertAfterCurrent
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.InsertAfterCurrent = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QComboBox
  * @name InsertBeforeCurrent
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.InsertBeforeCurrent = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QComboBox
  * @name InsertAlphabetically
  * @see QComboBox#InsertPolicy
  * @type Number
  */
QComboBox.InsertAlphabetically = 0x6;

/**
  * @constructor 
  * @memberOf QComboBox
  * @name InsertPolicy
  */
QComboBox.InsertPolicy = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QComboBox
  * @name AdjustToContents
  * @see QComboBox#SizeAdjustPolicy
  * @type Number
  */
QComboBox.AdjustToContents = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QComboBox
  * @name AdjustToContentsOnFirstShow
  * @see QComboBox#SizeAdjustPolicy
  * @type Number
  */
QComboBox.AdjustToContentsOnFirstShow = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QComboBox
  * @name AdjustToMinimumContentsLength
  * @see QComboBox#SizeAdjustPolicy
  * @type Number
  */
QComboBox.AdjustToMinimumContentsLength = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QComboBox
  * @name AdjustToMinimumContentsLengthWithIcon
  * @see QComboBox#SizeAdjustPolicy
  * @type Number
  */
QComboBox.AdjustToMinimumContentsLengthWithIcon = 0x3;

/**
  * @constructor 
  * @memberOf QComboBox
  * @name SizeAdjustPolicy
  */
QComboBox.SizeAdjustPolicy = function(value){;};



/**
  * @name addItem
  * @function
  * @memberOf QComboBox.prototype
  * @param {QIcon} icon
  * @param {String} text
  * @param {Object} userData
  * @returns {undefined}
  */
QComboBox.prototype.addItem = function(icon, text, userData){return undefined;};

/**
  * @name addItems
  * @function
  * @memberOf QComboBox.prototype
  * @param {Array} texts
  * @returns {undefined}
  */
QComboBox.prototype.addItems = function(texts){return undefined;};

/**
  * @name completer
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QCompleter}
  */
QComboBox.prototype.completer = function(){return new QCompleter();};

/**
  * @name findData
  * @function
  * @memberOf QComboBox.prototype
  * @param {Object} data
  * @param {Numeric} role
  * @param {Qt.MatchFlags} flags
  * @returns {Numeric}
  */
QComboBox.prototype.findData = function(data, role, flags){return new Numeric();};

/**
  * @name findText
  * @function
  * @memberOf QComboBox.prototype
  * @param {String} text
  * @param {Qt.MatchFlags} flags
  * @returns {Numeric}
  */
QComboBox.prototype.findText = function(text, flags){return new Numeric();};

/**
  * @name hidePopup
  * @function
  * @memberOf QComboBox.prototype
  * @returns {undefined}
  */
QComboBox.prototype.hidePopup = function(){return undefined;};

/**
  * @name insertItem
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @param {QIcon} icon
  * @param {String} text
  * @param {Object} userData
  * @returns {undefined}
  */
QComboBox.prototype.insertItem = function(index, icon, text, userData){return undefined;};

/**
  * @name insertItems
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @param {Array} texts
  * @returns {undefined}
  */
QComboBox.prototype.insertItems = function(index, texts){return undefined;};

/**
  * @name insertSeparator
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @returns {undefined}
  */
QComboBox.prototype.insertSeparator = function(index){return undefined;};

/**
  * @name itemData
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @param {Numeric} role
  * @returns {Object}
  */
QComboBox.prototype.itemData = function(index, role){return new Object();};

/**
  * @name itemDelegate
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QAbstractItemDelegate}
  */
QComboBox.prototype.itemDelegate = function(){return new QAbstractItemDelegate();};

/**
  * @name itemIcon
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @returns {QIcon}
  */
QComboBox.prototype.itemIcon = function(index){return new QIcon();};

/**
  * @name itemText
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QComboBox.prototype.itemText = function(index){return new String();};

/**
  * @name lineEdit
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QLineEdit}
  */
QComboBox.prototype.lineEdit = function(){return new QLineEdit();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QSize}
  */
QComboBox.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name model
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QAbstractItemModel}
  */
QComboBox.prototype.model = function(){return new QAbstractItemModel();};

/**
  * @name removeItem
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @returns {undefined}
  */
QComboBox.prototype.removeItem = function(index){return undefined;};

/**
  * @name rootModelIndex
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QModelIndex}
  */
QComboBox.prototype.rootModelIndex = function(){return new QModelIndex();};

/**
  * @name setCompleter
  * @function
  * @memberOf QComboBox.prototype
  * @param {QCompleter} c
  * @returns {undefined}
  */
QComboBox.prototype.setCompleter = function(c){return undefined;};

/**
  * @name setItemData
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @param {Object} value
  * @param {Numeric} role
  * @returns {undefined}
  */
QComboBox.prototype.setItemData = function(index, value, role){return undefined;};

/**
  * @name setItemDelegate
  * @function
  * @memberOf QComboBox.prototype
  * @param {QAbstractItemDelegate} delegate
  * @returns {undefined}
  */
QComboBox.prototype.setItemDelegate = function(delegate){return undefined;};

/**
  * @name setItemIcon
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @param {QIcon} icon
  * @returns {undefined}
  */
QComboBox.prototype.setItemIcon = function(index, icon){return undefined;};

/**
  * @name setItemText
  * @function
  * @memberOf QComboBox.prototype
  * @param {Numeric} index
  * @param {String} text
  * @returns {undefined}
  */
QComboBox.prototype.setItemText = function(index, text){return undefined;};

/**
  * @name setLineEdit
  * @function
  * @memberOf QComboBox.prototype
  * @param {QLineEdit} edit
  * @returns {undefined}
  */
QComboBox.prototype.setLineEdit = function(edit){return undefined;};

/**
  * @name setModel
  * @function
  * @memberOf QComboBox.prototype
  * @param {QAbstractItemModel} model
  * @returns {undefined}
  */
QComboBox.prototype.setModel = function(model){return undefined;};

/**
  * @name setRootModelIndex
  * @function
  * @memberOf QComboBox.prototype
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QComboBox.prototype.setRootModelIndex = function(index){return undefined;};

/**
  * @name setValidator
  * @function
  * @memberOf QComboBox.prototype
  * @param {QValidator} v
  * @returns {undefined}
  */
QComboBox.prototype.setValidator = function(v){return undefined;};

/**
  * @name setView
  * @function
  * @memberOf QComboBox.prototype
  * @param {QAbstractItemView} itemView
  * @returns {undefined}
  */
QComboBox.prototype.setView = function(itemView){return undefined;};

/**
  * @name showPopup
  * @function
  * @memberOf QComboBox.prototype
  * @returns {undefined}
  */
QComboBox.prototype.showPopup = function(){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QSize}
  */
QComboBox.prototype.sizeHint = function(){return new QSize();};

/**
  * @name validator
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QValidator}
  */
QComboBox.prototype.validator = function(){return new QValidator();};

/**
  * @name view
  * @function
  * @memberOf QComboBox.prototype
  * @returns {QAbstractItemView}
  */
QComboBox.prototype.view = function(){return new QAbstractItemView();};

/**
  * @name editable
  * @memberOf QComboBox.prototype
  * @type Boolean
  */
QComboBox.prototype.editable = new Boolean();

/**
  * @name count
  * @memberOf QComboBox.prototype
  * @type Numeric
  */
QComboBox.prototype.count = new Numeric();

/**
  * @name currentText
  * @memberOf QComboBox.prototype
  * @type String
  */
QComboBox.prototype.currentText = new String();

/**
  * @name currentIndex
  * @memberOf QComboBox.prototype
  * @type Numeric
  */
QComboBox.prototype.currentIndex = new Numeric();

/**
  * @name maxVisibleItems
  * @memberOf QComboBox.prototype
  * @type Numeric
  */
QComboBox.prototype.maxVisibleItems = new Numeric();

/**
  * @name maxCount
  * @memberOf QComboBox.prototype
  * @type Numeric
  */
QComboBox.prototype.maxCount = new Numeric();

/**
  * @name insertPolicy
  * @memberOf QComboBox.prototype
  * @type QComboBox.InsertPolicy
  */
QComboBox.prototype.insertPolicy = new QComboBox.InsertPolicy();

/**
  * @name sizeAdjustPolicy
  * @memberOf QComboBox.prototype
  * @type QComboBox.SizeAdjustPolicy
  */
QComboBox.prototype.sizeAdjustPolicy = new QComboBox.SizeAdjustPolicy();

/**
  * @name minimumContentsLength
  * @memberOf QComboBox.prototype
  * @type Numeric
  */
QComboBox.prototype.minimumContentsLength = new Numeric();

/**
  * @name iconSize
  * @memberOf QComboBox.prototype
  * @type QSize
  */
QComboBox.prototype.iconSize = new QSize();

/**
  * @name autoCompletion
  * @memberOf QComboBox.prototype
  * @type Boolean
  */
QComboBox.prototype.autoCompletion = new Boolean();

/**
  * @name autoCompletionCaseSensitivity
  * @memberOf QComboBox.prototype
  * @type Qt.CaseSensitivity
  */
QComboBox.prototype.autoCompletionCaseSensitivity = new Qt.CaseSensitivity();

/**
  * @name duplicatesEnabled
  * @memberOf QComboBox.prototype
  * @type Boolean
  */
QComboBox.prototype.duplicatesEnabled = new Boolean();

/**
  * @name frame
  * @memberOf QComboBox.prototype
  * @type Boolean
  */
QComboBox.prototype.frame = new Boolean();

/**
  * @name modelColumn
  * @memberOf QComboBox.prototype
  * @type Numeric
  */
QComboBox.prototype.modelColumn = new Numeric();


