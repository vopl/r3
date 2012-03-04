/**
  * @name QRegExpValidator
  * @constructor
  * @extends QValidator
  * @param {QObject} parent
  */
function QRegExpValidator(parent){return undefined;};

/**
  * @name QRegExpValidator^1
  * @constructor
  * @extends QValidator
  * @param {QRegExp} rx
  * @param {QObject} parent
  */
function QRegExpValidator(rx, parent){return undefined;};

QRegExpValidator.prototype = new QValidator();

/**
  * @name regExp
  * @memberOf QRegExpValidator.prototype
  * @type QRegExp
  */
QRegExpValidator.prototype.regExp = new QRegExp();


