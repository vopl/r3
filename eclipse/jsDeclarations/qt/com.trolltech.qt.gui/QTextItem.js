/**
  * @name QTextItem
  * @constructor
  */
function QTextItem(){return undefined;};

/**
  * @default 0xffffffff
  * @constant
  * @memberOf QTextItem
  * @name Dummy
  * @see QTextItem#RenderFlags
  * @see QTextItem#RenderFlag
  * @type Number
  */
QTextItem.Dummy = 0xffffffff;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextItem
  * @name RightToLeft
  * @see QTextItem#RenderFlags
  * @see QTextItem#RenderFlag
  * @type Number
  */
QTextItem.RightToLeft = 0x1;

/**
  * @default 0x10
  * @constant
  * @memberOf QTextItem
  * @name Overline
  * @see QTextItem#RenderFlags
  * @see QTextItem#RenderFlag
  * @type Number
  */
QTextItem.Overline = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf QTextItem
  * @name Underline
  * @see QTextItem#RenderFlags
  * @see QTextItem#RenderFlag
  * @type Number
  */
QTextItem.Underline = 0x20;

/**
  * @default 0x40
  * @constant
  * @memberOf QTextItem
  * @name StrikeOut
  * @see QTextItem#RenderFlags
  * @see QTextItem#RenderFlag
  * @type Number
  */
QTextItem.StrikeOut = 0x40;

/**
  * @constructor 
  * @memberOf QTextItem
  * @name RenderFlag
  */
QTextItem.RenderFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QTextItem
  * @name RenderFlags
  */
QTextItem.RenderFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name ascent
  * @function
  * @memberOf QTextItem.prototype
  * @returns {Numeric}
  */
QTextItem.prototype.ascent = function(){return new Numeric();};

/**
  * @name descent
  * @function
  * @memberOf QTextItem.prototype
  * @returns {Numeric}
  */
QTextItem.prototype.descent = function(){return new Numeric();};

/**
  * @name font
  * @function
  * @memberOf QTextItem.prototype
  * @returns {QFont}
  */
QTextItem.prototype.font = function(){return new QFont();};

/**
  * @name renderFlags
  * @function
  * @memberOf QTextItem.prototype
  * @returns {QWidget.RenderFlags}
  */
QTextItem.prototype.renderFlags = function(){return new QWidget.RenderFlags();};

/**
  * @name text
  * @function
  * @memberOf QTextItem.prototype
  * @returns {String}
  */
QTextItem.prototype.text = function(){return new String();};

/**
  * @name width
  * @function
  * @memberOf QTextItem.prototype
  * @returns {Numeric}
  */
QTextItem.prototype.width = function(){return new Numeric();};

