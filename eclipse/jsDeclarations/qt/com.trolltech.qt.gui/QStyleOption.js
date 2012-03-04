/**
  * @name QStyleOption
  * @constructor
  * @param {QStyleOption} other
  */
function QStyleOption(other){return undefined;};

/**
  * @name QStyleOption^1
  * @constructor
  * @param {Numeric} version
  * @param {Numeric} type
  */
function QStyleOption(version, type){return undefined;};

/**
  * @default 1
  * @constant
  * @memberOf QStyleOption
  * @name Version
  * @see QStyleOption#StyleOptionVersion
  * @type Number
  */
QStyleOption.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOption
  * @name StyleOptionVersion
  */
QStyleOption.StyleOptionVersion = function(value){;};



/**
  * @default SO_Default
  * @constant
  * @memberOf QStyleOption
  * @name Type
  * @see QStyleOption#StyleOptionType
  * @type Number
  */
QStyleOption.Type = 0x0;

/**
  * @constructor 
  * @memberOf QStyleOption
  * @name StyleOptionType
  */
QStyleOption.StyleOptionType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOption
  * @name SO_Default
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Default = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOption
  * @name SO_FocusRect
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_FocusRect = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOption
  * @name SO_Button
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Button = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyleOption
  * @name SO_Tab
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Tab = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QStyleOption
  * @name SO_MenuItem
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_MenuItem = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QStyleOption
  * @name SO_Frame
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Frame = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QStyleOption
  * @name SO_ProgressBar
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ProgressBar = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QStyleOption
  * @name SO_ToolBox
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ToolBox = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QStyleOption
  * @name SO_Header
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Header = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QStyleOption
  * @name SO_Q3DockWindow
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Q3DockWindow = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QStyleOption
  * @name SO_DockWidget
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_DockWidget = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QStyleOption
  * @name SO_Q3ListViewItem
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Q3ListViewItem = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QStyleOption
  * @name SO_ViewItem
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ViewItem = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QStyleOption
  * @name SO_TabWidgetFrame
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_TabWidgetFrame = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QStyleOption
  * @name SO_TabBarBase
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_TabBarBase = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QStyleOption
  * @name SO_RubberBand
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_RubberBand = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyleOption
  * @name SO_ToolBar
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ToolBar = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QStyleOption
  * @name SO_GraphicsItem
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_GraphicsItem = 0x11;

/**
  * @default 0xf00
  * @constant
  * @memberOf QStyleOption
  * @name SO_CustomBase
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_CustomBase = 0xf00;

/**
  * @default 0xf0000
  * @constant
  * @memberOf QStyleOption
  * @name SO_Complex
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Complex = 0xf0000;

/**
  * @default 0xf0001
  * @constant
  * @memberOf QStyleOption
  * @name SO_Slider
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Slider = 0xf0001;

/**
  * @default 0xf0002
  * @constant
  * @memberOf QStyleOption
  * @name SO_SpinBox
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_SpinBox = 0xf0002;

/**
  * @default 0xf0003
  * @constant
  * @memberOf QStyleOption
  * @name SO_ToolButton
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ToolButton = 0xf0003;

/**
  * @default 0xf0004
  * @constant
  * @memberOf QStyleOption
  * @name SO_ComboBox
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ComboBox = 0xf0004;

/**
  * @default 0xf0005
  * @constant
  * @memberOf QStyleOption
  * @name SO_Q3ListView
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_Q3ListView = 0xf0005;

/**
  * @default 0xf0006
  * @constant
  * @memberOf QStyleOption
  * @name SO_TitleBar
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_TitleBar = 0xf0006;

/**
  * @default 0xf0007
  * @constant
  * @memberOf QStyleOption
  * @name SO_GroupBox
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_GroupBox = 0xf0007;

/**
  * @default 0xf0008
  * @constant
  * @memberOf QStyleOption
  * @name SO_SizeGrip
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_SizeGrip = 0xf0008;

/**
  * @default 0xf000000
  * @constant
  * @memberOf QStyleOption
  * @name SO_ComplexCustomBase
  * @see QStyleOption#OptionType
  * @type Number
  */
QStyleOption.SO_ComplexCustomBase = 0xf000000;

/**
  * @constructor 
  * @memberOf QStyleOption
  * @name OptionType
  */
QStyleOption.OptionType = function(value){;};



/**
  * @name initFrom
  * @function
  * @memberOf QStyleOption.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QStyleOption.prototype.initFrom = function(w){return undefined;};

