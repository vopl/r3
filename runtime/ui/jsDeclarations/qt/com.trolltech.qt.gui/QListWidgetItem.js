/**
  * @name QListWidgetItem
  * @constructor
  * @param {QListWidget} view
  * @param {Numeric} type
  */
function QListWidgetItem(view, type){return undefined;};

/**
  * @name QListWidgetItem^1
  * @constructor
  * @param {QIcon} icon
  * @param {String} text
  * @param {QListWidget} view
  * @param {Numeric} type
  */
function QListWidgetItem(icon, text, view, type){return undefined;};

/**
  * @name QListWidgetItem^2
  * @constructor
  * @param {String} text
  * @param {QListWidget} view
  * @param {Numeric} type
  */
function QListWidgetItem(text, view, type){return undefined;};

/**
  * @default 0
  * @constant
  * @memberOf QListWidgetItem
  * @name Type
  * @see QListWidgetItem#ItemType
  * @type Number
  */
QListWidgetItem.Type = 0x0;

/**
  * @default 1000
  * @constant
  * @memberOf QListWidgetItem
  * @name UserType
  * @see QListWidgetItem#ItemType
  * @type Number
  */
QListWidgetItem.UserType = 0x3e8;

/**
  * @constructor 
  * @memberOf QListWidgetItem
  * @name ItemType
  */
QListWidgetItem.ItemType = function(value){;};



/**
  * @name background
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QBrush}
  */
QListWidgetItem.prototype.background = function(){return new QBrush();};

/**
  * @name checkState
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {Qt.CheckState}
  */
QListWidgetItem.prototype.checkState = function(){return new Qt.CheckState();};

/**
  * @name clone
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QListWidgetItem}
  */
QListWidgetItem.prototype.clone = function(){return new QListWidgetItem();};

/**
  * @name data
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Numeric} role
  * @returns {Object}
  */
QListWidgetItem.prototype.data = function(role){return new Object();};

/**
  * @name flags
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {Qt.ItemFlags}
  */
QListWidgetItem.prototype.flags = function(){return new Qt.ItemFlags();};

/**
  * @name font
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QFont}
  */
QListWidgetItem.prototype.font = function(){return new QFont();};

/**
  * @name foreground
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QBrush}
  */
QListWidgetItem.prototype.foreground = function(){return new QBrush();};

/**
  * @name icon
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QIcon}
  */
QListWidgetItem.prototype.icon = function(){return new QIcon();};

/**
  * @name isHidden
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {Boolean}
  */
QListWidgetItem.prototype.isHidden = function(){return new Boolean();};

/**
  * @name isSelected
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {Boolean}
  */
QListWidgetItem.prototype.isSelected = function(){return new Boolean();};

/**
  * @name listWidget
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QListWidget}
  */
QListWidgetItem.prototype.listWidget = function(){return new QListWidget();};

/**
  * @name readFrom
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QDataStream} _in
  * @returns {undefined}
  */
QListWidgetItem.prototype.readFrom = function(_in){return undefined;};

/**
  * @name setBackground
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QListWidgetItem.prototype.setBackground = function(brush){return undefined;};

/**
  * @name setCheckState
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Qt.CheckState} state
  * @returns {undefined}
  */
QListWidgetItem.prototype.setCheckState = function(state){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Numeric} role
  * @param {Object} value
  * @returns {undefined}
  */
QListWidgetItem.prototype.setData = function(role, value){return undefined;};

/**
  * @name setFlags
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Qt.ItemFlags} flags
  * @returns {undefined}
  */
QListWidgetItem.prototype.setFlags = function(flags){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QFont} font
  * @returns {undefined}
  */
QListWidgetItem.prototype.setFont = function(font){return undefined;};

/**
  * @name setForeground
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QListWidgetItem.prototype.setForeground = function(brush){return undefined;};

/**
  * @name setHidden
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Boolean} hide
  * @returns {undefined}
  */
QListWidgetItem.prototype.setHidden = function(hide){return undefined;};

/**
  * @name setIcon
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QIcon} icon
  * @returns {undefined}
  */
QListWidgetItem.prototype.setIcon = function(icon){return undefined;};

/**
  * @name setSelected
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Boolean} select
  * @returns {undefined}
  */
QListWidgetItem.prototype.setSelected = function(select){return undefined;};

/**
  * @name setSizeHint
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QSize} size
  * @returns {undefined}
  */
QListWidgetItem.prototype.setSizeHint = function(size){return undefined;};

/**
  * @name setStatusTip
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {String} statusTip
  * @returns {undefined}
  */
QListWidgetItem.prototype.setStatusTip = function(statusTip){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {String} text
  * @returns {undefined}
  */
QListWidgetItem.prototype.setText = function(text){return undefined;};

/**
  * @name setTextAlignment
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {Numeric} alignment
  * @returns {undefined}
  */
QListWidgetItem.prototype.setTextAlignment = function(alignment){return undefined;};

/**
  * @name setToolTip
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {String} toolTip
  * @returns {undefined}
  */
QListWidgetItem.prototype.setToolTip = function(toolTip){return undefined;};

/**
  * @name setWhatsThis
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {String} whatsThis
  * @returns {undefined}
  */
QListWidgetItem.prototype.setWhatsThis = function(whatsThis){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {QSize}
  */
QListWidgetItem.prototype.sizeHint = function(){return new QSize();};

/**
  * @name statusTip
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {String}
  */
QListWidgetItem.prototype.statusTip = function(){return new String();};

/**
  * @name text
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {String}
  */
QListWidgetItem.prototype.text = function(){return new String();};

/**
  * @name textAlignment
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {Numeric}
  */
QListWidgetItem.prototype.textAlignment = function(){return new Numeric();};

/**
  * @name toolTip
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {String}
  */
QListWidgetItem.prototype.toolTip = function(){return new String();};

/**
  * @name type
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {Numeric}
  */
QListWidgetItem.prototype.type = function(){return new Numeric();};

/**
  * @name whatsThis
  * @function
  * @memberOf QListWidgetItem.prototype
  * @returns {String}
  */
QListWidgetItem.prototype.whatsThis = function(){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QListWidgetItem.prototype
  * @param {QDataStream} out
  * @returns {undefined}
  */
QListWidgetItem.prototype.writeTo = function(out){return undefined;};

