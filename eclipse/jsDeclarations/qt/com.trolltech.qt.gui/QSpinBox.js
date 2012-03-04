/**
  * @name QSpinBox
  * @constructor
  * @extends QAbstractSpinBox
  * @param {QWidget} parent
  */
function QSpinBox(parent){return undefined;};

QSpinBox.prototype = new QAbstractSpinBox();

/**
  * @name setRange
  * @function
  * @memberOf QSpinBox.prototype
  * @param {Numeric} min
  * @param {Numeric} max
  * @returns {undefined}
  */
QSpinBox.prototype.setRange = function(min, max){return undefined;};

/**
  * @name suffix
  * @memberOf QSpinBox.prototype
  * @type String
  */
QSpinBox.prototype.suffix = new String();

/**
  * @name prefix
  * @memberOf QSpinBox.prototype
  * @type String
  */
QSpinBox.prototype.prefix = new String();

/**
  * @name cleanText
  * @memberOf QSpinBox.prototype
  * @type String
  */
QSpinBox.prototype.cleanText = new String();

/**
  * @name minimum
  * @memberOf QSpinBox.prototype
  * @type Numeric
  */
QSpinBox.prototype.minimum = new Numeric();

/**
  * @name maximum
  * @memberOf QSpinBox.prototype
  * @type Numeric
  */
QSpinBox.prototype.maximum = new Numeric();

/**
  * @name singleStep
  * @memberOf QSpinBox.prototype
  * @type Numeric
  */
QSpinBox.prototype.singleStep = new Numeric();

/**
  * @name value
  * @memberOf QSpinBox.prototype
  * @type Numeric
  */
QSpinBox.prototype.value = new Numeric();


