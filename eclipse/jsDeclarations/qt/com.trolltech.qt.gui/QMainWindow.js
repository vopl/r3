/**
  * @name QMainWindow
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QMainWindow(parent, flags){return undefined;};

QMainWindow.prototype = new QWidget();

/**
  * @default 0x01
  * @constant
  * @memberOf QMainWindow
  * @name AnimatedDocks
  * @see QMainWindow#DockOptions
  * @see QMainWindow#DockOption
  * @type Number
  */
QMainWindow.AnimatedDocks = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QMainWindow
  * @name AllowNestedDocks
  * @see QMainWindow#DockOptions
  * @see QMainWindow#DockOption
  * @type Number
  */
QMainWindow.AllowNestedDocks = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QMainWindow
  * @name AllowTabbedDocks
  * @see QMainWindow#DockOptions
  * @see QMainWindow#DockOption
  * @type Number
  */
QMainWindow.AllowTabbedDocks = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QMainWindow
  * @name ForceTabbedDocks
  * @see QMainWindow#DockOptions
  * @see QMainWindow#DockOption
  * @type Number
  */
QMainWindow.ForceTabbedDocks = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QMainWindow
  * @name VerticalTabs
  * @see QMainWindow#DockOptions
  * @see QMainWindow#DockOption
  * @type Number
  */
QMainWindow.VerticalTabs = 0x10;

/**
  * @constructor 
  * @memberOf QMainWindow
  * @name DockOption
  */
QMainWindow.DockOption = function(value){;};

/**
  * @constructor 
  * @memberOf QMainWindow
  * @name DockOptions
  */
QMainWindow.DockOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name addDockWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Qt.DockWidgetArea} area
  * @param {QDockWidget} dockwidget
  * @returns {undefined}
  */
QMainWindow.prototype.addDockWidget = function(area, dockwidget){return undefined;};

/**
  * @name addToolBar
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} toolbar
  * @returns {undefined}
  */
QMainWindow.prototype.addToolBar = function(toolbar){return undefined;};

/**
  * @name addToolBarBreak
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Qt.ToolBarArea} area
  * @returns {undefined}
  */
QMainWindow.prototype.addToolBarBreak = function(area){return undefined;};

/**
  * @name centralWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @returns {QWidget}
  */
QMainWindow.prototype.centralWidget = function(){return new QWidget();};

/**
  * @name corner
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Qt.Corner} corner
  * @returns {Qt.DockWidgetArea}
  */
QMainWindow.prototype.corner = function(corner){return new Qt.DockWidgetArea();};

/**
  * @name createPopupMenu
  * @function
  * @memberOf QMainWindow.prototype
  * @returns {QMenu}
  */
QMainWindow.prototype.createPopupMenu = function(){return new QMenu();};

/**
  * @name dockWidgetArea
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QDockWidget} dockwidget
  * @returns {Qt.DockWidgetArea}
  */
QMainWindow.prototype.dockWidgetArea = function(dockwidget){return new Qt.DockWidgetArea();};

/**
  * @name insertToolBar
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} before
  * @param {QToolBar} toolbar
  * @returns {undefined}
  */
QMainWindow.prototype.insertToolBar = function(before, toolbar){return undefined;};

/**
  * @name insertToolBarBreak
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} before
  * @returns {undefined}
  */
QMainWindow.prototype.insertToolBarBreak = function(before){return undefined;};

/**
  * @name isSeparator
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QPoint} pos
  * @returns {Boolean}
  */
QMainWindow.prototype.isSeparator = function(pos){return new Boolean();};

/**
  * @name menuBar
  * @function
  * @memberOf QMainWindow.prototype
  * @returns {QMenuBar}
  */
QMainWindow.prototype.menuBar = function(){return new QMenuBar();};

/**
  * @name menuWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @returns {QWidget}
  */
QMainWindow.prototype.menuWidget = function(){return new QWidget();};

/**
  * @name removeDockWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QDockWidget} dockwidget
  * @returns {undefined}
  */
QMainWindow.prototype.removeDockWidget = function(dockwidget){return undefined;};

/**
  * @name removeToolBar
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} toolbar
  * @returns {undefined}
  */
QMainWindow.prototype.removeToolBar = function(toolbar){return undefined;};

/**
  * @name removeToolBarBreak
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} before
  * @returns {undefined}
  */
QMainWindow.prototype.removeToolBarBreak = function(before){return undefined;};

/**
  * @name restoreDockWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QDockWidget} dockwidget
  * @returns {Boolean}
  */
QMainWindow.prototype.restoreDockWidget = function(dockwidget){return new Boolean();};

/**
  * @name restoreState
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QByteArray} state
  * @param {Numeric} version
  * @returns {Boolean}
  */
QMainWindow.prototype.restoreState = function(state, version){return new Boolean();};

/**
  * @name saveState
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Numeric} version
  * @returns {QByteArray}
  */
QMainWindow.prototype.saveState = function(version){return new QByteArray();};

/**
  * @name setCentralWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QMainWindow.prototype.setCentralWidget = function(widget){return undefined;};

/**
  * @name setCorner
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Qt.Corner} corner
  * @param {Qt.DockWidgetArea} area
  * @returns {undefined}
  */
QMainWindow.prototype.setCorner = function(corner, area){return undefined;};

/**
  * @name setMenuBar
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QMenuBar} menubar
  * @returns {undefined}
  */
QMainWindow.prototype.setMenuBar = function(menubar){return undefined;};

/**
  * @name setMenuWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QWidget} menubar
  * @returns {undefined}
  */
QMainWindow.prototype.setMenuWidget = function(menubar){return undefined;};

/**
  * @name setStatusBar
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QStatusBar} statusbar
  * @returns {undefined}
  */
QMainWindow.prototype.setStatusBar = function(statusbar){return undefined;};

/**
  * @name setTabPosition
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Qt.DockWidgetAreas} areas
  * @param {QStyleOptionToolBoxV2.TabPosition} tabPosition
  * @returns {undefined}
  */
QMainWindow.prototype.setTabPosition = function(areas, tabPosition){return undefined;};

/**
  * @name splitDockWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QDockWidget} after
  * @param {QDockWidget} dockwidget
  * @param {QPrinter.Orientation} orientation
  * @returns {undefined}
  */
QMainWindow.prototype.splitDockWidget = function(after, dockwidget, orientation){return undefined;};

/**
  * @name statusBar
  * @function
  * @memberOf QMainWindow.prototype
  * @returns {QStatusBar}
  */
QMainWindow.prototype.statusBar = function(){return new QStatusBar();};

/**
  * @name tabPosition
  * @function
  * @memberOf QMainWindow.prototype
  * @param {Qt.DockWidgetArea} area
  * @returns {QStyleOptionToolBoxV2.TabPosition}
  */
QMainWindow.prototype.tabPosition = function(area){return new QStyleOptionToolBoxV2.TabPosition();};

/**
  * @name tabifiedDockWidgets
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QDockWidget} dockwidget
  * @returns {Array}
  */
QMainWindow.prototype.tabifiedDockWidgets = function(dockwidget){return new Array();};

/**
  * @name tabifyDockWidget
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QDockWidget} first
  * @param {QDockWidget} second
  * @returns {undefined}
  */
QMainWindow.prototype.tabifyDockWidget = function(first, second){return undefined;};

/**
  * @name toolBarArea
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} toolbar
  * @returns {Qt.ToolBarArea}
  */
QMainWindow.prototype.toolBarArea = function(toolbar){return new Qt.ToolBarArea();};

/**
  * @name toolBarBreak
  * @function
  * @memberOf QMainWindow.prototype
  * @param {QToolBar} toolbar
  * @returns {Boolean}
  */
QMainWindow.prototype.toolBarBreak = function(toolbar){return new Boolean();};

/**
  * @name iconSize
  * @memberOf QMainWindow.prototype
  * @type QSize
  */
QMainWindow.prototype.iconSize = new QSize();

/**
  * @name toolButtonStyle
  * @memberOf QMainWindow.prototype
  * @type Qt.ToolButtonStyle
  */
QMainWindow.prototype.toolButtonStyle = new Qt.ToolButtonStyle();

/**
  * @name animated
  * @memberOf QMainWindow.prototype
  * @type Boolean
  */
QMainWindow.prototype.animated = new Boolean();

/**
  * @name documentMode
  * @memberOf QMainWindow.prototype
  * @type Boolean
  */
QMainWindow.prototype.documentMode = new Boolean();

/**
  * @name tabShape
  * @memberOf QMainWindow.prototype
  * @type QTabWidget.TabShape
  */
QMainWindow.prototype.tabShape = new QTabWidget.TabShape();

/**
  * @name dockNestingEnabled
  * @memberOf QMainWindow.prototype
  * @type Boolean
  */
QMainWindow.prototype.dockNestingEnabled = new Boolean();

/**
  * @name dockOptions
  * @memberOf QMainWindow.prototype
  * @type QMainWindow.DockOptions
  */
QMainWindow.prototype.dockOptions = new QMainWindow.DockOptions();

/**
  * @name unifiedTitleAndToolBarOnMac
  * @memberOf QMainWindow.prototype
  * @type Boolean
  */
QMainWindow.prototype.unifiedTitleAndToolBarOnMac = new Boolean();


