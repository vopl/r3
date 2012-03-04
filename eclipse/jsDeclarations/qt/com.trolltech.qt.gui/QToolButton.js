/**
  * @name QToolButton
  * @constructor
  * @extends QAbstractButton
  * @param {QWidget} parent
  */
function QToolButton(parent){return undefined;};

QToolButton.prototype = new QAbstractButton();

/**
  * @default 0x0
  * @constant
  * @memberOf QToolButton
  * @name DelayedPopup
  * @see QToolButton#ToolButtonPopupMode
  * @type Number
  */
QToolButton.DelayedPopup = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QToolButton
  * @name MenuButtonPopup
  * @see QToolButton#ToolButtonPopupMode
  * @type Number
  */
QToolButton.MenuButtonPopup = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QToolButton
  * @name InstantPopup
  * @see QToolButton#ToolButtonPopupMode
  * @type Number
  */
QToolButton.InstantPopup = 0x2;

/**
  * @constructor 
  * @memberOf QToolButton
  * @name ToolButtonPopupMode
  */
QToolButton.ToolButtonPopupMode = function(value){;};



/**
  * @name defaultAction
  * @function
  * @memberOf QToolButton.prototype
  * @returns {QAction}
  */
QToolButton.prototype.defaultAction = function(){return new QAction();};

/**
  * @name menu
  * @function
  * @memberOf QToolButton.prototype
  * @returns {QMenu}
  */
QToolButton.prototype.menu = function(){return new QMenu();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QToolButton.prototype
  * @returns {QSize}
  */
QToolButton.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setMenu
  * @function
  * @memberOf QToolButton.prototype
  * @param {QMenu} menu
  * @returns {undefined}
  */
QToolButton.prototype.setMenu = function(menu){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QToolButton.prototype
  * @returns {QSize}
  */
QToolButton.prototype.sizeHint = function(){return new QSize();};

/**
  * @name popupMode
  * @memberOf QToolButton.prototype
  * @type QToolButton.ToolButtonPopupMode
  */
QToolButton.prototype.popupMode = new QToolButton.ToolButtonPopupMode();

/**
  * @name toolButtonStyle
  * @memberOf QToolButton.prototype
  * @type Qt.ToolButtonStyle
  */
QToolButton.prototype.toolButtonStyle = new Qt.ToolButtonStyle();

/**
  * @name autoRaise
  * @memberOf QToolButton.prototype
  * @type Boolean
  */
QToolButton.prototype.autoRaise = new Boolean();

/**
  * @name arrowType
  * @memberOf QToolButton.prototype
  * @type Qt.ArrowType
  */
QToolButton.prototype.arrowType = new Qt.ArrowType();


