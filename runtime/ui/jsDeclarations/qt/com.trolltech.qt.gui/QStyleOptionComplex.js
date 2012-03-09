/**
  * @name QStyleOptionComplex
  * @constructor
  * @extends QStyleOption
  * @param {QStyleOptionComplex} other
  */
function QStyleOptionComplex(other){return undefined;};

/**
  * @name QStyleOptionComplex^1
  * @constructor
  * @extends QStyleOption
  * @param {Numeric} version
  * @param {Numeric} type
  */
function QStyleOptionComplex(version, type){return undefined;};

QStyleOptionComplex.prototype = new QStyleOption();

/**
  * @default 1
  * @constant
  * @memberOf QStyleOptionComplex
  * @name Version
  * @see QStyleOptionComplex#StyleOptionVersion
  * @type Number
  */
QStyleOptionComplex.Version = 0x1;

/**
  * @constructor 
  * @memberOf QStyleOptionComplex
  * @name StyleOptionVersion
  */
QStyleOptionComplex.StyleOptionVersion = function(value){;};



/**
  * @default SO_Complex
  * @constant
  * @memberOf QStyleOptionComplex
  * @name Type
  * @see QStyleOptionComplex#StyleOptionType
  * @type Number
  */
QStyleOptionComplex.Type = 0xf0000;

/**
  * @constructor 
  * @memberOf QStyleOptionComplex
  * @name StyleOptionType
  */
QStyleOptionComplex.StyleOptionType = function(value){;};



