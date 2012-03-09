/**
  * @name QPlainTextEdit
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QWidget} parent
  */
function QPlainTextEdit(parent){return undefined;};

/**
  * @name QPlainTextEdit^1
  * @constructor
  * @extends QAbstractScrollArea
  * @param {String} text
  * @param {QWidget} parent
  */
function QPlainTextEdit(text, parent){return undefined;};

QPlainTextEdit.prototype = new QAbstractScrollArea();

/**
  * @default 0x0
  * @constant
  * @memberOf QPlainTextEdit
  * @name NoWrap
  * @see QPlainTextEdit#LineWrapMode
  * @type Number
  */
QPlainTextEdit.NoWrap = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPlainTextEdit
  * @name WidgetWidth
  * @see QPlainTextEdit#LineWrapMode
  * @type Number
  */
QPlainTextEdit.WidgetWidth = 0x1;

/**
  * @constructor 
  * @memberOf QPlainTextEdit
  * @name LineWrapMode
  */
QPlainTextEdit.LineWrapMode = function(value){;};



/**
  * @name anchorAt
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QPoint} pos
  * @returns {String}
  */
QPlainTextEdit.prototype.anchorAt = function(pos){return new String();};

/**
  * @name canPaste
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {Boolean}
  */
QPlainTextEdit.prototype.canPaste = function(){return new Boolean();};

/**
  * @name createStandardContextMenu
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {QMenu}
  */
QPlainTextEdit.prototype.createStandardContextMenu = function(){return new QMenu();};

/**
  * @name currentCharFormat
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {QTextCharFormat}
  */
QPlainTextEdit.prototype.currentCharFormat = function(){return new QTextCharFormat();};

/**
  * @name cursorForPosition
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QPoint} pos
  * @returns {QTextCursor}
  */
QPlainTextEdit.prototype.cursorForPosition = function(pos){return new QTextCursor();};

/**
  * @name cursorRect
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {QRect}
  */
QPlainTextEdit.prototype.cursorRect = function(){return new QRect();};

/**
  * @name document
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {QTextDocument}
  */
QPlainTextEdit.prototype.document = function(){return new QTextDocument();};

/**
  * @name ensureCursorVisible
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {undefined}
  */
QPlainTextEdit.prototype.ensureCursorVisible = function(){return undefined;};

/**
  * @name extraSelections
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {Array}
  */
QPlainTextEdit.prototype.extraSelections = function(){return new Array();};

/**
  * @name find
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {String} exp
  * @param {QWebPage.FindFlags} options
  * @returns {Boolean}
  */
QPlainTextEdit.prototype.find = function(exp, options){return new Boolean();};

/**
  * @name loadResource
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {Numeric} type
  * @param {QUrl} name
  * @returns {Object}
  */
QPlainTextEdit.prototype.loadResource = function(type, name){return new Object();};

/**
  * @name mergeCurrentCharFormat
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QTextCharFormat} modifier
  * @returns {undefined}
  */
QPlainTextEdit.prototype.mergeCurrentCharFormat = function(modifier){return undefined;};

/**
  * @name moveCursor
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QTextCursor.MoveOperation} operation
  * @param {QTextCursor.MoveMode} mode
  * @returns {undefined}
  */
QPlainTextEdit.prototype.moveCursor = function(operation, mode){return undefined;};

/**
  * @name print
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QPrinter} printer
  * @returns {undefined}
  */
QPlainTextEdit.prototype.print = function(printer){return undefined;};

/**
  * @name setCurrentCharFormat
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QPlainTextEdit.prototype.setCurrentCharFormat = function(format){return undefined;};

/**
  * @name setDocument
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QTextDocument} document
  * @returns {undefined}
  */
QPlainTextEdit.prototype.setDocument = function(document){return undefined;};

/**
  * @name setExtraSelections
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {Array} selections
  * @returns {undefined}
  */
QPlainTextEdit.prototype.setExtraSelections = function(selections){return undefined;};

/**
  * @name setTextCursor
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {QTextCursor} cursor
  * @returns {undefined}
  */
QPlainTextEdit.prototype.setTextCursor = function(cursor){return undefined;};

/**
  * @name setWordWrapMode
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @param {Numeric} policy
  * @returns {undefined}
  */
QPlainTextEdit.prototype.setWordWrapMode = function(policy){return undefined;};

/**
  * @name textCursor
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {QTextCursor}
  */
QPlainTextEdit.prototype.textCursor = function(){return new QTextCursor();};

/**
  * @name wordWrapMode
  * @function
  * @memberOf QPlainTextEdit.prototype
  * @returns {Numeric}
  */
QPlainTextEdit.prototype.wordWrapMode = function(){return new Numeric();};

/**
  * @name tabChangesFocus
  * @memberOf QPlainTextEdit.prototype
  * @type Boolean
  */
QPlainTextEdit.prototype.tabChangesFocus = new Boolean();

/**
  * @name documentTitle
  * @memberOf QPlainTextEdit.prototype
  * @type String
  */
QPlainTextEdit.prototype.documentTitle = new String();

/**
  * @name undoRedoEnabled
  * @memberOf QPlainTextEdit.prototype
  * @type Boolean
  */
QPlainTextEdit.prototype.undoRedoEnabled = new Boolean();

/**
  * @name lineWrapMode
  * @memberOf QPlainTextEdit.prototype
  * @type QPlainTextEdit.LineWrapMode
  */
QPlainTextEdit.prototype.lineWrapMode = new QPlainTextEdit.LineWrapMode();

/**
  * @name readOnly
  * @memberOf QPlainTextEdit.prototype
  * @type Boolean
  */
QPlainTextEdit.prototype.readOnly = new Boolean();

/**
  * @name plainText
  * @memberOf QPlainTextEdit.prototype
  * @type String
  */
QPlainTextEdit.prototype.plainText = new String();

/**
  * @name overwriteMode
  * @memberOf QPlainTextEdit.prototype
  * @type Boolean
  */
QPlainTextEdit.prototype.overwriteMode = new Boolean();

/**
  * @name tabStopWidth
  * @memberOf QPlainTextEdit.prototype
  * @type Numeric
  */
QPlainTextEdit.prototype.tabStopWidth = new Numeric();

/**
  * @name cursorWidth
  * @memberOf QPlainTextEdit.prototype
  * @type Numeric
  */
QPlainTextEdit.prototype.cursorWidth = new Numeric();

/**
  * @name textInteractionFlags
  * @memberOf QPlainTextEdit.prototype
  * @type Qt.TextInteractionFlags
  */
QPlainTextEdit.prototype.textInteractionFlags = new Qt.TextInteractionFlags();

/**
  * @name blockCount
  * @memberOf QPlainTextEdit.prototype
  * @type Numeric
  */
QPlainTextEdit.prototype.blockCount = new Numeric();

/**
  * @name maximumBlockCount
  * @memberOf QPlainTextEdit.prototype
  * @type Numeric
  */
QPlainTextEdit.prototype.maximumBlockCount = new Numeric();

/**
  * @name backgroundVisible
  * @memberOf QPlainTextEdit.prototype
  * @type Boolean
  */
QPlainTextEdit.prototype.backgroundVisible = new Boolean();

/**
  * @name centerOnScroll
  * @memberOf QPlainTextEdit.prototype
  * @type Boolean
  */
QPlainTextEdit.prototype.centerOnScroll = new Boolean();


