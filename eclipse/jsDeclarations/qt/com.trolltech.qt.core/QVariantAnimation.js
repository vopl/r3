/**
  * @name QVariantAnimation
  * @constructor
  * @extends QAbstractAnimation
  * @param {QObject} parent
  */
function QVariantAnimation(parent){return undefined;};

QVariantAnimation.prototype = new QAbstractAnimation();

/**
  * @name keyValueAt
  * @function
  * @memberOf QVariantAnimation.prototype
  * @param {Numeric} step
  * @returns {Object}
  */
QVariantAnimation.prototype.keyValueAt = function(step){return new Object();};

/**
  * @name keyValues
  * @function
  * @memberOf QVariantAnimation.prototype
  * @returns {Array}
  */
QVariantAnimation.prototype.keyValues = function(){return new Array();};

/**
  * @name setKeyValueAt
  * @function
  * @memberOf QVariantAnimation.prototype
  * @param {Numeric} step
  * @param {Object} value
  * @returns {undefined}
  */
QVariantAnimation.prototype.setKeyValueAt = function(step, value){return undefined;};

/**
  * @name setKeyValues
  * @function
  * @memberOf QVariantAnimation.prototype
  * @param {Array} values
  * @returns {undefined}
  */
QVariantAnimation.prototype.setKeyValues = function(values){return undefined;};

/**
  * @name startValue
  * @memberOf QVariantAnimation.prototype
  * @type Object
  */
QVariantAnimation.prototype.startValue = new Object();

/**
  * @name endValue
  * @memberOf QVariantAnimation.prototype
  * @type Object
  */
QVariantAnimation.prototype.endValue = new Object();

/**
  * @name currentValue
  * @memberOf QVariantAnimation.prototype
  * @type Object
  */
QVariantAnimation.prototype.currentValue = new Object();

/**
  * @name duration
  * @memberOf QVariantAnimation.prototype
  * @type Numeric
  */
QVariantAnimation.prototype.duration = new Numeric();

/**
  * @name easingCurve
  * @memberOf QVariantAnimation.prototype
  * @type QEasingCurve
  */
QVariantAnimation.prototype.easingCurve = new QEasingCurve();


