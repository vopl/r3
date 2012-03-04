/**
  * @name QCheckBox
  * @constructor
  * @extends QAbstractButton
  * @param {QWidget} parent
  */
function QCheckBox(parent){return undefined;};

/**
  * @name QCheckBox^1
  * @constructor
  * @extends QAbstractButton
  * @param {String} text
  * @param {QWidget} parent
  */
function QCheckBox(text, parent){return undefined;};

QCheckBox.prototype = new QAbstractButton();

/**
  * @name checkState
  * @function
  * @memberOf QCheckBox.prototype
  * @returns {Qt.CheckState}
  */
QCheckBox.prototype.checkState = function(){return new Qt.CheckState();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QCheckBox.prototype
  * @returns {QSize}
  */
QCheckBox.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setCheckState
  * @function
  * @memberOf QCheckBox.prototype
  * @param {Qt.CheckState} state
  * @returns {undefined}
  */
QCheckBox.prototype.setCheckState = function(state){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QCheckBox.prototype
  * @returns {QSize}
  */
QCheckBox.prototype.sizeHint = function(){return new QSize();};

/**
  * @name tristate
  * @memberOf QCheckBox.prototype
  * @type Boolean
  */
QCheckBox.prototype.tristate = new Boolean();


