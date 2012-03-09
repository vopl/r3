/**
  * @name QWorkspace
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QWorkspace(parent){return undefined;};

QWorkspace.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QWorkspace
  * @name CreationOrder
  * @see QWorkspace#WindowOrder
  * @type Number
  */
QWorkspace.CreationOrder = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QWorkspace
  * @name StackingOrder
  * @see QWorkspace#WindowOrder
  * @type Number
  */
QWorkspace.StackingOrder = 0x1;

/**
  * @constructor 
  * @memberOf QWorkspace
  * @name WindowOrder
  */
QWorkspace.WindowOrder = function(value){;};



/**
  * @name activeWindow
  * @function
  * @memberOf QWorkspace.prototype
  * @returns {QWidget}
  */
QWorkspace.prototype.activeWindow = function(){return new QWidget();};

/**
  * @name addWindow
  * @function
  * @memberOf QWorkspace.prototype
  * @param {QWidget} w
  * @param {Qt.WindowFlags} flags
  * @returns {QWidget}
  */
QWorkspace.prototype.addWindow = function(w, flags){return new QWidget();};

/**
  * @name sizeHint
  * @function
  * @memberOf QWorkspace.prototype
  * @returns {QSize}
  */
QWorkspace.prototype.sizeHint = function(){return new QSize();};

/**
  * @name windowList
  * @function
  * @memberOf QWorkspace.prototype
  * @param {QMdiArea.WindowOrder} order
  * @returns {Array}
  */
QWorkspace.prototype.windowList = function(order){return new Array();};

/**
  * @name scrollBarsEnabled
  * @memberOf QWorkspace.prototype
  * @type Boolean
  */
QWorkspace.prototype.scrollBarsEnabled = new Boolean();

/**
  * @name background
  * @memberOf QWorkspace.prototype
  * @type QBrush
  */
QWorkspace.prototype.background = new QBrush();


