/**
  * @name QListView
  * @constructor
  * @extends QAbstractItemView
  * @param {QWidget} parent
  */
function QListView(parent){return undefined;};

QListView.prototype = new QAbstractItemView();

/**
  * @default 0x0
  * @constant
  * @memberOf QListView
  * @name Fixed
  * @see QListView#ResizeMode
  * @type Number
  */
QListView.Fixed = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QListView
  * @name Adjust
  * @see QListView#ResizeMode
  * @type Number
  */
QListView.Adjust = 0x1;

/**
  * @constructor 
  * @memberOf QListView
  * @name ResizeMode
  */
QListView.ResizeMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QListView
  * @name SinglePass
  * @see QListView#LayoutMode
  * @type Number
  */
QListView.SinglePass = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QListView
  * @name Batched
  * @see QListView#LayoutMode
  * @type Number
  */
QListView.Batched = 0x1;

/**
  * @constructor 
  * @memberOf QListView
  * @name LayoutMode
  */
QListView.LayoutMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QListView
  * @name ListMode
  * @see QListView#ViewMode
  * @type Number
  */
QListView.ListMode = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QListView
  * @name IconMode
  * @see QListView#ViewMode
  * @type Number
  */
QListView.IconMode = 0x1;

/**
  * @constructor 
  * @memberOf QListView
  * @name ViewMode
  */
QListView.ViewMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QListView
  * @name LeftToRight
  * @see QListView#Flow
  * @type Number
  */
QListView.LeftToRight = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QListView
  * @name TopToBottom
  * @see QListView#Flow
  * @type Number
  */
QListView.TopToBottom = 0x1;

/**
  * @constructor 
  * @memberOf QListView
  * @name Flow
  */
QListView.Flow = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QListView
  * @name Static
  * @see QListView#Movement
  * @type Number
  */
QListView.Static = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QListView
  * @name Free
  * @see QListView#Movement
  * @type Number
  */
QListView.Free = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QListView
  * @name Snap
  * @see QListView#Movement
  * @type Number
  */
QListView.Snap = 0x2;

/**
  * @constructor 
  * @memberOf QListView
  * @name Movement
  */
QListView.Movement = function(value){;};



/**
  * @name clearPropertyFlags
  * @function
  * @memberOf QListView.prototype
  * @returns {undefined}
  */
QListView.prototype.clearPropertyFlags = function(){return undefined;};

/**
  * @name isRowHidden
  * @function
  * @memberOf QListView.prototype
  * @param {Numeric} row
  * @returns {Boolean}
  */
QListView.prototype.isRowHidden = function(row){return new Boolean();};

/**
  * @name setRowHidden
  * @function
  * @memberOf QListView.prototype
  * @param {Numeric} row
  * @param {Boolean} hide
  * @returns {undefined}
  */
QListView.prototype.setRowHidden = function(row, hide){return undefined;};

/**
  * @name movement
  * @memberOf QListView.prototype
  * @type QListView.Movement
  */
QListView.prototype.movement = new QListView.Movement();

/**
  * @name flow
  * @memberOf QListView.prototype
  * @type QListView.Flow
  */
QListView.prototype.flow = new QListView.Flow();

/**
  * @name isWrapping
  * @memberOf QListView.prototype
  * @type Boolean
  */
QListView.prototype.isWrapping = new Boolean();

/**
  * @name resizeMode
  * @memberOf QListView.prototype
  * @type QListView.ResizeMode
  */
QListView.prototype.resizeMode = new QListView.ResizeMode();

/**
  * @name layoutMode
  * @memberOf QListView.prototype
  * @type QListView.LayoutMode
  */
QListView.prototype.layoutMode = new QListView.LayoutMode();

/**
  * @name spacing
  * @memberOf QListView.prototype
  * @type Numeric
  */
QListView.prototype.spacing = new Numeric();

/**
  * @name gridSize
  * @memberOf QListView.prototype
  * @type QSize
  */
QListView.prototype.gridSize = new QSize();

/**
  * @name viewMode
  * @memberOf QListView.prototype
  * @type QListView.ViewMode
  */
QListView.prototype.viewMode = new QListView.ViewMode();

/**
  * @name modelColumn
  * @memberOf QListView.prototype
  * @type Numeric
  */
QListView.prototype.modelColumn = new Numeric();

/**
  * @name uniformItemSizes
  * @memberOf QListView.prototype
  * @type Boolean
  */
QListView.prototype.uniformItemSizes = new Boolean();

/**
  * @name batchSize
  * @memberOf QListView.prototype
  * @type Numeric
  */
QListView.prototype.batchSize = new Numeric();

/**
  * @name wordWrap
  * @memberOf QListView.prototype
  * @type Boolean
  */
QListView.prototype.wordWrap = new Boolean();

/**
  * @name selectionRectVisible
  * @memberOf QListView.prototype
  * @type Boolean
  */
QListView.prototype.selectionRectVisible = new Boolean();


