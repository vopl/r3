/**
  * @name QStyleOptionHeader
  * @constructor
  * @extends QStyleOption
  */
function QStyleOptionHeader(){return undefined;};

/**
  * @name QStyleOptionHeader^1
  * @constructor
  * @extends QStyleOption
  * @param {QStyleOptionHeader} other
  */
function QStyleOptionHeader(other){return undefined;};

QStyleOptionHeader.prototype = new QStyleOption();

/**
  * @default 1
  * @constant
  * @memberOf QStyleOptionHeader
  * @name Version
  * @see QStyleOptionHeader#StyleOptionVersion
  * @type Number
  */
QStyleOptionHeader.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOptionHeader
  * @name StyleOptionVersion
  */
QStyleOptionHeader.StyleOptionVersion = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOptionHeader
  * @name Beginning
  * @see QStyleOptionHeader#SectionPosition
  * @type Number
  */
QStyleOptionHeader.Beginning = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOptionHeader
  * @name Middle
  * @see QStyleOptionHeader#SectionPosition
  * @type Number
  */
QStyleOptionHeader.Middle = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOptionHeader
  * @name End
  * @see QStyleOptionHeader#SectionPosition
  * @type Number
  */
QStyleOptionHeader.End = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyleOptionHeader
  * @name OnlyOneSection
  * @see QStyleOptionHeader#SectionPosition
  * @type Number
  */
QStyleOptionHeader.OnlyOneSection = 0x3;

/**
  * @constructor 
  * @memberOf QStyleOptionHeader
  * @name SectionPosition
  */
QStyleOptionHeader.SectionPosition = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOptionHeader
  * @name NotAdjacent
  * @see QStyleOptionHeader#SelectedPosition
  * @type Number
  */
QStyleOptionHeader.NotAdjacent = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOptionHeader
  * @name NextIsSelected
  * @see QStyleOptionHeader#SelectedPosition
  * @type Number
  */
QStyleOptionHeader.NextIsSelected = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOptionHeader
  * @name PreviousIsSelected
  * @see QStyleOptionHeader#SelectedPosition
  * @type Number
  */
QStyleOptionHeader.PreviousIsSelected = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyleOptionHeader
  * @name NextAndPreviousAreSelected
  * @see QStyleOptionHeader#SelectedPosition
  * @type Number
  */
QStyleOptionHeader.NextAndPreviousAreSelected = 0x3;

/**
  * @constructor 
  * @memberOf QStyleOptionHeader
  * @name SelectedPosition
  */
QStyleOptionHeader.SelectedPosition = function(value){;};



/**
  * @default SO_Header
  * @constant
  * @memberOf QStyleOptionHeader
  * @name Type
  * @see QStyleOptionHeader#StyleOptionType
  * @type Number
  */
QStyleOptionHeader.Type = 0x8;

/**
  * @constructor 
  * @memberOf QStyleOptionHeader
  * @name StyleOptionType
  */
QStyleOptionHeader.StyleOptionType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOptionHeader
  * @name None
  * @see QStyleOptionHeader#SortIndicator
  * @type Number
  */
QStyleOptionHeader.None = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOptionHeader
  * @name SortUp
  * @see QStyleOptionHeader#SortIndicator
  * @type Number
  */
QStyleOptionHeader.SortUp = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOptionHeader
  * @name SortDown
  * @see QStyleOptionHeader#SortIndicator
  * @type Number
  */
QStyleOptionHeader.SortDown = 0x2;

/**
  * @constructor 
  * @memberOf QStyleOptionHeader
  * @name SortIndicator
  */
QStyleOptionHeader.SortIndicator = function(value){;};



