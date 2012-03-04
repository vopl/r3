/**
  * @name QWebView
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QWebView(parent){return undefined;};

QWebView.prototype = new QWidget();

/**
  * @name findText
  * @function
  * @memberOf QWebView.prototype
  * @param {String} subString
  * @param {QWebPage.FindFlags} options
  * @returns {Boolean}
  */
QWebView.prototype.findText = function(subString, options){return new Boolean();};

/**
  * @name history
  * @function
  * @memberOf QWebView.prototype
  * @returns {Object}
  */
QWebView.prototype.history = function(){return new Object();};

/**
  * @name load
  * @function
  * @memberOf QWebView.prototype
  * @param {QNetworkRequest} request
  * @param {QNetworkAccessManager.Operation} operation
  * @param {QByteArray} body
  * @returns {undefined}
  */
QWebView.prototype.load = function(request, operation, body){return undefined;};

/**
  * @name page
  * @function
  * @memberOf QWebView.prototype
  * @returns {QWebPage}
  */
QWebView.prototype.page = function(){return new QWebPage();};

/**
  * @name pageAction
  * @function
  * @memberOf QWebView.prototype
  * @param {QWebPage.WebAction} action
  * @returns {QAction}
  */
QWebView.prototype.pageAction = function(action){return new QAction();};

/**
  * @name setContent
  * @function
  * @memberOf QWebView.prototype
  * @param {QByteArray} data
  * @param {String} mimeType
  * @param {QUrl} baseUrl
  * @returns {undefined}
  */
QWebView.prototype.setContent = function(data, mimeType, baseUrl){return undefined;};

/**
  * @name setHtml
  * @function
  * @memberOf QWebView.prototype
  * @param {String} html
  * @param {QUrl} baseUrl
  * @returns {undefined}
  */
QWebView.prototype.setHtml = function(html, baseUrl){return undefined;};

/**
  * @name setPage
  * @function
  * @memberOf QWebView.prototype
  * @param {QWebPage} page
  * @returns {undefined}
  */
QWebView.prototype.setPage = function(page){return undefined;};

/**
  * @name setRenderHint
  * @function
  * @memberOf QWebView.prototype
  * @param {QPainter.RenderHint} hint
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QWebView.prototype.setRenderHint = function(hint, enabled){return undefined;};

/**
  * @name settings
  * @function
  * @memberOf QWebView.prototype
  * @returns {QWebSettings}
  */
QWebView.prototype.settings = function(){return new QWebSettings();};

/**
  * @name sizeHint
  * @function
  * @memberOf QWebView.prototype
  * @returns {QSize}
  */
QWebView.prototype.sizeHint = function(){return new QSize();};

/**
  * @name triggerPageAction
  * @function
  * @memberOf QWebView.prototype
  * @param {QWebPage.WebAction} action
  * @param {Boolean} checked
  * @returns {undefined}
  */
QWebView.prototype.triggerPageAction = function(action, checked){return undefined;};

/**
  * @name title
  * @memberOf QWebView.prototype
  * @type String
  */
QWebView.prototype.title = new String();

/**
  * @name url
  * @memberOf QWebView.prototype
  * @type QUrl
  */
QWebView.prototype.url = new QUrl();

/**
  * @name icon
  * @memberOf QWebView.prototype
  * @type QIcon
  */
QWebView.prototype.icon = new QIcon();

/**
  * @name selectedText
  * @memberOf QWebView.prototype
  * @type String
  */
QWebView.prototype.selectedText = new String();

/**
  * @name selectedHtml
  * @memberOf QWebView.prototype
  * @type String
  */
QWebView.prototype.selectedHtml = new String();

/**
  * @name hasSelection
  * @memberOf QWebView.prototype
  * @type Boolean
  */
QWebView.prototype.hasSelection = new Boolean();

/**
  * @name modified
  * @memberOf QWebView.prototype
  * @type Boolean
  */
QWebView.prototype.modified = new Boolean();

/**
  * @name textSizeMultiplier
  * @memberOf QWebView.prototype
  * @type Numeric
  */
QWebView.prototype.textSizeMultiplier = new Numeric();

/**
  * @name zoomFactor
  * @memberOf QWebView.prototype
  * @type Numeric
  */
QWebView.prototype.zoomFactor = new Numeric();

/**
  * @name renderHints
  * @memberOf QWebView.prototype
  * @type QPainter.RenderHints
  */
QWebView.prototype.renderHints = new QPainter.RenderHints();


