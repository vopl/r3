/**
  * @name QPrinter
  * @constructor
  * @extends QPaintDevice
  * @param {QPrinter.PrinterMode} mode
  */
function QPrinter(mode){return undefined;};

/**
  * @name QPrinter^1
  * @constructor
  * @extends QPaintDevice
  * @param {Object} printer
  * @param {QPrinter.PrinterMode} mode
  */
function QPrinter(printer, mode){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name NativeFormat
  * @see QPrinter#OutputFormat
  * @type Number
  */
QPrinter.NativeFormat = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name PdfFormat
  * @see QPrinter#OutputFormat
  * @type Number
  */
QPrinter.PdfFormat = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name PostScriptFormat
  * @see QPrinter#OutputFormat
  * @type Number
  */
QPrinter.PostScriptFormat = 0x2;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name OutputFormat
  */
QPrinter.OutputFormat = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QPrinter
  * @name DuplexNone
  * @see QPrinter#DuplexMode
  * @type Number
  */
QPrinter.DuplexNone = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name DuplexAuto
  * @see QPrinter#DuplexMode
  * @type Number
  */
QPrinter.DuplexAuto = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name DuplexLongSide
  * @see QPrinter#DuplexMode
  * @type Number
  */
QPrinter.DuplexLongSide = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPrinter
  * @name DuplexShortSide
  * @see QPrinter#DuplexMode
  * @type Number
  */
QPrinter.DuplexShortSide = 0x3;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name DuplexMode
  */
QPrinter.DuplexMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name AllPages
  * @see QPrinter#PrintRange
  * @type Number
  */
QPrinter.AllPages = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name Selection
  * @see QPrinter#PrintRange
  * @type Number
  */
QPrinter.Selection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name PageRange
  * @see QPrinter#PrintRange
  * @type Number
  */
QPrinter.PageRange = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPrinter
  * @name CurrentPage
  * @see QPrinter#PrintRange
  * @type Number
  */
QPrinter.CurrentPage = 0x3;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name PrintRange
  */
QPrinter.PrintRange = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name Millimeter
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.Millimeter = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name Point
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.Point = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name Inch
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.Inch = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPrinter
  * @name Pica
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.Pica = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPrinter
  * @name Didot
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.Didot = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPrinter
  * @name Cicero
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.Cicero = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPrinter
  * @name DevicePixel
  * @see QPrinter#Unit
  * @type Number
  */
QPrinter.DevicePixel = 0x6;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name Unit
  */
QPrinter.Unit = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name ScreenResolution
  * @see QPrinter#PrinterMode
  * @type Number
  */
QPrinter.ScreenResolution = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name PrinterResolution
  * @see QPrinter#PrinterMode
  * @type Number
  */
QPrinter.PrinterResolution = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name HighResolution
  * @see QPrinter#PrinterMode
  * @type Number
  */
QPrinter.HighResolution = 0x2;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name PrinterMode
  */
QPrinter.PrinterMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name Portrait
  * @see QPrinter#Orientation
  * @type Number
  */
QPrinter.Portrait = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name Landscape
  * @see QPrinter#Orientation
  * @type Number
  */
QPrinter.Landscape = 0x1;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name Orientation
  */
QPrinter.Orientation = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name Idle
  * @see QPrinter#PrinterState
  * @type Number
  */
QPrinter.Idle = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name Active
  * @see QPrinter#PrinterState
  * @type Number
  */
QPrinter.Active = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name Aborted
  * @see QPrinter#PrinterState
  * @type Number
  */
QPrinter.Aborted = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPrinter
  * @name Error
  * @see QPrinter#PrinterState
  * @type Number
  */
QPrinter.Error = 0x3;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name PrinterState
  */
QPrinter.PrinterState = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name GrayScale
  * @see QPrinter#ColorMode
  * @type Number
  */
QPrinter.GrayScale = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name Color
  * @see QPrinter#ColorMode
  * @type Number
  */
QPrinter.Color = 0x1;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name ColorMode
  */
QPrinter.ColorMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name OnlyOne
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.OnlyOne = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name Lower
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Lower = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name Middle
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Middle = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPrinter
  * @name Manual
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Manual = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPrinter
  * @name Envelope
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Envelope = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPrinter
  * @name EnvelopeManual
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.EnvelopeManual = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPrinter
  * @name Auto
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Auto = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QPrinter
  * @name Tractor
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Tractor = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QPrinter
  * @name SmallFormat
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.SmallFormat = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QPrinter
  * @name LargeFormat
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.LargeFormat = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QPrinter
  * @name LargeCapacity
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.LargeCapacity = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QPrinter
  * @name Cassette
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.Cassette = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QPrinter
  * @name FormSource
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.FormSource = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QPrinter
  * @name MaxPageSource
  * @see QPrinter#PaperSource
  * @type Number
  */
QPrinter.MaxPageSource = 0xd;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name PaperSource
  */
QPrinter.PaperSource = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name FirstPageFirst
  * @see QPrinter#PageOrder
  * @type Number
  */
QPrinter.FirstPageFirst = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name LastPageFirst
  * @see QPrinter#PageOrder
  * @type Number
  */
QPrinter.LastPageFirst = 0x1;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name PageOrder
  */
QPrinter.PageOrder = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrinter
  * @name A4
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A4 = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrinter
  * @name B5
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B5 = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrinter
  * @name Letter
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Letter = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPrinter
  * @name Legal
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Legal = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPrinter
  * @name Executive
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Executive = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPrinter
  * @name A0
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A0 = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPrinter
  * @name A1
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A1 = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QPrinter
  * @name A2
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A2 = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QPrinter
  * @name A3
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A3 = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QPrinter
  * @name A5
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A5 = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QPrinter
  * @name A6
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A6 = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QPrinter
  * @name A7
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A7 = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QPrinter
  * @name A8
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A8 = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QPrinter
  * @name A9
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.A9 = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QPrinter
  * @name B0
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B0 = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QPrinter
  * @name B1
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B1 = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QPrinter
  * @name B10
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B10 = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QPrinter
  * @name B2
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B2 = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QPrinter
  * @name B3
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B3 = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QPrinter
  * @name B4
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B4 = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QPrinter
  * @name B6
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B6 = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QPrinter
  * @name B7
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B7 = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QPrinter
  * @name B8
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B8 = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QPrinter
  * @name B9
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.B9 = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QPrinter
  * @name C5E
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.C5E = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QPrinter
  * @name Comm10E
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Comm10E = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QPrinter
  * @name DLE
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.DLE = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QPrinter
  * @name Folio
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Folio = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QPrinter
  * @name Ledger
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Ledger = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QPrinter
  * @name Tabloid
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Tabloid = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QPrinter
  * @name Custom
  * @see QPrinter#PageSize
  * @type Number
  */
QPrinter.Custom = 0x1e;

/**
  * @constructor 
  * @memberOf QPrinter
  * @name PageSize
  */
QPrinter.PageSize = function(value){;};



/**
  * @name abort
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.abort = function(){return new Boolean();};

/**
  * @name actualNumCopies
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Numeric}
  */
QPrinter.prototype.actualNumCopies = function(){return new Numeric();};

/**
  * @name collateCopies
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.collateCopies = function(){return new Boolean();};

/**
  * @name colorMode
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.ColorMode}
  */
QPrinter.prototype.colorMode = function(){return new QPrinter.ColorMode();};

/**
  * @name copyCount
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Numeric}
  */
QPrinter.prototype.copyCount = function(){return new Numeric();};

/**
  * @name creator
  * @function
  * @memberOf QPrinter.prototype
  * @returns {String}
  */
QPrinter.prototype.creator = function(){return new String();};

/**
  * @name docName
  * @function
  * @memberOf QPrinter.prototype
  * @returns {String}
  */
QPrinter.prototype.docName = function(){return new String();};

/**
  * @name doubleSidedPrinting
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.doubleSidedPrinting = function(){return new Boolean();};

/**
  * @name duplex
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.DuplexMode}
  */
QPrinter.prototype.duplex = function(){return new QPrinter.DuplexMode();};

/**
  * @name fontEmbeddingEnabled
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.fontEmbeddingEnabled = function(){return new Boolean();};

/**
  * @name fromPage
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Numeric}
  */
QPrinter.prototype.fromPage = function(){return new Numeric();};

/**
  * @name fullPage
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.fullPage = function(){return new Boolean();};

/**
  * @name getPageMargins
  * @function
  * @memberOf QPrinter.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @param {QPrinter.Unit} unit
  * @returns {undefined}
  */
QPrinter.prototype.getPageMargins = function(left, top, right, bottom, unit){return undefined;};

/**
  * @name isValid
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.isValid = function(){return new Boolean();};

/**
  * @name newPage
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.newPage = function(){return new Boolean();};

/**
  * @name numCopies
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Numeric}
  */
QPrinter.prototype.numCopies = function(){return new Numeric();};

/**
  * @name orientation
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.Orientation}
  */
QPrinter.prototype.orientation = function(){return new QPrinter.Orientation();};

/**
  * @name outputFileName
  * @function
  * @memberOf QPrinter.prototype
  * @returns {String}
  */
QPrinter.prototype.outputFileName = function(){return new String();};

/**
  * @name outputFormat
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.OutputFormat}
  */
QPrinter.prototype.outputFormat = function(){return new QPrinter.OutputFormat();};

/**
  * @name pageOrder
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.PageOrder}
  */
QPrinter.prototype.pageOrder = function(){return new QPrinter.PageOrder();};

/**
  * @name pageRect
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QRect}
  */
QPrinter.prototype.pageRect = function(){return new QRect();};

/**
  * @name pageSize
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.PageSize}
  */
QPrinter.prototype.pageSize = function(){return new QPrinter.PageSize();};

/**
  * @name paperRect
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QRect}
  */
QPrinter.prototype.paperRect = function(){return new QRect();};

/**
  * @name paperSize
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.PageSize}
  */
QPrinter.prototype.paperSize = function(){return new QPrinter.PageSize();};

/**
  * @name paperSource
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.PaperSource}
  */
QPrinter.prototype.paperSource = function(){return new QPrinter.PaperSource();};

/**
  * @name printEngine
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrintEngine}
  */
QPrinter.prototype.printEngine = function(){return new QPrintEngine();};

/**
  * @name printProgram
  * @function
  * @memberOf QPrinter.prototype
  * @returns {String}
  */
QPrinter.prototype.printProgram = function(){return new String();};

/**
  * @name printRange
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QAbstractPrintDialog.PrintRange}
  */
QPrinter.prototype.printRange = function(){return new QAbstractPrintDialog.PrintRange();};

/**
  * @name printerName
  * @function
  * @memberOf QPrinter.prototype
  * @returns {String}
  */
QPrinter.prototype.printerName = function(){return new String();};

/**
  * @name printerState
  * @function
  * @memberOf QPrinter.prototype
  * @returns {QPrinter.PrinterState}
  */
QPrinter.prototype.printerState = function(){return new QPrinter.PrinterState();};

/**
  * @name resolution
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Numeric}
  */
QPrinter.prototype.resolution = function(){return new Numeric();};

/**
  * @name setCollateCopies
  * @function
  * @memberOf QPrinter.prototype
  * @param {Boolean} collate
  * @returns {undefined}
  */
QPrinter.prototype.setCollateCopies = function(collate){return undefined;};

/**
  * @name setColorMode
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.ColorMode} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setColorMode = function(arg__1){return undefined;};

/**
  * @name setCopyCount
  * @function
  * @memberOf QPrinter.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setCopyCount = function(arg__1){return undefined;};

/**
  * @name setCreator
  * @function
  * @memberOf QPrinter.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setCreator = function(arg__1){return undefined;};

/**
  * @name setDocName
  * @function
  * @memberOf QPrinter.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setDocName = function(arg__1){return undefined;};

/**
  * @name setDoubleSidedPrinting
  * @function
  * @memberOf QPrinter.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
QPrinter.prototype.setDoubleSidedPrinting = function(enable){return undefined;};

/**
  * @name setDuplex
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.DuplexMode} duplex
  * @returns {undefined}
  */
QPrinter.prototype.setDuplex = function(duplex){return undefined;};

/**
  * @name setFontEmbeddingEnabled
  * @function
  * @memberOf QPrinter.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
QPrinter.prototype.setFontEmbeddingEnabled = function(enable){return undefined;};

/**
  * @name setFromTo
  * @function
  * @memberOf QPrinter.prototype
  * @param {Numeric} fromPage
  * @param {Numeric} toPage
  * @returns {undefined}
  */
QPrinter.prototype.setFromTo = function(fromPage, toPage){return undefined;};

/**
  * @name setFullPage
  * @function
  * @memberOf QPrinter.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setFullPage = function(arg__1){return undefined;};

/**
  * @name setNumCopies
  * @function
  * @memberOf QPrinter.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setNumCopies = function(arg__1){return undefined;};

/**
  * @name setOrientation
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.Orientation} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setOrientation = function(arg__1){return undefined;};

/**
  * @name setOutputFileName
  * @function
  * @memberOf QPrinter.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setOutputFileName = function(arg__1){return undefined;};

/**
  * @name setOutputFormat
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.OutputFormat} format
  * @returns {undefined}
  */
QPrinter.prototype.setOutputFormat = function(format){return undefined;};

/**
  * @name setPageMargins
  * @function
  * @memberOf QPrinter.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @param {QPrinter.Unit} unit
  * @returns {undefined}
  */
QPrinter.prototype.setPageMargins = function(left, top, right, bottom, unit){return undefined;};

/**
  * @name setPageOrder
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.PageOrder} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setPageOrder = function(arg__1){return undefined;};

/**
  * @name setPageSize
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.PageSize} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setPageSize = function(arg__1){return undefined;};

/**
  * @name setPaperSize
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.PageSize} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setPaperSize = function(arg__1){return undefined;};

/**
  * @name setPaperSource
  * @function
  * @memberOf QPrinter.prototype
  * @param {QPrinter.PaperSource} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setPaperSource = function(arg__1){return undefined;};

/**
  * @name setPrintProgram
  * @function
  * @memberOf QPrinter.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setPrintProgram = function(arg__1){return undefined;};

/**
  * @name setPrintRange
  * @function
  * @memberOf QPrinter.prototype
  * @param {QAbstractPrintDialog.PrintRange} range
  * @returns {undefined}
  */
QPrinter.prototype.setPrintRange = function(range){return undefined;};

/**
  * @name setPrinterName
  * @function
  * @memberOf QPrinter.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setPrinterName = function(arg__1){return undefined;};

/**
  * @name setResolution
  * @function
  * @memberOf QPrinter.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QPrinter.prototype.setResolution = function(arg__1){return undefined;};

/**
  * @name supportedResolutions
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Array}
  */
QPrinter.prototype.supportedResolutions = function(){return new Array();};

/**
  * @name supportsMultipleCopies
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Boolean}
  */
QPrinter.prototype.supportsMultipleCopies = function(){return new Boolean();};

/**
  * @name toPage
  * @function
  * @memberOf QPrinter.prototype
  * @returns {Numeric}
  */
QPrinter.prototype.toPage = function(){return new Numeric();};

