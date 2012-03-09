/**
  * @name QPainter
  * @constructor
  */
function QPainter(){return undefined;};

/**
  * @name redirected
  * @function
  * @memberOf QPainter
  * @param {QPaintDevice} device
  * @param {QPoint} offset
  * @returns {QPaintDevice}
  */
QPainter.redirected = function(device, offset){return new QPaintDevice();};

/**
  * @name restoreRedirected
  * @function
  * @memberOf QPainter
  * @param {QPaintDevice} device
  * @returns {undefined}
  */
QPainter.restoreRedirected = function(device){return undefined;};

/**
  * @name setRedirected
  * @function
  * @memberOf QPainter
  * @param {QPaintDevice} device
  * @param {QPaintDevice} replacement
  * @param {QPoint} offset
  * @returns {undefined}
  */
QPainter.setRedirected = function(device, replacement, offset){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_SourceOver
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_SourceOver = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_DestinationOver
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_DestinationOver = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Clear
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Clear = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Source
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Source = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Destination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Destination = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_SourceIn
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_SourceIn = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_DestinationIn
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_DestinationIn = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_SourceOut
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_SourceOut = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_DestinationOut
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_DestinationOut = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_SourceAtop
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_SourceAtop = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_DestinationAtop
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_DestinationAtop = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Xor
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Xor = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Plus
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Plus = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Multiply
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Multiply = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Screen
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Screen = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Overlay
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Overlay = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Darken
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Darken = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Lighten
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Lighten = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_ColorDodge
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_ColorDodge = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_ColorBurn
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_ColorBurn = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_HardLight
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_HardLight = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_SoftLight
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_SoftLight = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Difference
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Difference = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QPainter
  * @name CompositionMode_Exclusion
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.CompositionMode_Exclusion = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QPainter
  * @name RasterOp_SourceOrDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_SourceOrDestination = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QPainter
  * @name RasterOp_SourceAndDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_SourceAndDestination = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QPainter
  * @name RasterOp_SourceXorDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_SourceXorDestination = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QPainter
  * @name RasterOp_NotSourceAndNotDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_NotSourceAndNotDestination = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QPainter
  * @name RasterOp_NotSourceOrNotDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_NotSourceOrNotDestination = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QPainter
  * @name RasterOp_NotSourceXorDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_NotSourceXorDestination = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QPainter
  * @name RasterOp_NotSource
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_NotSource = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QPainter
  * @name RasterOp_NotSourceAndDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_NotSourceAndDestination = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QPainter
  * @name RasterOp_SourceAndNotDestination
  * @see QPainter#CompositionMode
  * @type Number
  */
QPainter.RasterOp_SourceAndNotDestination = 0x20;

/**
  * @constructor 
  * @memberOf QPainter
  * @name CompositionMode
  */
QPainter.CompositionMode = function(value){;};



/**
  * @default 0x01
  * @constant
  * @memberOf QPainter
  * @name Antialiasing
  * @see QPainter#RenderHints
  * @see QPainter#RenderHint
  * @type Number
  */
QPainter.Antialiasing = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QPainter
  * @name TextAntialiasing
  * @see QPainter#RenderHints
  * @see QPainter#RenderHint
  * @type Number
  */
QPainter.TextAntialiasing = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QPainter
  * @name SmoothPixmapTransform
  * @see QPainter#RenderHints
  * @see QPainter#RenderHint
  * @type Number
  */
QPainter.SmoothPixmapTransform = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QPainter
  * @name HighQualityAntialiasing
  * @see QPainter#RenderHints
  * @see QPainter#RenderHint
  * @type Number
  */
QPainter.HighQualityAntialiasing = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QPainter
  * @name NonCosmeticDefaultPen
  * @see QPainter#RenderHints
  * @see QPainter#RenderHint
  * @type Number
  */
QPainter.NonCosmeticDefaultPen = 0x10;

/**
  * @constructor 
  * @memberOf QPainter
  * @name RenderHint
  */
QPainter.RenderHint = function(value){;};

/**
  * @constructor 
  * @memberOf QPainter
  * @name RenderHints
  */
QPainter.RenderHints = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x01
  * @constant
  * @memberOf QPainter
  * @name OpaqueHint
  * @see QPainter#PixmapFragmentHint
  * @type Number
  */
QPainter.OpaqueHint = 0x1;

/**
  * @constructor 
  * @memberOf QPainter
  * @name PixmapFragmentHint
  */
QPainter.PixmapFragmentHint = function(value){;};



/**
  * @name background
  * @function
  * @memberOf QPainter.prototype
  * @returns {QBrush}
  */
QPainter.prototype.background = function(){return new QBrush();};

/**
  * @name backgroundMode
  * @function
  * @memberOf QPainter.prototype
  * @returns {Qt.BGMode}
  */
QPainter.prototype.backgroundMode = function(){return new Qt.BGMode();};

/**
  * @name begin
  * @function
  * @memberOf QPainter.prototype
  * @param {QPaintDevice} arg__1
  * @returns {Boolean}
  */
QPainter.prototype.begin = function(arg__1){return new Boolean();};

/**
  * @name beginNativePainting
  * @function
  * @memberOf QPainter.prototype
  * @returns {undefined}
  */
QPainter.prototype.beginNativePainting = function(){return undefined;};

/**
  * @name boundingRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} rect
  * @param {Numeric} flags
  * @param {String} text
  * @returns {QRect}
  */
QPainter.prototype.boundingRect = function(rect, flags, text){return new QRect();};

/**
  * @name brush
  * @function
  * @memberOf QPainter.prototype
  * @returns {QBrush}
  */
QPainter.prototype.brush = function(){return new QBrush();};

/**
  * @name brushOrigin
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPoint}
  */
QPainter.prototype.brushOrigin = function(){return new QPoint();};

/**
  * @name clipBoundingRect
  * @function
  * @memberOf QPainter.prototype
  * @returns {QRectF}
  */
QPainter.prototype.clipBoundingRect = function(){return new QRectF();};

/**
  * @name clipPath
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPainterPath}
  */
QPainter.prototype.clipPath = function(){return new QPainterPath();};

/**
  * @name clipRegion
  * @function
  * @memberOf QPainter.prototype
  * @returns {QRegion}
  */
QPainter.prototype.clipRegion = function(){return new QRegion();};

/**
  * @name combinedMatrix
  * @function
  * @memberOf QPainter.prototype
  * @returns {QMatrix}
  */
QPainter.prototype.combinedMatrix = function(){return new QMatrix();};

/**
  * @name combinedTransform
  * @function
  * @memberOf QPainter.prototype
  * @returns {QTransform}
  */
QPainter.prototype.combinedTransform = function(){return new QTransform();};

/**
  * @name compositionMode
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPainter.CompositionMode}
  */
QPainter.prototype.compositionMode = function(){return new QPainter.CompositionMode();};

/**
  * @name device
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPaintDevice}
  */
QPainter.prototype.device = function(){return new QPaintDevice();};

/**
  * @name deviceMatrix
  * @function
  * @memberOf QPainter.prototype
  * @returns {QMatrix}
  */
QPainter.prototype.deviceMatrix = function(){return new QMatrix();};

/**
  * @name deviceTransform
  * @function
  * @memberOf QPainter.prototype
  * @returns {QTransform}
  */
QPainter.prototype.deviceTransform = function(){return new QTransform();};

/**
  * @name drawArc
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @param {Numeric} a
  * @param {Numeric} alen
  * @returns {undefined}
  */
QPainter.prototype.drawArc = function(arg__1, a, alen){return undefined;};

/**
  * @name drawChord
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @param {Numeric} a
  * @param {Numeric} alen
  * @returns {undefined}
  */
QPainter.prototype.drawChord = function(arg__1, a, alen){return undefined;};

/**
  * @name drawConvexPolygon
  * @function
  * @memberOf QPainter.prototype
  * @param {QPolygon} polygon
  * @returns {undefined}
  */
QPainter.prototype.drawConvexPolygon = function(polygon){return undefined;};

/**
  * @name drawEllipse
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} center
  * @param {Numeric} rx
  * @param {Numeric} ry
  * @returns {undefined}
  */
QPainter.prototype.drawEllipse = function(center, rx, ry){return undefined;};

/**
  * @name drawImage
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} p
  * @param {QImage} image
  * @returns {undefined}
  */
QPainter.prototype.drawImage = function(p, image){return undefined;};

/**
  * @name drawLine
  * @function
  * @memberOf QPainter.prototype
  * @param {QLine} line
  * @returns {undefined}
  */
QPainter.prototype.drawLine = function(line){return undefined;};

/**
  * @name drawLines
  * @function
  * @memberOf QPainter.prototype
  * @param {Array} lines
  * @returns {undefined}
  */
QPainter.prototype.drawLines = function(lines){return undefined;};

/**
  * @name drawLinesF
  * @function
  * @memberOf QPainter.prototype
  * @param {Array} lines
  * @returns {undefined}
  */
QPainter.prototype.drawLinesF = function(lines){return undefined;};

/**
  * @name drawLinesFromPoints
  * @function
  * @memberOf QPainter.prototype
  * @param {Array} pointPairs
  * @returns {undefined}
  */
QPainter.prototype.drawLinesFromPoints = function(pointPairs){return undefined;};

/**
  * @name drawLinesFromPointsF
  * @function
  * @memberOf QPainter.prototype
  * @param {Array} pointPairs
  * @returns {undefined}
  */
QPainter.prototype.drawLinesFromPointsF = function(pointPairs){return undefined;};

/**
  * @name drawPath
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QPainter.prototype.drawPath = function(path){return undefined;};

/**
  * @name drawPicture
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} p
  * @param {QPicture} picture
  * @returns {undefined}
  */
QPainter.prototype.drawPicture = function(p, picture){return undefined;};

/**
  * @name drawPie
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @param {Numeric} a
  * @param {Numeric} alen
  * @returns {undefined}
  */
QPainter.prototype.drawPie = function(arg__1, a, alen){return undefined;};

/**
  * @name drawPixmap
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} p
  * @param {QPixmap} pm
  * @returns {undefined}
  */
QPainter.prototype.drawPixmap = function(p, pm){return undefined;};

/**
  * @name drawPoint
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} p
  * @returns {undefined}
  */
QPainter.prototype.drawPoint = function(p){return undefined;};

/**
  * @name drawPoints
  * @function
  * @memberOf QPainter.prototype
  * @param {QPolygon} points
  * @returns {undefined}
  */
QPainter.prototype.drawPoints = function(points){return undefined;};

/**
  * @name drawPolygon
  * @function
  * @memberOf QPainter.prototype
  * @param {QPolygon} polygon
  * @param {Qt.FillRule} fillRule
  * @returns {undefined}
  */
QPainter.prototype.drawPolygon = function(polygon, fillRule){return undefined;};

/**
  * @name drawPolyline
  * @function
  * @memberOf QPainter.prototype
  * @param {QPolygon} polygon
  * @returns {undefined}
  */
QPainter.prototype.drawPolyline = function(polygon){return undefined;};

/**
  * @name drawRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} rect
  * @returns {undefined}
  */
QPainter.prototype.drawRect = function(rect){return undefined;};

/**
  * @name drawRects
  * @function
  * @memberOf QPainter.prototype
  * @param {Array} rectangles
  * @returns {undefined}
  */
QPainter.prototype.drawRects = function(rectangles){return undefined;};

/**
  * @name drawRectsF
  * @function
  * @memberOf QPainter.prototype
  * @param {Array} rectangles
  * @returns {undefined}
  */
QPainter.prototype.drawRectsF = function(rectangles){return undefined;};

/**
  * @name drawRoundRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} r
  * @param {Numeric} xround
  * @param {Numeric} yround
  * @returns {undefined}
  */
QPainter.prototype.drawRoundRect = function(r, xround, yround){return undefined;};

/**
  * @name drawRoundedRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} rect
  * @param {Numeric} xRadius
  * @param {Numeric} yRadius
  * @param {Qt.SizeMode} mode
  * @returns {undefined}
  */
QPainter.prototype.drawRoundedRect = function(rect, xRadius, yRadius, mode){return undefined;};

/**
  * @name drawText
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} p
  * @param {String} s
  * @returns {undefined}
  */
QPainter.prototype.drawText = function(p, s){return undefined;};

/**
  * @name drawTextItem
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} p
  * @param {QTextItem} ti
  * @returns {undefined}
  */
QPainter.prototype.drawTextItem = function(p, ti){return undefined;};

/**
  * @name drawTiledPixmap
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @param {QPixmap} arg__2
  * @param {QPoint} arg__3
  * @returns {undefined}
  */
QPainter.prototype.drawTiledPixmap = function(arg__1, arg__2, arg__3){return undefined;};

/**
  * @name end
  * @function
  * @memberOf QPainter.prototype
  * @returns {Boolean}
  */
QPainter.prototype.end = function(){return new Boolean();};

/**
  * @name endNativePainting
  * @function
  * @memberOf QPainter.prototype
  * @returns {undefined}
  */
QPainter.prototype.endNativePainting = function(){return undefined;};

/**
  * @name eraseRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @returns {undefined}
  */
QPainter.prototype.eraseRect = function(arg__1){return undefined;};

/**
  * @name fillPath
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainterPath} path
  * @param {QBrush} brush
  * @returns {undefined}
  */
QPainter.prototype.fillPath = function(path, brush){return undefined;};

/**
  * @name fillRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @param {QBrush} arg__2
  * @returns {undefined}
  */
QPainter.prototype.fillRect = function(arg__1, arg__2){return undefined;};

/**
  * @name font
  * @function
  * @memberOf QPainter.prototype
  * @returns {QFont}
  */
QPainter.prototype.font = function(){return new QFont();};

/**
  * @name hasClipping
  * @function
  * @memberOf QPainter.prototype
  * @returns {Boolean}
  */
QPainter.prototype.hasClipping = function(){return new Boolean();};

/**
  * @name initFrom
  * @function
  * @memberOf QPainter.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QPainter.prototype.initFrom = function(widget){return undefined;};

/**
  * @name isActive
  * @function
  * @memberOf QPainter.prototype
  * @returns {Boolean}
  */
QPainter.prototype.isActive = function(){return new Boolean();};

/**
  * @name layoutDirection
  * @function
  * @memberOf QPainter.prototype
  * @returns {QTextFormat.LayoutDirection}
  */
QPainter.prototype.layoutDirection = function(){return new QTextFormat.LayoutDirection();};

/**
  * @name opacity
  * @function
  * @memberOf QPainter.prototype
  * @returns {Numeric}
  */
QPainter.prototype.opacity = function(){return new Numeric();};

/**
  * @name paintEngine
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPaintEngine}
  */
QPainter.prototype.paintEngine = function(){return new QPaintEngine();};

/**
  * @name pen
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPen}
  */
QPainter.prototype.pen = function(){return new QPen();};

/**
  * @name renderHints
  * @function
  * @memberOf QPainter.prototype
  * @returns {QPainter.RenderHints}
  */
QPainter.prototype.renderHints = function(){return new QPainter.RenderHints();};

/**
  * @name resetMatrix
  * @function
  * @memberOf QPainter.prototype
  * @returns {undefined}
  */
QPainter.prototype.resetMatrix = function(){return undefined;};

/**
  * @name resetTransform
  * @function
  * @memberOf QPainter.prototype
  * @returns {undefined}
  */
QPainter.prototype.resetTransform = function(){return undefined;};

/**
  * @name restore
  * @function
  * @memberOf QPainter.prototype
  * @returns {undefined}
  */
QPainter.prototype.restore = function(){return undefined;};

/**
  * @name rotate
  * @function
  * @memberOf QPainter.prototype
  * @param {Numeric} a
  * @returns {undefined}
  */
QPainter.prototype.rotate = function(a){return undefined;};

/**
  * @name save
  * @function
  * @memberOf QPainter.prototype
  * @returns {undefined}
  */
QPainter.prototype.save = function(){return undefined;};

/**
  * @name scale
  * @function
  * @memberOf QPainter.prototype
  * @param {Numeric} sx
  * @param {Numeric} sy
  * @returns {undefined}
  */
QPainter.prototype.scale = function(sx, sy){return undefined;};

/**
  * @name setBackground
  * @function
  * @memberOf QPainter.prototype
  * @param {QBrush} bg
  * @returns {undefined}
  */
QPainter.prototype.setBackground = function(bg){return undefined;};

/**
  * @name setBackgroundMode
  * @function
  * @memberOf QPainter.prototype
  * @param {Qt.BGMode} mode
  * @returns {undefined}
  */
QPainter.prototype.setBackgroundMode = function(mode){return undefined;};

/**
  * @name setBrush
  * @function
  * @memberOf QPainter.prototype
  * @param {Qt.BrushStyle} style
  * @returns {undefined}
  */
QPainter.prototype.setBrush = function(style){return undefined;};

/**
  * @name setBrushOrigin
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} arg__1
  * @returns {undefined}
  */
QPainter.prototype.setBrushOrigin = function(arg__1){return undefined;};

/**
  * @name setClipPath
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainterPath} path
  * @param {Qt.ClipOperation} op
  * @returns {undefined}
  */
QPainter.prototype.setClipPath = function(path, op){return undefined;};

/**
  * @name setClipRect
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} arg__1
  * @param {Qt.ClipOperation} op
  * @returns {undefined}
  */
QPainter.prototype.setClipRect = function(arg__1, op){return undefined;};

/**
  * @name setClipRegion
  * @function
  * @memberOf QPainter.prototype
  * @param {QRegion} arg__1
  * @param {Qt.ClipOperation} op
  * @returns {undefined}
  */
QPainter.prototype.setClipRegion = function(arg__1, op){return undefined;};

/**
  * @name setClipping
  * @function
  * @memberOf QPainter.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
QPainter.prototype.setClipping = function(enable){return undefined;};

/**
  * @name setCompositionMode
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainter.CompositionMode} mode
  * @returns {undefined}
  */
QPainter.prototype.setCompositionMode = function(mode){return undefined;};

/**
  * @name setFont
  * @function
  * @memberOf QPainter.prototype
  * @param {QFont} f
  * @returns {undefined}
  */
QPainter.prototype.setFont = function(f){return undefined;};

/**
  * @name setLayoutDirection
  * @function
  * @memberOf QPainter.prototype
  * @param {QTextFormat.LayoutDirection} direction
  * @returns {undefined}
  */
QPainter.prototype.setLayoutDirection = function(direction){return undefined;};

/**
  * @name setOpacity
  * @function
  * @memberOf QPainter.prototype
  * @param {Numeric} opacity
  * @returns {undefined}
  */
QPainter.prototype.setOpacity = function(opacity){return undefined;};

/**
  * @name setPen
  * @function
  * @memberOf QPainter.prototype
  * @param {Qt.PenStyle} style
  * @returns {undefined}
  */
QPainter.prototype.setPen = function(style){return undefined;};

/**
  * @name setRenderHint
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainter.RenderHint} hint
  * @param {Boolean} on
  * @returns {undefined}
  */
QPainter.prototype.setRenderHint = function(hint, on){return undefined;};

/**
  * @name setRenderHints
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainter.RenderHints} hints
  * @param {Boolean} on
  * @returns {undefined}
  */
QPainter.prototype.setRenderHints = function(hints, on){return undefined;};

/**
  * @name setTransform
  * @function
  * @memberOf QPainter.prototype
  * @param {QTransform} transform
  * @param {Boolean} combine
  * @returns {undefined}
  */
QPainter.prototype.setTransform = function(transform, combine){return undefined;};

/**
  * @name setViewTransformEnabled
  * @function
  * @memberOf QPainter.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
QPainter.prototype.setViewTransformEnabled = function(enable){return undefined;};

/**
  * @name setViewport
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} viewport
  * @returns {undefined}
  */
QPainter.prototype.setViewport = function(viewport){return undefined;};

/**
  * @name setWindow
  * @function
  * @memberOf QPainter.prototype
  * @param {QRect} window
  * @returns {undefined}
  */
QPainter.prototype.setWindow = function(window){return undefined;};

/**
  * @name setWorldMatrix
  * @function
  * @memberOf QPainter.prototype
  * @param {QMatrix} matrix
  * @param {Boolean} combine
  * @returns {undefined}
  */
QPainter.prototype.setWorldMatrix = function(matrix, combine){return undefined;};

/**
  * @name setWorldMatrixEnabled
  * @function
  * @memberOf QPainter.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QPainter.prototype.setWorldMatrixEnabled = function(enabled){return undefined;};

/**
  * @name setWorldTransform
  * @function
  * @memberOf QPainter.prototype
  * @param {QTransform} matrix
  * @param {Boolean} combine
  * @returns {undefined}
  */
QPainter.prototype.setWorldTransform = function(matrix, combine){return undefined;};

/**
  * @name shear
  * @function
  * @memberOf QPainter.prototype
  * @param {Numeric} sh
  * @param {Numeric} sv
  * @returns {undefined}
  */
QPainter.prototype.shear = function(sh, sv){return undefined;};

/**
  * @name strokePath
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainterPath} path
  * @param {QPen} pen
  * @returns {undefined}
  */
QPainter.prototype.strokePath = function(path, pen){return undefined;};

/**
  * @name testRenderHint
  * @function
  * @memberOf QPainter.prototype
  * @param {QPainter.RenderHint} hint
  * @returns {Boolean}
  */
QPainter.prototype.testRenderHint = function(hint){return new Boolean();};

/**
  * @name transform
  * @function
  * @memberOf QPainter.prototype
  * @returns {QTransform}
  */
QPainter.prototype.transform = function(){return new QTransform();};

/**
  * @name translate
  * @function
  * @memberOf QPainter.prototype
  * @param {QPoint} offset
  * @returns {undefined}
  */
QPainter.prototype.translate = function(offset){return undefined;};

/**
  * @name viewTransformEnabled
  * @function
  * @memberOf QPainter.prototype
  * @returns {Boolean}
  */
QPainter.prototype.viewTransformEnabled = function(){return new Boolean();};

/**
  * @name viewport
  * @function
  * @memberOf QPainter.prototype
  * @returns {QRect}
  */
QPainter.prototype.viewport = function(){return new QRect();};

/**
  * @name window
  * @function
  * @memberOf QPainter.prototype
  * @returns {QRect}
  */
QPainter.prototype.window = function(){return new QRect();};

/**
  * @name worldMatrix
  * @function
  * @memberOf QPainter.prototype
  * @returns {QMatrix}
  */
QPainter.prototype.worldMatrix = function(){return new QMatrix();};

/**
  * @name worldMatrixEnabled
  * @function
  * @memberOf QPainter.prototype
  * @returns {Boolean}
  */
QPainter.prototype.worldMatrixEnabled = function(){return new Boolean();};

/**
  * @name worldTransform
  * @function
  * @memberOf QPainter.prototype
  * @returns {QTransform}
  */
QPainter.prototype.worldTransform = function(){return new QTransform();};

