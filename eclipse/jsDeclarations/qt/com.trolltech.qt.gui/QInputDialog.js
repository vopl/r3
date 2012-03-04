/**
  * @name QInputDialog
  * @constructor
  * @extends QDialog
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QInputDialog(parent, flags){return undefined;};

QInputDialog.prototype = new QDialog();

/**
  * @name getDouble
  * @function
  * @memberOf QInputDialog
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} label
  * @param {Numeric} value
  * @param {Numeric} minValue
  * @param {Numeric} maxValue
  * @param {Numeric} decimals
  * @param {Boolean} ok
  * @param {Qt.WindowFlags} flags
  * @returns {Numeric}
  */
QInputDialog.getDouble = function(parent, title, label, value, minValue, maxValue, decimals, ok, flags){return new Numeric();};

/**
  * @name getInt_private
  * @function
  * @memberOf QInputDialog
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} label
  * @param {Numeric} value
  * @param {Numeric} minValue
  * @param {Numeric} maxValue
  * @param {Numeric} step
  * @param {Boolean} ok
  * @param {Qt.WindowFlags} flags
  * @returns {Numeric}
  */
QInputDialog.getInt_private = function(parent, title, label, value, minValue, maxValue, step, ok, flags){return new Numeric();};

/**
  * @name getInteger
  * @function
  * @memberOf QInputDialog
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} label
  * @param {Numeric} value
  * @param {Numeric} minValue
  * @param {Numeric} maxValue
  * @param {Numeric} step
  * @param {Boolean} ok
  * @param {Qt.WindowFlags} flags
  * @returns {Numeric}
  */
QInputDialog.getInteger = function(parent, title, label, value, minValue, maxValue, step, ok, flags){return new Numeric();};

/**
  * @name getItem
  * @function
  * @memberOf QInputDialog
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} label
  * @param {Array} items
  * @param {Numeric} current
  * @param {Boolean} editable
  * @param {Boolean} ok
  * @param {Qt.WindowFlags} flags
  * @returns {String}
  */
QInputDialog.getItem = function(parent, title, label, items, current, editable, ok, flags){return new String();};

/**
  * @name getText
  * @function
  * @memberOf QInputDialog
  * @param {QWidget} parent
  * @param {String} title
  * @param {String} label
  * @param {QLineEdit.EchoMode} echo
  * @param {String} text
  * @param {Boolean} ok
  * @param {Qt.WindowFlags} flags
  * @returns {String}
  */
QInputDialog.getText = function(parent, title, label, echo, text, ok, flags){return new String();};

/**
  * @default 0x0
  * @constant
  * @memberOf QInputDialog
  * @name TextInput
  * @see QInputDialog#InputMode
  * @type Number
  */
QInputDialog.TextInput = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QInputDialog
  * @name IntInput
  * @see QInputDialog#InputMode
  * @type Number
  */
QInputDialog.IntInput = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QInputDialog
  * @name DoubleInput
  * @see QInputDialog#InputMode
  * @type Number
  */
QInputDialog.DoubleInput = 0x2;

/**
  * @constructor 
  * @memberOf QInputDialog
  * @name InputMode
  */
QInputDialog.InputMode = function(value){;};



/**
  * @default 0x00000001
  * @constant
  * @memberOf QInputDialog
  * @name NoButtons
  * @see QInputDialog#InputDialogOptions
  * @see QInputDialog#InputDialogOption
  * @type Number
  */
QInputDialog.NoButtons = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QInputDialog
  * @name UseListViewForComboBoxItems
  * @see QInputDialog#InputDialogOptions
  * @see QInputDialog#InputDialogOption
  * @type Number
  */
QInputDialog.UseListViewForComboBoxItems = 0x2;

/**
  * @constructor 
  * @memberOf QInputDialog
  * @name InputDialogOption
  */
QInputDialog.InputDialogOption = function(value){;};

/**
  * @constructor 
  * @memberOf QInputDialog
  * @name InputDialogOptions
  */
QInputDialog.InputDialogOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name cancelButtonText
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {String}
  */
QInputDialog.prototype.cancelButtonText = function(){return new String();};

/**
  * @name comboBoxItems
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Array}
  */
QInputDialog.prototype.comboBoxItems = function(){return new Array();};

/**
  * @name doubleDecimals
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.doubleDecimals = function(){return new Numeric();};

/**
  * @name doubleMaximum
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.doubleMaximum = function(){return new Numeric();};

/**
  * @name doubleMinimum
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.doubleMinimum = function(){return new Numeric();};

/**
  * @name doubleValue
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.doubleValue = function(){return new Numeric();};

/**
  * @name inputMode
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {QInputDialog.InputMode}
  */
QInputDialog.prototype.inputMode = function(){return new QInputDialog.InputMode();};

/**
  * @name intMaximum
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.intMaximum = function(){return new Numeric();};

/**
  * @name intMinimum
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.intMinimum = function(){return new Numeric();};

/**
  * @name intStep
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.intStep = function(){return new Numeric();};

/**
  * @name intValue
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Numeric}
  */
QInputDialog.prototype.intValue = function(){return new Numeric();};

/**
  * @name isComboBoxEditable
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {Boolean}
  */
QInputDialog.prototype.isComboBoxEditable = function(){return new Boolean();};

/**
  * @name labelText
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {String}
  */
QInputDialog.prototype.labelText = function(){return new String();};

/**
  * @name okButtonText
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {String}
  */
QInputDialog.prototype.okButtonText = function(){return new String();};

/**
  * @name open
  * @function
  * @memberOf QInputDialog.prototype
  * @param {QObject} receiver
  * @param {String} member
  * @returns {undefined}
  */
QInputDialog.prototype.open = function(receiver, member){return undefined;};

/**
  * @name options
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {QInputDialog.InputDialogOptions}
  */
QInputDialog.prototype.options = function(){return new QInputDialog.InputDialogOptions();};

/**
  * @name setCancelButtonText
  * @function
  * @memberOf QInputDialog.prototype
  * @param {String} text
  * @returns {undefined}
  */
QInputDialog.prototype.setCancelButtonText = function(text){return undefined;};

/**
  * @name setComboBoxEditable
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Boolean} editable
  * @returns {undefined}
  */
QInputDialog.prototype.setComboBoxEditable = function(editable){return undefined;};

/**
  * @name setComboBoxItems
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Array} items
  * @returns {undefined}
  */
QInputDialog.prototype.setComboBoxItems = function(items){return undefined;};

/**
  * @name setDoubleDecimals
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} decimals
  * @returns {undefined}
  */
QInputDialog.prototype.setDoubleDecimals = function(decimals){return undefined;};

/**
  * @name setDoubleMaximum
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} max
  * @returns {undefined}
  */
QInputDialog.prototype.setDoubleMaximum = function(max){return undefined;};

/**
  * @name setDoubleMinimum
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} min
  * @returns {undefined}
  */
QInputDialog.prototype.setDoubleMinimum = function(min){return undefined;};

/**
  * @name setDoubleRange
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} min
  * @param {Numeric} max
  * @returns {undefined}
  */
QInputDialog.prototype.setDoubleRange = function(min, max){return undefined;};

/**
  * @name setDoubleValue
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} value
  * @returns {undefined}
  */
QInputDialog.prototype.setDoubleValue = function(value){return undefined;};

/**
  * @name setInputMode
  * @function
  * @memberOf QInputDialog.prototype
  * @param {QInputDialog.InputMode} mode
  * @returns {undefined}
  */
QInputDialog.prototype.setInputMode = function(mode){return undefined;};

/**
  * @name setIntMaximum
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} max
  * @returns {undefined}
  */
QInputDialog.prototype.setIntMaximum = function(max){return undefined;};

/**
  * @name setIntMinimum
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} min
  * @returns {undefined}
  */
QInputDialog.prototype.setIntMinimum = function(min){return undefined;};

/**
  * @name setIntRange
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} min
  * @param {Numeric} max
  * @returns {undefined}
  */
QInputDialog.prototype.setIntRange = function(min, max){return undefined;};

/**
  * @name setIntStep
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} step
  * @returns {undefined}
  */
QInputDialog.prototype.setIntStep = function(step){return undefined;};

/**
  * @name setIntValue
  * @function
  * @memberOf QInputDialog.prototype
  * @param {Numeric} value
  * @returns {undefined}
  */
QInputDialog.prototype.setIntValue = function(value){return undefined;};

/**
  * @name setLabelText
  * @function
  * @memberOf QInputDialog.prototype
  * @param {String} text
  * @returns {undefined}
  */
QInputDialog.prototype.setLabelText = function(text){return undefined;};

/**
  * @name setOkButtonText
  * @function
  * @memberOf QInputDialog.prototype
  * @param {String} text
  * @returns {undefined}
  */
QInputDialog.prototype.setOkButtonText = function(text){return undefined;};

/**
  * @name setOption
  * @function
  * @memberOf QInputDialog.prototype
  * @param {QInputDialog.InputDialogOption} option
  * @param {Boolean} on
  * @returns {undefined}
  */
QInputDialog.prototype.setOption = function(option, on){return undefined;};

/**
  * @name setOptions
  * @function
  * @memberOf QInputDialog.prototype
  * @param {QInputDialog.InputDialogOptions} options
  * @returns {undefined}
  */
QInputDialog.prototype.setOptions = function(options){return undefined;};

/**
  * @name setTextEchoMode
  * @function
  * @memberOf QInputDialog.prototype
  * @param {QLineEdit.EchoMode} mode
  * @returns {undefined}
  */
QInputDialog.prototype.setTextEchoMode = function(mode){return undefined;};

/**
  * @name setTextValue
  * @function
  * @memberOf QInputDialog.prototype
  * @param {String} text
  * @returns {undefined}
  */
QInputDialog.prototype.setTextValue = function(text){return undefined;};

/**
  * @name testOption
  * @function
  * @memberOf QInputDialog.prototype
  * @param {QInputDialog.InputDialogOption} option
  * @returns {Boolean}
  */
QInputDialog.prototype.testOption = function(option){return new Boolean();};

/**
  * @name textEchoMode
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {QLineEdit.EchoMode}
  */
QInputDialog.prototype.textEchoMode = function(){return new QLineEdit.EchoMode();};

/**
  * @name textValue
  * @function
  * @memberOf QInputDialog.prototype
  * @returns {String}
  */
QInputDialog.prototype.textValue = function(){return new String();};

