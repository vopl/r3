/**
  * @name QFontDialog
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  */
function QFontDialog(parent){return undefined;};

/**
  * @name QFontDialog^1
  * @constructor
  * @extends QDialog
  * @param {QFont} initial
  * @param {QWidget} parent
  */
function QFontDialog(initial, parent){return undefined;};

QFontDialog.prototype = new QDialog();

/**
  * @name getFont
  * @function
  * @memberOf QFontDialog
  * @param {Boolean} ok
  * @param {QWidget} parent
  * @returns {QFont}
  */
QFontDialog.getFont = function(ok, parent){return new QFont();};

/**
  * @default 0x00000001
  * @constant
  * @memberOf QFontDialog
  * @name NoButtons
  * @see QFontDialog#FontDialogOptions
  * @see QFontDialog#FontDialogOption
  * @type Number
  */
QFontDialog.NoButtons = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QFontDialog
  * @name DontUseNativeDialog
  * @see QFontDialog#FontDialogOptions
  * @see QFontDialog#FontDialogOption
  * @type Number
  */
QFontDialog.DontUseNativeDialog = 0x2;

/**
  * @constructor 
  * @memberOf QFontDialog
  * @name FontDialogOption
  */
QFontDialog.FontDialogOption = function(value){;};

/**
  * @constructor 
  * @memberOf QFontDialog
  * @name FontDialogOptions
  */
QFontDialog.FontDialogOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name open
  * @function
  * @memberOf QFontDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QFontDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name selectedFont
  * @function
  * @memberOf QFontDialog.prototype
  * @returns {QFont}
  */
QFontDialog.prototype.selectedFont = function(){return new QFont();};

/**
  * @name setOption
  * @function
  * @memberOf QFontDialog.prototype
  * @param {QFontDialog.FontDialogOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QFontDialog.prototype.setOption = function(option, on){return undefined;};

/**
  * @name testOption
  * @function
  * @memberOf QFontDialog.prototype
  * @param {QFontDialog.FontDialogOption} option
  * @returns {Boolean}
  */
QFontDialog.prototype.testOption = function(option){return new Boolean();};

/**
  * @name currentFont
  * @memberOf QFontDialog.prototype
  * @type QFont
  */
QFontDialog.prototype.currentFont = new QFont();

/**
  * @name options
  * @memberOf QFontDialog.prototype
  * @type QFontDialog.FontDialogOptions
  */
QFontDialog.prototype.options = new QFontDialog.FontDialogOptions();


