/**
  * @name QFtp
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QFtp(parent){return undefined;};

QFtp.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QFtp
  * @name Binary
  * @see QFtp#TransferType
  * @type Number
  */
QFtp.Binary = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFtp
  * @name Ascii
  * @see QFtp#TransferType
  * @type Number
  */
QFtp.Ascii = 0x1;

/**
  * @constructor 
  * @memberOf QFtp
  * @name TransferType
  */
QFtp.TransferType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFtp
  * @name NoError
  * @see QFtp#Error
  * @type Number
  */
QFtp.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFtp
  * @name UnknownError
  * @see QFtp#Error
  * @type Number
  */
QFtp.UnknownError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFtp
  * @name HostNotFound
  * @see QFtp#Error
  * @type Number
  */
QFtp.HostNotFound = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFtp
  * @name ConnectionRefused
  * @see QFtp#Error
  * @type Number
  */
QFtp.ConnectionRefused = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFtp
  * @name NotConnected
  * @see QFtp#Error
  * @type Number
  */
QFtp.NotConnected = 0x4;

/**
  * @constructor 
  * @memberOf QFtp
  * @name Error
  */
QFtp.Error = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFtp
  * @name None
  * @see QFtp#Command
  * @type Number
  */
QFtp.None = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFtp
  * @name SetTransferMode
  * @see QFtp#Command
  * @type Number
  */
QFtp.SetTransferMode = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFtp
  * @name SetProxy
  * @see QFtp#Command
  * @type Number
  */
QFtp.SetProxy = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFtp
  * @name ConnectToHost
  * @see QFtp#Command
  * @type Number
  */
QFtp.ConnectToHost = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFtp
  * @name Login
  * @see QFtp#Command
  * @type Number
  */
QFtp.Login = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QFtp
  * @name Close
  * @see QFtp#Command
  * @type Number
  */
QFtp.Close = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QFtp
  * @name List
  * @see QFtp#Command
  * @type Number
  */
QFtp.List = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QFtp
  * @name Cd
  * @see QFtp#Command
  * @type Number
  */
QFtp.Cd = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QFtp
  * @name Get
  * @see QFtp#Command
  * @type Number
  */
QFtp.Get = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QFtp
  * @name Put
  * @see QFtp#Command
  * @type Number
  */
QFtp.Put = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QFtp
  * @name Remove
  * @see QFtp#Command
  * @type Number
  */
QFtp.Remove = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QFtp
  * @name Mkdir
  * @see QFtp#Command
  * @type Number
  */
QFtp.Mkdir = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QFtp
  * @name Rmdir
  * @see QFtp#Command
  * @type Number
  */
QFtp.Rmdir = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QFtp
  * @name Rename
  * @see QFtp#Command
  * @type Number
  */
QFtp.Rename = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QFtp
  * @name RawCommand
  * @see QFtp#Command
  * @type Number
  */
QFtp.RawCommand = 0xe;

/**
  * @constructor 
  * @memberOf QFtp
  * @name Command
  */
QFtp.Command = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFtp
  * @name Active
  * @see QFtp#TransferMode
  * @type Number
  */
QFtp.Active = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFtp
  * @name Passive
  * @see QFtp#TransferMode
  * @type Number
  */
QFtp.Passive = 0x1;

/**
  * @constructor 
  * @memberOf QFtp
  * @name TransferMode
  */
QFtp.TransferMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QFtp
  * @name Unconnected
  * @see QFtp#State
  * @type Number
  */
QFtp.Unconnected = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFtp
  * @name HostLookup
  * @see QFtp#State
  * @type Number
  */
QFtp.HostLookup = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFtp
  * @name Connecting
  * @see QFtp#State
  * @type Number
  */
QFtp.Connecting = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFtp
  * @name Connected
  * @see QFtp#State
  * @type Number
  */
QFtp.Connected = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFtp
  * @name LoggedIn
  * @see QFtp#State
  * @type Number
  */
QFtp.LoggedIn = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QFtp
  * @name Closing
  * @see QFtp#State
  * @type Number
  */
QFtp.Closing = 0x5;

/**
  * @constructor 
  * @memberOf QFtp
  * @name State
  */
QFtp.State = function(value){;};



/**
  * @name bytesAvailable
  * @function
  * @memberOf QFtp.prototype
  * @returns {Numeric}
  */
QFtp.prototype.bytesAvailable = function(){return new Numeric();};

/**
  * @name cd
  * @function
  * @memberOf QFtp.prototype
  * @param {String} dir
  * @returns {Numeric}
  */
QFtp.prototype.cd = function(dir){return new Numeric();};

/**
  * @name clearPendingCommands
  * @function
  * @memberOf QFtp.prototype
  * @returns {undefined}
  */
QFtp.prototype.clearPendingCommands = function(){return undefined;};

/**
  * @name close
  * @function
  * @memberOf QFtp.prototype
  * @returns {Numeric}
  */
QFtp.prototype.close = function(){return new Numeric();};

/**
  * @name connectToHost
  * @function
  * @memberOf QFtp.prototype
  * @param {String} host
  * @param {Numeric} port
  * @returns {Numeric}
  */
QFtp.prototype.connectToHost = function(host, port){return new Numeric();};

/**
  * @name currentCommand
  * @function
  * @memberOf QFtp.prototype
  * @returns {QFtp.Command}
  */
QFtp.prototype.currentCommand = function(){return new QFtp.Command();};

/**
  * @name currentDevice
  * @function
  * @memberOf QFtp.prototype
  * @returns {QIODevice}
  */
QFtp.prototype.currentDevice = function(){return new QIODevice();};

/**
  * @name currentId
  * @function
  * @memberOf QFtp.prototype
  * @returns {Numeric}
  */
QFtp.prototype.currentId = function(){return new Numeric();};

/**
  * @name error
  * @function
  * @memberOf QFtp.prototype
  * @returns {QStateMachine.Error}
  */
QFtp.prototype.error = function(){return new QStateMachine.Error();};

/**
  * @name errorString
  * @function
  * @memberOf QFtp.prototype
  * @returns {String}
  */
QFtp.prototype.errorString = function(){return new String();};

/**
  * @name get
  * @function
  * @memberOf QFtp.prototype
  * @param {String} file
  * @param {QIODevice} dev
  * @param {QFtp.TransferType} type
  * @returns {Numeric}
  */
QFtp.prototype.get = function(file, dev, type){return new Numeric();};

/**
  * @name hasPendingCommands
  * @function
  * @memberOf QFtp.prototype
  * @returns {Boolean}
  */
QFtp.prototype.hasPendingCommands = function(){return new Boolean();};

/**
  * @name list
  * @function
  * @memberOf QFtp.prototype
  * @param {String} dir
  * @returns {Numeric}
  */
QFtp.prototype.list = function(dir){return new Numeric();};

/**
  * @name login
  * @function
  * @memberOf QFtp.prototype
  * @param {String} user
  * @param {String} password
  * @returns {Numeric}
  */
QFtp.prototype.login = function(user, password){return new Numeric();};

/**
  * @name mkdir
  * @function
  * @memberOf QFtp.prototype
  * @param {String} dir
  * @returns {Numeric}
  */
QFtp.prototype.mkdir = function(dir){return new Numeric();};

/**
  * @name put
  * @function
  * @memberOf QFtp.prototype
  * @param {QIODevice} dev
  * @param {String} file
  * @param {QFtp.TransferType} type
  * @returns {Numeric}
  */
QFtp.prototype.put = function(dev, file, type){return new Numeric();};

/**
  * @name rawCommand
  * @function
  * @memberOf QFtp.prototype
  * @param {String} command
  * @returns {Numeric}
  */
QFtp.prototype.rawCommand = function(command){return new Numeric();};

/**
  * @name read
  * @function
  * @memberOf QFtp.prototype
  * @param {String} data
  * @param {Numeric} maxlen
  * @returns {Numeric}
  */
QFtp.prototype.read = function(data, maxlen){return new Numeric();};

/**
  * @name readAll
  * @function
  * @memberOf QFtp.prototype
  * @returns {QByteArray}
  */
QFtp.prototype.readAll = function(){return new QByteArray();};

/**
  * @name remove
  * @function
  * @memberOf QFtp.prototype
  * @param {String} file
  * @returns {Numeric}
  */
QFtp.prototype.remove = function(file){return new Numeric();};

/**
  * @name rename
  * @function
  * @memberOf QFtp.prototype
  * @param {String} oldname
  * @param {String} newname
  * @returns {Numeric}
  */
QFtp.prototype.rename = function(oldname, newname){return new Numeric();};

/**
  * @name rmdir
  * @function
  * @memberOf QFtp.prototype
  * @param {String} dir
  * @returns {Numeric}
  */
QFtp.prototype.rmdir = function(dir){return new Numeric();};

/**
  * @name setProxy
  * @function
  * @memberOf QFtp.prototype
  * @param {String} host
  * @param {Numeric} port
  * @returns {Numeric}
  */
QFtp.prototype.setProxy = function(host, port){return new Numeric();};

/**
  * @name setTransferMode
  * @function
  * @memberOf QFtp.prototype
  * @param {QFtp.TransferMode} mode
  * @returns {Numeric}
  */
QFtp.prototype.setTransferMode = function(mode){return new Numeric();};

/**
  * @name state
  * @function
  * @memberOf QFtp.prototype
  * @returns {QTimeLine.State}
  */
QFtp.prototype.state = function(){return new QTimeLine.State();};

