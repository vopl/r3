/**
  * @name QDesktopWidget
  * @constructor
  * @extends QWidget
  */
function QDesktopWidget(){return undefined;};

QDesktopWidget.prototype = new QWidget();

/**
  * @name availableGeometry
  * @function
  * @memberOf QDesktopWidget.prototype
  * @param {QPoint} point
  * @returns {QRect}
  */
QDesktopWidget.prototype.availableGeometry = function(point){return new QRect();};

/**
  * @name numScreens
  * @function
  * @memberOf QDesktopWidget.prototype
  * @returns {Numeric}
  */
QDesktopWidget.prototype.numScreens = function(){return new Numeric();};

/**
  * @name screen
  * @function
  * @memberOf QDesktopWidget.prototype
  * @param {Numeric} screen
  * @returns {QWidget}
  */
QDesktopWidget.prototype.screen = function(screen){return new QWidget();};

/**
  * @name screenGeometry
  * @function
  * @memberOf QDesktopWidget.prototype
  * @param {QPoint} point
  * @returns {QRect}
  */
QDesktopWidget.prototype.screenGeometry = function(point){return new QRect();};

/**
  * @name screenNumber
  * @function
  * @memberOf QDesktopWidget.prototype
  * @param {QPoint} arg__1
  * @returns {Numeric}
  */
QDesktopWidget.prototype.screenNumber = function(arg__1){return new Numeric();};

/**
  * @name virtualDesktop
  * @memberOf QDesktopWidget.prototype
  * @type Boolean
  */
QDesktopWidget.prototype.virtualDesktop = new Boolean();

/**
  * @name screenCount
  * @memberOf QDesktopWidget.prototype
  * @type Numeric
  */
QDesktopWidget.prototype.screenCount = new Numeric();

/**
  * @name primaryScreen
  * @memberOf QDesktopWidget.prototype
  * @type Numeric
  */
QDesktopWidget.prototype.primaryScreen = new Numeric();


