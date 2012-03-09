/**
  * @name QAbstractSpinBox
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QAbstractSpinBox(parent){return undefined;};

QAbstractSpinBox.prototype = new QWidget();

/**
  * @default 0x00
  * @constant
  * @memberOf QAbstractSpinBox
  * @name StepNone
  * @see QAbstractSpinBox#StepEnabled
  * @see QAbstractSpinBox#StepEnabledFlag
  * @type Number
  */
QAbstractSpinBox.StepNone = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QAbstractSpinBox
  * @name StepUpEnabled
  * @see QAbstractSpinBox#StepEnabled
  * @see QAbstractSpinBox#StepEnabledFlag
  * @type Number
  */
QAbstractSpinBox.StepUpEnabled = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QAbstractSpinBox
  * @name StepDownEnabled
  * @see QAbstractSpinBox#StepEnabled
  * @see QAbstractSpinBox#StepEnabledFlag
  * @type Number
  */
QAbstractSpinBox.StepDownEnabled = 0x2;

/**
  * @constructor 
  * @memberOf QAbstractSpinBox
  * @name StepEnabledFlag
  */
QAbstractSpinBox.StepEnabledFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QAbstractSpinBox
  * @name StepEnabled
  */
QAbstractSpinBox.StepEnabled = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSpinBox
  * @name CorrectToPreviousValue
  * @see QAbstractSpinBox#CorrectionMode
  * @type Number
  */
QAbstractSpinBox.CorrectToPreviousValue = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSpinBox
  * @name CorrectToNearestValue
  * @see QAbstractSpinBox#CorrectionMode
  * @type Number
  */
QAbstractSpinBox.CorrectToNearestValue = 0x1;

/**
  * @constructor 
  * @memberOf QAbstractSpinBox
  * @name CorrectionMode
  */
QAbstractSpinBox.CorrectionMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSpinBox
  * @name UpDownArrows
  * @see QAbstractSpinBox#ButtonSymbols
  * @type Number
  */
QAbstractSpinBox.UpDownArrows = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSpinBox
  * @name PlusMinus
  * @see QAbstractSpinBox#ButtonSymbols
  * @type Number
  */
QAbstractSpinBox.PlusMinus = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractSpinBox
  * @name NoButtons
  * @see QAbstractSpinBox#ButtonSymbols
  * @type Number
  */
QAbstractSpinBox.NoButtons = 0x2;

/**
  * @constructor 
  * @memberOf QAbstractSpinBox
  * @name ButtonSymbols
  */
QAbstractSpinBox.ButtonSymbols = function(value){;};



/**
  * @name fixup
  * @function
  * @memberOf QAbstractSpinBox.prototype
  * @param {String} input
  * @returns {undefined}
  */
QAbstractSpinBox.prototype.fixup = function(input){return undefined;};

/**
  * @name interpretText
  * @function
  * @memberOf QAbstractSpinBox.prototype
  * @returns {undefined}
  */
QAbstractSpinBox.prototype.interpretText = function(){return undefined;};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QAbstractSpinBox.prototype
  * @returns {QSize}
  */
QAbstractSpinBox.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name sizeHint
  * @function
  * @memberOf QAbstractSpinBox.prototype
  * @returns {QSize}
  */
QAbstractSpinBox.prototype.sizeHint = function(){return new QSize();};

/**
  * @name stepBy
  * @function
  * @memberOf QAbstractSpinBox.prototype
  * @param {Numeric} steps
  * @returns {undefined}
  */
QAbstractSpinBox.prototype.stepBy = function(steps){return undefined;};

/**
  * @name validate
  * @function
  * @memberOf QAbstractSpinBox.prototype
  * @param {String} input
  * @param {Numeric} pos
  * @returns {QTimeLine.State}
  */
QAbstractSpinBox.prototype.validate = function(input, pos){return new QTimeLine.State();};

/**
  * @name wrapping
  * @memberOf QAbstractSpinBox.prototype
  * @type Boolean
  */
QAbstractSpinBox.prototype.wrapping = new Boolean();

/**
  * @name frame
  * @memberOf QAbstractSpinBox.prototype
  * @type Boolean
  */
QAbstractSpinBox.prototype.frame = new Boolean();

/**
  * @name alignment
  * @memberOf QAbstractSpinBox.prototype
  * @type Qt.Alignment
  */
QAbstractSpinBox.prototype.alignment = new Qt.Alignment();

/**
  * @name readOnly
  * @memberOf QAbstractSpinBox.prototype
  * @type Boolean
  */
QAbstractSpinBox.prototype.readOnly = new Boolean();

/**
  * @name buttonSymbols
  * @memberOf QAbstractSpinBox.prototype
  * @type QAbstractSpinBox.ButtonSymbols
  */
QAbstractSpinBox.prototype.buttonSymbols = new QAbstractSpinBox.ButtonSymbols();

/**
  * @name specialValueText
  * @memberOf QAbstractSpinBox.prototype
  * @type String
  */
QAbstractSpinBox.prototype.specialValueText = new String();

/**
  * @name text
  * @memberOf QAbstractSpinBox.prototype
  * @type String
  */
QAbstractSpinBox.prototype.text = new String();

/**
  * @name accelerated
  * @memberOf QAbstractSpinBox.prototype
  * @type Boolean
  */
QAbstractSpinBox.prototype.accelerated = new Boolean();

/**
  * @name correctionMode
  * @memberOf QAbstractSpinBox.prototype
  * @type QAbstractSpinBox.CorrectionMode
  */
QAbstractSpinBox.prototype.correctionMode = new QAbstractSpinBox.CorrectionMode();

/**
  * @name acceptableInput
  * @memberOf QAbstractSpinBox.prototype
  * @type Boolean
  */
QAbstractSpinBox.prototype.acceptableInput = new Boolean();

/**
  * @name keyboardTracking
  * @memberOf QAbstractSpinBox.prototype
  * @type Boolean
  */
QAbstractSpinBox.prototype.keyboardTracking = new Boolean();


