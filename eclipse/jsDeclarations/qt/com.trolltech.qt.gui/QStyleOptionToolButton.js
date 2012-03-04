/**
  * @name QStyleOptionToolButton
  * @constructor
  * @extends QStyleOptionComplex
  */
function QStyleOptionToolButton(){return undefined;};

/**
  * @name QStyleOptionToolButton^1
  * @constructor
  * @extends QStyleOptionComplex
  * @param {QStyleOptionToolButton} other
  */
function QStyleOptionToolButton(other){return undefined;};

QStyleOptionToolButton.prototype = new QStyleOptionComplex();

/**
  * @default 1
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name Version
  * @see QStyleOptionToolButton#StyleOptionVersion
  * @type Number
  */
QStyleOptionToolButton.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOptionToolButton
  * @name StyleOptionVersion
  */
QStyleOptionToolButton.StyleOptionVersion = function(value){;};



/**
  * @default 0x00
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name None
  * @see QStyleOptionToolButton#ToolButtonFeatures
  * @see QStyleOptionToolButton#ToolButtonFeature
  * @type Number
  */
QStyleOptionToolButton.None = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name Arrow
  * @see QStyleOptionToolButton#ToolButtonFeatures
  * @see QStyleOptionToolButton#ToolButtonFeature
  * @type Number
  */
QStyleOptionToolButton.Arrow = 0x1;

/**
  * @default 0x04
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name Menu
  * @see QStyleOptionToolButton#ToolButtonFeatures
  * @see QStyleOptionToolButton#ToolButtonFeature
  * @type Number
  */
QStyleOptionToolButton.Menu = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name PopupDelay
  * @see QStyleOptionToolButton#ToolButtonFeatures
  * @see QStyleOptionToolButton#ToolButtonFeature
  * @type Number
  */
QStyleOptionToolButton.PopupDelay = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name HasMenu
  * @see QStyleOptionToolButton#ToolButtonFeatures
  * @see QStyleOptionToolButton#ToolButtonFeature
  * @type Number
  */
QStyleOptionToolButton.HasMenu = 0x10;

/**
  * @constructor 
  * @memberOf QStyleOptionToolButton
  * @name ToolButtonFeature
  */
QStyleOptionToolButton.ToolButtonFeature = function(value){;};

/**
  * @constructor 
  * @memberOf QStyleOptionToolButton
  * @name ToolButtonFeatures
  */
QStyleOptionToolButton.ToolButtonFeatures = function(value1, value2 /*, ...*/){;};


/**
  * @default SO_ToolButton
  * @constant
  * @memberOf QStyleOptionToolButton
  * @name Type
  * @see QStyleOptionToolButton#StyleOptionType
  * @type Number
  */
QStyleOptionToolButton.Type = 0xf0003;

/**
  * @constructor 
  * @memberOf QStyleOptionToolButton
  * @name StyleOptionType
  */
QStyleOptionToolButton.StyleOptionType = function(value){;};



