/**
  * @name QNetworkDiskCache
  * @constructor
  * @extends QAbstractNetworkCache
  * @param {QObject} parent
  */
function QNetworkDiskCache(parent){return undefined;};

QNetworkDiskCache.prototype = new QAbstractNetworkCache();

/**
  * @name cacheDirectory
  * @function
  * @memberOf QNetworkDiskCache.prototype
  * @returns {String}
  */
QNetworkDiskCache.prototype.cacheDirectory = function(){return new String();};

/**
  * @name fileMetaData
  * @function
  * @memberOf QNetworkDiskCache.prototype
  * @param {String} fileName
  * @returns {QNetworkCacheMetaData}
  */
QNetworkDiskCache.prototype.fileMetaData = function(fileName){return new QNetworkCacheMetaData();};

/**
  * @name maximumCacheSize
  * @function
  * @memberOf QNetworkDiskCache.prototype
  * @returns {Numeric}
  */
QNetworkDiskCache.prototype.maximumCacheSize = function(){return new Numeric();};

/**
  * @name setCacheDirectory
  * @function
  * @memberOf QNetworkDiskCache.prototype
  * @param {String} cacheDir
  * @returns {undefined}
  */
QNetworkDiskCache.prototype.setCacheDirectory = function(cacheDir){return undefined;};

/**
  * @name setMaximumCacheSize
  * @function
  * @memberOf QNetworkDiskCache.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QNetworkDiskCache.prototype.setMaximumCacheSize = function(size){return undefined;};

