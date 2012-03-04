/**
  * @name QStyleOptionTab
  * @constructor
  * @extends QStyleOption
  */
function QStyleOptionTab(){return undefined;};

/**
  * @name QStyleOptionTab^1
  * @constructor
  * @extends QStyleOption
  * @param {QStyleOptionTab} other
  */
function QStyleOptionTab(other){return undefined;};

QStyleOptionTab.prototype = new QStyleOption();

/**
  * @default 1
  * @constant
  * @memberOf QStyleOptionTab
  * @name Version
  * @see QStyleOptionTab#StyleOptionVersion
  * @type Number
  */
QStyleOptionTab.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOptionTab
  * @name StyleOptionVersion
  */
QStyleOptionTab.StyleOptionVersion = function(value){;};



/**
  * @default 0x00
  * @constant
  * @memberOf QStyleOptionTab
  * @name NoCornerWidgets
  * @see QStyleOptionTab#CornerWidgets
  * @see QStyleOptionTab#CornerWidget
  * @type Number
  */
QStyleOptionTab.NoCornerWidgets = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QStyleOptionTab
  * @name LeftCornerWidget
  * @see QStyleOptionTab#CornerWidgets
  * @see QStyleOptionTab#CornerWidget
  * @type Number
  */
QStyleOptionTab.LeftCornerWidget = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QStyleOptionTab
  * @name RightCornerWidget
  * @see QStyleOptionTab#CornerWidgets
  * @see QStyleOptionTab#CornerWidget
  * @type Number
  */
QStyleOptionTab.RightCornerWidget = 0x2;

/**
  * @constructor 
  * @memberOf QStyleOptionTab
  * @name CornerWidget
  */
QStyleOptionTab.CornerWidget = function(value){;};

/**
  * @constructor 
  * @memberOf QStyleOptionTab
  * @name CornerWidgets
  */
QStyleOptionTab.CornerWidgets = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOptionTab
  * @name Beginning
  * @see QStyleOptionTab#TabPosition
  * @type Number
  */
QStyleOptionTab.Beginning = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOptionTab
  * @name Middle
  * @see QStyleOptionTab#TabPosition
  * @type Number
  */
QStyleOptionTab.Middle = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOptionTab
  * @name End
  * @see QStyleOptionTab#TabPosition
  * @type Number
  */
QStyleOptionTab.End = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyleOptionTab
  * @name OnlyOneTab
  * @see QStyleOptionTab#TabPosition
  * @type Number
  */
QStyleOptionTab.OnlyOneTab = 0x3;

/**
  * @constructor 
  * @memberOf QStyleOptionTab
  * @name TabPosition
  */
QStyleOptionTab.TabPosition = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOptionTab
  * @name NotAdjacent
  * @see QStyleOptionTab#SelectedPosition
  * @type Number
  */
QStyleOptionTab.NotAdjacent = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOptionTab
  * @name NextIsSelected
  * @see QStyleOptionTab#SelectedPosition
  * @type Number
  */
QStyleOptionTab.NextIsSelected = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOptionTab
  * @name PreviousIsSelected
  * @see QStyleOptionTab#SelectedPosition
  * @type Number
  */
QStyleOptionTab.PreviousIsSelected = 0x2;

/**
  * @constructor 
  * @memberOf QStyleOptionTab
  * @name SelectedPosition
  */
QStyleOptionTab.SelectedPosition = function(value){;};



/**
  * @default SO_Tab
  * @constant
  * @memberOf QStyleOptionTab
  * @name Type
  * @see QStyleOptionTab#StyleOptionType
  * @type Number
  */
QStyleOptionTab.Type = 0x3;

/**
  * @constructor 
  * @memberOf QStyleOptionTab
  * @name StyleOptionType
  */
QStyleOptionTab.StyleOptionType = function(value){;};



