/**
  * @name QSlider
  * @constructor
  * @extends QAbstractSlider
  * @param {QWidget} parent
  */
function QSlider(parent){return undefined;};

/**
  * @name QSlider^1
  * @constructor
  * @extends QAbstractSlider
  * @param {QPrinter.Orientation} orientation
  * @param {QWidget} parent
  */
function QSlider(orientation, parent){return undefined;};

QSlider.prototype = new QAbstractSlider();

/**
  * @default 0
  * @constant
  * @memberOf QSlider
  * @name NoTicks
  * @see QSlider#TickPosition
  * @type Number
  */
QSlider.NoTicks = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QSlider
  * @name TicksAbove
  * @see QSlider#TickPosition
  * @type Number
  */
QSlider.TicksAbove = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QSlider
  * @name TicksBelow
  * @see QSlider#TickPosition
  * @type Number
  */
QSlider.TicksBelow = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QSlider
  * @name TicksBothSides
  * @see QSlider#TickPosition
  * @type Number
  */
QSlider.TicksBothSides = 0x3;

/**
  * @constructor 
  * @memberOf QSlider
  * @name TickPosition
  */
QSlider.TickPosition = function(value){;};



/**
  * @name minimumSizeHint
  * @function
  * @memberOf QSlider.prototype
  * @returns {QSize}
  */
QSlider.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name sizeHint
  * @function
  * @memberOf QSlider.prototype
  * @returns {QSize}
  */
QSlider.prototype.sizeHint = function(){return new QSize();};

/**
  * @name tickPosition
  * @memberOf QSlider.prototype
  * @type QSlider.TickPosition
  */
QSlider.prototype.tickPosition = new QSlider.TickPosition();

/**
  * @name tickInterval
  * @memberOf QSlider.prototype
  * @type Numeric
  */
QSlider.prototype.tickInterval = new Numeric();


