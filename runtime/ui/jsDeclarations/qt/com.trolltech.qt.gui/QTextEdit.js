/**
  * @name QTextEdit
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QWidget} parent
  */
function QTextEdit(parent){return undefined;};

/**
  * @name QTextEdit^1
  * @constructor
  * @extends QAbstractScrollArea
  * @param {String} text
  * @param {QWidget} parent
  */
function QTextEdit(text, parent){return undefined;};

QTextEdit.prototype = new QAbstractScrollArea();

/**
  * @default 0xffffffff
  * @constant
  * @memberOf QTextEdit
  * @name AutoAll
  * @see QTextEdit#AutoFormatting
  * @see QTextEdit#AutoFormattingFlag
  * @type Number
  */
QTextEdit.AutoAll = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf QTextEdit
  * @name AutoNone
  * @see QTextEdit#AutoFormatting
  * @see QTextEdit#AutoFormattingFlag
  * @type Number
  */
QTextEdit.AutoNone = 0x0;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QTextEdit
  * @name AutoBulletList
  * @see QTextEdit#AutoFormatting
  * @see QTextEdit#AutoFormattingFlag
  * @type Number
  */
QTextEdit.AutoBulletList = 0x1;

/**
  * @constructor 
  * @memberOf QTextEdit
  * @name AutoFormattingFlag
  */
QTextEdit.AutoFormattingFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QTextEdit
  * @name AutoFormatting
  */
QTextEdit.AutoFormatting = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QTextEdit
  * @name NoWrap
  * @see QTextEdit#LineWrapMode
  * @type Number
  */
QTextEdit.NoWrap = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextEdit
  * @name WidgetWidth
  * @see QTextEdit#LineWrapMode
  * @type Number
  */
QTextEdit.WidgetWidth = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextEdit
  * @name FixedPixelWidth
  * @see QTextEdit#LineWrapMode
  * @type Number
  */
QTextEdit.FixedPixelWidth = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextEdit
  * @name FixedColumnWidth
  * @see QTextEdit#LineWrapMode
  * @type Number
  */
QTextEdit.FixedColumnWidth = 0x3;

/**
  * @constructor 
  * @memberOf QTextEdit
  * @name LineWrapMode
  */
QTextEdit.LineWrapMode = function(value){;};



/**
  * @name alignment
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Qt.Alignment}
  */
QTextEdit.prototype.alignment = function(){return new Qt.Alignment();};

/**
  * @name anchorAt
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QPoint} pos
  * @returns {String}
  */
QTextEdit.prototype.anchorAt = function(pos){return new String();};

/**
  * @name canPaste
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Boolean}
  */
QTextEdit.prototype.canPaste = function(){return new Boolean();};

/**
  * @name createStandardContextMenu
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QMenu}
  */
QTextEdit.prototype.createStandardContextMenu = function(){return new QMenu();};

/**
  * @name currentCharFormat
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QTextCharFormat}
  */
QTextEdit.prototype.currentCharFormat = function(){return new QTextCharFormat();};

/**
  * @name currentFont
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QFont}
  */
QTextEdit.prototype.currentFont = function(){return new QFont();};

/**
  * @name cursorForPosition
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QPoint} pos
  * @returns {QTextCursor}
  */
QTextEdit.prototype.cursorForPosition = function(pos){return new QTextCursor();};

/**
  * @name cursorRect
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QRect}
  */
QTextEdit.prototype.cursorRect = function(){return new QRect();};

/**
  * @name document
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QTextDocument}
  */
QTextEdit.prototype.document = function(){return new QTextDocument();};

/**
  * @name ensureCursorVisible
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {undefined}
  */
QTextEdit.prototype.ensureCursorVisible = function(){return undefined;};

/**
  * @name extraSelections
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Array}
  */
QTextEdit.prototype.extraSelections = function(){return new Array();};

/**
  * @name find
  * @function
  * @memberOf QTextEdit.prototype
  * @param {String} exp
  * @param {QWebPage.FindFlags} options
  * @returns {Boolean}
  */
QTextEdit.prototype.find = function(exp, options){return new Boolean();};

/**
  * @name fontFamily
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {String}
  */
QTextEdit.prototype.fontFamily = function(){return new String();};

/**
  * @name fontItalic
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Boolean}
  */
QTextEdit.prototype.fontItalic = function(){return new Boolean();};

/**
  * @name fontPointSize
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Numeric}
  */
QTextEdit.prototype.fontPointSize = function(){return new Numeric();};

/**
  * @name fontUnderline
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Boolean}
  */
QTextEdit.prototype.fontUnderline = function(){return new Boolean();};

/**
  * @name fontWeight
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Numeric}
  */
QTextEdit.prototype.fontWeight = function(){return new Numeric();};

/**
  * @name loadResource
  * @function
  * @memberOf QTextEdit.prototype
  * @param {Numeric} type
  * @param {QUrl} name
  * @returns {Object}
  */
QTextEdit.prototype.loadResource = function(type, name){return new Object();};

/**
  * @name mergeCurrentCharFormat
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QTextCharFormat} modifier
  * @returns {undefined}
  */
QTextEdit.prototype.mergeCurrentCharFormat = function(modifier){return undefined;};

/**
  * @name moveCursor
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QTextCursor.MoveOperation} operation
  * @param {QTextCursor.MoveMode} mode
  * @returns {undefined}
  */
QTextEdit.prototype.moveCursor = function(operation, mode){return undefined;};

/**
  * @name print
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QPrinter} printer
  * @returns {undefined}
  */
QTextEdit.prototype.print = function(printer){return undefined;};

/**
  * @name setCurrentCharFormat
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QTextEdit.prototype.setCurrentCharFormat = function(format){return undefined;};

/**
  * @name setDocument
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QTextDocument} document
  * @returns {undefined}
  */
QTextEdit.prototype.setDocument = function(document){return undefined;};

/**
  * @name setExtraSelections
  * @function
  * @memberOf QTextEdit.prototype
  * @param {Array} selections
  * @returns {undefined}
  */
QTextEdit.prototype.setExtraSelections = function(selections){return undefined;};

/**
  * @name setTextCursor
  * @function
  * @memberOf QTextEdit.prototype
  * @param {QTextCursor} cursor
  * @returns {undefined}
  */
QTextEdit.prototype.setTextCursor = function(cursor){return undefined;};

/**
  * @name setWordWrapMode
  * @function
  * @memberOf QTextEdit.prototype
  * @param {Numeric} policy
  * @returns {undefined}
  */
QTextEdit.prototype.setWordWrapMode = function(policy){return undefined;};

/**
  * @name textBackgroundColor
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QColor}
  */
QTextEdit.prototype.textBackgroundColor = function(){return new QColor();};

/**
  * @name textColor
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QColor}
  */
QTextEdit.prototype.textColor = function(){return new QColor();};

/**
  * @name textCursor
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {QTextCursor}
  */
QTextEdit.prototype.textCursor = function(){return new QTextCursor();};

/**
  * @name wordWrapMode
  * @function
  * @memberOf QTextEdit.prototype
  * @returns {Numeric}
  */
QTextEdit.prototype.wordWrapMode = function(){return new Numeric();};

/**
  * @name autoFormatting
  * @memberOf QTextEdit.prototype
  * @type QTextEdit.AutoFormatting
  */
QTextEdit.prototype.autoFormatting = new QTextEdit.AutoFormatting();

/**
  * @name tabChangesFocus
  * @memberOf QTextEdit.prototype
  * @type Boolean
  */
QTextEdit.prototype.tabChangesFocus = new Boolean();

/**
  * @name documentTitle
  * @memberOf QTextEdit.prototype
  * @type String
  */
QTextEdit.prototype.documentTitle = new String();

/**
  * @name undoRedoEnabled
  * @memberOf QTextEdit.prototype
  * @type Boolean
  */
QTextEdit.prototype.undoRedoEnabled = new Boolean();

/**
  * @name lineWrapMode
  * @memberOf QTextEdit.prototype
  * @type QPlainTextEdit.LineWrapMode
  */
QTextEdit.prototype.lineWrapMode = new QPlainTextEdit.LineWrapMode();

/**
  * @name lineWrapColumnOrWidth
  * @memberOf QTextEdit.prototype
  * @type Numeric
  */
QTextEdit.prototype.lineWrapColumnOrWidth = new Numeric();

/**
  * @name readOnly
  * @memberOf QTextEdit.prototype
  * @type Boolean
  */
QTextEdit.prototype.readOnly = new Boolean();

/**
  * @name html
  * @memberOf QTextEdit.prototype
  * @type String
  */
QTextEdit.prototype.html = new String();

/**
  * @name plainText
  * @memberOf QTextEdit.prototype
  * @type String
  */
QTextEdit.prototype.plainText = new String();

/**
  * @name overwriteMode
  * @memberOf QTextEdit.prototype
  * @type Boolean
  */
QTextEdit.prototype.overwriteMode = new Boolean();

/**
  * @name tabStopWidth
  * @memberOf QTextEdit.prototype
  * @type Numeric
  */
QTextEdit.prototype.tabStopWidth = new Numeric();

/**
  * @name acceptRichText
  * @memberOf QTextEdit.prototype
  * @type Boolean
  */
QTextEdit.prototype.acceptRichText = new Boolean();

/**
  * @name cursorWidth
  * @memberOf QTextEdit.prototype
  * @type Numeric
  */
QTextEdit.prototype.cursorWidth = new Numeric();

/**
  * @name textInteractionFlags
  * @memberOf QTextEdit.prototype
  * @type Qt.TextInteractionFlags
  */
QTextEdit.prototype.textInteractionFlags = new Qt.TextInteractionFlags();


