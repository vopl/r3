/**
  * @name QDragEnterEvent
  * @constructor
  * @extends QDragMoveEvent
  * @param {QPoint} pos
  * @param {Qt.DropActions} actions
  * @param {QMimeData} data
  * @param {Qt.MouseButtons} buttons
  * @param {Qt.KeyboardModifiers} modifiers
  */
function QDragEnterEvent(pos, actions, data, buttons, modifiers){return undefined;};

QDragEnterEvent.prototype = new QDragMoveEvent();

