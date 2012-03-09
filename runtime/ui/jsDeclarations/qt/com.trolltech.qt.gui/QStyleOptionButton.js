/**
  * @name QStyleOptionButton
  * @constructor
  * @extends QStyleOption
  */
function QStyleOptionButton(){return undefined;};

/**
  * @name QStyleOptionButton^1
  * @constructor
  * @extends QStyleOption
  * @param {QStyleOptionButton} other
  */
function QStyleOptionButton(other){return undefined;};

QStyleOptionButton.prototype = new QStyleOption();

/**
  * @default 1
  * @constant
  * @memberOf QStyleOptionButton
  * @name Version
  * @see QStyleOptionButton#StyleOptionVersion
  * @type Number
  */
QStyleOptionButton.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOptionButton
  * @name StyleOptionVersion
  */
QStyleOptionButton.StyleOptionVersion = function(value){;};



/**
  * @default 0x00
  * @constant
  * @memberOf QStyleOptionButton
  * @name None
  * @see QStyleOptionButton#ButtonFeatures
  * @see QStyleOptionButton#ButtonFeature
  * @type Number
  */
QStyleOptionButton.None = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QStyleOptionButton
  * @name Flat
  * @see QStyleOptionButton#ButtonFeatures
  * @see QStyleOptionButton#ButtonFeature
  * @type Number
  */
QStyleOptionButton.Flat = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QStyleOptionButton
  * @name HasMenu
  * @see QStyleOptionButton#ButtonFeatures
  * @see QStyleOptionButton#ButtonFeature
  * @type Number
  */
QStyleOptionButton.HasMenu = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QStyleOptionButton
  * @name DefaultButton
  * @see QStyleOptionButton#ButtonFeatures
  * @see QStyleOptionButton#ButtonFeature
  * @type Number
  */
QStyleOptionButton.DefaultButton = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QStyleOptionButton
  * @name AutoDefaultButton
  * @see QStyleOptionButton#ButtonFeatures
  * @see QStyleOptionButton#ButtonFeature
  * @type Number
  */
QStyleOptionButton.AutoDefaultButton = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QStyleOptionButton
  * @name CommandLinkButton
  * @see QStyleOptionButton#ButtonFeatures
  * @see QStyleOptionButton#ButtonFeature
  * @type Number
  */
QStyleOptionButton.CommandLinkButton = 0x10;

/**
  * @constructor 
  * @memberOf QStyleOptionButton
  * @name ButtonFeature
  */
QStyleOptionButton.ButtonFeature = function(value){;};

/**
  * @constructor 
  * @memberOf QStyleOptionButton
  * @name ButtonFeatures
  */
QStyleOptionButton.ButtonFeatures = function(value1, value2 /*, ...*/){;};


/**
  * @default SO_Button
  * @constant
  * @memberOf QStyleOptionButton
  * @name Type
  * @see QStyleOptionButton#StyleOptionType
  * @type Number
  */
QStyleOptionButton.Type = 0x2;

/**
  * @constructor 
  * @memberOf QStyleOptionButton
  * @name StyleOptionType
  */
QStyleOptionButton.StyleOptionType = function(value){;};



