/**
  * @name QProgressDialog
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QProgressDialog(parent, flags){return undefined;};

/**
  * @name QProgressDialog^1
  * @constructor
  * @extends QDialog
  * @param {String} labelText
  * @param {String} cancelButtonText
  * @param {Numeric} minimum
  * @param {Numeric} maximum
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QProgressDialog(labelText, cancelButtonText, minimum, maximum, parent, flags){return undefined;};

QProgressDialog.prototype = new QDialog();

/**
  * @name open
  * @function
  * @memberOf QProgressDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QProgressDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name setBar
  * @function
  * @memberOf QProgressDialog.prototype
  * @param {QProgressBar} bar
  * @returns {undefined}
  */
QProgressDialog.prototype.setBar = function(bar){return undefined;};

/**
  * @name setCancelButton
  * @function
  * @memberOf QProgressDialog.prototype
  * @param {QPushButton} button
  * @returns {undefined}
  */
QProgressDialog.prototype.setCancelButton = function(button){return undefined;};

/**
  * @name setLabel
  * @function
  * @memberOf QProgressDialog.prototype
  * @param {QLabel} label
  * @returns {undefined}
  */
QProgressDialog.prototype.setLabel = function(label){return undefined;};

/**
  * @name wasCanceled
  * @memberOf QProgressDialog.prototype
  * @type Boolean
  */
QProgressDialog.prototype.wasCanceled = new Boolean();

/**
  * @name minimum
  * @memberOf QProgressDialog.prototype
  * @type Numeric
  */
QProgressDialog.prototype.minimum = new Numeric();

/**
  * @name maximum
  * @memberOf QProgressDialog.prototype
  * @type Numeric
  */
QProgressDialog.prototype.maximum = new Numeric();

/**
  * @name value
  * @memberOf QProgressDialog.prototype
  * @type Numeric
  */
QProgressDialog.prototype.value = new Numeric();

/**
  * @name autoReset
  * @memberOf QProgressDialog.prototype
  * @type Boolean
  */
QProgressDialog.prototype.autoReset = new Boolean();

/**
  * @name autoClose
  * @memberOf QProgressDialog.prototype
  * @type Boolean
  */
QProgressDialog.prototype.autoClose = new Boolean();

/**
  * @name minimumDuration
  * @memberOf QProgressDialog.prototype
  * @type Numeric
  */
QProgressDialog.prototype.minimumDuration = new Numeric();

/**
  * @name labelText
  * @memberOf QProgressDialog.prototype
  * @type String
  */
QProgressDialog.prototype.labelText = new String();


