/**
  * @name QAbstractPageSetupDialog
  * @constructor
  * @extends QDialog
  * @param {QPrinter} printer
  * @param {QWidget} parent
  */
function QAbstractPageSetupDialog(printer, parent){return undefined;};

QAbstractPageSetupDialog.prototype = new QDialog();

/**
  * @name printer
  * @function
  * @memberOf QAbstractPageSetupDialog.prototype
  * @returns {QPrinter}
  */
QAbstractPageSetupDialog.prototype.printer = function(){return new QPrinter();};

