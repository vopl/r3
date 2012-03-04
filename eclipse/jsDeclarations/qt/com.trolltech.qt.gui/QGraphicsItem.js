/**
  * @name QGraphicsItem
  * @constructor
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsItem(parent, scene){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsItem
  * @name NoCache
  * @see QGraphicsItem#CacheMode
  * @type Number
  */
QGraphicsItem.NoCache = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemCoordinateCache
  * @see QGraphicsItem#CacheMode
  * @type Number
  */
QGraphicsItem.ItemCoordinateCache = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsItem
  * @name DeviceCoordinateCache
  * @see QGraphicsItem#CacheMode
  * @type Number
  */
QGraphicsItem.DeviceCoordinateCache = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsItem
  * @name CacheMode
  */
QGraphicsItem.CacheMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsItem
  * @name NonModal
  * @see QGraphicsItem#PanelModality
  * @type Number
  */
QGraphicsItem.NonModal = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsItem
  * @name PanelModal
  * @see QGraphicsItem#PanelModality
  * @type Number
  */
QGraphicsItem.PanelModal = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsItem
  * @name SceneModal
  * @see QGraphicsItem#PanelModality
  * @type Number
  */
QGraphicsItem.SceneModal = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsItem
  * @name PanelModality
  */
QGraphicsItem.PanelModality = function(value){;};



/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIsMovable
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIsMovable = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIsSelectable
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIsSelectable = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIsFocusable
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIsFocusable = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemClipsToShape
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemClipsToShape = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemClipsChildrenToShape
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemClipsChildrenToShape = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIgnoresTransformations
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIgnoresTransformations = 0x20;

/**
  * @default 0x40
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIgnoresParentOpacity
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIgnoresParentOpacity = 0x40;

/**
  * @default 0x80
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemDoesntPropagateOpacityToChildren
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemDoesntPropagateOpacityToChildren = 0x80;

/**
  * @default 0x100
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemStacksBehindParent
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemStacksBehindParent = 0x100;

/**
  * @default 0x200
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemUsesExtendedStyleOption
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemUsesExtendedStyleOption = 0x200;

/**
  * @default 0x400
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemHasNoContents
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemHasNoContents = 0x400;

/**
  * @default 0x800
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemSendsGeometryChanges
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemSendsGeometryChanges = 0x800;

/**
  * @default 0x1000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemAcceptsInputMethod
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemAcceptsInputMethod = 0x1000;

/**
  * @default 0x2000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemNegativeZStacksBehindParent
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemNegativeZStacksBehindParent = 0x2000;

/**
  * @default 0x4000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIsPanel
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIsPanel = 0x4000;

/**
  * @default 0x8000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemIsFocusScope
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemIsFocusScope = 0x8000;

/**
  * @default 0x10000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemSendsScenePositionChanges
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemSendsScenePositionChanges = 0x10000;

/**
  * @default 0x20000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemStopsClickFocusPropagation
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemStopsClickFocusPropagation = 0x20000;

/**
  * @default 0x40000
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemStopsFocusHandling
  * @see QGraphicsItem#GraphicsItemFlags
  * @see QGraphicsItem#GraphicsItemFlag
  * @type Number
  */
QGraphicsItem.ItemStopsFocusHandling = 0x40000;

/**
  * @constructor 
  * @memberOf QGraphicsItem
  * @name GraphicsItemFlag
  */
QGraphicsItem.GraphicsItemFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QGraphicsItem
  * @name GraphicsItemFlags
  */
QGraphicsItem.GraphicsItemFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemPositionChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemPositionChange = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemMatrixChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemMatrixChange = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemVisibleChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemVisibleChange = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemEnabledChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemEnabledChange = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemSelectedChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemSelectedChange = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemParentChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemParentChange = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemChildAddedChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemChildAddedChange = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemChildRemovedChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemChildRemovedChange = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemTransformChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemTransformChange = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemPositionHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemPositionHasChanged = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemTransformHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemTransformHasChanged = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemSceneChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemSceneChange = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemVisibleHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemVisibleHasChanged = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemEnabledHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemEnabledHasChanged = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemSelectedHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemSelectedHasChanged = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemParentHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemParentHasChanged = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemSceneHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemSceneHasChanged = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemCursorChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemCursorChange = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemCursorHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemCursorHasChanged = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemToolTipChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemToolTipChange = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemToolTipHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemToolTipHasChanged = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemFlagsChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemFlagsChange = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemFlagsHaveChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemFlagsHaveChanged = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemZValueChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemZValueChange = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemZValueHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemZValueHasChanged = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemOpacityChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemOpacityChange = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemOpacityHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemOpacityHasChanged = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemScenePositionHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemScenePositionHasChanged = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemRotationChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemRotationChange = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemRotationHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemRotationHasChanged = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemScaleChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemScaleChange = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemScaleHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemScaleHasChanged = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemTransformOriginPointChange
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemTransformOriginPointChange = 0x20;

/**
  * @default 0x21
  * @constant
  * @memberOf QGraphicsItem
  * @name ItemTransformOriginPointHasChanged
  * @see QGraphicsItem#GraphicsItemChange
  * @type Number
  */
QGraphicsItem.ItemTransformOriginPointHasChanged = 0x21;

/**
  * @constructor 
  * @memberOf QGraphicsItem
  * @name GraphicsItemChange
  */
QGraphicsItem.GraphicsItemChange = function(value){;};



/**
  * @name acceptDrops
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.acceptDrops = function(){return new Boolean();};

/**
  * @name acceptHoverEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.acceptHoverEvents = function(){return new Boolean();};

/**
  * @name acceptTouchEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.acceptTouchEvents = function(){return new Boolean();};

/**
  * @name acceptedMouseButtons
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Qt.MouseButtons}
  */
QGraphicsItem.prototype.acceptedMouseButtons = function(){return new Qt.MouseButtons();};

/**
  * @name acceptsHoverEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.acceptsHoverEvents = function(){return new Boolean();};

/**
  * @name advance
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} phase
  * @returns {undefined}
  */
QGraphicsItem.prototype.advance = function(phase){return undefined;};

/**
  * @name boundingRect
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QRectF}
  */
QGraphicsItem.prototype.boundingRect = function(){return new QRectF();};

/**
  * @name boundingRegion
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QTransform} itemToDeviceTransform
  * @returns {QRegion}
  */
QGraphicsItem.prototype.boundingRegion = function(itemToDeviceTransform){return new QRegion();};

/**
  * @name boundingRegionGranularity
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.boundingRegionGranularity = function(){return new Numeric();};

/**
  * @name cacheMode
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsView.CacheMode}
  */
QGraphicsItem.prototype.cacheMode = function(){return new QGraphicsView.CacheMode();};

/**
  * @name childItems
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Array}
  */
QGraphicsItem.prototype.childItems = function(){return new Array();};

/**
  * @name childrenBoundingRect
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QRectF}
  */
QGraphicsItem.prototype.childrenBoundingRect = function(){return new QRectF();};

/**
  * @name clearFocus
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.clearFocus = function(){return undefined;};

/**
  * @name clipPath
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.clipPath = function(){return new QPainterPath();};

/**
  * @name collidesWithItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} other
  * @param {Qt.ItemSelectionMode} mode
  * @returns {Boolean}
  */
QGraphicsItem.prototype.collidesWithItem = function(other, mode){return new Boolean();};

/**
  * @name collidesWithPath
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPainterPath} path
  * @param {Qt.ItemSelectionMode} mode
  * @returns {Boolean}
  */
QGraphicsItem.prototype.collidesWithPath = function(path, mode){return new Boolean();};

/**
  * @name collidingItems
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Qt.ItemSelectionMode} mode
  * @returns {Array}
  */
QGraphicsItem.prototype.collidingItems = function(mode){return new Array();};

/**
  * @name commonAncestorItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} other
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.commonAncestorItem = function(other){return new QGraphicsItem();};

/**
  * @name contains
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPointF} point
  * @returns {Boolean}
  */
QGraphicsItem.prototype.contains = function(point){return new Boolean();};

/**
  * @name cursor
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QCursor}
  */
QGraphicsItem.prototype.cursor = function(){return new QCursor();};

/**
  * @name data
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} key
  * @returns {Object}
  */
QGraphicsItem.prototype.data = function(key){return new Object();};

/**
  * @name deviceTransform
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QTransform} viewportTransform
  * @returns {QTransform}
  */
QGraphicsItem.prototype.deviceTransform = function(viewportTransform){return new QTransform();};

/**
  * @name effectiveOpacity
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.effectiveOpacity = function(){return new Numeric();};

/**
  * @name ensureVisible
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QRectF} rect
  * @param {Numeric} xmargin
  * @param {Numeric} ymargin
  * @returns {undefined}
  */
QGraphicsItem.prototype.ensureVisible = function(rect, xmargin, ymargin){return undefined;};

/**
  * @name filtersChildEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.filtersChildEvents = function(){return new Boolean();};

/**
  * @name flags
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem.GraphicsItemFlags}
  */
QGraphicsItem.prototype.flags = function(){return new QGraphicsItem.GraphicsItemFlags();};

/**
  * @name focusItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.focusItem = function(){return new QGraphicsItem();};

/**
  * @name focusProxy
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.focusProxy = function(){return new QGraphicsItem();};

/**
  * @name focusScopeItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.focusScopeItem = function(){return new QGraphicsItem();};

/**
  * @name grabKeyboard
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.grabKeyboard = function(){return undefined;};

/**
  * @name grabMouse
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.grabMouse = function(){return undefined;};

/**
  * @name graphicsEffect
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsEffect}
  */
QGraphicsItem.prototype.graphicsEffect = function(){return new QGraphicsEffect();};

/**
  * @name group
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItemGroup}
  */
QGraphicsItem.prototype.group = function(){return new QGraphicsItemGroup();};

/**
  * @name handlesChildEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.handlesChildEvents = function(){return new Boolean();};

/**
  * @name hasCursor
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.hasCursor = function(){return new Boolean();};

/**
  * @name hasFocus
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.hasFocus = function(){return new Boolean();};

/**
  * @name hide
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.hide = function(){return undefined;};

/**
  * @name inputMethodHints
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Qt.InputMethodHints}
  */
QGraphicsItem.prototype.inputMethodHints = function(){return new Qt.InputMethodHints();};

/**
  * @name installSceneEventFilter
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} filterItem
  * @returns {undefined}
  */
QGraphicsItem.prototype.installSceneEventFilter = function(filterItem){return undefined;};

/**
  * @name isActive
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isActive = function(){return new Boolean();};

/**
  * @name isAncestorOf
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} child
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isAncestorOf = function(child){return new Boolean();};

/**
  * @name isBlockedByModalPanel
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} blockingPanel
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isBlockedByModalPanel = function(blockingPanel){return new Boolean();};

/**
  * @name isClipped
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isClipped = function(){return new Boolean();};

/**
  * @name isEnabled
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isEnabled = function(){return new Boolean();};

/**
  * @name isObscured
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isObscured = function(){return new Boolean();};

/**
  * @name isObscuredBy
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} item
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isObscuredBy = function(item){return new Boolean();};

/**
  * @name isPanel
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isPanel = function(){return new Boolean();};

/**
  * @name isSelected
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isSelected = function(){return new Boolean();};

/**
  * @name isUnderMouse
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isUnderMouse = function(){return new Boolean();};

/**
  * @name isVisible
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isVisible = function(){return new Boolean();};

/**
  * @name isVisibleTo
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} parent
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isVisibleTo = function(parent){return new Boolean();};

/**
  * @name isWidget
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isWidget = function(){return new Boolean();};

/**
  * @name isWindow
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Boolean}
  */
QGraphicsItem.prototype.isWindow = function(){return new Boolean();};

/**
  * @name itemTransform
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} other
  * @param {Boolean} ok
  * @returns {QTransform}
  */
QGraphicsItem.prototype.itemTransform = function(other, ok){return new QTransform();};

/**
  * @name mapFromItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} item
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.mapFromItem = function(item, path){return new QPainterPath();};

/**
  * @name mapFromParent
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.mapFromParent = function(path){return new QPainterPath();};

/**
  * @name mapFromScene
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.mapFromScene = function(path){return new QPainterPath();};

/**
  * @name mapRectFromItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} item
  * @param {QRectF} rect
  * @returns {QRectF}
  */
QGraphicsItem.prototype.mapRectFromItem = function(item, rect){return new QRectF();};

/**
  * @name mapRectFromParent
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QRectF} rect
  * @returns {QRectF}
  */
QGraphicsItem.prototype.mapRectFromParent = function(rect){return new QRectF();};

/**
  * @name mapRectFromScene
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QRectF} rect
  * @returns {QRectF}
  */
QGraphicsItem.prototype.mapRectFromScene = function(rect){return new QRectF();};

/**
  * @name mapRectToItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} item
  * @param {QRectF} rect
  * @returns {QRectF}
  */
QGraphicsItem.prototype.mapRectToItem = function(item, rect){return new QRectF();};

/**
  * @name mapRectToParent
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QRectF} rect
  * @returns {QRectF}
  */
QGraphicsItem.prototype.mapRectToParent = function(rect){return new QRectF();};

/**
  * @name mapRectToScene
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QRectF} rect
  * @returns {QRectF}
  */
QGraphicsItem.prototype.mapRectToScene = function(rect){return new QRectF();};

/**
  * @name mapToItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} item
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.mapToItem = function(item, path){return new QPainterPath();};

/**
  * @name mapToParent
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.mapToParent = function(path){return new QPainterPath();};

/**
  * @name mapToScene
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.mapToScene = function(path){return new QPainterPath();};

/**
  * @name moveBy
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {undefined}
  */
QGraphicsItem.prototype.moveBy = function(dx, dy){return undefined;};

/**
  * @name opacity
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.opacity = function(){return new Numeric();};

/**
  * @name opaqueArea
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.opaqueArea = function(){return new QPainterPath();};

/**
  * @name paint
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPainter} painter
  * @param {QStyleOptionGraphicsItem} option
  * @param {QWidget} widget
  * @returns {undefined}
  */
QGraphicsItem.prototype.paint = function(painter, option, widget){return undefined;};

/**
  * @name panel
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.panel = function(){return new QGraphicsItem();};

/**
  * @name panelModality
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem.PanelModality}
  */
QGraphicsItem.prototype.panelModality = function(){return new QGraphicsItem.PanelModality();};

/**
  * @name parentItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.parentItem = function(){return new QGraphicsItem();};

/**
  * @name parentObject
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsObject}
  */
QGraphicsItem.prototype.parentObject = function(){return new QGraphicsObject();};

/**
  * @name parentWidget
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsWidget}
  */
QGraphicsItem.prototype.parentWidget = function(){return new QGraphicsWidget();};

/**
  * @name pos
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QPointF}
  */
QGraphicsItem.prototype.pos = function(){return new QPointF();};

/**
  * @name removeSceneEventFilter
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} filterItem
  * @returns {undefined}
  */
QGraphicsItem.prototype.removeSceneEventFilter = function(filterItem){return undefined;};

/**
  * @name resetTransform
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.resetTransform = function(){return undefined;};

/**
  * @name rotate
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QGraphicsItem.prototype.rotate = function(angle){return undefined;};

/**
  * @name rotation
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.rotation = function(){return new Numeric();};

/**
  * @name scale
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.scale = function(){return new Numeric();};

/**
  * @name scene
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsScene}
  */
QGraphicsItem.prototype.scene = function(){return new QGraphicsScene();};

/**
  * @name sceneBoundingRect
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QRectF}
  */
QGraphicsItem.prototype.sceneBoundingRect = function(){return new QRectF();};

/**
  * @name scenePos
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QPointF}
  */
QGraphicsItem.prototype.scenePos = function(){return new QPointF();};

/**
  * @name sceneTransform
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QTransform}
  */
QGraphicsItem.prototype.sceneTransform = function(){return new QTransform();};

/**
  * @name scroll
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @param {QRectF} rect
  * @returns {undefined}
  */
QGraphicsItem.prototype.scroll = function(dx, dy, rect){return undefined;};

/**
  * @name setAcceptDrops
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} on
  * @returns {undefined}
  */
QGraphicsItem.prototype.setAcceptDrops = function(on){return undefined;};

/**
  * @name setAcceptHoverEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setAcceptHoverEvents = function(enabled){return undefined;};

/**
  * @name setAcceptTouchEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setAcceptTouchEvents = function(enabled){return undefined;};

/**
  * @name setAcceptedMouseButtons
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Qt.MouseButtons} buttons
  * @returns {undefined}
  */
QGraphicsItem.prototype.setAcceptedMouseButtons = function(buttons){return undefined;};

/**
  * @name setAcceptsHoverEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setAcceptsHoverEvents = function(enabled){return undefined;};

/**
  * @name setActive
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} active
  * @returns {undefined}
  */
QGraphicsItem.prototype.setActive = function(active){return undefined;};

/**
  * @name setBoundingRegionGranularity
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} granularity
  * @returns {undefined}
  */
QGraphicsItem.prototype.setBoundingRegionGranularity = function(granularity){return undefined;};

/**
  * @name setCacheMode
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsView.CacheMode} mode
  * @param {QSize} cacheSize
  * @returns {undefined}
  */
QGraphicsItem.prototype.setCacheMode = function(mode, cacheSize){return undefined;};

/**
  * @name setCursor
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QCursor} cursor
  * @returns {undefined}
  */
QGraphicsItem.prototype.setCursor = function(cursor){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} key
  * @param {Object} value
  * @returns {undefined}
  */
QGraphicsItem.prototype.setData = function(key, value){return undefined;};

/**
  * @name setEnabled
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setEnabled = function(enabled){return undefined;};

/**
  * @name setFiltersChildEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setFiltersChildEvents = function(enabled){return undefined;};

/**
  * @name setFlag
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem.GraphicsItemFlag} flag
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setFlag = function(flag, enabled){return undefined;};

/**
  * @name setFlags
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem.GraphicsItemFlags} flags
  * @returns {undefined}
  */
QGraphicsItem.prototype.setFlags = function(flags){return undefined;};

/**
  * @name setFocus
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Qt.FocusReason} focusReason
  * @returns {undefined}
  */
QGraphicsItem.prototype.setFocus = function(focusReason){return undefined;};

/**
  * @name setFocusProxy
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} item
  * @returns {undefined}
  */
QGraphicsItem.prototype.setFocusProxy = function(item){return undefined;};

/**
  * @name setGraphicsEffect
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsEffect} effect
  * @returns {undefined}
  */
QGraphicsItem.prototype.setGraphicsEffect = function(effect){return undefined;};

/**
  * @name setGroup
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItemGroup} group
  * @returns {undefined}
  */
QGraphicsItem.prototype.setGroup = function(group){return undefined;};

/**
  * @name setHandlesChildEvents
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsItem.prototype.setHandlesChildEvents = function(enabled){return undefined;};

/**
  * @name setInputMethodHints
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Qt.InputMethodHints} hints
  * @returns {undefined}
  */
QGraphicsItem.prototype.setInputMethodHints = function(hints){return undefined;};

/**
  * @name setOpacity
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} opacity
  * @returns {undefined}
  */
QGraphicsItem.prototype.setOpacity = function(opacity){return undefined;};

/**
  * @name setPanelModality
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem.PanelModality} panelModality
  * @returns {undefined}
  */
QGraphicsItem.prototype.setPanelModality = function(panelModality){return undefined;};

/**
  * @name setParentItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} parent
  * @returns {undefined}
  */
QGraphicsItem.prototype.setParentItem = function(parent){return undefined;};

/**
  * @name setPos
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QGraphicsItem.prototype.setPos = function(pos){return undefined;};

/**
  * @name setRotation
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QGraphicsItem.prototype.setRotation = function(angle){return undefined;};

/**
  * @name setScale
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} scale
  * @returns {undefined}
  */
QGraphicsItem.prototype.setScale = function(scale){return undefined;};

/**
  * @name setSelected
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} selected
  * @returns {undefined}
  */
QGraphicsItem.prototype.setSelected = function(selected){return undefined;};

/**
  * @name setToolTip
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {String} toolTip
  * @returns {undefined}
  */
QGraphicsItem.prototype.setToolTip = function(toolTip){return undefined;};

/**
  * @name setTransform
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QTransform} matrix
  * @param {Boolean} combine
  * @returns {undefined}
  */
QGraphicsItem.prototype.setTransform = function(matrix, combine){return undefined;};

/**
  * @name setTransformOriginPoint
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QPointF} origin
  * @returns {undefined}
  */
QGraphicsItem.prototype.setTransformOriginPoint = function(origin){return undefined;};

/**
  * @name setTransformations
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Array} transformations
  * @returns {undefined}
  */
QGraphicsItem.prototype.setTransformations = function(transformations){return undefined;};

/**
  * @name setVisible
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Boolean} visible
  * @returns {undefined}
  */
QGraphicsItem.prototype.setVisible = function(visible){return undefined;};

/**
  * @name setX
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} x
  * @returns {undefined}
  */
QGraphicsItem.prototype.setX = function(x){return undefined;};

/**
  * @name setY
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} y
  * @returns {undefined}
  */
QGraphicsItem.prototype.setY = function(y){return undefined;};

/**
  * @name setZValue
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} z
  * @returns {undefined}
  */
QGraphicsItem.prototype.setZValue = function(z){return undefined;};

/**
  * @name shape
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QPainterPath}
  */
QGraphicsItem.prototype.shape = function(){return new QPainterPath();};

/**
  * @name shear
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} sh
  * @param {Numeric} sv
  * @returns {undefined}
  */
QGraphicsItem.prototype.shear = function(sh, sv){return undefined;};

/**
  * @name show
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.show = function(){return undefined;};

/**
  * @name stackBefore
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QGraphicsItem} sibling
  * @returns {undefined}
  */
QGraphicsItem.prototype.stackBefore = function(sibling){return undefined;};

/**
  * @name toGraphicsObject
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsObject}
  */
QGraphicsItem.prototype.toGraphicsObject = function(){return new QGraphicsObject();};

/**
  * @name toolTip
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {String}
  */
QGraphicsItem.prototype.toolTip = function(){return new String();};

/**
  * @name topLevelItem
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsItem.prototype.topLevelItem = function(){return new QGraphicsItem();};

/**
  * @name topLevelWidget
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsWidget}
  */
QGraphicsItem.prototype.topLevelWidget = function(){return new QGraphicsWidget();};

/**
  * @name transform
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QTransform}
  */
QGraphicsItem.prototype.transform = function(){return new QTransform();};

/**
  * @name transformOriginPoint
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QPointF}
  */
QGraphicsItem.prototype.transformOriginPoint = function(){return new QPointF();};

/**
  * @name transformations
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Array}
  */
QGraphicsItem.prototype.transformations = function(){return new Array();};

/**
  * @name translate
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {undefined}
  */
QGraphicsItem.prototype.translate = function(dx, dy){return undefined;};

/**
  * @name type
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.type = function(){return new Numeric();};

/**
  * @name ungrabKeyboard
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.ungrabKeyboard = function(){return undefined;};

/**
  * @name ungrabMouse
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.ungrabMouse = function(){return undefined;};

/**
  * @name unsetCursor
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {undefined}
  */
QGraphicsItem.prototype.unsetCursor = function(){return undefined;};

/**
  * @name update
  * @function
  * @memberOf QGraphicsItem.prototype
  * @param {QRectF} rect
  * @returns {undefined}
  */
QGraphicsItem.prototype.update = function(rect){return undefined;};

/**
  * @name window
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {QGraphicsWidget}
  */
QGraphicsItem.prototype.window = function(){return new QGraphicsWidget();};

/**
  * @name x
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.y = function(){return new Numeric();};

/**
  * @name zValue
  * @function
  * @memberOf QGraphicsItem.prototype
  * @returns {Numeric}
  */
QGraphicsItem.prototype.zValue = function(){return new Numeric();};

