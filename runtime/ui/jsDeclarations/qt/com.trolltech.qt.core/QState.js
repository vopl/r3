/**
  * @name QState
  * @constructor
  * @extends QAbstractState
  * @param {QState} parent
  */
function QState(parent){return undefined;};

/**
  * @name QState^1
  * @constructor
  * @extends QAbstractState
  * @param {QState.ChildMode} childMode
  * @param {QState} parent
  */
function QState(childMode, parent){return undefined;};

QState.prototype = new QAbstractState();

/**
  * @default 0x0
  * @constant
  * @memberOf QState
  * @name ExclusiveStates
  * @see QState#ChildMode
  * @type Number
  */
QState.ExclusiveStates = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QState
  * @name ParallelStates
  * @see QState#ChildMode
  * @type Number
  */
QState.ParallelStates = 0x1;

/**
  * @constructor 
  * @memberOf QState
  * @name ChildMode
  */
QState.ChildMode = function(value){;};



/**
  * @name addTransition
  * @function
  * @memberOf QState.prototype
  * @param {QAbstractState} target
  * @returns {QAbstractTransition}
  */
QState.prototype.addTransition = function(target){return new QAbstractTransition();};

/**
  * @name assignProperty
  * @function
  * @memberOf QState.prototype
  * @param {QObject} object
  * @param {String} name
  * @param {Object} value
  * @returns {undefined}
  */
QState.prototype.assignProperty = function(object, name, value){return undefined;};

/**
  * @name removeTransition
  * @function
  * @memberOf QState.prototype
  * @param {QAbstractTransition} transition
  * @returns {undefined}
  */
QState.prototype.removeTransition = function(transition){return undefined;};

/**
  * @name transitions
  * @function
  * @memberOf QState.prototype
  * @returns {Array}
  */
QState.prototype.transitions = function(){return new Array();};

/**
  * @name initialState
  * @memberOf QState.prototype
  * @type QAbstractState
  */
QState.prototype.initialState = new QAbstractState();

/**
  * @name errorState
  * @memberOf QState.prototype
  * @type QAbstractState
  */
QState.prototype.errorState = new QAbstractState();

/**
  * @name childMode
  * @memberOf QState.prototype
  * @type QState.ChildMode
  */
QState.prototype.childMode = new QState.ChildMode();


