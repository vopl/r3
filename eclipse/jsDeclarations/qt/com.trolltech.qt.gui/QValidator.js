/**
  * @name QValidator
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QValidator(parent){return undefined;};

QValidator.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QValidator
  * @name Invalid
  * @see QValidator#State
  * @type Number
  */
QValidator.Invalid = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QValidator
  * @name Intermediate
  * @see QValidator#State
  * @type Number
  */
QValidator.Intermediate = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QValidator
  * @name Acceptable
  * @see QValidator#State
  * @type Number
  */
QValidator.Acceptable = 0x2;

/**
  * @constructor 
  * @memberOf QValidator
  * @name State
  */
QValidator.State = function(value){;};



/**
  * @name fixup
  * @function
  * @memberOf QValidator.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QValidator.prototype.fixup = function(arg__1){return undefined;};

/**
  * @name locale
  * @function
  * @memberOf QValidator.prototype
  * @returns {QLocale}
  */
QValidator.prototype.locale = function(){return new QLocale();};

/**
  * @name setLocale
  * @function
  * @memberOf QValidator.prototype
  * @param {QLocale} locale
  * @returns {undefined}
  */
QValidator.prototype.setLocale = function(locale){return undefined;};

/**
  * @name validate
  * @function
  * @memberOf QValidator.prototype
  * @param {String} arg__1
  * @param {Numeric} arg__2
  * @returns {QTimeLine.State}
  */
QValidator.prototype.validate = function(arg__1, arg__2){return new QTimeLine.State();};

