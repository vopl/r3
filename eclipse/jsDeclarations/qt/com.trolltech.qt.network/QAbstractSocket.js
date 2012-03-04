/**
  * @name QAbstractSocket
  * @constructor
  * @extends QIODevice
  * @param {QAbstractSocket.SocketType} socketType
  * @param {QObject} parent
  */
function QAbstractSocket(socketType, parent){return undefined;};

QAbstractSocket.prototype = new QIODevice();

/**
  * @default -1
  * @constant
  * @memberOf QAbstractSocket
  * @name UnknownSocketType
  * @see QAbstractSocket#SocketType
  * @type Number
  */
QAbstractSocket.UnknownSocketType = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSocket
  * @name TcpSocket
  * @see QAbstractSocket#SocketType
  * @type Number
  */
QAbstractSocket.TcpSocket = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSocket
  * @name UdpSocket
  * @see QAbstractSocket#SocketType
  * @type Number
  */
QAbstractSocket.UdpSocket = 0x1;

/**
  * @constructor 
  * @memberOf QAbstractSocket
  * @name SocketType
  */
QAbstractSocket.SocketType = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QAbstractSocket
  * @name UnknownSocketError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.UnknownSocketError = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSocket
  * @name ConnectionRefusedError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ConnectionRefusedError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSocket
  * @name RemoteHostClosedError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.RemoteHostClosedError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractSocket
  * @name HostNotFoundError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.HostNotFoundError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractSocket
  * @name SocketAccessError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.SocketAccessError = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAbstractSocket
  * @name SocketResourceError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.SocketResourceError = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QAbstractSocket
  * @name SocketTimeoutError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.SocketTimeoutError = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QAbstractSocket
  * @name DatagramTooLargeError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.DatagramTooLargeError = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QAbstractSocket
  * @name NetworkError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.NetworkError = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QAbstractSocket
  * @name AddressInUseError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.AddressInUseError = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QAbstractSocket
  * @name SocketAddressNotAvailableError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.SocketAddressNotAvailableError = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QAbstractSocket
  * @name UnsupportedSocketOperationError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.UnsupportedSocketOperationError = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QAbstractSocket
  * @name UnfinishedSocketOperationError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.UnfinishedSocketOperationError = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QAbstractSocket
  * @name ProxyAuthenticationRequiredError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ProxyAuthenticationRequiredError = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QAbstractSocket
  * @name SslHandshakeFailedError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.SslHandshakeFailedError = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QAbstractSocket
  * @name ProxyConnectionRefusedError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ProxyConnectionRefusedError = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QAbstractSocket
  * @name ProxyConnectionClosedError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ProxyConnectionClosedError = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QAbstractSocket
  * @name ProxyConnectionTimeoutError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ProxyConnectionTimeoutError = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QAbstractSocket
  * @name ProxyNotFoundError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ProxyNotFoundError = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QAbstractSocket
  * @name ProxyProtocolError
  * @see QAbstractSocket#SocketError
  * @type Number
  */
QAbstractSocket.ProxyProtocolError = 0x12;

/**
  * @constructor 
  * @memberOf QAbstractSocket
  * @name SocketError
  */
QAbstractSocket.SocketError = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QAbstractSocket
  * @name UnknownNetworkLayerProtocol
  * @see QAbstractSocket#NetworkLayerProtocol
  * @type Number
  */
QAbstractSocket.UnknownNetworkLayerProtocol = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSocket
  * @name IPv4Protocol
  * @see QAbstractSocket#NetworkLayerProtocol
  * @type Number
  */
QAbstractSocket.IPv4Protocol = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSocket
  * @name IPv6Protocol
  * @see QAbstractSocket#NetworkLayerProtocol
  * @type Number
  */
QAbstractSocket.IPv6Protocol = 0x1;

/**
  * @constructor 
  * @memberOf QAbstractSocket
  * @name NetworkLayerProtocol
  */
QAbstractSocket.NetworkLayerProtocol = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSocket
  * @name LowDelayOption
  * @see QAbstractSocket#SocketOption
  * @type Number
  */
QAbstractSocket.LowDelayOption = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSocket
  * @name KeepAliveOption
  * @see QAbstractSocket#SocketOption
  * @type Number
  */
QAbstractSocket.KeepAliveOption = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractSocket
  * @name MulticastTtlOption
  * @see QAbstractSocket#SocketOption
  * @type Number
  */
QAbstractSocket.MulticastTtlOption = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractSocket
  * @name MulticastLoopbackOption
  * @see QAbstractSocket#SocketOption
  * @type Number
  */
QAbstractSocket.MulticastLoopbackOption = 0x3;

/**
  * @constructor 
  * @memberOf QAbstractSocket
  * @name SocketOption
  */
QAbstractSocket.SocketOption = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QAbstractSocket
  * @name UnconnectedState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.UnconnectedState = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QAbstractSocket
  * @name HostLookupState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.HostLookupState = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QAbstractSocket
  * @name ConnectingState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.ConnectingState = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QAbstractSocket
  * @name ConnectedState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.ConnectedState = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QAbstractSocket
  * @name BoundState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.BoundState = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QAbstractSocket
  * @name ListeningState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.ListeningState = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QAbstractSocket
  * @name ClosingState
  * @see QAbstractSocket#SocketState
  * @type Number
  */
QAbstractSocket.ClosingState = 0x6;

/**
  * @constructor 
  * @memberOf QAbstractSocket
  * @name SocketState
  */
QAbstractSocket.SocketState = function(value){;};



/**
  * @name abort
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {undefined}
  */
QAbstractSocket.prototype.abort = function(){return undefined;};

/**
  * @name connectToHost
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {QHostAddress} address
  * @param {Numeric} port
  * @param {QIODevice.OpenMode} mode
  * @returns {undefined}
  */
QAbstractSocket.prototype.connectToHost = function(address, port, mode){return undefined;};

/**
  * @name disconnectFromHost
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {undefined}
  */
QAbstractSocket.prototype.disconnectFromHost = function(){return undefined;};

/**
  * @name error
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {QAbstractSocket.SocketError}
  */
QAbstractSocket.prototype.error = function(){return new QAbstractSocket.SocketError();};

/**
  * @name flush
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {Boolean}
  */
QAbstractSocket.prototype.flush = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {Boolean}
  */
QAbstractSocket.prototype.isValid = function(){return new Boolean();};

/**
  * @name localAddress
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {QHostAddress}
  */
QAbstractSocket.prototype.localAddress = function(){return new QHostAddress();};

/**
  * @name localPort
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {Numeric}
  */
QAbstractSocket.prototype.localPort = function(){return new Numeric();};

/**
  * @name peerAddress
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {QHostAddress}
  */
QAbstractSocket.prototype.peerAddress = function(){return new QHostAddress();};

/**
  * @name peerName
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {String}
  */
QAbstractSocket.prototype.peerName = function(){return new String();};

/**
  * @name peerPort
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {Numeric}
  */
QAbstractSocket.prototype.peerPort = function(){return new Numeric();};

/**
  * @name proxy
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {QNetworkProxy}
  */
QAbstractSocket.prototype.proxy = function(){return new QNetworkProxy();};

/**
  * @name readBufferSize
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {Numeric}
  */
QAbstractSocket.prototype.readBufferSize = function(){return new Numeric();};

/**
  * @name setProxy
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {QNetworkProxy} networkProxy
  * @returns {undefined}
  */
QAbstractSocket.prototype.setProxy = function(networkProxy){return undefined;};

/**
  * @name setReadBufferSize
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QAbstractSocket.prototype.setReadBufferSize = function(size){return undefined;};

/**
  * @name setSocketDescriptor
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {Numeric} socketDescriptor
  * @param {QAbstractSocket.SocketState} state
  * @param {QIODevice.OpenMode} openMode
  * @returns {Boolean}
  */
QAbstractSocket.prototype.setSocketDescriptor = function(socketDescriptor, state, openMode){return new Boolean();};

/**
  * @name setSocketOption
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {QAbstractSocket.SocketOption} option
  * @param {Object} value
  * @returns {undefined}
  */
QAbstractSocket.prototype.setSocketOption = function(option, value){return undefined;};

/**
  * @name socketDescriptor
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {Numeric}
  */
QAbstractSocket.prototype.socketDescriptor = function(){return new Numeric();};

/**
  * @name socketOption
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {QAbstractSocket.SocketOption} option
  * @returns {Object}
  */
QAbstractSocket.prototype.socketOption = function(option){return new Object();};

/**
  * @name socketType
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {QAbstractSocket.SocketType}
  */
QAbstractSocket.prototype.socketType = function(){return new QAbstractSocket.SocketType();};

/**
  * @name state
  * @function
  * @memberOf QAbstractSocket.prototype
  * @returns {QAbstractSocket.SocketState}
  */
QAbstractSocket.prototype.state = function(){return new QAbstractSocket.SocketState();};

/**
  * @name waitForConnected
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QAbstractSocket.prototype.waitForConnected = function(msecs){return new Boolean();};

/**
  * @name waitForDisconnected
  * @function
  * @memberOf QAbstractSocket.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QAbstractSocket.prototype.waitForDisconnected = function(msecs){return new Boolean();};

