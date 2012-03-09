/**
  * @name QNetworkRequest
  * @constructor
  * @param {QNetworkRequest} other
  */
function QNetworkRequest(other){return undefined;};

/**
  * @name QNetworkRequest^1
  * @constructor
  * @param {QUrl} url
  */
function QNetworkRequest(url){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QNetworkRequest
  * @name AlwaysNetwork
  * @see QNetworkRequest#CacheLoadControl
  * @type Number
  */
QNetworkRequest.AlwaysNetwork = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkRequest
  * @name PreferNetwork
  * @see QNetworkRequest#CacheLoadControl
  * @type Number
  */
QNetworkRequest.PreferNetwork = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkRequest
  * @name PreferCache
  * @see QNetworkRequest#CacheLoadControl
  * @type Number
  */
QNetworkRequest.PreferCache = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QNetworkRequest
  * @name AlwaysCache
  * @see QNetworkRequest#CacheLoadControl
  * @type Number
  */
QNetworkRequest.AlwaysCache = 0x3;

/**
  * @constructor 
  * @memberOf QNetworkRequest
  * @name CacheLoadControl
  */
QNetworkRequest.CacheLoadControl = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QNetworkRequest
  * @name ContentTypeHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.ContentTypeHeader = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkRequest
  * @name ContentLengthHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.ContentLengthHeader = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkRequest
  * @name LocationHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.LocationHeader = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QNetworkRequest
  * @name LastModifiedHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.LastModifiedHeader = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QNetworkRequest
  * @name CookieHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.CookieHeader = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QNetworkRequest
  * @name SetCookieHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.SetCookieHeader = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QNetworkRequest
  * @name ContentDispositionHeader
  * @see QNetworkRequest#KnownHeaders
  * @type Number
  */
QNetworkRequest.ContentDispositionHeader = 0x6;

/**
  * @constructor 
  * @memberOf QNetworkRequest
  * @name KnownHeaders
  */
QNetworkRequest.KnownHeaders = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf QNetworkRequest
  * @name HighPriority
  * @see QNetworkRequest#Priority
  * @type Number
  */
QNetworkRequest.HighPriority = 0x1;

/**
  * @default 3
  * @constant
  * @memberOf QNetworkRequest
  * @name NormalPriority
  * @see QNetworkRequest#Priority
  * @type Number
  */
QNetworkRequest.NormalPriority = 0x3;

/**
  * @default 5
  * @constant
  * @memberOf QNetworkRequest
  * @name LowPriority
  * @see QNetworkRequest#Priority
  * @type Number
  */
QNetworkRequest.LowPriority = 0x5;

/**
  * @constructor 
  * @memberOf QNetworkRequest
  * @name Priority
  */
QNetworkRequest.Priority = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QNetworkRequest
  * @name HttpStatusCodeAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.HttpStatusCodeAttribute = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkRequest
  * @name HttpReasonPhraseAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.HttpReasonPhraseAttribute = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkRequest
  * @name RedirectionTargetAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.RedirectionTargetAttribute = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QNetworkRequest
  * @name ConnectionEncryptedAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.ConnectionEncryptedAttribute = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QNetworkRequest
  * @name CacheLoadControlAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.CacheLoadControlAttribute = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QNetworkRequest
  * @name CacheSaveControlAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.CacheSaveControlAttribute = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QNetworkRequest
  * @name SourceIsFromCacheAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.SourceIsFromCacheAttribute = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QNetworkRequest
  * @name DoNotBufferUploadDataAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.DoNotBufferUploadDataAttribute = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QNetworkRequest
  * @name HttpPipeliningAllowedAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.HttpPipeliningAllowedAttribute = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QNetworkRequest
  * @name HttpPipeliningWasUsedAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.HttpPipeliningWasUsedAttribute = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QNetworkRequest
  * @name CustomVerbAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.CustomVerbAttribute = 0xa;

/**
  * @default 0xb
  * @constant
  * @memberOf QNetworkRequest
  * @name CookieLoadControlAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.CookieLoadControlAttribute = 0xb;

/**
  * @default 0xc
  * @constant
  * @memberOf QNetworkRequest
  * @name AuthenticationReuseAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.AuthenticationReuseAttribute = 0xc;

/**
  * @default 0xd
  * @constant
  * @memberOf QNetworkRequest
  * @name CookieSaveControlAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.CookieSaveControlAttribute = 0xd;

/**
  * @default 0xe
  * @constant
  * @memberOf QNetworkRequest
  * @name MaximumDownloadBufferSizeAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.MaximumDownloadBufferSizeAttribute = 0xe;

/**
  * @default 0xf
  * @constant
  * @memberOf QNetworkRequest
  * @name DownloadBufferAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.DownloadBufferAttribute = 0xf;

/**
  * @default 0x10
  * @constant
  * @memberOf QNetworkRequest
  * @name SynchronousRequestAttribute
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.SynchronousRequestAttribute = 0x10;

/**
  * @default 1000
  * @constant
  * @memberOf QNetworkRequest
  * @name User
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.User = 0x3e8;

/**
  * @default 32767
  * @constant
  * @memberOf QNetworkRequest
  * @name UserMax
  * @see QNetworkRequest#Attribute
  * @type Number
  */
QNetworkRequest.UserMax = 0x7fff;

/**
  * @constructor 
  * @memberOf QNetworkRequest
  * @name Attribute
  */
QNetworkRequest.Attribute = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QNetworkRequest
  * @name Automatic
  * @see QNetworkRequest#LoadControl
  * @type Number
  */
QNetworkRequest.Automatic = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkRequest
  * @name Manual
  * @see QNetworkRequest#LoadControl
  * @type Number
  */
QNetworkRequest.Manual = 0x1;

/**
  * @constructor 
  * @memberOf QNetworkRequest
  * @name LoadControl
  */
QNetworkRequest.LoadControl = function(value){;};



/**
  * @name attribute
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QNetworkRequest.Attribute} code
  * @param {Object} defaultValue
  * @returns {Object}
  */
QNetworkRequest.prototype.attribute = function(code, defaultValue){return new Object();};

/**
  * @name hasRawHeader
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QByteArray} headerName
  * @returns {Boolean}
  */
QNetworkRequest.prototype.hasRawHeader = function(headerName){return new Boolean();};

/**
  * @name header
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QNetworkRequest.KnownHeaders} header
  * @returns {Object}
  */
QNetworkRequest.prototype.header = function(header){return new Object();};

/**
  * @name operator_equal
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QNetworkRequest} other
  * @returns {Boolean}
  */
QNetworkRequest.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name originatingObject
  * @function
  * @memberOf QNetworkRequest.prototype
  * @returns {QObject}
  */
QNetworkRequest.prototype.originatingObject = function(){return new QObject();};

/**
  * @name priority
  * @function
  * @memberOf QNetworkRequest.prototype
  * @returns {QAction.Priority}
  */
QNetworkRequest.prototype.priority = function(){return new QAction.Priority();};

/**
  * @name rawHeader
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QByteArray} headerName
  * @returns {QByteArray}
  */
QNetworkRequest.prototype.rawHeader = function(headerName){return new QByteArray();};

/**
  * @name rawHeaderList
  * @function
  * @memberOf QNetworkRequest.prototype
  * @returns {Array}
  */
QNetworkRequest.prototype.rawHeaderList = function(){return new Array();};

/**
  * @name setAttribute
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QNetworkRequest.Attribute} code
  * @param {Object} value
  * @returns {undefined}
  */
QNetworkRequest.prototype.setAttribute = function(code, value){return undefined;};

/**
  * @name setHeader
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QNetworkRequest.KnownHeaders} header
  * @param {Object} value
  * @returns {undefined}
  */
QNetworkRequest.prototype.setHeader = function(header, value){return undefined;};

/**
  * @name setOriginatingObject
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QObject} object
  * @returns {undefined}
  */
QNetworkRequest.prototype.setOriginatingObject = function(object){return undefined;};

/**
  * @name setPriority
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QAction.Priority} priority
  * @returns {undefined}
  */
QNetworkRequest.prototype.setPriority = function(priority){return undefined;};

/**
  * @name setRawHeader
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QByteArray} headerName
  * @param {QByteArray} value
  * @returns {undefined}
  */
QNetworkRequest.prototype.setRawHeader = function(headerName, value){return undefined;};

/**
  * @name setUrl
  * @function
  * @memberOf QNetworkRequest.prototype
  * @param {QUrl} url
  * @returns {undefined}
  */
QNetworkRequest.prototype.setUrl = function(url){return undefined;};

/**
  * @name url
  * @function
  * @memberOf QNetworkRequest.prototype
  * @returns {QUrl}
  */
QNetworkRequest.prototype.url = function(){return new QUrl();};

