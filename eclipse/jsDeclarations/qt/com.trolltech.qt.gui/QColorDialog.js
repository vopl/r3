/**
  * @name QColorDialog
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  */
function QColorDialog(parent){return undefined;};

/**
  * @name QColorDialog^1
  * @constructor
  * @extends QDialog
  * @param {QColor} initial
  * @param {QWidget} parent
  */
function QColorDialog(initial, parent){return undefined;};

QColorDialog.prototype = new QDialog();

/**
  * @name customColor
  * @function
  * @memberOf QColorDialog
  * @param {Numeric} index
  * @returns {Numeric}
  */
QColorDialog.customColor = function(index){return new Numeric();};

/**
  * @name customCount
  * @function
  * @memberOf QColorDialog
  * @returns {Numeric}
  */
QColorDialog.customCount = function(){return new Numeric();};

/**
  * @name getColor
  * @function
  * @memberOf QColorDialog
  * @param {QColor} initial
  * @param {QWidget} parent
  * @returns {QColor}
  */
QColorDialog.getColor = function(initial, parent){return new QColor();};

/**
  * @name setCustomColor
  * @function
  * @memberOf QColorDialog
  * @param {Numeric} index
  * @param {Numeric} color
  * @returns {undefined}
  */
QColorDialog.setCustomColor = function(index, color){return undefined;};

/**
  * @name setStandardColor
  * @function
  * @memberOf QColorDialog
  * @param {Numeric} index
  * @param {Numeric} color
  * @returns {undefined}
  */
QColorDialog.setStandardColor = function(index, color){return undefined;};

/**
  * @default 0x00000001
  * @constant
  * @memberOf QColorDialog
  * @name ShowAlphaChannel
  * @see QColorDialog#ColorDialogOptions
  * @see QColorDialog#ColorDialogOption
  * @type Number
  */
QColorDialog.ShowAlphaChannel = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QColorDialog
  * @name NoButtons
  * @see QColorDialog#ColorDialogOptions
  * @see QColorDialog#ColorDialogOption
  * @type Number
  */
QColorDialog.NoButtons = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QColorDialog
  * @name DontUseNativeDialog
  * @see QColorDialog#ColorDialogOptions
  * @see QColorDialog#ColorDialogOption
  * @type Number
  */
QColorDialog.DontUseNativeDialog = 0x4;

/**
  * @constructor 
  * @memberOf QColorDialog
  * @name ColorDialogOption
  */
QColorDialog.ColorDialogOption = function(value){;};

/**
  * @constructor 
  * @memberOf QColorDialog
  * @name ColorDialogOptions
  */
QColorDialog.ColorDialogOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name open
  * @function
  * @memberOf QColorDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QColorDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name selectedColor
  * @function
  * @memberOf QColorDialog.prototype
  * @returns {QColor}
  */
QColorDialog.prototype.selectedColor = function(){return new QColor();};

/**
  * @name setCurrentColor
  * @function
  * @memberOf QColorDialog.prototype
  * @param {QColor} color
  * @returns {undefined}
  */
QColorDialog.prototype.setCurrentColor = function(color){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QColorDialog.prototype
  * @param {QColorDialog.ColorDialogOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QColorDialog.prototype.setOption = function(option, on){return undefined;};

/**
  * @name testOption
  * @function
  * @memberOf QColorDialog.prototype
  * @param {QColorDialog.ColorDialogOption} option
  * @returns {Boolean}
  */
QColorDialog.prototype.testOption = function(option){return new Boolean();};

/**
  * @name currentColor
  * @memberOf QColorDialog.prototype
  * @type QColor
  */
QColorDialog.prototype.currentColor = new QColor();

/**
  * @name options
  * @memberOf QColorDialog.prototype
  * @type QColorDialog.ColorDialogOptions
  */
QColorDialog.prototype.options = new QColorDialog.ColorDialogOptions();


