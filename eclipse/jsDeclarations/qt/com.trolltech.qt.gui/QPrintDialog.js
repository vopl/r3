/**
  * @name QPrintDialog
  * @constructor
  * @extends QAbstractPrintDialog
  * @param {QPrinter} printer
  * @param {QWidget} parent
  */
function QPrintDialog(printer, parent){return undefined;};

/**
  * @name QPrintDialog^1
  * @constructor
  * @extends QAbstractPrintDialog
  * @param {QWidget} parent
  */
function QPrintDialog(parent){return undefined;};

QPrintDialog.prototype = new QAbstractPrintDialog();

/**
  * @name open
  * @function
  * @memberOf QPrintDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QPrintDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QPrintDialog.prototype
  * @param {QAbstractPrintDialog.PrintDialogOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QPrintDialog.prototype.setOption = function(option, on){return undefined;};

/**
  * @name testOption
  * @function
  * @memberOf QPrintDialog.prototype
  * @param {QAbstractPrintDialog.PrintDialogOption} option
  * @returns {Boolean}
  */
QPrintDialog.prototype.testOption = function(option){return new Boolean();};

/**
  * @name options
  * @memberOf QPrintDialog.prototype
  * @type QAbstractPrintDialog.PrintDialogOptions
  */
QPrintDialog.prototype.options = new QAbstractPrintDialog.PrintDialogOptions();


