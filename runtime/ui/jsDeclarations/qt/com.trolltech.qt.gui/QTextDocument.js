/**
  * @name QTextDocument
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QTextDocument(parent){return undefined;};

/**
  * @name QTextDocument^1
  * @constructor
  * @extends QObject
  * @param {String} text
  * @param {QObject} parent
  */
function QTextDocument(text, parent){return undefined;};

QTextDocument.prototype = new QObject();

/**
  * @default 1
  * @constant
  * @memberOf QTextDocument
  * @name HtmlResource
  * @see QTextDocument#ResourceType
  * @type Number
  */
QTextDocument.HtmlResource = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QTextDocument
  * @name ImageResource
  * @see QTextDocument#ResourceType
  * @type Number
  */
QTextDocument.ImageResource = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QTextDocument
  * @name StyleSheetResource
  * @see QTextDocument#ResourceType
  * @type Number
  */
QTextDocument.StyleSheetResource = 0x3;

/**
  * @default 100
  * @constant
  * @memberOf QTextDocument
  * @name UserResource
  * @see QTextDocument#ResourceType
  * @type Number
  */
QTextDocument.UserResource = 0x64;

/**
  * @constructor 
  * @memberOf QTextDocument
  * @name ResourceType
  */
QTextDocument.ResourceType = function(value){;};



/**
  * @default 0x01
  * @constant
  * @memberOf QTextDocument
  * @name UndoStack
  * @see QTextDocument#Stacks
  * @type Number
  */
QTextDocument.UndoStack = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QTextDocument
  * @name RedoStack
  * @see QTextDocument#Stacks
  * @type Number
  */
QTextDocument.RedoStack = 0x2;

/**
  * @default UndoStack|RedoStack
  * @constant
  * @memberOf QTextDocument
  * @name UndoAndRedoStacks
  * @see QTextDocument#Stacks
  * @type Number
  */
QTextDocument.UndoAndRedoStacks = 0x3;

/**
  * @constructor 
  * @memberOf QTextDocument
  * @name Stacks
  */
QTextDocument.Stacks = function(value){;};



/**
  * @default 0x00001
  * @constant
  * @memberOf QTextDocument
  * @name FindBackward
  * @see QTextDocument#FindFlags
  * @see QTextDocument#FindFlag
  * @type Number
  */
QTextDocument.FindBackward = 0x1;

/**
  * @default 0x00002
  * @constant
  * @memberOf QTextDocument
  * @name FindCaseSensitively
  * @see QTextDocument#FindFlags
  * @see QTextDocument#FindFlag
  * @type Number
  */
QTextDocument.FindCaseSensitively = 0x2;

/**
  * @default 0x00004
  * @constant
  * @memberOf QTextDocument
  * @name FindWholeWords
  * @see QTextDocument#FindFlags
  * @see QTextDocument#FindFlag
  * @type Number
  */
QTextDocument.FindWholeWords = 0x4;

/**
  * @constructor 
  * @memberOf QTextDocument
  * @name FindFlag
  */
QTextDocument.FindFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QTextDocument
  * @name FindFlags
  */
QTextDocument.FindFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QTextDocument
  * @name DocumentTitle
  * @see QTextDocument#MetaInformation
  * @type Number
  */
QTextDocument.DocumentTitle = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextDocument
  * @name DocumentUrl
  * @see QTextDocument#MetaInformation
  * @type Number
  */
QTextDocument.DocumentUrl = 0x1;

/**
  * @constructor 
  * @memberOf QTextDocument
  * @name MetaInformation
  */
QTextDocument.MetaInformation = function(value){;};



/**
  * @name addResource
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} type
  * @param {QUrl} name
  * @param {Object} resource
  * @returns {undefined}
  */
QTextDocument.prototype.addResource = function(type, name, resource){return undefined;};

/**
  * @name adjustSize
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {undefined}
  */
QTextDocument.prototype.adjustSize = function(){return undefined;};

/**
  * @name allFormats
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Array}
  */
QTextDocument.prototype.allFormats = function(){return new Array();};

/**
  * @name availableRedoSteps
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.availableRedoSteps = function(){return new Numeric();};

/**
  * @name availableUndoSteps
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.availableUndoSteps = function(){return new Numeric();};

/**
  * @name begin
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {QTextBlock}
  */
QTextDocument.prototype.begin = function(){return new QTextBlock();};

/**
  * @name characterAt
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} pos
  * @returns {String}
  */
QTextDocument.prototype.characterAt = function(pos){return new String();};

/**
  * @name characterCount
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.characterCount = function(){return new Numeric();};

/**
  * @name clear
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {undefined}
  */
QTextDocument.prototype.clear = function(){return undefined;};

/**
  * @name clearUndoRedoStacks
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QTextDocument.Stacks} historyToClear
  * @returns {undefined}
  */
QTextDocument.prototype.clearUndoRedoStacks = function(historyToClear){return undefined;};

/**
  * @name clone
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QObject} parent
  * @returns {QTextDocument}
  */
QTextDocument.prototype.clone = function(parent){return new QTextDocument();};

/**
  * @name defaultTextOption
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Object}
  */
QTextDocument.prototype.defaultTextOption = function(){return new Object();};

/**
  * @name documentLayout
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Object}
  */
QTextDocument.prototype.documentLayout = function(){return new Object();};

/**
  * @name drawContents
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QPainter} painter
  * @param {QRectF} rect
  * @returns {undefined}
  */
QTextDocument.prototype.drawContents = function(painter, rect){return undefined;};

/**
  * @name end
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {QTextBlock}
  */
QTextDocument.prototype.end = function(){return new QTextBlock();};

/**
  * @name find
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QRegExp} expr
  * @param {QTextCursor} from
  * @param {QWebPage.FindFlags} options
  * @returns {QTextCursor}
  */
QTextDocument.prototype.find = function(expr, from, options){return new QTextCursor();};

/**
  * @name findBlock
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} pos
  * @returns {QTextBlock}
  */
QTextDocument.prototype.findBlock = function(pos){return new QTextBlock();};

/**
  * @name findBlockByLineNumber
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} blockNumber
  * @returns {QTextBlock}
  */
QTextDocument.prototype.findBlockByLineNumber = function(blockNumber){return new QTextBlock();};

/**
  * @name findBlockByNumber
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} blockNumber
  * @returns {QTextBlock}
  */
QTextDocument.prototype.findBlockByNumber = function(blockNumber){return new QTextBlock();};

/**
  * @name firstBlock
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {QTextBlock}
  */
QTextDocument.prototype.firstBlock = function(){return new QTextBlock();};

/**
  * @name frameAt
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} pos
  * @returns {QTextFrame}
  */
QTextDocument.prototype.frameAt = function(pos){return new QTextFrame();};

/**
  * @name idealWidth
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.idealWidth = function(){return new Numeric();};

/**
  * @name isEmpty
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Boolean}
  */
QTextDocument.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name isRedoAvailable
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Boolean}
  */
QTextDocument.prototype.isRedoAvailable = function(){return new Boolean();};

/**
  * @name isUndoAvailable
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Boolean}
  */
QTextDocument.prototype.isUndoAvailable = function(){return new Boolean();};

/**
  * @name lastBlock
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {QTextBlock}
  */
QTextDocument.prototype.lastBlock = function(){return new QTextBlock();};

/**
  * @name lineCount
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.lineCount = function(){return new Numeric();};

/**
  * @name markContentsDirty
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} from
  * @param {Numeric} length
  * @returns {undefined}
  */
QTextDocument.prototype.markContentsDirty = function(from, length){return undefined;};

/**
  * @name metaInformation
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QTextDocument.MetaInformation} info
  * @returns {String}
  */
QTextDocument.prototype.metaInformation = function(info){return new String();};

/**
  * @name object
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} objectIndex
  * @returns {QTextObject}
  */
QTextDocument.prototype.object = function(objectIndex){return new QTextObject();};

/**
  * @name objectForFormat
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QTextFormat} arg__1
  * @returns {QTextObject}
  */
QTextDocument.prototype.objectForFormat = function(arg__1){return new QTextObject();};

/**
  * @name pageCount
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.pageCount = function(){return new Numeric();};

/**
  * @name print
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QPrinter} printer
  * @returns {undefined}
  */
QTextDocument.prototype.print = function(printer){return undefined;};

/**
  * @name redo
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QTextCursor} cursor
  * @returns {undefined}
  */
QTextDocument.prototype.redo = function(cursor){return undefined;};

/**
  * @name resource
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Numeric} type
  * @param {QUrl} name
  * @returns {Object}
  */
QTextDocument.prototype.resource = function(type, name){return new Object();};

/**
  * @name revision
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {Numeric}
  */
QTextDocument.prototype.revision = function(){return new Numeric();};

/**
  * @name rootFrame
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {QTextFrame}
  */
QTextDocument.prototype.rootFrame = function(){return new QTextFrame();};

/**
  * @name setDefaultTextOption
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Object} option
  * @returns {undefined}
  */
QTextDocument.prototype.setDefaultTextOption = function(option){return undefined;};

/**
  * @name setDocumentLayout
  * @function
  * @memberOf QTextDocument.prototype
  * @param {Object} layout
  * @returns {undefined}
  */
QTextDocument.prototype.setDocumentLayout = function(layout){return undefined;};

/**
  * @name setHtml
  * @function
  * @memberOf QTextDocument.prototype
  * @param {String} html
  * @returns {undefined}
  */
QTextDocument.prototype.setHtml = function(html){return undefined;};

/**
  * @name setMetaInformation
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QTextDocument.MetaInformation} info
  * @param {String} arg__2
  * @returns {undefined}
  */
QTextDocument.prototype.setMetaInformation = function(info, arg__2){return undefined;};

/**
  * @name setPlainText
  * @function
  * @memberOf QTextDocument.prototype
  * @param {String} text
  * @returns {undefined}
  */
QTextDocument.prototype.setPlainText = function(text){return undefined;};

/**
  * @name toHtml
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QByteArray} encoding
  * @returns {String}
  */
QTextDocument.prototype.toHtml = function(encoding){return new String();};

/**
  * @name toPlainText
  * @function
  * @memberOf QTextDocument.prototype
  * @returns {String}
  */
QTextDocument.prototype.toPlainText = function(){return new String();};

/**
  * @name undo
  * @function
  * @memberOf QTextDocument.prototype
  * @param {QTextCursor} cursor
  * @returns {undefined}
  */
QTextDocument.prototype.undo = function(cursor){return undefined;};

/**
  * @name undoRedoEnabled
  * @memberOf QTextDocument.prototype
  * @type Boolean
  */
QTextDocument.prototype.undoRedoEnabled = new Boolean();

/**
  * @name modified
  * @memberOf QTextDocument.prototype
  * @type Boolean
  */
QTextDocument.prototype.modified = new Boolean();

/**
  * @name pageSize
  * @memberOf QTextDocument.prototype
  * @type QSizeF
  */
QTextDocument.prototype.pageSize = new QSizeF();

/**
  * @name defaultFont
  * @memberOf QTextDocument.prototype
  * @type QFont
  */
QTextDocument.prototype.defaultFont = new QFont();

/**
  * @name useDesignMetrics
  * @memberOf QTextDocument.prototype
  * @type Boolean
  */
QTextDocument.prototype.useDesignMetrics = new Boolean();

/**
  * @name size
  * @memberOf QTextDocument.prototype
  * @type QSizeF
  */
QTextDocument.prototype.size = new QSizeF();

/**
  * @name textWidth
  * @memberOf QTextDocument.prototype
  * @type Numeric
  */
QTextDocument.prototype.textWidth = new Numeric();

/**
  * @name blockCount
  * @memberOf QTextDocument.prototype
  * @type Numeric
  */
QTextDocument.prototype.blockCount = new Numeric();

/**
  * @name indentWidth
  * @memberOf QTextDocument.prototype
  * @type Numeric
  */
QTextDocument.prototype.indentWidth = new Numeric();

/**
  * @name defaultStyleSheet
  * @memberOf QTextDocument.prototype
  * @type String
  */
QTextDocument.prototype.defaultStyleSheet = new String();

/**
  * @name maximumBlockCount
  * @memberOf QTextDocument.prototype
  * @type Numeric
  */
QTextDocument.prototype.maximumBlockCount = new Numeric();

/**
  * @name documentMargin
  * @memberOf QTextDocument.prototype
  * @type Numeric
  */
QTextDocument.prototype.documentMargin = new Numeric();


