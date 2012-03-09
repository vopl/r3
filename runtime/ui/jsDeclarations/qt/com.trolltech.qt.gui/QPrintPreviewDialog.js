/**
  * @name QPrintPreviewDialog
  * @constructor
  * @extends QDialog
  * @param {QPrinter} printer
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QPrintPreviewDialog(printer, parent, flags){return undefined;};

/**
  * @name QPrintPreviewDialog^1
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QPrintPreviewDialog(parent, flags){return undefined;};

QPrintPreviewDialog.prototype = new QDialog();

/**
  * @name open
  * @function
  * @memberOf QPrintPreviewDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QPrintPreviewDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name printer
  * @function
  * @memberOf QPrintPreviewDialog.prototype
  * @returns {QPrinter}
  */
QPrintPreviewDialog.prototype.printer = function(){return new QPrinter();};

