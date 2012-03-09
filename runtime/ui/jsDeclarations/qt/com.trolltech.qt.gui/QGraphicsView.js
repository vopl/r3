/**
  * @name QGraphicsView
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QGraphicsScene} scene
  * @param {QWidget} parent
  */
function QGraphicsView(scene, parent){return undefined;};

/**
  * @name QGraphicsView^1
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QWidget} parent
  */
function QGraphicsView(parent){return undefined;};

QGraphicsView.prototype = new QAbstractScrollArea();

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsView
  * @name DontClipPainter
  * @see QGraphicsView#OptimizationFlags
  * @see QGraphicsView#OptimizationFlag
  * @type Number
  */
QGraphicsView.DontClipPainter = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsView
  * @name DontSavePainterState
  * @see QGraphicsView#OptimizationFlags
  * @see QGraphicsView#OptimizationFlag
  * @type Number
  */
QGraphicsView.DontSavePainterState = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QGraphicsView
  * @name DontAdjustForAntialiasing
  * @see QGraphicsView#OptimizationFlags
  * @see QGraphicsView#OptimizationFlag
  * @type Number
  */
QGraphicsView.DontAdjustForAntialiasing = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QGraphicsView
  * @name IndirectPainting
  * @see QGraphicsView#OptimizationFlags
  * @see QGraphicsView#OptimizationFlag
  * @type Number
  */
QGraphicsView.IndirectPainting = 0x8;

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name OptimizationFlag
  */
QGraphicsView.OptimizationFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name OptimizationFlags
  */
QGraphicsView.OptimizationFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsView
  * @name NoAnchor
  * @see QGraphicsView#ViewportAnchor
  * @type Number
  */
QGraphicsView.NoAnchor = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsView
  * @name AnchorViewCenter
  * @see QGraphicsView#ViewportAnchor
  * @type Number
  */
QGraphicsView.AnchorViewCenter = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsView
  * @name AnchorUnderMouse
  * @see QGraphicsView#ViewportAnchor
  * @type Number
  */
QGraphicsView.AnchorUnderMouse = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name ViewportAnchor
  */
QGraphicsView.ViewportAnchor = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsView
  * @name FullViewportUpdate
  * @see QGraphicsView#ViewportUpdateMode
  * @type Number
  */
QGraphicsView.FullViewportUpdate = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsView
  * @name MinimalViewportUpdate
  * @see QGraphicsView#ViewportUpdateMode
  * @type Number
  */
QGraphicsView.MinimalViewportUpdate = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsView
  * @name SmartViewportUpdate
  * @see QGraphicsView#ViewportUpdateMode
  * @type Number
  */
QGraphicsView.SmartViewportUpdate = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QGraphicsView
  * @name NoViewportUpdate
  * @see QGraphicsView#ViewportUpdateMode
  * @type Number
  */
QGraphicsView.NoViewportUpdate = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QGraphicsView
  * @name BoundingRectViewportUpdate
  * @see QGraphicsView#ViewportUpdateMode
  * @type Number
  */
QGraphicsView.BoundingRectViewportUpdate = 0x4;

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name ViewportUpdateMode
  */
QGraphicsView.ViewportUpdateMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsView
  * @name CacheNone
  * @see QGraphicsView#CacheMode
  * @see QGraphicsView#CacheModeFlag
  * @type Number
  */
QGraphicsView.CacheNone = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsView
  * @name CacheBackground
  * @see QGraphicsView#CacheMode
  * @see QGraphicsView#CacheModeFlag
  * @type Number
  */
QGraphicsView.CacheBackground = 0x1;

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name CacheModeFlag
  */
QGraphicsView.CacheModeFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name CacheMode
  */
QGraphicsView.CacheMode = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsView
  * @name NoDrag
  * @see QGraphicsView#DragMode
  * @type Number
  */
QGraphicsView.NoDrag = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsView
  * @name ScrollHandDrag
  * @see QGraphicsView#DragMode
  * @type Number
  */
QGraphicsView.ScrollHandDrag = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsView
  * @name RubberBandDrag
  * @see QGraphicsView#DragMode
  * @type Number
  */
QGraphicsView.RubberBandDrag = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsView
  * @name DragMode
  */
QGraphicsView.DragMode = function(value){;};



/**
  * @name centerOn
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QGraphicsItem} item
  * @returns {undefined}
  */
QGraphicsView.prototype.centerOn = function(item){return undefined;};

/**
  * @name ensureVisible
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QGraphicsItem} item
  * @param {Numeric} xmargin
  * @param {Numeric} ymargin
  * @returns {undefined}
  */
QGraphicsView.prototype.ensureVisible = function(item, xmargin, ymargin){return undefined;};

/**
  * @name fitInView
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QGraphicsItem} item
  * @param {Qt.AspectRatioMode} aspectRadioMode
  * @returns {undefined}
  */
QGraphicsView.prototype.fitInView = function(item, aspectRadioMode){return undefined;};

/**
  * @name isTransformed
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {Boolean}
  */
QGraphicsView.prototype.isTransformed = function(){return new Boolean();};

/**
  * @name itemAt
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QPoint} pos
  * @returns {QGraphicsItem}
  */
QGraphicsView.prototype.itemAt = function(pos){return new QGraphicsItem();};

/**
  * @name items
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {Array}
  */
QGraphicsView.prototype.items = function(){return new Array();};

/**
  * @name mapFromScene
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsView.prototype.mapFromScene = function(path){return new QPainterPath();};

/**
  * @name mapToScene
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QPainterPath} path
  * @returns {QPainterPath}
  */
QGraphicsView.prototype.mapToScene = function(path){return new QPainterPath();};

/**
  * @name matrix
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {QMatrix}
  */
QGraphicsView.prototype.matrix = function(){return new QMatrix();};

/**
  * @name render
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QPainter} painter
  * @param {QRectF} target
  * @param {QRect} source
  * @param {Qt.AspectRatioMode} aspectRatioMode
  * @returns {undefined}
  */
QGraphicsView.prototype.render = function(painter, target, source, aspectRatioMode){return undefined;};

/**
  * @name resetCachedContent
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {undefined}
  */
QGraphicsView.prototype.resetCachedContent = function(){return undefined;};

/**
  * @name resetMatrix
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {undefined}
  */
QGraphicsView.prototype.resetMatrix = function(){return undefined;};

/**
  * @name resetTransform
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {undefined}
  */
QGraphicsView.prototype.resetTransform = function(){return undefined;};

/**
  * @name rotate
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {Numeric} angle
  * @returns {undefined}
  */
QGraphicsView.prototype.rotate = function(angle){return undefined;};

/**
  * @name scale
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {Numeric} sx
  * @param {Numeric} sy
  * @returns {undefined}
  */
QGraphicsView.prototype.scale = function(sx, sy){return undefined;};

/**
  * @name scene
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {QGraphicsScene}
  */
QGraphicsView.prototype.scene = function(){return new QGraphicsScene();};

/**
  * @name setMatrix
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QMatrix} matrix
  * @param {Boolean} combine
  * @returns {undefined}
  */
QGraphicsView.prototype.setMatrix = function(matrix, combine){return undefined;};

/**
  * @name setOptimizationFlag
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QGraphicsView.OptimizationFlag} flag
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsView.prototype.setOptimizationFlag = function(flag, enabled){return undefined;};

/**
  * @name setRenderHint
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QPainter.RenderHint} hint
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsView.prototype.setRenderHint = function(hint, enabled){return undefined;};

/**
  * @name setScene
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QGraphicsScene} scene
  * @returns {undefined}
  */
QGraphicsView.prototype.setScene = function(scene){return undefined;};

/**
  * @name setSceneRect
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QGraphicsView.prototype.setSceneRect = function(x, y, w, h){return undefined;};

/**
  * @name setTransform
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {QTransform} matrix
  * @param {Boolean} combine
  * @returns {undefined}
  */
QGraphicsView.prototype.setTransform = function(matrix, combine){return undefined;};

/**
  * @name shear
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {Numeric} sh
  * @param {Numeric} sv
  * @returns {undefined}
  */
QGraphicsView.prototype.shear = function(sh, sv){return undefined;};

/**
  * @name transform
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {QTransform}
  */
QGraphicsView.prototype.transform = function(){return new QTransform();};

/**
  * @name translate
  * @function
  * @memberOf QGraphicsView.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {undefined}
  */
QGraphicsView.prototype.translate = function(dx, dy){return undefined;};

/**
  * @name viewportTransform
  * @function
  * @memberOf QGraphicsView.prototype
  * @returns {QTransform}
  */
QGraphicsView.prototype.viewportTransform = function(){return new QTransform();};

/**
  * @name backgroundBrush
  * @memberOf QGraphicsView.prototype
  * @type QBrush
  */
QGraphicsView.prototype.backgroundBrush = new QBrush();

/**
  * @name foregroundBrush
  * @memberOf QGraphicsView.prototype
  * @type QBrush
  */
QGraphicsView.prototype.foregroundBrush = new QBrush();

/**
  * @name interactive
  * @memberOf QGraphicsView.prototype
  * @type Boolean
  */
QGraphicsView.prototype.interactive = new Boolean();

/**
  * @name sceneRect
  * @memberOf QGraphicsView.prototype
  * @type QRectF
  */
QGraphicsView.prototype.sceneRect = new QRectF();

/**
  * @name alignment
  * @memberOf QGraphicsView.prototype
  * @type Qt.Alignment
  */
QGraphicsView.prototype.alignment = new Qt.Alignment();

/**
  * @name renderHints
  * @memberOf QGraphicsView.prototype
  * @type QPainter.RenderHints
  */
QGraphicsView.prototype.renderHints = new QPainter.RenderHints();

/**
  * @name dragMode
  * @memberOf QGraphicsView.prototype
  * @type QGraphicsView.DragMode
  */
QGraphicsView.prototype.dragMode = new QGraphicsView.DragMode();

/**
  * @name cacheMode
  * @memberOf QGraphicsView.prototype
  * @type QGraphicsView.CacheMode
  */
QGraphicsView.prototype.cacheMode = new QGraphicsView.CacheMode();

/**
  * @name transformationAnchor
  * @memberOf QGraphicsView.prototype
  * @type QGraphicsView.ViewportAnchor
  */
QGraphicsView.prototype.transformationAnchor = new QGraphicsView.ViewportAnchor();

/**
  * @name resizeAnchor
  * @memberOf QGraphicsView.prototype
  * @type QGraphicsView.ViewportAnchor
  */
QGraphicsView.prototype.resizeAnchor = new QGraphicsView.ViewportAnchor();

/**
  * @name viewportUpdateMode
  * @memberOf QGraphicsView.prototype
  * @type QGraphicsView.ViewportUpdateMode
  */
QGraphicsView.prototype.viewportUpdateMode = new QGraphicsView.ViewportUpdateMode();

/**
  * @name rubberBandSelectionMode
  * @memberOf QGraphicsView.prototype
  * @type Qt.ItemSelectionMode
  */
QGraphicsView.prototype.rubberBandSelectionMode = new Qt.ItemSelectionMode();

/**
  * @name optimizationFlags
  * @memberOf QGraphicsView.prototype
  * @type QGraphicsView.OptimizationFlags
  */
QGraphicsView.prototype.optimizationFlags = new QGraphicsView.OptimizationFlags();


