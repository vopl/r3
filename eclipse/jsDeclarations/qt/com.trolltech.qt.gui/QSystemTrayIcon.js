/**
  * @name QSystemTrayIcon
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QSystemTrayIcon(parent){return undefined;};

/**
  * @name QSystemTrayIcon^1
  * @constructor
  * @extends QObject
  * @param {QIcon} icon
  * @param {QObject} parent
  */
function QSystemTrayIcon(icon, parent){return undefined;};

QSystemTrayIcon.prototype = new QObject();

/**
  * @name isSystemTrayAvailable
  * @function
  * @memberOf QSystemTrayIcon
  * @returns {Boolean}
  */
QSystemTrayIcon.isSystemTrayAvailable = function(){return new Boolean();};

/**
  * @name supportsMessages
  * @function
  * @memberOf QSystemTrayIcon
  * @returns {Boolean}
  */
QSystemTrayIcon.supportsMessages = function(){return new Boolean();};

/**
  * @default 0x0
  * @constant
  * @memberOf QSystemTrayIcon
  * @name NoIcon
  * @see QSystemTrayIcon#MessageIcon
  * @type Number
  */
QSystemTrayIcon.NoIcon = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSystemTrayIcon
  * @name Information
  * @see QSystemTrayIcon#MessageIcon
  * @type Number
  */
QSystemTrayIcon.Information = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSystemTrayIcon
  * @name Warning
  * @see QSystemTrayIcon#MessageIcon
  * @type Number
  */
QSystemTrayIcon.Warning = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSystemTrayIcon
  * @name Critical
  * @see QSystemTrayIcon#MessageIcon
  * @type Number
  */
QSystemTrayIcon.Critical = 0x3;

/**
  * @constructor 
  * @memberOf QSystemTrayIcon
  * @name MessageIcon
  */
QSystemTrayIcon.MessageIcon = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSystemTrayIcon
  * @name Unknown
  * @see QSystemTrayIcon#ActivationReason
  * @type Number
  */
QSystemTrayIcon.Unknown = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSystemTrayIcon
  * @name Context
  * @see QSystemTrayIcon#ActivationReason
  * @type Number
  */
QSystemTrayIcon.Context = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSystemTrayIcon
  * @name DoubleClick
  * @see QSystemTrayIcon#ActivationReason
  * @type Number
  */
QSystemTrayIcon.DoubleClick = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSystemTrayIcon
  * @name Trigger
  * @see QSystemTrayIcon#ActivationReason
  * @type Number
  */
QSystemTrayIcon.Trigger = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QSystemTrayIcon
  * @name MiddleClick
  * @see QSystemTrayIcon#ActivationReason
  * @type Number
  */
QSystemTrayIcon.MiddleClick = 0x4;

/**
  * @constructor 
  * @memberOf QSystemTrayIcon
  * @name ActivationReason
  */
QSystemTrayIcon.ActivationReason = function(value){;};



/**
  * @name contextMenu
  * @function
  * @memberOf QSystemTrayIcon.prototype
  * @returns {QMenu}
  */
QSystemTrayIcon.prototype.contextMenu = function(){return new QMenu();};

/**
  * @name geometry
  * @function
  * @memberOf QSystemTrayIcon.prototype
  * @returns {QRect}
  */
QSystemTrayIcon.prototype.geometry = function(){return new QRect();};

/**
  * @name setContextMenu
  * @function
  * @memberOf QSystemTrayIcon.prototype
  * @param {QMenu} menu
  * @returns {undefined}
  */
QSystemTrayIcon.prototype.setContextMenu = function(menu){return undefined;};

/**
  * @name showMessage
  * @function
  * @memberOf QSystemTrayIcon.prototype
  * @param {String} title
  * @param {String} msg
  * @param {QSystemTrayIcon.MessageIcon} icon
  * @param {Numeric} msecs
  * @returns {undefined}
  */
QSystemTrayIcon.prototype.showMessage = function(title, msg, icon, msecs){return undefined;};

/**
  * @name toolTip
  * @memberOf QSystemTrayIcon.prototype
  * @type String
  */
QSystemTrayIcon.prototype.toolTip = new String();

/**
  * @name icon
  * @memberOf QSystemTrayIcon.prototype
  * @type QIcon
  */
QSystemTrayIcon.prototype.icon = new QIcon();

/**
  * @name visible
  * @memberOf QSystemTrayIcon.prototype
  * @type Boolean
  */
QSystemTrayIcon.prototype.visible = new Boolean();


