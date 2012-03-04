/**
  * @name QTextStream
  * @constructor
  */
function QTextStream(){return undefined;};

/**
  * @name QTextStream^1
  * @constructor
  * @param {QIODevice} device
  */
function QTextStream(device){return undefined;};

/**
  * @name QTextStream^2
  * @constructor
  * @param {QByteArray} array
  * @param {QIODevice.OpenMode} openMode
  */
function QTextStream(array, openMode){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QTextStream
  * @name SmartNotation
  * @see QTextStream#RealNumberNotation
  * @type Number
  */
QTextStream.SmartNotation = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextStream
  * @name FixedNotation
  * @see QTextStream#RealNumberNotation
  * @type Number
  */
QTextStream.FixedNotation = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextStream
  * @name ScientificNotation
  * @see QTextStream#RealNumberNotation
  * @type Number
  */
QTextStream.ScientificNotation = 0x2;

/**
  * @constructor 
  * @memberOf QTextStream
  * @name RealNumberNotation
  */
QTextStream.RealNumberNotation = function(value){;};



/**
  * @default 0x1
  * @constant
  * @memberOf QTextStream
  * @name ShowBase
  * @see QTextStream#NumberFlags
  * @see QTextStream#NumberFlag
  * @type Number
  */
QTextStream.ShowBase = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextStream
  * @name ForcePoint
  * @see QTextStream#NumberFlags
  * @see QTextStream#NumberFlag
  * @type Number
  */
QTextStream.ForcePoint = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QTextStream
  * @name ForceSign
  * @see QTextStream#NumberFlags
  * @see QTextStream#NumberFlag
  * @type Number
  */
QTextStream.ForceSign = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QTextStream
  * @name UppercaseBase
  * @see QTextStream#NumberFlags
  * @see QTextStream#NumberFlag
  * @type Number
  */
QTextStream.UppercaseBase = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QTextStream
  * @name UppercaseDigits
  * @see QTextStream#NumberFlags
  * @see QTextStream#NumberFlag
  * @type Number
  */
QTextStream.UppercaseDigits = 0x10;

/**
  * @constructor 
  * @memberOf QTextStream
  * @name NumberFlag
  */
QTextStream.NumberFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QTextStream
  * @name NumberFlags
  */
QTextStream.NumberFlags = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QTextStream
  * @name AlignLeft
  * @see QTextStream#FieldAlignment
  * @type Number
  */
QTextStream.AlignLeft = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextStream
  * @name AlignRight
  * @see QTextStream#FieldAlignment
  * @type Number
  */
QTextStream.AlignRight = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextStream
  * @name AlignCenter
  * @see QTextStream#FieldAlignment
  * @type Number
  */
QTextStream.AlignCenter = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextStream
  * @name AlignAccountingStyle
  * @see QTextStream#FieldAlignment
  * @type Number
  */
QTextStream.AlignAccountingStyle = 0x3;

/**
  * @constructor 
  * @memberOf QTextStream
  * @name FieldAlignment
  */
QTextStream.FieldAlignment = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QTextStream
  * @name Ok
  * @see QTextStream#Status
  * @type Number
  */
QTextStream.Ok = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextStream
  * @name ReadPastEnd
  * @see QTextStream#Status
  * @type Number
  */
QTextStream.ReadPastEnd = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextStream
  * @name ReadCorruptData
  * @see QTextStream#Status
  * @type Number
  */
QTextStream.ReadCorruptData = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QTextStream
  * @name WriteFailed
  * @see QTextStream#Status
  * @type Number
  */
QTextStream.WriteFailed = 0x3;

/**
  * @constructor 
  * @memberOf QTextStream
  * @name Status
  */
QTextStream.Status = function(value){;};



/**
  * @name atEnd
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Boolean}
  */
QTextStream.prototype.atEnd = function(){return new Boolean();};

/**
  * @name autoDetectUnicode
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Boolean}
  */
QTextStream.prototype.autoDetectUnicode = function(){return new Boolean();};

/**
  * @name codec
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QTextCodec}
  */
QTextStream.prototype.codec = function(){return new QTextCodec();};

/**
  * @name device
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QIODevice}
  */
QTextStream.prototype.device = function(){return new QIODevice();};

/**
  * @name fieldAlignment
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QTextStream.FieldAlignment}
  */
QTextStream.prototype.fieldAlignment = function(){return new QTextStream.FieldAlignment();};

/**
  * @name fieldWidth
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Numeric}
  */
QTextStream.prototype.fieldWidth = function(){return new Numeric();};

/**
  * @name flush
  * @function
  * @memberOf QTextStream.prototype
  * @returns {undefined}
  */
QTextStream.prototype.flush = function(){return undefined;};

/**
  * @name generateByteOrderMark
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Boolean}
  */
QTextStream.prototype.generateByteOrderMark = function(){return new Boolean();};

/**
  * @name integerBase
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Numeric}
  */
QTextStream.prototype.integerBase = function(){return new Numeric();};

/**
  * @name locale
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QLocale}
  */
QTextStream.prototype.locale = function(){return new QLocale();};

/**
  * @name numberFlags
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QTextStream.NumberFlags}
  */
QTextStream.prototype.numberFlags = function(){return new QTextStream.NumberFlags();};

/**
  * @name padChar
  * @function
  * @memberOf QTextStream.prototype
  * @returns {String}
  */
QTextStream.prototype.padChar = function(){return new String();};

/**
  * @name pos
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Numeric}
  */
QTextStream.prototype.pos = function(){return new Numeric();};

/**
  * @name read
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} maxlen
  * @returns {String}
  */
QTextStream.prototype.read = function(maxlen){return new String();};

/**
  * @name readAll
  * @function
  * @memberOf QTextStream.prototype
  * @returns {String}
  */
QTextStream.prototype.readAll = function(){return new String();};

/**
  * @name readByte
  * @function
  * @memberOf QTextStream.prototype
  * @param {String} ch
  * @returns {QTextStream}
  */
QTextStream.prototype.readByte = function(ch){return new QTextStream();};

/**
  * @name readDouble
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} f
  * @returns {QTextStream}
  */
QTextStream.prototype.readDouble = function(f){return new QTextStream();};

/**
  * @name readFloat
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} f
  * @returns {QTextStream}
  */
QTextStream.prototype.readFloat = function(f){return new QTextStream();};

/**
  * @name readInt
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.readInt = function(i){return new QTextStream();};

/**
  * @name readLine
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} maxlen
  * @returns {String}
  */
QTextStream.prototype.readLine = function(maxlen){return new String();};

/**
  * @name readLongLong
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.readLongLong = function(i){return new QTextStream();};

/**
  * @name readShort
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.readShort = function(i){return new QTextStream();};

/**
  * @name readUInt
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.readUInt = function(i){return new QTextStream();};

/**
  * @name readUShort
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.readUShort = function(i){return new QTextStream();};

/**
  * @name realNumberNotation
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QTextStream.RealNumberNotation}
  */
QTextStream.prototype.realNumberNotation = function(){return new QTextStream.RealNumberNotation();};

/**
  * @name realNumberPrecision
  * @function
  * @memberOf QTextStream.prototype
  * @returns {Numeric}
  */
QTextStream.prototype.realNumberPrecision = function(){return new Numeric();};

/**
  * @name reset
  * @function
  * @memberOf QTextStream.prototype
  * @returns {undefined}
  */
QTextStream.prototype.reset = function(){return undefined;};

/**
  * @name resetStatus
  * @function
  * @memberOf QTextStream.prototype
  * @returns {undefined}
  */
QTextStream.prototype.resetStatus = function(){return undefined;};

/**
  * @name seek
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} pos
  * @returns {Boolean}
  */
QTextStream.prototype.seek = function(pos){return new Boolean();};

/**
  * @name setAutoDetectUnicode
  * @function
  * @memberOf QTextStream.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QTextStream.prototype.setAutoDetectUnicode = function(enabled){return undefined;};

/**
  * @name setCodec
  * @function
  * @memberOf QTextStream.prototype
  * @param {QTextCodec} codec
  * @returns {undefined}
  */
QTextStream.prototype.setCodec = function(codec){return undefined;};

/**
  * @name setDevice
  * @function
  * @memberOf QTextStream.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QTextStream.prototype.setDevice = function(device){return undefined;};

/**
  * @name setFieldAlignment
  * @function
  * @memberOf QTextStream.prototype
  * @param {QTextStream.FieldAlignment} alignment
  * @returns {undefined}
  */
QTextStream.prototype.setFieldAlignment = function(alignment){return undefined;};

/**
  * @name setFieldWidth
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} width
  * @returns {undefined}
  */
QTextStream.prototype.setFieldWidth = function(width){return undefined;};

/**
  * @name setGenerateByteOrderMark
  * @function
  * @memberOf QTextStream.prototype
  * @param {Boolean} generate
  * @returns {undefined}
  */
QTextStream.prototype.setGenerateByteOrderMark = function(generate){return undefined;};

/**
  * @name setIntegerBase
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} base
  * @returns {undefined}
  */
QTextStream.prototype.setIntegerBase = function(base){return undefined;};

/**
  * @name setLocale
  * @function
  * @memberOf QTextStream.prototype
  * @param {QLocale} locale
  * @returns {undefined}
  */
QTextStream.prototype.setLocale = function(locale){return undefined;};

/**
  * @name setNumberFlags
  * @function
  * @memberOf QTextStream.prototype
  * @param {QTextStream.NumberFlags} flags
  * @returns {undefined}
  */
QTextStream.prototype.setNumberFlags = function(flags){return undefined;};

/**
  * @name setPadChar
  * @function
  * @memberOf QTextStream.prototype
  * @param {String} ch
  * @returns {undefined}
  */
QTextStream.prototype.setPadChar = function(ch){return undefined;};

/**
  * @name setRealNumberNotation
  * @function
  * @memberOf QTextStream.prototype
  * @param {QTextStream.RealNumberNotation} notation
  * @returns {undefined}
  */
QTextStream.prototype.setRealNumberNotation = function(notation){return undefined;};

/**
  * @name setRealNumberPrecision
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} precision
  * @returns {undefined}
  */
QTextStream.prototype.setRealNumberPrecision = function(precision){return undefined;};

/**
  * @name setStatus
  * @function
  * @memberOf QTextStream.prototype
  * @param {QSettings.Status} status
  * @returns {undefined}
  */
QTextStream.prototype.setStatus = function(status){return undefined;};

/**
  * @name skipWhiteSpace
  * @function
  * @memberOf QTextStream.prototype
  * @returns {undefined}
  */
QTextStream.prototype.skipWhiteSpace = function(){return undefined;};

/**
  * @name status
  * @function
  * @memberOf QTextStream.prototype
  * @returns {QSettings.Status}
  */
QTextStream.prototype.status = function(){return new QSettings.Status();};

/**
  * @name writeBoolean
  * @function
  * @memberOf QTextStream.prototype
  * @param {Boolean} b
  * @returns {QTextStream}
  */
QTextStream.prototype.writeBoolean = function(b){return new QTextStream();};

/**
  * @name writeByte
  * @function
  * @memberOf QTextStream.prototype
  * @param {String} ch
  * @returns {QTextStream}
  */
QTextStream.prototype.writeByte = function(ch){return new QTextStream();};

/**
  * @name writeByteArray
  * @function
  * @memberOf QTextStream.prototype
  * @param {QByteArray} array
  * @returns {QTextStream}
  */
QTextStream.prototype.writeByteArray = function(array){return new QTextStream();};

/**
  * @name writeDouble
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} f
  * @returns {QTextStream}
  */
QTextStream.prototype.writeDouble = function(f){return new QTextStream();};

/**
  * @name writeFloat
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} f
  * @returns {QTextStream}
  */
QTextStream.prototype.writeFloat = function(f){return new QTextStream();};

/**
  * @name writeInt
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.writeInt = function(i){return new QTextStream();};

/**
  * @name writeShort
  * @function
  * @memberOf QTextStream.prototype
  * @param {Numeric} i
  * @returns {QTextStream}
  */
QTextStream.prototype.writeShort = function(i){return new QTextStream();};

/**
  * @name writeString
  * @function
  * @memberOf QTextStream.prototype
  * @param {String} s
  * @returns {QTextStream}
  */
QTextStream.prototype.writeString = function(s){return new QTextStream();};

