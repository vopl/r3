/**
  * @name QUrl
  * @constructor
  */
function QUrl(){return undefined;};

/**
  * @name QUrl^1
  * @constructor
  * @param {String} url
  */
function QUrl(url){return undefined;};

/**
  * @name QUrl^2
  * @constructor
  * @param {String} url
  * @param {QUrl.ParsingMode} mode
  */
function QUrl(url, mode){return undefined;};

/**
  * @name QUrl^3
  * @constructor
  * @param {QUrl} copy
  */
function QUrl(copy){return undefined;};

/**
  * @name fromAce
  * @function
  * @memberOf QUrl
  * @param {QByteArray} arg__1
  * @returns {String}
  */
QUrl.fromAce = function(arg__1){return new String();};

/**
  * @name fromEncoded
  * @function
  * @memberOf QUrl
  * @param {QByteArray} url
  * @returns {QUrl}
  */
QUrl.fromEncoded = function(url){return new QUrl();};

/**
  * @name fromLocalFile
  * @function
  * @memberOf QUrl
  * @param {String} localfile
  * @returns {QUrl}
  */
QUrl.fromLocalFile = function(localfile){return new QUrl();};

/**
  * @name fromPercentEncoding
  * @function
  * @memberOf QUrl
  * @param {QByteArray} arg__1
  * @returns {String}
  */
QUrl.fromPercentEncoding = function(arg__1){return new String();};

/**
  * @name fromUserInput
  * @function
  * @memberOf QUrl
  * @param {String} userInput
  * @returns {QUrl}
  */
QUrl.fromUserInput = function(userInput){return new QUrl();};

/**
  * @name idnWhitelist
  * @function
  * @memberOf QUrl
  * @returns {Array}
  */
QUrl.idnWhitelist = function(){return new Array();};

/**
  * @name setIdnWhitelist
  * @function
  * @memberOf QUrl
  * @param {Array} arg__1
  * @returns {undefined}
  */
QUrl.setIdnWhitelist = function(arg__1){return undefined;};

/**
  * @name toAce
  * @function
  * @memberOf QUrl
  * @param {String} arg__1
  * @returns {QByteArray}
  */
QUrl.toAce = function(arg__1){return new QByteArray();};

/**
  * @name toPercentEncoding
  * @function
  * @memberOf QUrl
  * @param {String} arg__1
  * @param {QByteArray} exclude
  * @param {QByteArray} include
  * @returns {QByteArray}
  */
QUrl.toPercentEncoding = function(arg__1, exclude, include){return new QByteArray();};

/**
  * @default 0x0
  * @constant
  * @memberOf QUrl
  * @name TolerantMode
  * @see QUrl#ParsingMode
  * @type Number
  */
QUrl.TolerantMode = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QUrl
  * @name StrictMode
  * @see QUrl#ParsingMode
  * @type Number
  */
QUrl.StrictMode = 0x1;

/**
  * @constructor 
  * @memberOf QUrl
  * @name ParsingMode
  */
QUrl.ParsingMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QUrl
  * @name None
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.None = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QUrl
  * @name RemoveScheme
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemoveScheme = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QUrl
  * @name RemovePassword
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemovePassword = 0x2;

/**
  * @default RemovePassword|0x4
  * @constant
  * @memberOf QUrl
  * @name RemoveUserInfo
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemoveUserInfo = 0x6;

/**
  * @default 0x8
  * @constant
  * @memberOf QUrl
  * @name RemovePort
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemovePort = 0x8;

/**
  * @default RemoveUserInfo|RemovePort|0x10
  * @constant
  * @memberOf QUrl
  * @name RemoveAuthority
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemoveAuthority = 0x1e;

/**
  * @default 0x20
  * @constant
  * @memberOf QUrl
  * @name RemovePath
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemovePath = 0x20;

/**
  * @default 0x40
  * @constant
  * @memberOf QUrl
  * @name RemoveQuery
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemoveQuery = 0x40;

/**
  * @default 0x80
  * @constant
  * @memberOf QUrl
  * @name RemoveFragment
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.RemoveFragment = 0x80;

/**
  * @default 0x10000
  * @constant
  * @memberOf QUrl
  * @name StripTrailingSlash
  * @see QUrl#FormattingOptions
  * @see QUrl#FormattingOption
  * @type Number
  */
QUrl.StripTrailingSlash = 0x10000;

/**
  * @constructor 
  * @memberOf QUrl
  * @name FormattingOption
  */
QUrl.FormattingOption = function(value){;};

/**
  * @constructor 
  * @memberOf QUrl
  * @name FormattingOptions
  */
QUrl.FormattingOptions = function(value1, value2 /*, ...*/){;};


/**
  * @name addEncodedQueryItem
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} key
  * @param {QByteArray} value
  * @returns {undefined}
  */
QUrl.prototype.addEncodedQueryItem = function(key, value){return undefined;};

/**
  * @name addQueryItem
  * @function
  * @memberOf QUrl.prototype
  * @param {String} key
  * @param {String} value
  * @returns {undefined}
  */
QUrl.prototype.addQueryItem = function(key, value){return undefined;};

/**
  * @name allEncodedQueryItemValues
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} key
  * @returns {Array}
  */
QUrl.prototype.allEncodedQueryItemValues = function(key){return new Array();};

/**
  * @name allQueryItemValues
  * @function
  * @memberOf QUrl.prototype
  * @param {String} key
  * @returns {Array}
  */
QUrl.prototype.allQueryItemValues = function(key){return new Array();};

/**
  * @name authority
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.authority = function(){return new String();};

/**
  * @name clear
  * @function
  * @memberOf QUrl.prototype
  * @returns {undefined}
  */
QUrl.prototype.clear = function(){return undefined;};

/**
  * @name encodedFragment
  * @function
  * @memberOf QUrl.prototype
  * @returns {QByteArray}
  */
QUrl.prototype.encodedFragment = function(){return new QByteArray();};

/**
  * @name encodedHost
  * @function
  * @memberOf QUrl.prototype
  * @returns {QByteArray}
  */
QUrl.prototype.encodedHost = function(){return new QByteArray();};

/**
  * @name encodedPassword
  * @function
  * @memberOf QUrl.prototype
  * @returns {QByteArray}
  */
QUrl.prototype.encodedPassword = function(){return new QByteArray();};

/**
  * @name encodedPath
  * @function
  * @memberOf QUrl.prototype
  * @returns {QByteArray}
  */
QUrl.prototype.encodedPath = function(){return new QByteArray();};

/**
  * @name encodedQuery
  * @function
  * @memberOf QUrl.prototype
  * @returns {QByteArray}
  */
QUrl.prototype.encodedQuery = function(){return new QByteArray();};

/**
  * @name encodedQueryItemValue
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} key
  * @returns {QByteArray}
  */
QUrl.prototype.encodedQueryItemValue = function(key){return new QByteArray();};

/**
  * @name encodedQueryItems
  * @function
  * @memberOf QUrl.prototype
  * @returns {Array}
  */
QUrl.prototype.encodedQueryItems = function(){return new Array();};

/**
  * @name encodedUserName
  * @function
  * @memberOf QUrl.prototype
  * @returns {QByteArray}
  */
QUrl.prototype.encodedUserName = function(){return new QByteArray();};

/**
  * @name errorString
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.errorString = function(){return new String();};

/**
  * @name fragment
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.fragment = function(){return new String();};

/**
  * @name hasEncodedQueryItem
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} key
  * @returns {Boolean}
  */
QUrl.prototype.hasEncodedQueryItem = function(key){return new Boolean();};

/**
  * @name hasFragment
  * @function
  * @memberOf QUrl.prototype
  * @returns {Boolean}
  */
QUrl.prototype.hasFragment = function(){return new Boolean();};

/**
  * @name hasQuery
  * @function
  * @memberOf QUrl.prototype
  * @returns {Boolean}
  */
QUrl.prototype.hasQuery = function(){return new Boolean();};

/**
  * @name hasQueryItem
  * @function
  * @memberOf QUrl.prototype
  * @param {String} key
  * @returns {Boolean}
  */
QUrl.prototype.hasQueryItem = function(key){return new Boolean();};

/**
  * @name host
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.host = function(){return new String();};

/**
  * @name isEmpty
  * @function
  * @memberOf QUrl.prototype
  * @returns {Boolean}
  */
QUrl.prototype.isEmpty = function(){return new Boolean();};

/**
  * @name isLocalFile
  * @function
  * @memberOf QUrl.prototype
  * @returns {Boolean}
  */
QUrl.prototype.isLocalFile = function(){return new Boolean();};

/**
  * @name isParentOf
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl} url
  * @returns {Boolean}
  */
QUrl.prototype.isParentOf = function(url){return new Boolean();};

/**
  * @name isRelative
  * @function
  * @memberOf QUrl.prototype
  * @returns {Boolean}
  */
QUrl.prototype.isRelative = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QUrl.prototype
  * @returns {Boolean}
  */
QUrl.prototype.isValid = function(){return new Boolean();};

/**
  * @name operator_equal
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl} url
  * @returns {Boolean}
  */
QUrl.prototype.operator_equal = function(url){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl} url
  * @returns {Boolean}
  */
QUrl.prototype.operator_less = function(url){return new Boolean();};

/**
  * @name password
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.password = function(){return new String();};

/**
  * @name path
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.path = function(){return new String();};

/**
  * @name port
  * @function
  * @memberOf QUrl.prototype
  * @returns {Numeric}
  */
QUrl.prototype.port = function(){return new Numeric();};

/**
  * @name queryItemValue
  * @function
  * @memberOf QUrl.prototype
  * @param {String} key
  * @returns {String}
  */
QUrl.prototype.queryItemValue = function(key){return new String();};

/**
  * @name queryItems
  * @function
  * @memberOf QUrl.prototype
  * @returns {Array}
  */
QUrl.prototype.queryItems = function(){return new Array();};

/**
  * @name queryPairDelimiter
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.queryPairDelimiter = function(){return new String();};

/**
  * @name queryValueDelimiter
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.queryValueDelimiter = function(){return new String();};

/**
  * @name readFrom
  * @function
  * @memberOf QUrl.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QUrl.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name removeAllEncodedQueryItems
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} key
  * @returns {undefined}
  */
QUrl.prototype.removeAllEncodedQueryItems = function(key){return undefined;};

/**
  * @name removeAllQueryItems
  * @function
  * @memberOf QUrl.prototype
  * @param {String} key
  * @returns {undefined}
  */
QUrl.prototype.removeAllQueryItems = function(key){return undefined;};

/**
  * @name removeEncodedQueryItem
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} key
  * @returns {undefined}
  */
QUrl.prototype.removeEncodedQueryItem = function(key){return undefined;};

/**
  * @name removeQueryItem
  * @function
  * @memberOf QUrl.prototype
  * @param {String} key
  * @returns {undefined}
  */
QUrl.prototype.removeQueryItem = function(key){return undefined;};

/**
  * @name resolved
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl} relative
  * @returns {QUrl}
  */
QUrl.prototype.resolved = function(relative){return new QUrl();};

/**
  * @name scheme
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.scheme = function(){return new String();};

/**
  * @name setAuthority
  * @function
  * @memberOf QUrl.prototype
  * @param {String} authority
  * @returns {undefined}
  */
QUrl.prototype.setAuthority = function(authority){return undefined;};

/**
  * @name setEncodedFragment
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} fragment
  * @returns {undefined}
  */
QUrl.prototype.setEncodedFragment = function(fragment){return undefined;};

/**
  * @name setEncodedHost
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} host
  * @returns {undefined}
  */
QUrl.prototype.setEncodedHost = function(host){return undefined;};

/**
  * @name setEncodedPassword
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} password
  * @returns {undefined}
  */
QUrl.prototype.setEncodedPassword = function(password){return undefined;};

/**
  * @name setEncodedPath
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} path
  * @returns {undefined}
  */
QUrl.prototype.setEncodedPath = function(path){return undefined;};

/**
  * @name setEncodedQuery
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} query
  * @returns {undefined}
  */
QUrl.prototype.setEncodedQuery = function(query){return undefined;};

/**
  * @name setEncodedQueryItems
  * @function
  * @memberOf QUrl.prototype
  * @param {Array} query
  * @returns {undefined}
  */
QUrl.prototype.setEncodedQueryItems = function(query){return undefined;};

/**
  * @name setEncodedUrl
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} url
  * @returns {undefined}
  */
QUrl.prototype.setEncodedUrl = function(url){return undefined;};

/**
  * @name setEncodedUserName
  * @function
  * @memberOf QUrl.prototype
  * @param {QByteArray} userName
  * @returns {undefined}
  */
QUrl.prototype.setEncodedUserName = function(userName){return undefined;};

/**
  * @name setFragment
  * @function
  * @memberOf QUrl.prototype
  * @param {String} fragment
  * @returns {undefined}
  */
QUrl.prototype.setFragment = function(fragment){return undefined;};

/**
  * @name setHost
  * @function
  * @memberOf QUrl.prototype
  * @param {String} host
  * @returns {undefined}
  */
QUrl.prototype.setHost = function(host){return undefined;};

/**
  * @name setPassword
  * @function
  * @memberOf QUrl.prototype
  * @param {String} password
  * @returns {undefined}
  */
QUrl.prototype.setPassword = function(password){return undefined;};

/**
  * @name setPath
  * @function
  * @memberOf QUrl.prototype
  * @param {String} path
  * @returns {undefined}
  */
QUrl.prototype.setPath = function(path){return undefined;};

/**
  * @name setPort
  * @function
  * @memberOf QUrl.prototype
  * @param {Numeric} port
  * @returns {undefined}
  */
QUrl.prototype.setPort = function(port){return undefined;};

/**
  * @name setQueryDelimiters
  * @function
  * @memberOf QUrl.prototype
  * @param {String} valueDelimiter
  * @param {String} pairDelimiter
  * @returns {undefined}
  */
QUrl.prototype.setQueryDelimiters = function(valueDelimiter, pairDelimiter){return undefined;};

/**
  * @name setQueryItems
  * @function
  * @memberOf QUrl.prototype
  * @param {Array} query
  * @returns {undefined}
  */
QUrl.prototype.setQueryItems = function(query){return undefined;};

/**
  * @name setScheme
  * @function
  * @memberOf QUrl.prototype
  * @param {String} scheme
  * @returns {undefined}
  */
QUrl.prototype.setScheme = function(scheme){return undefined;};

/**
  * @name setUrl
  * @function
  * @memberOf QUrl.prototype
  * @param {String} url
  * @returns {undefined}
  */
QUrl.prototype.setUrl = function(url){return undefined;};

/**
  * @name setUserInfo
  * @function
  * @memberOf QUrl.prototype
  * @param {String} userInfo
  * @returns {undefined}
  */
QUrl.prototype.setUserInfo = function(userInfo){return undefined;};

/**
  * @name setUserName
  * @function
  * @memberOf QUrl.prototype
  * @param {String} userName
  * @returns {undefined}
  */
QUrl.prototype.setUserName = function(userName){return undefined;};

/**
  * @name swap
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl} other
  * @returns {undefined}
  */
QUrl.prototype.swap = function(other){return undefined;};

/**
  * @name toEncoded
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl.FormattingOptions} options
  * @returns {QByteArray}
  */
QUrl.prototype.toEncoded = function(options){return new QByteArray();};

/**
  * @name toLocalFile
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.toLocalFile = function(){return new String();};

/**
  * @name toString
  * @function
  * @memberOf QUrl.prototype
  * @param {QUrl.FormattingOptions} options
  * @returns {String}
  */
QUrl.prototype.toString = function(options){return new String();};

/**
  * @name topLevelDomain
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.topLevelDomain = function(){return new String();};

/**
  * @name userInfo
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.userInfo = function(){return new String();};

/**
  * @name userName
  * @function
  * @memberOf QUrl.prototype
  * @returns {String}
  */
QUrl.prototype.userName = function(){return new String();};

/**
  * @name writeTo
  * @function
  * @memberOf QUrl.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QUrl.prototype.writeTo = function(arg__1){return undefined;};

