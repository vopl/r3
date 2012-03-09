/**
  * @name QPaintEngine
  * @constructor
  * @param {QPaintEngine.PaintEngineFeatures} features
  */
function QPaintEngine(features){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QPaintEngine
  * @name OddEvenMode
  * @see QPaintEngine#PolygonDrawMode
  * @type Number
  */
QPaintEngine.OddEvenMode = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPaintEngine
  * @name WindingMode
  * @see QPaintEngine#PolygonDrawMode
  * @type Number
  */
QPaintEngine.WindingMode = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPaintEngine
  * @name ConvexMode
  * @see QPaintEngine#PolygonDrawMode
  * @type Number
  */
QPaintEngine.ConvexMode = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPaintEngine
  * @name PolylineMode
  * @see QPaintEngine#PolygonDrawMode
  * @type Number
  */
QPaintEngine.PolylineMode = 0x3;

/**
  * @constructor 
  * @memberOf QPaintEngine
  * @name PolygonDrawMode
  */
QPaintEngine.PolygonDrawMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPaintEngine
  * @name X11
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.X11 = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPaintEngine
  * @name Windows
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.Windows = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPaintEngine
  * @name QuickDraw
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.QuickDraw = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPaintEngine
  * @name CoreGraphics
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.CoreGraphics = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPaintEngine
  * @name MacPrinter
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.MacPrinter = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPaintEngine
  * @name QWindowSystem
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.QWindowSystem = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPaintEngine
  * @name PostScript
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.PostScript = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QPaintEngine
  * @name OpenGL
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.OpenGL = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QPaintEngine
  * @name Picture
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.Picture = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QPaintEngine
  * @name SVG
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.SVG = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QPaintEngine
  * @name Raster
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.Raster = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QPaintEngine
  * @name Direct3D
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.Direct3D = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QPaintEngine
  * @name Pdf
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.Pdf = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QPaintEngine
  * @name OpenVG
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.OpenVG = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QPaintEngine
  * @name OpenGL2
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.OpenGL2 = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QPaintEngine
  * @name PaintBuffer
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.PaintBuffer = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QPaintEngine
  * @name Blitter
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.Blitter = 0x10;

/**
  * @default 50
  * @constant
  * @memberOf QPaintEngine
  * @name User
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.User = 0x32;

/**
  * @default 100
  * @constant
  * @memberOf QPaintEngine
  * @name MaxUser
  * @see QPaintEngine#Type
  * @type Number
  */
QPaintEngine.MaxUser = 0x64;

/**
  * @constructor 
  * @memberOf QPaintEngine
  * @name Type
  */
QPaintEngine.Type = function(value){;};



/**
  * @default 0xffffffff
  * @constant
  * @memberOf QPaintEngine
  * @name AllFeatures
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.AllFeatures = 0xffffffff;

/**
  * @default 0x00000001
  * @constant
  * @memberOf QPaintEngine
  * @name PrimitiveTransform
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PrimitiveTransform = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QPaintEngine
  * @name PatternTransform
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PatternTransform = 0x2;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QPaintEngine
  * @name PixmapTransform
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PixmapTransform = 0x4;

/**
  * @default 0x00000008
  * @constant
  * @memberOf QPaintEngine
  * @name PatternBrush
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PatternBrush = 0x8;

/**
  * @default 0x00000010
  * @constant
  * @memberOf QPaintEngine
  * @name LinearGradientFill
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.LinearGradientFill = 0x10;

/**
  * @default 0x00000020
  * @constant
  * @memberOf QPaintEngine
  * @name RadialGradientFill
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.RadialGradientFill = 0x20;

/**
  * @default 0x00000040
  * @constant
  * @memberOf QPaintEngine
  * @name ConicalGradientFill
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.ConicalGradientFill = 0x40;

/**
  * @default 0x00000080
  * @constant
  * @memberOf QPaintEngine
  * @name AlphaBlend
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.AlphaBlend = 0x80;

/**
  * @default 0x00000100
  * @constant
  * @memberOf QPaintEngine
  * @name PorterDuff
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PorterDuff = 0x100;

/**
  * @default 0x00000200
  * @constant
  * @memberOf QPaintEngine
  * @name PainterPaths
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PainterPaths = 0x200;

/**
  * @default 0x00000400
  * @constant
  * @memberOf QPaintEngine
  * @name Antialiasing
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.Antialiasing = 0x400;

/**
  * @default 0x00000800
  * @constant
  * @memberOf QPaintEngine
  * @name BrushStroke
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.BrushStroke = 0x800;

/**
  * @default 0x00001000
  * @constant
  * @memberOf QPaintEngine
  * @name ConstantOpacity
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.ConstantOpacity = 0x1000;

/**
  * @default 0x00002000
  * @constant
  * @memberOf QPaintEngine
  * @name MaskedBrush
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.MaskedBrush = 0x2000;

/**
  * @default 0x00004000
  * @constant
  * @memberOf QPaintEngine
  * @name PerspectiveTransform
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PerspectiveTransform = 0x4000;

/**
  * @default 0x00008000
  * @constant
  * @memberOf QPaintEngine
  * @name BlendModes
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.BlendModes = 0x8000;

/**
  * @default 0x00010000
  * @constant
  * @memberOf QPaintEngine
  * @name ObjectBoundingModeGradients
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.ObjectBoundingModeGradients = 0x10000;

/**
  * @default 0x00020000
  * @constant
  * @memberOf QPaintEngine
  * @name RasterOpModes
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.RasterOpModes = 0x20000;

/**
  * @default 0x20000000
  * @constant
  * @memberOf QPaintEngine
  * @name PaintOutsidePaintEvent
  * @see QPaintEngine#PaintEngineFeatures
  * @see QPaintEngine#PaintEngineFeature
  * @type Number
  */
QPaintEngine.PaintOutsidePaintEvent = 0x20000000;

/**
  * @constructor 
  * @memberOf QPaintEngine
  * @name PaintEngineFeature
  */
QPaintEngine.PaintEngineFeature = function(value){;};

/**
  * @constructor 
  * @memberOf QPaintEngine
  * @name PaintEngineFeatures
  */
QPaintEngine.PaintEngineFeatures = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0001
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyPen
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyPen = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyBrush
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyBrush = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyBrushOrigin
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyBrushOrigin = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyFont
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyFont = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyBackground
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyBackground = 0x10;

/**
  * @default 0x0020
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyBackgroundMode
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyBackgroundMode = 0x20;

/**
  * @default 0x0040
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyTransform
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyTransform = 0x40;

/**
  * @default 0x0080
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyClipRegion
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyClipRegion = 0x80;

/**
  * @default 0x0100
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyClipPath
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyClipPath = 0x100;

/**
  * @default 0x0200
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyHints
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyHints = 0x200;

/**
  * @default 0x0400
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyCompositionMode
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyCompositionMode = 0x400;

/**
  * @default 0x0800
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyClipEnabled
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyClipEnabled = 0x800;

/**
  * @default 0x1000
  * @constant
  * @memberOf QPaintEngine
  * @name DirtyOpacity
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.DirtyOpacity = 0x1000;

/**
  * @default 0xffff
  * @constant
  * @memberOf QPaintEngine
  * @name AllDirty
  * @see QPaintEngine#DirtyFlags
  * @see QPaintEngine#DirtyFlag
  * @type Number
  */
QPaintEngine.AllDirty = 0xffff;

/**
  * @constructor 
  * @memberOf QPaintEngine
  * @name DirtyFlag
  */
QPaintEngine.DirtyFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QPaintEngine
  * @name DirtyFlags
  */
QPaintEngine.DirtyFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name begin
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPaintDevice} pdev
  * @returns {Boolean}
  */
QPaintEngine.prototype.begin = function(pdev){return new Boolean();};

/**
  * @name clearDirty
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPaintEngine.DirtyFlags} df
  * @returns {undefined}
  */
QPaintEngine.prototype.clearDirty = function(df){return undefined;};

/**
  * @name coordinateOffset
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {QPoint}
  */
QPaintEngine.prototype.coordinateOffset = function(){return new QPoint();};

/**
  * @name drawEllipse
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRect} r
  * @returns {undefined}
  */
QPaintEngine.prototype.drawEllipse = function(r){return undefined;};

/**
  * @name drawImage
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRectF} r
  * @param {QImage} pm
  * @param {QRectF} sr
  * @param {Qt.ImageConversionFlags} flags
  * @returns {undefined}
  */
QPaintEngine.prototype.drawImage = function(r, pm, sr, flags){return undefined;};

/**
  * @name drawLines
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QLine} lines
  * @param {Numeric} lineCount
  * @returns {undefined}
  */
QPaintEngine.prototype.drawLines = function(lines, lineCount){return undefined;};

/**
  * @name drawPath
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPainterPath} path
  * @returns {undefined}
  */
QPaintEngine.prototype.drawPath = function(path){return undefined;};

/**
  * @name drawPixmap
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRectF} r
  * @param {QPixmap} pm
  * @param {QRectF} sr
  * @returns {undefined}
  */
QPaintEngine.prototype.drawPixmap = function(r, pm, sr){return undefined;};

/**
  * @name drawPoints
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPoint} points
  * @param {Numeric} pointCount
  * @returns {undefined}
  */
QPaintEngine.prototype.drawPoints = function(points, pointCount){return undefined;};

/**
  * @name drawPolygon
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPoint} points
  * @param {Numeric} pointCount
  * @param {QPaintEngine.PolygonDrawMode} mode
  * @returns {undefined}
  */
QPaintEngine.prototype.drawPolygon = function(points, pointCount, mode){return undefined;};

/**
  * @name drawRects
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRect} rects
  * @param {Numeric} rectCount
  * @returns {undefined}
  */
QPaintEngine.prototype.drawRects = function(rects, rectCount){return undefined;};

/**
  * @name drawTextItem
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPointF} p
  * @param {QTextItem} textItem
  * @returns {undefined}
  */
QPaintEngine.prototype.drawTextItem = function(p, textItem){return undefined;};

/**
  * @name drawTiledPixmap
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRectF} r
  * @param {QPixmap} pixmap
  * @param {QPointF} s
  * @returns {undefined}
  */
QPaintEngine.prototype.drawTiledPixmap = function(r, pixmap, s){return undefined;};

/**
  * @name end
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {Boolean}
  */
QPaintEngine.prototype.end = function(){return new Boolean();};

/**
  * @name hasFeature
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPaintEngine.PaintEngineFeatures} feature
  * @returns {Boolean}
  */
QPaintEngine.prototype.hasFeature = function(feature){return new Boolean();};

/**
  * @name isActive
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {Boolean}
  */
QPaintEngine.prototype.isActive = function(){return new Boolean();};

/**
  * @name isExtended
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {Boolean}
  */
QPaintEngine.prototype.isExtended = function(){return new Boolean();};

/**
  * @name paintDevice
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {QPaintDevice}
  */
QPaintEngine.prototype.paintDevice = function(){return new QPaintDevice();};

/**
  * @name painter
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {QPainter}
  */
QPaintEngine.prototype.painter = function(){return new QPainter();};

/**
  * @name setActive
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {Boolean} newState
  * @returns {undefined}
  */
QPaintEngine.prototype.setActive = function(newState){return undefined;};

/**
  * @name setDirty
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPaintEngine.DirtyFlags} df
  * @returns {undefined}
  */
QPaintEngine.prototype.setDirty = function(df){return undefined;};

/**
  * @name setSystemClip
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRegion} baseClip
  * @returns {undefined}
  */
QPaintEngine.prototype.setSystemClip = function(baseClip){return undefined;};

/**
  * @name setSystemRect
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QRect} rect
  * @returns {undefined}
  */
QPaintEngine.prototype.setSystemRect = function(rect){return undefined;};

/**
  * @name syncState
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {undefined}
  */
QPaintEngine.prototype.syncState = function(){return undefined;};

/**
  * @name systemClip
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {QRegion}
  */
QPaintEngine.prototype.systemClip = function(){return new QRegion();};

/**
  * @name systemRect
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {QRect}
  */
QPaintEngine.prototype.systemRect = function(){return new QRect();};

/**
  * @name testDirty
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPaintEngine.DirtyFlags} df
  * @returns {Boolean}
  */
QPaintEngine.prototype.testDirty = function(df){return new Boolean();};

/**
  * @name type
  * @function
  * @memberOf QPaintEngine.prototype
  * @returns {QApplication.Type}
  */
QPaintEngine.prototype.type = function(){return new QApplication.Type();};

/**
  * @name updateState
  * @function
  * @memberOf QPaintEngine.prototype
  * @param {QPaintEngineState} state
  * @returns {undefined}
  */
QPaintEngine.prototype.updateState = function(state){return undefined;};

