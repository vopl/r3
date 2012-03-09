/**
  * @name QLineEdit
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QLineEdit(parent){return undefined;};

/**
  * @name QLineEdit^1
  * @constructor
  * @extends QWidget
  * @param {String} arg__1
  * @param {QWidget} parent
  */
function QLineEdit(arg__1, parent){return undefined;};

QLineEdit.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QLineEdit
  * @name Normal
  * @see QLineEdit#EchoMode
  * @type Number
  */
QLineEdit.Normal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLineEdit
  * @name NoEcho
  * @see QLineEdit#EchoMode
  * @type Number
  */
QLineEdit.NoEcho = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QLineEdit
  * @name Password
  * @see QLineEdit#EchoMode
  * @type Number
  */
QLineEdit.Password = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QLineEdit
  * @name PasswordEchoOnEdit
  * @see QLineEdit#EchoMode
  * @type Number
  */
QLineEdit.PasswordEchoOnEdit = 0x3;

/**
  * @constructor 
  * @memberOf QLineEdit
  * @name EchoMode
  */
QLineEdit.EchoMode = function(value){;};



/**
  * @name backspace
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {undefined}
  */
QLineEdit.prototype.backspace = function(){return undefined;};

/**
  * @name completer
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {QCompleter}
  */
QLineEdit.prototype.completer = function(){return new QCompleter();};

/**
  * @name createStandardContextMenu
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {QMenu}
  */
QLineEdit.prototype.createStandardContextMenu = function(){return new QMenu();};

/**
  * @name cursorBackward
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Boolean} mark
  * @param {Numeric} steps
  * @returns {undefined}
  */
QLineEdit.prototype.cursorBackward = function(mark, steps){return undefined;};

/**
  * @name cursorForward
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Boolean} mark
  * @param {Numeric} steps
  * @returns {undefined}
  */
QLineEdit.prototype.cursorForward = function(mark, steps){return undefined;};

/**
  * @name cursorPositionAt
  * @function
  * @memberOf QLineEdit.prototype
  * @param {QPoint} pos
  * @returns {Numeric}
  */
QLineEdit.prototype.cursorPositionAt = function(pos){return new Numeric();};

/**
  * @name cursorWordBackward
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Boolean} mark
  * @returns {undefined}
  */
QLineEdit.prototype.cursorWordBackward = function(mark){return undefined;};

/**
  * @name cursorWordForward
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Boolean} mark
  * @returns {undefined}
  */
QLineEdit.prototype.cursorWordForward = function(mark){return undefined;};

/**
  * @name del
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {undefined}
  */
QLineEdit.prototype.del = function(){return undefined;};

/**
  * @name deselect
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {undefined}
  */
QLineEdit.prototype.deselect = function(){return undefined;};

/**
  * @name end
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Boolean} mark
  * @returns {undefined}
  */
QLineEdit.prototype.end = function(mark){return undefined;};

/**
  * @name getTextMargins
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @returns {undefined}
  */
QLineEdit.prototype.getTextMargins = function(left, top, right, bottom){return undefined;};

/**
  * @name home
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Boolean} mark
  * @returns {undefined}
  */
QLineEdit.prototype.home = function(mark){return undefined;};

/**
  * @name insert
  * @function
  * @memberOf QLineEdit.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QLineEdit.prototype.insert = function(arg__1){return undefined;};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {QSize}
  */
QLineEdit.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name selectionStart
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {Numeric}
  */
QLineEdit.prototype.selectionStart = function(){return new Numeric();};

/**
  * @name setCompleter
  * @function
  * @memberOf QLineEdit.prototype
  * @param {QCompleter} completer
  * @returns {undefined}
  */
QLineEdit.prototype.setCompleter = function(completer){return undefined;};

/**
  * @name setSelection
  * @function
  * @memberOf QLineEdit.prototype
  * @param {Numeric} arg__1
  * @param {Numeric} arg__2
  * @returns {undefined}
  */
QLineEdit.prototype.setSelection = function(arg__1, arg__2){return undefined;};

/**
  * @name setTextMargins
  * @function
  * @memberOf QLineEdit.prototype
  * @param {QMargins} margins
  * @returns {undefined}
  */
QLineEdit.prototype.setTextMargins = function(margins){return undefined;};

/**
  * @name setValidator
  * @function
  * @memberOf QLineEdit.prototype
  * @param {QValidator} arg__1
  * @returns {undefined}
  */
QLineEdit.prototype.setValidator = function(arg__1){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {QSize}
  */
QLineEdit.prototype.sizeHint = function(){return new QSize();};

/**
  * @name textMargins
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {QMargins}
  */
QLineEdit.prototype.textMargins = function(){return new QMargins();};

/**
  * @name validator
  * @function
  * @memberOf QLineEdit.prototype
  * @returns {QValidator}
  */
QLineEdit.prototype.validator = function(){return new QValidator();};

/**
  * @name inputMask
  * @memberOf QLineEdit.prototype
  * @type String
  */
QLineEdit.prototype.inputMask = new String();

/**
  * @name text
  * @memberOf QLineEdit.prototype
  * @type String
  */
QLineEdit.prototype.text = new String();

/**
  * @name maxLength
  * @memberOf QLineEdit.prototype
  * @type Numeric
  */
QLineEdit.prototype.maxLength = new Numeric();

/**
  * @name frame
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.frame = new Boolean();

/**
  * @name echoMode
  * @memberOf QLineEdit.prototype
  * @type QLineEdit.EchoMode
  */
QLineEdit.prototype.echoMode = new QLineEdit.EchoMode();

/**
  * @name displayText
  * @memberOf QLineEdit.prototype
  * @type String
  */
QLineEdit.prototype.displayText = new String();

/**
  * @name cursorPosition
  * @memberOf QLineEdit.prototype
  * @type Numeric
  */
QLineEdit.prototype.cursorPosition = new Numeric();

/**
  * @name alignment
  * @memberOf QLineEdit.prototype
  * @type Qt.Alignment
  */
QLineEdit.prototype.alignment = new Qt.Alignment();

/**
  * @name modified
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.modified = new Boolean();

/**
  * @name hasSelectedText
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.hasSelectedText = new Boolean();

/**
  * @name selectedText
  * @memberOf QLineEdit.prototype
  * @type String
  */
QLineEdit.prototype.selectedText = new String();

/**
  * @name dragEnabled
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.dragEnabled = new Boolean();

/**
  * @name readOnly
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.readOnly = new Boolean();

/**
  * @name undoAvailable
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.undoAvailable = new Boolean();

/**
  * @name redoAvailable
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.redoAvailable = new Boolean();

/**
  * @name acceptableInput
  * @memberOf QLineEdit.prototype
  * @type Boolean
  */
QLineEdit.prototype.acceptableInput = new Boolean();

/**
  * @name placeholderText
  * @memberOf QLineEdit.prototype
  * @type String
  */
QLineEdit.prototype.placeholderText = new String();


