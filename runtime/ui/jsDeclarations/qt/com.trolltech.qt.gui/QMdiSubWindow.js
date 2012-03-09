/**
  * @name QMdiSubWindow
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QMdiSubWindow(parent, flags){return undefined;};

QMdiSubWindow.prototype = new QWidget();

/**
  * @default 0x1
  * @constant
  * @memberOf QMdiSubWindow
  * @name AllowOutsideAreaHorizontally
  * @see QMdiSubWindow#SubWindowOptions
  * @see QMdiSubWindow#SubWindowOption
  * @type Number
  */
QMdiSubWindow.AllowOutsideAreaHorizontally = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QMdiSubWindow
  * @name AllowOutsideAreaVertically
  * @see QMdiSubWindow#SubWindowOptions
  * @see QMdiSubWindow#SubWindowOption
  * @type Number
  */
QMdiSubWindow.AllowOutsideAreaVertically = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QMdiSubWindow
  * @name RubberBandResize
  * @see QMdiSubWindow#SubWindowOptions
  * @see QMdiSubWindow#SubWindowOption
  * @type Number
  */
QMdiSubWindow.RubberBandResize = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QMdiSubWindow
  * @name RubberBandMove
  * @see QMdiSubWindow#SubWindowOptions
  * @see QMdiSubWindow#SubWindowOption
  * @type Number
  */
QMdiSubWindow.RubberBandMove = 0x8;

/**
  * @constructor 
  * @memberOf QMdiSubWindow
  * @name SubWindowOption
  */
QMdiSubWindow.SubWindowOption = function(value){;};

/**
  * @constructor 
  * @memberOf QMdiSubWindow
  * @name SubWindowOptions
  */
QMdiSubWindow.SubWindowOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name isShaded
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {Boolean}
  */
QMdiSubWindow.prototype.isShaded = function(){return new Boolean();};

/**
  * @name maximizedButtonsWidget
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QWidget}
  */
QMdiSubWindow.prototype.maximizedButtonsWidget = function(){return new QWidget();};

/**
  * @name maximizedSystemMenuIconWidget
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QWidget}
  */
QMdiSubWindow.prototype.maximizedSystemMenuIconWidget = function(){return new QWidget();};

/**
  * @name mdiArea
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QMdiArea}
  */
QMdiSubWindow.prototype.mdiArea = function(){return new QMdiArea();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QSize}
  */
QMdiSubWindow.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setOption
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @param {QMdiSubWindow.SubWindowOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QMdiSubWindow.prototype.setOption = function(option, on){return undefined;};

/**
  * @name setSystemMenu
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @param {QMenu} systemMenu
  * @returns {undefined}
  */
QMdiSubWindow.prototype.setSystemMenu = function(systemMenu){return undefined;};

/**
  * @name setWidget
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QMdiSubWindow.prototype.setWidget = function(widget){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QSize}
  */
QMdiSubWindow.prototype.sizeHint = function(){return new QSize();};

/**
  * @name systemMenu
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QMenu}
  */
QMdiSubWindow.prototype.systemMenu = function(){return new QMenu();};

/**
  * @name testOption
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @param {QMdiSubWindow.SubWindowOption} arg__1
  * @returns {Boolean}
  */
QMdiSubWindow.prototype.testOption = function(arg__1){return new Boolean();};

/**
  * @name widget
  * @function
  * @memberOf QMdiSubWindow.prototype
  * @returns {QWidget}
  */
QMdiSubWindow.prototype.widget = function(){return new QWidget();};

/**
  * @name keyboardSingleStep
  * @memberOf QMdiSubWindow.prototype
  * @type Numeric
  */
QMdiSubWindow.prototype.keyboardSingleStep = new Numeric();

/**
  * @name keyboardPageStep
  * @memberOf QMdiSubWindow.prototype
  * @type Numeric
  */
QMdiSubWindow.prototype.keyboardPageStep = new Numeric();


