/**
  * @name QHostAddress
  * @constructor
  */
function QHostAddress(){return undefined;};

/**
  * @name QHostAddress^1
  * @constructor
  * @param {QHostAddress.SpecialAddress} address
  */
function QHostAddress(address){return undefined;};

/**
  * @name QHostAddress^2
  * @constructor
  * @param {QHostAddress} copy
  */
function QHostAddress(copy){return undefined;};

/**
  * @name QHostAddress^3
  * @constructor
  * @param {QIPv6Address} ip6Addr
  */
function QHostAddress(ip6Addr){return undefined;};

/**
  * @name QHostAddress^4
  * @constructor
  * @param {String} address
  */
function QHostAddress(address){return undefined;};

/**
  * @name QHostAddress^5
  * @constructor
  * @param {Numeric} ip4Addr
  */
function QHostAddress(ip4Addr){return undefined;};

/**
  * @name parseSubnet
  * @function
  * @memberOf QHostAddress
  * @param {String} subnet
  * @returns {Object}
  */
QHostAddress.parseSubnet = function(subnet){return new Object();};

/**
  * @default 0x0
  * @constant
  * @memberOf QHostAddress
  * @name Null
  * @see QHostAddress#SpecialAddress
  * @type Number
  */
QHostAddress.Null = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHostAddress
  * @name Broadcast
  * @see QHostAddress#SpecialAddress
  * @type Number
  */
QHostAddress.Broadcast = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QHostAddress
  * @name LocalHost
  * @see QHostAddress#SpecialAddress
  * @type Number
  */
QHostAddress.LocalHost = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QHostAddress
  * @name LocalHostIPv6
  * @see QHostAddress#SpecialAddress
  * @type Number
  */
QHostAddress.LocalHostIPv6 = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QHostAddress
  * @name Any
  * @see QHostAddress#SpecialAddress
  * @type Number
  */
QHostAddress.Any = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QHostAddress
  * @name AnyIPv6
  * @see QHostAddress#SpecialAddress
  * @type Number
  */
QHostAddress.AnyIPv6 = 0x5;

/**
  * @constructor 
  * @memberOf QHostAddress
  * @name SpecialAddress
  */
QHostAddress.SpecialAddress = function(value){;};



/**
  * @name clear
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {undefined}
  */
QHostAddress.prototype.clear = function(){return undefined;};

/**
  * @name isInSubnet
  * @function
  * @memberOf QHostAddress.prototype
  * @param {QHostAddress} subnet
  * @param {Numeric} netmask
  * @returns {Boolean}
  */
QHostAddress.prototype.isInSubnet = function(subnet, netmask){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {Boolean}
  */
QHostAddress.prototype.isNull = function(){return new Boolean();};

/**
  * @name operator_equal
  * @function
  * @memberOf QHostAddress.prototype
  * @param {QHostAddress.SpecialAddress} address
  * @returns {Boolean}
  */
QHostAddress.prototype.operator_equal = function(address){return new Boolean();};

/**
  * @name protocol
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {QAbstractSocket.NetworkLayerProtocol}
  */
QHostAddress.prototype.protocol = function(){return new QAbstractSocket.NetworkLayerProtocol();};

/**
  * @name readFrom
  * @function
  * @memberOf QHostAddress.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QHostAddress.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name scopeId
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {String}
  */
QHostAddress.prototype.scopeId = function(){return new String();};

/**
  * @name setAddress
  * @function
  * @memberOf QHostAddress.prototype
  * @param {QIPv6Address} ip6Addr
  * @returns {undefined}
  */
QHostAddress.prototype.setAddress = function(ip6Addr){return undefined;};

/**
  * @name setScopeId
  * @function
  * @memberOf QHostAddress.prototype
  * @param {String} id
  * @returns {undefined}
  */
QHostAddress.prototype.setScopeId = function(id){return undefined;};

/**
  * @name toIPv4Address
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {Numeric}
  */
QHostAddress.prototype.toIPv4Address = function(){return new Numeric();};

/**
  * @name toIPv6Address
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {QIPv6Address}
  */
QHostAddress.prototype.toIPv6Address = function(){return new QIPv6Address();};

/**
  * @name toString
  * @function
  * @memberOf QHostAddress.prototype
  * @returns {String}
  */
QHostAddress.prototype.toString = function(){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QHostAddress.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QHostAddress.prototype.writeTo = function(arg__1){return undefined;};

