/**
  * @name QHeaderView
  * @constructor
  * @extends QAbstractItemView
  * @param {QPrinter.Orientation} orientation
  * @param {QWidget} parent
  */
function QHeaderView(orientation, parent){return undefined;};

QHeaderView.prototype = new QAbstractItemView();

/**
  * @default 0x0
  * @constant
  * @memberOf QHeaderView
  * @name Interactive
  * @see QHeaderView#ResizeMode
  * @type Number
  */
QHeaderView.Interactive = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHeaderView
  * @name Stretch
  * @see QHeaderView#ResizeMode
  * @type Number
  */
QHeaderView.Stretch = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QHeaderView
  * @name Fixed
  * @see QHeaderView#ResizeMode
  * @type Number
  */
QHeaderView.Fixed = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QHeaderView
  * @name ResizeToContents
  * @see QHeaderView#ResizeMode
  * @type Number
  */
QHeaderView.ResizeToContents = 0x3;

/**
  * @constructor 
  * @memberOf QHeaderView
  * @name ResizeMode
  */
QHeaderView.ResizeMode = function(value){;};



/**
  * @name count
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Numeric}
  */
QHeaderView.prototype.count = function(){return new Numeric();};

/**
  * @name hiddenSectionCount
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Numeric}
  */
QHeaderView.prototype.hiddenSectionCount = function(){return new Numeric();};

/**
  * @name hideSection
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {undefined}
  */
QHeaderView.prototype.hideSection = function(logicalIndex){return undefined;};

/**
  * @name isClickable
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Boolean}
  */
QHeaderView.prototype.isClickable = function(){return new Boolean();};

/**
  * @name isMovable
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Boolean}
  */
QHeaderView.prototype.isMovable = function(){return new Boolean();};

/**
  * @name isSectionHidden
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {Boolean}
  */
QHeaderView.prototype.isSectionHidden = function(logicalIndex){return new Boolean();};

/**
  * @name length
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Numeric}
  */
QHeaderView.prototype.length = function(){return new Numeric();};

/**
  * @name logicalIndex
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} visualIndex
  * @returns {Numeric}
  */
QHeaderView.prototype.logicalIndex = function(visualIndex){return new Numeric();};

/**
  * @name logicalIndexAt
  * @function
  * @memberOf QHeaderView.prototype
  * @param {QPoint} pos
  * @returns {Numeric}
  */
QHeaderView.prototype.logicalIndexAt = function(pos){return new Numeric();};

/**
  * @name moveSection
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} from
  * @param {Numeric} to
  * @returns {undefined}
  */
QHeaderView.prototype.moveSection = function(from, to){return undefined;};

/**
  * @name offset
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Numeric}
  */
QHeaderView.prototype.offset = function(){return new Numeric();};

/**
  * @name orientation
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {QPrinter.Orientation}
  */
QHeaderView.prototype.orientation = function(){return new QPrinter.Orientation();};

/**
  * @name resizeMode
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {QListView.ResizeMode}
  */
QHeaderView.prototype.resizeMode = function(logicalIndex){return new QListView.ResizeMode();};

/**
  * @name resizeSection
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @param {Numeric} size
  * @returns {undefined}
  */
QHeaderView.prototype.resizeSection = function(logicalIndex, size){return undefined;};

/**
  * @name resizeSections
  * @function
  * @memberOf QHeaderView.prototype
  * @param {QListView.ResizeMode} mode
  * @returns {undefined}
  */
QHeaderView.prototype.resizeSections = function(mode){return undefined;};

/**
  * @name restoreState
  * @function
  * @memberOf QHeaderView.prototype
  * @param {QByteArray} state
  * @returns {Boolean}
  */
QHeaderView.prototype.restoreState = function(state){return new Boolean();};

/**
  * @name saveState
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {QByteArray}
  */
QHeaderView.prototype.saveState = function(){return new QByteArray();};

/**
  * @name sectionPosition
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {Numeric}
  */
QHeaderView.prototype.sectionPosition = function(logicalIndex){return new Numeric();};

/**
  * @name sectionSize
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {Numeric}
  */
QHeaderView.prototype.sectionSize = function(logicalIndex){return new Numeric();};

/**
  * @name sectionSizeHint
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {Numeric}
  */
QHeaderView.prototype.sectionSizeHint = function(logicalIndex){return new Numeric();};

/**
  * @name sectionViewportPosition
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {Numeric}
  */
QHeaderView.prototype.sectionViewportPosition = function(logicalIndex){return new Numeric();};

/**
  * @name sectionsHidden
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Boolean}
  */
QHeaderView.prototype.sectionsHidden = function(){return new Boolean();};

/**
  * @name sectionsMoved
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Boolean}
  */
QHeaderView.prototype.sectionsMoved = function(){return new Boolean();};

/**
  * @name setClickable
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Boolean} clickable
  * @returns {undefined}
  */
QHeaderView.prototype.setClickable = function(clickable){return undefined;};

/**
  * @name setMovable
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Boolean} movable
  * @returns {undefined}
  */
QHeaderView.prototype.setMovable = function(movable){return undefined;};

/**
  * @name setResizeMode
  * @function
  * @memberOf QHeaderView.prototype
  * @param {QListView.ResizeMode} mode
  * @returns {undefined}
  */
QHeaderView.prototype.setResizeMode = function(mode){return undefined;};

/**
  * @name setSectionHidden
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @param {Boolean} hide
  * @returns {undefined}
  */
QHeaderView.prototype.setSectionHidden = function(logicalIndex, hide){return undefined;};

/**
  * @name setSortIndicator
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @param {Qt.SortOrder} order
  * @returns {undefined}
  */
QHeaderView.prototype.setSortIndicator = function(logicalIndex, order){return undefined;};

/**
  * @name showSection
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {undefined}
  */
QHeaderView.prototype.showSection = function(logicalIndex){return undefined;};

/**
  * @name sortIndicatorOrder
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Qt.SortOrder}
  */
QHeaderView.prototype.sortIndicatorOrder = function(){return new Qt.SortOrder();};

/**
  * @name sortIndicatorSection
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Numeric}
  */
QHeaderView.prototype.sortIndicatorSection = function(){return new Numeric();};

/**
  * @name stretchSectionCount
  * @function
  * @memberOf QHeaderView.prototype
  * @returns {Numeric}
  */
QHeaderView.prototype.stretchSectionCount = function(){return new Numeric();};

/**
  * @name swapSections
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} first
  * @param {Numeric} second
  * @returns {undefined}
  */
QHeaderView.prototype.swapSections = function(first, second){return undefined;};

/**
  * @name visualIndex
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} logicalIndex
  * @returns {Numeric}
  */
QHeaderView.prototype.visualIndex = function(logicalIndex){return new Numeric();};

/**
  * @name visualIndexAt
  * @function
  * @memberOf QHeaderView.prototype
  * @param {Numeric} position
  * @returns {Numeric}
  */
QHeaderView.prototype.visualIndexAt = function(position){return new Numeric();};

/**
  * @name showSortIndicator
  * @memberOf QHeaderView.prototype
  * @type Boolean
  */
QHeaderView.prototype.showSortIndicator = new Boolean();

/**
  * @name highlightSections
  * @memberOf QHeaderView.prototype
  * @type Boolean
  */
QHeaderView.prototype.highlightSections = new Boolean();

/**
  * @name stretchLastSection
  * @memberOf QHeaderView.prototype
  * @type Boolean
  */
QHeaderView.prototype.stretchLastSection = new Boolean();

/**
  * @name cascadingSectionResizes
  * @memberOf QHeaderView.prototype
  * @type Boolean
  */
QHeaderView.prototype.cascadingSectionResizes = new Boolean();

/**
  * @name defaultSectionSize
  * @memberOf QHeaderView.prototype
  * @type Numeric
  */
QHeaderView.prototype.defaultSectionSize = new Numeric();

/**
  * @name minimumSectionSize
  * @memberOf QHeaderView.prototype
  * @type Numeric
  */
QHeaderView.prototype.minimumSectionSize = new Numeric();

/**
  * @name defaultAlignment
  * @memberOf QHeaderView.prototype
  * @type Qt.Alignment
  */
QHeaderView.prototype.defaultAlignment = new Qt.Alignment();


