/**
  * @name QSizePolicy
  * @constructor
  */
function QSizePolicy(){return undefined;};

/**
  * @name QSizePolicy^1
  * @constructor
  * @param {QSizePolicy.Policy} horizontal
  * @param {QSizePolicy.Policy} vertical
  */
function QSizePolicy(horizontal, vertical){return undefined;};

/**
  * @name QSizePolicy^2
  * @constructor
  * @param {QSizePolicy.Policy} horizontal
  * @param {QSizePolicy.Policy} vertical
  * @param {QSizePolicy.ControlType} type
  */
function QSizePolicy(horizontal, vertical, type){return undefined;};

/**
  * @default 0x00000001
  * @constant
  * @memberOf QSizePolicy
  * @name DefaultType
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.DefaultType = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QSizePolicy
  * @name ButtonBox
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.ButtonBox = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QSizePolicy
  * @name CheckBox
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.CheckBox = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QSizePolicy
  * @name ComboBox
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.ComboBox = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QSizePolicy
  * @name Frame
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.Frame = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QSizePolicy
  * @name GroupBox
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.GroupBox = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QSizePolicy
  * @name Label
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.Label = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf QSizePolicy
  * @name Line
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.Line = 0x80;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QSizePolicy
  * @name LineEdit
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.LineEdit = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QSizePolicy
  * @name PushButton
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.PushButton = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QSizePolicy
  * @name RadioButton
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.RadioButton = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QSizePolicy
  * @name Slider
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.Slider = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QSizePolicy
  * @name SpinBox
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.SpinBox = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QSizePolicy
  * @name TabWidget
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.TabWidget = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QSizePolicy
  * @name ToolButton
  * @see QSizePolicy#ControlTypes
  * @see QSizePolicy#ControlType
  * @type Number
  */
QSizePolicy.ToolButton = 0x4000;

/**
  * @constructor 
  * @memberOf QSizePolicy
  * @name ControlType
  */
QSizePolicy.ControlType = function(value){;};

/**
  * @constructor 
  * @memberOf QSizePolicy
  * @name ControlTypes
  */
QSizePolicy.ControlTypes = function(value1, value2 /*, ...*/){;};


/**
  * @default 1
  * @constant
  * @memberOf QSizePolicy
  * @name GrowFlag
  * @see QSizePolicy#PolicyFlag
  * @type Number
  */
QSizePolicy.GrowFlag = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QSizePolicy
  * @name ExpandFlag
  * @see QSizePolicy#PolicyFlag
  * @type Number
  */
QSizePolicy.ExpandFlag = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf QSizePolicy
  * @name ShrinkFlag
  * @see QSizePolicy#PolicyFlag
  * @type Number
  */
QSizePolicy.ShrinkFlag = 0x4;

/**
  * @default 8
  * @constant
  * @memberOf QSizePolicy
  * @name IgnoreFlag
  * @see QSizePolicy#PolicyFlag
  * @type Number
  */
QSizePolicy.IgnoreFlag = 0x8;

/**
  * @constructor 
  * @memberOf QSizePolicy
  * @name PolicyFlag
  */
QSizePolicy.PolicyFlag = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QSizePolicy
  * @name Fixed
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.Fixed = 0x0;

/**
  * @default GrowFlag
  * @constant
  * @memberOf QSizePolicy
  * @name Minimum
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.Minimum = 0x1;

/**
  * @default GrowFlag|ExpandFlag
  * @constant
  * @memberOf QSizePolicy
  * @name MinimumExpanding
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.MinimumExpanding = 0x3;

/**
  * @default ShrinkFlag
  * @constant
  * @memberOf QSizePolicy
  * @name Maximum
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.Maximum = 0x4;

/**
  * @default GrowFlag|ShrinkFlag
  * @constant
  * @memberOf QSizePolicy
  * @name Preferred
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.Preferred = 0x5;

/**
  * @default GrowFlag|ShrinkFlag|ExpandFlag
  * @constant
  * @memberOf QSizePolicy
  * @name Expanding
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.Expanding = 0x7;

/**
  * @default ShrinkFlag|GrowFlag|IgnoreFlag
  * @constant
  * @memberOf QSizePolicy
  * @name Ignored
  * @see QSizePolicy#Policy
  * @type Number
  */
QSizePolicy.Ignored = 0xd;

/**
  * @constructor 
  * @memberOf QSizePolicy
  * @name Policy
  */
QSizePolicy.Policy = function(value){;};



/**
  * @name controlType
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {QSizePolicy.ControlType}
  */
QSizePolicy.prototype.controlType = function(){return new QSizePolicy.ControlType();};

/**
  * @name expandingDirections
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {Qt.Orientations}
  */
QSizePolicy.prototype.expandingDirections = function(){return new Qt.Orientations();};

/**
  * @name hasHeightForWidth
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {Boolean}
  */
QSizePolicy.prototype.hasHeightForWidth = function(){return new Boolean();};

/**
  * @name hasWidthForHeight
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {Boolean}
  */
QSizePolicy.prototype.hasWidthForHeight = function(){return new Boolean();};

/**
  * @name horizontalPolicy
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {QSizePolicy.Policy}
  */
QSizePolicy.prototype.horizontalPolicy = function(){return new QSizePolicy.Policy();};

/**
  * @name horizontalStretch
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {Numeric}
  */
QSizePolicy.prototype.horizontalStretch = function(){return new Numeric();};

/**
  * @name operator_equal
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {QSizePolicy} s
  * @returns {Boolean}
  */
QSizePolicy.prototype.operator_equal = function(s){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QSizePolicy.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setControlType
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {QSizePolicy.ControlType} type
  * @returns {undefined}
  */
QSizePolicy.prototype.setControlType = function(type){return undefined;};

/**
  * @name setHeightForWidth
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QSizePolicy.prototype.setHeightForWidth = function(b){return undefined;};

/**
  * @name setHorizontalPolicy
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {QSizePolicy.Policy} d
  * @returns {undefined}
  */
QSizePolicy.prototype.setHorizontalPolicy = function(d){return undefined;};

/**
  * @name setHorizontalStretch
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {Numeric} stretchFactor
  * @returns {undefined}
  */
QSizePolicy.prototype.setHorizontalStretch = function(stretchFactor){return undefined;};

/**
  * @name setVerticalPolicy
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {QSizePolicy.Policy} d
  * @returns {undefined}
  */
QSizePolicy.prototype.setVerticalPolicy = function(d){return undefined;};

/**
  * @name setVerticalStretch
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {Numeric} stretchFactor
  * @returns {undefined}
  */
QSizePolicy.prototype.setVerticalStretch = function(stretchFactor){return undefined;};

/**
  * @name setWidthForHeight
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QSizePolicy.prototype.setWidthForHeight = function(b){return undefined;};

/**
  * @name transpose
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {undefined}
  */
QSizePolicy.prototype.transpose = function(){return undefined;};

/**
  * @name verticalPolicy
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {QSizePolicy.Policy}
  */
QSizePolicy.prototype.verticalPolicy = function(){return new QSizePolicy.Policy();};

/**
  * @name verticalStretch
  * @function
  * @memberOf QSizePolicy.prototype
  * @returns {Numeric}
  */
QSizePolicy.prototype.verticalStretch = function(){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QSizePolicy.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QSizePolicy.prototype.writeTo = function(arg__1){return undefined;};

