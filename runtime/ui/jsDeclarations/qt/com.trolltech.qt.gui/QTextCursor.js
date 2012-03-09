/**
  * @name QTextCursor
  * @constructor
  */
function QTextCursor(){return undefined;};

/**
  * @name QTextCursor^1
  * @constructor
  * @param {QTextDocument} document
  */
function QTextCursor(document){return undefined;};

/**
  * @name QTextCursor^2
  * @constructor
  * @param {QTextFrame} frame
  */
function QTextCursor(frame){return undefined;};

/**
  * @name QTextCursor^3
  * @constructor
  * @param {QTextBlock} block
  */
function QTextCursor(block){return undefined;};

/**
  * @name QTextCursor^4
  * @constructor
  * @param {QTextCursor} cursor
  */
function QTextCursor(cursor){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QTextCursor
  * @name MoveAnchor
  * @see QTextCursor#MoveMode
  * @type Number
  */
QTextCursor.MoveAnchor = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextCursor
  * @name KeepAnchor
  * @see QTextCursor#MoveMode
  * @type Number
  */
QTextCursor.KeepAnchor = 0x1;

/**
  * @constructor 
  * @memberOf QTextCursor
  * @name MoveMode
  */
QTextCursor.MoveMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTextCursor
  * @name NoMove
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.NoMove = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextCursor
  * @name Start
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.Start = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextCursor
  * @name Up
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.Up = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextCursor
  * @name StartOfLine
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.StartOfLine = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTextCursor
  * @name StartOfBlock
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.StartOfBlock = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTextCursor
  * @name StartOfWord
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.StartOfWord = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QTextCursor
  * @name PreviousBlock
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.PreviousBlock = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QTextCursor
  * @name PreviousCharacter
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.PreviousCharacter = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QTextCursor
  * @name PreviousWord
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.PreviousWord = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QTextCursor
  * @name Left
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.Left = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QTextCursor
  * @name WordLeft
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.WordLeft = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QTextCursor
  * @name End
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.End = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QTextCursor
  * @name Down
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.Down = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QTextCursor
  * @name EndOfLine
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.EndOfLine = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QTextCursor
  * @name EndOfWord
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.EndOfWord = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QTextCursor
  * @name EndOfBlock
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.EndOfBlock = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QTextCursor
  * @name NextBlock
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.NextBlock = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QTextCursor
  * @name NextCharacter
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.NextCharacter = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QTextCursor
  * @name NextWord
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.NextWord = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QTextCursor
  * @name Right
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.Right = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QTextCursor
  * @name WordRight
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.WordRight = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QTextCursor
  * @name NextCell
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.NextCell = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QTextCursor
  * @name PreviousCell
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.PreviousCell = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QTextCursor
  * @name NextRow
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.NextRow = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QTextCursor
  * @name PreviousRow
  * @see QTextCursor#MoveOperation
  * @type Number
  */
QTextCursor.PreviousRow = 0x18;

/**
  * @constructor 
  * @memberOf QTextCursor
  * @name MoveOperation
  */
QTextCursor.MoveOperation = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTextCursor
  * @name WordUnderCursor
  * @see QTextCursor#SelectionType
  * @type Number
  */
QTextCursor.WordUnderCursor = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextCursor
  * @name LineUnderCursor
  * @see QTextCursor#SelectionType
  * @type Number
  */
QTextCursor.LineUnderCursor = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextCursor
  * @name BlockUnderCursor
  * @see QTextCursor#SelectionType
  * @type Number
  */
QTextCursor.BlockUnderCursor = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextCursor
  * @name Document
  * @see QTextCursor#SelectionType
  * @type Number
  */
QTextCursor.Document = 0x3;

/**
  * @constructor 
  * @memberOf QTextCursor
  * @name SelectionType
  */
QTextCursor.SelectionType = function(value){;};



/**
  * @name anchor
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.anchor = function(){return new Numeric();};

/**
  * @name atBlockEnd
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.atBlockEnd = function(){return new Boolean();};

/**
  * @name atBlockStart
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.atBlockStart = function(){return new Boolean();};

/**
  * @name atEnd
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.atEnd = function(){return new Boolean();};

/**
  * @name atStart
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.atStart = function(){return new Boolean();};

/**
  * @name beginEditBlock
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.beginEditBlock = function(){return undefined;};

/**
  * @name block
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextBlock}
  */
QTextCursor.prototype.block = function(){return new QTextBlock();};

/**
  * @name blockCharFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextCharFormat}
  */
QTextCursor.prototype.blockCharFormat = function(){return new QTextCharFormat();};

/**
  * @name blockFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextBlockFormat}
  */
QTextCursor.prototype.blockFormat = function(){return new QTextBlockFormat();};

/**
  * @name blockNumber
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.blockNumber = function(){return new Numeric();};

/**
  * @name charFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextCharFormat}
  */
QTextCursor.prototype.charFormat = function(){return new QTextCharFormat();};

/**
  * @name clearSelection
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.clearSelection = function(){return undefined;};

/**
  * @name columnNumber
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.columnNumber = function(){return new Numeric();};

/**
  * @name createList
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextListFormat.Style} style
  * @returns {QTextList}
  */
QTextCursor.prototype.createList = function(style){return new QTextList();};

/**
  * @name currentFrame
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextFrame}
  */
QTextCursor.prototype.currentFrame = function(){return new QTextFrame();};

/**
  * @name currentList
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextList}
  */
QTextCursor.prototype.currentList = function(){return new QTextList();};

/**
  * @name currentTable
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextTable}
  */
QTextCursor.prototype.currentTable = function(){return new QTextTable();};

/**
  * @name deleteChar
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.deleteChar = function(){return undefined;};

/**
  * @name deletePreviousChar
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.deletePreviousChar = function(){return undefined;};

/**
  * @name document
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextDocument}
  */
QTextCursor.prototype.document = function(){return new QTextDocument();};

/**
  * @name endEditBlock
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.endEditBlock = function(){return undefined;};

/**
  * @name hasComplexSelection
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.hasComplexSelection = function(){return new Boolean();};

/**
  * @name hasSelection
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.hasSelection = function(){return new Boolean();};

/**
  * @name insertBlock
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.insertBlock = function(){return undefined;};

/**
  * @name insertFragment
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextDocumentFragment} fragment
  * @returns {undefined}
  */
QTextCursor.prototype.insertFragment = function(fragment){return undefined;};

/**
  * @name insertFrame
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextFrameFormat} format
  * @returns {QTextFrame}
  */
QTextCursor.prototype.insertFrame = function(format){return new QTextFrame();};

/**
  * @name insertHtml
  * @function
  * @memberOf QTextCursor.prototype
  * @param {String} html
  * @returns {undefined}
  */
QTextCursor.prototype.insertHtml = function(html){return undefined;};

/**
  * @name insertImage
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QImage} image
  * @param {String} name
  * @returns {undefined}
  */
QTextCursor.prototype.insertImage = function(image, name){return undefined;};

/**
  * @name insertList
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextListFormat.Style} style
  * @returns {QTextList}
  */
QTextCursor.prototype.insertList = function(style){return new QTextList();};

/**
  * @name insertTable
  * @function
  * @memberOf QTextCursor.prototype
  * @param {Numeric} rows
  * @param {Numeric} cols
  * @returns {QTextTable}
  */
QTextCursor.prototype.insertTable = function(rows, cols){return new QTextTable();};

/**
  * @name insertText
  * @function
  * @memberOf QTextCursor.prototype
  * @param {String} text
  * @returns {undefined}
  */
QTextCursor.prototype.insertText = function(text){return undefined;};

/**
  * @name isCopyOf
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCursor} other
  * @returns {Boolean}
  */
QTextCursor.prototype.isCopyOf = function(other){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.isNull = function(){return new Boolean();};

/**
  * @name joinPreviousEditBlock
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.joinPreviousEditBlock = function(){return undefined;};

/**
  * @name keepPositionOnInsert
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.keepPositionOnInsert = function(){return new Boolean();};

/**
  * @name mergeBlockCharFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCharFormat} modifier
  * @returns {undefined}
  */
QTextCursor.prototype.mergeBlockCharFormat = function(modifier){return undefined;};

/**
  * @name mergeBlockFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextBlockFormat} modifier
  * @returns {undefined}
  */
QTextCursor.prototype.mergeBlockFormat = function(modifier){return undefined;};

/**
  * @name mergeCharFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCharFormat} modifier
  * @returns {undefined}
  */
QTextCursor.prototype.mergeCharFormat = function(modifier){return undefined;};

/**
  * @name movePosition
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCursor.MoveOperation} op
  * @param {QTextCursor.MoveMode} arg__2
  * @param {Numeric} n
  * @returns {Boolean}
  */
QTextCursor.prototype.movePosition = function(op, arg__2, n){return new Boolean();};

/**
  * @name operator_equal
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCursor} rhs
  * @returns {Boolean}
  */
QTextCursor.prototype.operator_equal = function(rhs){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCursor} rhs
  * @returns {Boolean}
  */
QTextCursor.prototype.operator_less = function(rhs){return new Boolean();};

/**
  * @name position
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.position = function(){return new Numeric();};

/**
  * @name positionInBlock
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.positionInBlock = function(){return new Numeric();};

/**
  * @name removeSelectedText
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {undefined}
  */
QTextCursor.prototype.removeSelectedText = function(){return undefined;};

/**
  * @name select
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCursor.SelectionType} selection
  * @returns {undefined}
  */
QTextCursor.prototype.select = function(selection){return undefined;};

/**
  * @name selectedTableCells
  * @function
  * @memberOf QTextCursor.prototype
  * @param {Numeric} firstRow
  * @param {Numeric} numRows
  * @param {Numeric} firstColumn
  * @param {Numeric} numColumns
  * @returns {undefined}
  */
QTextCursor.prototype.selectedTableCells = function(firstRow, numRows, firstColumn, numColumns){return undefined;};

/**
  * @name selectedText
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {String}
  */
QTextCursor.prototype.selectedText = function(){return new String();};

/**
  * @name selection
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {QTextDocumentFragment}
  */
QTextCursor.prototype.selection = function(){return new QTextDocumentFragment();};

/**
  * @name selectionEnd
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.selectionEnd = function(){return new Numeric();};

/**
  * @name selectionStart
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.selectionStart = function(){return new Numeric();};

/**
  * @name setBlockCharFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QTextCursor.prototype.setBlockCharFormat = function(format){return undefined;};

/**
  * @name setBlockFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextBlockFormat} format
  * @returns {undefined}
  */
QTextCursor.prototype.setBlockFormat = function(format){return undefined;};

/**
  * @name setCharFormat
  * @function
  * @memberOf QTextCursor.prototype
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QTextCursor.prototype.setCharFormat = function(format){return undefined;};

/**
  * @name setKeepPositionOnInsert
  * @function
  * @memberOf QTextCursor.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QTextCursor.prototype.setKeepPositionOnInsert = function(b){return undefined;};

/**
  * @name setPosition
  * @function
  * @memberOf QTextCursor.prototype
  * @param {Numeric} pos
  * @param {QTextCursor.MoveMode} mode
  * @returns {undefined}
  */
QTextCursor.prototype.setPosition = function(pos, mode){return undefined;};

/**
  * @name setVerticalMovementX
  * @function
  * @memberOf QTextCursor.prototype
  * @param {Numeric} x
  * @returns {undefined}
  */
QTextCursor.prototype.setVerticalMovementX = function(x){return undefined;};

/**
  * @name setVisualNavigation
  * @function
  * @memberOf QTextCursor.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QTextCursor.prototype.setVisualNavigation = function(b){return undefined;};

/**
  * @name verticalMovementX
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Numeric}
  */
QTextCursor.prototype.verticalMovementX = function(){return new Numeric();};

/**
  * @name visualNavigation
  * @function
  * @memberOf QTextCursor.prototype
  * @returns {Boolean}
  */
QTextCursor.prototype.visualNavigation = function(){return new Boolean();};

