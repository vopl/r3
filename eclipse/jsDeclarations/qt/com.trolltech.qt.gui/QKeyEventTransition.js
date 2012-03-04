/**
  * @name QKeyEventTransition
  * @constructor
  * @extends QEventTransition
  * @param {QObject} object
  * @param {QApplication.Type} type
  * @param {Numeric} key
  * @param {QState} sourceState
  */
function QKeyEventTransition(object, type, key, sourceState){return undefined;};

/**
  * @name QKeyEventTransition^1
  * @constructor
  * @extends QEventTransition
  * @param {QState} sourceState
  */
function QKeyEventTransition(sourceState){return undefined;};

QKeyEventTransition.prototype = new QEventTransition();

/**
  * @name key
  * @memberOf QKeyEventTransition.prototype
  * @type Numeric
  */
QKeyEventTransition.prototype.key = new Numeric();

/**
  * @name modifierMask
  * @memberOf QKeyEventTransition.prototype
  * @type Qt.KeyboardModifiers
  */
QKeyEventTransition.prototype.modifierMask = new Qt.KeyboardModifiers();


