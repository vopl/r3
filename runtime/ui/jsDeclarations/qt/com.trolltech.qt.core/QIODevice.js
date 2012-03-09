/**
  * @name QIODevice
  * @constructor
  * @extends QObject
  */
function QIODevice(){return undefined;};

/**
  * @name QIODevice^1
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QIODevice(parent){return undefined;};

QIODevice.prototype = new QObject();

/**
  * @default 0x0000
  * @constant
  * @memberOf QIODevice
  * @name NotOpen
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.NotOpen = 0x0;

/**
  * @default 0x0001
  * @constant
  * @memberOf QIODevice
  * @name ReadOnly
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.ReadOnly = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QIODevice
  * @name WriteOnly
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.WriteOnly = 0x2;

/**
  * @default ReadOnly|WriteOnly
  * @constant
  * @memberOf QIODevice
  * @name ReadWrite
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.ReadWrite = 0x3;

/**
  * @default 0x0004
  * @constant
  * @memberOf QIODevice
  * @name Append
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.Append = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QIODevice
  * @name Truncate
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.Truncate = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QIODevice
  * @name Text
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.Text = 0x10;

/**
  * @default 0x0020
  * @constant
  * @memberOf QIODevice
  * @name Unbuffered
  * @see QIODevice#OpenMode
  * @see QIODevice#OpenModeFlag
  * @type Number
  */
QIODevice.Unbuffered = 0x20;

/**
  * @constructor 
  * @memberOf QIODevice
  * @name OpenModeFlag
  */
QIODevice.OpenModeFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QIODevice
  * @name OpenMode
  */
QIODevice.OpenMode = function(value1, value2 /*, ...*/){;};


/**
  * @name atEnd
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.atEnd = function(){return new Boolean();};

/**
  * @name bytesAvailable
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Numeric}
  */
QIODevice.prototype.bytesAvailable = function(){return new Numeric();};

/**
  * @name bytesToWrite
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Numeric}
  */
QIODevice.prototype.bytesToWrite = function(){return new Numeric();};

/**
  * @name canReadLine
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.canReadLine = function(){return new Boolean();};

/**
  * @name close
  * @function
  * @memberOf QIODevice.prototype
  * @returns {undefined}
  */
QIODevice.prototype.close = function(){return undefined;};

/**
  * @name errorString
  * @function
  * @memberOf QIODevice.prototype
  * @returns {String}
  */
QIODevice.prototype.errorString = function(){return new String();};

/**
  * @name getChar
  * @function
  * @memberOf QIODevice.prototype
  * @param {String} c
  * @returns {Boolean}
  */
QIODevice.prototype.getChar = function(c){return new Boolean();};

/**
  * @name isOpen
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.isOpen = function(){return new Boolean();};

/**
  * @name isReadable
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.isReadable = function(){return new Boolean();};

/**
  * @name isSequential
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.isSequential = function(){return new Boolean();};

/**
  * @name isTextModeEnabled
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.isTextModeEnabled = function(){return new Boolean();};

/**
  * @name isWritable
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.isWritable = function(){return new Boolean();};

/**
  * @name open
  * @function
  * @memberOf QIODevice.prototype
  * @param {QIODevice.OpenMode} mode
  * @returns {Boolean}
  */
QIODevice.prototype.open = function(mode){return new Boolean();};

/**
  * @name openMode
  * @function
  * @memberOf QIODevice.prototype
  * @returns {QIODevice.OpenMode}
  */
QIODevice.prototype.openMode = function(){return new QIODevice.OpenMode();};

/**
  * @name peek
  * @function
  * @memberOf QIODevice.prototype
  * @param {Numeric} maxlen
  * @returns {QByteArray}
  */
QIODevice.prototype.peek = function(maxlen){return new QByteArray();};

/**
  * @name pos
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Numeric}
  */
QIODevice.prototype.pos = function(){return new Numeric();};

/**
  * @name putChar
  * @function
  * @memberOf QIODevice.prototype
  * @param {String} c
  * @returns {Boolean}
  */
QIODevice.prototype.putChar = function(c){return new Boolean();};

/**
  * @name read
  * @function
  * @memberOf QIODevice.prototype
  * @param {Numeric} maxlen
  * @returns {QByteArray}
  */
QIODevice.prototype.read = function(maxlen){return new QByteArray();};

/**
  * @name readAll
  * @function
  * @memberOf QIODevice.prototype
  * @returns {QByteArray}
  */
QIODevice.prototype.readAll = function(){return new QByteArray();};

/**
  * @name readLine
  * @function
  * @memberOf QIODevice.prototype
  * @param {Numeric} maxlen
  * @returns {QByteArray}
  */
QIODevice.prototype.readLine = function(maxlen){return new QByteArray();};

/**
  * @name reset
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Boolean}
  */
QIODevice.prototype.reset = function(){return new Boolean();};

/**
  * @name seek
  * @function
  * @memberOf QIODevice.prototype
  * @param {Numeric} pos
  * @returns {Boolean}
  */
QIODevice.prototype.seek = function(pos){return new Boolean();};

/**
  * @name setTextModeEnabled
  * @function
  * @memberOf QIODevice.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QIODevice.prototype.setTextModeEnabled = function(enabled){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QIODevice.prototype
  * @returns {Numeric}
  */
QIODevice.prototype.size = function(){return new Numeric();};

/**
  * @name ungetChar
  * @function
  * @memberOf QIODevice.prototype
  * @param {String} c
  * @returns {undefined}
  */
QIODevice.prototype.ungetChar = function(c){return undefined;};

/**
  * @name waitForBytesWritten
  * @function
  * @memberOf QIODevice.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QIODevice.prototype.waitForBytesWritten = function(msecs){return new Boolean();};

/**
  * @name waitForReadyRead
  * @function
  * @memberOf QIODevice.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QIODevice.prototype.waitForReadyRead = function(msecs){return new Boolean();};

/**
  * @name write
  * @function
  * @memberOf QIODevice.prototype
  * @param {QByteArray} data
  * @returns {Numeric}
  */
QIODevice.prototype.write = function(data){return new Numeric();};

