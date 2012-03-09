/**
  * @name QTabletEvent
  * @constructor
  * @extends QInputEvent
  * @param {QApplication.Type} t
  * @param {QPoint} pos
  * @param {QPoint} globalPos
  * @param {QPointF} hiResGlobalPos
  * @param {Numeric} device
  * @param {Numeric} pointerType
  * @param {Numeric} pressure
  * @param {Numeric} xTilt
  * @param {Numeric} yTilt
  * @param {Numeric} tangentialPressure
  * @param {Numeric} rotation
  * @param {Numeric} z
  * @param {Qt.KeyboardModifiers} keyState
  * @param {Numeric} uniqueID
  */
function QTabletEvent(t, pos, globalPos, hiResGlobalPos, device, pointerType, pressure, xTilt, yTilt, tangentialPressure, rotation, z, keyState, uniqueID){return undefined;};

QTabletEvent.prototype = new QInputEvent();

/**
  * @default 0x0
  * @constant
  * @memberOf QTabletEvent
  * @name NoDevice
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.NoDevice = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabletEvent
  * @name Puck
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.Puck = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTabletEvent
  * @name Stylus
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.Stylus = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTabletEvent
  * @name Airbrush
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.Airbrush = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QTabletEvent
  * @name FourDMouse
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.FourDMouse = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QTabletEvent
  * @name XFreeEraser
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.XFreeEraser = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QTabletEvent
  * @name RotationStylus
  * @see QTabletEvent#TabletDevice
  * @type Number
  */
QTabletEvent.RotationStylus = 0x6;

/**
  * @constructor 
  * @memberOf QTabletEvent
  * @name TabletDevice
  */
QTabletEvent.TabletDevice = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTabletEvent
  * @name UnknownPointer
  * @see QTabletEvent#PointerType
  * @type Number
  */
QTabletEvent.UnknownPointer = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTabletEvent
  * @name Pen
  * @see QTabletEvent#PointerType
  * @type Number
  */
QTabletEvent.Pen = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTabletEvent
  * @name Cursor
  * @see QTabletEvent#PointerType
  * @type Number
  */
QTabletEvent.Cursor = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTabletEvent
  * @name Eraser
  * @see QTabletEvent#PointerType
  * @type Number
  */
QTabletEvent.Eraser = 0x3;

/**
  * @constructor 
  * @memberOf QTabletEvent
  * @name PointerType
  */
QTabletEvent.PointerType = function(value){;};



/**
  * @name device
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {QTabletEvent.TabletDevice}
  */
QTabletEvent.prototype.device = function(){return new QTabletEvent.TabletDevice();};

/**
  * @name globalPos
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {QPoint}
  */
QTabletEvent.prototype.globalPos = function(){return new QPoint();};

/**
  * @name globalX
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.globalX = function(){return new Numeric();};

/**
  * @name globalY
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.globalY = function(){return new Numeric();};

/**
  * @name hiResGlobalPos
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {QPointF}
  */
QTabletEvent.prototype.hiResGlobalPos = function(){return new QPointF();};

/**
  * @name hiResGlobalX
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.hiResGlobalX = function(){return new Numeric();};

/**
  * @name hiResGlobalY
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.hiResGlobalY = function(){return new Numeric();};

/**
  * @name pointerType
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {QTabletEvent.PointerType}
  */
QTabletEvent.prototype.pointerType = function(){return new QTabletEvent.PointerType();};

/**
  * @name pos
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {QPoint}
  */
QTabletEvent.prototype.pos = function(){return new QPoint();};

/**
  * @name pressure
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.pressure = function(){return new Numeric();};

/**
  * @name rotation
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.rotation = function(){return new Numeric();};

/**
  * @name tangentialPressure
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.tangentialPressure = function(){return new Numeric();};

/**
  * @name uniqueId
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.uniqueId = function(){return new Numeric();};

/**
  * @name x
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.x = function(){return new Numeric();};

/**
  * @name xTilt
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.xTilt = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.y = function(){return new Numeric();};

/**
  * @name yTilt
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.yTilt = function(){return new Numeric();};

/**
  * @name z
  * @function
  * @memberOf QTabletEvent.prototype
  * @returns {Numeric}
  */
QTabletEvent.prototype.z = function(){return new Numeric();};

