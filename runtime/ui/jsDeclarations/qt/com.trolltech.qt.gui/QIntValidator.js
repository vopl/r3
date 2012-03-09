/**
  * @name QIntValidator
  * @constructor
  * @extends QValidator
  * @param {QObject} parent
  */
function QIntValidator(parent){return undefined;};

/**
  * @name QIntValidator^1
  * @constructor
  * @extends QValidator
  * @param {Numeric} bottom
  * @param {Numeric} top
  * @param {QObject} parent
  */
function QIntValidator(bottom, top, parent){return undefined;};

QIntValidator.prototype = new QValidator();

/**
  * @name setRange
  * @function
  * @memberOf QIntValidator.prototype
  * @param {Numeric} bottom
  * @param {Numeric} top
  * @returns {undefined}
  */
QIntValidator.prototype.setRange = function(bottom, top){return undefined;};

/**
  * @name bottom
  * @memberOf QIntValidator.prototype
  * @type Numeric
  */
QIntValidator.prototype.bottom = new Numeric();

/**
  * @name top
  * @memberOf QIntValidator.prototype
  * @type Numeric
  */
QIntValidator.prototype.top = new Numeric();


