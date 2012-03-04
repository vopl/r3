/**
  * @class QNetworkReply from package com.trolltech.qt.network
  * @extends QIODevice
  */
var QNetworkReply = {};

QNetworkReply.prototype = new QIODevice();

/**
  * @default 0
  * @constant
  * @memberOf QNetworkReply
  * @name NoError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.NoError = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QNetworkReply
  * @name ConnectionRefusedError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ConnectionRefusedError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkReply
  * @name RemoteHostClosedError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.RemoteHostClosedError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QNetworkReply
  * @name HostNotFoundError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.HostNotFoundError = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QNetworkReply
  * @name TimeoutError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.TimeoutError = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QNetworkReply
  * @name OperationCanceledError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.OperationCanceledError = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QNetworkReply
  * @name SslHandshakeFailedError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.SslHandshakeFailedError = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QNetworkReply
  * @name TemporaryNetworkFailureError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.TemporaryNetworkFailureError = 0x7;

/**
  * @default 99
  * @constant
  * @memberOf QNetworkReply
  * @name UnknownNetworkError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.UnknownNetworkError = 0x63;

/**
  * @default 101
  * @constant
  * @memberOf QNetworkReply
  * @name ProxyConnectionRefusedError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProxyConnectionRefusedError = 0x65;

/**
  * @default 0x66
  * @constant
  * @memberOf QNetworkReply
  * @name ProxyConnectionClosedError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProxyConnectionClosedError = 0x66;

/**
  * @default 0x67
  * @constant
  * @memberOf QNetworkReply
  * @name ProxyNotFoundError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProxyNotFoundError = 0x67;

/**
  * @default 0x68
  * @constant
  * @memberOf QNetworkReply
  * @name ProxyTimeoutError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProxyTimeoutError = 0x68;

/**
  * @default 0x69
  * @constant
  * @memberOf QNetworkReply
  * @name ProxyAuthenticationRequiredError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProxyAuthenticationRequiredError = 0x69;

/**
  * @default 199
  * @constant
  * @memberOf QNetworkReply
  * @name UnknownProxyError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.UnknownProxyError = 0xc7;

/**
  * @default 201
  * @constant
  * @memberOf QNetworkReply
  * @name ContentAccessDenied
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ContentAccessDenied = 0xc9;

/**
  * @default 0xca
  * @constant
  * @memberOf QNetworkReply
  * @name ContentOperationNotPermittedError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ContentOperationNotPermittedError = 0xca;

/**
  * @default 0xcb
  * @constant
  * @memberOf QNetworkReply
  * @name ContentNotFoundError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ContentNotFoundError = 0xcb;

/**
  * @default 0xcc
  * @constant
  * @memberOf QNetworkReply
  * @name AuthenticationRequiredError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.AuthenticationRequiredError = 0xcc;

/**
  * @default 0xcd
  * @constant
  * @memberOf QNetworkReply
  * @name ContentReSendError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ContentReSendError = 0xcd;

/**
  * @default 299
  * @constant
  * @memberOf QNetworkReply
  * @name UnknownContentError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.UnknownContentError = 0x12b;

/**
  * @default 301
  * @constant
  * @memberOf QNetworkReply
  * @name ProtocolUnknownError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProtocolUnknownError = 0x12d;

/**
  * @default 0x12e
  * @constant
  * @memberOf QNetworkReply
  * @name ProtocolInvalidOperationError
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProtocolInvalidOperationError = 0x12e;

/**
  * @default 399
  * @constant
  * @memberOf QNetworkReply
  * @name ProtocolFailure
  * @see QNetworkReply#NetworkError
  * @type Number
  */
QNetworkReply.ProtocolFailure = 0x18f;

/**
  * @constructor 
  * @memberOf QNetworkReply
  * @name NetworkError
  */
QNetworkReply.NetworkError = function(value){;};



/**
  * @name abort
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {undefined}
  */
QNetworkReply.prototype.abort = function(){return undefined;};

/**
  * @name attribute
  * @function
  * @memberOf QNetworkReply.prototype
  * @param {QNetworkRequest.Attribute} code
  * @returns {Object}
  */
QNetworkReply.prototype.attribute = function(code){return new Object();};

/**
  * @name error
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {QNetworkReply.NetworkError}
  */
QNetworkReply.prototype.error = function(){return new QNetworkReply.NetworkError();};

/**
  * @name hasRawHeader
  * @function
  * @memberOf QNetworkReply.prototype
  * @param {QByteArray} headerName
  * @returns {Boolean}
  */
QNetworkReply.prototype.hasRawHeader = function(headerName){return new Boolean();};

/**
  * @name header
  * @function
  * @memberOf QNetworkReply.prototype
  * @param {QNetworkRequest.KnownHeaders} header
  * @returns {Object}
  */
QNetworkReply.prototype.header = function(header){return new Object();};

/**
  * @name isFinished
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {Boolean}
  */
QNetworkReply.prototype.isFinished = function(){return new Boolean();};

/**
  * @name isRunning
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {Boolean}
  */
QNetworkReply.prototype.isRunning = function(){return new Boolean();};

/**
  * @name manager
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {QNetworkAccessManager}
  */
QNetworkReply.prototype.manager = function(){return new QNetworkAccessManager();};

/**
  * @name operation
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {QNetworkAccessManager.Operation}
  */
QNetworkReply.prototype.operation = function(){return new QNetworkAccessManager.Operation();};

/**
  * @name rawHeader
  * @function
  * @memberOf QNetworkReply.prototype
  * @param {QByteArray} headerName
  * @returns {QByteArray}
  */
QNetworkReply.prototype.rawHeader = function(headerName){return new QByteArray();};

/**
  * @name rawHeaderList
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {Array}
  */
QNetworkReply.prototype.rawHeaderList = function(){return new Array();};

/**
  * @name rawHeaderPairs
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {Array}
  */
QNetworkReply.prototype.rawHeaderPairs = function(){return new Array();};

/**
  * @name readBufferSize
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {Numeric}
  */
QNetworkReply.prototype.readBufferSize = function(){return new Numeric();};

/**
  * @name request
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {QNetworkRequest}
  */
QNetworkReply.prototype.request = function(){return new QNetworkRequest();};

/**
  * @name setReadBufferSize
  * @function
  * @memberOf QNetworkReply.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QNetworkReply.prototype.setReadBufferSize = function(size){return undefined;};

/**
  * @name url
  * @function
  * @memberOf QNetworkReply.prototype
  * @returns {QUrl}
  */
QNetworkReply.prototype.url = function(){return new QUrl();};

