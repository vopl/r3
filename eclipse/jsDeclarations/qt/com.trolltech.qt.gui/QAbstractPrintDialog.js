/**
  * @name QAbstractPrintDialog
  * @constructor
  * @extends QDialog
  * @param {QPrinter} printer
  * @param {QWidget} parent
  */
function QAbstractPrintDialog(printer, parent){return undefined;};

QAbstractPrintDialog.prototype = new QDialog();

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name AllPages
  * @see QAbstractPrintDialog#PrintRange
  * @type Number
  */
QAbstractPrintDialog.AllPages = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name Selection
  * @see QAbstractPrintDialog#PrintRange
  * @type Number
  */
QAbstractPrintDialog.Selection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PageRange
  * @see QAbstractPrintDialog#PrintRange
  * @type Number
  */
QAbstractPrintDialog.PageRange = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name CurrentPage
  * @see QAbstractPrintDialog#PrintRange
  * @type Number
  */
QAbstractPrintDialog.CurrentPage = 0x3;

/**
  * @constructor 
  * @memberOf QAbstractPrintDialog
  * @name PrintRange
  */
QAbstractPrintDialog.PrintRange = function(value){;};



/**
  * @default 0x0000
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name None
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.None = 0x0;

/**
  * @default 0x0001
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PrintToFile
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.PrintToFile = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PrintSelection
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.PrintSelection = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PrintPageRange
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.PrintPageRange = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PrintShowPageSize
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.PrintShowPageSize = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PrintCollateCopies
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.PrintCollateCopies = 0x10;

/**
  * @default 0x0020
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name DontUseSheet
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.DontUseSheet = 0x20;

/**
  * @default 0x0040
  * @constant
  * @memberOf QAbstractPrintDialog
  * @name PrintCurrentPage
  * @see QAbstractPrintDialog#PrintDialogOptions
  * @see QAbstractPrintDialog#PrintDialogOption
  * @type Number
  */
QAbstractPrintDialog.PrintCurrentPage = 0x40;

/**
  * @constructor 
  * @memberOf QAbstractPrintDialog
  * @name PrintDialogOption
  */
QAbstractPrintDialog.PrintDialogOption = function(value){;};

/**
  * @constructor 
  * @memberOf QAbstractPrintDialog
  * @name PrintDialogOptions
  */
QAbstractPrintDialog.PrintDialogOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name addEnabledOption
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {QAbstractPrintDialog.PrintDialogOption} option
  * @returns {undefined}
  */
QAbstractPrintDialog.prototype.addEnabledOption = function(option){return undefined;};

/**
  * @name enabledOptions
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {QAbstractPrintDialog.PrintDialogOptions}
  */
QAbstractPrintDialog.prototype.enabledOptions = function(){return new QAbstractPrintDialog.PrintDialogOptions();};

/**
  * @name fromPage
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {Numeric}
  */
QAbstractPrintDialog.prototype.fromPage = function(){return new Numeric();};

/**
  * @name isOptionEnabled
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {QAbstractPrintDialog.PrintDialogOption} option
  * @returns {Boolean}
  */
QAbstractPrintDialog.prototype.isOptionEnabled = function(option){return new Boolean();};

/**
  * @name maxPage
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {Numeric}
  */
QAbstractPrintDialog.prototype.maxPage = function(){return new Numeric();};

/**
  * @name minPage
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {Numeric}
  */
QAbstractPrintDialog.prototype.minPage = function(){return new Numeric();};

/**
  * @name printRange
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {QAbstractPrintDialog.PrintRange}
  */
QAbstractPrintDialog.prototype.printRange = function(){return new QAbstractPrintDialog.PrintRange();};

/**
  * @name printer
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {QPrinter}
  */
QAbstractPrintDialog.prototype.printer = function(){return new QPrinter();};

/**
  * @name setEnabledOptions
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {QAbstractPrintDialog.PrintDialogOptions} options
  * @returns {undefined}
  */
QAbstractPrintDialog.prototype.setEnabledOptions = function(options){return undefined;};

/**
  * @name setFromTo
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {Numeric} fromPage
  * @param {Numeric} toPage
  * @returns {undefined}
  */
QAbstractPrintDialog.prototype.setFromTo = function(fromPage, toPage){return undefined;};

/**
  * @name setMinMax
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {Numeric} min
  * @param {Numeric} max
  * @returns {undefined}
  */
QAbstractPrintDialog.prototype.setMinMax = function(min, max){return undefined;};

/**
  * @name setOptionTabs
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {Array} tabs
  * @returns {undefined}
  */
QAbstractPrintDialog.prototype.setOptionTabs = function(tabs){return undefined;};

/**
  * @name setPrintRange
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @param {QAbstractPrintDialog.PrintRange} range
  * @returns {undefined}
  */
QAbstractPrintDialog.prototype.setPrintRange = function(range){return undefined;};

/**
  * @name toPage
  * @function
  * @memberOf QAbstractPrintDialog.prototype
  * @returns {Numeric}
  */
QAbstractPrintDialog.prototype.toPage = function(){return new Numeric();};

