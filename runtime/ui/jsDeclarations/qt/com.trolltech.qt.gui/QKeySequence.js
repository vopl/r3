/**
  * @name QKeySequence
  * @constructor
  */
function QKeySequence(){return undefined;};

/**
  * @name QKeySequence^1
  * @constructor
  * @param {QKeySequence.StandardKey} key
  */
function QKeySequence(key){return undefined;};

/**
  * @name QKeySequence^2
  * @constructor
  * @param {QKeySequence} ks
  */
function QKeySequence(ks){return undefined;};

/**
  * @name QKeySequence^3
  * @constructor
  * @param {String} key
  */
function QKeySequence(key){return undefined;};

/**
  * @name QKeySequence^4
  * @constructor
  * @param {String} key
  * @param {QKeySequence.SequenceFormat} format
  */
function QKeySequence(key, format){return undefined;};

/**
  * @name QKeySequence^5
  * @constructor
  * @param {Numeric} k1
  * @param {Numeric} k2
  * @param {Numeric} k3
  * @param {Numeric} k4
  */
function QKeySequence(k1, k2, k3, k4){return undefined;};

/**
  * @name fromString
  * @function
  * @memberOf QKeySequence
  * @param {String} str
  * @param {QKeySequence.SequenceFormat} format
  * @returns {QKeySequence}
  */
QKeySequence.fromString = function(str, format){return new QKeySequence();};

/**
  * @name keyBindings
  * @function
  * @memberOf QKeySequence
  * @param {QKeySequence.StandardKey} key
  * @returns {Array}
  */
QKeySequence.keyBindings = function(key){return new Array();};

/**
  * @name mnemonic
  * @function
  * @memberOf QKeySequence
  * @param {String} text
  * @returns {QKeySequence}
  */
QKeySequence.mnemonic = function(text){return new QKeySequence();};

/**
  * @default 0x0
  * @constant
  * @memberOf QKeySequence
  * @name NativeText
  * @see QKeySequence#SequenceFormat
  * @type Number
  */
QKeySequence.NativeText = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QKeySequence
  * @name PortableText
  * @see QKeySequence#SequenceFormat
  * @type Number
  */
QKeySequence.PortableText = 0x1;

/**
  * @constructor 
  * @memberOf QKeySequence
  * @name SequenceFormat
  */
QKeySequence.SequenceFormat = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QKeySequence
  * @name UnknownKey
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.UnknownKey = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QKeySequence
  * @name HelpContents
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.HelpContents = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QKeySequence
  * @name WhatsThis
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.WhatsThis = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QKeySequence
  * @name Open
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Open = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QKeySequence
  * @name Close
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Close = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QKeySequence
  * @name Save
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Save = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QKeySequence
  * @name New
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.New = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QKeySequence
  * @name Delete
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Delete = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QKeySequence
  * @name Cut
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Cut = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QKeySequence
  * @name Copy
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Copy = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QKeySequence
  * @name Paste
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Paste = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QKeySequence
  * @name Undo
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Undo = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QKeySequence
  * @name Redo
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Redo = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QKeySequence
  * @name Back
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Back = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QKeySequence
  * @name Forward
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Forward = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QKeySequence
  * @name Refresh
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Refresh = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QKeySequence
  * @name ZoomIn
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.ZoomIn = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QKeySequence
  * @name ZoomOut
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.ZoomOut = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QKeySequence
  * @name Print
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Print = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QKeySequence
  * @name AddTab
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.AddTab = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QKeySequence
  * @name NextChild
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.NextChild = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QKeySequence
  * @name PreviousChild
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.PreviousChild = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QKeySequence
  * @name Find
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Find = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QKeySequence
  * @name FindNext
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.FindNext = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QKeySequence
  * @name FindPrevious
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.FindPrevious = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QKeySequence
  * @name Replace
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Replace = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QKeySequence
  * @name SelectAll
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectAll = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QKeySequence
  * @name Bold
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Bold = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QKeySequence
  * @name Italic
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Italic = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QKeySequence
  * @name Underline
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Underline = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QKeySequence
  * @name MoveToNextChar
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToNextChar = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QKeySequence
  * @name MoveToPreviousChar
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToPreviousChar = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QKeySequence
  * @name MoveToNextWord
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToNextWord = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QKeySequence
  * @name MoveToPreviousWord
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToPreviousWord = 0x21;

/**
  * @default 0x22
  * @constant
  * @memberOf QKeySequence
  * @name MoveToNextLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToNextLine = 0x22;

/**
  * @default 0x23
  * @constant
  * @memberOf QKeySequence
  * @name MoveToPreviousLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToPreviousLine = 0x23;

/**
  * @default 0x24
  * @constant
  * @memberOf QKeySequence
  * @name MoveToNextPage
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToNextPage = 0x24;

/**
  * @default 0x25
  * @constant
  * @memberOf QKeySequence
  * @name MoveToPreviousPage
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToPreviousPage = 0x25;

/**
  * @default 0x26
  * @constant
  * @memberOf QKeySequence
  * @name MoveToStartOfLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToStartOfLine = 0x26;

/**
  * @default 0x27
  * @constant
  * @memberOf QKeySequence
  * @name MoveToEndOfLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToEndOfLine = 0x27;

/**
  * @default 0x28
  * @constant
  * @memberOf QKeySequence
  * @name MoveToStartOfBlock
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToStartOfBlock = 0x28;

/**
  * @default 0x29
  * @constant
  * @memberOf QKeySequence
  * @name MoveToEndOfBlock
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToEndOfBlock = 0x29;

/**
  * @default 0x2a
  * @constant
  * @memberOf QKeySequence
  * @name MoveToStartOfDocument
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToStartOfDocument = 0x2a;

/**
  * @default 0x2b
  * @constant
  * @memberOf QKeySequence
  * @name MoveToEndOfDocument
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.MoveToEndOfDocument = 0x2b;

/**
  * @default 0x2c
  * @constant
  * @memberOf QKeySequence
  * @name SelectNextChar
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectNextChar = 0x2c;

/**
  * @default 0x2d
  * @constant
  * @memberOf QKeySequence
  * @name SelectPreviousChar
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectPreviousChar = 0x2d;

/**
  * @default 0x2e
  * @constant
  * @memberOf QKeySequence
  * @name SelectNextWord
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectNextWord = 0x2e;

/**
  * @default 0x2f
  * @constant
  * @memberOf QKeySequence
  * @name SelectPreviousWord
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectPreviousWord = 0x2f;

/**
  * @default 0x30
  * @constant
  * @memberOf QKeySequence
  * @name SelectNextLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectNextLine = 0x30;

/**
  * @default 0x31
  * @constant
  * @memberOf QKeySequence
  * @name SelectPreviousLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectPreviousLine = 0x31;

/**
  * @default 0x32
  * @constant
  * @memberOf QKeySequence
  * @name SelectNextPage
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectNextPage = 0x32;

/**
  * @default 0x33
  * @constant
  * @memberOf QKeySequence
  * @name SelectPreviousPage
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectPreviousPage = 0x33;

/**
  * @default 0x34
  * @constant
  * @memberOf QKeySequence
  * @name SelectStartOfLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectStartOfLine = 0x34;

/**
  * @default 0x35
  * @constant
  * @memberOf QKeySequence
  * @name SelectEndOfLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectEndOfLine = 0x35;

/**
  * @default 0x36
  * @constant
  * @memberOf QKeySequence
  * @name SelectStartOfBlock
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectStartOfBlock = 0x36;

/**
  * @default 0x37
  * @constant
  * @memberOf QKeySequence
  * @name SelectEndOfBlock
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectEndOfBlock = 0x37;

/**
  * @default 0x38
  * @constant
  * @memberOf QKeySequence
  * @name SelectStartOfDocument
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectStartOfDocument = 0x38;

/**
  * @default 0x39
  * @constant
  * @memberOf QKeySequence
  * @name SelectEndOfDocument
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SelectEndOfDocument = 0x39;

/**
  * @default 0x3a
  * @constant
  * @memberOf QKeySequence
  * @name DeleteStartOfWord
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.DeleteStartOfWord = 0x3a;

/**
  * @default 0x3b
  * @constant
  * @memberOf QKeySequence
  * @name DeleteEndOfWord
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.DeleteEndOfWord = 0x3b;

/**
  * @default 0x3c
  * @constant
  * @memberOf QKeySequence
  * @name DeleteEndOfLine
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.DeleteEndOfLine = 0x3c;

/**
  * @default 0x3d
  * @constant
  * @memberOf QKeySequence
  * @name InsertParagraphSeparator
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.InsertParagraphSeparator = 0x3d;

/**
  * @default 0x3e
  * @constant
  * @memberOf QKeySequence
  * @name InsertLineSeparator
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.InsertLineSeparator = 0x3e;

/**
  * @default 0x3f
  * @constant
  * @memberOf QKeySequence
  * @name SaveAs
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.SaveAs = 0x3f;

/**
  * @default 0x40
  * @constant
  * @memberOf QKeySequence
  * @name Preferences
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Preferences = 0x40;

/**
  * @default 0x41
  * @constant
  * @memberOf QKeySequence
  * @name Quit
  * @see QKeySequence#StandardKey
  * @type Number
  */
QKeySequence.Quit = 0x41;

/**
  * @constructor 
  * @memberOf QKeySequence
  * @name StandardKey
  */
QKeySequence.StandardKey = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QKeySequence
  * @name NoMatch
  * @see QKeySequence#SequenceMatch
  * @type Number
  */
QKeySequence.NoMatch = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QKeySequence
  * @name PartialMatch
  * @see QKeySequence#SequenceMatch
  * @type Number
  */
QKeySequence.PartialMatch = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QKeySequence
  * @name ExactMatch
  * @see QKeySequence#SequenceMatch
  * @type Number
  */
QKeySequence.ExactMatch = 0x2;

/**
  * @constructor 
  * @memberOf QKeySequence
  * @name SequenceMatch
  */
QKeySequence.SequenceMatch = function(value){;};



/**
  * @name count
  * @function
  * @memberOf QKeySequence.prototype
  * @returns {Numeric}
  */
QKeySequence.prototype.count = function(){return new Numeric();};

/**
  * @name isEmpty
  * @function
  * @memberOf QKeySequence.prototype
  * @returns {Boolean}
  */
QKeySequence.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name matches
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QKeySequence} seq
  * @returns {QKeySequence.SequenceMatch}
  */
QKeySequence.prototype.matches = function(seq){return new QKeySequence.SequenceMatch();};

/**
  * @name operator_cast_int
  * @function
  * @memberOf QKeySequence.prototype
  * @returns {Numeric}
  */
QKeySequence.prototype.operator_cast_int = function(){return new Numeric();};

/**
  * @name operator_equal
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QKeySequence} other
  * @returns {Boolean}
  */
QKeySequence.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QKeySequence} ks
  * @returns {Boolean}
  */
QKeySequence.prototype.operator_less = function(ks){return new Boolean();};

/**
  * @name operator_subscript
  * @function
  * @memberOf QKeySequence.prototype
  * @param {Numeric} i
  * @returns {Numeric}
  */
QKeySequence.prototype.operator_subscript = function(i){return new Numeric();};

/**
  * @name readFrom
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QDataStream} out
  * @returns {undefined}
  */
QKeySequence.prototype.readFrom = function(out){return undefined;};

/**
  * @name swap
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QKeySequence} other
  * @returns {undefined}
  */
QKeySequence.prototype.swap = function(other){return undefined;};

/**
  * @name toString
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QKeySequence.SequenceFormat} format
  * @returns {String}
  */
QKeySequence.prototype.toString = function(format){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QKeySequence.prototype
  * @param {QDataStream} _in
  * @returns {undefined}
  */
QKeySequence.prototype.writeTo = function(_in){return undefined;};

