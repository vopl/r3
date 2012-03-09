/**
  * @name QWidget
  * @constructor
  * @extends QObject
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QWidget(parent, f){return undefined;};

QWidget.prototype = new QObject();

/**
  * @name keyboardGrabber
  * @function
  * @memberOf QWidget
  * @returns {QWidget}
  */
QWidget.keyboardGrabber = function(){return new QWidget();};

/**
  * @name mouseGrabber
  * @function
  * @memberOf QWidget
  * @returns {QWidget}
  */
QWidget.mouseGrabber = function(){return new QWidget();};

/**
  * @name setTabOrder
  * @function
  * @memberOf QWidget
  * @param {QWidget} arg__1
  * @param {QWidget} arg__2
  * @returns {undefined}
  */
QWidget.setTabOrder = function(arg__1, arg__2){return undefined;};

/**
  * @default 0x1
  * @constant
  * @memberOf QWidget
  * @name DrawWindowBackground
  * @see QWidget#RenderFlags
  * @see QWidget#RenderFlag
  * @type Number
  */
QWidget.DrawWindowBackground = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QWidget
  * @name DrawChildren
  * @see QWidget#RenderFlags
  * @see QWidget#RenderFlag
  * @type Number
  */
QWidget.DrawChildren = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QWidget
  * @name IgnoreMask
  * @see QWidget#RenderFlags
  * @see QWidget#RenderFlag
  * @type Number
  */
QWidget.IgnoreMask = 0x4;

/**
  * @constructor 
  * @memberOf QWidget
  * @name RenderFlag
  */
QWidget.RenderFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QWidget
  * @name RenderFlags
  */
QWidget.RenderFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name actions
  * @function
  * @memberOf QWidget.prototype
  * @returns {Array}
  */
QWidget.prototype.actions = function(){return new Array();};

/**
  * @name activateWindow
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.activateWindow = function(){return undefined;};

/**
  * @name addAction
  * @function
  * @memberOf QWidget.prototype
  * @param {QAction} action
  * @returns {undefined}
  */
QWidget.prototype.addAction = function(action){return undefined;};

/**
  * @name addActions
  * @function
  * @memberOf QWidget.prototype
  * @param {Array} actions
  * @returns {undefined}
  */
QWidget.prototype.addActions = function(actions){return undefined;};

/**
  * @name adjustSize
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.adjustSize = function(){return undefined;};

/**
  * @name backgroundRole
  * @function
  * @memberOf QWidget.prototype
  * @returns {QPalette.ColorRole}
  */
QWidget.prototype.backgroundRole = function(){return new QPalette.ColorRole();};

/**
  * @name childAt
  * @function
  * @memberOf QWidget.prototype
  * @param {QPoint} p
  * @returns {QWidget}
  */
QWidget.prototype.childAt = function(p){return new QWidget();};

/**
  * @name clearFocus
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.clearFocus = function(){return undefined;};

/**
  * @name clearMask
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.clearMask = function(){return undefined;};

/**
  * @name contentsMargins
  * @function
  * @memberOf QWidget.prototype
  * @returns {QMargins}
  */
QWidget.prototype.contentsMargins = function(){return new QMargins();};

/**
  * @name contentsRect
  * @function
  * @memberOf QWidget.prototype
  * @returns {QRect}
  */
QWidget.prototype.contentsRect = function(){return new QRect();};

/**
  * @name createWinId
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.createWinId = function(){return undefined;};

/**
  * @name effectiveWinId
  * @function
  * @memberOf QWidget.prototype
  * @returns {String}
  */
QWidget.prototype.effectiveWinId = function(){return new String();};

/**
  * @name ensurePolished
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.ensurePolished = function(){return undefined;};

/**
  * @name focusProxy
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.focusProxy = function(){return new QWidget();};

/**
  * @name focusWidget
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.focusWidget = function(){return new QWidget();};

/**
  * @name foregroundRole
  * @function
  * @memberOf QWidget.prototype
  * @returns {QPalette.ColorRole}
  */
QWidget.prototype.foregroundRole = function(){return new QPalette.ColorRole();};

/**
  * @name getContentsMargins
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @returns {undefined}
  */
QWidget.prototype.getContentsMargins = function(left, top, right, bottom){return undefined;};

/**
  * @name grabGesture
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.GestureType} type
  * @param {Qt.GestureFlags} flags
  * @returns {undefined}
  */
QWidget.prototype.grabGesture = function(type, flags){return undefined;};

/**
  * @name grabKeyboard
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.grabKeyboard = function(){return undefined;};

/**
  * @name grabMouse
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.grabMouse = function(){return undefined;};

/**
  * @name grabShortcut
  * @function
  * @memberOf QWidget.prototype
  * @param {QKeySequence} key
  * @param {Qt.ShortcutContext} context
  * @returns {Numeric}
  */
QWidget.prototype.grabShortcut = function(key, context){return new Numeric();};

/**
  * @name graphicsEffect
  * @function
  * @memberOf QWidget.prototype
  * @returns {QGraphicsEffect}
  */
QWidget.prototype.graphicsEffect = function(){return new QGraphicsEffect();};

/**
  * @name graphicsProxyWidget
  * @function
  * @memberOf QWidget.prototype
  * @returns {QGraphicsProxyWidget}
  */
QWidget.prototype.graphicsProxyWidget = function(){return new QGraphicsProxyWidget();};

/**
  * @name heightForWidth
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} arg__1
  * @returns {Numeric}
  */
QWidget.prototype.heightForWidth = function(arg__1){return new Numeric();};

/**
  * @name inputContext
  * @function
  * @memberOf QWidget.prototype
  * @returns {QInputContext}
  */
QWidget.prototype.inputContext = function(){return new QInputContext();};

/**
  * @name inputMethodQuery
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.InputMethodQuery} arg__1
  * @returns {Object}
  */
QWidget.prototype.inputMethodQuery = function(arg__1){return new Object();};

/**
  * @name insertAction
  * @function
  * @memberOf QWidget.prototype
  * @param {QAction} before
  * @param {QAction} action
  * @returns {undefined}
  */
QWidget.prototype.insertAction = function(before, action){return undefined;};

/**
  * @name insertActions
  * @function
  * @memberOf QWidget.prototype
  * @param {QAction} before
  * @param {Array} actions
  * @returns {undefined}
  */
QWidget.prototype.insertActions = function(before, actions){return undefined;};

/**
  * @name isAncestorOf
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} child
  * @returns {Boolean}
  */
QWidget.prototype.isAncestorOf = function(child){return new Boolean();};

/**
  * @name isEnabledTo
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} arg__1
  * @returns {Boolean}
  */
QWidget.prototype.isEnabledTo = function(arg__1){return new Boolean();};

/**
  * @name isHidden
  * @function
  * @memberOf QWidget.prototype
  * @returns {Boolean}
  */
QWidget.prototype.isHidden = function(){return new Boolean();};

/**
  * @name isLeftToRight
  * @function
  * @memberOf QWidget.prototype
  * @returns {Boolean}
  */
QWidget.prototype.isLeftToRight = function(){return new Boolean();};

/**
  * @name isRightToLeft
  * @function
  * @memberOf QWidget.prototype
  * @returns {Boolean}
  */
QWidget.prototype.isRightToLeft = function(){return new Boolean();};

/**
  * @name isVisibleTo
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} arg__1
  * @returns {Boolean}
  */
QWidget.prototype.isVisibleTo = function(arg__1){return new Boolean();};

/**
  * @name isWindow
  * @function
  * @memberOf QWidget.prototype
  * @returns {Boolean}
  */
QWidget.prototype.isWindow = function(){return new Boolean();};

/**
  * @name layout
  * @function
  * @memberOf QWidget.prototype
  * @returns {QLayout}
  */
QWidget.prototype.layout = function(){return new QLayout();};

/**
  * @name mapFrom
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} arg__1
  * @param {QPoint} arg__2
  * @returns {QPoint}
  */
QWidget.prototype.mapFrom = function(arg__1, arg__2){return new QPoint();};

/**
  * @name mapFromGlobal
  * @function
  * @memberOf QWidget.prototype
  * @param {QPoint} arg__1
  * @returns {QPoint}
  */
QWidget.prototype.mapFromGlobal = function(arg__1){return new QPoint();};

/**
  * @name mapFromParent
  * @function
  * @memberOf QWidget.prototype
  * @param {QPoint} arg__1
  * @returns {QPoint}
  */
QWidget.prototype.mapFromParent = function(arg__1){return new QPoint();};

/**
  * @name mapTo
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} arg__1
  * @param {QPoint} arg__2
  * @returns {QPoint}
  */
QWidget.prototype.mapTo = function(arg__1, arg__2){return new QPoint();};

/**
  * @name mapToGlobal
  * @function
  * @memberOf QWidget.prototype
  * @param {QPoint} arg__1
  * @returns {QPoint}
  */
QWidget.prototype.mapToGlobal = function(arg__1){return new QPoint();};

/**
  * @name mapToParent
  * @function
  * @memberOf QWidget.prototype
  * @param {QPoint} arg__1
  * @returns {QPoint}
  */
QWidget.prototype.mapToParent = function(arg__1){return new QPoint();};

/**
  * @name mask
  * @function
  * @memberOf QWidget.prototype
  * @returns {QRegion}
  */
QWidget.prototype.mask = function(){return new QRegion();};

/**
  * @name move
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @returns {undefined}
  */
QWidget.prototype.move = function(x, y){return undefined;};

/**
  * @name nativeParentWidget
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.nativeParentWidget = function(){return new QWidget();};

/**
  * @name nextInFocusChain
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.nextInFocusChain = function(){return new QWidget();};

/**
  * @name overrideWindowFlags
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.WindowFlags} type
  * @returns {undefined}
  */
QWidget.prototype.overrideWindowFlags = function(type){return undefined;};

/**
  * @name overrideWindowState
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.WindowStates} state
  * @returns {undefined}
  */
QWidget.prototype.overrideWindowState = function(state){return undefined;};

/**
  * @name parentWidget
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.parentWidget = function(){return new QWidget();};

/**
  * @name previousInFocusChain
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.previousInFocusChain = function(){return new QWidget();};

/**
  * @name releaseKeyboard
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.releaseKeyboard = function(){return undefined;};

/**
  * @name releaseMouse
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.releaseMouse = function(){return undefined;};

/**
  * @name releaseShortcut
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} id
  * @returns {undefined}
  */
QWidget.prototype.releaseShortcut = function(id){return undefined;};

/**
  * @name removeAction
  * @function
  * @memberOf QWidget.prototype
  * @param {QAction} action
  * @returns {undefined}
  */
QWidget.prototype.removeAction = function(action){return undefined;};

/**
  * @name render
  * @function
  * @memberOf QWidget.prototype
  * @param {QPaintDevice} target
  * @param {QPoint} targetOffset
  * @param {QRegion} sourceRegion
  * @param {QWidget.RenderFlags} renderFlags
  * @returns {undefined}
  */
QWidget.prototype.render = function(target, targetOffset, sourceRegion, renderFlags){return undefined;};

/**
  * @name repaint
  * @function
  * @memberOf QWidget.prototype
  * @param {QRect} arg__1
  * @returns {undefined}
  */
QWidget.prototype.repaint = function(arg__1){return undefined;};

/**
  * @name resize
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QWidget.prototype.resize = function(w, h){return undefined;};

/**
  * @name restoreGeometry
  * @function
  * @memberOf QWidget.prototype
  * @param {QByteArray} geometry
  * @returns {Boolean}
  */
QWidget.prototype.restoreGeometry = function(geometry){return new Boolean();};

/**
  * @name saveGeometry
  * @function
  * @memberOf QWidget.prototype
  * @returns {QByteArray}
  */
QWidget.prototype.saveGeometry = function(){return new QByteArray();};

/**
  * @name scroll
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} dx
  * @param {Numeric} dy
  * @returns {undefined}
  */
QWidget.prototype.scroll = function(dx, dy){return undefined;};

/**
  * @name setAttribute
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.WidgetAttribute} arg__1
  * @param {Boolean} on
  * @returns {undefined}
  */
QWidget.prototype.setAttribute = function(arg__1, on){return undefined;};

/**
  * @name setBackgroundRole
  * @function
  * @memberOf QWidget.prototype
  * @param {QPalette.ColorRole} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setBackgroundRole = function(arg__1){return undefined;};

/**
  * @name setBaseSize
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} basew
  * @param {Numeric} baseh
  * @returns {undefined}
  */
QWidget.prototype.setBaseSize = function(basew, baseh){return undefined;};

/**
  * @name setContentsMargins
  * @function
  * @memberOf QWidget.prototype
  * @param {QMargins} margins
  * @returns {undefined}
  */
QWidget.prototype.setContentsMargins = function(margins){return undefined;};

/**
  * @name setFixedHeight
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} h
  * @returns {undefined}
  */
QWidget.prototype.setFixedHeight = function(h){return undefined;};

/**
  * @name setFixedSize
  * @function
  * @memberOf QWidget.prototype
  * @param {QSize} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setFixedSize = function(arg__1){return undefined;};

/**
  * @name setFixedWidth
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} w
  * @returns {undefined}
  */
QWidget.prototype.setFixedWidth = function(w){return undefined;};

/**
  * @name setFocus
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.FocusReason} reason
  * @returns {undefined}
  */
QWidget.prototype.setFocus = function(reason){return undefined;};

/**
  * @name setFocusProxy
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setFocusProxy = function(arg__1){return undefined;};

/**
  * @name setForegroundRole
  * @function
  * @memberOf QWidget.prototype
  * @param {QPalette.ColorRole} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setForegroundRole = function(arg__1){return undefined;};

/**
  * @name setGeometry
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QWidget.prototype.setGeometry = function(x, y, w, h){return undefined;};

/**
  * @name setGraphicsEffect
  * @function
  * @memberOf QWidget.prototype
  * @param {QGraphicsEffect} effect
  * @returns {undefined}
  */
QWidget.prototype.setGraphicsEffect = function(effect){return undefined;};

/**
  * @name setInputContext
  * @function
  * @memberOf QWidget.prototype
  * @param {QInputContext} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setInputContext = function(arg__1){return undefined;};

/**
  * @name setLayout
  * @function
  * @memberOf QWidget.prototype
  * @param {QLayout} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setLayout = function(arg__1){return undefined;};

/**
  * @name setMask
  * @function
  * @memberOf QWidget.prototype
  * @param {QBitmap} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setMask = function(arg__1){return undefined;};

/**
  * @name setMaximumSize
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} maxw
  * @param {Numeric} maxh
  * @returns {undefined}
  */
QWidget.prototype.setMaximumSize = function(maxw, maxh){return undefined;};

/**
  * @name setMinimumSize
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} minw
  * @param {Numeric} minh
  * @returns {undefined}
  */
QWidget.prototype.setMinimumSize = function(minw, minh){return undefined;};

/**
  * @name setParent
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} parent
  * @returns {undefined}
  */
QWidget.prototype.setParent = function(parent){return undefined;};

/**
  * @name setShortcutAutoRepeat
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} id
  * @param {Boolean} enable
  * @returns {undefined}
  */
QWidget.prototype.setShortcutAutoRepeat = function(id, enable){return undefined;};

/**
  * @name setShortcutEnabled
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} id
  * @param {Boolean} enable
  * @returns {undefined}
  */
QWidget.prototype.setShortcutEnabled = function(id, enable){return undefined;};

/**
  * @name setSizeIncrement
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QWidget.prototype.setSizeIncrement = function(w, h){return undefined;};

/**
  * @name setSizePolicy
  * @function
  * @memberOf QWidget.prototype
  * @param {QSizePolicy.Policy} horizontal
  * @param {QSizePolicy.Policy} vertical
  * @returns {undefined}
  */
QWidget.prototype.setSizePolicy = function(horizontal, vertical){return undefined;};

/**
  * @name setStyle
  * @function
  * @memberOf QWidget.prototype
  * @param {QStyle} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setStyle = function(arg__1){return undefined;};

/**
  * @name setWindowFlags
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.WindowFlags} type
  * @returns {undefined}
  */
QWidget.prototype.setWindowFlags = function(type){return undefined;};

/**
  * @name setWindowOpacity
  * @function
  * @memberOf QWidget.prototype
  * @param {Numeric} level
  * @returns {undefined}
  */
QWidget.prototype.setWindowOpacity = function(level){return undefined;};

/**
  * @name setWindowRole
  * @function
  * @memberOf QWidget.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QWidget.prototype.setWindowRole = function(arg__1){return undefined;};

/**
  * @name setWindowState
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.WindowStates} state
  * @returns {undefined}
  */
QWidget.prototype.setWindowState = function(state){return undefined;};

/**
  * @name stackUnder
  * @function
  * @memberOf QWidget.prototype
  * @param {QWidget} arg__1
  * @returns {undefined}
  */
QWidget.prototype.stackUnder = function(arg__1){return undefined;};

/**
  * @name style
  * @function
  * @memberOf QWidget.prototype
  * @returns {QStyle}
  */
QWidget.prototype.style = function(){return new QStyle();};

/**
  * @name testAttribute
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.WidgetAttribute} arg__1
  * @returns {Boolean}
  */
QWidget.prototype.testAttribute = function(arg__1){return new Boolean();};

/**
  * @name underMouse
  * @function
  * @memberOf QWidget.prototype
  * @returns {Boolean}
  */
QWidget.prototype.underMouse = function(){return new Boolean();};

/**
  * @name ungrabGesture
  * @function
  * @memberOf QWidget.prototype
  * @param {Qt.GestureType} type
  * @returns {undefined}
  */
QWidget.prototype.ungrabGesture = function(type){return undefined;};

/**
  * @name unsetCursor
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.unsetCursor = function(){return undefined;};

/**
  * @name unsetLayoutDirection
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.unsetLayoutDirection = function(){return undefined;};

/**
  * @name unsetLocale
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.unsetLocale = function(){return undefined;};

/**
  * @name update
  * @function
  * @memberOf QWidget.prototype
  * @param {QRect} arg__1
  * @returns {undefined}
  */
QWidget.prototype.update = function(arg__1){return undefined;};

/**
  * @name updateGeometry
  * @function
  * @memberOf QWidget.prototype
  * @returns {undefined}
  */
QWidget.prototype.updateGeometry = function(){return undefined;};

/**
  * @name visibleRegion
  * @function
  * @memberOf QWidget.prototype
  * @returns {QRegion}
  */
QWidget.prototype.visibleRegion = function(){return new QRegion();};

/**
  * @name winId
  * @function
  * @memberOf QWidget.prototype
  * @returns {String}
  */
QWidget.prototype.winId = function(){return new String();};

/**
  * @name window
  * @function
  * @memberOf QWidget.prototype
  * @returns {QWidget}
  */
QWidget.prototype.window = function(){return new QWidget();};

/**
  * @name windowFlags
  * @function
  * @memberOf QWidget.prototype
  * @returns {Qt.WindowFlags}
  */
QWidget.prototype.windowFlags = function(){return new Qt.WindowFlags();};

/**
  * @name windowOpacity
  * @function
  * @memberOf QWidget.prototype
  * @returns {Numeric}
  */
QWidget.prototype.windowOpacity = function(){return new Numeric();};

/**
  * @name windowRole
  * @function
  * @memberOf QWidget.prototype
  * @returns {String}
  */
QWidget.prototype.windowRole = function(){return new String();};

/**
  * @name windowState
  * @function
  * @memberOf QWidget.prototype
  * @returns {Qt.WindowStates}
  */
QWidget.prototype.windowState = function(){return new Qt.WindowStates();};

/**
  * @name windowType
  * @function
  * @memberOf QWidget.prototype
  * @returns {Qt.WindowType}
  */
QWidget.prototype.windowType = function(){return new Qt.WindowType();};

/**
  * @name modal
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.modal = new Boolean();

/**
  * @name windowModality
  * @memberOf QWidget.prototype
  * @type Qt.WindowModality
  */
QWidget.prototype.windowModality = new Qt.WindowModality();

/**
  * @name enabled
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.enabled = new Boolean();

/**
  * @name geometry
  * @memberOf QWidget.prototype
  * @type QRect
  */
QWidget.prototype.geometry = new QRect();

/**
  * @name frameGeometry
  * @memberOf QWidget.prototype
  * @type QRect
  */
QWidget.prototype.frameGeometry = new QRect();

/**
  * @name normalGeometry
  * @memberOf QWidget.prototype
  * @type QRect
  */
QWidget.prototype.normalGeometry = new QRect();

/**
  * @name x
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.x = new Numeric();

/**
  * @name y
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.y = new Numeric();

/**
  * @name pos
  * @memberOf QWidget.prototype
  * @type QPoint
  */
QWidget.prototype.pos = new QPoint();

/**
  * @name frameSize
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.frameSize = new QSize();

/**
  * @name size
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.size = new QSize();

/**
  * @name width
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.width = new Numeric();

/**
  * @name height
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.height = new Numeric();

/**
  * @name rect
  * @memberOf QWidget.prototype
  * @type QRect
  */
QWidget.prototype.rect = new QRect();

/**
  * @name childrenRect
  * @memberOf QWidget.prototype
  * @type QRect
  */
QWidget.prototype.childrenRect = new QRect();

/**
  * @name childrenRegion
  * @memberOf QWidget.prototype
  * @type QRegion
  */
QWidget.prototype.childrenRegion = new QRegion();

/**
  * @name sizePolicy
  * @memberOf QWidget.prototype
  * @type QSizePolicy
  */
QWidget.prototype.sizePolicy = new QSizePolicy();

/**
  * @name minimumSize
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.minimumSize = new QSize();

/**
  * @name maximumSize
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.maximumSize = new QSize();

/**
  * @name minimumWidth
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.minimumWidth = new Numeric();

/**
  * @name minimumHeight
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.minimumHeight = new Numeric();

/**
  * @name maximumWidth
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.maximumWidth = new Numeric();

/**
  * @name maximumHeight
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.maximumHeight = new Numeric();

/**
  * @name sizeIncrement
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.sizeIncrement = new QSize();

/**
  * @name baseSize
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.baseSize = new QSize();

/**
  * @name palette
  * @memberOf QWidget.prototype
  * @type QPalette
  */
QWidget.prototype.palette = new QPalette();

/**
  * @name font
  * @memberOf QWidget.prototype
  * @type QFont
  */
QWidget.prototype.font = new QFont();

/**
  * @name cursor
  * @memberOf QWidget.prototype
  * @type QCursor
  */
QWidget.prototype.cursor = new QCursor();

/**
  * @name mouseTracking
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.mouseTracking = new Boolean();

/**
  * @name isActiveWindow
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.isActiveWindow = new Boolean();

/**
  * @name focusPolicy
  * @memberOf QWidget.prototype
  * @type Qt.FocusPolicy
  */
QWidget.prototype.focusPolicy = new Qt.FocusPolicy();

/**
  * @name focus
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.focus = new Boolean();

/**
  * @name contextMenuPolicy
  * @memberOf QWidget.prototype
  * @type Qt.ContextMenuPolicy
  */
QWidget.prototype.contextMenuPolicy = new Qt.ContextMenuPolicy();

/**
  * @name updatesEnabled
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.updatesEnabled = new Boolean();

/**
  * @name visible
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.visible = new Boolean();

/**
  * @name minimized
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.minimized = new Boolean();

/**
  * @name maximized
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.maximized = new Boolean();

/**
  * @name fullScreen
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.fullScreen = new Boolean();

/**
  * @name sizeHint
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.sizeHint = new QSize();

/**
  * @name minimumSizeHint
  * @memberOf QWidget.prototype
  * @type QSize
  */
QWidget.prototype.minimumSizeHint = new QSize();

/**
  * @name acceptDrops
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.acceptDrops = new Boolean();

/**
  * @name windowTitle
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.windowTitle = new String();

/**
  * @name windowIcon
  * @memberOf QWidget.prototype
  * @type QIcon
  */
QWidget.prototype.windowIcon = new QIcon();

/**
  * @name windowIconText
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.windowIconText = new String();

/**
  * @name windowOpacity
  * @memberOf QWidget.prototype
  * @type Numeric
  */
QWidget.prototype.windowOpacity = new Numeric();

/**
  * @name windowModified
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.windowModified = new Boolean();

/**
  * @name toolTip
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.toolTip = new String();

/**
  * @name statusTip
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.statusTip = new String();

/**
  * @name whatsThis
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.whatsThis = new String();

/**
  * @name accessibleName
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.accessibleName = new String();

/**
  * @name accessibleDescription
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.accessibleDescription = new String();

/**
  * @name layoutDirection
  * @memberOf QWidget.prototype
  * @type QTextFormat.LayoutDirection
  */
QWidget.prototype.layoutDirection = new QTextFormat.LayoutDirection();

/**
  * @name autoFillBackground
  * @memberOf QWidget.prototype
  * @type Boolean
  */
QWidget.prototype.autoFillBackground = new Boolean();

/**
  * @name styleSheet
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.styleSheet = new String();

/**
  * @name locale
  * @memberOf QWidget.prototype
  * @type QLocale
  */
QWidget.prototype.locale = new QLocale();

/**
  * @name windowFilePath
  * @memberOf QWidget.prototype
  * @type String
  */
QWidget.prototype.windowFilePath = new String();

/**
  * @name inputMethodHints
  * @memberOf QWidget.prototype
  * @type Qt.InputMethodHints
  */
QWidget.prototype.inputMethodHints = new Qt.InputMethodHints();


