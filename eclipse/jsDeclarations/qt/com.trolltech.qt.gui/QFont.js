/**
  * @name QFont
  * @constructor
  */
function QFont(){return undefined;};

/**
  * @name QFont^1
  * @constructor
  * @param {QFont} arg__1
  */
function QFont(arg__1){return undefined;};

/**
  * @name QFont^2
  * @constructor
  * @param {QFont} arg__1
  * @param {QPaintDevice} pd
  */
function QFont(arg__1, pd){return undefined;};

/**
  * @name QFont^3
  * @constructor
  * @param {String} family
  * @param {Numeric} pointSize
  * @param {Numeric} weight
  * @param {Boolean} italic
  */
function QFont(family, pointSize, weight, italic){return undefined;};

/**
  * @name cacheStatistics
  * @function
  * @memberOf QFont
  * @returns {undefined}
  */
QFont.cacheStatistics = function(){return undefined;};

/**
  * @name cleanup
  * @function
  * @memberOf QFont
  * @returns {undefined}
  */
QFont.cleanup = function(){return undefined;};

/**
  * @name initialize
  * @function
  * @memberOf QFont
  * @returns {undefined}
  */
QFont.initialize = function(){return undefined;};

/**
  * @name insertSubstitution
  * @function
  * @memberOf QFont
  * @param {String} arg__1
  * @param {String} arg__2
  * @returns {undefined}
  */
QFont.insertSubstitution = function(arg__1, arg__2){return undefined;};

/**
  * @name insertSubstitutions
  * @function
  * @memberOf QFont
  * @param {String} arg__1
  * @param {Array} arg__2
  * @returns {undefined}
  */
QFont.insertSubstitutions = function(arg__1, arg__2){return undefined;};

/**
  * @name removeSubstitution
  * @function
  * @memberOf QFont
  * @param {String} arg__1
  * @returns {undefined}
  */
QFont.removeSubstitution = function(arg__1){return undefined;};

/**
  * @name substitute
  * @function
  * @memberOf QFont
  * @param {String} arg__1
  * @returns {String}
  */
QFont.substitute = function(arg__1){return new String();};

/**
  * @name substitutes
  * @function
  * @memberOf QFont
  * @param {String} arg__1
  * @returns {Array}
  */
QFont.substitutes = function(arg__1){return new Array();};

/**
  * @name substitutions
  * @function
  * @memberOf QFont
  * @returns {Array}
  */
QFont.substitutions = function(){return new Array();};

/**
  * @default 0x0001
  * @constant
  * @memberOf QFont
  * @name PreferDefault
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferDefault = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QFont
  * @name PreferBitmap
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferBitmap = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QFont
  * @name PreferDevice
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferDevice = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QFont
  * @name PreferOutline
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferOutline = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QFont
  * @name ForceOutline
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.ForceOutline = 0x10;

/**
  * @default 0x0020
  * @constant
  * @memberOf QFont
  * @name PreferMatch
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferMatch = 0x20;

/**
  * @default 0x0040
  * @constant
  * @memberOf QFont
  * @name PreferQuality
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferQuality = 0x40;

/**
  * @default 0x0080
  * @constant
  * @memberOf QFont
  * @name PreferAntialias
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.PreferAntialias = 0x80;

/**
  * @default 0x0100
  * @constant
  * @memberOf QFont
  * @name NoAntialias
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.NoAntialias = 0x100;

/**
  * @default 0x0200
  * @constant
  * @memberOf QFont
  * @name OpenGLCompatible
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.OpenGLCompatible = 0x200;

/**
  * @default 0x0400
  * @constant
  * @memberOf QFont
  * @name ForceIntegerMetrics
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.ForceIntegerMetrics = 0x400;

/**
  * @default 0x8000
  * @constant
  * @memberOf QFont
  * @name NoFontMerging
  * @see QFont#StyleStrategy
  * @type Number
  */
QFont.NoFontMerging = 0x8000;

/**
  * @constructor 
  * @memberOf QFont
  * @name StyleStrategy
  */
QFont.StyleStrategy = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFont
  * @name PercentageSpacing
  * @see QFont#SpacingType
  * @type Number
  */
QFont.PercentageSpacing = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFont
  * @name AbsoluteSpacing
  * @see QFont#SpacingType
  * @type Number
  */
QFont.AbsoluteSpacing = 0x1;

/**
  * @constructor 
  * @memberOf QFont
  * @name SpacingType
  */
QFont.SpacingType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFont
  * @name Helvetica
  * @see QFont#StyleHint
  * @type Number
  */
QFont.Helvetica = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFont
  * @name Times
  * @see QFont#StyleHint
  * @type Number
  */
QFont.Times = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFont
  * @name Courier
  * @see QFont#StyleHint
  * @type Number
  */
QFont.Courier = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFont
  * @name OldEnglish
  * @see QFont#StyleHint
  * @type Number
  */
QFont.OldEnglish = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFont
  * @name System
  * @see QFont#StyleHint
  * @type Number
  */
QFont.System = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QFont
  * @name AnyStyle
  * @see QFont#StyleHint
  * @type Number
  */
QFont.AnyStyle = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QFont
  * @name Cursive
  * @see QFont#StyleHint
  * @type Number
  */
QFont.Cursive = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QFont
  * @name Monospace
  * @see QFont#StyleHint
  * @type Number
  */
QFont.Monospace = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QFont
  * @name Fantasy
  * @see QFont#StyleHint
  * @type Number
  */
QFont.Fantasy = 0x8;

/**
  * @constructor 
  * @memberOf QFont
  * @name StyleHint
  */
QFont.StyleHint = function(value){;};



/**
  * @default 25
  * @constant
  * @memberOf QFont
  * @name Light
  * @see QFont#Weight
  * @type Number
  */
QFont.Light = 0x19;

/**
  * @default 50
  * @constant
  * @memberOf QFont
  * @name Normal
  * @see QFont#Weight
  * @type Number
  */
QFont.Normal = 0x32;

/**
  * @default 63
  * @constant
  * @memberOf QFont
  * @name DemiBold
  * @see QFont#Weight
  * @type Number
  */
QFont.DemiBold = 0x3f;

/**
  * @default 75
  * @constant
  * @memberOf QFont
  * @name Bold
  * @see QFont#Weight
  * @type Number
  */
QFont.Bold = 0x4b;

/**
  * @default 87
  * @constant
  * @memberOf QFont
  * @name Black
  * @see QFont#Weight
  * @type Number
  */
QFont.Black = 0x57;

/**
  * @constructor 
  * @memberOf QFont
  * @name Weight
  */
QFont.Weight = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFont
  * @name MixedCase
  * @see QFont#Capitalization
  * @type Number
  */
QFont.MixedCase = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFont
  * @name AllUppercase
  * @see QFont#Capitalization
  * @type Number
  */
QFont.AllUppercase = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFont
  * @name AllLowercase
  * @see QFont#Capitalization
  * @type Number
  */
QFont.AllLowercase = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFont
  * @name SmallCaps
  * @see QFont#Capitalization
  * @type Number
  */
QFont.SmallCaps = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFont
  * @name Capitalize
  * @see QFont#Capitalization
  * @type Number
  */
QFont.Capitalize = 0x4;

/**
  * @constructor 
  * @memberOf QFont
  * @name Capitalization
  */
QFont.Capitalization = function(value){;};



/**
  * @default 50
  * @constant
  * @memberOf QFont
  * @name UltraCondensed
  * @see QFont#Stretch
  * @type Number
  */
QFont.UltraCondensed = 0x32;

/**
  * @default 62
  * @constant
  * @memberOf QFont
  * @name ExtraCondensed
  * @see QFont#Stretch
  * @type Number
  */
QFont.ExtraCondensed = 0x3e;

/**
  * @default 75
  * @constant
  * @memberOf QFont
  * @name Condensed
  * @see QFont#Stretch
  * @type Number
  */
QFont.Condensed = 0x4b;

/**
  * @default 87
  * @constant
  * @memberOf QFont
  * @name SemiCondensed
  * @see QFont#Stretch
  * @type Number
  */
QFont.SemiCondensed = 0x57;

/**
  * @default 100
  * @constant
  * @memberOf QFont
  * @name Unstretched
  * @see QFont#Stretch
  * @type Number
  */
QFont.Unstretched = 0x64;

/**
  * @default 112
  * @constant
  * @memberOf QFont
  * @name SemiExpanded
  * @see QFont#Stretch
  * @type Number
  */
QFont.SemiExpanded = 0x70;

/**
  * @default 125
  * @constant
  * @memberOf QFont
  * @name Expanded
  * @see QFont#Stretch
  * @type Number
  */
QFont.Expanded = 0x7d;

/**
  * @default 150
  * @constant
  * @memberOf QFont
  * @name ExtraExpanded
  * @see QFont#Stretch
  * @type Number
  */
QFont.ExtraExpanded = 0x96;

/**
  * @default 200
  * @constant
  * @memberOf QFont
  * @name UltraExpanded
  * @see QFont#Stretch
  * @type Number
  */
QFont.UltraExpanded = 0xc8;

/**
  * @constructor 
  * @memberOf QFont
  * @name Stretch
  */
QFont.Stretch = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFont
  * @name StyleNormal
  * @see QFont#Style
  * @type Number
  */
QFont.StyleNormal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFont
  * @name StyleItalic
  * @see QFont#Style
  * @type Number
  */
QFont.StyleItalic = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFont
  * @name StyleOblique
  * @see QFont#Style
  * @type Number
  */
QFont.StyleOblique = 0x2;

/**
  * @constructor 
  * @memberOf QFont
  * @name Style
  */
QFont.Style = function(value){;};



/**
  * @name bold
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.bold = function(){return new Boolean();};

/**
  * @name capitalization
  * @function
  * @memberOf QFont.prototype
  * @returns {QFont.Capitalization}
  */
QFont.prototype.capitalization = function(){return new QFont.Capitalization();};

/**
  * @name defaultFamily
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.defaultFamily = function(){return new String();};

/**
  * @name exactMatch
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.exactMatch = function(){return new Boolean();};

/**
  * @name family
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.family = function(){return new String();};

/**
  * @name fixedPitch
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.fixedPitch = function(){return new Boolean();};

/**
  * @name fromString
  * @function
  * @memberOf QFont.prototype
  * @param {String} arg__1
  * @returns {Boolean}
  */
QFont.prototype.fromString = function(arg__1){return new Boolean();};

/**
  * @name handle
  * @function
  * @memberOf QFont.prototype
  * @returns {Object}
  */
QFont.prototype.handle = function(){return new Object();};

/**
  * @name isCopyOf
  * @function
  * @memberOf QFont.prototype
  * @param {QFont} arg__1
  * @returns {Boolean}
  */
QFont.prototype.isCopyOf = function(arg__1){return new Boolean();};

/**
  * @name italic
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.italic = function(){return new Boolean();};

/**
  * @name kerning
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.kerning = function(){return new Boolean();};

/**
  * @name key
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.key = function(){return new String();};

/**
  * @name lastResortFamily
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.lastResortFamily = function(){return new String();};

/**
  * @name lastResortFont
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.lastResortFont = function(){return new String();};

/**
  * @name letterSpacing
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.letterSpacing = function(){return new Numeric();};

/**
  * @name letterSpacingType
  * @function
  * @memberOf QFont.prototype
  * @returns {QFont.SpacingType}
  */
QFont.prototype.letterSpacingType = function(){return new QFont.SpacingType();};

/**
  * @name operator_equal
  * @function
  * @memberOf QFont.prototype
  * @param {QFont} arg__1
  * @returns {Boolean}
  */
QFont.prototype.operator_equal = function(arg__1){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QFont.prototype
  * @param {QFont} arg__1
  * @returns {Boolean}
  */
QFont.prototype.operator_less = function(arg__1){return new Boolean();};

/**
  * @name overline
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.overline = function(){return new Boolean();};

/**
  * @name pixelSize
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.pixelSize = function(){return new Numeric();};

/**
  * @name pointSize
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.pointSize = function(){return new Numeric();};

/**
  * @name pointSizeF
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.pointSizeF = function(){return new Numeric();};

/**
  * @name rawMode
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.rawMode = function(){return new Boolean();};

/**
  * @name rawName
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.rawName = function(){return new String();};

/**
  * @name readFrom
  * @function
  * @memberOf QFont.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QFont.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name resolve
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.resolve = function(){return new Numeric();};

/**
  * @name setBold
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setBold = function(arg__1){return undefined;};

/**
  * @name setCapitalization
  * @function
  * @memberOf QFont.prototype
  * @param {QFont.Capitalization} arg__1
  * @returns {undefined}
  */
QFont.prototype.setCapitalization = function(arg__1){return undefined;};

/**
  * @name setFamily
  * @function
  * @memberOf QFont.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QFont.prototype.setFamily = function(arg__1){return undefined;};

/**
  * @name setFixedPitch
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setFixedPitch = function(arg__1){return undefined;};

/**
  * @name setItalic
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QFont.prototype.setItalic = function(b){return undefined;};

/**
  * @name setKerning
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setKerning = function(arg__1){return undefined;};

/**
  * @name setLetterSpacing
  * @function
  * @memberOf QFont.prototype
  * @param {QFont.SpacingType} type
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QFont.prototype.setLetterSpacing = function(type, spacing){return undefined;};

/**
  * @name setOverline
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setOverline = function(arg__1){return undefined;};

/**
  * @name setPixelSize
  * @function
  * @memberOf QFont.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFont.prototype.setPixelSize = function(arg__1){return undefined;};

/**
  * @name setPointSize
  * @function
  * @memberOf QFont.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFont.prototype.setPointSize = function(arg__1){return undefined;};

/**
  * @name setPointSizeF
  * @function
  * @memberOf QFont.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFont.prototype.setPointSizeF = function(arg__1){return undefined;};

/**
  * @name setRawMode
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setRawMode = function(arg__1){return undefined;};

/**
  * @name setRawName
  * @function
  * @memberOf QFont.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QFont.prototype.setRawName = function(arg__1){return undefined;};

/**
  * @name setStretch
  * @function
  * @memberOf QFont.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFont.prototype.setStretch = function(arg__1){return undefined;};

/**
  * @name setStrikeOut
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setStrikeOut = function(arg__1){return undefined;};

/**
  * @name setStyle
  * @function
  * @memberOf QFont.prototype
  * @param {QTextListFormat.Style} style
  * @returns {undefined}
  */
QFont.prototype.setStyle = function(style){return undefined;};

/**
  * @name setStyleHint
  * @function
  * @memberOf QFont.prototype
  * @param {QStyle.StyleHint} arg__1
  * @param {QFont.StyleStrategy} arg__2
  * @returns {undefined}
  */
QFont.prototype.setStyleHint = function(arg__1, arg__2){return undefined;};

/**
  * @name setStyleName
  * @function
  * @memberOf QFont.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QFont.prototype.setStyleName = function(arg__1){return undefined;};

/**
  * @name setStyleStrategy
  * @function
  * @memberOf QFont.prototype
  * @param {QFont.StyleStrategy} s
  * @returns {undefined}
  */
QFont.prototype.setStyleStrategy = function(s){return undefined;};

/**
  * @name setUnderline
  * @function
  * @memberOf QFont.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QFont.prototype.setUnderline = function(arg__1){return undefined;};

/**
  * @name setWeight
  * @function
  * @memberOf QFont.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFont.prototype.setWeight = function(arg__1){return undefined;};

/**
  * @name setWordSpacing
  * @function
  * @memberOf QFont.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QFont.prototype.setWordSpacing = function(spacing){return undefined;};

/**
  * @name stretch
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.stretch = function(){return new Numeric();};

/**
  * @name strikeOut
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.strikeOut = function(){return new Boolean();};

/**
  * @name style
  * @function
  * @memberOf QFont.prototype
  * @returns {QTextListFormat.Style}
  */
QFont.prototype.style = function(){return new QTextListFormat.Style();};

/**
  * @name styleHint
  * @function
  * @memberOf QFont.prototype
  * @returns {QStyle.StyleHint}
  */
QFont.prototype.styleHint = function(){return new QStyle.StyleHint();};

/**
  * @name styleName
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.styleName = function(){return new String();};

/**
  * @name styleStrategy
  * @function
  * @memberOf QFont.prototype
  * @returns {QFont.StyleStrategy}
  */
QFont.prototype.styleStrategy = function(){return new QFont.StyleStrategy();};

/**
  * @name toString
  * @function
  * @memberOf QFont.prototype
  * @returns {String}
  */
QFont.prototype.toString = function(){return new String();};

/**
  * @name underline
  * @function
  * @memberOf QFont.prototype
  * @returns {Boolean}
  */
QFont.prototype.underline = function(){return new Boolean();};

/**
  * @name weight
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.weight = function(){return new Numeric();};

/**
  * @name wordSpacing
  * @function
  * @memberOf QFont.prototype
  * @returns {Numeric}
  */
QFont.prototype.wordSpacing = function(){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QFont.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QFont.prototype.writeTo = function(arg__1){return undefined;};

