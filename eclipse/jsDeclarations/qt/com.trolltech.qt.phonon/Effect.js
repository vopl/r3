/**
  * @name Effect
  * @constructor
  * @extends QObject
  * @param {EffectDescription} description
  * @param {QObject} parent
  */
function Effect(description, parent){return undefined;};

Effect.prototype = new QObject();

/**
  * @name description
  * @function
  * @memberOf Effect.prototype
  * @returns {EffectDescription}
  */
Effect.prototype.description = function(){return new EffectDescription();};

/**
  * @name parameterValue
  * @function
  * @memberOf Effect.prototype
  * @param {EffectParameter} arg__1
  * @returns {Object}
  */
Effect.prototype.parameterValue = function(arg__1){return new Object();};

/**
  * @name parameters
  * @function
  * @memberOf Effect.prototype
  * @returns {Array}
  */
Effect.prototype.parameters = function(){return new Array();};

/**
  * @name setParameterValue
  * @function
  * @memberOf Effect.prototype
  * @param {EffectParameter} arg__1
  * @param {Object} value
  * @returns {undefined}
  */
Effect.prototype.setParameterValue = function(arg__1, value){return undefined;};

