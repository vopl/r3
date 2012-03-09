/**
  * @name QProgressBar
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QProgressBar(parent){return undefined;};

QProgressBar.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QProgressBar
  * @name TopToBottom
  * @see QProgressBar#Direction
  * @type Number
  */
QProgressBar.TopToBottom = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QProgressBar
  * @name BottomToTop
  * @see QProgressBar#Direction
  * @type Number
  */
QProgressBar.BottomToTop = 0x1;

/**
  * @constructor 
  * @memberOf QProgressBar
  * @name Direction
  */
QProgressBar.Direction = function(value){;};



/**
  * @name minimumSizeHint
  * @function
  * @memberOf QProgressBar.prototype
  * @returns {QSize}
  */
QProgressBar.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name sizeHint
  * @function
  * @memberOf QProgressBar.prototype
  * @returns {QSize}
  */
QProgressBar.prototype.sizeHint = function(){return new QSize();};

/**
  * @name minimum
  * @memberOf QProgressBar.prototype
  * @type Numeric
  */
QProgressBar.prototype.minimum = new Numeric();

/**
  * @name maximum
  * @memberOf QProgressBar.prototype
  * @type Numeric
  */
QProgressBar.prototype.maximum = new Numeric();

/**
  * @name text
  * @memberOf QProgressBar.prototype
  * @type String
  */
QProgressBar.prototype.text = new String();

/**
  * @name value
  * @memberOf QProgressBar.prototype
  * @type Numeric
  */
QProgressBar.prototype.value = new Numeric();

/**
  * @name alignment
  * @memberOf QProgressBar.prototype
  * @type Qt.Alignment
  */
QProgressBar.prototype.alignment = new Qt.Alignment();

/**
  * @name textVisible
  * @memberOf QProgressBar.prototype
  * @type Boolean
  */
QProgressBar.prototype.textVisible = new Boolean();

/**
  * @name orientation
  * @memberOf QProgressBar.prototype
  * @type QPrinter.Orientation
  */
QProgressBar.prototype.orientation = new QPrinter.Orientation();

/**
  * @name invertedAppearance
  * @memberOf QProgressBar.prototype
  * @type Boolean
  */
QProgressBar.prototype.invertedAppearance = new Boolean();

/**
  * @name textDirection
  * @memberOf QProgressBar.prototype
  * @type QBoxLayout.Direction
  */
QProgressBar.prototype.textDirection = new QBoxLayout.Direction();

/**
  * @name format
  * @memberOf QProgressBar.prototype
  * @type String
  */
QProgressBar.prototype.format = new String();


