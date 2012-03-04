/**
  * @name QTreeWidgetItem
  * @constructor
  * @param {QTreeWidget} view
  * @param {QTreeWidgetItem} after
  * @param {Numeric} type
  */
function QTreeWidgetItem(view, after, type){return undefined;};

/**
  * @name QTreeWidgetItem^1
  * @constructor
  * @param {QTreeWidget} view
  * @param {Array} strings
  * @param {Numeric} type
  */
function QTreeWidgetItem(view, strings, type){return undefined;};

/**
  * @name QTreeWidgetItem^2
  * @constructor
  * @param {QTreeWidget} view
  * @param {Numeric} type
  */
function QTreeWidgetItem(view, type){return undefined;};

/**
  * @name QTreeWidgetItem^3
  * @constructor
  * @param {QTreeWidgetItem} parent
  * @param {QTreeWidgetItem} after
  * @param {Numeric} type
  */
function QTreeWidgetItem(parent, after, type){return undefined;};

/**
  * @name QTreeWidgetItem^4
  * @constructor
  * @param {QTreeWidgetItem} parent
  * @param {Array} strings
  * @param {Numeric} type
  */
function QTreeWidgetItem(parent, strings, type){return undefined;};

/**
  * @name QTreeWidgetItem^5
  * @constructor
  * @param {QTreeWidgetItem} parent
  * @param {Numeric} type
  */
function QTreeWidgetItem(parent, type){return undefined;};

/**
  * @name QTreeWidgetItem^6
  * @constructor
  * @param {Array} strings
  * @param {Numeric} type
  */
function QTreeWidgetItem(strings, type){return undefined;};

/**
  * @name QTreeWidgetItem^7
  * @constructor
  * @param {Numeric} type
  */
function QTreeWidgetItem(type){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QTreeWidgetItem
  * @name Type
  * @see QTreeWidgetItem#ItemType
  * @type Number
  */
QTreeWidgetItem.Type = 0x0;

/**
  * @default 1000
  * @constant
  * @memberOf QTreeWidgetItem
  * @name UserType
  * @see QTreeWidgetItem#ItemType
  * @type Number
  */
QTreeWidgetItem.UserType = 0x3e8;

/**
  * @constructor 
  * @memberOf QTreeWidgetItem
  * @name ItemType
  */
QTreeWidgetItem.ItemType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTreeWidgetItem
  * @name ShowIndicator
  * @see QTreeWidgetItem#ChildIndicatorPolicy
  * @type Number
  */
QTreeWidgetItem.ShowIndicator = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTreeWidgetItem
  * @name DontShowIndicator
  * @see QTreeWidgetItem#ChildIndicatorPolicy
  * @type Number
  */
QTreeWidgetItem.DontShowIndicator = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTreeWidgetItem
  * @name DontShowIndicatorWhenChildless
  * @see QTreeWidgetItem#ChildIndicatorPolicy
  * @type Number
  */
QTreeWidgetItem.DontShowIndicatorWhenChildless = 0x2;

/**
  * @constructor 
  * @memberOf QTreeWidgetItem
  * @name ChildIndicatorPolicy
  */
QTreeWidgetItem.ChildIndicatorPolicy = function(value){;};



/**
  * @name addChild
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {QTreeWidgetItem} child
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.addChild = function(child){return undefined;};

/**
  * @name addChildren
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Array} children
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.addChildren = function(children){return undefined;};

/**
  * @name background
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {QBrush}
  */
QTreeWidgetItem.prototype.background = function(column){return new QBrush();};

/**
  * @name checkState
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {Qt.CheckState}
  */
QTreeWidgetItem.prototype.checkState = function(column){return new Qt.CheckState();};

/**
  * @name child
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} index
  * @returns {QTreeWidgetItem}
  */
QTreeWidgetItem.prototype.child = function(index){return new QTreeWidgetItem();};

/**
  * @name childCount
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Numeric}
  */
QTreeWidgetItem.prototype.childCount = function(){return new Numeric();};

/**
  * @name childIndicatorPolicy
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {QTreeWidgetItem.ChildIndicatorPolicy}
  */
QTreeWidgetItem.prototype.childIndicatorPolicy = function(){return new QTreeWidgetItem.ChildIndicatorPolicy();};

/**
  * @name clone
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {QTreeWidgetItem}
  */
QTreeWidgetItem.prototype.clone = function(){return new QTreeWidgetItem();};

/**
  * @name columnCount
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Numeric}
  */
QTreeWidgetItem.prototype.columnCount = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {Numeric} role
  * @returns {Object}
  */
QTreeWidgetItem.prototype.data = function(column, role){return new Object();};

/**
  * @name flags
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Qt.ItemFlags}
  */
QTreeWidgetItem.prototype.flags = function(){return new Qt.ItemFlags();};

/**
  * @name font
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {QFont}
  */
QTreeWidgetItem.prototype.font = function(column){return new QFont();};

/**
  * @name foreground
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {QBrush}
  */
QTreeWidgetItem.prototype.foreground = function(column){return new QBrush();};

/**
  * @name icon
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {QIcon}
  */
QTreeWidgetItem.prototype.icon = function(column){return new QIcon();};

/**
  * @name indexOfChild
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {QTreeWidgetItem} child
  * @returns {Numeric}
  */
QTreeWidgetItem.prototype.indexOfChild = function(child){return new Numeric();};

/**
  * @name insertChild
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} index
  * @param {QTreeWidgetItem} child
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.insertChild = function(index, child){return undefined;};

/**
  * @name insertChildren
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} index
  * @param {Array} children
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.insertChildren = function(index, children){return undefined;};

/**
  * @name isDisabled
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Boolean}
  */
QTreeWidgetItem.prototype.isDisabled = function(){return new Boolean();};

/**
  * @name isExpanded
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Boolean}
  */
QTreeWidgetItem.prototype.isExpanded = function(){return new Boolean();};

/**
  * @name isFirstColumnSpanned
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Boolean}
  */
QTreeWidgetItem.prototype.isFirstColumnSpanned = function(){return new Boolean();};

/**
  * @name isHidden
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Boolean}
  */
QTreeWidgetItem.prototype.isHidden = function(){return new Boolean();};

/**
  * @name isSelected
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Boolean}
  */
QTreeWidgetItem.prototype.isSelected = function(){return new Boolean();};

/**
  * @name parent
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {QTreeWidgetItem}
  */
QTreeWidgetItem.prototype.parent = function(){return new QTreeWidgetItem();};

/**
  * @name readFrom
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {QDataStream} _in
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.readFrom = function(_in){return undefined;};

/**
  * @name removeChild
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {QTreeWidgetItem} child
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.removeChild = function(child){return undefined;};

/**
  * @name setBackground
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {QBrush} brush
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setBackground = function(column, brush){return undefined;};

/**
  * @name setCheckState
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {Qt.CheckState} state
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setCheckState = function(column, state){return undefined;};

/**
  * @name setChildIndicatorPolicy
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {QTreeWidgetItem.ChildIndicatorPolicy} policy
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setChildIndicatorPolicy = function(policy){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {Numeric} role
  * @param {Object} value
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setData = function(column, role, value){return undefined;};

/**
  * @name setDisabled
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Boolean} disabled
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setDisabled = function(disabled){return undefined;};

/**
  * @name setExpanded
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Boolean} expand
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setExpanded = function(expand){return undefined;};

/**
  * @name setFirstColumnSpanned
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Boolean} span
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setFirstColumnSpanned = function(span){return undefined;};

/**
  * @name setFlags
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Qt.ItemFlags} flags
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setFlags = function(flags){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {QFont} font
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setFont = function(column, font){return undefined;};

/**
  * @name setForeground
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {QBrush} brush
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setForeground = function(column, brush){return undefined;};

/**
  * @name setHidden
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Boolean} hide
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setHidden = function(hide){return undefined;};

/**
  * @name setIcon
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {QIcon} icon
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setIcon = function(column, icon){return undefined;};

/**
  * @name setSelected
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Boolean} select
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setSelected = function(select){return undefined;};

/**
  * @name setSizeHint
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {QSize} size
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setSizeHint = function(column, size){return undefined;};

/**
  * @name setStatusTip
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {String} statusTip
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setStatusTip = function(column, statusTip){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {String} text
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setText = function(column, text){return undefined;};

/**
  * @name setTextAlignment
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {Numeric} alignment
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setTextAlignment = function(column, alignment){return undefined;};

/**
  * @name setToolTip
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {String} toolTip
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setToolTip = function(column, toolTip){return undefined;};

/**
  * @name setWhatsThis
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {String} whatsThis
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.setWhatsThis = function(column, whatsThis){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {QSize}
  */
QTreeWidgetItem.prototype.sizeHint = function(column){return new QSize();};

/**
  * @name sortChildren
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.sortChildren = function(column, order){return undefined;};

/**
  * @name statusTip
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {String}
  */
QTreeWidgetItem.prototype.statusTip = function(column){return new String();};

/**
  * @name takeChild
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} index
  * @returns {QTreeWidgetItem}
  */
QTreeWidgetItem.prototype.takeChild = function(index){return new QTreeWidgetItem();};

/**
  * @name takeChildren
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Array}
  */
QTreeWidgetItem.prototype.takeChildren = function(){return new Array();};

/**
  * @name text
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {String}
  */
QTreeWidgetItem.prototype.text = function(column){return new String();};

/**
  * @name textAlignment
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {Numeric}
  */
QTreeWidgetItem.prototype.textAlignment = function(column){return new Numeric();};

/**
  * @name toolTip
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {String}
  */
QTreeWidgetItem.prototype.toolTip = function(column){return new String();};

/**
  * @name treeWidget
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {QTreeWidget}
  */
QTreeWidgetItem.prototype.treeWidget = function(){return new QTreeWidget();};

/**
  * @name type
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @returns {Numeric}
  */
QTreeWidgetItem.prototype.type = function(){return new Numeric();};

/**
  * @name whatsThis
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {Numeric} column
  * @returns {String}
  */
QTreeWidgetItem.prototype.whatsThis = function(column){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QTreeWidgetItem.prototype
  * @param {QDataStream} out
  * @returns {undefined}
  */
QTreeWidgetItem.prototype.writeTo = function(out){return undefined;};

