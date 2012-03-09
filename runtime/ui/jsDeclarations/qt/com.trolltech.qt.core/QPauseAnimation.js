/**
  * @name QPauseAnimation
  * @constructor
  * @extends QAbstractAnimation
  * @param {QObject} parent
  */
function QPauseAnimation(parent){return undefined;};

/**
  * @name QPauseAnimation^1
  * @constructor
  * @extends QAbstractAnimation
  * @param {Numeric} msecs
  * @param {QObject} parent
  */
function QPauseAnimation(msecs, parent){return undefined;};

QPauseAnimation.prototype = new QAbstractAnimation();

/**
  * @name duration
  * @memberOf QPauseAnimation.prototype
  * @type Numeric
  */
QPauseAnimation.prototype.duration = new Numeric();


