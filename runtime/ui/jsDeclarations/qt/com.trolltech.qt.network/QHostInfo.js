/**
  * @name QHostInfo
  * @constructor
  * @param {QHostInfo} d
  */
function QHostInfo(d){return undefined;};

/**
  * @name QHostInfo^1
  * @constructor
  * @param {Numeric} lookupId
  */
function QHostInfo(lookupId){return undefined;};

/**
  * @name abortHostLookup
  * @function
  * @memberOf QHostInfo
  * @param {Numeric} lookupId
  * @returns {undefined}
  */
QHostInfo.abortHostLookup = function(lookupId){return undefined;};

/**
  * @name fromName
  * @function
  * @memberOf QHostInfo
  * @param {String} name
  * @returns {QHostInfo}
  */
QHostInfo.fromName = function(name){return new QHostInfo();};

/**
  * @name localDomainName
  * @function
  * @memberOf QHostInfo
  * @returns {String}
  */
QHostInfo.localDomainName = function(){return new String();};

/**
  * @name localHostName
  * @function
  * @memberOf QHostInfo
  * @returns {String}
  */
QHostInfo.localHostName = function(){return new String();};

/**
  * @name lookupHost
  * @function
  * @memberOf QHostInfo
  * @param {String} name
  * @param {QObject} receiver
  * @param {String} member
  * @returns {Numeric}
  */
QHostInfo.lookupHost = function(name, receiver, member){return new Numeric();};

/**
  * @default 0x0
  * @constant
  * @memberOf QHostInfo
  * @name NoError
  * @see QHostInfo#HostInfoError
  * @type Number
  */
QHostInfo.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QHostInfo
  * @name HostNotFound
  * @see QHostInfo#HostInfoError
  * @type Number
  */
QHostInfo.HostNotFound = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QHostInfo
  * @name UnknownError
  * @see QHostInfo#HostInfoError
  * @type Number
  */
QHostInfo.UnknownError = 0x2;

/**
  * @constructor 
  * @memberOf QHostInfo
  * @name HostInfoError
  */
QHostInfo.HostInfoError = function(value){;};



/**
  * @name addresses
  * @function
  * @memberOf QHostInfo.prototype
  * @returns {Array}
  */
QHostInfo.prototype.addresses = function(){return new Array();};

/**
  * @name error
  * @function
  * @memberOf QHostInfo.prototype
  * @returns {QHostInfo.HostInfoError}
  */
QHostInfo.prototype.error = function(){return new QHostInfo.HostInfoError();};

/**
  * @name errorString
  * @function
  * @memberOf QHostInfo.prototype
  * @returns {String}
  */
QHostInfo.prototype.errorString = function(){return new String();};

/**
  * @name hostName
  * @function
  * @memberOf QHostInfo.prototype
  * @returns {String}
  */
QHostInfo.prototype.hostName = function(){return new String();};

/**
  * @name lookupId
  * @function
  * @memberOf QHostInfo.prototype
  * @returns {Numeric}
  */
QHostInfo.prototype.lookupId = function(){return new Numeric();};

/**
  * @name setAddresses
  * @function
  * @memberOf QHostInfo.prototype
  * @param {Array} addresses
  * @returns {undefined}
  */
QHostInfo.prototype.setAddresses = function(addresses){return undefined;};

/**
  * @name setError
  * @function
  * @memberOf QHostInfo.prototype
  * @param {QHostInfo.HostInfoError} error
  * @returns {undefined}
  */
QHostInfo.prototype.setError = function(error){return undefined;};

/**
  * @name setErrorString
  * @function
  * @memberOf QHostInfo.prototype
  * @param {String} errorString
  * @returns {undefined}
  */
QHostInfo.prototype.setErrorString = function(errorString){return undefined;};

/**
  * @name setHostName
  * @function
  * @memberOf QHostInfo.prototype
  * @param {String} name
  * @returns {undefined}
  */
QHostInfo.prototype.setHostName = function(name){return undefined;};

/**
  * @name setLookupId
  * @function
  * @memberOf QHostInfo.prototype
  * @param {Numeric} id
  * @returns {undefined}
  */
QHostInfo.prototype.setLookupId = function(id){return undefined;};

