/**
  * @name QNetworkProxy
  * @constructor
  */
function QNetworkProxy(){return undefined;};

/**
  * @name QNetworkProxy^1
  * @constructor
  * @param {QNetworkProxy.ProxyType} type
  * @param {String} hostName
  * @param {Numeric} port
  * @param {String} user
  * @param {String} password
  */
function QNetworkProxy(type, hostName, port, user, password){return undefined;};

/**
  * @name QNetworkProxy^2
  * @constructor
  * @param {QNetworkProxy} other
  */
function QNetworkProxy(other){return undefined;};

/**
  * @name applicationProxy
  * @function
  * @memberOf QNetworkProxy
  * @returns {QNetworkProxy}
  */
QNetworkProxy.applicationProxy = function(){return new QNetworkProxy();};

/**
  * @name setApplicationProxy
  * @function
  * @memberOf QNetworkProxy
  * @param {QNetworkProxy} proxy
  * @returns {undefined}
  */
QNetworkProxy.setApplicationProxy = function(proxy){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QNetworkProxy
  * @name DefaultProxy
  * @see QNetworkProxy#ProxyType
  * @type Number
  */
QNetworkProxy.DefaultProxy = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkProxy
  * @name Socks5Proxy
  * @see QNetworkProxy#ProxyType
  * @type Number
  */
QNetworkProxy.Socks5Proxy = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkProxy
  * @name NoProxy
  * @see QNetworkProxy#ProxyType
  * @type Number
  */
QNetworkProxy.NoProxy = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QNetworkProxy
  * @name HttpProxy
  * @see QNetworkProxy#ProxyType
  * @type Number
  */
QNetworkProxy.HttpProxy = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QNetworkProxy
  * @name HttpCachingProxy
  * @see QNetworkProxy#ProxyType
  * @type Number
  */
QNetworkProxy.HttpCachingProxy = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QNetworkProxy
  * @name FtpCachingProxy
  * @see QNetworkProxy#ProxyType
  * @type Number
  */
QNetworkProxy.FtpCachingProxy = 0x5;

/**
  * @constructor 
  * @memberOf QNetworkProxy
  * @name ProxyType
  */
QNetworkProxy.ProxyType = function(value){;};



/**
  * @default 0x0001
  * @constant
  * @memberOf QNetworkProxy
  * @name TunnelingCapability
  * @see QNetworkProxy#Capabilities
  * @see QNetworkProxy#Capability
  * @type Number
  */
QNetworkProxy.TunnelingCapability = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QNetworkProxy
  * @name ListeningCapability
  * @see QNetworkProxy#Capabilities
  * @see QNetworkProxy#Capability
  * @type Number
  */
QNetworkProxy.ListeningCapability = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QNetworkProxy
  * @name UdpTunnelingCapability
  * @see QNetworkProxy#Capabilities
  * @see QNetworkProxy#Capability
  * @type Number
  */
QNetworkProxy.UdpTunnelingCapability = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QNetworkProxy
  * @name CachingCapability
  * @see QNetworkProxy#Capabilities
  * @see QNetworkProxy#Capability
  * @type Number
  */
QNetworkProxy.CachingCapability = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QNetworkProxy
  * @name HostNameLookupCapability
  * @see QNetworkProxy#Capabilities
  * @see QNetworkProxy#Capability
  * @type Number
  */
QNetworkProxy.HostNameLookupCapability = 0x10;

/**
  * @constructor 
  * @memberOf QNetworkProxy
  * @name Capability
  */
QNetworkProxy.Capability = function(value){;};

/**
  * @constructor 
  * @memberOf QNetworkProxy
  * @name Capabilities
  */
QNetworkProxy.Capabilities = function(value1, value2 /*, ...*/){;};


/**
  * @name capabilities
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {QImageIOPlugin.Capabilities}
  */
QNetworkProxy.prototype.capabilities = function(){return new QImageIOPlugin.Capabilities();};

/**
  * @name hostName
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {String}
  */
QNetworkProxy.prototype.hostName = function(){return new String();};

/**
  * @name isCachingProxy
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {Boolean}
  */
QNetworkProxy.prototype.isCachingProxy = function(){return new Boolean();};

/**
  * @name isTransparentProxy
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {Boolean}
  */
QNetworkProxy.prototype.isTransparentProxy = function(){return new Boolean();};

/**
  * @name operator_equal
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {QNetworkProxy} other
  * @returns {Boolean}
  */
QNetworkProxy.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name password
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {String}
  */
QNetworkProxy.prototype.password = function(){return new String();};

/**
  * @name port
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {Numeric}
  */
QNetworkProxy.prototype.port = function(){return new Numeric();};

/**
  * @name setCapabilities
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {QImageIOPlugin.Capabilities} capab
  * @returns {undefined}
  */
QNetworkProxy.prototype.setCapabilities = function(capab){return undefined;};

/**
  * @name setHostName
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {String} hostName
  * @returns {undefined}
  */
QNetworkProxy.prototype.setHostName = function(hostName){return undefined;};

/**
  * @name setPassword
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {String} password
  * @returns {undefined}
  */
QNetworkProxy.prototype.setPassword = function(password){return undefined;};

/**
  * @name setPort
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {Numeric} port
  * @returns {undefined}
  */
QNetworkProxy.prototype.setPort = function(port){return undefined;};

/**
  * @name setType
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {QNetworkProxy.ProxyType} type
  * @returns {undefined}
  */
QNetworkProxy.prototype.setType = function(type){return undefined;};

/**
  * @name setUser
  * @function
  * @memberOf QNetworkProxy.prototype
  * @param {String} userName
  * @returns {undefined}
  */
QNetworkProxy.prototype.setUser = function(userName){return undefined;};

/**
  * @name type
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {QNetworkProxy.ProxyType}
  */
QNetworkProxy.prototype.type = function(){return new QNetworkProxy.ProxyType();};

/**
  * @name user
  * @function
  * @memberOf QNetworkProxy.prototype
  * @returns {String}
  */
QNetworkProxy.prototype.user = function(){return new String();};

