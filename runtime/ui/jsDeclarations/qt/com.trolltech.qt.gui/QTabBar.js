/**
  * @name QTabBar
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QTabBar(parent){return undefined;};

QTabBar.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QTabBar
  * @name SelectLeftTab
  * @see QTabBar#SelectionBehavior
  * @type Number
  */
QTabBar.SelectLeftTab = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabBar
  * @name SelectRightTab
  * @see QTabBar#SelectionBehavior
  * @type Number
  */
QTabBar.SelectRightTab = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTabBar
  * @name SelectPreviousTab
  * @see QTabBar#SelectionBehavior
  * @type Number
  */
QTabBar.SelectPreviousTab = 0x2;

/**
  * @constructor 
  * @memberOf QTabBar
  * @name SelectionBehavior
  */
QTabBar.SelectionBehavior = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTabBar
  * @name LeftSide
  * @see QTabBar#ButtonPosition
  * @type Number
  */
QTabBar.LeftSide = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabBar
  * @name RightSide
  * @see QTabBar#ButtonPosition
  * @type Number
  */
QTabBar.RightSide = 0x1;

/**
  * @constructor 
  * @memberOf QTabBar
  * @name ButtonPosition
  */
QTabBar.ButtonPosition = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTabBar
  * @name RoundedNorth
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.RoundedNorth = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabBar
  * @name RoundedSouth
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.RoundedSouth = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTabBar
  * @name RoundedWest
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.RoundedWest = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTabBar
  * @name RoundedEast
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.RoundedEast = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTabBar
  * @name TriangularNorth
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.TriangularNorth = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTabBar
  * @name TriangularSouth
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.TriangularSouth = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QTabBar
  * @name TriangularWest
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.TriangularWest = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QTabBar
  * @name TriangularEast
  * @see QTabBar#Shape
  * @type Number
  */
QTabBar.TriangularEast = 0x7;

/**
  * @constructor 
  * @memberOf QTabBar
  * @name Shape
  */
QTabBar.Shape = function(value){;};



/**
  * @name addTab
  * @function
  * @memberOf QTabBar.prototype
  * @param {QIcon} icon
  * @param {String} text
  * @returns {Numeric}
  */
QTabBar.prototype.addTab = function(icon, text){return new Numeric();};

/**
  * @name insertTab
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {QIcon} icon
  * @param {String} text
  * @returns {Numeric}
  */
QTabBar.prototype.insertTab = function(index, icon, text){return new Numeric();};

/**
  * @name isTabEnabled
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {Boolean}
  */
QTabBar.prototype.isTabEnabled = function(index){return new Boolean();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QTabBar.prototype
  * @returns {QSize}
  */
QTabBar.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name moveTab
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} from
  * @param {Numeric} to
  * @returns {undefined}
  */
QTabBar.prototype.moveTab = function(from, to){return undefined;};

/**
  * @name removeTab
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {undefined}
  */
QTabBar.prototype.removeTab = function(index){return undefined;};

/**
  * @name setTabButton
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {QTabBar.ButtonPosition} position
  * @param {QWidget} widget
  * @returns {undefined}
  */
QTabBar.prototype.setTabButton = function(index, position, widget){return undefined;};

/**
  * @name setTabData
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {Object} data
  * @returns {undefined}
  */
QTabBar.prototype.setTabData = function(index, data){return undefined;};

/**
  * @name setTabEnabled
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {Boolean} arg__2
  * @returns {undefined}
  */
QTabBar.prototype.setTabEnabled = function(index, arg__2){return undefined;};

/**
  * @name setTabIcon
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {QIcon} icon
  * @returns {undefined}
  */
QTabBar.prototype.setTabIcon = function(index, icon){return undefined;};

/**
  * @name setTabText
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {String} text
  * @returns {undefined}
  */
QTabBar.prototype.setTabText = function(index, text){return undefined;};

/**
  * @name setTabTextColor
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {QColor} color
  * @returns {undefined}
  */
QTabBar.prototype.setTabTextColor = function(index, color){return undefined;};

/**
  * @name setTabToolTip
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {String} tip
  * @returns {undefined}
  */
QTabBar.prototype.setTabToolTip = function(index, tip){return undefined;};

/**
  * @name setTabWhatsThis
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {String} text
  * @returns {undefined}
  */
QTabBar.prototype.setTabWhatsThis = function(index, text){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QTabBar.prototype
  * @returns {QSize}
  */
QTabBar.prototype.sizeHint = function(){return new QSize();};

/**
  * @name tabAt
  * @function
  * @memberOf QTabBar.prototype
  * @param {QPoint} pos
  * @returns {Numeric}
  */
QTabBar.prototype.tabAt = function(pos){return new Numeric();};

/**
  * @name tabButton
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @param {QTabBar.ButtonPosition} position
  * @returns {QWidget}
  */
QTabBar.prototype.tabButton = function(index, position){return new QWidget();};

/**
  * @name tabData
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {Object}
  */
QTabBar.prototype.tabData = function(index){return new Object();};

/**
  * @name tabIcon
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {QIcon}
  */
QTabBar.prototype.tabIcon = function(index){return new QIcon();};

/**
  * @name tabRect
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {QRect}
  */
QTabBar.prototype.tabRect = function(index){return new QRect();};

/**
  * @name tabText
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QTabBar.prototype.tabText = function(index){return new String();};

/**
  * @name tabTextColor
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {QColor}
  */
QTabBar.prototype.tabTextColor = function(index){return new QColor();};

/**
  * @name tabToolTip
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QTabBar.prototype.tabToolTip = function(index){return new String();};

/**
  * @name tabWhatsThis
  * @function
  * @memberOf QTabBar.prototype
  * @param {Numeric} index
  * @returns {String}
  */
QTabBar.prototype.tabWhatsThis = function(index){return new String();};

/**
  * @name shape
  * @memberOf QTabBar.prototype
  * @type QTabBar.Shape
  */
QTabBar.prototype.shape = new QTabBar.Shape();

/**
  * @name currentIndex
  * @memberOf QTabBar.prototype
  * @type Numeric
  */
QTabBar.prototype.currentIndex = new Numeric();

/**
  * @name count
  * @memberOf QTabBar.prototype
  * @type Numeric
  */
QTabBar.prototype.count = new Numeric();

/**
  * @name drawBase
  * @memberOf QTabBar.prototype
  * @type Boolean
  */
QTabBar.prototype.drawBase = new Boolean();

/**
  * @name iconSize
  * @memberOf QTabBar.prototype
  * @type QSize
  */
QTabBar.prototype.iconSize = new QSize();

/**
  * @name elideMode
  * @memberOf QTabBar.prototype
  * @type Qt.TextElideMode
  */
QTabBar.prototype.elideMode = new Qt.TextElideMode();

/**
  * @name usesScrollButtons
  * @memberOf QTabBar.prototype
  * @type Boolean
  */
QTabBar.prototype.usesScrollButtons = new Boolean();

/**
  * @name tabsClosable
  * @memberOf QTabBar.prototype
  * @type Boolean
  */
QTabBar.prototype.tabsClosable = new Boolean();

/**
  * @name selectionBehaviorOnRemove
  * @memberOf QTabBar.prototype
  * @type QAbstractItemView.SelectionBehavior
  */
QTabBar.prototype.selectionBehaviorOnRemove = new QAbstractItemView.SelectionBehavior();

/**
  * @name expanding
  * @memberOf QTabBar.prototype
  * @type Boolean
  */
QTabBar.prototype.expanding = new Boolean();

/**
  * @name movable
  * @memberOf QTabBar.prototype
  * @type Boolean
  */
QTabBar.prototype.movable = new Boolean();

/**
  * @name documentMode
  * @memberOf QTabBar.prototype
  * @type Boolean
  */
QTabBar.prototype.documentMode = new Boolean();


