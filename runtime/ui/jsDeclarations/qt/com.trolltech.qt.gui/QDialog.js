/**
  * @name QDialog
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QDialog(parent, f){return undefined;};

QDialog.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QDialog
  * @name Rejected
  * @see QDialog#DialogCode
  * @type Number
  */
QDialog.Rejected = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDialog
  * @name Accepted
  * @see QDialog#DialogCode
  * @type Number
  */
QDialog.Accepted = 0x1;

/**
  * @constructor 
  * @memberOf QDialog
  * @name DialogCode
  */
QDialog.DialogCode = function(value){;};



/**
  * @name minimumSizeHint
  * @function
  * @memberOf QDialog.prototype
  * @returns {QSize}
  */
QDialog.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name result
  * @function
  * @memberOf QDialog.prototype
  * @returns {Numeric}
  */
QDialog.prototype.result = function(){return new Numeric();};

/**
  * @name setResult
  * @function
  * @memberOf QDialog.prototype
  * @param {Numeric} r
  * @returns {undefined}
  */
QDialog.prototype.setResult = function(r){return undefined;};

/**
  * @name setVisible
  * @function
  * @memberOf QDialog.prototype
  * @param {Boolean} visible
  * @returns {undefined}
  */
QDialog.prototype.setVisible = function(visible){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QDialog.prototype
  * @returns {QSize}
  */
QDialog.prototype.sizeHint = function(){return new QSize();};

/**
  * @name sizeGripEnabled
  * @memberOf QDialog.prototype
  * @type Boolean
  */
QDialog.prototype.sizeGripEnabled = new Boolean();

/**
  * @name modal
  * @memberOf QDialog.prototype
  * @type Boolean
  */
QDialog.prototype.modal = new Boolean();


