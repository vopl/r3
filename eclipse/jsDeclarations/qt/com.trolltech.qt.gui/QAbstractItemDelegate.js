/**
  * @name QAbstractItemDelegate
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QAbstractItemDelegate(parent){return undefined;};

QAbstractItemDelegate.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractItemDelegate
  * @name NoHint
  * @see QAbstractItemDelegate#EndEditHint
  * @type Number
  */
QAbstractItemDelegate.NoHint = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractItemDelegate
  * @name EditNextItem
  * @see QAbstractItemDelegate#EndEditHint
  * @type Number
  */
QAbstractItemDelegate.EditNextItem = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractItemDelegate
  * @name EditPreviousItem
  * @see QAbstractItemDelegate#EndEditHint
  * @type Number
  */
QAbstractItemDelegate.EditPreviousItem = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractItemDelegate
  * @name SubmitModelCache
  * @see QAbstractItemDelegate#EndEditHint
  * @type Number
  */
QAbstractItemDelegate.SubmitModelCache = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAbstractItemDelegate
  * @name RevertModelCache
  * @see QAbstractItemDelegate#EndEditHint
  * @type Number
  */
QAbstractItemDelegate.RevertModelCache = 0x4;

/**
  * @constructor 
  * @memberOf QAbstractItemDelegate
  * @name EndEditHint
  */
QAbstractItemDelegate.EndEditHint = function(value){;};



/**
  * @name createEditor
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QWidget} parent
  * @param {QStyleOptionViewItem} option
  * @param {QModelIndex} index
  * @returns {QWidget}
  */
QAbstractItemDelegate.prototype.createEditor = function(parent, option, index){return new QWidget();};

/**
  * @name editorEvent
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QEvent} event
  * @param {QAbstractItemModel} model
  * @param {QStyleOptionViewItem} option
  * @param {QModelIndex} index
  * @returns {Boolean}
  */
QAbstractItemDelegate.prototype.editorEvent = function(event, model, option, index){return new Boolean();};

/**
  * @name paint
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QPainter} painter
  * @param {QStyleOptionViewItem} option
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QAbstractItemDelegate.prototype.paint = function(painter, option, index){return undefined;};

/**
  * @name setEditorData
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QWidget} editor
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QAbstractItemDelegate.prototype.setEditorData = function(editor, index){return undefined;};

/**
  * @name setModelData
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QWidget} editor
  * @param {QAbstractItemModel} model
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QAbstractItemDelegate.prototype.setModelData = function(editor, model, index){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QStyleOptionViewItem} option
  * @param {QModelIndex} index
  * @returns {QSize}
  */
QAbstractItemDelegate.prototype.sizeHint = function(option, index){return new QSize();};

/**
  * @name updateEditorGeometry
  * @function
  * @memberOf QAbstractItemDelegate.prototype
  * @param {QWidget} editor
  * @param {QStyleOptionViewItem} option
  * @param {QModelIndex} index
  * @returns {undefined}
  */
QAbstractItemDelegate.prototype.updateEditorGeometry = function(editor, option, index){return undefined;};

