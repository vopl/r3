/**
  * @name QAnimationGroup
  * @constructor
  * @extends QAbstractAnimation
  * @param {QObject} parent
  */
function QAnimationGroup(parent){return undefined;};

QAnimationGroup.prototype = new QAbstractAnimation();

/**
  * @name addAnimation
  * @function
  * @memberOf QAnimationGroup.prototype
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QAnimationGroup.prototype.addAnimation = function(animation){return undefined;};

/**
  * @name animationAt
  * @function
  * @memberOf QAnimationGroup.prototype
  * @param {Numeric} index
  * @returns {QAbstractAnimation}
  */
QAnimationGroup.prototype.animationAt = function(index){return new QAbstractAnimation();};

/**
  * @name animationCount
  * @function
  * @memberOf QAnimationGroup.prototype
  * @returns {Numeric}
  */
QAnimationGroup.prototype.animationCount = function(){return new Numeric();};

/**
  * @name clear
  * @function
  * @memberOf QAnimationGroup.prototype
  * @returns {undefined}
  */
QAnimationGroup.prototype.clear = function(){return undefined;};

/**
  * @name indexOfAnimation
  * @function
  * @memberOf QAnimationGroup.prototype
  * @param {QAbstractAnimation} animation
  * @returns {Numeric}
  */
QAnimationGroup.prototype.indexOfAnimation = function(animation){return new Numeric();};

/**
  * @name insertAnimation
  * @function
  * @memberOf QAnimationGroup.prototype
  * @param {Numeric} index
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QAnimationGroup.prototype.insertAnimation = function(index, animation){return undefined;};

/**
  * @name removeAnimation
  * @function
  * @memberOf QAnimationGroup.prototype
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QAnimationGroup.prototype.removeAnimation = function(animation){return undefined;};

/**
  * @name takeAnimation
  * @function
  * @memberOf QAnimationGroup.prototype
  * @param {Numeric} index
  * @returns {QAbstractAnimation}
  */
QAnimationGroup.prototype.takeAnimation = function(index){return new QAbstractAnimation();};

