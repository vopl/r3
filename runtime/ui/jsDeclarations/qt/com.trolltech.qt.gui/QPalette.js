/**
  * @name QPalette
  * @constructor
  */
function QPalette(){return undefined;};

/**
  * @name QPalette^1
  * @constructor
  * @param {Qt.GlobalColor} button
  */
function QPalette(button){return undefined;};

/**
  * @name QPalette^2
  * @constructor
  * @param {QBrush} windowText
  * @param {QBrush} button
  * @param {QBrush} light
  * @param {QBrush} dark
  * @param {QBrush} mid
  * @param {QBrush} text
  * @param {QBrush} bright_text
  * @param {QBrush} base
  * @param {QBrush} window
  */
function QPalette(windowText, button, light, dark, mid, text, bright_text, base, window){return undefined;};

/**
  * @name QPalette^3
  * @constructor
  * @param {QColor} button
  */
function QPalette(button){return undefined;};

/**
  * @name QPalette^4
  * @constructor
  * @param {QColor} button
  * @param {QColor} window
  */
function QPalette(button, window){return undefined;};

/**
  * @name QPalette^5
  * @constructor
  * @param {QPalette} palette
  */
function QPalette(palette){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QPalette
  * @name Active
  * @see QPalette#ColorGroup
  * @type Number
  */
QPalette.Active = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPalette
  * @name Disabled
  * @see QPalette#ColorGroup
  * @type Number
  */
QPalette.Disabled = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPalette
  * @name Inactive
  * @see QPalette#ColorGroup
  * @type Number
  */
QPalette.Inactive = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPalette
  * @name NColorGroups
  * @see QPalette#ColorGroup
  * @type Number
  */
QPalette.NColorGroups = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPalette
  * @name Current
  * @see QPalette#ColorGroup
  * @type Number
  */
QPalette.Current = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPalette
  * @name All
  * @see QPalette#ColorGroup
  * @type Number
  */
QPalette.All = 0x5;

/**
  * @constructor 
  * @memberOf QPalette
  * @name ColorGroup
  */
QPalette.ColorGroup = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPalette
  * @name WindowText
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.WindowText = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPalette
  * @name Button
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Button = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPalette
  * @name Light
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Light = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPalette
  * @name Midlight
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Midlight = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPalette
  * @name Dark
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Dark = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPalette
  * @name Mid
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Mid = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPalette
  * @name Text
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Text = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QPalette
  * @name BrightText
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.BrightText = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QPalette
  * @name ButtonText
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.ButtonText = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QPalette
  * @name Base
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Base = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QPalette
  * @name Window
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Window = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QPalette
  * @name Shadow
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Shadow = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QPalette
  * @name Highlight
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Highlight = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QPalette
  * @name HighlightedText
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.HighlightedText = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QPalette
  * @name Link
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.Link = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QPalette
  * @name LinkVisited
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.LinkVisited = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QPalette
  * @name AlternateBase
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.AlternateBase = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QPalette
  * @name NoRole
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.NoRole = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QPalette
  * @name ToolTipBase
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.ToolTipBase = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QPalette
  * @name ToolTipText
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.ToolTipText = 0x13;

/**
  * @default ToolTipText+1
  * @constant
  * @memberOf QPalette
  * @name NColorRoles
  * @see QPalette#ColorRole
  * @type Number
  */
QPalette.NColorRoles = 0x14;

/**
  * @constructor 
  * @memberOf QPalette
  * @name ColorRole
  */
QPalette.ColorRole = function(value){;};



/**
  * @name alternateBase
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.alternateBase = function(){return new QBrush();};

/**
  * @name base
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.base = function(){return new QBrush();};

/**
  * @name brightText
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.brightText = function(){return new QBrush();};

/**
  * @name brush
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cg
  * @param {QPalette.ColorRole} cr
  * @returns {QBrush}
  */
QPalette.prototype.brush = function(cg, cr){return new QBrush();};

/**
  * @name button
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.button = function(){return new QBrush();};

/**
  * @name buttonText
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.buttonText = function(){return new QBrush();};

/**
  * @name cacheKey
  * @function
  * @memberOf QPalette.prototype
  * @returns {Numeric}
  */
QPalette.prototype.cacheKey = function(){return new Numeric();};

/**
  * @name color
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cg
  * @param {QPalette.ColorRole} cr
  * @returns {QColor}
  */
QPalette.prototype.color = function(cg, cr){return new QColor();};

/**
  * @name currentColorGroup
  * @function
  * @memberOf QPalette.prototype
  * @returns {QPalette.ColorGroup}
  */
QPalette.prototype.currentColorGroup = function(){return new QPalette.ColorGroup();};

/**
  * @name dark
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.dark = function(){return new QBrush();};

/**
  * @name highlight
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.highlight = function(){return new QBrush();};

/**
  * @name highlightedText
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.highlightedText = function(){return new QBrush();};

/**
  * @name isBrushSet
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cg
  * @param {QPalette.ColorRole} cr
  * @returns {Boolean}
  */
QPalette.prototype.isBrushSet = function(cg, cr){return new Boolean();};

/**
  * @name isCopyOf
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette} p
  * @returns {Boolean}
  */
QPalette.prototype.isCopyOf = function(p){return new Boolean();};

/**
  * @name isEqual
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cr1
  * @param {QPalette.ColorGroup} cr2
  * @returns {Boolean}
  */
QPalette.prototype.isEqual = function(cr1, cr2){return new Boolean();};

/**
  * @name light
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.light = function(){return new QBrush();};

/**
  * @name link
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.link = function(){return new QBrush();};

/**
  * @name linkVisited
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.linkVisited = function(){return new QBrush();};

/**
  * @name mid
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.mid = function(){return new QBrush();};

/**
  * @name midlight
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.midlight = function(){return new QBrush();};

/**
  * @name operator_equal
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette} p
  * @returns {Boolean}
  */
QPalette.prototype.operator_equal = function(p){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QPalette.prototype
  * @param {QDataStream} ds
  * @returns {undefined}
  */
QPalette.prototype.readFrom = function(ds){return undefined;};

/**
  * @name resolve
  * @function
  * @memberOf QPalette.prototype
  * @returns {Numeric}
  */
QPalette.prototype.resolve = function(){return new Numeric();};

/**
  * @name setBrush
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cg
  * @param {QPalette.ColorRole} cr
  * @param {QBrush} brush
  * @returns {undefined}
  */
QPalette.prototype.setBrush = function(cg, cr, brush){return undefined;};

/**
  * @name setColor
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cg
  * @param {QPalette.ColorRole} cr
  * @param {QColor} color
  * @returns {undefined}
  */
QPalette.prototype.setColor = function(cg, cr, color){return undefined;};

/**
  * @name setColorGroup
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cr
  * @param {QBrush} windowText
  * @param {QBrush} button
  * @param {QBrush} light
  * @param {QBrush} dark
  * @param {QBrush} mid
  * @param {QBrush} text
  * @param {QBrush} bright_text
  * @param {QBrush} base
  * @param {QBrush} window
  * @returns {undefined}
  */
QPalette.prototype.setColorGroup = function(cr, windowText, button, light, dark, mid, text, bright_text, base, window){return undefined;};

/**
  * @name setCurrentColorGroup
  * @function
  * @memberOf QPalette.prototype
  * @param {QPalette.ColorGroup} cg
  * @returns {undefined}
  */
QPalette.prototype.setCurrentColorGroup = function(cg){return undefined;};

/**
  * @name shadow
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.shadow = function(){return new QBrush();};

/**
  * @name text
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.text = function(){return new QBrush();};

/**
  * @name toolTipBase
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.toolTipBase = function(){return new QBrush();};

/**
  * @name toolTipText
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.toolTipText = function(){return new QBrush();};

/**
  * @name window
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.window = function(){return new QBrush();};

/**
  * @name windowText
  * @function
  * @memberOf QPalette.prototype
  * @returns {QBrush}
  */
QPalette.prototype.windowText = function(){return new QBrush();};

/**
  * @name writeTo
  * @function
  * @memberOf QPalette.prototype
  * @param {QDataStream} ds
  * @returns {undefined}
  */
QPalette.prototype.writeTo = function(ds){return undefined;};

