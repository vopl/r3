/**
  * @name QLCDNumber
  * @constructor
  * @extends QFrame
  * @param {QWidget} parent
  */
function QLCDNumber(parent){return undefined;};

/**
  * @name QLCDNumber^1
  * @constructor
  * @extends QFrame
  * @param {Numeric} numDigits
  * @param {QWidget} parent
  */
function QLCDNumber(numDigits, parent){return undefined;};

QLCDNumber.prototype = new QFrame();

/**
  * @default 0x0
  * @constant
  * @memberOf QLCDNumber
  * @name Hex
  * @see QLCDNumber#Mode
  * @type Number
  */
QLCDNumber.Hex = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLCDNumber
  * @name Dec
  * @see QLCDNumber#Mode
  * @type Number
  */
QLCDNumber.Dec = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QLCDNumber
  * @name Oct
  * @see QLCDNumber#Mode
  * @type Number
  */
QLCDNumber.Oct = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QLCDNumber
  * @name Bin
  * @see QLCDNumber#Mode
  * @type Number
  */
QLCDNumber.Bin = 0x3;

/**
  * @constructor 
  * @memberOf QLCDNumber
  * @name Mode
  */
QLCDNumber.Mode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QLCDNumber
  * @name Outline
  * @see QLCDNumber#SegmentStyle
  * @type Number
  */
QLCDNumber.Outline = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLCDNumber
  * @name Filled
  * @see QLCDNumber#SegmentStyle
  * @type Number
  */
QLCDNumber.Filled = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QLCDNumber
  * @name Flat
  * @see QLCDNumber#SegmentStyle
  * @type Number
  */
QLCDNumber.Flat = 0x2;

/**
  * @constructor 
  * @memberOf QLCDNumber
  * @name SegmentStyle
  */
QLCDNumber.SegmentStyle = function(value){;};



/**
  * @name checkOverflow
  * @function
  * @memberOf QLCDNumber.prototype
  * @param {Numeric} num
  * @returns {Boolean}
  */
QLCDNumber.prototype.checkOverflow = function(num){return new Boolean();};

/**
  * @name smallDecimalPoint
  * @memberOf QLCDNumber.prototype
  * @type Boolean
  */
QLCDNumber.prototype.smallDecimalPoint = new Boolean();

/**
  * @name numDigits
  * @memberOf QLCDNumber.prototype
  * @type Numeric
  */
QLCDNumber.prototype.numDigits = new Numeric();

/**
  * @name digitCount
  * @memberOf QLCDNumber.prototype
  * @type Numeric
  */
QLCDNumber.prototype.digitCount = new Numeric();

/**
  * @name mode
  * @memberOf QLCDNumber.prototype
  * @type QLCDNumber.Mode
  */
QLCDNumber.prototype.mode = new QLCDNumber.Mode();

/**
  * @name segmentStyle
  * @memberOf QLCDNumber.prototype
  * @type QLCDNumber.SegmentStyle
  */
QLCDNumber.prototype.segmentStyle = new QLCDNumber.SegmentStyle();

/**
  * @name value
  * @memberOf QLCDNumber.prototype
  * @type Numeric
  */
QLCDNumber.prototype.value = new Numeric();

/**
  * @name intValue
  * @memberOf QLCDNumber.prototype
  * @type Numeric
  */
QLCDNumber.prototype.intValue = new Numeric();


