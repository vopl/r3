/**
  * @name QDoubleValidator
  * @constructor
  * @extends QValidator
  * @param {QObject} parent
  */
function QDoubleValidator(parent){return undefined;};

/**
  * @name QDoubleValidator^1
  * @constructor
  * @extends QValidator
  * @param {Numeric} bottom
  * @param {Numeric} top
  * @param {Numeric} decimals
  * @param {QObject} parent
  */
function QDoubleValidator(bottom, top, decimals, parent){return undefined;};

QDoubleValidator.prototype = new QValidator();

/**
  * @default 0x0
  * @constant
  * @memberOf QDoubleValidator
  * @name StandardNotation
  * @see QDoubleValidator#Notation
  * @type Number
  */
QDoubleValidator.StandardNotation = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDoubleValidator
  * @name ScientificNotation
  * @see QDoubleValidator#Notation
  * @type Number
  */
QDoubleValidator.ScientificNotation = 0x1;

/**
  * @constructor 
  * @memberOf QDoubleValidator
  * @name Notation
  */
QDoubleValidator.Notation = function(value){;};



/**
  * @name setRange
  * @function
  * @memberOf QDoubleValidator.prototype
  * @param {Numeric} bottom
  * @param {Numeric} top
  * @param {Numeric} decimals
  * @returns {undefined}
  */
QDoubleValidator.prototype.setRange = function(bottom, top, decimals){return undefined;};

/**
  * @name bottom
  * @memberOf QDoubleValidator.prototype
  * @type Numeric
  */
QDoubleValidator.prototype.bottom = new Numeric();

/**
  * @name top
  * @memberOf QDoubleValidator.prototype
  * @type Numeric
  */
QDoubleValidator.prototype.top = new Numeric();

/**
  * @name decimals
  * @memberOf QDoubleValidator.prototype
  * @type Numeric
  */
QDoubleValidator.prototype.decimals = new Numeric();

/**
  * @name notation
  * @memberOf QDoubleValidator.prototype
  * @type QDoubleValidator.Notation
  */
QDoubleValidator.prototype.notation = new QDoubleValidator.Notation();


