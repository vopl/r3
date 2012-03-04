/**
  * @name QLocalServer
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QLocalServer(parent){return undefined;};

QLocalServer.prototype = new QObject();

/**
  * @name removeServer
  * @function
  * @memberOf QLocalServer
  * @param {String} name
  * @returns {Boolean}
  */
QLocalServer.removeServer = function(name){return new Boolean();};

/**
  * @name close
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {undefined}
  */
QLocalServer.prototype.close = function(){return undefined;};

/**
  * @name errorString
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {String}
  */
QLocalServer.prototype.errorString = function(){return new String();};

/**
  * @name fullServerName
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {String}
  */
QLocalServer.prototype.fullServerName = function(){return new String();};

/**
  * @name hasPendingConnections
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {Boolean}
  */
QLocalServer.prototype.hasPendingConnections = function(){return new Boolean();};

/**
  * @name isListening
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {Boolean}
  */
QLocalServer.prototype.isListening = function(){return new Boolean();};

/**
  * @name listen
  * @function
  * @memberOf QLocalServer.prototype
  * @param {String} name
  * @returns {Boolean}
  */
QLocalServer.prototype.listen = function(name){return new Boolean();};

/**
  * @name maxPendingConnections
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {Numeric}
  */
QLocalServer.prototype.maxPendingConnections = function(){return new Numeric();};

/**
  * @name nextPendingConnection
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {QLocalSocket}
  */
QLocalServer.prototype.nextPendingConnection = function(){return new QLocalSocket();};

/**
  * @name serverError
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {QAbstractSocket.SocketError}
  */
QLocalServer.prototype.serverError = function(){return new QAbstractSocket.SocketError();};

/**
  * @name serverName
  * @function
  * @memberOf QLocalServer.prototype
  * @returns {String}
  */
QLocalServer.prototype.serverName = function(){return new String();};

/**
  * @name setMaxPendingConnections
  * @function
  * @memberOf QLocalServer.prototype
  * @param {Numeric} numConnections
  * @returns {undefined}
  */
QLocalServer.prototype.setMaxPendingConnections = function(numConnections){return undefined;};

/**
  * @name waitForNewConnection
  * @function
  * @memberOf QLocalServer.prototype
  * @param {Numeric} msec
  * @param {Boolean} timedOut
  * @returns {Boolean}
  */
QLocalServer.prototype.waitForNewConnection = function(msec, timedOut){return new Boolean();};

