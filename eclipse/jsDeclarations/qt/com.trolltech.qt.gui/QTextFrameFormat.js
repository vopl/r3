/**
  * @name QTextFrameFormat
  * @constructor
  * @extends QTextFormat
  */
function QTextFrameFormat(){return undefined;};

QTextFrameFormat.prototype = new QTextFormat();

/**
  * @default 0x0
  * @constant
  * @memberOf QTextFrameFormat
  * @name InFlow
  * @see QTextFrameFormat#Position
  * @type Number
  */
QTextFrameFormat.InFlow = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextFrameFormat
  * @name FloatLeft
  * @see QTextFrameFormat#Position
  * @type Number
  */
QTextFrameFormat.FloatLeft = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextFrameFormat
  * @name FloatRight
  * @see QTextFrameFormat#Position
  * @type Number
  */
QTextFrameFormat.FloatRight = 0x2;

/**
  * @constructor 
  * @memberOf QTextFrameFormat
  * @name Position
  */
QTextFrameFormat.Position = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_None
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_None = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Dotted
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Dotted = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Dashed
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Dashed = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Solid
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Solid = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Double
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Double = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_DotDash
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_DotDash = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_DotDotDash
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_DotDotDash = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Groove
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Groove = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Ridge
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Ridge = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Inset
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Inset = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QTextFrameFormat
  * @name BorderStyle_Outset
  * @see QTextFrameFormat#BorderStyle
  * @type Number
  */
QTextFrameFormat.BorderStyle_Outset = 0xa;

/**
  * @constructor 
  * @memberOf QTextFrameFormat
  * @name BorderStyle
  */
QTextFrameFormat.BorderStyle = function(value){;};



/**
  * @name border
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.border = function(){return new Numeric();};

/**
  * @name borderBrush
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {QBrush}
  */
QTextFrameFormat.prototype.borderBrush = function(){return new QBrush();};

/**
  * @name borderStyle
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {QTextFrameFormat.BorderStyle}
  */
QTextFrameFormat.prototype.borderStyle = function(){return new QTextFrameFormat.BorderStyle();};

/**
  * @name bottomMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.bottomMargin = function(){return new Numeric();};

/**
  * @name height
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {QTextLength}
  */
QTextFrameFormat.prototype.height = function(){return new QTextLength();};

/**
  * @name leftMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.leftMargin = function(){return new Numeric();};

/**
  * @name margin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.margin = function(){return new Numeric();};

/**
  * @name padding
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.padding = function(){return new Numeric();};

/**
  * @name pageBreakPolicy
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {QTextFormat.PageBreakFlags}
  */
QTextFrameFormat.prototype.pageBreakPolicy = function(){return new QTextFormat.PageBreakFlags();};

/**
  * @name position
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {QStyleOptionViewItem.Position}
  */
QTextFrameFormat.prototype.position = function(){return new QStyleOptionViewItem.Position();};

/**
  * @name rightMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.rightMargin = function(){return new Numeric();};

/**
  * @name setBorder
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} border
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setBorder = function(border){return undefined;};

/**
  * @name setBorderBrush
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {QBrush} brush
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setBorderBrush = function(brush){return undefined;};

/**
  * @name setBorderStyle
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {QTextFrameFormat.BorderStyle} style
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setBorderStyle = function(style){return undefined;};

/**
  * @name setBottomMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} margin
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setBottomMargin = function(margin){return undefined;};

/**
  * @name setHeight
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {QTextLength} height
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setHeight = function(height){return undefined;};

/**
  * @name setLeftMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} margin
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setLeftMargin = function(margin){return undefined;};

/**
  * @name setMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} margin
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setMargin = function(margin){return undefined;};

/**
  * @name setPadding
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} padding
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setPadding = function(padding){return undefined;};

/**
  * @name setPageBreakPolicy
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {QTextFormat.PageBreakFlags} flags
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setPageBreakPolicy = function(flags){return undefined;};

/**
  * @name setPosition
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {QStyleOptionViewItem.Position} f
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setPosition = function(f){return undefined;};

/**
  * @name setRightMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} margin
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setRightMargin = function(margin){return undefined;};

/**
  * @name setTopMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {Numeric} margin
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setTopMargin = function(margin){return undefined;};

/**
  * @name setWidth
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @param {QTextLength} length
  * @returns {undefined}
  */
QTextFrameFormat.prototype.setWidth = function(length){return undefined;};

/**
  * @name topMargin
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {Numeric}
  */
QTextFrameFormat.prototype.topMargin = function(){return new Numeric();};

/**
  * @name width
  * @function
  * @memberOf QTextFrameFormat.prototype
  * @returns {QTextLength}
  */
QTextFrameFormat.prototype.width = function(){return new QTextLength();};

