/**
  * @name EffectParameter
  * @constructor
  * @param {Numeric} parameterId
  * @param {String} name
  * @param {EffectParameter.Hints} hints
  * @param {Object} defaultValue
  * @param {Object} min
  * @param {Object} max
  * @param {Array} values
  * @param {String} description
  */
function EffectParameter(parameterId, name, hints, defaultValue, min, max, values, description){return undefined;};

/**
  * @default 0x04
  * @constant
  * @memberOf EffectParameter
  * @name ToggledHint
  * @see EffectParameter#Hints
  * @see EffectParameter#Hint
  * @type Number
  */
EffectParameter.ToggledHint = 0x4;

/**
  * @default 0x10
  * @constant
  * @memberOf EffectParameter
  * @name LogarithmicHint
  * @see EffectParameter#Hints
  * @see EffectParameter#Hint
  * @type Number
  */
EffectParameter.LogarithmicHint = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf EffectParameter
  * @name IntegerHint
  * @see EffectParameter#Hints
  * @see EffectParameter#Hint
  * @type Number
  */
EffectParameter.IntegerHint = 0x20;

/**
  * @constructor 
  * @memberOf EffectParameter
  * @name Hint
  */
EffectParameter.Hint = function(value){;};

/**
  * @constructor 
  * @memberOf EffectParameter
  * @name Hints
  */
EffectParameter.Hints = function(value1, value2 /*, ...*/){;};


/**
  * @name defaultValue
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {Object}
  */
EffectParameter.prototype.defaultValue = function(){return new Object();};

/**
  * @name description
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {String}
  */
EffectParameter.prototype.description = function(){return new String();};

/**
  * @name isLogarithmicControl
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {Boolean}
  */
EffectParameter.prototype.isLogarithmicControl = function(){return new Boolean();};

/**
  * @name maximumValue
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {Object}
  */
EffectParameter.prototype.maximumValue = function(){return new Object();};

/**
  * @name minimumValue
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {Object}
  */
EffectParameter.prototype.minimumValue = function(){return new Object();};

/**
  * @name name
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {String}
  */
EffectParameter.prototype.name = function(){return new String();};

/**
  * @name possibleValues
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {Array}
  */
EffectParameter.prototype.possibleValues = function(){return new Array();};

/**
  * @name type
  * @function
  * @memberOf EffectParameter.prototype
  * @returns {Object}
  */
EffectParameter.prototype.type = function(){return new Object();};

