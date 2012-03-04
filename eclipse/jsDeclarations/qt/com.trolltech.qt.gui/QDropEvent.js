/**
  * @name QDropEvent
  * @constructor
  * @extends QEvent
  * @param {QPoint} pos
  * @param {Qt.DropActions} actions
  * @param {QMimeData} data
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {QApplication.Type} type
  */
function QDropEvent(pos, actions, data, buttons, modifiers, type){return undefined;};

QDropEvent.prototype = new QEvent();

/**
  * @name acceptProposedAction
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {undefined}
  */
QDropEvent.prototype.acceptProposedAction = function(){return undefined;};

/**
  * @name dropAction
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {Qt.DropAction}
  */
QDropEvent.prototype.dropAction = function(){return new Qt.DropAction();};

/**
  * @name keyboardModifiers
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {Qt.KeyboardModifiers}
  */
QDropEvent.prototype.keyboardModifiers = function(){return new Qt.KeyboardModifiers();};

/**
  * @name mimeData
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {QMimeData}
  */
QDropEvent.prototype.mimeData = function(){return new QMimeData();};

/**
  * @name mouseButtons
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {Qt.MouseButtons}
  */
QDropEvent.prototype.mouseButtons = function(){return new Qt.MouseButtons();};

/**
  * @name pos
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {QPoint}
  */
QDropEvent.prototype.pos = function(){return new QPoint();};

/**
  * @name possibleActions
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {Qt.DropActions}
  */
QDropEvent.prototype.possibleActions = function(){return new Qt.DropActions();};

/**
  * @name proposedAction
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {Qt.DropAction}
  */
QDropEvent.prototype.proposedAction = function(){return new Qt.DropAction();};

/**
  * @name setDropAction
  * @function
  * @memberOf QDropEvent.prototype
  * @param {Qt.DropAction} action
  * @returns {undefined}
  */
QDropEvent.prototype.setDropAction = function(action){return undefined;};

/**
  * @name source
  * @function
  * @memberOf QDropEvent.prototype
  * @returns {QWidget}
  */
QDropEvent.prototype.source = function(){return new QWidget();};

