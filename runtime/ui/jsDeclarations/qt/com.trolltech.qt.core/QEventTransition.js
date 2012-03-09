/**
  * @name QEventTransition
  * @constructor
  * @extends QAbstractTransition
  * @param {QObject} object
  * @param {QApplication.Type} type
  * @param {QState} sourceState
  */
function QEventTransition(object, type, sourceState){return undefined;};

/**
  * @name QEventTransition^1
  * @constructor
  * @extends QAbstractTransition
  * @param {QState} sourceState
  */
function QEventTransition(sourceState){return undefined;};

QEventTransition.prototype = new QAbstractTransition();

/**
  * @name eventSource
  * @memberOf QEventTransition.prototype
  * @type QObject
  */
QEventTransition.prototype.eventSource = new QObject();

/**
  * @name eventType
  * @memberOf QEventTransition.prototype
  * @type QApplication.Type
  */
QEventTransition.prototype.eventType = new QApplication.Type();


