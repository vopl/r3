/**
  * @name QToolBar
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QToolBar(parent){return undefined;};

/**
  * @name QToolBar^1
  * @constructor
  * @extends QWidget
  * @param {String} title
  * @param {QWidget} parent
  */
function QToolBar(title, parent){return undefined;};

QToolBar.prototype = new QWidget();

/**
  * @name actionAt
  * @function
  * @memberOf QToolBar.prototype
  * @param {QPoint} p
  * @returns {QAction}
  */
QToolBar.prototype.actionAt = function(p){return new QAction();};

/**
  * @name actionGeometry
  * @function
  * @memberOf QToolBar.prototype
  * @param {QAction} action
  * @returns {QRect}
  */
QToolBar.prototype.actionGeometry = function(action){return new QRect();};

/**
  * @name addAction
  * @function
  * @memberOf QToolBar.prototype
  * @param {QIcon} icon
  * @param {String} text
  * @returns {QAction}
  */
QToolBar.prototype.addAction = function(icon, text){return new QAction();};

/**
  * @name addSeparator
  * @function
  * @memberOf QToolBar.prototype
  * @returns {QAction}
  */
QToolBar.prototype.addSeparator = function(){return new QAction();};

/**
  * @name addWidget
  * @function
  * @memberOf QToolBar.prototype
  * @param {QWidget} widget
  * @returns {QAction}
  */
QToolBar.prototype.addWidget = function(widget){return new QAction();};

/**
  * @name allowedAreas
  * @function
  * @memberOf QToolBar.prototype
  * @returns {Qt.ToolBarAreas}
  */
QToolBar.prototype.allowedAreas = function(){return new Qt.ToolBarAreas();};

/**
  * @name clear
  * @function
  * @memberOf QToolBar.prototype
  * @returns {undefined}
  */
QToolBar.prototype.clear = function(){return undefined;};

/**
  * @name iconSize
  * @function
  * @memberOf QToolBar.prototype
  * @returns {QSize}
  */
QToolBar.prototype.iconSize = function(){return new QSize();};

/**
  * @name insertSeparator
  * @function
  * @memberOf QToolBar.prototype
  * @param {QAction} before
  * @returns {QAction}
  */
QToolBar.prototype.insertSeparator = function(before){return new QAction();};

/**
  * @name insertWidget
  * @function
  * @memberOf QToolBar.prototype
  * @param {QAction} before
  * @param {QWidget} widget
  * @returns {QAction}
  */
QToolBar.prototype.insertWidget = function(before, widget){return new QAction();};

/**
  * @name isAreaAllowed
  * @function
  * @memberOf QToolBar.prototype
  * @param {Qt.ToolBarArea} area
  * @returns {Boolean}
  */
QToolBar.prototype.isAreaAllowed = function(area){return new Boolean();};

/**
  * @name isFloatable
  * @function
  * @memberOf QToolBar.prototype
  * @returns {Boolean}
  */
QToolBar.prototype.isFloatable = function(){return new Boolean();};

/**
  * @name isFloating
  * @function
  * @memberOf QToolBar.prototype
  * @returns {Boolean}
  */
QToolBar.prototype.isFloating = function(){return new Boolean();};

/**
  * @name orientation
  * @function
  * @memberOf QToolBar.prototype
  * @returns {QPrinter.Orientation}
  */
QToolBar.prototype.orientation = function(){return new QPrinter.Orientation();};

/**
  * @name setAllowedAreas
  * @function
  * @memberOf QToolBar.prototype
  * @param {Qt.ToolBarAreas} areas
  * @returns {undefined}
  */
QToolBar.prototype.setAllowedAreas = function(areas){return undefined;};

/**
  * @name setFloatable
  * @function
  * @memberOf QToolBar.prototype
  * @param {Boolean} floatable
  * @returns {undefined}
  */
QToolBar.prototype.setFloatable = function(floatable){return undefined;};

/**
  * @name setMovable
  * @function
  * @memberOf QToolBar.prototype
  * @param {Boolean} movable
  * @returns {undefined}
  */
QToolBar.prototype.setMovable = function(movable){return undefined;};

/**
  * @name setOrientation
  * @function
  * @memberOf QToolBar.prototype
  * @param {QPrinter.Orientation} orientation
  * @returns {undefined}
  */
QToolBar.prototype.setOrientation = function(orientation){return undefined;};

/**
  * @name toggleViewAction
  * @function
  * @memberOf QToolBar.prototype
  * @returns {QAction}
  */
QToolBar.prototype.toggleViewAction = function(){return new QAction();};

/**
  * @name toolButtonStyle
  * @function
  * @memberOf QToolBar.prototype
  * @returns {Qt.ToolButtonStyle}
  */
QToolBar.prototype.toolButtonStyle = function(){return new Qt.ToolButtonStyle();};

/**
  * @name widgetForAction
  * @function
  * @memberOf QToolBar.prototype
  * @param {QAction} action
  * @returns {QWidget}
  */
QToolBar.prototype.widgetForAction = function(action){return new QWidget();};

/**
  * @name movable
  * @memberOf QToolBar.prototype
  * @type Boolean
  */
QToolBar.prototype.movable = new Boolean();


