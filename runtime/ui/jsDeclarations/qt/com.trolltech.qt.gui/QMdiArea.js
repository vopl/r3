/**
  * @name QMdiArea
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QWidget} parent
  */
function QMdiArea(parent){return undefined;};

QMdiArea.prototype = new QAbstractScrollArea();

/**
  * @default 0x0
  * @constant
  * @memberOf QMdiArea
  * @name CreationOrder
  * @see QMdiArea#WindowOrder
  * @type Number
  */
QMdiArea.CreationOrder = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QMdiArea
  * @name StackingOrder
  * @see QMdiArea#WindowOrder
  * @type Number
  */
QMdiArea.StackingOrder = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QMdiArea
  * @name ActivationHistoryOrder
  * @see QMdiArea#WindowOrder
  * @type Number
  */
QMdiArea.ActivationHistoryOrder = 0x2;

/**
  * @constructor 
  * @memberOf QMdiArea
  * @name WindowOrder
  */
QMdiArea.WindowOrder = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QMdiArea
  * @name SubWindowView
  * @see QMdiArea#ViewMode
  * @type Number
  */
QMdiArea.SubWindowView = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QMdiArea
  * @name TabbedView
  * @see QMdiArea#ViewMode
  * @type Number
  */
QMdiArea.TabbedView = 0x1;

/**
  * @constructor 
  * @memberOf QMdiArea
  * @name ViewMode
  */
QMdiArea.ViewMode = function(value){;};



/**
  * @default 0x1
  * @constant
  * @memberOf QMdiArea
  * @name DontMaximizeSubWindowOnActivation
  * @see QMdiArea#AreaOptions
  * @see QMdiArea#AreaOption
  * @type Number
  */
QMdiArea.DontMaximizeSubWindowOnActivation = 0x1;

/**
  * @constructor 
  * @memberOf QMdiArea
  * @name AreaOption
  */
QMdiArea.AreaOption = function(value){;};

/**
  * @constructor 
  * @memberOf QMdiArea
  * @name AreaOptions
  */
QMdiArea.AreaOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name activeSubWindow
  * @function
  * @memberOf QMdiArea.prototype
  * @returns {QMdiSubWindow}
  */
QMdiArea.prototype.activeSubWindow = function(){return new QMdiSubWindow();};

/**
  * @name addSubWindow
  * @function
  * @memberOf QMdiArea.prototype
  * @param {QWidget} widget
  * @param {Qt.WindowFlags} flags
  * @returns {QMdiSubWindow}
  */
QMdiArea.prototype.addSubWindow = function(widget, flags){return new QMdiSubWindow();};

/**
  * @name currentSubWindow
  * @function
  * @memberOf QMdiArea.prototype
  * @returns {QMdiSubWindow}
  */
QMdiArea.prototype.currentSubWindow = function(){return new QMdiSubWindow();};

/**
  * @name removeSubWindow
  * @function
  * @memberOf QMdiArea.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QMdiArea.prototype.removeSubWindow = function(widget){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QMdiArea.prototype
  * @param {QMdiArea.AreaOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QMdiArea.prototype.setOption = function(option, on){return undefined;};

/**
  * @name subWindowList
  * @function
  * @memberOf QMdiArea.prototype
  * @param {QMdiArea.WindowOrder} order
  * @returns {Array}
  */
QMdiArea.prototype.subWindowList = function(order){return new Array();};

/**
  * @name testOption
  * @function
  * @memberOf QMdiArea.prototype
  * @param {QMdiArea.AreaOption} opton
  * @returns {Boolean}
  */
QMdiArea.prototype.testOption = function(opton){return new Boolean();};

/**
  * @name background
  * @memberOf QMdiArea.prototype
  * @type QBrush
  */
QMdiArea.prototype.background = new QBrush();

/**
  * @name activationOrder
  * @memberOf QMdiArea.prototype
  * @type QMdiArea.WindowOrder
  */
QMdiArea.prototype.activationOrder = new QMdiArea.WindowOrder();

/**
  * @name viewMode
  * @memberOf QMdiArea.prototype
  * @type QListView.ViewMode
  */
QMdiArea.prototype.viewMode = new QListView.ViewMode();

/**
  * @name documentMode
  * @memberOf QMdiArea.prototype
  * @type Boolean
  */
QMdiArea.prototype.documentMode = new Boolean();

/**
  * @name tabsClosable
  * @memberOf QMdiArea.prototype
  * @type Boolean
  */
QMdiArea.prototype.tabsClosable = new Boolean();

/**
  * @name tabsMovable
  * @memberOf QMdiArea.prototype
  * @type Boolean
  */
QMdiArea.prototype.tabsMovable = new Boolean();

/**
  * @name tabShape
  * @memberOf QMdiArea.prototype
  * @type QTabWidget.TabShape
  */
QMdiArea.prototype.tabShape = new QTabWidget.TabShape();

/**
  * @name tabPosition
  * @memberOf QMdiArea.prototype
  * @type QStyleOptionToolBoxV2.TabPosition
  */
QMdiArea.prototype.tabPosition = new QStyleOptionToolBoxV2.TabPosition();


