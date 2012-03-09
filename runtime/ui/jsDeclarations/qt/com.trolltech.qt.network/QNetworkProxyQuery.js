/**
  * @name QNetworkProxyQuery
  * @constructor
  */
function QNetworkProxyQuery(){return undefined;};

/**
  * @name QNetworkProxyQuery^1
  * @constructor
  * @param {QNetworkProxyQuery} other
  */
function QNetworkProxyQuery(other){return undefined;};

/**
  * @name QNetworkProxyQuery^2
  * @constructor
  * @param {String} hostname
  * @param {Numeric} port
  * @param {String} protocolTag
  * @param {QNetworkProxyQuery.QueryType} queryType
  */
function QNetworkProxyQuery(hostname, port, protocolTag, queryType){return undefined;};

/**
  * @name QNetworkProxyQuery^3
  * @constructor
  * @param {QUrl} requestUrl
  * @param {QNetworkProxyQuery.QueryType} queryType
  */
function QNetworkProxyQuery(requestUrl, queryType){return undefined;};

/**
  * @name QNetworkProxyQuery^4
  * @constructor
  * @param {Numeric} bindPort
  * @param {String} protocolTag
  * @param {QNetworkProxyQuery.QueryType} queryType
  */
function QNetworkProxyQuery(bindPort, protocolTag, queryType){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QNetworkProxyQuery
  * @name TcpSocket
  * @see QNetworkProxyQuery#QueryType
  * @type Number
  */
QNetworkProxyQuery.TcpSocket = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkProxyQuery
  * @name UdpSocket
  * @see QNetworkProxyQuery#QueryType
  * @type Number
  */
QNetworkProxyQuery.UdpSocket = 0x1;

/**
  * @default 100
  * @constant
  * @memberOf QNetworkProxyQuery
  * @name TcpServer
  * @see QNetworkProxyQuery#QueryType
  * @type Number
  */
QNetworkProxyQuery.TcpServer = 0x64;

/**
  * @default 0x65
  * @constant
  * @memberOf QNetworkProxyQuery
  * @name UrlRequest
  * @see QNetworkProxyQuery#QueryType
  * @type Number
  */
QNetworkProxyQuery.UrlRequest = 0x65;

/**
  * @constructor 
  * @memberOf QNetworkProxyQuery
  * @name QueryType
  */
QNetworkProxyQuery.QueryType = function(value){;};



/**
  * @name localPort
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @returns {Numeric}
  */
QNetworkProxyQuery.prototype.localPort = function(){return new Numeric();};

/**
  * @name operator_equal
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {QNetworkProxyQuery} other
  * @returns {Boolean}
  */
QNetworkProxyQuery.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name peerHostName
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @returns {String}
  */
QNetworkProxyQuery.prototype.peerHostName = function(){return new String();};

/**
  * @name peerPort
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @returns {Numeric}
  */
QNetworkProxyQuery.prototype.peerPort = function(){return new Numeric();};

/**
  * @name protocolTag
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @returns {String}
  */
QNetworkProxyQuery.prototype.protocolTag = function(){return new String();};

/**
  * @name queryType
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @returns {QNetworkProxyQuery.QueryType}
  */
QNetworkProxyQuery.prototype.queryType = function(){return new QNetworkProxyQuery.QueryType();};

/**
  * @name setLocalPort
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {Numeric} port
  * @returns {undefined}
  */
QNetworkProxyQuery.prototype.setLocalPort = function(port){return undefined;};

/**
  * @name setPeerHostName
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {String} hostname
  * @returns {undefined}
  */
QNetworkProxyQuery.prototype.setPeerHostName = function(hostname){return undefined;};

/**
  * @name setPeerPort
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {Numeric} port
  * @returns {undefined}
  */
QNetworkProxyQuery.prototype.setPeerPort = function(port){return undefined;};

/**
  * @name setProtocolTag
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {String} protocolTag
  * @returns {undefined}
  */
QNetworkProxyQuery.prototype.setProtocolTag = function(protocolTag){return undefined;};

/**
  * @name setQueryType
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {QNetworkProxyQuery.QueryType} type
  * @returns {undefined}
  */
QNetworkProxyQuery.prototype.setQueryType = function(type){return undefined;};

/**
  * @name setUrl
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @param {QUrl} url
  * @returns {undefined}
  */
QNetworkProxyQuery.prototype.setUrl = function(url){return undefined;};

/**
  * @name url
  * @function
  * @memberOf QNetworkProxyQuery.prototype
  * @returns {QUrl}
  */
QNetworkProxyQuery.prototype.url = function(){return new QUrl();};

