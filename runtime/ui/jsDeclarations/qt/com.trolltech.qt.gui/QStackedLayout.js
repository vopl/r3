/**
  * @name QStackedLayout
  * @constructor
  * @extends QLayout
  */
function QStackedLayout(){return undefined;};

/**
  * @name QStackedLayout^1
  * @constructor
  * @extends QLayout
  * @param {QLayout} parentLayout
  */
function QStackedLayout(parentLayout){return undefined;};

/**
  * @name QStackedLayout^2
  * @constructor
  * @extends QLayout
  * @param {QWidget} parent
  */
function QStackedLayout(parent){return undefined;};

QStackedLayout.prototype = new QLayout();

/**
  * @default 0x0
  * @constant
  * @memberOf QStackedLayout
  * @name StackOne
  * @see QStackedLayout#StackingMode
  * @type Number
  */
QStackedLayout.StackOne = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QStackedLayout
  * @name StackAll
  * @see QStackedLayout#StackingMode
  * @type Number
  */
QStackedLayout.StackAll = 0x1;

/**
  * @constructor 
  * @memberOf QStackedLayout
  * @name StackingMode
  */
QStackedLayout.StackingMode = function(value){;};



/**
  * @name addStackedWidget
  * @function
  * @memberOf QStackedLayout.prototype
  * @param {QWidget} w
  * @returns {Numeric}
  */
QStackedLayout.prototype.addStackedWidget = function(w){return new Numeric();};

/**
  * @name currentWidget
  * @function
  * @memberOf QStackedLayout.prototype
  * @returns {QWidget}
  */
QStackedLayout.prototype.currentWidget = function(){return new QWidget();};

/**
  * @name insertWidget
  * @function
  * @memberOf QStackedLayout.prototype
  * @param {Numeric} index
  * @param {QWidget} w
  * @returns {Numeric}
  */
QStackedLayout.prototype.insertWidget = function(index, w){return new Numeric();};

/**
  * @name widget
  * @function
  * @memberOf QStackedLayout.prototype
  * @param {Numeric} arg__1
  * @returns {QWidget}
  */
QStackedLayout.prototype.widget = function(arg__1){return new QWidget();};

/**
  * @name currentIndex
  * @memberOf QStackedLayout.prototype
  * @type Numeric
  */
QStackedLayout.prototype.currentIndex = new Numeric();

/**
  * @name stackingMode
  * @memberOf QStackedLayout.prototype
  * @type QStackedLayout.StackingMode
  */
QStackedLayout.prototype.stackingMode = new QStackedLayout.StackingMode();


