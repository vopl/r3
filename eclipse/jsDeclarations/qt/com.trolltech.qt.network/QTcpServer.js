/**
  * @name QTcpServer
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QTcpServer(parent){return undefined;};

QTcpServer.prototype = new QObject();

/**
  * @name close
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {undefined}
  */
QTcpServer.prototype.close = function(){return undefined;};

/**
  * @name errorString
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {String}
  */
QTcpServer.prototype.errorString = function(){return new String();};

/**
  * @name hasPendingConnections
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {Boolean}
  */
QTcpServer.prototype.hasPendingConnections = function(){return new Boolean();};

/**
  * @name isListening
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {Boolean}
  */
QTcpServer.prototype.isListening = function(){return new Boolean();};

/**
  * @name listen
  * @function
  * @memberOf QTcpServer.prototype
  * @param {QHostAddress} address
  * @param {Numeric} port
  * @returns {Boolean}
  */
QTcpServer.prototype.listen = function(address, port){return new Boolean();};

/**
  * @name maxPendingConnections
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {Numeric}
  */
QTcpServer.prototype.maxPendingConnections = function(){return new Numeric();};

/**
  * @name nextPendingConnection
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {QTcpSocket}
  */
QTcpServer.prototype.nextPendingConnection = function(){return new QTcpSocket();};

/**
  * @name proxy
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {QNetworkProxy}
  */
QTcpServer.prototype.proxy = function(){return new QNetworkProxy();};

/**
  * @name serverAddress
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {QHostAddress}
  */
QTcpServer.prototype.serverAddress = function(){return new QHostAddress();};

/**
  * @name serverError
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {QAbstractSocket.SocketError}
  */
QTcpServer.prototype.serverError = function(){return new QAbstractSocket.SocketError();};

/**
  * @name serverPort
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {Numeric}
  */
QTcpServer.prototype.serverPort = function(){return new Numeric();};

/**
  * @name setMaxPendingConnections
  * @function
  * @memberOf QTcpServer.prototype
  * @param {Numeric} numConnections
  * @returns {undefined}
  */
QTcpServer.prototype.setMaxPendingConnections = function(numConnections){return undefined;};

/**
  * @name setProxy
  * @function
  * @memberOf QTcpServer.prototype
  * @param {QNetworkProxy} networkProxy
  * @returns {undefined}
  */
QTcpServer.prototype.setProxy = function(networkProxy){return undefined;};

/**
  * @name setSocketDescriptor
  * @function
  * @memberOf QTcpServer.prototype
  * @param {Numeric} socketDescriptor
  * @returns {Boolean}
  */
QTcpServer.prototype.setSocketDescriptor = function(socketDescriptor){return new Boolean();};

/**
  * @name socketDescriptor
  * @function
  * @memberOf QTcpServer.prototype
  * @returns {Numeric}
  */
QTcpServer.prototype.socketDescriptor = function(){return new Numeric();};

/**
  * @name waitForNewConnection
  * @function
  * @memberOf QTcpServer.prototype
  * @param {Numeric} msec
  * @param {Boolean} timedOut
  * @returns {Boolean}
  */
QTcpServer.prototype.waitForNewConnection = function(msec, timedOut){return new Boolean();};

