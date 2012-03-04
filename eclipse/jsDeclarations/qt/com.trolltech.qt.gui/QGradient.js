/**
  * @name QGradient
  * @constructor
  */
function QGradient(){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QGradient
  * @name LogicalMode
  * @see QGradient#CoordinateMode
  * @type Number
  */
QGradient.LogicalMode = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGradient
  * @name StretchToDeviceMode
  * @see QGradient#CoordinateMode
  * @type Number
  */
QGradient.StretchToDeviceMode = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGradient
  * @name ObjectBoundingMode
  * @see QGradient#CoordinateMode
  * @type Number
  */
QGradient.ObjectBoundingMode = 0x2;

/**
  * @constructor 
  * @memberOf QGradient
  * @name CoordinateMode
  */
QGradient.CoordinateMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QGradient
  * @name PadSpread
  * @see QGradient#Spread
  * @type Number
  */
QGradient.PadSpread = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGradient
  * @name ReflectSpread
  * @see QGradient#Spread
  * @type Number
  */
QGradient.ReflectSpread = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGradient
  * @name RepeatSpread
  * @see QGradient#Spread
  * @type Number
  */
QGradient.RepeatSpread = 0x2;

/**
  * @constructor 
  * @memberOf QGradient
  * @name Spread
  */
QGradient.Spread = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QGradient
  * @name LinearGradient
  * @see QGradient#Type
  * @type Number
  */
QGradient.LinearGradient = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGradient
  * @name RadialGradient
  * @see QGradient#Type
  * @type Number
  */
QGradient.RadialGradient = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGradient
  * @name ConicalGradient
  * @see QGradient#Type
  * @type Number
  */
QGradient.ConicalGradient = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QGradient
  * @name NoGradient
  * @see QGradient#Type
  * @type Number
  */
QGradient.NoGradient = 0x3;

/**
  * @constructor 
  * @memberOf QGradient
  * @name Type
  */
QGradient.Type = function(value){;};



/**
  * @name coordinateMode
  * @function
  * @memberOf QGradient.prototype
  * @returns {QGradient.CoordinateMode}
  */
QGradient.prototype.coordinateMode = function(){return new QGradient.CoordinateMode();};

/**
  * @name operator_equal
  * @function
  * @memberOf QGradient.prototype
  * @param {QGradient} gradient
  * @returns {Boolean}
  */
QGradient.prototype.operator_equal = function(gradient){return new Boolean();};

/**
  * @name setColorAt
  * @function
  * @memberOf QGradient.prototype
  * @param {Numeric} pos
  * @param {QColor} color
  * @returns {undefined}
  */
QGradient.prototype.setColorAt = function(pos, color){return undefined;};

/**
  * @name setCoordinateMode
  * @function
  * @memberOf QGradient.prototype
  * @param {QGradient.CoordinateMode} mode
  * @returns {undefined}
  */
QGradient.prototype.setCoordinateMode = function(mode){return undefined;};

/**
  * @name setSpread
  * @function
  * @memberOf QGradient.prototype
  * @param {QGradient.Spread} spread
  * @returns {undefined}
  */
QGradient.prototype.setSpread = function(spread){return undefined;};

/**
  * @name setStops
  * @function
  * @memberOf QGradient.prototype
  * @param {Array} stops
  * @returns {undefined}
  */
QGradient.prototype.setStops = function(stops){return undefined;};

/**
  * @name spread
  * @function
  * @memberOf QGradient.prototype
  * @returns {QGradient.Spread}
  */
QGradient.prototype.spread = function(){return new QGradient.Spread();};

/**
  * @name stops
  * @function
  * @memberOf QGradient.prototype
  * @returns {Array}
  */
QGradient.prototype.stops = function(){return new Array();};

/**
  * @name type
  * @function
  * @memberOf QGradient.prototype
  * @returns {QApplication.Type}
  */
QGradient.prototype.type = function(){return new QApplication.Type();};

