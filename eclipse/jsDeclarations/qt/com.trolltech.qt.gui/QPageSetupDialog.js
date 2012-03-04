/**
  * @name QPageSetupDialog
  * @constructor
  * @extends QAbstractPageSetupDialog
  * @param {QPrinter} printer
  * @param {QWidget} parent
  */
function QPageSetupDialog(printer, parent){return undefined;};

/**
  * @name QPageSetupDialog^1
  * @constructor
  * @extends QAbstractPageSetupDialog
  * @param {QWidget} parent
  */
function QPageSetupDialog(parent){return undefined;};

QPageSetupDialog.prototype = new QAbstractPageSetupDialog();

/**
  * @default 0x80000000
  * @constant
  * @memberOf QPageSetupDialog
  * @name OwnsPrinter
  * @see QPageSetupDialog#PageSetupDialogOptions
  * @see QPageSetupDialog#PageSetupDialogOption
  * @type Number
  */
QPageSetupDialog.OwnsPrinter = 0x80000000;

/**
  * @default 0x00000000
  * @constant
  * @memberOf QPageSetupDialog
  * @name None
  * @see QPageSetupDialog#PageSetupDialogOptions
  * @see QPageSetupDialog#PageSetupDialogOption
  * @type Number
  */
QPageSetupDialog.None = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QPageSetupDialog
  * @name DontUseSheet
  * @see QPageSetupDialog#PageSetupDialogOptions
  * @see QPageSetupDialog#PageSetupDialogOption
  * @type Number
  */
QPageSetupDialog.DontUseSheet = 0x1;

/**
  * @constructor 
  * @memberOf QPageSetupDialog
  * @name PageSetupDialogOption
  */
QPageSetupDialog.PageSetupDialogOption = function(value){;};

/**
  * @constructor 
  * @memberOf QPageSetupDialog
  * @name PageSetupDialogOptions
  */
QPageSetupDialog.PageSetupDialogOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name addEnabledOption
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @param {QPageSetupDialog.PageSetupDialogOption} option
  * @returns {undefined}
  */
QPageSetupDialog.prototype.addEnabledOption = function(option){return undefined;};

/**
  * @name enabledOptions
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @returns {QPageSetupDialog.PageSetupDialogOptions}
  */
QPageSetupDialog.prototype.enabledOptions = function(){return new QPageSetupDialog.PageSetupDialogOptions();};

/**
  * @name isOptionEnabled
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @param {QPageSetupDialog.PageSetupDialogOption} option
  * @returns {Boolean}
  */
QPageSetupDialog.prototype.isOptionEnabled = function(option){return new Boolean();};

/**
  * @name open
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QPageSetupDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name setEnabledOptions
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @param {QPageSetupDialog.PageSetupDialogOptions} options
  * @returns {undefined}
  */
QPageSetupDialog.prototype.setEnabledOptions = function(options){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @param {QPageSetupDialog.PageSetupDialogOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QPageSetupDialog.prototype.setOption = function(option, on){return undefined;};

/**
  * @name testOption
  * @function
  * @memberOf QPageSetupDialog.prototype
  * @param {QPageSetupDialog.PageSetupDialogOption} option
  * @returns {Boolean}
  */
QPageSetupDialog.prototype.testOption = function(option){return new Boolean();};

/**
  * @name options
  * @memberOf QPageSetupDialog.prototype
  * @type QPageSetupDialog.PageSetupDialogOptions
  */
QPageSetupDialog.prototype.options = new QPageSetupDialog.PageSetupDialogOptions();


