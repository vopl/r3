/**
  * @name QUdpSocket
  * @constructor
  * @extends QAbstractSocket
  * @param {QObject} parent
  */
function QUdpSocket(parent){return undefined;};

QUdpSocket.prototype = new QAbstractSocket();

/**
  * @default 0x0
  * @constant
  * @memberOf QUdpSocket
  * @name DefaultForPlatform
  * @see QUdpSocket#BindMode
  * @see QUdpSocket#BindFlag
  * @type Number
  */
QUdpSocket.DefaultForPlatform = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QUdpSocket
  * @name ShareAddress
  * @see QUdpSocket#BindMode
  * @see QUdpSocket#BindFlag
  * @type Number
  */
QUdpSocket.ShareAddress = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QUdpSocket
  * @name DontShareAddress
  * @see QUdpSocket#BindMode
  * @see QUdpSocket#BindFlag
  * @type Number
  */
QUdpSocket.DontShareAddress = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QUdpSocket
  * @name ReuseAddressHint
  * @see QUdpSocket#BindMode
  * @see QUdpSocket#BindFlag
  * @type Number
  */
QUdpSocket.ReuseAddressHint = 0x4;

/**
  * @constructor 
  * @memberOf QUdpSocket
  * @name BindFlag
  */
QUdpSocket.BindFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QUdpSocket
  * @name BindMode
  */
QUdpSocket.BindMode = function(value1, value2 /*, ...*/){;};


/**
  * @name bind
  * @function
  * @memberOf QUdpSocket.prototype
  * @param {QHostAddress} address
  * @param {Numeric} port
  * @returns {Boolean}
  */
QUdpSocket.prototype.bind = function(address, port){return new Boolean();};

/**
  * @name hasPendingDatagrams
  * @function
  * @memberOf QUdpSocket.prototype
  * @returns {Boolean}
  */
QUdpSocket.prototype.hasPendingDatagrams = function(){return new Boolean();};

/**
  * @name joinMulticastGroup
  * @function
  * @memberOf QUdpSocket.prototype
  * @param {QHostAddress} groupAddress
  * @returns {Boolean}
  */
QUdpSocket.prototype.joinMulticastGroup = function(groupAddress){return new Boolean();};

/**
  * @name leaveMulticastGroup
  * @function
  * @memberOf QUdpSocket.prototype
  * @param {QHostAddress} groupAddress
  * @returns {Boolean}
  */
QUdpSocket.prototype.leaveMulticastGroup = function(groupAddress){return new Boolean();};

/**
  * @name multicastInterface
  * @function
  * @memberOf QUdpSocket.prototype
  * @returns {QNetworkInterface}
  */
QUdpSocket.prototype.multicastInterface = function(){return new QNetworkInterface();};

/**
  * @name pendingDatagramSize
  * @function
  * @memberOf QUdpSocket.prototype
  * @returns {Numeric}
  */
QUdpSocket.prototype.pendingDatagramSize = function(){return new Numeric();};

/**
  * @name readDatagram
  * @function
  * @memberOf QUdpSocket.prototype
  * @param {String} data
  * @param {Numeric} maxlen
  * @param {QHostAddress} host
  * @param {Numeric} port
  * @returns {Numeric}
  */
QUdpSocket.prototype.readDatagram = function(data, maxlen, host, port){return new Numeric();};

/**
  * @name setMulticastInterface
  * @function
  * @memberOf QUdpSocket.prototype
  * @param {QNetworkInterface} iface
  * @returns {undefined}
  */
QUdpSocket.prototype.setMulticastInterface = function(iface){return undefined;};

/**
  * @name writeDatagram
  * @function
  * @memberOf QUdpSocket.prototype
  * @param {QByteArray} datagram
  * @param {QHostAddress} host
  * @param {Numeric} port
  * @returns {Numeric}
  */
QUdpSocket.prototype.writeDatagram = function(datagram, host, port){return new Numeric();};

