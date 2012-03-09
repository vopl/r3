/**
  * @name QTabWidget
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QTabWidget(parent){return undefined;};

QTabWidget.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QTabWidget
  * @name Rounded
  * @see QTabWidget#TabShape
  * @type Number
  */
QTabWidget.Rounded = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabWidget
  * @name Triangular
  * @see QTabWidget#TabShape
  * @type Number
  */
QTabWidget.Triangular = 0x1;

/**
  * @constructor 
  * @memberOf QTabWidget
  * @name TabShape
  */
QTabWidget.TabShape = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTabWidget
  * @name North
  * @see QTabWidget#TabPosition
  * @type Number
  */
QTabWidget.North = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabWidget
  * @name South
  * @see QTabWidget#TabPosition
  * @type Number
  */
QTabWidget.South = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTabWidget
  * @name West
  * @see QTabWidget#TabPosition
  * @type Number
  */
QTabWidget.West = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTabWidget
  * @name East
  * @see QTabWidget#TabPosition
  * @type Number
  */
QTabWidget.East = 0x3;

/**
  * @constructor 
  * @memberOf QTabWidget
  * @name TabPosition
  */
QTabWidget.TabPosition = function(value){;};



/**
  * @name addTab
  * @function
  * @memberOf QTabWidget.prototype
  * @param {QWidget} widget
  * @param {QIcon} icon
  * @param {String} label
  * @returns {Numeric}
  */
QTabWidget.prototype.addTab = function(widget, icon, label){return new Numeric();};

/**
  * @name clear
  * @function
  * @memberOf QTabWidget.prototype
  * @returns {undefined}
  */
QTabWidget.prototype.clear = function(){return undefined;};

/**
  * @name cornerWidget
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Qt.Corner} corner
  * @returns {QWidget}
  */
QTabWidget.prototype.cornerWidget = function(corner){return new QWidget();};

/**
  * @name currentWidget
  * @function
  * @memberOf QTabWidget.prototype
  * @returns {QWidget}
  */
QTabWidget.prototype.currentWidget = function(){return new QWidget();};

/**
  * @name indexOf
  * @function
  * @memberOf QTabWidget.prototype
  * @param {QWidget} widget
  * @returns {Numeric}
  */
QTabWidget.prototype.indexOf = function(widget){return new Numeric();};

/**
  * @name insertTab
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @param {QWidget} widget
  * @param {QIcon} icon
  * @param {String} label
  * @returns {Numeric}
  */
QTabWidget.prototype.insertTab = function(index, widget, icon, label){return new Numeric();};

/**
  * @name isTabEnabled
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {Boolean}
  */
QTabWidget.prototype.isTabEnabled = function(index){return new Boolean();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QTabWidget.prototype
  * @returns {QSize}
  */
QTabWidget.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name removeTab
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {undefined}
  */
QTabWidget.prototype.removeTab = function(index){return undefined;};

/**
  * @name setCornerWidget
  * @function
  * @memberOf QTabWidget.prototype
  * @param {QWidget} w
  * @param {Qt.Corner} corner
  * @returns {undefined}
  */
QTabWidget.prototype.setCornerWidget = function(w, corner){return undefined;};

/**
  * @name setTabEnabled
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @param {Boolean} arg__2
  * @returns {undefined}
  */
QTabWidget.prototype.setTabEnabled = function(index, arg__2){return undefined;};

/**
  * @name setTabIcon
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @param {QIcon} icon
  * @returns {undefined}
  */
QTabWidget.prototype.setTabIcon = function(index, icon){return undefined;};

/**
  * @name setTabText
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @param {String} arg__2
  * @returns {undefined}
  */
QTabWidget.prototype.setTabText = function(index, arg__2){return undefined;};

/**
  * @name setTabToolTip
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @param {String} tip
  * @returns {undefined}
  */
QTabWidget.prototype.setTabToolTip = function(index, tip){return undefined;};

/**
  * @name setTabWhatsThis
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @param {String} text
  * @returns {undefined}
  */
QTabWidget.prototype.setTabWhatsThis = function(index, text){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QTabWidget.prototype
  * @returns {QSize}
  */
QTabWidget.prototype.sizeHint = function(){return new QSize();};

/**
  * @name tabIcon
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {QIcon}
  */
QTabWidget.prototype.tabIcon = function(index){return new QIcon();};

/**
  * @name tabText
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QTabWidget.prototype.tabText = function(index){return new String();};

/**
  * @name tabToolTip
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QTabWidget.prototype.tabToolTip = function(index){return new String();};

/**
  * @name tabWhatsThis
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QTabWidget.prototype.tabWhatsThis = function(index){return new String();};

/**
  * @name widget
  * @function
  * @memberOf QTabWidget.prototype
  * @param {Numeric} index
  * @returns {QWidget}
  */
QTabWidget.prototype.widget = function(index){return new QWidget();};

/**
  * @name tabPosition
  * @memberOf QTabWidget.prototype
  * @type QStyleOptionToolBoxV2.TabPosition
  */
QTabWidget.prototype.tabPosition = new QStyleOptionToolBoxV2.TabPosition();

/**
  * @name tabShape
  * @memberOf QTabWidget.prototype
  * @type QTabWidget.TabShape
  */
QTabWidget.prototype.tabShape = new QTabWidget.TabShape();

/**
  * @name currentIndex
  * @memberOf QTabWidget.prototype
  * @type Numeric
  */
QTabWidget.prototype.currentIndex = new Numeric();

/**
  * @name count
  * @memberOf QTabWidget.prototype
  * @type Numeric
  */
QTabWidget.prototype.count = new Numeric();

/**
  * @name iconSize
  * @memberOf QTabWidget.prototype
  * @type QSize
  */
QTabWidget.prototype.iconSize = new QSize();

/**
  * @name elideMode
  * @memberOf QTabWidget.prototype
  * @type Qt.TextElideMode
  */
QTabWidget.prototype.elideMode = new Qt.TextElideMode();

/**
  * @name usesScrollButtons
  * @memberOf QTabWidget.prototype
  * @type Boolean
  */
QTabWidget.prototype.usesScrollButtons = new Boolean();

/**
  * @name documentMode
  * @memberOf QTabWidget.prototype
  * @type Boolean
  */
QTabWidget.prototype.documentMode = new Boolean();

/**
  * @name tabsClosable
  * @memberOf QTabWidget.prototype
  * @type Boolean
  */
QTabWidget.prototype.tabsClosable = new Boolean();

/**
  * @name movable
  * @memberOf QTabWidget.prototype
  * @type Boolean
  */
QTabWidget.prototype.movable = new Boolean();


