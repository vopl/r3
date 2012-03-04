/**
  * @name QNetworkAccessManager
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QNetworkAccessManager(parent){return undefined;};

QNetworkAccessManager.prototype = new QObject();

/**
  * @default -1
  * @constant
  * @memberOf QNetworkAccessManager
  * @name UnknownAccessibility
  * @see QNetworkAccessManager#NetworkAccessibility
  * @type Number
  */
QNetworkAccessManager.UnknownAccessibility = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf QNetworkAccessManager
  * @name NotAccessible
  * @see QNetworkAccessManager#NetworkAccessibility
  * @type Number
  */
QNetworkAccessManager.NotAccessible = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QNetworkAccessManager
  * @name Accessible
  * @see QNetworkAccessManager#NetworkAccessibility
  * @type Number
  */
QNetworkAccessManager.Accessible = 0x1;

/**
  * @constructor 
  * @memberOf QNetworkAccessManager
  * @name NetworkAccessibility
  */
QNetworkAccessManager.NetworkAccessibility = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QNetworkAccessManager
  * @name UnknownOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.UnknownOperation = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QNetworkAccessManager
  * @name HeadOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.HeadOperation = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkAccessManager
  * @name GetOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.GetOperation = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QNetworkAccessManager
  * @name PutOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.PutOperation = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QNetworkAccessManager
  * @name PostOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.PostOperation = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QNetworkAccessManager
  * @name DeleteOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.DeleteOperation = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QNetworkAccessManager
  * @name CustomOperation
  * @see QNetworkAccessManager#Operation
  * @type Number
  */
QNetworkAccessManager.CustomOperation = 0x6;

/**
  * @constructor 
  * @memberOf QNetworkAccessManager
  * @name Operation
  */
QNetworkAccessManager.Operation = function(value){;};



/**
  * @name cache
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @returns {QAbstractNetworkCache}
  */
QNetworkAccessManager.prototype.cache = function(){return new QAbstractNetworkCache();};

/**
  * @name cookieJar
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @returns {QNetworkCookieJar}
  */
QNetworkAccessManager.prototype.cookieJar = function(){return new QNetworkCookieJar();};

/**
  * @name deleteResource
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkRequest} request
  * @returns {QNetworkReply}
  */
QNetworkAccessManager.prototype.deleteResource = function(request){return new QNetworkReply();};

/**
  * @name get
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkRequest} request
  * @returns {QNetworkReply}
  */
QNetworkAccessManager.prototype.get = function(request){return new QNetworkReply();};

/**
  * @name head
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkRequest} request
  * @returns {QNetworkReply}
  */
QNetworkAccessManager.prototype.head = function(request){return new QNetworkReply();};

/**
  * @name post
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkRequest} request
  * @param {QIODevice} data
  * @returns {QNetworkReply}
  */
QNetworkAccessManager.prototype.post = function(request, data){return new QNetworkReply();};

/**
  * @name proxy
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @returns {QNetworkProxy}
  */
QNetworkAccessManager.prototype.proxy = function(){return new QNetworkProxy();};

/**
  * @name proxyFactory
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @returns {QNetworkProxyFactory}
  */
QNetworkAccessManager.prototype.proxyFactory = function(){return new QNetworkProxyFactory();};

/**
  * @name put
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkRequest} request
  * @param {QIODevice} data
  * @returns {QNetworkReply}
  */
QNetworkAccessManager.prototype.put = function(request, data){return new QNetworkReply();};

/**
  * @name sendCustomRequest
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkRequest} request
  * @param {QByteArray} verb
  * @param {QIODevice} data
  * @returns {QNetworkReply}
  */
QNetworkAccessManager.prototype.sendCustomRequest = function(request, verb, data){return new QNetworkReply();};

/**
  * @name setCache
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QAbstractNetworkCache} cache
  * @returns {undefined}
  */
QNetworkAccessManager.prototype.setCache = function(cache){return undefined;};

/**
  * @name setCookieJar
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkCookieJar} cookieJar
  * @returns {undefined}
  */
QNetworkAccessManager.prototype.setCookieJar = function(cookieJar){return undefined;};

/**
  * @name setProxy
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkProxy} proxy
  * @returns {undefined}
  */
QNetworkAccessManager.prototype.setProxy = function(proxy){return undefined;};

/**
  * @name setProxyFactory
  * @function
  * @memberOf QNetworkAccessManager.prototype
  * @param {QNetworkProxyFactory} factory
  * @returns {undefined}
  */
QNetworkAccessManager.prototype.setProxyFactory = function(factory){return undefined;};

/**
  * @name networkAccessible
  * @memberOf QNetworkAccessManager.prototype
  * @type QNetworkAccessManager.NetworkAccessibility
  */
QNetworkAccessManager.prototype.networkAccessible = new QNetworkAccessManager.NetworkAccessibility();


