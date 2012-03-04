/**
  * @name QStateMachine
  * @constructor
  * @extends QState
  * @param {QObject} parent
  */
function QStateMachine(parent){return undefined;};

QStateMachine.prototype = new QState();

/**
  * @default 0x0
  * @constant
  * @memberOf QStateMachine
  * @name NoError
  * @see QStateMachine#Error
  * @type Number
  */
QStateMachine.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStateMachine
  * @name NoInitialStateError
  * @see QStateMachine#Error
  * @type Number
  */
QStateMachine.NoInitialStateError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QStateMachine
  * @name NoDefaultStateInHistoryStateError
  * @see QStateMachine#Error
  * @type Number
  */
QStateMachine.NoDefaultStateInHistoryStateError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QStateMachine
  * @name NoCommonAncestorForTransitionError
  * @see QStateMachine#Error
  * @type Number
  */
QStateMachine.NoCommonAncestorForTransitionError = 0x3;

/**
  * @constructor 
  * @memberOf QStateMachine
  * @name Error
  */
QStateMachine.Error = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStateMachine
  * @name NormalPriority
  * @see QStateMachine#EventPriority
  * @type Number
  */
QStateMachine.NormalPriority = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStateMachine
  * @name HighPriority
  * @see QStateMachine#EventPriority
  * @type Number
  */
QStateMachine.HighPriority = 0x1;

/**
  * @constructor 
  * @memberOf QStateMachine
  * @name EventPriority
  */
QStateMachine.EventPriority = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QStateMachine
  * @name DontRestoreProperties
  * @see QStateMachine#RestorePolicy
  * @type Number
  */
QStateMachine.DontRestoreProperties = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStateMachine
  * @name RestoreProperties
  * @see QStateMachine#RestorePolicy
  * @type Number
  */
QStateMachine.RestoreProperties = 0x1;

/**
  * @constructor 
  * @memberOf QStateMachine
  * @name RestorePolicy
  */
QStateMachine.RestorePolicy = function(value){;};



/**
  * @name addDefaultAnimation
  * @function
  * @memberOf QStateMachine.prototype
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QStateMachine.prototype.addDefaultAnimation = function(animation){return undefined;};

/**
  * @name addState
  * @function
  * @memberOf QStateMachine.prototype
  * @param {QAbstractState} state
  * @returns {undefined}
  */
QStateMachine.prototype.addState = function(state){return undefined;};

/**
  * @name cancelDelayedEvent
  * @function
  * @memberOf QStateMachine.prototype
  * @param {Numeric} id
  * @returns {Boolean}
  */
QStateMachine.prototype.cancelDelayedEvent = function(id){return new Boolean();};

/**
  * @name clearError
  * @function
  * @memberOf QStateMachine.prototype
  * @returns {undefined}
  */
QStateMachine.prototype.clearError = function(){return undefined;};

/**
  * @name configuration
  * @function
  * @memberOf QStateMachine.prototype
  * @returns {Array}
  */
QStateMachine.prototype.configuration = function(){return new Array();};

/**
  * @name defaultAnimations
  * @function
  * @memberOf QStateMachine.prototype
  * @returns {Array}
  */
QStateMachine.prototype.defaultAnimations = function(){return new Array();};

/**
  * @name error
  * @function
  * @memberOf QStateMachine.prototype
  * @returns {QStateMachine.Error}
  */
QStateMachine.prototype.error = function(){return new QStateMachine.Error();};

/**
  * @name isRunning
  * @function
  * @memberOf QStateMachine.prototype
  * @returns {Boolean}
  */
QStateMachine.prototype.isRunning = function(){return new Boolean();};

/**
  * @name postDelayedEvent
  * @function
  * @memberOf QStateMachine.prototype
  * @param {QEvent} event
  * @param {Numeric} delay
  * @returns {Numeric}
  */
QStateMachine.prototype.postDelayedEvent = function(event, delay){return new Numeric();};

/**
  * @name postEvent
  * @function
  * @memberOf QStateMachine.prototype
  * @param {QEvent} event
  * @param {QStateMachine.EventPriority} priority
  * @returns {undefined}
  */
QStateMachine.prototype.postEvent = function(event, priority){return undefined;};

/**
  * @name removeDefaultAnimation
  * @function
  * @memberOf QStateMachine.prototype
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QStateMachine.prototype.removeDefaultAnimation = function(animation){return undefined;};

/**
  * @name removeState
  * @function
  * @memberOf QStateMachine.prototype
  * @param {QAbstractState} state
  * @returns {undefined}
  */
QStateMachine.prototype.removeState = function(state){return undefined;};

/**
  * @name errorString
  * @memberOf QStateMachine.prototype
  * @type String
  */
QStateMachine.prototype.errorString = new String();

/**
  * @name globalRestorePolicy
  * @memberOf QStateMachine.prototype
  * @type QStateMachine.RestorePolicy
  */
QStateMachine.prototype.globalRestorePolicy = new QStateMachine.RestorePolicy();

/**
  * @name animated
  * @memberOf QStateMachine.prototype
  * @type Boolean
  */
QStateMachine.prototype.animated = new Boolean();


