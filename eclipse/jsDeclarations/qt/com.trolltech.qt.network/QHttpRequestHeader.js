/**
  * @name QHttpRequestHeader
  * @constructor
  * @extends QHttpHeader
  */
function QHttpRequestHeader(){return undefined;};

/**
  * @name QHttpRequestHeader^1
  * @constructor
  * @extends QHttpHeader
  * @param {QHttpRequestHeader} header
  */
function QHttpRequestHeader(header){return undefined;};

/**
  * @name QHttpRequestHeader^2
  * @constructor
  * @extends QHttpHeader
  * @param {String} method
  * @param {String} path
  * @param {Numeric} majorVer
  * @param {Numeric} minorVer
  */
function QHttpRequestHeader(method, path, majorVer, minorVer){return undefined;};

/**
  * @name QHttpRequestHeader^3
  * @constructor
  * @extends QHttpHeader
  * @param {String} str
  */
function QHttpRequestHeader(str){return undefined;};

QHttpRequestHeader.prototype = new QHttpHeader();

/**
  * @name method
  * @function
  * @memberOf QHttpRequestHeader.prototype
  * @returns {String}
  */
QHttpRequestHeader.prototype.method = function(){return new String();};

/**
  * @name path
  * @function
  * @memberOf QHttpRequestHeader.prototype
  * @returns {String}
  */
QHttpRequestHeader.prototype.path = function(){return new String();};

/**
  * @name setRequest
  * @function
  * @memberOf QHttpRequestHeader.prototype
  * @param {String} method
  * @param {String} path
  * @param {Numeric} majorVer
  * @param {Numeric} minorVer
  * @returns {undefined}
  */
QHttpRequestHeader.prototype.setRequest = function(method, path, majorVer, minorVer){return undefined;};

