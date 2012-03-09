/**
  * @name QHttpResponseHeader
  * @constructor
  * @extends QHttpHeader
  */
function QHttpResponseHeader(){return undefined;};

/**
  * @name QHttpResponseHeader^1
  * @constructor
  * @extends QHttpHeader
  * @param {QHttpResponseHeader} header
  */
function QHttpResponseHeader(header){return undefined;};

/**
  * @name QHttpResponseHeader^2
  * @constructor
  * @extends QHttpHeader
  * @param {String} str
  */
function QHttpResponseHeader(str){return undefined;};

/**
  * @name QHttpResponseHeader^3
  * @constructor
  * @extends QHttpHeader
  * @param {Numeric} code
  * @param {String} text
  * @param {Numeric} majorVer
  * @param {Numeric} minorVer
  */
function QHttpResponseHeader(code, text, majorVer, minorVer){return undefined;};

QHttpResponseHeader.prototype = new QHttpHeader();

/**
  * @name reasonPhrase
  * @function
  * @memberOf QHttpResponseHeader.prototype
  * @returns {String}
  */
QHttpResponseHeader.prototype.reasonPhrase = function(){return new String();};

/**
  * @name setStatusLine
  * @function
  * @memberOf QHttpResponseHeader.prototype
  * @param {Numeric} code
  * @param {String} text
  * @param {Numeric} majorVer
  * @param {Numeric} minorVer
  * @returns {undefined}
  */
QHttpResponseHeader.prototype.setStatusLine = function(code, text, majorVer, minorVer){return undefined;};

/**
  * @name statusCode
  * @function
  * @memberOf QHttpResponseHeader.prototype
  * @returns {Numeric}
  */
QHttpResponseHeader.prototype.statusCode = function(){return new Numeric();};

