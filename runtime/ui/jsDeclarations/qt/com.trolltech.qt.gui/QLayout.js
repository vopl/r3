/**
  * @name QLayout
  * @constructor
  * @extends QObject
  */
function QLayout(){return undefined;};

/**
  * @name QLayout^1
  * @constructor
  * @extends QObject
  * @param {QWidget} parent
  */
function QLayout(parent){return undefined;};

QLayout.prototype = new QObject();

/**
  * @name closestAcceptableSize
  * @function
  * @memberOf QLayout
  * @param {QWidget} w
  * @param {QSize} s
  * @returns {QSize}
  */
QLayout.closestAcceptableSize = function(w, s){return new QSize();};

/**
  * @default 0x0
  * @constant
  * @memberOf QLayout
  * @name SetDefaultConstraint
  * @see QLayout#SizeConstraint
  * @type Number
  */
QLayout.SetDefaultConstraint = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QLayout
  * @name SetNoConstraint
  * @see QLayout#SizeConstraint
  * @type Number
  */
QLayout.SetNoConstraint = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QLayout
  * @name SetMinimumSize
  * @see QLayout#SizeConstraint
  * @type Number
  */
QLayout.SetMinimumSize = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QLayout
  * @name SetFixedSize
  * @see QLayout#SizeConstraint
  * @type Number
  */
QLayout.SetFixedSize = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QLayout
  * @name SetMaximumSize
  * @see QLayout#SizeConstraint
  * @type Number
  */
QLayout.SetMaximumSize = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QLayout
  * @name SetMinAndMaxSize
  * @see QLayout#SizeConstraint
  * @type Number
  */
QLayout.SetMinAndMaxSize = 0x5;

/**
  * @constructor 
  * @memberOf QLayout
  * @name SizeConstraint
  */
QLayout.SizeConstraint = function(value){;};



/**
  * @name activate
  * @function
  * @memberOf QLayout.prototype
  * @returns {Boolean}
  */
QLayout.prototype.activate = function(){return new Boolean();};

/**
  * @name addItem
  * @function
  * @memberOf QLayout.prototype
  * @param {QLayoutItem} arg__1
  * @returns {undefined}
  */
QLayout.prototype.addItem = function(arg__1){return undefined;};

/**
  * @name addWidget
  * @function
  * @memberOf QLayout.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QLayout.prototype.addWidget = function(w){return undefined;};

/**
  * @name contentsMargins
  * @function
  * @memberOf QLayout.prototype
  * @returns {QMargins}
  */
QLayout.prototype.contentsMargins = function(){return new QMargins();};

/**
  * @name contentsRect
  * @function
  * @memberOf QLayout.prototype
  * @returns {QRect}
  */
QLayout.prototype.contentsRect = function(){return new QRect();};

/**
  * @name count
  * @function
  * @memberOf QLayout.prototype
  * @returns {Numeric}
  */
QLayout.prototype.count = function(){return new Numeric();};

/**
  * @name getContentsMargins
  * @function
  * @memberOf QLayout.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @returns {undefined}
  */
QLayout.prototype.getContentsMargins = function(left, top, right, bottom){return undefined;};

/**
  * @name indexOf
  * @function
  * @memberOf QLayout.prototype
  * @param {QWidget} arg__1
  * @returns {Numeric}
  */
QLayout.prototype.indexOf = function(arg__1){return new Numeric();};

/**
  * @name isEnabled
  * @function
  * @memberOf QLayout.prototype
  * @returns {Boolean}
  */
QLayout.prototype.isEnabled = function(){return new Boolean();};

/**
  * @name itemAt
  * @function
  * @memberOf QLayout.prototype
  * @param {Numeric} index
  * @returns {QLayoutItem}
  */
QLayout.prototype.itemAt = function(index){return new QLayoutItem();};

/**
  * @name menuBar
  * @function
  * @memberOf QLayout.prototype
  * @returns {QWidget}
  */
QLayout.prototype.menuBar = function(){return new QWidget();};

/**
  * @name parentWidget
  * @function
  * @memberOf QLayout.prototype
  * @returns {QWidget}
  */
QLayout.prototype.parentWidget = function(){return new QWidget();};

/**
  * @name removeItem
  * @function
  * @memberOf QLayout.prototype
  * @param {QLayoutItem} arg__1
  * @returns {undefined}
  */
QLayout.prototype.removeItem = function(arg__1){return undefined;};

/**
  * @name removeWidget
  * @function
  * @memberOf QLayout.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QLayout.prototype.removeWidget = function(w){return undefined;};

/**
  * @name setAlignment
  * @function
  * @memberOf QLayout.prototype
  * @param {QLayout} l
  * @param {Qt.Alignment} alignment
  * @returns {Boolean}
  */
QLayout.prototype.setAlignment = function(l, alignment){return new Boolean();};

/**
  * @name setContentsMargins
  * @function
  * @memberOf QLayout.prototype
  * @param {QMargins} margins
  * @returns {undefined}
  */
QLayout.prototype.setContentsMargins = function(margins){return undefined;};

/**
  * @name setEnabled
  * @function
  * @memberOf QLayout.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QLayout.prototype.setEnabled = function(arg__1){return undefined;};

/**
  * @name setMenuBar
  * @function
  * @memberOf QLayout.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QLayout.prototype.setMenuBar = function(w){return undefined;};

/**
  * @name takeAt
  * @function
  * @memberOf QLayout.prototype
  * @param {Numeric} index
  * @returns {QLayoutItem}
  */
QLayout.prototype.takeAt = function(index){return new QLayoutItem();};

/**
  * @name totalHeightForWidth
  * @function
  * @memberOf QLayout.prototype
  * @param {Numeric} w
  * @returns {Numeric}
  */
QLayout.prototype.totalHeightForWidth = function(w){return new Numeric();};

/**
  * @name totalMaximumSize
  * @function
  * @memberOf QLayout.prototype
  * @returns {QSize}
  */
QLayout.prototype.totalMaximumSize = function(){return new QSize();};

/**
  * @name totalMinimumSize
  * @function
  * @memberOf QLayout.prototype
  * @returns {QSize}
  */
QLayout.prototype.totalMinimumSize = function(){return new QSize();};

/**
  * @name totalSizeHint
  * @function
  * @memberOf QLayout.prototype
  * @returns {QSize}
  */
QLayout.prototype.totalSizeHint = function(){return new QSize();};

/**
  * @name update
  * @function
  * @memberOf QLayout.prototype
  * @returns {undefined}
  */
QLayout.prototype.update = function(){return undefined;};

/**
  * @name margin
  * @memberOf QLayout.prototype
  * @type Numeric
  */
QLayout.prototype.margin = new Numeric();

/**
  * @name spacing
  * @memberOf QLayout.prototype
  * @type Numeric
  */
QLayout.prototype.spacing = new Numeric();

/**
  * @name sizeConstraint
  * @memberOf QLayout.prototype
  * @type QLayout.SizeConstraint
  */
QLayout.prototype.sizeConstraint = new QLayout.SizeConstraint();


