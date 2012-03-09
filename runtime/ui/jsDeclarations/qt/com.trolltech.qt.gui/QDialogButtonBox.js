/**
  * @name QDialogButtonBox
  * @constructor
  * @extends QWidget
  * @param {QMessageBox.StandardButtons} buttons
  * @param {QPrinter.Orientation} orientation
  * @param {QWidget} parent
  */
function QDialogButtonBox(buttons, orientation, parent){return undefined;};

/**
  * @name QDialogButtonBox^1
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QDialogButtonBox(parent){return undefined;};

/**
  * @name QDialogButtonBox^2
  * @constructor
  * @extends QWidget
  * @param {QPrinter.Orientation} orientation
  * @param {QWidget} parent
  */
function QDialogButtonBox(orientation, parent){return undefined;};

QDialogButtonBox.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QDialogButtonBox
  * @name WinLayout
  * @see QDialogButtonBox#ButtonLayout
  * @type Number
  */
QDialogButtonBox.WinLayout = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDialogButtonBox
  * @name MacLayout
  * @see QDialogButtonBox#ButtonLayout
  * @type Number
  */
QDialogButtonBox.MacLayout = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QDialogButtonBox
  * @name KdeLayout
  * @see QDialogButtonBox#ButtonLayout
  * @type Number
  */
QDialogButtonBox.KdeLayout = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QDialogButtonBox
  * @name GnomeLayout
  * @see QDialogButtonBox#ButtonLayout
  * @type Number
  */
QDialogButtonBox.GnomeLayout = 0x3;

/**
  * @constructor 
  * @memberOf QDialogButtonBox
  * @name ButtonLayout
  */
QDialogButtonBox.ButtonLayout = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QDialogButtonBox
  * @name InvalidRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.InvalidRole = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QDialogButtonBox
  * @name AcceptRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.AcceptRole = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDialogButtonBox
  * @name RejectRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.RejectRole = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QDialogButtonBox
  * @name DestructiveRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.DestructiveRole = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QDialogButtonBox
  * @name ActionRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.ActionRole = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QDialogButtonBox
  * @name HelpRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.HelpRole = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QDialogButtonBox
  * @name YesRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.YesRole = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QDialogButtonBox
  * @name NoRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.NoRole = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QDialogButtonBox
  * @name ResetRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.ResetRole = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QDialogButtonBox
  * @name ApplyRole
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.ApplyRole = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QDialogButtonBox
  * @name NRoles
  * @see QDialogButtonBox#ButtonRole
  * @type Number
  */
QDialogButtonBox.NRoles = 0x9;

/**
  * @constructor 
  * @memberOf QDialogButtonBox
  * @name ButtonRole
  */
QDialogButtonBox.ButtonRole = function(value){;};



/**
  * @default 0x00000000
  * @constant
  * @memberOf QDialogButtonBox
  * @name NoButton
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.NoButton = 0x0;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QDialogButtonBox
  * @name Ok
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Ok = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QDialogButtonBox
  * @name Save
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Save = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QDialogButtonBox
  * @name SaveAll
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.SaveAll = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Open
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Open = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Yes
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Yes = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf QDialogButtonBox
  * @name YesToAll
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.YesToAll = 0x8000;

/**
  * @default 0x00010000
  * @constant
  * @memberOf QDialogButtonBox
  * @name No
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.No = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf QDialogButtonBox
  * @name NoToAll
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.NoToAll = 0x20000;

/**
  * @default 0x00040000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Abort
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Abort = 0x40000;

/**
  * @default 0x00080000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Retry
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Retry = 0x80000;

/**
  * @default 0x00100000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Ignore
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Ignore = 0x100000;

/**
  * @default 0x00200000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Close
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Close = 0x200000;

/**
  * @default 0x00400000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Cancel
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Cancel = 0x400000;

/**
  * @default 0x00800000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Discard
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Discard = 0x800000;

/**
  * @default 0x01000000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Help
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Help = 0x1000000;

/**
  * @default 0x02000000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Apply
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Apply = 0x2000000;

/**
  * @default 0x04000000
  * @constant
  * @memberOf QDialogButtonBox
  * @name Reset
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.Reset = 0x4000000;

/**
  * @default 0x08000000
  * @constant
  * @memberOf QDialogButtonBox
  * @name RestoreDefaults
  * @see QDialogButtonBox#StandardButtons
  * @see QDialogButtonBox#StandardButton
  * @type Number
  */
QDialogButtonBox.RestoreDefaults = 0x8000000;

/**
  * @constructor 
  * @memberOf QDialogButtonBox
  * @name StandardButton
  */
QDialogButtonBox.StandardButton = function(value){;};

/**
  * @constructor 
  * @memberOf QDialogButtonBox
  * @name StandardButtons
  */
QDialogButtonBox.StandardButtons = function(value1, value2 /*, ...*/){;};


/**
  * @name addButton
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @param {QAbstractButton} button
  * @param {QMessageBox.ButtonRole} role
  * @returns {undefined}
  */
QDialogButtonBox.prototype.addButton = function(button, role){return undefined;};

/**
  * @name button
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @param {QMessageBox.StandardButton} which
  * @returns {QPushButton}
  */
QDialogButtonBox.prototype.button = function(which){return new QPushButton();};

/**
  * @name buttonRole
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @param {QAbstractButton} button
  * @returns {QMessageBox.ButtonRole}
  */
QDialogButtonBox.prototype.buttonRole = function(button){return new QMessageBox.ButtonRole();};

/**
  * @name buttons
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @returns {Array}
  */
QDialogButtonBox.prototype.buttons = function(){return new Array();};

/**
  * @name clear
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @returns {undefined}
  */
QDialogButtonBox.prototype.clear = function(){return undefined;};

/**
  * @name removeButton
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @param {QAbstractButton} button
  * @returns {undefined}
  */
QDialogButtonBox.prototype.removeButton = function(button){return undefined;};

/**
  * @name standardButton
  * @function
  * @memberOf QDialogButtonBox.prototype
  * @param {QAbstractButton} button
  * @returns {QMessageBox.StandardButton}
  */
QDialogButtonBox.prototype.standardButton = function(button){return new QMessageBox.StandardButton();};

/**
  * @name orientation
  * @memberOf QDialogButtonBox.prototype
  * @type QPrinter.Orientation
  */
QDialogButtonBox.prototype.orientation = new QPrinter.Orientation();

/**
  * @name standardButtons
  * @memberOf QDialogButtonBox.prototype
  * @type QMessageBox.StandardButtons
  */
QDialogButtonBox.prototype.standardButtons = new QMessageBox.StandardButtons();

/**
  * @name centerButtons
  * @memberOf QDialogButtonBox.prototype
  * @type Boolean
  */
QDialogButtonBox.prototype.centerButtons = new Boolean();


