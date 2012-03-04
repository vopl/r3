/**
  * @name QMessageBox
  * @constructor
  * @extends QDialog
  * @param {QMessageBox.Icon} icon
  * @param {String} title
  * @param {String} text
  * @param {QMessageBox.StandardButtons} buttons
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QMessageBox(icon, title, text, buttons, parent, flags){return undefined;};

/**
  * @name QMessageBox^1
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  */
function QMessageBox(parent){return undefined;};

QMessageBox.prototype = new QDialog();

/**
  * @name about
  * @function
  * @memberOf QMessageBox
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} text
  * @returns {undefined}
  */
QMessageBox.about = function(parent, title, text){return undefined;};

/**
  * @name aboutQt
  * @function
  * @memberOf QMessageBox
  * @param {QWidget} parent
  * @param {String} title
  * @returns {undefined}
  */
QMessageBox.aboutQt = function(parent, title){return undefined;};

/**
  * @name critical
  * @function
  * @memberOf QMessageBox
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} text
  * @param {QMessageBox.StandardButtons} buttons
  * @param {QMessageBox.StandardButton} defaultButton
  * @returns {QMessageBox.StandardButton}
  */
QMessageBox.critical = function(parent, title, text, buttons, defaultButton){return new QMessageBox.StandardButton();};

/**
  * @name information
  * @function
  * @memberOf QMessageBox
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} text
  * @param {QMessageBox.StandardButtons} buttons
  * @param {QMessageBox.StandardButton} defaultButton
  * @returns {QMessageBox.StandardButton}
  */
QMessageBox.information = function(parent, title, text, buttons, defaultButton){return new QMessageBox.StandardButton();};

/**
  * @name question
  * @function
  * @memberOf QMessageBox
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} text
  * @param {QMessageBox.StandardButtons} buttons
  * @param {QMessageBox.StandardButton} defaultButton
  * @returns {QMessageBox.StandardButton}
  */
QMessageBox.question = function(parent, title, text, buttons, defaultButton){return new QMessageBox.StandardButton();};

/**
  * @name warning
  * @function
  * @memberOf QMessageBox
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} text
  * @param {QMessageBox.StandardButtons} buttons
  * @param {QMessageBox.StandardButton} defaultButton
  * @returns {QMessageBox.StandardButton}
  */
QMessageBox.warning = function(parent, title, text, buttons, defaultButton){return new QMessageBox.StandardButton();};

/**
  * @default -1
  * @constant
  * @memberOf QMessageBox
  * @name InvalidRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.InvalidRole = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QMessageBox
  * @name AcceptRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.AcceptRole = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QMessageBox
  * @name RejectRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.RejectRole = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QMessageBox
  * @name DestructiveRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.DestructiveRole = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QMessageBox
  * @name ActionRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.ActionRole = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QMessageBox
  * @name HelpRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.HelpRole = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QMessageBox
  * @name YesRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.YesRole = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QMessageBox
  * @name NoRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.NoRole = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QMessageBox
  * @name ResetRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.ResetRole = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QMessageBox
  * @name ApplyRole
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.ApplyRole = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QMessageBox
  * @name NRoles
  * @see QMessageBox#ButtonRole
  * @type Number
  */
QMessageBox.NRoles = 0x9;

/**
  * @constructor 
  * @memberOf QMessageBox
  * @name ButtonRole
  */
QMessageBox.ButtonRole = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf QMessageBox
  * @name NoButton
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.NoButton = 0x0;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QMessageBox
  * @name Default
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Default = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QMessageBox
  * @name Escape
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Escape = 0x200;

/**
  * @default 0x00000300
  * @constant
  * @memberOf QMessageBox
  * @name FlagMask
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.FlagMask = 0x300;

/**
  * @default ~FlagMask
  * @constant
  * @memberOf QMessageBox
  * @name ButtonMask
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.ButtonMask = 0x301;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QMessageBox
  * @name Ok
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Ok = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QMessageBox
  * @name Save
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Save = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QMessageBox
  * @name SaveAll
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.SaveAll = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QMessageBox
  * @name Open
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Open = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QMessageBox
  * @name Yes
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Yes = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf QMessageBox
  * @name YesToAll
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.YesToAll = 0x8000;

/**
  * @default 0x00010000
  * @constant
  * @memberOf QMessageBox
  * @name No
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.No = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf QMessageBox
  * @name NoToAll
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.NoToAll = 0x20000;

/**
  * @default 0x00040000
  * @constant
  * @memberOf QMessageBox
  * @name Abort
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Abort = 0x40000;

/**
  * @default 0x00080000
  * @constant
  * @memberOf QMessageBox
  * @name Retry
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Retry = 0x80000;

/**
  * @default 0x00100000
  * @constant
  * @memberOf QMessageBox
  * @name Ignore
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Ignore = 0x100000;

/**
  * @default 0x00200000
  * @constant
  * @memberOf QMessageBox
  * @name Close
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Close = 0x200000;

/**
  * @default 0x00400000
  * @constant
  * @memberOf QMessageBox
  * @name Cancel
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Cancel = 0x400000;

/**
  * @default 0x00800000
  * @constant
  * @memberOf QMessageBox
  * @name Discard
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Discard = 0x800000;

/**
  * @default 0x01000000
  * @constant
  * @memberOf QMessageBox
  * @name Help
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Help = 0x1000000;

/**
  * @default 0x02000000
  * @constant
  * @memberOf QMessageBox
  * @name Apply
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Apply = 0x2000000;

/**
  * @default 0x04000000
  * @constant
  * @memberOf QMessageBox
  * @name Reset
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.Reset = 0x4000000;

/**
  * @default 0x08000000
  * @constant
  * @memberOf QMessageBox
  * @name RestoreDefaults
  * @see QMessageBox#StandardButtons
  * @see QMessageBox#StandardButton
  * @type Number
  */
QMessageBox.RestoreDefaults = 0x8000000;

/**
  * @constructor 
  * @memberOf QMessageBox
  * @name StandardButton
  */
QMessageBox.StandardButton = function(value){;};

/**
  * @constructor 
  * @memberOf QMessageBox
  * @name StandardButtons
  */
QMessageBox.StandardButtons = function(value1, value2 /*, ...*/){;};


/**
  * @default 0
  * @constant
  * @memberOf QMessageBox
  * @name NoIcon
  * @see QMessageBox#Icon
  * @type Number
  */
QMessageBox.NoIcon = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QMessageBox
  * @name Information
  * @see QMessageBox#Icon
  * @type Number
  */
QMessageBox.Information = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QMessageBox
  * @name Warning
  * @see QMessageBox#Icon
  * @type Number
  */
QMessageBox.Warning = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QMessageBox
  * @name Critical
  * @see QMessageBox#Icon
  * @type Number
  */
QMessageBox.Critical = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QMessageBox
  * @name Question
  * @see QMessageBox#Icon
  * @type Number
  */
QMessageBox.Question = 0x4;

/**
  * @constructor 
  * @memberOf QMessageBox
  * @name Icon
  */
QMessageBox.Icon = function(value){;};



/**
  * @name addButton
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QAbstractButton} button
  * @param {QMessageBox.ButtonRole} role
  * @returns {undefined}
  */
QMessageBox.prototype.addButton = function(button, role){return undefined;};

/**
  * @name button
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QMessageBox.StandardButton} which
  * @returns {QAbstractButton}
  */
QMessageBox.prototype.button = function(which){return new QAbstractButton();};

/**
  * @name buttonRole
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QAbstractButton} button
  * @returns {QMessageBox.ButtonRole}
  */
QMessageBox.prototype.buttonRole = function(button){return new QMessageBox.ButtonRole();};

/**
  * @name buttons
  * @function
  * @memberOf QMessageBox.prototype
  * @returns {Array}
  */
QMessageBox.prototype.buttons = function(){return new Array();};

/**
  * @name clickedButton
  * @function
  * @memberOf QMessageBox.prototype
  * @returns {QAbstractButton}
  */
QMessageBox.prototype.clickedButton = function(){return new QAbstractButton();};

/**
  * @name defaultButton
  * @function
  * @memberOf QMessageBox.prototype
  * @returns {QPushButton}
  */
QMessageBox.prototype.defaultButton = function(){return new QPushButton();};

/**
  * @name escapeButton
  * @function
  * @memberOf QMessageBox.prototype
  * @returns {QAbstractButton}
  */
QMessageBox.prototype.escapeButton = function(){return new QAbstractButton();};

/**
  * @name open
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QMessageBox.prototype.open = function(receiver, member){return undefined;};

/**
  * @name removeButton
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QAbstractButton} button
  * @returns {undefined}
  */
QMessageBox.prototype.removeButton = function(button){return undefined;};

/**
  * @name setDefaultButton
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QMessageBox.StandardButton} button
  * @returns {undefined}
  */
QMessageBox.prototype.setDefaultButton = function(button){return undefined;};

/**
  * @name setEscapeButton
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QAbstractButton} button
  * @returns {undefined}
  */
QMessageBox.prototype.setEscapeButton = function(button){return undefined;};

/**
  * @name standardButton
  * @function
  * @memberOf QMessageBox.prototype
  * @param {QAbstractButton} button
  * @returns {QMessageBox.StandardButton}
  */
QMessageBox.prototype.standardButton = function(button){return new QMessageBox.StandardButton();};

/**
  * @name text
  * @memberOf QMessageBox.prototype
  * @type String
  */
QMessageBox.prototype.text = new String();

/**
  * @name icon
  * @memberOf QMessageBox.prototype
  * @type QMessageBox.Icon
  */
QMessageBox.prototype.icon = new QMessageBox.Icon();

/**
  * @name iconPixmap
  * @memberOf QMessageBox.prototype
  * @type QPixmap
  */
QMessageBox.prototype.iconPixmap = new QPixmap();

/**
  * @name textFormat
  * @memberOf QMessageBox.prototype
  * @type Qt.TextFormat
  */
QMessageBox.prototype.textFormat = new Qt.TextFormat();

/**
  * @name standardButtons
  * @memberOf QMessageBox.prototype
  * @type QMessageBox.StandardButtons
  */
QMessageBox.prototype.standardButtons = new QMessageBox.StandardButtons();

/**
  * @name detailedText
  * @memberOf QMessageBox.prototype
  * @type String
  */
QMessageBox.prototype.detailedText = new String();

/**
  * @name informativeText
  * @memberOf QMessageBox.prototype
  * @type String
  */
QMessageBox.prototype.informativeText = new String();


