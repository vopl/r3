/**
  * @name QRadioButton
  * @constructor
  * @extends QAbstractButton
  * @param {QWidget} parent
  */
function QRadioButton(parent){return undefined;};

/**
  * @name QRadioButton^1
  * @constructor
  * @extends QAbstractButton
  * @param {String} text
  * @param {QWidget} parent
  */
function QRadioButton(text, parent){return undefined;};

QRadioButton.prototype = new QAbstractButton();

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QRadioButton.prototype
  * @returns {QSize}
  */
QRadioButton.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name sizeHint
  * @function
  * @memberOf QRadioButton.prototype
  * @returns {QSize}
  */
QRadioButton.prototype.sizeHint = function(){return new QSize();};

