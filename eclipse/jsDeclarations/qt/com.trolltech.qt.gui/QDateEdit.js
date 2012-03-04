/**
  * @name QDateEdit
  * @constructor
  * @extends QDateTimeEdit
  * @param {QWidget} parent
  */
function QDateEdit(parent){return undefined;};

/**
  * @name QDateEdit^1
  * @constructor
  * @extends QDateTimeEdit
  * @param {QDate} date
  * @param {QWidget} parent
  */
function QDateEdit(date, parent){return undefined;};

QDateEdit.prototype = new QDateTimeEdit();

