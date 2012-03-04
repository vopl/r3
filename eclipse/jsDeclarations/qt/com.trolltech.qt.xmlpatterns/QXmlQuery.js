/**
  * @name QXmlQuery
  * @constructor
  */
function QXmlQuery(){return undefined;};

/**
  * @name QXmlQuery^1
  * @constructor
  * @param {QXmlQuery.QueryLanguage} queryLanguage
  * @param {QXmlNamePool} np
  */
function QXmlQuery(queryLanguage, np){return undefined;};

/**
  * @name QXmlQuery^2
  * @constructor
  * @param {QXmlNamePool} np
  */
function QXmlQuery(np){return undefined;};

/**
  * @name QXmlQuery^3
  * @constructor
  * @param {QXmlQuery} other
  */
function QXmlQuery(other){return undefined;};

/**
  * @default 1
  * @constant
  * @memberOf QXmlQuery
  * @name XQuery10
  * @see QXmlQuery#QueryLanguage
  * @type Number
  */
QXmlQuery.XQuery10 = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QXmlQuery
  * @name XSLT20
  * @see QXmlQuery#QueryLanguage
  * @type Number
  */
QXmlQuery.XSLT20 = 0x2;

/**
  * @default 1024
  * @constant
  * @memberOf QXmlQuery
  * @name XmlSchema11IdentityConstraintSelector
  * @see QXmlQuery#QueryLanguage
  * @type Number
  */
QXmlQuery.XmlSchema11IdentityConstraintSelector = 0x400;

/**
  * @default 2048
  * @constant
  * @memberOf QXmlQuery
  * @name XmlSchema11IdentityConstraintField
  * @see QXmlQuery#QueryLanguage
  * @type Number
  */
QXmlQuery.XmlSchema11IdentityConstraintField = 0x800;

/**
  * @default 4096
  * @constant
  * @memberOf QXmlQuery
  * @name XPath20
  * @see QXmlQuery#QueryLanguage
  * @type Number
  */
QXmlQuery.XPath20 = 0x1000;

/**
  * @constructor 
  * @memberOf QXmlQuery
  * @name QueryLanguage
  */
QXmlQuery.QueryLanguage = function(value){;};



/**
  * @name bindVariable
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {String} localName
  * @param {QIODevice} arg__2
  * @returns {undefined}
  */
QXmlQuery.prototype.bindVariable = function(localName, arg__2){return undefined;};

/**
  * @name evaluateTo
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QIODevice} target
  * @returns {Boolean}
  */
QXmlQuery.prototype.evaluateTo = function(target){return new Boolean();};

/**
  * @name initialTemplateName
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {QXmlName}
  */
QXmlQuery.prototype.initialTemplateName = function(){return new QXmlName();};

/**
  * @name isValid
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {Boolean}
  */
QXmlQuery.prototype.isValid = function(){return new Boolean();};

/**
  * @name messageHandler
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {QAbstractMessageHandler}
  */
QXmlQuery.prototype.messageHandler = function(){return new QAbstractMessageHandler();};

/**
  * @name namePool
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {QXmlNamePool}
  */
QXmlQuery.prototype.namePool = function(){return new QXmlNamePool();};

/**
  * @name networkAccessManager
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {QNetworkAccessManager}
  */
QXmlQuery.prototype.networkAccessManager = function(){return new QNetworkAccessManager();};

/**
  * @name operator_assign
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QXmlQuery} other
  * @returns {QXmlQuery}
  */
QXmlQuery.prototype.operator_assign = function(other){return new QXmlQuery();};

/**
  * @name queryLanguage
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {QXmlQuery.QueryLanguage}
  */
QXmlQuery.prototype.queryLanguage = function(){return new QXmlQuery.QueryLanguage();};

/**
  * @name setFocus
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QIODevice} document
  * @returns {Boolean}
  */
QXmlQuery.prototype.setFocus = function(document){return new Boolean();};

/**
  * @name setInitialTemplateName
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {String} name
  * @returns {undefined}
  */
QXmlQuery.prototype.setInitialTemplateName = function(name){return undefined;};

/**
  * @name setMessageHandler
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QAbstractMessageHandler} messageHandler
  * @returns {undefined}
  */
QXmlQuery.prototype.setMessageHandler = function(messageHandler){return undefined;};

/**
  * @name setNetworkAccessManager
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QNetworkAccessManager} newManager
  * @returns {undefined}
  */
QXmlQuery.prototype.setNetworkAccessManager = function(newManager){return undefined;};

/**
  * @name setQuery
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QIODevice} sourceCode
  * @param {QUrl} documentURI
  * @returns {undefined}
  */
QXmlQuery.prototype.setQuery = function(sourceCode, documentURI){return undefined;};

/**
  * @name setUriResolver
  * @function
  * @memberOf QXmlQuery.prototype
  * @param {QAbstractUriResolver} resolver
  * @returns {undefined}
  */
QXmlQuery.prototype.setUriResolver = function(resolver){return undefined;};

/**
  * @name uriResolver
  * @function
  * @memberOf QXmlQuery.prototype
  * @returns {QAbstractUriResolver}
  */
QXmlQuery.prototype.uriResolver = function(){return new QAbstractUriResolver();};

