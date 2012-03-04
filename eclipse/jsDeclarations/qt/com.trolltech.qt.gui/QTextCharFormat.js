/**
  * @name QTextCharFormat
  * @constructor
  * @extends QTextFormat
  */
function QTextCharFormat(){return undefined;};

QTextCharFormat.prototype = new QTextFormat();

/**
  * @default 0
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignNormal
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignNormal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignSuperScript
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignSuperScript = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignSubScript
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignSubScript = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignMiddle
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignMiddle = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignTop
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignTop = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignBottom
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignBottom = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QTextCharFormat
  * @name AlignBaseline
  * @see QTextCharFormat#VerticalAlignment
  * @type Number
  */
QTextCharFormat.AlignBaseline = 0x6;

/**
  * @constructor 
  * @memberOf QTextCharFormat
  * @name VerticalAlignment
  */
QTextCharFormat.VerticalAlignment = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTextCharFormat
  * @name NoUnderline
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.NoUnderline = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextCharFormat
  * @name SingleUnderline
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.SingleUnderline = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextCharFormat
  * @name DashUnderline
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.DashUnderline = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextCharFormat
  * @name DotLine
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.DotLine = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTextCharFormat
  * @name DashDotLine
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.DashDotLine = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTextCharFormat
  * @name DashDotDotLine
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.DashDotDotLine = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QTextCharFormat
  * @name WaveUnderline
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.WaveUnderline = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QTextCharFormat
  * @name SpellCheckUnderline
  * @see QTextCharFormat#UnderlineStyle
  * @type Number
  */
QTextCharFormat.SpellCheckUnderline = 0x7;

/**
  * @constructor 
  * @memberOf QTextCharFormat
  * @name UnderlineStyle
  */
QTextCharFormat.UnderlineStyle = function(value){;};



/**
  * @name anchorHref
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {String}
  */
QTextCharFormat.prototype.anchorHref = function(){return new String();};

/**
  * @name anchorNames
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Array}
  */
QTextCharFormat.prototype.anchorNames = function(){return new Array();};

/**
  * @name font
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QFont}
  */
QTextCharFormat.prototype.font = function(){return new QFont();};

/**
  * @name fontCapitalization
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QFont.Capitalization}
  */
QTextCharFormat.prototype.fontCapitalization = function(){return new QFont.Capitalization();};

/**
  * @name fontFamily
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {String}
  */
QTextCharFormat.prototype.fontFamily = function(){return new String();};

/**
  * @name fontFixedPitch
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.fontFixedPitch = function(){return new Boolean();};

/**
  * @name fontItalic
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.fontItalic = function(){return new Boolean();};

/**
  * @name fontKerning
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.fontKerning = function(){return new Boolean();};

/**
  * @name fontLetterSpacing
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Numeric}
  */
QTextCharFormat.prototype.fontLetterSpacing = function(){return new Numeric();};

/**
  * @name fontOverline
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.fontOverline = function(){return new Boolean();};

/**
  * @name fontPointSize
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Numeric}
  */
QTextCharFormat.prototype.fontPointSize = function(){return new Numeric();};

/**
  * @name fontStrikeOut
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.fontStrikeOut = function(){return new Boolean();};

/**
  * @name fontStyleHint
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QStyle.StyleHint}
  */
QTextCharFormat.prototype.fontStyleHint = function(){return new QStyle.StyleHint();};

/**
  * @name fontStyleStrategy
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QFont.StyleStrategy}
  */
QTextCharFormat.prototype.fontStyleStrategy = function(){return new QFont.StyleStrategy();};

/**
  * @name fontUnderline
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.fontUnderline = function(){return new Boolean();};

/**
  * @name fontWeight
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Numeric}
  */
QTextCharFormat.prototype.fontWeight = function(){return new Numeric();};

/**
  * @name fontWordSpacing
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Numeric}
  */
QTextCharFormat.prototype.fontWordSpacing = function(){return new Numeric();};

/**
  * @name isAnchor
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Boolean}
  */
QTextCharFormat.prototype.isAnchor = function(){return new Boolean();};

/**
  * @name setAnchor
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} anchor
  * @returns {undefined}
  */
QTextCharFormat.prototype.setAnchor = function(anchor){return undefined;};

/**
  * @name setAnchorHref
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {String} value
  * @returns {undefined}
  */
QTextCharFormat.prototype.setAnchorHref = function(value){return undefined;};

/**
  * @name setAnchorNames
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Array} names
  * @returns {undefined}
  */
QTextCharFormat.prototype.setAnchorNames = function(names){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QFont} font
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFont = function(font){return undefined;};

/**
  * @name setFontCapitalization
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QFont.Capitalization} capitalization
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontCapitalization = function(capitalization){return undefined;};

/**
  * @name setFontFamily
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {String} family
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontFamily = function(family){return undefined;};

/**
  * @name setFontFixedPitch
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} fixedPitch
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontFixedPitch = function(fixedPitch){return undefined;};

/**
  * @name setFontItalic
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} italic
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontItalic = function(italic){return undefined;};

/**
  * @name setFontKerning
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontKerning = function(enable){return undefined;};

/**
  * @name setFontLetterSpacing
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontLetterSpacing = function(spacing){return undefined;};

/**
  * @name setFontOverline
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} overline
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontOverline = function(overline){return undefined;};

/**
  * @name setFontPointSize
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontPointSize = function(size){return undefined;};

/**
  * @name setFontStrikeOut
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} strikeOut
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontStrikeOut = function(strikeOut){return undefined;};

/**
  * @name setFontStyleHint
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QStyle.StyleHint} hint
  * @param {QFont.StyleStrategy} strategy
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontStyleHint = function(hint, strategy){return undefined;};

/**
  * @name setFontStyleStrategy
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QFont.StyleStrategy} strategy
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontStyleStrategy = function(strategy){return undefined;};

/**
  * @name setFontUnderline
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Boolean} underline
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontUnderline = function(underline){return undefined;};

/**
  * @name setFontWeight
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Numeric} weight
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontWeight = function(weight){return undefined;};

/**
  * @name setFontWordSpacing
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QTextCharFormat.prototype.setFontWordSpacing = function(spacing){return undefined;};

/**
  * @name setTableCellColumnSpan
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Numeric} tableCellColumnSpan
  * @returns {undefined}
  */
QTextCharFormat.prototype.setTableCellColumnSpan = function(tableCellColumnSpan){return undefined;};

/**
  * @name setTableCellRowSpan
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {Numeric} tableCellRowSpan
  * @returns {undefined}
  */
QTextCharFormat.prototype.setTableCellRowSpan = function(tableCellRowSpan){return undefined;};

/**
  * @name setTextOutline
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QPen} pen
  * @returns {undefined}
  */
QTextCharFormat.prototype.setTextOutline = function(pen){return undefined;};

/**
  * @name setToolTip
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {String} tip
  * @returns {undefined}
  */
QTextCharFormat.prototype.setToolTip = function(tip){return undefined;};

/**
  * @name setUnderlineColor
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QColor} color
  * @returns {undefined}
  */
QTextCharFormat.prototype.setUnderlineColor = function(color){return undefined;};

/**
  * @name setUnderlineStyle
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QTextCharFormat.UnderlineStyle} style
  * @returns {undefined}
  */
QTextCharFormat.prototype.setUnderlineStyle = function(style){return undefined;};

/**
  * @name setVerticalAlignment
  * @function
  * @memberOf QTextCharFormat.prototype
  * @param {QTextCharFormat.VerticalAlignment} alignment
  * @returns {undefined}
  */
QTextCharFormat.prototype.setVerticalAlignment = function(alignment){return undefined;};

/**
  * @name tableCellColumnSpan
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Numeric}
  */
QTextCharFormat.prototype.tableCellColumnSpan = function(){return new Numeric();};

/**
  * @name tableCellRowSpan
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {Numeric}
  */
QTextCharFormat.prototype.tableCellRowSpan = function(){return new Numeric();};

/**
  * @name textOutline
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QPen}
  */
QTextCharFormat.prototype.textOutline = function(){return new QPen();};

/**
  * @name toolTip
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {String}
  */
QTextCharFormat.prototype.toolTip = function(){return new String();};

/**
  * @name underlineColor
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QColor}
  */
QTextCharFormat.prototype.underlineColor = function(){return new QColor();};

/**
  * @name underlineStyle
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QTextCharFormat.UnderlineStyle}
  */
QTextCharFormat.prototype.underlineStyle = function(){return new QTextCharFormat.UnderlineStyle();};

/**
  * @name verticalAlignment
  * @function
  * @memberOf QTextCharFormat.prototype
  * @returns {QTextCharFormat.VerticalAlignment}
  */
QTextCharFormat.prototype.verticalAlignment = function(){return new QTextCharFormat.VerticalAlignment();};

