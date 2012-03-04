/**
  * @name QGraphicsWidget
  * @constructor
  * @extends QGraphicsObject
  * @param {QGraphicsItem} parent
  * @param {Qt.WindowFlags} wFlags
  */
function QGraphicsWidget(parent, wFlags){return undefined;};

QGraphicsWidget.prototype = new QGraphicsObject();

/**
  * @name setTabOrder
  * @function
  * @memberOf QGraphicsWidget
  * @param {QGraphicsWidget} first
  * @param {QGraphicsWidget} second
  * @returns {undefined}
  */
QGraphicsWidget.setTabOrder = function(first, second){return undefined;};

/**
  * @name actions
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {Array}
  */
QGraphicsWidget.prototype.actions = function(){return new Array();};

/**
  * @name addAction
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QAction} action
  * @returns {undefined}
  */
QGraphicsWidget.prototype.addAction = function(action){return undefined;};

/**
  * @name addActions
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Array} actions
  * @returns {undefined}
  */
QGraphicsWidget.prototype.addActions = function(actions){return undefined;};

/**
  * @name adjustSize
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {undefined}
  */
QGraphicsWidget.prototype.adjustSize = function(){return undefined;};

/**
  * @name focusWidget
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {QGraphicsWidget}
  */
QGraphicsWidget.prototype.focusWidget = function(){return new QGraphicsWidget();};

/**
  * @name getWindowFrameMargins
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @returns {undefined}
  */
QGraphicsWidget.prototype.getWindowFrameMargins = function(left, top, right, bottom){return undefined;};

/**
  * @name grabShortcut
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QKeySequence} sequence
  * @param {Qt.ShortcutContext} context
  * @returns {Numeric}
  */
QGraphicsWidget.prototype.grabShortcut = function(sequence, context){return new Numeric();};

/**
  * @name insertAction
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QAction} before
  * @param {QAction} action
  * @returns {undefined}
  */
QGraphicsWidget.prototype.insertAction = function(before, action){return undefined;};

/**
  * @name insertActions
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QAction} before
  * @param {Array} actions
  * @returns {undefined}
  */
QGraphicsWidget.prototype.insertActions = function(before, actions){return undefined;};

/**
  * @name isActiveWindow
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {Boolean}
  */
QGraphicsWidget.prototype.isActiveWindow = function(){return new Boolean();};

/**
  * @name paintWindowFrame
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QPainter} painter
  * @param {QStyleOptionGraphicsItem} option
  * @param {QWidget} widget
  * @returns {undefined}
  */
QGraphicsWidget.prototype.paintWindowFrame = function(painter, option, widget){return undefined;};

/**
  * @name rect
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {QRectF}
  */
QGraphicsWidget.prototype.rect = function(){return new QRectF();};

/**
  * @name releaseShortcut
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} id
  * @returns {undefined}
  */
QGraphicsWidget.prototype.releaseShortcut = function(id){return undefined;};

/**
  * @name removeAction
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QAction} action
  * @returns {undefined}
  */
QGraphicsWidget.prototype.removeAction = function(action){return undefined;};

/**
  * @name resize
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QGraphicsWidget.prototype.resize = function(w, h){return undefined;};

/**
  * @name setAttribute
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Qt.WidgetAttribute} attribute
  * @param {Boolean} on
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setAttribute = function(attribute, on){return undefined;};

/**
  * @name setContentsMargins
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setContentsMargins = function(left, top, right, bottom){return undefined;};

/**
  * @name setGeometry
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} w
  * @param {Numeric} h
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setGeometry = function(x, y, w, h){return undefined;};

/**
  * @name setShortcutAutoRepeat
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} id
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setShortcutAutoRepeat = function(id, enabled){return undefined;};

/**
  * @name setShortcutEnabled
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} id
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setShortcutEnabled = function(id, enabled){return undefined;};

/**
  * @name setStyle
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {QStyle} style
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setStyle = function(style){return undefined;};

/**
  * @name setWindowFrameMargins
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Numeric} left
  * @param {Numeric} top
  * @param {Numeric} right
  * @param {Numeric} bottom
  * @returns {undefined}
  */
QGraphicsWidget.prototype.setWindowFrameMargins = function(left, top, right, bottom){return undefined;};

/**
  * @name style
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {QStyle}
  */
QGraphicsWidget.prototype.style = function(){return new QStyle();};

/**
  * @name testAttribute
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @param {Qt.WidgetAttribute} attribute
  * @returns {Boolean}
  */
QGraphicsWidget.prototype.testAttribute = function(attribute){return new Boolean();};

/**
  * @name unsetLayoutDirection
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {undefined}
  */
QGraphicsWidget.prototype.unsetLayoutDirection = function(){return undefined;};

/**
  * @name unsetWindowFrameMargins
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {undefined}
  */
QGraphicsWidget.prototype.unsetWindowFrameMargins = function(){return undefined;};

/**
  * @name windowFrameGeometry
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {QRectF}
  */
QGraphicsWidget.prototype.windowFrameGeometry = function(){return new QRectF();};

/**
  * @name windowFrameRect
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {QRectF}
  */
QGraphicsWidget.prototype.windowFrameRect = function(){return new QRectF();};

/**
  * @name windowType
  * @function
  * @memberOf QGraphicsWidget.prototype
  * @returns {Qt.WindowType}
  */
QGraphicsWidget.prototype.windowType = function(){return new Qt.WindowType();};

/**
  * @name palette
  * @memberOf QGraphicsWidget.prototype
  * @type QPalette
  */
QGraphicsWidget.prototype.palette = new QPalette();

/**
  * @name font
  * @memberOf QGraphicsWidget.prototype
  * @type QFont
  */
QGraphicsWidget.prototype.font = new QFont();

/**
  * @name layoutDirection
  * @memberOf QGraphicsWidget.prototype
  * @type QTextFormat.LayoutDirection
  */
QGraphicsWidget.prototype.layoutDirection = new QTextFormat.LayoutDirection();

/**
  * @name size
  * @memberOf QGraphicsWidget.prototype
  * @type QSizeF
  */
QGraphicsWidget.prototype.size = new QSizeF();

/**
  * @name minimumSize
  * @memberOf QGraphicsWidget.prototype
  * @type QSizeF
  */
QGraphicsWidget.prototype.minimumSize = new QSizeF();

/**
  * @name preferredSize
  * @memberOf QGraphicsWidget.prototype
  * @type QSizeF
  */
QGraphicsWidget.prototype.preferredSize = new QSizeF();

/**
  * @name maximumSize
  * @memberOf QGraphicsWidget.prototype
  * @type QSizeF
  */
QGraphicsWidget.prototype.maximumSize = new QSizeF();

/**
  * @name sizePolicy
  * @memberOf QGraphicsWidget.prototype
  * @type QSizePolicy
  */
QGraphicsWidget.prototype.sizePolicy = new QSizePolicy();

/**
  * @name focusPolicy
  * @memberOf QGraphicsWidget.prototype
  * @type Qt.FocusPolicy
  */
QGraphicsWidget.prototype.focusPolicy = new Qt.FocusPolicy();

/**
  * @name windowFlags
  * @memberOf QGraphicsWidget.prototype
  * @type Qt.WindowFlags
  */
QGraphicsWidget.prototype.windowFlags = new Qt.WindowFlags();

/**
  * @name windowTitle
  * @memberOf QGraphicsWidget.prototype
  * @type String
  */
QGraphicsWidget.prototype.windowTitle = new String();

/**
  * @name geometry
  * @memberOf QGraphicsWidget.prototype
  * @type QRectF
  */
QGraphicsWidget.prototype.geometry = new QRectF();

/**
  * @name autoFillBackground
  * @memberOf QGraphicsWidget.prototype
  * @type Boolean
  */
QGraphicsWidget.prototype.autoFillBackground = new Boolean();

/**
  * @name layout
  * @memberOf QGraphicsWidget.prototype
  * @type QGraphicsLayout
  */
QGraphicsWidget.prototype.layout = new QGraphicsLayout();


