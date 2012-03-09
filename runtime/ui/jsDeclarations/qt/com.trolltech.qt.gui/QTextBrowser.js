/**
  * @name QTextBrowser
  * @constructor
  * @extends QTextEdit
  * @param {QWidget} parent
  */
function QTextBrowser(parent){return undefined;};

QTextBrowser.prototype = new QTextEdit();

/**
  * @name backwardHistoryCount
  * @function
  * @memberOf QTextBrowser.prototype
  * @returns {Numeric}
  */
QTextBrowser.prototype.backwardHistoryCount = function(){return new Numeric();};

/**
  * @name clearHistory
  * @function
  * @memberOf QTextBrowser.prototype
  * @returns {undefined}
  */
QTextBrowser.prototype.clearHistory = function(){return undefined;};

/**
  * @name forwardHistoryCount
  * @function
  * @memberOf QTextBrowser.prototype
  * @returns {Numeric}
  */
QTextBrowser.prototype.forwardHistoryCount = function(){return new Numeric();};

/**
  * @name historyTitle
  * @function
  * @memberOf QTextBrowser.prototype
  * @param {Numeric} arg__1
  * @returns {String}
  */
QTextBrowser.prototype.historyTitle = function(arg__1){return new String();};

/**
  * @name historyUrl
  * @function
  * @memberOf QTextBrowser.prototype
  * @param {Numeric} arg__1
  * @returns {QUrl}
  */
QTextBrowser.prototype.historyUrl = function(arg__1){return new QUrl();};

/**
  * @name isBackwardAvailable
  * @function
  * @memberOf QTextBrowser.prototype
  * @returns {Boolean}
  */
QTextBrowser.prototype.isBackwardAvailable = function(){return new Boolean();};

/**
  * @name isForwardAvailable
  * @function
  * @memberOf QTextBrowser.prototype
  * @returns {Boolean}
  */
QTextBrowser.prototype.isForwardAvailable = function(){return new Boolean();};

/**
  * @name source
  * @memberOf QTextBrowser.prototype
  * @type QUrl
  */
QTextBrowser.prototype.source = new QUrl();

/**
  * @name searchPaths
  * @memberOf QTextBrowser.prototype
  * @type Array
  */
QTextBrowser.prototype.searchPaths = new Array();

/**
  * @name openExternalLinks
  * @memberOf QTextBrowser.prototype
  * @type Boolean
  */
QTextBrowser.prototype.openExternalLinks = new Boolean();

/**
  * @name openLinks
  * @memberOf QTextBrowser.prototype
  * @type Boolean
  */
QTextBrowser.prototype.openLinks = new Boolean();


