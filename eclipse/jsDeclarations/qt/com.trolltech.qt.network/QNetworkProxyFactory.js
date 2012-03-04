/**
  * @name QNetworkProxyFactory
  * @constructor
  */
function QNetworkProxyFactory(){return undefined;};

/**
  * @name proxyForQuery
  * @function
  * @memberOf QNetworkProxyFactory
  * @param {QNetworkProxyQuery} query
  * @returns {Array}
  */
QNetworkProxyFactory.proxyForQuery = function(query){return new Array();};

/**
  * @name setApplicationProxyFactory
  * @function
  * @memberOf QNetworkProxyFactory
  * @param {QNetworkProxyFactory} factory
  * @returns {undefined}
  */
QNetworkProxyFactory.setApplicationProxyFactory = function(factory){return undefined;};

/**
  * @name setUseSystemConfiguration
  * @function
  * @memberOf QNetworkProxyFactory
  * @param {Boolean} enable
  * @returns {undefined}
  */
QNetworkProxyFactory.setUseSystemConfiguration = function(enable){return undefined;};

/**
  * @name systemProxyForQuery
  * @function
  * @memberOf QNetworkProxyFactory
  * @param {QNetworkProxyQuery} query
  * @returns {Array}
  */
QNetworkProxyFactory.systemProxyForQuery = function(query){return new Array();};

/**
  * @name queryProxy
  * @function
  * @memberOf QNetworkProxyFactory.prototype
  * @param {QNetworkProxyQuery} query
  * @returns {Array}
  */
QNetworkProxyFactory.prototype.queryProxy = function(query){return new Array();};

