/**
  * @name QFrame
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QFrame(parent, f){return undefined;};

QFrame.prototype = new QWidget();

/**
  * @default 0x000f
  * @constant
  * @memberOf QFrame
  * @name Shape_Mask
  * @see QFrame#StyleMask
  * @type Number
  */
QFrame.Shape_Mask = 0xf;

/**
  * @default 0x00f0
  * @constant
  * @memberOf QFrame
  * @name Shadow_Mask
  * @see QFrame#StyleMask
  * @type Number
  */
QFrame.Shadow_Mask = 0xf0;

/**
  * @constructor 
  * @memberOf QFrame
  * @name StyleMask
  */
QFrame.StyleMask = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QFrame
  * @name NoFrame
  * @see QFrame#Shape
  * @type Number
  */
QFrame.NoFrame = 0x0;

/**
  * @default 0x0001
  * @constant
  * @memberOf QFrame
  * @name Box
  * @see QFrame#Shape
  * @type Number
  */
QFrame.Box = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QFrame
  * @name Panel
  * @see QFrame#Shape
  * @type Number
  */
QFrame.Panel = 0x2;

/**
  * @default 0x0003
  * @constant
  * @memberOf QFrame
  * @name WinPanel
  * @see QFrame#Shape
  * @type Number
  */
QFrame.WinPanel = 0x3;

/**
  * @default 0x0004
  * @constant
  * @memberOf QFrame
  * @name HLine
  * @see QFrame#Shape
  * @type Number
  */
QFrame.HLine = 0x4;

/**
  * @default 0x0005
  * @constant
  * @memberOf QFrame
  * @name VLine
  * @see QFrame#Shape
  * @type Number
  */
QFrame.VLine = 0x5;

/**
  * @default 0x0006
  * @constant
  * @memberOf QFrame
  * @name StyledPanel
  * @see QFrame#Shape
  * @type Number
  */
QFrame.StyledPanel = 0x6;

/**
  * @constructor 
  * @memberOf QFrame
  * @name Shape
  */
QFrame.Shape = function(value){;};



/**
  * @default 0x0010
  * @constant
  * @memberOf QFrame
  * @name Plain
  * @see QFrame#Shadow
  * @type Number
  */
QFrame.Plain = 0x10;

/**
  * @default 0x0020
  * @constant
  * @memberOf QFrame
  * @name Raised
  * @see QFrame#Shadow
  * @type Number
  */
QFrame.Raised = 0x20;

/**
  * @default 0x0030
  * @constant
  * @memberOf QFrame
  * @name Sunken
  * @see QFrame#Shadow
  * @type Number
  */
QFrame.Sunken = 0x30;

/**
  * @constructor 
  * @memberOf QFrame
  * @name Shadow
  */
QFrame.Shadow = function(value){;};



/**
  * @name frameStyle
  * @function
  * @memberOf QFrame.prototype
  * @returns {Numeric}
  */
QFrame.prototype.frameStyle = function(){return new Numeric();};

/**
  * @name setFrameStyle
  * @function
  * @memberOf QFrame.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QFrame.prototype.setFrameStyle = function(arg__1){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QFrame.prototype
  * @returns {QSize}
  */
QFrame.prototype.sizeHint = function(){return new QSize();};

/**
  * @name frameShape
  * @memberOf QFrame.prototype
  * @type QTabBar.Shape
  */
QFrame.prototype.frameShape = new QTabBar.Shape();

/**
  * @name frameShadow
  * @memberOf QFrame.prototype
  * @type QFrame.Shadow
  */
QFrame.prototype.frameShadow = new QFrame.Shadow();

/**
  * @name lineWidth
  * @memberOf QFrame.prototype
  * @type Numeric
  */
QFrame.prototype.lineWidth = new Numeric();

/**
  * @name midLineWidth
  * @memberOf QFrame.prototype
  * @type Numeric
  */
QFrame.prototype.midLineWidth = new Numeric();

/**
  * @name frameWidth
  * @memberOf QFrame.prototype
  * @type Numeric
  */
QFrame.prototype.frameWidth = new Numeric();

/**
  * @name frameRect
  * @memberOf QFrame.prototype
  * @type QRect
  */
QFrame.prototype.frameRect = new QRect();


