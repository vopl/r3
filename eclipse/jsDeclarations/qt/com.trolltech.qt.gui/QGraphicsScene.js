/**
  * @name QGraphicsScene
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QGraphicsScene(parent){return undefined;};

/**
  * @name QGraphicsScene^1
  * @constructor
  * @extends QObject
  * @param {QRectF} sceneRect
  * @param {QObject} parent
  */
function QGraphicsScene(sceneRect, parent){return undefined;};

/**
  * @name QGraphicsScene^2
  * @constructor
  * @extends QObject
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} width
  * @param {Numeric} height
  * @param {QObject} parent
  */
function QGraphicsScene(x, y, width, height, parent){return undefined;};

QGraphicsScene.prototype = new QObject();

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsScene
  * @name ItemLayer
  * @see QGraphicsScene#SceneLayers
  * @see QGraphicsScene#SceneLayer
  * @type Number
  */
QGraphicsScene.ItemLayer = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsScene
  * @name BackgroundLayer
  * @see QGraphicsScene#SceneLayers
  * @see QGraphicsScene#SceneLayer
  * @type Number
  */
QGraphicsScene.BackgroundLayer = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QGraphicsScene
  * @name ForegroundLayer
  * @see QGraphicsScene#SceneLayers
  * @see QGraphicsScene#SceneLayer
  * @type Number
  */
QGraphicsScene.ForegroundLayer = 0x4;

/**
  * @default 0xffff
  * @constant
  * @memberOf QGraphicsScene
  * @name AllLayers
  * @see QGraphicsScene#SceneLayers
  * @see QGraphicsScene#SceneLayer
  * @type Number
  */
QGraphicsScene.AllLayers = 0xffff;

/**
  * @constructor 
  * @memberOf QGraphicsScene
  * @name SceneLayer
  */
QGraphicsScene.SceneLayer = function(value){;};

/**
  * @constructor 
  * @memberOf QGraphicsScene
  * @name SceneLayers
  */
QGraphicsScene.SceneLayers = function(value1, value2 /*, ...*/){;};


/**
  * @default -1
  * @constant
  * @memberOf QGraphicsScene
  * @name NoIndex
  * @see QGraphicsScene#ItemIndexMethod
  * @type Number
  */
QGraphicsScene.NoIndex = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsScene
  * @name BspTreeIndex
  * @see QGraphicsScene#ItemIndexMethod
  * @type Number
  */
QGraphicsScene.BspTreeIndex = 0x0;

/**
  * @constructor 
  * @memberOf QGraphicsScene
  * @name ItemIndexMethod
  */
QGraphicsScene.ItemIndexMethod = function(value){;};



/**
  * @name activePanel
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsScene.prototype.activePanel = function(){return new QGraphicsItem();};

/**
  * @name activeWindow
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QGraphicsWidget}
  */
QGraphicsScene.prototype.activeWindow = function(){return new QGraphicsWidget();};

/**
  * @name addEllipse
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QRectF} rect
  * @param {QPen} pen
  * @param {QBrush} brush
  * @returns {QGraphicsEllipseItem}
  */
QGraphicsScene.prototype.addEllipse = function(rect, pen, brush){return new QGraphicsEllipseItem();};

/**
  * @name addItem
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItem} item
  * @returns {undefined}
  */
QGraphicsScene.prototype.addItem = function(item){return undefined;};

/**
  * @name addLine
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QLineF} line
  * @param {QPen} pen
  * @returns {QGraphicsLineItem}
  */
QGraphicsScene.prototype.addLine = function(line, pen){return new QGraphicsLineItem();};

/**
  * @name addPath
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QPainterPath} path
  * @param {QPen} pen
  * @param {QBrush} brush
  * @returns {QGraphicsPathItem}
  */
QGraphicsScene.prototype.addPath = function(path, pen, brush){return new QGraphicsPathItem();};

/**
  * @name addPixmap
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QPixmap} pixmap
  * @returns {QGraphicsPixmapItem}
  */
QGraphicsScene.prototype.addPixmap = function(pixmap){return new QGraphicsPixmapItem();};

/**
  * @name addPolygon
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QPolygonF} polygon
  * @param {QPen} pen
  * @param {QBrush} brush
  * @returns {QGraphicsPolygonItem}
  */
QGraphicsScene.prototype.addPolygon = function(polygon, pen, brush){return new QGraphicsPolygonItem();};

/**
  * @name addRect
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QRectF} rect
  * @param {QPen} pen
  * @param {QBrush} brush
  * @returns {QGraphicsRectItem}
  */
QGraphicsScene.prototype.addRect = function(rect, pen, brush){return new QGraphicsRectItem();};

/**
  * @name addSimpleText
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {String} text
  * @param {QFont} font
  * @returns {QGraphicsSimpleTextItem}
  */
QGraphicsScene.prototype.addSimpleText = function(text, font){return new QGraphicsSimpleTextItem();};

/**
  * @name addText
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {String} text
  * @param {QFont} font
  * @returns {QGraphicsTextItem}
  */
QGraphicsScene.prototype.addText = function(text, font){return new QGraphicsTextItem();};

/**
  * @name addWidget
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QWidget} widget
  * @param {Qt.WindowFlags} wFlags
  * @returns {QGraphicsProxyWidget}
  */
QGraphicsScene.prototype.addWidget = function(widget, wFlags){return new QGraphicsProxyWidget();};

/**
  * @name clearFocus
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {undefined}
  */
QGraphicsScene.prototype.clearFocus = function(){return undefined;};

/**
  * @name collidingItems
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItem} item
  * @param {Qt.ItemSelectionMode} mode
  * @returns {Array}
  */
QGraphicsScene.prototype.collidingItems = function(item, mode){return new Array();};

/**
  * @name createItemGroup
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {Array} items
  * @returns {QGraphicsItemGroup}
  */
QGraphicsScene.prototype.createItemGroup = function(items){return new QGraphicsItemGroup();};

/**
  * @name destroyItemGroup
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItemGroup} group
  * @returns {undefined}
  */
QGraphicsScene.prototype.destroyItemGroup = function(group){return undefined;};

/**
  * @name focusItem
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsScene.prototype.focusItem = function(){return new QGraphicsItem();};

/**
  * @name hasFocus
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Boolean}
  */
QGraphicsScene.prototype.hasFocus = function(){return new Boolean();};

/**
  * @name height
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Numeric}
  */
QGraphicsScene.prototype.height = function(){return new Numeric();};

/**
  * @name inputMethodQuery
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {Qt.InputMethodQuery} query
  * @returns {Object}
  */
QGraphicsScene.prototype.inputMethodQuery = function(query){return new Object();};

/**
  * @name invalidate
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @param {QGraphicsScene.SceneLayers} layers
  * @returns {undefined}
  */
QGraphicsScene.prototype.invalidate = function(x, y, w, h, layers){return undefined;};

/**
  * @name isActive
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Boolean}
  */
QGraphicsScene.prototype.isActive = function(){return new Boolean();};

/**
  * @name itemAt
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QPointF} pos
  * @returns {QGraphicsItem}
  */
QGraphicsScene.prototype.itemAt = function(pos){return new QGraphicsItem();};

/**
  * @name items
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Array}
  */
QGraphicsScene.prototype.items = function(){return new Array();};

/**
  * @name itemsBoundingRect
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QRectF}
  */
QGraphicsScene.prototype.itemsBoundingRect = function(){return new QRectF();};

/**
  * @name mouseGrabberItem
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QGraphicsItem}
  */
QGraphicsScene.prototype.mouseGrabberItem = function(){return new QGraphicsItem();};

/**
  * @name removeItem
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItem} item
  * @returns {undefined}
  */
QGraphicsScene.prototype.removeItem = function(item){return undefined;};

/**
  * @name render
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QPainter} painter
  * @param {QRectF} target
  * @param {QRectF} source
  * @param {Qt.AspectRatioMode} aspectRatioMode
  * @returns {undefined}
  */
QGraphicsScene.prototype.render = function(painter, target, source, aspectRatioMode){return undefined;};

/**
  * @name selectedItems
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Array}
  */
QGraphicsScene.prototype.selectedItems = function(){return new Array();};

/**
  * @name selectionArea
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QPainterPath}
  */
QGraphicsScene.prototype.selectionArea = function(){return new QPainterPath();};

/**
  * @name sendEvent
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItem} item
  * @param {QEvent} event
  * @returns {Boolean}
  */
QGraphicsScene.prototype.sendEvent = function(item, event){return new Boolean();};

/**
  * @name setActivePanel
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItem} item
  * @returns {undefined}
  */
QGraphicsScene.prototype.setActivePanel = function(item){return undefined;};

/**
  * @name setActiveWindow
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsWidget} widget
  * @returns {undefined}
  */
QGraphicsScene.prototype.setActiveWindow = function(widget){return undefined;};

/**
  * @name setFocus
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {Qt.FocusReason} focusReason
  * @returns {undefined}
  */
QGraphicsScene.prototype.setFocus = function(focusReason){return undefined;};

/**
  * @name setFocusItem
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QGraphicsItem} item
  * @param {Qt.FocusReason} focusReason
  * @returns {undefined}
  */
QGraphicsScene.prototype.setFocusItem = function(item, focusReason){return undefined;};

/**
  * @name setSceneRect
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QGraphicsScene.prototype.setSceneRect = function(x, y, w, h){return undefined;};

/**
  * @name setSelectionArea
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QGraphicsScene.prototype.setSelectionArea = function(path){return undefined;};

/**
  * @name setStyle
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {QStyle} style
  * @returns {undefined}
  */
QGraphicsScene.prototype.setStyle = function(style){return undefined;};

/**
  * @name style
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {QStyle}
  */
QGraphicsScene.prototype.style = function(){return new QStyle();};

/**
  * @name update
  * @function
  * @memberOf QGraphicsScene.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QGraphicsScene.prototype.update = function(x, y, w, h){return undefined;};

/**
  * @name views
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Array}
  */
QGraphicsScene.prototype.views = function(){return new Array();};

/**
  * @name width
  * @function
  * @memberOf QGraphicsScene.prototype
  * @returns {Numeric}
  */
QGraphicsScene.prototype.width = function(){return new Numeric();};

/**
  * @name backgroundBrush
  * @memberOf QGraphicsScene.prototype
  * @type QBrush
  */
QGraphicsScene.prototype.backgroundBrush = new QBrush();

/**
  * @name foregroundBrush
  * @memberOf QGraphicsScene.prototype
  * @type QBrush
  */
QGraphicsScene.prototype.foregroundBrush = new QBrush();

/**
  * @name itemIndexMethod
  * @memberOf QGraphicsScene.prototype
  * @type QGraphicsScene.ItemIndexMethod
  */
QGraphicsScene.prototype.itemIndexMethod = new QGraphicsScene.ItemIndexMethod();

/**
  * @name sceneRect
  * @memberOf QGraphicsScene.prototype
  * @type QRectF
  */
QGraphicsScene.prototype.sceneRect = new QRectF();

/**
  * @name bspTreeDepth
  * @memberOf QGraphicsScene.prototype
  * @type Numeric
  */
QGraphicsScene.prototype.bspTreeDepth = new Numeric();

/**
  * @name palette
  * @memberOf QGraphicsScene.prototype
  * @type QPalette
  */
QGraphicsScene.prototype.palette = new QPalette();

/**
  * @name font
  * @memberOf QGraphicsScene.prototype
  * @type QFont
  */
QGraphicsScene.prototype.font = new QFont();

/**
  * @name sortCacheEnabled
  * @memberOf QGraphicsScene.prototype
  * @type Boolean
  */
QGraphicsScene.prototype.sortCacheEnabled = new Boolean();

/**
  * @name stickyFocus
  * @memberOf QGraphicsScene.prototype
  * @type Boolean
  */
QGraphicsScene.prototype.stickyFocus = new Boolean();


