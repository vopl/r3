/**
  * @name QXmlSchemaValidator
  * @constructor
  */
function QXmlSchemaValidator(){return undefined;};

/**
  * @name QXmlSchemaValidator^1
  * @constructor
  * @param {QXmlSchema} schema
  */
function QXmlSchemaValidator(schema){return undefined;};

/**
  * @name messageHandler
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @returns {QAbstractMessageHandler}
  */
QXmlSchemaValidator.prototype.messageHandler = function(){return new QAbstractMessageHandler();};

/**
  * @name namePool
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @returns {QXmlNamePool}
  */
QXmlSchemaValidator.prototype.namePool = function(){return new QXmlNamePool();};

/**
  * @name networkAccessManager
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @returns {QNetworkAccessManager}
  */
QXmlSchemaValidator.prototype.networkAccessManager = function(){return new QNetworkAccessManager();};

/**
  * @name schema
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @returns {QXmlSchema}
  */
QXmlSchemaValidator.prototype.schema = function(){return new QXmlSchema();};

/**
  * @name setMessageHandler
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @param {QAbstractMessageHandler} handler
  * @returns {undefined}
  */
QXmlSchemaValidator.prototype.setMessageHandler = function(handler){return undefined;};

/**
  * @name setNetworkAccessManager
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @param {QNetworkAccessManager} networkmanager
  * @returns {undefined}
  */
QXmlSchemaValidator.prototype.setNetworkAccessManager = function(networkmanager){return undefined;};

/**
  * @name setSchema
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @param {QXmlSchema} schema
  * @returns {undefined}
  */
QXmlSchemaValidator.prototype.setSchema = function(schema){return undefined;};

/**
  * @name setUriResolver
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @param {QAbstractUriResolver} resolver
  * @returns {undefined}
  */
QXmlSchemaValidator.prototype.setUriResolver = function(resolver){return undefined;};

/**
  * @name uriResolver
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @returns {QAbstractUriResolver}
  */
QXmlSchemaValidator.prototype.uriResolver = function(){return new QAbstractUriResolver();};

/**
  * @name validate
  * @function
  * @memberOf QXmlSchemaValidator.prototype
  * @param {QIODevice} source
  * @param {QUrl} documentUri
  * @returns {Boolean}
  */
QXmlSchemaValidator.prototype.validate = function(source, documentUri){return new Boolean();};

