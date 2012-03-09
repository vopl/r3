/**
  * @name QStyleOptionViewItem
  * @constructor
  * @extends QStyleOption
  */
function QStyleOptionViewItem(){return undefined;};

/**
  * @name QStyleOptionViewItem^1
  * @constructor
  * @extends QStyleOption
  * @param {QStyleOptionViewItem} other
  */
function QStyleOptionViewItem(other){return undefined;};

QStyleOptionViewItem.prototype = new QStyleOption();

/**
  * @default 1
  * @constant
  * @memberOf QStyleOptionViewItem
  * @name Version
  * @see QStyleOptionViewItem#StyleOptionVersion
  * @type Number
  */
QStyleOptionViewItem.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOptionViewItem
  * @name StyleOptionVersion
  */
QStyleOptionViewItem.StyleOptionVersion = function(value){;};



/**
  * @default SO_ViewItem
  * @constant
  * @memberOf QStyleOptionViewItem
  * @name Type
  * @see QStyleOptionViewItem#StyleOptionType
  * @type Number
  */
QStyleOptionViewItem.Type = 0xc;

/**
  * @constructor 
  * @memberOf QStyleOptionViewItem
  * @name StyleOptionType
  */
QStyleOptionViewItem.StyleOptionType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStyleOptionViewItem
  * @name Left
  * @see QStyleOptionViewItem#Position
  * @type Number
  */
QStyleOptionViewItem.Left = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStyleOptionViewItem
  * @name Right
  * @see QStyleOptionViewItem#Position
  * @type Number
  */
QStyleOptionViewItem.Right = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStyleOptionViewItem
  * @name Top
  * @see QStyleOptionViewItem#Position
  * @type Number
  */
QStyleOptionViewItem.Top = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStyleOptionViewItem
  * @name Bottom
  * @see QStyleOptionViewItem#Position
  * @type Number
  */
QStyleOptionViewItem.Bottom = 0x3;

/**
  * @constructor 
  * @memberOf QStyleOptionViewItem
  * @name Position
  */
QStyleOptionViewItem.Position = function(value){;};



