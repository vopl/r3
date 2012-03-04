/**
  * @name QActionEvent
  * @constructor
  * @extends QEvent
  * @param {Numeric} type
  * @param {QAction} action
  * @param {QAction} before
  */
function QActionEvent(type, action, before){return undefined;};

QActionEvent.prototype = new QEvent();

/**
  * @name action
  * @function
  * @memberOf QActionEvent.prototype
  * @returns {QAction}
  */
QActionEvent.prototype.action = function(){return new QAction();};

/**
  * @name before
  * @function
  * @memberOf QActionEvent.prototype
  * @returns {QAction}
  */
QActionEvent.prototype.before = function(){return new QAction();};

