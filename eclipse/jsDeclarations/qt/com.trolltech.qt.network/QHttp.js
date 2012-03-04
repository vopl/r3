/**
  * @name QHttp
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QHttp(parent){return undefined;};

/**
  * @name QHttp^1
  * @constructor
  * @extends QObject
  * @param {String} hostname
  * @param {QHttp.ConnectionMode} mode
  * @param {Numeric} port
  * @param {QObject} parent
  */
function QHttp(hostname, mode, port, parent){return undefined;};

/**
  * @name QHttp^2
  * @constructor
  * @extends QObject
  * @param {String} hostname
  * @param {Numeric} port
  * @param {QObject} parent
  */
function QHttp(hostname, port, parent){return undefined;};

QHttp.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QHttp
  * @name NoError
  * @see QHttp#Error
  * @type Number
  */
QHttp.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHttp
  * @name UnknownError
  * @see QHttp#Error
  * @type Number
  */
QHttp.UnknownError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QHttp
  * @name HostNotFound
  * @see QHttp#Error
  * @type Number
  */
QHttp.HostNotFound = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QHttp
  * @name ConnectionRefused
  * @see QHttp#Error
  * @type Number
  */
QHttp.ConnectionRefused = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QHttp
  * @name UnexpectedClose
  * @see QHttp#Error
  * @type Number
  */
QHttp.UnexpectedClose = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QHttp
  * @name InvalidResponseHeader
  * @see QHttp#Error
  * @type Number
  */
QHttp.InvalidResponseHeader = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QHttp
  * @name WrongContentLength
  * @see QHttp#Error
  * @type Number
  */
QHttp.WrongContentLength = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QHttp
  * @name Aborted
  * @see QHttp#Error
  * @type Number
  */
QHttp.Aborted = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QHttp
  * @name AuthenticationRequiredError
  * @see QHttp#Error
  * @type Number
  */
QHttp.AuthenticationRequiredError = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QHttp
  * @name ProxyAuthenticationRequiredError
  * @see QHttp#Error
  * @type Number
  */
QHttp.ProxyAuthenticationRequiredError = 0x9;

/**
  * @constructor 
  * @memberOf QHttp
  * @name Error
  */
QHttp.Error = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QHttp
  * @name ConnectionModeHttp
  * @see QHttp#ConnectionMode
  * @type Number
  */
QHttp.ConnectionModeHttp = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHttp
  * @name ConnectionModeHttps
  * @see QHttp#ConnectionMode
  * @type Number
  */
QHttp.ConnectionModeHttps = 0x1;

/**
  * @constructor 
  * @memberOf QHttp
  * @name ConnectionMode
  */
QHttp.ConnectionMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QHttp
  * @name Unconnected
  * @see QHttp#State
  * @type Number
  */
QHttp.Unconnected = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHttp
  * @name HostLookup
  * @see QHttp#State
  * @type Number
  */
QHttp.HostLookup = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QHttp
  * @name Connecting
  * @see QHttp#State
  * @type Number
  */
QHttp.Connecting = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QHttp
  * @name Sending
  * @see QHttp#State
  * @type Number
  */
QHttp.Sending = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QHttp
  * @name Reading
  * @see QHttp#State
  * @type Number
  */
QHttp.Reading = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QHttp
  * @name Connected
  * @see QHttp#State
  * @type Number
  */
QHttp.Connected = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QHttp
  * @name Closing
  * @see QHttp#State
  * @type Number
  */
QHttp.Closing = 0x6;

/**
  * @constructor 
  * @memberOf QHttp
  * @name State
  */
QHttp.State = function(value){;};



/**
  * @name bytesAvailable
  * @function
  * @memberOf QHttp.prototype
  * @returns {Numeric}
  */
QHttp.prototype.bytesAvailable = function(){return new Numeric();};

/**
  * @name clearPendingRequests
  * @function
  * @memberOf QHttp.prototype
  * @returns {undefined}
  */
QHttp.prototype.clearPendingRequests = function(){return undefined;};

/**
  * @name close
  * @function
  * @memberOf QHttp.prototype
  * @returns {Numeric}
  */
QHttp.prototype.close = function(){return new Numeric();};

/**
  * @name currentDestinationDevice
  * @function
  * @memberOf QHttp.prototype
  * @returns {QIODevice}
  */
QHttp.prototype.currentDestinationDevice = function(){return new QIODevice();};

/**
  * @name currentId
  * @function
  * @memberOf QHttp.prototype
  * @returns {Numeric}
  */
QHttp.prototype.currentId = function(){return new Numeric();};

/**
  * @name currentRequest
  * @function
  * @memberOf QHttp.prototype
  * @returns {QHttpRequestHeader}
  */
QHttp.prototype.currentRequest = function(){return new QHttpRequestHeader();};

/**
  * @name currentSourceDevice
  * @function
  * @memberOf QHttp.prototype
  * @returns {QIODevice}
  */
QHttp.prototype.currentSourceDevice = function(){return new QIODevice();};

/**
  * @name error
  * @function
  * @memberOf QHttp.prototype
  * @returns {QStateMachine.Error}
  */
QHttp.prototype.error = function(){return new QStateMachine.Error();};

/**
  * @name errorString
  * @function
  * @memberOf QHttp.prototype
  * @returns {String}
  */
QHttp.prototype.errorString = function(){return new String();};

/**
  * @name get
  * @function
  * @memberOf QHttp.prototype
  * @param {String} path
  * @param {QIODevice} to
  * @returns {Numeric}
  */
QHttp.prototype.get = function(path, to){return new Numeric();};

/**
  * @name hasPendingRequests
  * @function
  * @memberOf QHttp.prototype
  * @returns {Boolean}
  */
QHttp.prototype.hasPendingRequests = function(){return new Boolean();};

/**
  * @name head
  * @function
  * @memberOf QHttp.prototype
  * @param {String} path
  * @returns {Numeric}
  */
QHttp.prototype.head = function(path){return new Numeric();};

/**
  * @name lastResponse
  * @function
  * @memberOf QHttp.prototype
  * @returns {QHttpResponseHeader}
  */
QHttp.prototype.lastResponse = function(){return new QHttpResponseHeader();};

/**
  * @name post
  * @function
  * @memberOf QHttp.prototype
  * @param {String} path
  * @param {QIODevice} data
  * @param {QIODevice} to
  * @returns {Numeric}
  */
QHttp.prototype.post = function(path, data, to){return new Numeric();};

/**
  * @name read
  * @function
  * @memberOf QHttp.prototype
  * @param {String} data
  * @param {Numeric} maxlen
  * @returns {Numeric}
  */
QHttp.prototype.read = function(data, maxlen){return new Numeric();};

/**
  * @name readAll
  * @function
  * @memberOf QHttp.prototype
  * @returns {QByteArray}
  */
QHttp.prototype.readAll = function(){return new QByteArray();};

/**
  * @name request
  * @function
  * @memberOf QHttp.prototype
  * @param {QHttpRequestHeader} header
  * @param {QIODevice} device
  * @param {QIODevice} to
  * @returns {Numeric}
  */
QHttp.prototype.request = function(header, device, to){return new Numeric();};

/**
  * @name setHost
  * @function
  * @memberOf QHttp.prototype
  * @param {String} hostname
  * @param {QHttp.ConnectionMode} mode
  * @param {Numeric} port
  * @returns {Numeric}
  */
QHttp.prototype.setHost = function(hostname, mode, port){return new Numeric();};

/**
  * @name setProxy
  * @function
  * @memberOf QHttp.prototype
  * @param {QNetworkProxy} proxy
  * @returns {Numeric}
  */
QHttp.prototype.setProxy = function(proxy){return new Numeric();};

/**
  * @name setSocket
  * @function
  * @memberOf QHttp.prototype
  * @param {QTcpSocket} socket
  * @returns {Numeric}
  */
QHttp.prototype.setSocket = function(socket){return new Numeric();};

/**
  * @name setUser
  * @function
  * @memberOf QHttp.prototype
  * @param {String} username
  * @param {String} password
  * @returns {Numeric}
  */
QHttp.prototype.setUser = function(username, password){return new Numeric();};

/**
  * @name state
  * @function
  * @memberOf QHttp.prototype
  * @returns {QTimeLine.State}
  */
QHttp.prototype.state = function(){return new QTimeLine.State();};

