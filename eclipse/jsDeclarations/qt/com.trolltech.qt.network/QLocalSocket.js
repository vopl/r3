/**
  * @name QLocalSocket
  * @constructor
  * @extends QIODevice
  * @param {QObject} parent
  */
function QLocalSocket(parent){return undefined;};

QLocalSocket.prototype = new QIODevice();

/**
  * @default QAbstractSocket::UnconnectedState
  * @constant
  * @memberOf QLocalSocket
  * @name UnconnectedState
  * @see QLocalSocket#LocalSocketState
  * @type Number
  */
QLocalSocket.UnconnectedState = 0x0;

/**
  * @default QAbstractSocket::ConnectingState
  * @constant
  * @memberOf QLocalSocket
  * @name ConnectingState
  * @see QLocalSocket#LocalSocketState
  * @type Number
  */
QLocalSocket.ConnectingState = 0x2;

/**
  * @default QAbstractSocket::ConnectedState
  * @constant
  * @memberOf QLocalSocket
  * @name ConnectedState
  * @see QLocalSocket#LocalSocketState
  * @type Number
  */
QLocalSocket.ConnectedState = 0x3;

/**
  * @default QAbstractSocket::ClosingState
  * @constant
  * @memberOf QLocalSocket
  * @name ClosingState
  * @see QLocalSocket#LocalSocketState
  * @type Number
  */
QLocalSocket.ClosingState = 0x6;

/**
  * @constructor 
  * @memberOf QLocalSocket
  * @name LocalSocketState
  */
QLocalSocket.LocalSocketState = function(value){;};



/**
  * @default QAbstractSocket::UnknownSocketError
  * @constant
  * @memberOf QLocalSocket
  * @name UnknownSocketError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.UnknownSocketError = 0xffffffff;

/**
  * @default QAbstractSocket::ConnectionRefusedError
  * @constant
  * @memberOf QLocalSocket
  * @name ConnectionRefusedError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.ConnectionRefusedError = 0x0;

/**
  * @default QAbstractSocket::RemoteHostClosedError
  * @constant
  * @memberOf QLocalSocket
  * @name PeerClosedError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.PeerClosedError = 0x1;

/**
  * @default QAbstractSocket::HostNotFoundError
  * @constant
  * @memberOf QLocalSocket
  * @name ServerNotFoundError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.ServerNotFoundError = 0x2;

/**
  * @default QAbstractSocket::SocketAccessError
  * @constant
  * @memberOf QLocalSocket
  * @name SocketAccessError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.SocketAccessError = 0x3;

/**
  * @default QAbstractSocket::SocketResourceError
  * @constant
  * @memberOf QLocalSocket
  * @name SocketResourceError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.SocketResourceError = 0x4;

/**
  * @default QAbstractSocket::SocketTimeoutError
  * @constant
  * @memberOf QLocalSocket
  * @name SocketTimeoutError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.SocketTimeoutError = 0x5;

/**
  * @default QAbstractSocket::DatagramTooLargeError
  * @constant
  * @memberOf QLocalSocket
  * @name DatagramTooLargeError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.DatagramTooLargeError = 0x6;

/**
  * @default QAbstractSocket::NetworkError
  * @constant
  * @memberOf QLocalSocket
  * @name ConnectionError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.ConnectionError = 0x7;

/**
  * @default QAbstractSocket::UnsupportedSocketOperationError
  * @constant
  * @memberOf QLocalSocket
  * @name UnsupportedSocketOperationError
  * @see QLocalSocket#LocalSocketError
  * @type Number
  */
QLocalSocket.UnsupportedSocketOperationError = 0xa;

/**
  * @constructor 
  * @memberOf QLocalSocket
  * @name LocalSocketError
  */
QLocalSocket.LocalSocketError = function(value){;};



/**
  * @name abort
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {undefined}
  */
QLocalSocket.prototype.abort = function(){return undefined;};

/**
  * @name connectToServer
  * @function
  * @memberOf QLocalSocket.prototype
  * @param {String} name
  * @param {QIODevice.OpenMode} openMode
  * @returns {undefined}
  */
QLocalSocket.prototype.connectToServer = function(name, openMode){return undefined;};

/**
  * @name disconnectFromServer
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {undefined}
  */
QLocalSocket.prototype.disconnectFromServer = function(){return undefined;};

/**
  * @name error
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {QLocalSocket.LocalSocketError}
  */
QLocalSocket.prototype.error = function(){return new QLocalSocket.LocalSocketError();};

/**
  * @name flush
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {Boolean}
  */
QLocalSocket.prototype.flush = function(){return new Boolean();};

/**
  * @name fullServerName
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {String}
  */
QLocalSocket.prototype.fullServerName = function(){return new String();};

/**
  * @name isValid
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {Boolean}
  */
QLocalSocket.prototype.isValid = function(){return new Boolean();};

/**
  * @name readBufferSize
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {Numeric}
  */
QLocalSocket.prototype.readBufferSize = function(){return new Numeric();};

/**
  * @name serverName
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {String}
  */
QLocalSocket.prototype.serverName = function(){return new String();};

/**
  * @name setReadBufferSize
  * @function
  * @memberOf QLocalSocket.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QLocalSocket.prototype.setReadBufferSize = function(size){return undefined;};

/**
  * @name setSocketDescriptor
  * @function
  * @memberOf QLocalSocket.prototype
  * @param {Numeric} socketDescriptor
  * @param {QLocalSocket.LocalSocketState} socketState
  * @param {QIODevice.OpenMode} openMode
  * @returns {Boolean}
  */
QLocalSocket.prototype.setSocketDescriptor = function(socketDescriptor, socketState, openMode){return new Boolean();};

/**
  * @name socketDescriptor
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {Numeric}
  */
QLocalSocket.prototype.socketDescriptor = function(){return new Numeric();};

/**
  * @name state
  * @function
  * @memberOf QLocalSocket.prototype
  * @returns {QLocalSocket.LocalSocketState}
  */
QLocalSocket.prototype.state = function(){return new QLocalSocket.LocalSocketState();};

/**
  * @name waitForConnected
  * @function
  * @memberOf QLocalSocket.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QLocalSocket.prototype.waitForConnected = function(msecs){return new Boolean();};

/**
  * @name waitForDisconnected
  * @function
  * @memberOf QLocalSocket.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QLocalSocket.prototype.waitForDisconnected = function(msecs){return new Boolean();};

