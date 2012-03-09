/**
  * @name QStandardItem
  * @constructor
  */
function QStandardItem(){return undefined;};

/**
  * @name QStandardItem^1
  * @constructor
  * @param {QIcon} icon
  * @param {String} text
  */
function QStandardItem(icon, text){return undefined;};

/**
  * @name QStandardItem^2
  * @constructor
  * @param {String} text
  */
function QStandardItem(text){return undefined;};

/**
  * @name QStandardItem^3
  * @constructor
  * @param {Numeric} rows
  * @param {Numeric} columns
  */
function QStandardItem(rows, columns){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QStandardItem
  * @name Type
  * @see QStandardItem#ItemType
  * @type Number
  */
QStandardItem.Type = 0x0;

/**
  * @default 1000
  * @constant
  * @memberOf QStandardItem
  * @name UserType
  * @see QStandardItem#ItemType
  * @type Number
  */
QStandardItem.UserType = 0x3e8;

/**
  * @constructor 
  * @memberOf QStandardItem
  * @name ItemType
  */
QStandardItem.ItemType = function(value){;};



/**
  * @name accessibleDescription
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {String}
  */
QStandardItem.prototype.accessibleDescription = function(){return new String();};

/**
  * @name accessibleText
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {String}
  */
QStandardItem.prototype.accessibleText = function(){return new String();};

/**
  * @name appendColumn
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Array} items
  * @returns {undefined}
  */
QStandardItem.prototype.appendColumn = function(items){return undefined;};

/**
  * @name appendRow
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItem.prototype.appendRow = function(item){return undefined;};

/**
  * @name appendRows
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Array} items
  * @returns {undefined}
  */
QStandardItem.prototype.appendRows = function(items){return undefined;};

/**
  * @name background
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QBrush}
  */
QStandardItem.prototype.background = function(){return new QBrush();};

/**
  * @name checkState
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Qt.CheckState}
  */
QStandardItem.prototype.checkState = function(){return new Qt.CheckState();};

/**
  * @name child
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QStandardItem}
  */
QStandardItem.prototype.child = function(row, column){return new QStandardItem();};

/**
  * @name clone
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QStandardItem}
  */
QStandardItem.prototype.clone = function(){return new QStandardItem();};

/**
  * @name column
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Numeric}
  */
QStandardItem.prototype.column = function(){return new Numeric();};

/**
  * @name columnCount
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Numeric}
  */
QStandardItem.prototype.columnCount = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} role
  * @returns {Object}
  */
QStandardItem.prototype.data = function(role){return new Object();};

/**
  * @name flags
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Qt.ItemFlags}
  */
QStandardItem.prototype.flags = function(){return new Qt.ItemFlags();};

/**
  * @name font
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QFont}
  */
QStandardItem.prototype.font = function(){return new QFont();};

/**
  * @name foreground
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QBrush}
  */
QStandardItem.prototype.foreground = function(){return new QBrush();};

/**
  * @name hasChildren
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.hasChildren = function(){return new Boolean();};

/**
  * @name icon
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QIcon}
  */
QStandardItem.prototype.icon = function(){return new QIcon();};

/**
  * @name index
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QModelIndex}
  */
QStandardItem.prototype.index = function(){return new QModelIndex();};

/**
  * @name insertColumn
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} column
  * @param {Array} items
  * @returns {undefined}
  */
QStandardItem.prototype.insertColumn = function(column, items){return undefined;};

/**
  * @name insertColumns
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} column
  * @param {Numeric} count
  * @returns {undefined}
  */
QStandardItem.prototype.insertColumns = function(column, count){return undefined;};

/**
  * @name insertRow
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItem.prototype.insertRow = function(row, item){return undefined;};

/**
  * @name insertRows
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @param {Array} items
  * @returns {undefined}
  */
QStandardItem.prototype.insertRows = function(row, items){return undefined;};

/**
  * @name isCheckable
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isCheckable = function(){return new Boolean();};

/**
  * @name isDragEnabled
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isDragEnabled = function(){return new Boolean();};

/**
  * @name isDropEnabled
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isDropEnabled = function(){return new Boolean();};

/**
  * @name isEditable
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isEditable = function(){return new Boolean();};

/**
  * @name isEnabled
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isEnabled = function(){return new Boolean();};

/**
  * @name isSelectable
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isSelectable = function(){return new Boolean();};

/**
  * @name isTristate
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Boolean}
  */
QStandardItem.prototype.isTristate = function(){return new Boolean();};

/**
  * @name model
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QStandardItemModel}
  */
QStandardItem.prototype.model = function(){return new QStandardItemModel();};

/**
  * @name parent
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QStandardItem}
  */
QStandardItem.prototype.parent = function(){return new QStandardItem();};

/**
  * @name readFrom
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QDataStream} _in
  * @returns {undefined}
  */
QStandardItem.prototype.readFrom = function(_in){return undefined;};

/**
  * @name removeColumn
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} column
  * @returns {undefined}
  */
QStandardItem.prototype.removeColumn = function(column){return undefined;};

/**
  * @name removeColumns
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} column
  * @param {Numeric} count
  * @returns {undefined}
  */
QStandardItem.prototype.removeColumns = function(column, count){return undefined;};

/**
  * @name removeRow
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @returns {undefined}
  */
QStandardItem.prototype.removeRow = function(row){return undefined;};

/**
  * @name removeRows
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @param {Numeric} count
  * @returns {undefined}
  */
QStandardItem.prototype.removeRows = function(row, count){return undefined;};

/**
  * @name row
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Numeric}
  */
QStandardItem.prototype.row = function(){return new Numeric();};

/**
  * @name rowCount
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Numeric}
  */
QStandardItem.prototype.rowCount = function(){return new Numeric();};

/**
  * @name setAccessibleDescription
  * @function
  * @memberOf QStandardItem.prototype
  * @param {String} accessibleDescription
  * @returns {undefined}
  */
QStandardItem.prototype.setAccessibleDescription = function(accessibleDescription){return undefined;};

/**
  * @name setAccessibleText
  * @function
  * @memberOf QStandardItem.prototype
  * @param {String} accessibleText
  * @returns {undefined}
  */
QStandardItem.prototype.setAccessibleText = function(accessibleText){return undefined;};

/**
  * @name setBackground
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QStandardItem.prototype.setBackground = function(brush){return undefined;};

/**
  * @name setCheckState
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Qt.CheckState} checkState
  * @returns {undefined}
  */
QStandardItem.prototype.setCheckState = function(checkState){return undefined;};

/**
  * @name setCheckable
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} checkable
  * @returns {undefined}
  */
QStandardItem.prototype.setCheckable = function(checkable){return undefined;};

/**
  * @name setChild
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @param {QStandardItem} item
  * @returns {undefined}
  */
QStandardItem.prototype.setChild = function(row, item){return undefined;};

/**
  * @name setColumnCount
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} columns
  * @returns {undefined}
  */
QStandardItem.prototype.setColumnCount = function(columns){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Object} value
  * @param {Numeric} role
  * @returns {undefined}
  */
QStandardItem.prototype.setData = function(value, role){return undefined;};

/**
  * @name setDragEnabled
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} dragEnabled
  * @returns {undefined}
  */
QStandardItem.prototype.setDragEnabled = function(dragEnabled){return undefined;};

/**
  * @name setDropEnabled
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} dropEnabled
  * @returns {undefined}
  */
QStandardItem.prototype.setDropEnabled = function(dropEnabled){return undefined;};

/**
  * @name setEditable
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} editable
  * @returns {undefined}
  */
QStandardItem.prototype.setEditable = function(editable){return undefined;};

/**
  * @name setEnabled
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QStandardItem.prototype.setEnabled = function(enabled){return undefined;};

/**
  * @name setFlags
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Qt.ItemFlags} flags
  * @returns {undefined}
  */
QStandardItem.prototype.setFlags = function(flags){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QFont} font
  * @returns {undefined}
  */
QStandardItem.prototype.setFont = function(font){return undefined;};

/**
  * @name setForeground
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QStandardItem.prototype.setForeground = function(brush){return undefined;};

/**
  * @name setIcon
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QIcon} icon
  * @returns {undefined}
  */
QStandardItem.prototype.setIcon = function(icon){return undefined;};

/**
  * @name setRowCount
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} rows
  * @returns {undefined}
  */
QStandardItem.prototype.setRowCount = function(rows){return undefined;};

/**
  * @name setSelectable
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} selectable
  * @returns {undefined}
  */
QStandardItem.prototype.setSelectable = function(selectable){return undefined;};

/**
  * @name setSizeHint
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QSize} sizeHint
  * @returns {undefined}
  */
QStandardItem.prototype.setSizeHint = function(sizeHint){return undefined;};

/**
  * @name setStatusTip
  * @function
  * @memberOf QStandardItem.prototype
  * @param {String} statusTip
  * @returns {undefined}
  */
QStandardItem.prototype.setStatusTip = function(statusTip){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QStandardItem.prototype
  * @param {String} text
  * @returns {undefined}
  */
QStandardItem.prototype.setText = function(text){return undefined;};

/**
  * @name setTextAlignment
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Qt.Alignment} textAlignment
  * @returns {undefined}
  */
QStandardItem.prototype.setTextAlignment = function(textAlignment){return undefined;};

/**
  * @name setToolTip
  * @function
  * @memberOf QStandardItem.prototype
  * @param {String} toolTip
  * @returns {undefined}
  */
QStandardItem.prototype.setToolTip = function(toolTip){return undefined;};

/**
  * @name setTristate
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Boolean} tristate
  * @returns {undefined}
  */
QStandardItem.prototype.setTristate = function(tristate){return undefined;};

/**
  * @name setWhatsThis
  * @function
  * @memberOf QStandardItem.prototype
  * @param {String} whatsThis
  * @returns {undefined}
  */
QStandardItem.prototype.setWhatsThis = function(whatsThis){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {QSize}
  */
QStandardItem.prototype.sizeHint = function(){return new QSize();};

/**
  * @name sortChildren
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QStandardItem.prototype.sortChildren = function(column, order){return undefined;};

/**
  * @name statusTip
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {String}
  */
QStandardItem.prototype.statusTip = function(){return new String();};

/**
  * @name takeChild
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @param {Numeric} column
  * @returns {QStandardItem}
  */
QStandardItem.prototype.takeChild = function(row, column){return new QStandardItem();};

/**
  * @name takeColumn
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} column
  * @returns {Array}
  */
QStandardItem.prototype.takeColumn = function(column){return new Array();};

/**
  * @name takeRow
  * @function
  * @memberOf QStandardItem.prototype
  * @param {Numeric} row
  * @returns {Array}
  */
QStandardItem.prototype.takeRow = function(row){return new Array();};

/**
  * @name text
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {String}
  */
QStandardItem.prototype.text = function(){return new String();};

/**
  * @name textAlignment
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Qt.Alignment}
  */
QStandardItem.prototype.textAlignment = function(){return new Qt.Alignment();};

/**
  * @name toolTip
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {String}
  */
QStandardItem.prototype.toolTip = function(){return new String();};

/**
  * @name type
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {Numeric}
  */
QStandardItem.prototype.type = function(){return new Numeric();};

/**
  * @name whatsThis
  * @function
  * @memberOf QStandardItem.prototype
  * @returns {String}
  */
QStandardItem.prototype.whatsThis = function(){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QStandardItem.prototype
  * @param {QDataStream} out
  * @returns {undefined}
  */
QStandardItem.prototype.writeTo = function(out){return undefined;};

