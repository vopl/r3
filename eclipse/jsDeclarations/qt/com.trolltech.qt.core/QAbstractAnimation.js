/**
  * @name QAbstractAnimation
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QAbstractAnimation(parent){return undefined;};

QAbstractAnimation.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractAnimation
  * @name Forward
  * @see QAbstractAnimation#Direction
  * @type Number
  */
QAbstractAnimation.Forward = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractAnimation
  * @name Backward
  * @see QAbstractAnimation#Direction
  * @type Number
  */
QAbstractAnimation.Backward = 0x1;

/**
  * @constructor 
  * @memberOf QAbstractAnimation
  * @name Direction
  */
QAbstractAnimation.Direction = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QAbstractAnimation
  * @name KeepWhenStopped
  * @see QAbstractAnimation#DeletionPolicy
  * @type Number
  */
QAbstractAnimation.KeepWhenStopped = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractAnimation
  * @name DeleteWhenStopped
  * @see QAbstractAnimation#DeletionPolicy
  * @type Number
  */
QAbstractAnimation.DeleteWhenStopped = 0x1;

/**
  * @constructor 
  * @memberOf QAbstractAnimation
  * @name DeletionPolicy
  */
QAbstractAnimation.DeletionPolicy = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractAnimation
  * @name Stopped
  * @see QAbstractAnimation#State
  * @type Number
  */
QAbstractAnimation.Stopped = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractAnimation
  * @name Paused
  * @see QAbstractAnimation#State
  * @type Number
  */
QAbstractAnimation.Paused = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractAnimation
  * @name Running
  * @see QAbstractAnimation#State
  * @type Number
  */
QAbstractAnimation.Running = 0x2;

/**
  * @constructor 
  * @memberOf QAbstractAnimation
  * @name State
  */
QAbstractAnimation.State = function(value){;};



/**
  * @name currentLoopTime
  * @function
  * @memberOf QAbstractAnimation.prototype
  * @returns {Numeric}
  */
QAbstractAnimation.prototype.currentLoopTime = function(){return new Numeric();};

/**
  * @name group
  * @function
  * @memberOf QAbstractAnimation.prototype
  * @returns {QAnimationGroup}
  */
QAbstractAnimation.prototype.group = function(){return new QAnimationGroup();};

/**
  * @name totalDuration
  * @function
  * @memberOf QAbstractAnimation.prototype
  * @returns {Numeric}
  */
QAbstractAnimation.prototype.totalDuration = function(){return new Numeric();};

/**
  * @name state
  * @memberOf QAbstractAnimation.prototype
  * @type QTimeLine.State
  */
QAbstractAnimation.prototype.state = new QTimeLine.State();

/**
  * @name loopCount
  * @memberOf QAbstractAnimation.prototype
  * @type Numeric
  */
QAbstractAnimation.prototype.loopCount = new Numeric();

/**
  * @name currentTime
  * @memberOf QAbstractAnimation.prototype
  * @type Numeric
  */
QAbstractAnimation.prototype.currentTime = new Numeric();

/**
  * @name currentLoop
  * @memberOf QAbstractAnimation.prototype
  * @type Numeric
  */
QAbstractAnimation.prototype.currentLoop = new Numeric();

/**
  * @name direction
  * @memberOf QAbstractAnimation.prototype
  * @type QBoxLayout.Direction
  */
QAbstractAnimation.prototype.direction = new QBoxLayout.Direction();

/**
  * @name duration
  * @memberOf QAbstractAnimation.prototype
  * @type Numeric
  */
QAbstractAnimation.prototype.duration = new Numeric();


