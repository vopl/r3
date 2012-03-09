/**
  * @name QTimeLine
  * @constructor
  * @extends QObject
  * @param {Numeric} duration
  * @param {QObject} parent
  */
function QTimeLine(duration, parent){return undefined;};

QTimeLine.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QTimeLine
  * @name Forward
  * @see QTimeLine#Direction
  * @type Number
  */
QTimeLine.Forward = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTimeLine
  * @name Backward
  * @see QTimeLine#Direction
  * @type Number
  */
QTimeLine.Backward = 0x1;

/**
  * @constructor 
  * @memberOf QTimeLine
  * @name Direction
  */
QTimeLine.Direction = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTimeLine
  * @name EaseInCurve
  * @see QTimeLine#CurveShape
  * @type Number
  */
QTimeLine.EaseInCurve = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTimeLine
  * @name EaseOutCurve
  * @see QTimeLine#CurveShape
  * @type Number
  */
QTimeLine.EaseOutCurve = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTimeLine
  * @name EaseInOutCurve
  * @see QTimeLine#CurveShape
  * @type Number
  */
QTimeLine.EaseInOutCurve = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTimeLine
  * @name LinearCurve
  * @see QTimeLine#CurveShape
  * @type Number
  */
QTimeLine.LinearCurve = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTimeLine
  * @name SineCurve
  * @see QTimeLine#CurveShape
  * @type Number
  */
QTimeLine.SineCurve = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTimeLine
  * @name CosineCurve
  * @see QTimeLine#CurveShape
  * @type Number
  */
QTimeLine.CosineCurve = 0x5;

/**
  * @constructor 
  * @memberOf QTimeLine
  * @name CurveShape
  */
QTimeLine.CurveShape = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTimeLine
  * @name NotRunning
  * @see QTimeLine#State
  * @type Number
  */
QTimeLine.NotRunning = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTimeLine
  * @name Paused
  * @see QTimeLine#State
  * @type Number
  */
QTimeLine.Paused = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTimeLine
  * @name Running
  * @see QTimeLine#State
  * @type Number
  */
QTimeLine.Running = 0x2;

/**
  * @constructor 
  * @memberOf QTimeLine
  * @name State
  */
QTimeLine.State = function(value){;};



/**
  * @name currentFrame
  * @function
  * @memberOf QTimeLine.prototype
  * @returns {Numeric}
  */
QTimeLine.prototype.currentFrame = function(){return new Numeric();};

/**
  * @name currentValue
  * @function
  * @memberOf QTimeLine.prototype
  * @returns {Numeric}
  */
QTimeLine.prototype.currentValue = function(){return new Numeric();};

/**
  * @name endFrame
  * @function
  * @memberOf QTimeLine.prototype
  * @returns {Numeric}
  */
QTimeLine.prototype.endFrame = function(){return new Numeric();};

/**
  * @name frameForTime
  * @function
  * @memberOf QTimeLine.prototype
  * @param {Numeric} msec
  * @returns {Numeric}
  */
QTimeLine.prototype.frameForTime = function(msec){return new Numeric();};

/**
  * @name setEndFrame
  * @function
  * @memberOf QTimeLine.prototype
  * @param {Numeric} frame
  * @returns {undefined}
  */
QTimeLine.prototype.setEndFrame = function(frame){return undefined;};

/**
  * @name setFrameRange
  * @function
  * @memberOf QTimeLine.prototype
  * @param {Numeric} startFrame
  * @param {Numeric} endFrame
  * @returns {undefined}
  */
QTimeLine.prototype.setFrameRange = function(startFrame, endFrame){return undefined;};

/**
  * @name setStartFrame
  * @function
  * @memberOf QTimeLine.prototype
  * @param {Numeric} frame
  * @returns {undefined}
  */
QTimeLine.prototype.setStartFrame = function(frame){return undefined;};

/**
  * @name startFrame
  * @function
  * @memberOf QTimeLine.prototype
  * @returns {Numeric}
  */
QTimeLine.prototype.startFrame = function(){return new Numeric();};

/**
  * @name state
  * @function
  * @memberOf QTimeLine.prototype
  * @returns {QTimeLine.State}
  */
QTimeLine.prototype.state = function(){return new QTimeLine.State();};

/**
  * @name valueForTime
  * @function
  * @memberOf QTimeLine.prototype
  * @param {Numeric} msec
  * @returns {Numeric}
  */
QTimeLine.prototype.valueForTime = function(msec){return new Numeric();};

/**
  * @name duration
  * @memberOf QTimeLine.prototype
  * @type Numeric
  */
QTimeLine.prototype.duration = new Numeric();

/**
  * @name updateInterval
  * @memberOf QTimeLine.prototype
  * @type Numeric
  */
QTimeLine.prototype.updateInterval = new Numeric();

/**
  * @name currentTime
  * @memberOf QTimeLine.prototype
  * @type Numeric
  */
QTimeLine.prototype.currentTime = new Numeric();

/**
  * @name direction
  * @memberOf QTimeLine.prototype
  * @type QBoxLayout.Direction
  */
QTimeLine.prototype.direction = new QBoxLayout.Direction();

/**
  * @name loopCount
  * @memberOf QTimeLine.prototype
  * @type Numeric
  */
QTimeLine.prototype.loopCount = new Numeric();

/**
  * @name curveShape
  * @memberOf QTimeLine.prototype
  * @type QTimeLine.CurveShape
  */
QTimeLine.prototype.curveShape = new QTimeLine.CurveShape();

/**
  * @name easingCurve
  * @memberOf QTimeLine.prototype
  * @type QEasingCurve
  */
QTimeLine.prototype.easingCurve = new QEasingCurve();


