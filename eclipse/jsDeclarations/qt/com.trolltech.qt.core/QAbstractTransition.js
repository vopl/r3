/**
  * @name QAbstractTransition
  * @constructor
  * @extends QObject
  * @param {QState} sourceState
  */
function QAbstractTransition(sourceState){return undefined;};

QAbstractTransition.prototype = new QObject();

/**
  * @name addAnimation
  * @function
  * @memberOf QAbstractTransition.prototype
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QAbstractTransition.prototype.addAnimation = function(animation){return undefined;};

/**
  * @name animations
  * @function
  * @memberOf QAbstractTransition.prototype
  * @returns {Array}
  */
QAbstractTransition.prototype.animations = function(){return new Array();};

/**
  * @name machine
  * @function
  * @memberOf QAbstractTransition.prototype
  * @returns {QStateMachine}
  */
QAbstractTransition.prototype.machine = function(){return new QStateMachine();};

/**
  * @name removeAnimation
  * @function
  * @memberOf QAbstractTransition.prototype
  * @param {QAbstractAnimation} animation
  * @returns {undefined}
  */
QAbstractTransition.prototype.removeAnimation = function(animation){return undefined;};

/**
  * @name sourceState
  * @memberOf QAbstractTransition.prototype
  * @type QState
  */
QAbstractTransition.prototype.sourceState = new QState();

/**
  * @name targetState
  * @memberOf QAbstractTransition.prototype
  * @type QAbstractState
  */
QAbstractTransition.prototype.targetState = new QAbstractState();

/**
  * @name targetStates
  * @memberOf QAbstractTransition.prototype
  * @type Array
  */
QAbstractTransition.prototype.targetStates = new Array();


