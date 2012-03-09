/**
  * @name QEventLoop
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QEventLoop(parent){return undefined;};

QEventLoop.prototype = new QObject();

/**
  * @default 0x00
  * @constant
  * @memberOf QEventLoop
  * @name AllEvents
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.AllEvents = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QEventLoop
  * @name ExcludeUserInputEvents
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.ExcludeUserInputEvents = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QEventLoop
  * @name ExcludeSocketNotifiers
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.ExcludeSocketNotifiers = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QEventLoop
  * @name WaitForMoreEvents
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.WaitForMoreEvents = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QEventLoop
  * @name X11ExcludeTimers
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.X11ExcludeTimers = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QEventLoop
  * @name DeferredDeletion
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.DeferredDeletion = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf QEventLoop
  * @name EventLoopExec
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.EventLoopExec = 0x20;

/**
  * @default 0x40
  * @constant
  * @memberOf QEventLoop
  * @name DialogExec
  * @see QEventLoop#ProcessEventsFlags
  * @see QEventLoop#ProcessEventsFlag
  * @type Number
  */
QEventLoop.DialogExec = 0x40;

/**
  * @constructor 
  * @memberOf QEventLoop
  * @name ProcessEventsFlag
  */
QEventLoop.ProcessEventsFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QEventLoop
  * @name ProcessEventsFlags
  */
QEventLoop.ProcessEventsFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name exec
  * @function
  * @memberOf QEventLoop.prototype
  * @param {QEventLoop.ProcessEventsFlags} flags
  * @returns {Numeric}
  */
QEventLoop.prototype.exec = function(flags){return new Numeric();};

/**
  * @name exit
  * @function
  * @memberOf QEventLoop.prototype
  * @param {Numeric} returnCode
  * @returns {undefined}
  */
QEventLoop.prototype.exit = function(returnCode){return undefined;};

/**
  * @name isRunning
  * @function
  * @memberOf QEventLoop.prototype
  * @returns {Boolean}
  */
QEventLoop.prototype.isRunning = function(){return new Boolean();};

/**
  * @name processEvents
  * @function
  * @memberOf QEventLoop.prototype
  * @param {QEventLoop.ProcessEventsFlags} flags
  * @returns {Boolean}
  */
QEventLoop.prototype.processEvents = function(flags){return new Boolean();};

/**
  * @name wakeUp
  * @function
  * @memberOf QEventLoop.prototype
  * @returns {undefined}
  */
QEventLoop.prototype.wakeUp = function(){return undefined;};

