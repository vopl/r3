/**
  * @name QMenuBar
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QMenuBar(parent){return undefined;};

QMenuBar.prototype = new QWidget();

/**
  * @name actionAt
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QPoint} arg__1
  * @returns {QAction}
  */
QMenuBar.prototype.actionAt = function(arg__1){return new QAction();};

/**
  * @name actionGeometry
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QAction} arg__1
  * @returns {QRect}
  */
QMenuBar.prototype.actionGeometry = function(arg__1){return new QRect();};

/**
  * @name activeAction
  * @function
  * @memberOf QMenuBar.prototype
  * @returns {QAction}
  */
QMenuBar.prototype.activeAction = function(){return new QAction();};

/**
  * @name addAction
  * @function
  * @memberOf QMenuBar.prototype
  * @param {String} text
  * @returns {QAction}
  */
QMenuBar.prototype.addAction = function(text){return new QAction();};

/**
  * @name addMenu
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QMenu} menu
  * @returns {QAction}
  */
QMenuBar.prototype.addMenu = function(menu){return new QAction();};

/**
  * @name addSeparator
  * @function
  * @memberOf QMenuBar.prototype
  * @returns {QAction}
  */
QMenuBar.prototype.addSeparator = function(){return new QAction();};

/**
  * @name clear
  * @function
  * @memberOf QMenuBar.prototype
  * @returns {undefined}
  */
QMenuBar.prototype.clear = function(){return undefined;};

/**
  * @name cornerWidget
  * @function
  * @memberOf QMenuBar.prototype
  * @param {Qt.Corner} corner
  * @returns {QWidget}
  */
QMenuBar.prototype.cornerWidget = function(corner){return new QWidget();};

/**
  * @name insertMenu
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QAction} before
  * @param {QMenu} menu
  * @returns {QAction}
  */
QMenuBar.prototype.insertMenu = function(before, menu){return new QAction();};

/**
  * @name insertSeparator
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QAction} before
  * @returns {QAction}
  */
QMenuBar.prototype.insertSeparator = function(before){return new QAction();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QMenuBar.prototype
  * @returns {QSize}
  */
QMenuBar.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setActiveAction
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QAction} action
  * @returns {undefined}
  */
QMenuBar.prototype.setActiveAction = function(action){return undefined;};

/**
  * @name setCornerWidget
  * @function
  * @memberOf QMenuBar.prototype
  * @param {QWidget} w
  * @param {Qt.Corner} corner
  * @returns {undefined}
  */
QMenuBar.prototype.setCornerWidget = function(w, corner){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QMenuBar.prototype
  * @returns {QSize}
  */
QMenuBar.prototype.sizeHint = function(){return new QSize();};

/**
  * @name defaultUp
  * @memberOf QMenuBar.prototype
  * @type Boolean
  */
QMenuBar.prototype.defaultUp = new Boolean();

/**
  * @name nativeMenuBar
  * @memberOf QMenuBar.prototype
  * @type Boolean
  */
QMenuBar.prototype.nativeMenuBar = new Boolean();


