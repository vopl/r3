/**
  * @name QDragMoveEvent
  * @constructor
  * @extends QDropEvent
  * @param {QPoint} pos
  * @param {Qt.DropActions} actions
  * @param {QMimeData} data
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {QApplication.Type} type
  */
function QDragMoveEvent(pos, actions, data, buttons, modifiers, type){return undefined;};

QDragMoveEvent.prototype = new QDropEvent();

/**
  * @name accept
  * @function
  * @memberOf QDragMoveEvent.prototype
  * @param {QRect} r
  * @returns {undefined}
  */
QDragMoveEvent.prototype.accept = function(r){return undefined;};

/**
  * @name answerRect
  * @function
  * @memberOf QDragMoveEvent.prototype
  * @returns {QRect}
  */
QDragMoveEvent.prototype.answerRect = function(){return new QRect();};

/**
  * @name ignore
  * @function
  * @memberOf QDragMoveEvent.prototype
  * @param {QRect} r
  * @returns {undefined}
  */
QDragMoveEvent.prototype.ignore = function(r){return undefined;};

