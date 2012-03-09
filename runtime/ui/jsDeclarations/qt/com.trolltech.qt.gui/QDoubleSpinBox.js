/**
  * @name QDoubleSpinBox
  * @constructor
  * @extends QAbstractSpinBox
  * @param {QWidget} parent
  */
function QDoubleSpinBox(parent){return undefined;};

QDoubleSpinBox.prototype = new QAbstractSpinBox();

/**
  * @name setRange
  * @function
  * @memberOf QDoubleSpinBox.prototype
  * @param {Numeric} min
  * @param {Numeric} max
  * @returns {undefined}
  */
QDoubleSpinBox.prototype.setRange = function(min, max){return undefined;};

/**
  * @name textFromValue
  * @function
  * @memberOf QDoubleSpinBox.prototype
  * @param {Numeric} val
  * @returns {String}
  */
QDoubleSpinBox.prototype.textFromValue = function(val){return new String();};

/**
  * @name valueFromText
  * @function
  * @memberOf QDoubleSpinBox.prototype
  * @param {String} text
  * @returns {Numeric}
  */
QDoubleSpinBox.prototype.valueFromText = function(text){return new Numeric();};

/**
  * @name prefix
  * @memberOf QDoubleSpinBox.prototype
  * @type String
  */
QDoubleSpinBox.prototype.prefix = new String();

/**
  * @name suffix
  * @memberOf QDoubleSpinBox.prototype
  * @type String
  */
QDoubleSpinBox.prototype.suffix = new String();

/**
  * @name cleanText
  * @memberOf QDoubleSpinBox.prototype
  * @type String
  */
QDoubleSpinBox.prototype.cleanText = new String();

/**
  * @name decimals
  * @memberOf QDoubleSpinBox.prototype
  * @type Numeric
  */
QDoubleSpinBox.prototype.decimals = new Numeric();

/**
  * @name minimum
  * @memberOf QDoubleSpinBox.prototype
  * @type Numeric
  */
QDoubleSpinBox.prototype.minimum = new Numeric();

/**
  * @name maximum
  * @memberOf QDoubleSpinBox.prototype
  * @type Numeric
  */
QDoubleSpinBox.prototype.maximum = new Numeric();

/**
  * @name singleStep
  * @memberOf QDoubleSpinBox.prototype
  * @type Numeric
  */
QDoubleSpinBox.prototype.singleStep = new Numeric();

/**
  * @name value
  * @memberOf QDoubleSpinBox.prototype
  * @type Numeric
  */
QDoubleSpinBox.prototype.value = new Numeric();


