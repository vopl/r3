/**
  * @name QBoxLayout
  * @constructor
  * @extends QLayout
  * @param {QBoxLayout.Direction} arg__1
  * @param {QWidget} parent
  */
function QBoxLayout(arg__1, parent){return undefined;};

QBoxLayout.prototype = new QLayout();

/**
  * @default 0x0
  * @constant
  * @memberOf QBoxLayout
  * @name LeftToRight
  * @see QBoxLayout#Direction
  * @type Number
  */
QBoxLayout.LeftToRight = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QBoxLayout
  * @name RightToLeft
  * @see QBoxLayout#Direction
  * @type Number
  */
QBoxLayout.RightToLeft = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QBoxLayout
  * @name TopToBottom
  * @see QBoxLayout#Direction
  * @type Number
  */
QBoxLayout.TopToBottom = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QBoxLayout
  * @name BottomToTop
  * @see QBoxLayout#Direction
  * @type Number
  */
QBoxLayout.BottomToTop = 0x3;

/**
  * @constructor 
  * @memberOf QBoxLayout
  * @name Direction
  */
QBoxLayout.Direction = function(value){;};



/**
  * @name addLayout
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {QLayout} layout
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QBoxLayout.prototype.addLayout = function(layout, stretch){return undefined;};

/**
  * @name addSpacerItem
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {QSpacerItem} spacerItem
  * @returns {undefined}
  */
QBoxLayout.prototype.addSpacerItem = function(spacerItem){return undefined;};

/**
  * @name addSpacing
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QBoxLayout.prototype.addSpacing = function(size){return undefined;};

/**
  * @name addStretch
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QBoxLayout.prototype.addStretch = function(stretch){return undefined;};

/**
  * @name addStrut
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QBoxLayout.prototype.addStrut = function(arg__1){return undefined;};

/**
  * @name addWidget
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {QWidget} arg__1
  * @param {Numeric} stretch
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QBoxLayout.prototype.addWidget = function(arg__1, stretch, alignment){return undefined;};

/**
  * @name direction
  * @function
  * @memberOf QBoxLayout.prototype
  * @returns {QBoxLayout.Direction}
  */
QBoxLayout.prototype.direction = function(){return new QBoxLayout.Direction();};

/**
  * @name insertLayout
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @param {QLayout} layout
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QBoxLayout.prototype.insertLayout = function(index, layout, stretch){return undefined;};

/**
  * @name insertSpacerItem
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @param {QSpacerItem} spacerItem
  * @returns {undefined}
  */
QBoxLayout.prototype.insertSpacerItem = function(index, spacerItem){return undefined;};

/**
  * @name insertSpacing
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @param {Numeric} size
  * @returns {undefined}
  */
QBoxLayout.prototype.insertSpacing = function(index, size){return undefined;};

/**
  * @name insertStretch
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QBoxLayout.prototype.insertStretch = function(index, stretch){return undefined;};

/**
  * @name insertWidget
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @param {QWidget} widget
  * @param {Numeric} stretch
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QBoxLayout.prototype.insertWidget = function(index, widget, stretch, alignment){return undefined;};

/**
  * @name setDirection
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {QBoxLayout.Direction} arg__1
  * @returns {undefined}
  */
QBoxLayout.prototype.setDirection = function(arg__1){return undefined;};

/**
  * @name setSpacing
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} spacing
  * @returns {undefined}
  */
QBoxLayout.prototype.setSpacing = function(spacing){return undefined;};

/**
  * @name setStretch
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QBoxLayout.prototype.setStretch = function(index, stretch){return undefined;};

/**
  * @name setStretchFactor
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {QLayout} l
  * @param {Numeric} stretch
  * @returns {Boolean}
  */
QBoxLayout.prototype.setStretchFactor = function(l, stretch){return new Boolean();};

/**
  * @name spacing
  * @function
  * @memberOf QBoxLayout.prototype
  * @returns {Numeric}
  */
QBoxLayout.prototype.spacing = function(){return new Numeric();};

/**
  * @name stretch
  * @function
  * @memberOf QBoxLayout.prototype
  * @param {Numeric} index
  * @returns {Numeric}
  */
QBoxLayout.prototype.stretch = function(index){return new Numeric();};

