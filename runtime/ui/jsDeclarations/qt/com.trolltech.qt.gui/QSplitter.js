/**
  * @name QSplitter
  * @constructor
  * @extends QFrame
  * @param {QWidget} parent
  */
function QSplitter(parent){return undefined;};

/**
  * @name QSplitter^1
  * @constructor
  * @extends QFrame
  * @param {QPrinter.Orientation} arg__1
  * @param {QWidget} parent
  */
function QSplitter(arg__1, parent){return undefined;};

QSplitter.prototype = new QFrame();

/**
  * @name addWidget
  * @function
  * @memberOf QSplitter.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QSplitter.prototype.addWidget = function(widget){return undefined;};

/**
  * @name count
  * @function
  * @memberOf QSplitter.prototype
  * @returns {Numeric}
  */
QSplitter.prototype.count = function(){return new Numeric();};

/**
  * @name getRange
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @param {Numeric} arg__2
  * @param {Numeric} arg__3
  * @returns {undefined}
  */
QSplitter.prototype.getRange = function(index, arg__2, arg__3){return undefined;};

/**
  * @name handle
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @returns {QSplitterHandle}
  */
QSplitter.prototype.handle = function(index){return new QSplitterHandle();};

/**
  * @name indexOf
  * @function
  * @memberOf QSplitter.prototype
  * @param {QWidget} w
  * @returns {Numeric}
  */
QSplitter.prototype.indexOf = function(w){return new Numeric();};

/**
  * @name insertWidget
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @param {QWidget} widget
  * @returns {undefined}
  */
QSplitter.prototype.insertWidget = function(index, widget){return undefined;};

/**
  * @name isCollapsible
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @returns {Boolean}
  */
QSplitter.prototype.isCollapsible = function(index){return new Boolean();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QSplitter.prototype
  * @returns {QSize}
  */
QSplitter.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name readFrom
  * @function
  * @memberOf QSplitter.prototype
  * @param {QTextStream} arg__1
  * @returns {undefined}
  */
QSplitter.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name refresh
  * @function
  * @memberOf QSplitter.prototype
  * @returns {undefined}
  */
QSplitter.prototype.refresh = function(){return undefined;};

/**
  * @name restoreState
  * @function
  * @memberOf QSplitter.prototype
  * @param {QByteArray} state
  * @returns {Boolean}
  */
QSplitter.prototype.restoreState = function(state){return new Boolean();};

/**
  * @name saveState
  * @function
  * @memberOf QSplitter.prototype
  * @returns {QByteArray}
  */
QSplitter.prototype.saveState = function(){return new QByteArray();};

/**
  * @name setCollapsible
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @param {Boolean} arg__2
  * @returns {undefined}
  */
QSplitter.prototype.setCollapsible = function(index, arg__2){return undefined;};

/**
  * @name setSizes
  * @function
  * @memberOf QSplitter.prototype
  * @param {Array} list
  * @returns {undefined}
  */
QSplitter.prototype.setSizes = function(list){return undefined;};

/**
  * @name setStretchFactor
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QSplitter.prototype.setStretchFactor = function(index, stretch){return undefined;};

/**
  * @name sizes
  * @function
  * @memberOf QSplitter.prototype
  * @returns {Array}
  */
QSplitter.prototype.sizes = function(){return new Array();};

/**
  * @name widget
  * @function
  * @memberOf QSplitter.prototype
  * @param {Numeric} index
  * @returns {QWidget}
  */
QSplitter.prototype.widget = function(index){return new QWidget();};

/**
  * @name writeTo
  * @function
  * @memberOf QSplitter.prototype
  * @param {QTextStream} arg__1
  * @returns {undefined}
  */
QSplitter.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name orientation
  * @memberOf QSplitter.prototype
  * @type QPrinter.Orientation
  */
QSplitter.prototype.orientation = new QPrinter.Orientation();

/**
  * @name opaqueResize
  * @memberOf QSplitter.prototype
  * @type Boolean
  */
QSplitter.prototype.opaqueResize = new Boolean();

/**
  * @name handleWidth
  * @memberOf QSplitter.prototype
  * @type Numeric
  */
QSplitter.prototype.handleWidth = new Numeric();

/**
  * @name childrenCollapsible
  * @memberOf QSplitter.prototype
  * @type Boolean
  */
QSplitter.prototype.childrenCollapsible = new Boolean();


