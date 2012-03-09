/**
  * @name QAbstractSlider
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QAbstractSlider(parent){return undefined;};

QAbstractSlider.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderNoAction
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderNoAction = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderSingleStepAdd
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderSingleStepAdd = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderSingleStepSub
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderSingleStepSub = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderPageStepAdd
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderPageStepAdd = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderPageStepSub
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderPageStepSub = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderToMinimum
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderToMinimum = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderToMaximum
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderToMaximum = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QAbstractSlider
  * @name SliderMove
  * @see QAbstractSlider#SliderAction
  * @type Number
  */
QAbstractSlider.SliderMove = 0x7;

/**
  * @constructor 
  * @memberOf QAbstractSlider
  * @name SliderAction
  */
QAbstractSlider.SliderAction = function(value){;};



/**
  * @name setRange
  * @function
  * @memberOf QAbstractSlider.prototype
  * @param {Numeric} min
  * @param {Numeric} max
  * @returns {undefined}
  */
QAbstractSlider.prototype.setRange = function(min, max){return undefined;};

/**
  * @name triggerAction
  * @function
  * @memberOf QAbstractSlider.prototype
  * @param {QAbstractSlider.SliderAction} action
  * @returns {undefined}
  */
QAbstractSlider.prototype.triggerAction = function(action){return undefined;};

/**
  * @name minimum
  * @memberOf QAbstractSlider.prototype
  * @type Numeric
  */
QAbstractSlider.prototype.minimum = new Numeric();

/**
  * @name maximum
  * @memberOf QAbstractSlider.prototype
  * @type Numeric
  */
QAbstractSlider.prototype.maximum = new Numeric();

/**
  * @name singleStep
  * @memberOf QAbstractSlider.prototype
  * @type Numeric
  */
QAbstractSlider.prototype.singleStep = new Numeric();

/**
  * @name pageStep
  * @memberOf QAbstractSlider.prototype
  * @type Numeric
  */
QAbstractSlider.prototype.pageStep = new Numeric();

/**
  * @name value
  * @memberOf QAbstractSlider.prototype
  * @type Numeric
  */
QAbstractSlider.prototype.value = new Numeric();

/**
  * @name sliderPosition
  * @memberOf QAbstractSlider.prototype
  * @type Numeric
  */
QAbstractSlider.prototype.sliderPosition = new Numeric();

/**
  * @name tracking
  * @memberOf QAbstractSlider.prototype
  * @type Boolean
  */
QAbstractSlider.prototype.tracking = new Boolean();

/**
  * @name orientation
  * @memberOf QAbstractSlider.prototype
  * @type QPrinter.Orientation
  */
QAbstractSlider.prototype.orientation = new QPrinter.Orientation();

/**
  * @name invertedAppearance
  * @memberOf QAbstractSlider.prototype
  * @type Boolean
  */
QAbstractSlider.prototype.invertedAppearance = new Boolean();

/**
  * @name invertedControls
  * @memberOf QAbstractSlider.prototype
  * @type Boolean
  */
QAbstractSlider.prototype.invertedControls = new Boolean();

/**
  * @name sliderDown
  * @memberOf QAbstractSlider.prototype
  * @type Boolean
  */
QAbstractSlider.prototype.sliderDown = new Boolean();


