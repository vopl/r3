/**
  * @name QDataStream
  * @constructor
  */
function QDataStream(){return undefined;};

/**
  * @name QDataStream^1
  * @constructor
  * @param {QByteArray} arg__1
  * @param {QIODevice.OpenMode} flags
  */
function QDataStream(arg__1, flags){return undefined;};

/**
  * @name QDataStream^2
  * @constructor
  * @param {QIODevice} arg__1
  */
function QDataStream(arg__1){return undefined;};

/**
  * @name QDataStream^3
  * @constructor
  * @param {QByteArray} arg__1
  */
function QDataStream(arg__1){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QDataStream
  * @name SinglePrecision
  * @see QDataStream#FloatingPointPrecision
  * @type Number
  */
QDataStream.SinglePrecision = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDataStream
  * @name DoublePrecision
  * @see QDataStream#FloatingPointPrecision
  * @type Number
  */
QDataStream.DoublePrecision = 0x1;

/**
  * @constructor 
  * @memberOf QDataStream
  * @name FloatingPointPrecision
  */
QDataStream.FloatingPointPrecision = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf QDataStream
  * @name Qt_1_0
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_1_0 = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QDataStream
  * @name Qt_2_0
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_2_0 = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QDataStream
  * @name Qt_2_1
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_2_1 = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QDataStream
  * @name Qt_3_0
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_3_0 = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf QDataStream
  * @name Qt_3_1
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_3_1 = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf QDataStream
  * @name Qt_3_3
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_3_3 = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QDataStream
  * @name Qt_4_0
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_4_0 = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf QDataStream
  * @name Qt_4_2
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_4_2 = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf QDataStream
  * @name Qt_4_3
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_4_3 = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf QDataStream
  * @name Qt_4_4
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_4_4 = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf QDataStream
  * @name Qt_4_5
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_4_5 = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf QDataStream
  * @name Qt_4_6
  * @see QDataStream#Version
  * @type Number
  */
QDataStream.Qt_4_6 = 0xc;

/**
  * @constructor 
  * @memberOf QDataStream
  * @name Version
  */
QDataStream.Version = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QDataStream
  * @name Ok
  * @see QDataStream#Status
  * @type Number
  */
QDataStream.Ok = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDataStream
  * @name ReadPastEnd
  * @see QDataStream#Status
  * @type Number
  */
QDataStream.ReadPastEnd = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QDataStream
  * @name ReadCorruptData
  * @see QDataStream#Status
  * @type Number
  */
QDataStream.ReadCorruptData = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QDataStream
  * @name WriteFailed
  * @see QDataStream#Status
  * @type Number
  */
QDataStream.WriteFailed = 0x3;

/**
  * @constructor 
  * @memberOf QDataStream
  * @name Status
  */
QDataStream.Status = function(value){;};



/**
  * @name atEnd
  * @function
  * @memberOf QDataStream.prototype
  * @returns {Boolean}
  */
QDataStream.prototype.atEnd = function(){return new Boolean();};

/**
  * @name device
  * @function
  * @memberOf QDataStream.prototype
  * @returns {QIODevice}
  */
QDataStream.prototype.device = function(){return new QIODevice();};

/**
  * @name floatingPointPrecision
  * @function
  * @memberOf QDataStream.prototype
  * @returns {QDataStream.FloatingPointPrecision}
  */
QDataStream.prototype.floatingPointPrecision = function(){return new QDataStream.FloatingPointPrecision();};

/**
  * @name readBoolean
  * @function
  * @memberOf QDataStream.prototype
  * @param {Boolean} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readBoolean = function(i){return new QDataStream();};

/**
  * @name readByte
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readByte = function(i){return new QDataStream();};

/**
  * @name readDouble
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} f
  * @returns {QDataStream}
  */
QDataStream.prototype.readDouble = function(f){return new QDataStream();};

/**
  * @name readFloat
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} f
  * @returns {QDataStream}
  */
QDataStream.prototype.readFloat = function(f){return new QDataStream();};

/**
  * @name readInt
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readInt = function(i){return new QDataStream();};

/**
  * @name readLongLong
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readLongLong = function(i){return new QDataStream();};

/**
  * @name readShort
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readShort = function(i){return new QDataStream();};

/**
  * @name readUInt
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readUInt = function(i){return new QDataStream();};

/**
  * @name readULongLong
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readULongLong = function(i){return new QDataStream();};

/**
  * @name readUShort
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.readUShort = function(i){return new QDataStream();};

/**
  * @name resetStatus
  * @function
  * @memberOf QDataStream.prototype
  * @returns {undefined}
  */
QDataStream.prototype.resetStatus = function(){return undefined;};

/**
  * @name setDevice
  * @function
  * @memberOf QDataStream.prototype
  * @param {QIODevice} arg__1
  * @returns {undefined}
  */
QDataStream.prototype.setDevice = function(arg__1){return undefined;};

/**
  * @name setFloatingPointPrecision
  * @function
  * @memberOf QDataStream.prototype
  * @param {QDataStream.FloatingPointPrecision} precision
  * @returns {undefined}
  */
QDataStream.prototype.setFloatingPointPrecision = function(precision){return undefined;};

/**
  * @name setStatus
  * @function
  * @memberOf QDataStream.prototype
  * @param {QSettings.Status} status
  * @returns {undefined}
  */
QDataStream.prototype.setStatus = function(status){return undefined;};

/**
  * @name setVersion
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QDataStream.prototype.setVersion = function(arg__1){return undefined;};

/**
  * @name skipRawData
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} len
  * @returns {Numeric}
  */
QDataStream.prototype.skipRawData = function(len){return new Numeric();};

/**
  * @name status
  * @function
  * @memberOf QDataStream.prototype
  * @returns {QSettings.Status}
  */
QDataStream.prototype.status = function(){return new QSettings.Status();};

/**
  * @name unsetDevice
  * @function
  * @memberOf QDataStream.prototype
  * @returns {undefined}
  */
QDataStream.prototype.unsetDevice = function(){return undefined;};

/**
  * @name version
  * @function
  * @memberOf QDataStream.prototype
  * @returns {Numeric}
  */
QDataStream.prototype.version = function(){return new Numeric();};

/**
  * @name writeBoolean
  * @function
  * @memberOf QDataStream.prototype
  * @param {Boolean} i
  * @returns {QDataStream}
  */
QDataStream.prototype.writeBoolean = function(i){return new QDataStream();};

/**
  * @name writeByte
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.writeByte = function(i){return new QDataStream();};

/**
  * @name writeDouble
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} f
  * @returns {QDataStream}
  */
QDataStream.prototype.writeDouble = function(f){return new QDataStream();};

/**
  * @name writeFloat
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} f
  * @returns {QDataStream}
  */
QDataStream.prototype.writeFloat = function(f){return new QDataStream();};

/**
  * @name writeInt
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.writeInt = function(i){return new QDataStream();};

/**
  * @name writeLongLong
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.writeLongLong = function(i){return new QDataStream();};

/**
  * @name writeShort
  * @function
  * @memberOf QDataStream.prototype
  * @param {Numeric} i
  * @returns {QDataStream}
  */
QDataStream.prototype.writeShort = function(i){return new QDataStream();};

