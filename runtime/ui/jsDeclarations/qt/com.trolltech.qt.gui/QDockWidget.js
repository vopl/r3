/**
  * @name QDockWidget
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QDockWidget(parent, flags){return undefined;};

/**
  * @name QDockWidget^1
  * @constructor
  * @extends QWidget
  * @param {String} title
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QDockWidget(title, parent, flags){return undefined;};

QDockWidget.prototype = new QWidget();

/**
  * @default 0x00
  * @constant
  * @memberOf QDockWidget
  * @name NoDockWidgetFeatures
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.NoDockWidgetFeatures = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QDockWidget
  * @name DockWidgetClosable
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.DockWidgetClosable = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QDockWidget
  * @name DockWidgetMovable
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.DockWidgetMovable = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QDockWidget
  * @name DockWidgetFloatable
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.DockWidgetFloatable = 0x4;

/**
  * @default DockWidgetClosable|DockWidgetMovable|DockWidgetFloatable
  * @constant
  * @memberOf QDockWidget
  * @name AllDockWidgetFeatures
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.AllDockWidgetFeatures = 0x7;

/**
  * @default 0x08
  * @constant
  * @memberOf QDockWidget
  * @name DockWidgetVerticalTitleBar
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.DockWidgetVerticalTitleBar = 0x8;

/**
  * @default 0x0f
  * @constant
  * @memberOf QDockWidget
  * @name DockWidgetFeatureMask
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.DockWidgetFeatureMask = 0xf;

/**
  * @default 0xff
  * @constant
  * @memberOf QDockWidget
  * @name Reserved
  * @see QDockWidget#DockWidgetFeatures
  * @see QDockWidget#DockWidgetFeature
  * @type Number
  */
QDockWidget.Reserved = 0xff;

/**
  * @constructor 
  * @memberOf QDockWidget
  * @name DockWidgetFeature
  */
QDockWidget.DockWidgetFeature = function(value){;};

/**
  * @constructor 
  * @memberOf QDockWidget
  * @name DockWidgetFeatures
  */
QDockWidget.DockWidgetFeatures = function(value1, value2 /*, ...*/){;};


/**
  * @name allowedAreas
  * @function
  * @memberOf QDockWidget.prototype
  * @returns {Qt.DockWidgetAreas}
  */
QDockWidget.prototype.allowedAreas = function(){return new Qt.DockWidgetAreas();};

/**
  * @name isAreaAllowed
  * @function
  * @memberOf QDockWidget.prototype
  * @param {Qt.DockWidgetArea} area
  * @returns {Boolean}
  */
QDockWidget.prototype.isAreaAllowed = function(area){return new Boolean();};

/**
  * @name setAllowedAreas
  * @function
  * @memberOf QDockWidget.prototype
  * @param {Qt.DockWidgetAreas} areas
  * @returns {undefined}
  */
QDockWidget.prototype.setAllowedAreas = function(areas){return undefined;};

/**
  * @name setTitleBarWidget
  * @function
  * @memberOf QDockWidget.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QDockWidget.prototype.setTitleBarWidget = function(widget){return undefined;};

/**
  * @name setWidget
  * @function
  * @memberOf QDockWidget.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QDockWidget.prototype.setWidget = function(widget){return undefined;};

/**
  * @name titleBarWidget
  * @function
  * @memberOf QDockWidget.prototype
  * @returns {QWidget}
  */
QDockWidget.prototype.titleBarWidget = function(){return new QWidget();};

/**
  * @name toggleViewAction
  * @function
  * @memberOf QDockWidget.prototype
  * @returns {QAction}
  */
QDockWidget.prototype.toggleViewAction = function(){return new QAction();};

/**
  * @name widget
  * @function
  * @memberOf QDockWidget.prototype
  * @returns {QWidget}
  */
QDockWidget.prototype.widget = function(){return new QWidget();};

/**
  * @name floating
  * @memberOf QDockWidget.prototype
  * @type Boolean
  */
QDockWidget.prototype.floating = new Boolean();

/**
  * @name features
  * @memberOf QDockWidget.prototype
  * @type QDockWidget.DockWidgetFeatures
  */
QDockWidget.prototype.features = new QDockWidget.DockWidgetFeatures();

/**
  * @name allowedAreas
  * @memberOf QDockWidget.prototype
  * @type Qt.DockWidgetAreas
  */
QDockWidget.prototype.allowedAreas = new Qt.DockWidgetAreas();

/**
  * @name windowTitle
  * @memberOf QDockWidget.prototype
  * @type String
  */
QDockWidget.prototype.windowTitle = new String();


