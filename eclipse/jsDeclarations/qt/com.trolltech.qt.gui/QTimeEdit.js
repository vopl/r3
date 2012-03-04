/**
  * @name QTimeEdit
  * @constructor
  * @extends QDateTimeEdit
  * @param {QWidget} parent
  */
function QTimeEdit(parent){return undefined;};

/**
  * @name QTimeEdit^1
  * @constructor
  * @extends QDateTimeEdit
  * @param {QTime} time
  * @param {QWidget} parent
  */
function QTimeEdit(time, parent){return undefined;};

QTimeEdit.prototype = new QDateTimeEdit();

