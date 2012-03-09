/**
  * @name QHistoryState
  * @constructor
  * @extends QAbstractState
  * @param {QHistoryState.HistoryType} type
  * @param {QState} parent
  */
function QHistoryState(type, parent){return undefined;};

/**
  * @name QHistoryState^1
  * @constructor
  * @extends QAbstractState
  * @param {QState} parent
  */
function QHistoryState(parent){return undefined;};

QHistoryState.prototype = new QAbstractState();

/**
  * @default 0x0
  * @constant
  * @memberOf QHistoryState
  * @name ShallowHistory
  * @see QHistoryState#HistoryType
  * @type Number
  */
QHistoryState.ShallowHistory = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHistoryState
  * @name DeepHistory
  * @see QHistoryState#HistoryType
  * @type Number
  */
QHistoryState.DeepHistory = 0x1;

/**
  * @constructor 
  * @memberOf QHistoryState
  * @name HistoryType
  */
QHistoryState.HistoryType = function(value){;};



/**
  * @name defaultState
  * @memberOf QHistoryState.prototype
  * @type QAbstractState
  */
QHistoryState.prototype.defaultState = new QAbstractState();

/**
  * @name historyType
  * @memberOf QHistoryState.prototype
  * @type QHistoryState.HistoryType
  */
QHistoryState.prototype.historyType = new QHistoryState.HistoryType();


