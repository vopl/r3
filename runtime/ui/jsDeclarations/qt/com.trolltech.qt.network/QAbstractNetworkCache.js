/**
  * @class QAbstractNetworkCache from package com.trolltech.qt.network
  * @extends QObject
  */
var QAbstractNetworkCache = {};

QAbstractNetworkCache.prototype = new QObject();

/**
  * @name cacheSize
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @returns {Numeric}
  */
QAbstractNetworkCache.prototype.cacheSize = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @param {QUrl} url
  * @returns {QIODevice}
  */
QAbstractNetworkCache.prototype.data = function(url){return new QIODevice();};

/**
  * @name insert
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QAbstractNetworkCache.prototype.insert = function(device){return undefined;};

/**
  * @name metaData
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @param {QUrl} url
  * @returns {QNetworkCacheMetaData}
  */
QAbstractNetworkCache.prototype.metaData = function(url){return new QNetworkCacheMetaData();};

/**
  * @name prepare
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @param {QNetworkCacheMetaData} metaData
  * @returns {QIODevice}
  */
QAbstractNetworkCache.prototype.prepare = function(metaData){return new QIODevice();};

/**
  * @name remove
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @param {QUrl} url
  * @returns {Boolean}
  */
QAbstractNetworkCache.prototype.remove = function(url){return new Boolean();};

/**
  * @name updateMetaData
  * @function
  * @memberOf QAbstractNetworkCache.prototype
  * @param {QNetworkCacheMetaData} metaData
  * @returns {undefined}
  */
QAbstractNetworkCache.prototype.updateMetaData = function(metaData){return undefined;};

