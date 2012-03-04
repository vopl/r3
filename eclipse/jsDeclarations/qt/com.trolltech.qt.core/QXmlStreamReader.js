/**
  * @name QXmlStreamReader
  * @constructor
  */
function QXmlStreamReader(){return undefined;};

/**
  * @name QXmlStreamReader^1
  * @constructor
  * @param {QIODevice} device
  */
function QXmlStreamReader(device){return undefined;};

/**
  * @name QXmlStreamReader^2
  * @constructor
  * @param {QByteArray} data
  */
function QXmlStreamReader(data){return undefined;};

/**
  * @name QXmlStreamReader^3
  * @constructor
  * @param {String} data
  */
function QXmlStreamReader(data){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QXmlStreamReader
  * @name NoError
  * @see QXmlStreamReader#Error
  * @type Number
  */
QXmlStreamReader.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QXmlStreamReader
  * @name UnexpectedElementError
  * @see QXmlStreamReader#Error
  * @type Number
  */
QXmlStreamReader.UnexpectedElementError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QXmlStreamReader
  * @name CustomError
  * @see QXmlStreamReader#Error
  * @type Number
  */
QXmlStreamReader.CustomError = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QXmlStreamReader
  * @name NotWellFormedError
  * @see QXmlStreamReader#Error
  * @type Number
  */
QXmlStreamReader.NotWellFormedError = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QXmlStreamReader
  * @name PrematureEndOfDocumentError
  * @see QXmlStreamReader#Error
  * @type Number
  */
QXmlStreamReader.PrematureEndOfDocumentError = 0x4;

/**
  * @constructor 
  * @memberOf QXmlStreamReader
  * @name Error
  */
QXmlStreamReader.Error = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QXmlStreamReader
  * @name NoToken
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.NoToken = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QXmlStreamReader
  * @name Invalid
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.Invalid = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QXmlStreamReader
  * @name StartDocument
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.StartDocument = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QXmlStreamReader
  * @name EndDocument
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.EndDocument = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QXmlStreamReader
  * @name StartElement
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.StartElement = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QXmlStreamReader
  * @name EndElement
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.EndElement = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QXmlStreamReader
  * @name Characters
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.Characters = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QXmlStreamReader
  * @name Comment
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.Comment = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QXmlStreamReader
  * @name DTD
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.DTD = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QXmlStreamReader
  * @name EntityReference
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.EntityReference = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QXmlStreamReader
  * @name ProcessingInstruction
  * @see QXmlStreamReader#TokenType
  * @type Number
  */
QXmlStreamReader.ProcessingInstruction = 0xa;

/**
  * @constructor 
  * @memberOf QXmlStreamReader
  * @name TokenType
  */
QXmlStreamReader.TokenType = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QXmlStreamReader
  * @name ErrorOnUnexpectedElement
  * @see QXmlStreamReader#ReadElementTextBehaviour
  * @type Number
  */
QXmlStreamReader.ErrorOnUnexpectedElement = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QXmlStreamReader
  * @name IncludeChildElements
  * @see QXmlStreamReader#ReadElementTextBehaviour
  * @type Number
  */
QXmlStreamReader.IncludeChildElements = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QXmlStreamReader
  * @name SkipChildElements
  * @see QXmlStreamReader#ReadElementTextBehaviour
  * @type Number
  */
QXmlStreamReader.SkipChildElements = 0x2;

/**
  * @constructor 
  * @memberOf QXmlStreamReader
  * @name ReadElementTextBehaviour
  */
QXmlStreamReader.ReadElementTextBehaviour = function(value){;};



/**
  * @name addData
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {QByteArray} data
  * @returns {undefined}
  */
QXmlStreamReader.prototype.addData = function(data){return undefined;};

/**
  * @name addExtraNamespaceDeclaration
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {QXmlStreamNamespaceDeclaration} extraNamespaceDeclaraction
  * @returns {undefined}
  */
QXmlStreamReader.prototype.addExtraNamespaceDeclaration = function(extraNamespaceDeclaraction){return undefined;};

/**
  * @name addExtraNamespaceDeclarations
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {Array} extraNamespaceDeclaractions
  * @returns {undefined}
  */
QXmlStreamReader.prototype.addExtraNamespaceDeclarations = function(extraNamespaceDeclaractions){return undefined;};

/**
  * @name atEnd
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.atEnd = function(){return new Boolean();};

/**
  * @name attributes
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {QXmlStreamAttributes}
  */
QXmlStreamReader.prototype.attributes = function(){return new QXmlStreamAttributes();};

/**
  * @name characterOffset
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Numeric}
  */
QXmlStreamReader.prototype.characterOffset = function(){return new Numeric();};

/**
  * @name clear
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {undefined}
  */
QXmlStreamReader.prototype.clear = function(){return undefined;};

/**
  * @name columnNumber
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Numeric}
  */
QXmlStreamReader.prototype.columnNumber = function(){return new Numeric();};

/**
  * @name device
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {QIODevice}
  */
QXmlStreamReader.prototype.device = function(){return new QIODevice();};

/**
  * @name documentEncoding
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.documentEncoding = function(){return new String();};

/**
  * @name documentVersion
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.documentVersion = function(){return new String();};

/**
  * @name dtdName
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.dtdName = function(){return new String();};

/**
  * @name dtdPublicId
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.dtdPublicId = function(){return new String();};

/**
  * @name dtdSystemId
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.dtdSystemId = function(){return new String();};

/**
  * @name entityDeclarations
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Array}
  */
QXmlStreamReader.prototype.entityDeclarations = function(){return new Array();};

/**
  * @name entityResolver
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {QXmlStreamEntityResolver}
  */
QXmlStreamReader.prototype.entityResolver = function(){return new QXmlStreamEntityResolver();};

/**
  * @name error
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {QStateMachine.Error}
  */
QXmlStreamReader.prototype.error = function(){return new QStateMachine.Error();};

/**
  * @name errorString
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.errorString = function(){return new String();};

/**
  * @name hasError
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.hasError = function(){return new Boolean();};

/**
  * @name isCDATA
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isCDATA = function(){return new Boolean();};

/**
  * @name isCharacters
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isCharacters = function(){return new Boolean();};

/**
  * @name isComment
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isComment = function(){return new Boolean();};

/**
  * @name isDTD
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isDTD = function(){return new Boolean();};

/**
  * @name isEndDocument
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isEndDocument = function(){return new Boolean();};

/**
  * @name isEndElement
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isEndElement = function(){return new Boolean();};

/**
  * @name isEntityReference
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isEntityReference = function(){return new Boolean();};

/**
  * @name isProcessingInstruction
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isProcessingInstruction = function(){return new Boolean();};

/**
  * @name isStandaloneDocument
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isStandaloneDocument = function(){return new Boolean();};

/**
  * @name isStartDocument
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isStartDocument = function(){return new Boolean();};

/**
  * @name isStartElement
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isStartElement = function(){return new Boolean();};

/**
  * @name isWhitespace
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.isWhitespace = function(){return new Boolean();};

/**
  * @name lineNumber
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Numeric}
  */
QXmlStreamReader.prototype.lineNumber = function(){return new Numeric();};

/**
  * @name name
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.name = function(){return new String();};

/**
  * @name namespaceDeclarations
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Array}
  */
QXmlStreamReader.prototype.namespaceDeclarations = function(){return new Array();};

/**
  * @name namespaceProcessing
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.namespaceProcessing = function(){return new Boolean();};

/**
  * @name namespaceUri
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.namespaceUri = function(){return new String();};

/**
  * @name notationDeclarations
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Array}
  */
QXmlStreamReader.prototype.notationDeclarations = function(){return new Array();};

/**
  * @name prefix
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.prefix = function(){return new String();};

/**
  * @name processingInstructionData
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.processingInstructionData = function(){return new String();};

/**
  * @name processingInstructionTarget
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.processingInstructionTarget = function(){return new String();};

/**
  * @name qualifiedName
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.qualifiedName = function(){return new String();};

/**
  * @name raiseError
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {String} message
  * @returns {undefined}
  */
QXmlStreamReader.prototype.raiseError = function(message){return undefined;};

/**
  * @name readElementText
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.readElementText = function(){return new String();};

/**
  * @name readNext
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {QXmlStreamReader.TokenType}
  */
QXmlStreamReader.prototype.readNext = function(){return new QXmlStreamReader.TokenType();};

/**
  * @name readNextStartElement
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {Boolean}
  */
QXmlStreamReader.prototype.readNextStartElement = function(){return new Boolean();};

/**
  * @name setDevice
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {QIODevice} device
  * @returns {undefined}
  */
QXmlStreamReader.prototype.setDevice = function(device){return undefined;};

/**
  * @name setEntityResolver
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {QXmlStreamEntityResolver} resolver
  * @returns {undefined}
  */
QXmlStreamReader.prototype.setEntityResolver = function(resolver){return undefined;};

/**
  * @name setNamespaceProcessing
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @param {Boolean} arg__1
  * @returns {undefined}
  */
QXmlStreamReader.prototype.setNamespaceProcessing = function(arg__1){return undefined;};

/**
  * @name skipCurrentElement
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {undefined}
  */
QXmlStreamReader.prototype.skipCurrentElement = function(){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.text = function(){return new String();};

/**
  * @name tokenString
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {String}
  */
QXmlStreamReader.prototype.tokenString = function(){return new String();};

/**
  * @name tokenType
  * @function
  * @memberOf QXmlStreamReader.prototype
  * @returns {QXmlStreamReader.TokenType}
  */
QXmlStreamReader.prototype.tokenType = function(){return new QXmlStreamReader.TokenType();};

