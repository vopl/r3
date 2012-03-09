/**
  * @name QAction
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QAction(parent){return undefined;};

/**
  * @name QAction^1
  * @constructor
  * @extends QObject
  * @param {QIcon} icon
  * @param {String} text
  * @param {QObject} parent
  */
function QAction(icon, text, parent){return undefined;};

/**
  * @name QAction^2
  * @constructor
  * @extends QObject
  * @param {String} text
  * @param {QObject} parent
  */
function QAction(text, parent){return undefined;};

QAction.prototype = new QObject();

/**
  * @default 0
  * @constant
  * @memberOf QAction
  * @name LowPriority
  * @see QAction#Priority
  * @type Number
  */
QAction.LowPriority = 0x0;

/**
  * @default 128
  * @constant
  * @memberOf QAction
  * @name NormalPriority
  * @see QAction#Priority
  * @type Number
  */
QAction.NormalPriority = 0x80;

/**
  * @default 256
  * @constant
  * @memberOf QAction
  * @name HighPriority
  * @see QAction#Priority
  * @type Number
  */
QAction.HighPriority = 0x100;

/**
  * @constructor 
  * @memberOf QAction
  * @name Priority
  */
QAction.Priority = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAction
  * @name Trigger
  * @see QAction#ActionEvent
  * @type Number
  */
QAction.Trigger = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAction
  * @name Hover
  * @see QAction#ActionEvent
  * @type Number
  */
QAction.Hover = 0x1;

/**
  * @constructor 
  * @memberOf QAction
  * @name ActionEvent
  */
QAction.ActionEvent = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAction
  * @name NoSoftKey
  * @see QAction#SoftKeyRole
  * @type Number
  */
QAction.NoSoftKey = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAction
  * @name PositiveSoftKey
  * @see QAction#SoftKeyRole
  * @type Number
  */
QAction.PositiveSoftKey = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAction
  * @name NegativeSoftKey
  * @see QAction#SoftKeyRole
  * @type Number
  */
QAction.NegativeSoftKey = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAction
  * @name SelectSoftKey
  * @see QAction#SoftKeyRole
  * @type Number
  */
QAction.SelectSoftKey = 0x3;

/**
  * @constructor 
  * @memberOf QAction
  * @name SoftKeyRole
  */
QAction.SoftKeyRole = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAction
  * @name NoRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.NoRole = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAction
  * @name TextHeuristicRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.TextHeuristicRole = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAction
  * @name ApplicationSpecificRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.ApplicationSpecificRole = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAction
  * @name AboutQtRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.AboutQtRole = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAction
  * @name AboutRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.AboutRole = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QAction
  * @name PreferencesRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.PreferencesRole = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QAction
  * @name QuitRole
  * @see QAction#MenuRole
  * @type Number
  */
QAction.QuitRole = 0x6;

/**
  * @constructor 
  * @memberOf QAction
  * @name MenuRole
  */
QAction.MenuRole = function(value){;};



/**
  * @name actionGroup
  * @function
  * @memberOf QAction.prototype
  * @returns {QActionGroup}
  */
QAction.prototype.actionGroup = function(){return new QActionGroup();};

/**
  * @name activate
  * @function
  * @memberOf QAction.prototype
  * @param {QAction.ActionEvent} event
  * @returns {undefined}
  */
QAction.prototype.activate = function(event){return undefined;};

/**
  * @name associatedGraphicsWidgets
  * @function
  * @memberOf QAction.prototype
  * @returns {Array}
  */
QAction.prototype.associatedGraphicsWidgets = function(){return new Array();};

/**
  * @name associatedWidgets
  * @function
  * @memberOf QAction.prototype
  * @returns {Array}
  */
QAction.prototype.associatedWidgets = function(){return new Array();};

/**
  * @name data
  * @function
  * @memberOf QAction.prototype
  * @returns {Object}
  */
QAction.prototype.data = function(){return new Object();};

/**
  * @name isSeparator
  * @function
  * @memberOf QAction.prototype
  * @returns {Boolean}
  */
QAction.prototype.isSeparator = function(){return new Boolean();};

/**
  * @name menu
  * @function
  * @memberOf QAction.prototype
  * @returns {QMenu}
  */
QAction.prototype.menu = function(){return new QMenu();};

/**
  * @name parentWidget
  * @function
  * @memberOf QAction.prototype
  * @returns {QWidget}
  */
QAction.prototype.parentWidget = function(){return new QWidget();};

/**
  * @name setActionGroup
  * @function
  * @memberOf QAction.prototype
  * @param {QActionGroup} group
  * @returns {undefined}
  */
QAction.prototype.setActionGroup = function(group){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QAction.prototype
  * @param {Object} _var
  * @returns {undefined}
  */
QAction.prototype.setData = function(_var){return undefined;};

/**
  * @name setMenu
  * @function
  * @memberOf QAction.prototype
  * @param {QMenu} menu
  * @returns {undefined}
  */
QAction.prototype.setMenu = function(menu){return undefined;};

/**
  * @name setSeparator
  * @function
  * @memberOf QAction.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QAction.prototype.setSeparator = function(b){return undefined;};

/**
  * @name setShortcuts
  * @function
  * @memberOf QAction.prototype
  * @param {QKeySequence.StandardKey} arg__1
  * @returns {undefined}
  */
QAction.prototype.setShortcuts = function(arg__1){return undefined;};

/**
  * @name shortcuts
  * @function
  * @memberOf QAction.prototype
  * @returns {Array}
  */
QAction.prototype.shortcuts = function(){return new Array();};

/**
  * @name showStatusText
  * @function
  * @memberOf QAction.prototype
  * @param {QWidget} widget
  * @returns {Boolean}
  */
QAction.prototype.showStatusText = function(widget){return new Boolean();};

/**
  * @name checkable
  * @memberOf QAction.prototype
  * @type Boolean
  */
QAction.prototype.checkable = new Boolean();

/**
  * @name checked
  * @memberOf QAction.prototype
  * @type Boolean
  */
QAction.prototype.checked = new Boolean();

/**
  * @name enabled
  * @memberOf QAction.prototype
  * @type Boolean
  */
QAction.prototype.enabled = new Boolean();

/**
  * @name icon
  * @memberOf QAction.prototype
  * @type QIcon
  */
QAction.prototype.icon = new QIcon();

/**
  * @name text
  * @memberOf QAction.prototype
  * @type String
  */
QAction.prototype.text = new String();

/**
  * @name iconText
  * @memberOf QAction.prototype
  * @type String
  */
QAction.prototype.iconText = new String();

/**
  * @name toolTip
  * @memberOf QAction.prototype
  * @type String
  */
QAction.prototype.toolTip = new String();

/**
  * @name statusTip
  * @memberOf QAction.prototype
  * @type String
  */
QAction.prototype.statusTip = new String();

/**
  * @name whatsThis
  * @memberOf QAction.prototype
  * @type String
  */
QAction.prototype.whatsThis = new String();

/**
  * @name font
  * @memberOf QAction.prototype
  * @type QFont
  */
QAction.prototype.font = new QFont();

/**
  * @name shortcut
  * @memberOf QAction.prototype
  * @type QKeySequence
  */
QAction.prototype.shortcut = new QKeySequence();

/**
  * @name shortcutContext
  * @memberOf QAction.prototype
  * @type Qt.ShortcutContext
  */
QAction.prototype.shortcutContext = new Qt.ShortcutContext();

/**
  * @name autoRepeat
  * @memberOf QAction.prototype
  * @type Boolean
  */
QAction.prototype.autoRepeat = new Boolean();

/**
  * @name visible
  * @memberOf QAction.prototype
  * @type Boolean
  */
QAction.prototype.visible = new Boolean();

/**
  * @name menuRole
  * @memberOf QAction.prototype
  * @type QAction.MenuRole
  */
QAction.prototype.menuRole = new QAction.MenuRole();

/**
  * @name softKeyRole
  * @memberOf QAction.prototype
  * @type QAction.SoftKeyRole
  */
QAction.prototype.softKeyRole = new QAction.SoftKeyRole();

/**
  * @name iconVisibleInMenu
  * @memberOf QAction.prototype
  * @type Boolean
  */
QAction.prototype.iconVisibleInMenu = new Boolean();

/**
  * @name priority
  * @memberOf QAction.prototype
  * @type QAction.Priority
  */
QAction.prototype.priority = new QAction.Priority();


