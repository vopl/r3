/**
  * @class QWebFrame from package com.trolltech.qt.webkit
  * @extends QObject
  */
var QWebFrame = {};

QWebFrame.prototype = new QObject();

/**
  * @default 0x10
  * @constant
  * @memberOf QWebFrame
  * @name ContentsLayer
  * @see QWebFrame#RenderLayer
  * @type Number
  */
QWebFrame.ContentsLayer = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf QWebFrame
  * @name ScrollBarLayer
  * @see QWebFrame#RenderLayer
  * @type Number
  */
QWebFrame.ScrollBarLayer = 0x20;

/**
  * @default 0x40
  * @constant
  * @memberOf QWebFrame
  * @name PanIconLayer
  * @see QWebFrame#RenderLayer
  * @type Number
  */
QWebFrame.PanIconLayer = 0x40;

/**
  * @default 0xff
  * @constant
  * @memberOf QWebFrame
  * @name AllLayers
  * @see QWebFrame#RenderLayer
  * @type Number
  */
QWebFrame.AllLayers = 0xff;

/**
  * @constructor 
  * @memberOf QWebFrame
  * @name RenderLayer
  */
QWebFrame.RenderLayer = function(value){;};



/**
  * @name addToJavaScriptWindowObject
  * @function
  * @memberOf QWebFrame.prototype
  * @param {String} name
  * @param {QObject} object
  * @returns {undefined}
  */
QWebFrame.prototype.addToJavaScriptWindowObject = function(name, object){return undefined;};

/**
  * @name childFrames
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {Array}
  */
QWebFrame.prototype.childFrames = function(){return new Array();};

/**
  * @name documentElement
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {QWebElement}
  */
QWebFrame.prototype.documentElement = function(){return new QWebElement();};

/**
  * @name findFirstElement
  * @function
  * @memberOf QWebFrame.prototype
  * @param {String} selectorQuery
  * @returns {QWebElement}
  */
QWebFrame.prototype.findFirstElement = function(selectorQuery){return new QWebElement();};

/**
  * @name frameName
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {String}
  */
QWebFrame.prototype.frameName = function(){return new String();};

/**
  * @name geometry
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {QRect}
  */
QWebFrame.prototype.geometry = function(){return new QRect();};

/**
  * @name hitTestContent
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPoint} pos
  * @returns {QWebHitTestResult}
  */
QWebFrame.prototype.hitTestContent = function(pos){return new QWebHitTestResult();};

/**
  * @name load
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QNetworkRequest} request
  * @param {QNetworkAccessManager.Operation} operation
  * @param {QByteArray} body
  * @returns {undefined}
  */
QWebFrame.prototype.load = function(request, operation, body){return undefined;};

/**
  * @name metaData
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {Object}
  */
QWebFrame.prototype.metaData = function(){return new Object();};

/**
  * @name page
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {QWebPage}
  */
QWebFrame.prototype.page = function(){return new QWebPage();};

/**
  * @name parentFrame
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {QWebFrame}
  */
QWebFrame.prototype.parentFrame = function(){return new QWebFrame();};

/**
  * @name pos
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {QPoint}
  */
QWebFrame.prototype.pos = function(){return new QPoint();};

/**
  * @name render
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPainter} arg__1
  * @returns {undefined}
  */
QWebFrame.prototype.render = function(arg__1){return undefined;};

/**
  * @name renderTreeDump
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {String}
  */
QWebFrame.prototype.renderTreeDump = function(){return new String();};

/**
  * @name scroll
  * @function
  * @memberOf QWebFrame.prototype
  * @param {Numeric} arg__1
  * @param {Numeric} arg__2
  * @returns {undefined}
  */
QWebFrame.prototype.scroll = function(arg__1, arg__2){return undefined;};

/**
  * @name scrollBarGeometry
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @returns {QRect}
  */
QWebFrame.prototype.scrollBarGeometry = function(orientation){return new QRect();};

/**
  * @name scrollBarMaximum
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @returns {Numeric}
  */
QWebFrame.prototype.scrollBarMaximum = function(orientation){return new Numeric();};

/**
  * @name scrollBarMinimum
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @returns {Numeric}
  */
QWebFrame.prototype.scrollBarMinimum = function(orientation){return new Numeric();};

/**
  * @name scrollBarPolicy
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @returns {Qt.ScrollBarPolicy}
  */
QWebFrame.prototype.scrollBarPolicy = function(orientation){return new Qt.ScrollBarPolicy();};

/**
  * @name scrollBarValue
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @returns {Numeric}
  */
QWebFrame.prototype.scrollBarValue = function(orientation){return new Numeric();};

/**
  * @name scrollToAnchor
  * @function
  * @memberOf QWebFrame.prototype
  * @param {String} anchor
  * @returns {undefined}
  */
QWebFrame.prototype.scrollToAnchor = function(anchor){return undefined;};

/**
  * @name setContent
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QByteArray} data
  * @param {String} mimeType
  * @param {QUrl} baseUrl
  * @returns {undefined}
  */
QWebFrame.prototype.setContent = function(data, mimeType, baseUrl){return undefined;};

/**
  * @name setFocus
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {undefined}
  */
QWebFrame.prototype.setFocus = function(){return undefined;};

/**
  * @name setHtml
  * @function
  * @memberOf QWebFrame.prototype
  * @param {String} html
  * @param {QUrl} baseUrl
  * @returns {undefined}
  */
QWebFrame.prototype.setHtml = function(html, baseUrl){return undefined;};

/**
  * @name setScrollBarPolicy
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @param {Qt.ScrollBarPolicy} policy
  * @returns {undefined}
  */
QWebFrame.prototype.setScrollBarPolicy = function(orientation, policy){return undefined;};

/**
  * @name setScrollBarValue
  * @function
  * @memberOf QWebFrame.prototype
  * @param {QPrinter.Orientation} orientation
  * @param {Numeric} value
  * @returns {undefined}
  */
QWebFrame.prototype.setScrollBarValue = function(orientation, value){return undefined;};

/**
  * @name toHtml
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {String}
  */
QWebFrame.prototype.toHtml = function(){return new String();};

/**
  * @name toPlainText
  * @function
  * @memberOf QWebFrame.prototype
  * @returns {String}
  */
QWebFrame.prototype.toPlainText = function(){return new String();};

/**
  * @name textSizeMultiplier
  * @memberOf QWebFrame.prototype
  * @type Numeric
  */
QWebFrame.prototype.textSizeMultiplier = new Numeric();

/**
  * @name zoomFactor
  * @memberOf QWebFrame.prototype
  * @type Numeric
  */
QWebFrame.prototype.zoomFactor = new Numeric();

/**
  * @name title
  * @memberOf QWebFrame.prototype
  * @type String
  */
QWebFrame.prototype.title = new String();

/**
  * @name url
  * @memberOf QWebFrame.prototype
  * @type QUrl
  */
QWebFrame.prototype.url = new QUrl();

/**
  * @name requestedUrl
  * @memberOf QWebFrame.prototype
  * @type QUrl
  */
QWebFrame.prototype.requestedUrl = new QUrl();

/**
  * @name baseUrl
  * @memberOf QWebFrame.prototype
  * @type QUrl
  */
QWebFrame.prototype.baseUrl = new QUrl();

/**
  * @name icon
  * @memberOf QWebFrame.prototype
  * @type QIcon
  */
QWebFrame.prototype.icon = new QIcon();

/**
  * @name contentsSize
  * @memberOf QWebFrame.prototype
  * @type QSize
  */
QWebFrame.prototype.contentsSize = new QSize();

/**
  * @name scrollPosition
  * @memberOf QWebFrame.prototype
  * @type QPoint
  */
QWebFrame.prototype.scrollPosition = new QPoint();

/**
  * @name focus
  * @memberOf QWebFrame.prototype
  * @type Boolean
  */
QWebFrame.prototype.focus = new Boolean();


