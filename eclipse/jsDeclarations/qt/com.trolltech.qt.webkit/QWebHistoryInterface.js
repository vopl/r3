/**
  * @name QWebHistoryInterface
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QWebHistoryInterface(parent){return undefined;};

QWebHistoryInterface.prototype = new QObject();

/**
  * @name defaultInterface
  * @function
  * @memberOf QWebHistoryInterface
  * @returns {QWebHistoryInterface}
  */
QWebHistoryInterface.defaultInterface = function(){return new QWebHistoryInterface();};

/**
  * @name setDefaultInterface
  * @function
  * @memberOf QWebHistoryInterface
  * @param {QWebHistoryInterface} defaultInterface
  * @returns {undefined}
  */
QWebHistoryInterface.setDefaultInterface = function(defaultInterface){return undefined;};

/**
  * @name addHistoryEntry
  * @function
  * @memberOf QWebHistoryInterface.prototype
  * @param {String} url
  * @returns {undefined}
  */
QWebHistoryInterface.prototype.addHistoryEntry = function(url){return undefined;};

/**
  * @name historyContains
  * @function
  * @memberOf QWebHistoryInterface.prototype
  * @param {String} url
  * @returns {Boolean}
  */
QWebHistoryInterface.prototype.historyContains = function(url){return new Boolean();};

