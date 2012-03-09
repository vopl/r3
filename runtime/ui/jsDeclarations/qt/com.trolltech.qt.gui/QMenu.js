/**
  * @name QMenu
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QMenu(parent){return undefined;};

/**
  * @name QMenu^1
  * @constructor
  * @extends QWidget
  * @param {String} title
  * @param {QWidget} parent
  */
function QMenu(title, parent){return undefined;};

QMenu.prototype = new QWidget();

/**
  * @name exec
  * @function
  * @memberOf QMenu
  * @param {Array} actions
  * @param {QPoint} pos
  * @param {QAction} at
  * @returns {QAction}
  */
QMenu.exec = function(actions, pos, at){return new QAction();};

/**
  * @name actionAt
  * @function
  * @memberOf QMenu.prototype
  * @param {QPoint} arg__1
  * @returns {QAction}
  */
QMenu.prototype.actionAt = function(arg__1){return new QAction();};

/**
  * @name actionGeometry
  * @function
  * @memberOf QMenu.prototype
  * @param {QAction} arg__1
  * @returns {QRect}
  */
QMenu.prototype.actionGeometry = function(arg__1){return new QRect();};

/**
  * @name activeAction
  * @function
  * @memberOf QMenu.prototype
  * @returns {QAction}
  */
QMenu.prototype.activeAction = function(){return new QAction();};

/**
  * @name addAction
  * @function
  * @memberOf QMenu.prototype
  * @param {QIcon} icon
  * @param {String} text
  * @returns {QAction}
  */
QMenu.prototype.addAction = function(icon, text){return new QAction();};

/**
  * @name addMenu
  * @function
  * @memberOf QMenu.prototype
  * @param {QMenu} menu
  * @returns {QAction}
  */
QMenu.prototype.addMenu = function(menu){return new QAction();};

/**
  * @name addSeparator
  * @function
  * @memberOf QMenu.prototype
  * @returns {QAction}
  */
QMenu.prototype.addSeparator = function(){return new QAction();};

/**
  * @name clear
  * @function
  * @memberOf QMenu.prototype
  * @returns {undefined}
  */
QMenu.prototype.clear = function(){return undefined;};

/**
  * @name defaultAction
  * @function
  * @memberOf QMenu.prototype
  * @returns {QAction}
  */
QMenu.prototype.defaultAction = function(){return new QAction();};

/**
  * @name exec
  * @function
  * @memberOf QMenu.prototype
  * @returns {QAction}
  */
QMenu.prototype.exec = function(){return new QAction();};

/**
  * @name hideTearOffMenu
  * @function
  * @memberOf QMenu.prototype
  * @returns {undefined}
  */
QMenu.prototype.hideTearOffMenu = function(){return undefined;};

/**
  * @name insertMenu
  * @function
  * @memberOf QMenu.prototype
  * @param {QAction} before
  * @param {QMenu} menu
  * @returns {QAction}
  */
QMenu.prototype.insertMenu = function(before, menu){return new QAction();};

/**
  * @name insertSeparator
  * @function
  * @memberOf QMenu.prototype
  * @param {QAction} before
  * @returns {QAction}
  */
QMenu.prototype.insertSeparator = function(before){return new QAction();};

/**
  * @name isEmpty
  * @function
  * @memberOf QMenu.prototype
  * @returns {Boolean}
  */
QMenu.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name isTearOffMenuVisible
  * @function
  * @memberOf QMenu.prototype
  * @returns {Boolean}
  */
QMenu.prototype.isTearOffMenuVisible = function(){return new Boolean();};

/**
  * @name menuAction
  * @function
  * @memberOf QMenu.prototype
  * @returns {QAction}
  */
QMenu.prototype.menuAction = function(){return new QAction();};

/**
  * @name popup
  * @function
  * @memberOf QMenu.prototype
  * @param {QPoint} pos
  * @param {QAction} at
  * @returns {undefined}
  */
QMenu.prototype.popup = function(pos, at){return undefined;};

/**
  * @name setActiveAction
  * @function
  * @memberOf QMenu.prototype
  * @param {QAction} act
  * @returns {undefined}
  */
QMenu.prototype.setActiveAction = function(act){return undefined;};

/**
  * @name setDefaultAction
  * @function
  * @memberOf QMenu.prototype
  * @param {QAction} arg__1
  * @returns {undefined}
  */
QMenu.prototype.setDefaultAction = function(arg__1){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QMenu.prototype
  * @returns {QSize}
  */
QMenu.prototype.sizeHint = function(){return new QSize();};

/**
  * @name tearOffEnabled
  * @memberOf QMenu.prototype
  * @type Boolean
  */
QMenu.prototype.tearOffEnabled = new Boolean();

/**
  * @name title
  * @memberOf QMenu.prototype
  * @type String
  */
QMenu.prototype.title = new String();

/**
  * @name icon
  * @memberOf QMenu.prototype
  * @type QIcon
  */
QMenu.prototype.icon = new QIcon();

/**
  * @name separatorsCollapsible
  * @memberOf QMenu.prototype
  * @type Boolean
  */
QMenu.prototype.separatorsCollapsible = new Boolean();


