/**
  * @name QTableWidgetItem
  * @constructor
  * @param {QIcon} icon
  * @param {String} text
  * @param {Numeric} type
  */
function QTableWidgetItem(icon, text, type){return undefined;};

/**
  * @name QTableWidgetItem^1
  * @constructor
  * @param {String} text
  * @param {Numeric} type
  */
function QTableWidgetItem(text, type){return undefined;};

/**
  * @name QTableWidgetItem^2
  * @constructor
  * @param {Numeric} type
  */
function QTableWidgetItem(type){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QTableWidgetItem
  * @name Type
  * @see QTableWidgetItem#ItemType
  * @type Number
  */
QTableWidgetItem.Type = 0x0;

/**
  * @default 1000
  * @constant
  * @memberOf QTableWidgetItem
  * @name UserType
  * @see QTableWidgetItem#ItemType
  * @type Number
  */
QTableWidgetItem.UserType = 0x3e8;

/**
  * @constructor 
  * @memberOf QTableWidgetItem
  * @name ItemType
  */
QTableWidgetItem.ItemType = function(value){;};



/**
  * @name background
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QBrush}
  */
QTableWidgetItem.prototype.background = function(){return new QBrush();};

/**
  * @name checkState
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Qt.CheckState}
  */
QTableWidgetItem.prototype.checkState = function(){return new Qt.CheckState();};

/**
  * @name clone
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QTableWidgetItem}
  */
QTableWidgetItem.prototype.clone = function(){return new QTableWidgetItem();};

/**
  * @name column
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Numeric}
  */
QTableWidgetItem.prototype.column = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {Numeric} role
  * @returns {Object}
  */
QTableWidgetItem.prototype.data = function(role){return new Object();};

/**
  * @name flags
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Qt.ItemFlags}
  */
QTableWidgetItem.prototype.flags = function(){return new Qt.ItemFlags();};

/**
  * @name font
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QFont}
  */
QTableWidgetItem.prototype.font = function(){return new QFont();};

/**
  * @name foreground
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QBrush}
  */
QTableWidgetItem.prototype.foreground = function(){return new QBrush();};

/**
  * @name icon
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QIcon}
  */
QTableWidgetItem.prototype.icon = function(){return new QIcon();};

/**
  * @name isSelected
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Boolean}
  */
QTableWidgetItem.prototype.isSelected = function(){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QDataStream} _in
  * @returns {undefined}
  */
QTableWidgetItem.prototype.readFrom = function(_in){return undefined;};

/**
  * @name row
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Numeric}
  */
QTableWidgetItem.prototype.row = function(){return new Numeric();};

/**
  * @name setBackground
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setBackground = function(brush){return undefined;};

/**
  * @name setCheckState
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {Qt.CheckState} state
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setCheckState = function(state){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {Numeric} role
  * @param {Object} value
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setData = function(role, value){return undefined;};

/**
  * @name setFlags
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {Qt.ItemFlags} flags
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setFlags = function(flags){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QFont} font
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setFont = function(font){return undefined;};

/**
  * @name setForeground
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setForeground = function(brush){return undefined;};

/**
  * @name setIcon
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QIcon} icon
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setIcon = function(icon){return undefined;};

/**
  * @name setSelected
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {Boolean} select
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setSelected = function(select){return undefined;};

/**
  * @name setSizeHint
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QSize} size
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setSizeHint = function(size){return undefined;};

/**
  * @name setStatusTip
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {String} statusTip
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setStatusTip = function(statusTip){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {String} text
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setText = function(text){return undefined;};

/**
  * @name setTextAlignment
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {Numeric} alignment
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setTextAlignment = function(alignment){return undefined;};

/**
  * @name setToolTip
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {String} toolTip
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setToolTip = function(toolTip){return undefined;};

/**
  * @name setWhatsThis
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {String} whatsThis
  * @returns {undefined}
  */
QTableWidgetItem.prototype.setWhatsThis = function(whatsThis){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QSize}
  */
QTableWidgetItem.prototype.sizeHint = function(){return new QSize();};

/**
  * @name statusTip
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {String}
  */
QTableWidgetItem.prototype.statusTip = function(){return new String();};

/**
  * @name tableWidget
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {QTableWidget}
  */
QTableWidgetItem.prototype.tableWidget = function(){return new QTableWidget();};

/**
  * @name text
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {String}
  */
QTableWidgetItem.prototype.text = function(){return new String();};

/**
  * @name textAlignment
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Numeric}
  */
QTableWidgetItem.prototype.textAlignment = function(){return new Numeric();};

/**
  * @name toolTip
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {String}
  */
QTableWidgetItem.prototype.toolTip = function(){return new String();};

/**
  * @name type
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {Numeric}
  */
QTableWidgetItem.prototype.type = function(){return new Numeric();};

/**
  * @name whatsThis
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @returns {String}
  */
QTableWidgetItem.prototype.whatsThis = function(){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QTableWidgetItem.prototype
  * @param {QDataStream} out
  * @returns {undefined}
  */
QTableWidgetItem.prototype.writeTo = function(out){return undefined;};

