/**
  * @name QGraphicsWebView
  * @constructor
  * @extends QGraphicsWidget
  * @param {QGraphicsItem} parent
  */
function QGraphicsWebView(parent){return undefined;};

QGraphicsWebView.prototype = new QGraphicsWidget();

/**
  * @name findText
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {String} subString
  * @param {QWebPage.FindFlags} options
  * @returns {Boolean}
  */
QGraphicsWebView.prototype.findText = function(subString, options){return new Boolean();};

/**
  * @name history
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @returns {Object}
  */
QGraphicsWebView.prototype.history = function(){return new Object();};

/**
  * @name load
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {QNetworkRequest} request
  * @param {QNetworkAccessManager.Operation} operation
  * @param {QByteArray} body
  * @returns {undefined}
  */
QGraphicsWebView.prototype.load = function(request, operation, body){return undefined;};

/**
  * @name page
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @returns {QWebPage}
  */
QGraphicsWebView.prototype.page = function(){return new QWebPage();};

/**
  * @name pageAction
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {QWebPage.WebAction} action
  * @returns {QAction}
  */
QGraphicsWebView.prototype.pageAction = function(action){return new QAction();};

/**
  * @name setContent
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {QByteArray} data
  * @param {String} mimeType
  * @param {QUrl} baseUrl
  * @returns {undefined}
  */
QGraphicsWebView.prototype.setContent = function(data, mimeType, baseUrl){return undefined;};

/**
  * @name setHtml
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {String} html
  * @param {QUrl} baseUrl
  * @returns {undefined}
  */
QGraphicsWebView.prototype.setHtml = function(html, baseUrl){return undefined;};

/**
  * @name setPage
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {QWebPage} arg__1
  * @returns {undefined}
  */
QGraphicsWebView.prototype.setPage = function(arg__1){return undefined;};

/**
  * @name setRenderHint
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {QPainter.RenderHint} arg__1
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QGraphicsWebView.prototype.setRenderHint = function(arg__1, enabled){return undefined;};

/**
  * @name settings
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @returns {QWebSettings}
  */
QGraphicsWebView.prototype.settings = function(){return new QWebSettings();};

/**
  * @name triggerPageAction
  * @function
  * @memberOf QGraphicsWebView.prototype
  * @param {QWebPage.WebAction} action
  * @param {Boolean} checked
  * @returns {undefined}
  */
QGraphicsWebView.prototype.triggerPageAction = function(action, checked){return undefined;};

/**
  * @name title
  * @memberOf QGraphicsWebView.prototype
  * @type String
  */
QGraphicsWebView.prototype.title = new String();

/**
  * @name icon
  * @memberOf QGraphicsWebView.prototype
  * @type QIcon
  */
QGraphicsWebView.prototype.icon = new QIcon();

/**
  * @name zoomFactor
  * @memberOf QGraphicsWebView.prototype
  * @type Numeric
  */
QGraphicsWebView.prototype.zoomFactor = new Numeric();

/**
  * @name url
  * @memberOf QGraphicsWebView.prototype
  * @type QUrl
  */
QGraphicsWebView.prototype.url = new QUrl();

/**
  * @name modified
  * @memberOf QGraphicsWebView.prototype
  * @type Boolean
  */
QGraphicsWebView.prototype.modified = new Boolean();

/**
  * @name resizesToContents
  * @memberOf QGraphicsWebView.prototype
  * @type Boolean
  */
QGraphicsWebView.prototype.resizesToContents = new Boolean();

/**
  * @name tiledBackingStoreFrozen
  * @memberOf QGraphicsWebView.prototype
  * @type Boolean
  */
QGraphicsWebView.prototype.tiledBackingStoreFrozen = new Boolean();

/**
  * @name renderHints
  * @memberOf QGraphicsWebView.prototype
  * @type QPainter.RenderHints
  */
QGraphicsWebView.prototype.renderHints = new QPainter.RenderHints();


