/**
  * @name QSequentialAnimationGroup
  * @constructor
  * @extends QAnimationGroup
  * @param {QObject} parent
  */
function QSequentialAnimationGroup(parent){return undefined;};

QSequentialAnimationGroup.prototype = new QAnimationGroup();

/**
  * @name addPause
  * @function
  * @memberOf QSequentialAnimationGroup.prototype
  * @param {Numeric} msecs
  * @returns {QPauseAnimation}
  */
QSequentialAnimationGroup.prototype.addPause = function(msecs){return new QPauseAnimation();};

/**
  * @name insertPause
  * @function
  * @memberOf QSequentialAnimationGroup.prototype
  * @param {Numeric} index
  * @param {Numeric} msecs
  * @returns {QPauseAnimation}
  */
QSequentialAnimationGroup.prototype.insertPause = function(index, msecs){return new QPauseAnimation();};

/**
  * @name currentAnimation
  * @memberOf QSequentialAnimationGroup.prototype
  * @type QAbstractAnimation
  */
QSequentialAnimationGroup.prototype.currentAnimation = new QAbstractAnimation();


