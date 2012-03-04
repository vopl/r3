/**
  * @name QSignalTransition
  * @constructor
  * @extends QAbstractTransition
  * @param {QObject} sender
  * @param {String} signal
  * @param {QState} sourceState
  */
function QSignalTransition(sender, signal, sourceState){return undefined;};

/**
  * @name QSignalTransition^1
  * @constructor
  * @extends QAbstractTransition
  * @param {QState} sourceState
  */
function QSignalTransition(sourceState){return undefined;};

QSignalTransition.prototype = new QAbstractTransition();

/**
  * @name senderObject
  * @memberOf QSignalTransition.prototype
  * @type QObject
  */
QSignalTransition.prototype.senderObject = new QObject();

/**
  * @name signal
  * @memberOf QSignalTransition.prototype
  * @type QByteArray
  */
QSignalTransition.prototype.signal = new QByteArray();


