/**
  * @name QStyleHintReturnVariant
  * @constructor
  * @extends QStyleHintReturn
  */
function QStyleHintReturnVariant(){return undefined;};

QStyleHintReturnVariant.prototype = new QStyleHintReturn();

/**
  * @default 1
  * @constant
  * @memberOf QStyleHintReturnVariant
  * @name Version
  * @see QStyleHintReturnVariant#StyleOptionVersion
  * @type Number
  */
QStyleHintReturnVariant.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleHintReturnVariant
  * @name StyleOptionVersion
  */
QStyleHintReturnVariant.StyleOptionVersion = function(value){;};



/**
  * @default SH_Variant
  * @constant
  * @memberOf QStyleHintReturnVariant
  * @name Type
  * @see QStyleHintReturnVariant#StyleOptionType
  * @type Number
  */
QStyleHintReturnVariant.Type = 0xf002;

/**
  * @constructor 
  * @memberOf QStyleHintReturnVariant
  * @name StyleOptionType
  */
QStyleHintReturnVariant.StyleOptionType = function(value){;};



