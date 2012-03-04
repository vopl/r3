/**
  * @name QMouseEventTransition
  * @constructor
  * @extends QEventTransition
  * @param {QObject} object
  * @param {QApplication.Type} type
  * @param {Qt.MouseButton} button
  * @param {QState} sourceState
  */
function QMouseEventTransition(object, type, button, sourceState){return undefined;};

/**
  * @name QMouseEventTransition^1
  * @constructor
  * @extends QEventTransition
  * @param {QState} sourceState
  */
function QMouseEventTransition(sourceState){return undefined;};

QMouseEventTransition.prototype = new QEventTransition();

/**
  * @name hitTestPath
  * @function
  * @memberOf QMouseEventTransition.prototype
  * @returns {QPainterPath}
  */
QMouseEventTransition.prototype.hitTestPath = function(){return new QPainterPath();};

/**
  * @name setHitTestPath
  * @function
  * @memberOf QMouseEventTransition.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QMouseEventTransition.prototype.setHitTestPath = function(path){return undefined;};

/**
  * @name button
  * @memberOf QMouseEventTransition.prototype
  * @type Qt.MouseButton
  */
QMouseEventTransition.prototype.button = new Qt.MouseButton();

/**
  * @name modifierMask
  * @memberOf QMouseEventTransition.prototype
  * @type Qt.KeyboardModifiers
  */
QMouseEventTransition.prototype.modifierMask = new Qt.KeyboardModifiers();


