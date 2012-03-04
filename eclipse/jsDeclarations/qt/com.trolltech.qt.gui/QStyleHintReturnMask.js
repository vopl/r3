/**
  * @name QStyleHintReturnMask
  * @constructor
  * @extends QStyleHintReturn
  */
function QStyleHintReturnMask(){return undefined;};

QStyleHintReturnMask.prototype = new QStyleHintReturn();

/**
  * @default 1
  * @constant
  * @memberOf QStyleHintReturnMask
  * @name Version
  * @see QStyleHintReturnMask#StyleOptionVersion
  * @type Number
  */
QStyleHintReturnMask.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleHintReturnMask
  * @name StyleOptionVersion
  */
QStyleHintReturnMask.StyleOptionVersion = function(value){;};



/**
  * @default SH_Mask
  * @constant
  * @memberOf QStyleHintReturnMask
  * @name Type
  * @see QStyleHintReturnMask#StyleOptionType
  * @type Number
  */
QStyleHintReturnMask.Type = 0xf001;

/**
  * @constructor 
  * @memberOf QStyleHintReturnMask
  * @name StyleOptionType
  */
QStyleHintReturnMask.StyleOptionType = function(value){;};



