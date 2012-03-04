/**
  * @name QDomNode
  * @constructor
  */
function QDomNode(){return undefined;};

/**
  * @name QDomNode^1
  * @constructor
  * @param {QDomNode} arg__1
  */
function QDomNode(arg__1){return undefined;};

/**
  * @default 1
  * @constant
  * @memberOf QDomNode
  * @name ElementNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.ElementNode = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QDomNode
  * @name AttributeNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.AttributeNode = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QDomNode
  * @name TextNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.TextNode = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QDomNode
  * @name CDATASectionNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.CDATASectionNode = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf QDomNode
  * @name EntityReferenceNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.EntityReferenceNode = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf QDomNode
  * @name EntityNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.EntityNode = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QDomNode
  * @name ProcessingInstructionNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.ProcessingInstructionNode = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf QDomNode
  * @name CommentNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.CommentNode = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf QDomNode
  * @name DocumentNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.DocumentNode = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf QDomNode
  * @name DocumentTypeNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.DocumentTypeNode = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf QDomNode
  * @name DocumentFragmentNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.DocumentFragmentNode = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf QDomNode
  * @name NotationNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.NotationNode = 0xc;

/**
  * @default 21
  * @constant
  * @memberOf QDomNode
  * @name BaseNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.BaseNode = 0x15;

/**
  * @default 22
  * @constant
  * @memberOf QDomNode
  * @name CharacterDataNode
  * @see QDomNode#NodeType
  * @type Number
  */
QDomNode.CharacterDataNode = 0x16;

/**
  * @constructor 
  * @memberOf QDomNode
  * @name NodeType
  */
QDomNode.NodeType = function(value){;};



/**
  * @default 1
  * @constant
  * @memberOf QDomNode
  * @name EncodingFromDocument
  * @see QDomNode#EncodingPolicy
  * @type Number
  */
QDomNode.EncodingFromDocument = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QDomNode
  * @name EncodingFromTextStream
  * @see QDomNode#EncodingPolicy
  * @type Number
  */
QDomNode.EncodingFromTextStream = 0x2;

/**
  * @constructor 
  * @memberOf QDomNode
  * @name EncodingPolicy
  */
QDomNode.EncodingPolicy = function(value){;};



/**
  * @name appendChild
  * @function
  * @memberOf QDomNode.prototype
  * @param {QDomNode} newChild
  * @returns {QDomNode}
  */
QDomNode.prototype.appendChild = function(newChild){return new QDomNode();};

/**
  * @name childNodes
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNodeList}
  */
QDomNode.prototype.childNodes = function(){return new QDomNodeList();};

/**
  * @name clear
  * @function
  * @memberOf QDomNode.prototype
  * @returns {undefined}
  */
QDomNode.prototype.clear = function(){return undefined;};

/**
  * @name cloneNode
  * @function
  * @memberOf QDomNode.prototype
  * @param {Boolean} deep
  * @returns {QDomNode}
  */
QDomNode.prototype.cloneNode = function(deep){return new QDomNode();};

/**
  * @name columnNumber
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Numeric}
  */
QDomNode.prototype.columnNumber = function(){return new Numeric();};

/**
  * @name firstChild
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNode}
  */
QDomNode.prototype.firstChild = function(){return new QDomNode();};

/**
  * @name firstChildElement
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} tagName
  * @returns {QDomElement}
  */
QDomNode.prototype.firstChildElement = function(tagName){return new QDomElement();};

/**
  * @name hasAttributes
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.hasAttributes = function(){return new Boolean();};

/**
  * @name hasChildNodes
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.hasChildNodes = function(){return new Boolean();};

/**
  * @name insertAfter
  * @function
  * @memberOf QDomNode.prototype
  * @param {QDomNode} newChild
  * @param {QDomNode} refChild
  * @returns {QDomNode}
  */
QDomNode.prototype.insertAfter = function(newChild, refChild){return new QDomNode();};

/**
  * @name insertBefore
  * @function
  * @memberOf QDomNode.prototype
  * @param {QDomNode} newChild
  * @param {QDomNode} refChild
  * @returns {QDomNode}
  */
QDomNode.prototype.insertBefore = function(newChild, refChild){return new QDomNode();};

/**
  * @name isAttr
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isAttr = function(){return new Boolean();};

/**
  * @name isCDATASection
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isCDATASection = function(){return new Boolean();};

/**
  * @name isCharacterData
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isCharacterData = function(){return new Boolean();};

/**
  * @name isComment
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isComment = function(){return new Boolean();};

/**
  * @name isDocument
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isDocument = function(){return new Boolean();};

/**
  * @name isDocumentFragment
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isDocumentFragment = function(){return new Boolean();};

/**
  * @name isDocumentType
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isDocumentType = function(){return new Boolean();};

/**
  * @name isElement
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isElement = function(){return new Boolean();};

/**
  * @name isEntity
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isEntity = function(){return new Boolean();};

/**
  * @name isEntityReference
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isEntityReference = function(){return new Boolean();};

/**
  * @name isNotation
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isNotation = function(){return new Boolean();};

/**
  * @name isNull
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isNull = function(){return new Boolean();};

/**
  * @name isProcessingInstruction
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isProcessingInstruction = function(){return new Boolean();};

/**
  * @name isSupported
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} feature
  * @param {String} version
  * @returns {Boolean}
  */
QDomNode.prototype.isSupported = function(feature, version){return new Boolean();};

/**
  * @name isText
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Boolean}
  */
QDomNode.prototype.isText = function(){return new Boolean();};

/**
  * @name lastChild
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNode}
  */
QDomNode.prototype.lastChild = function(){return new QDomNode();};

/**
  * @name lastChildElement
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} tagName
  * @returns {QDomElement}
  */
QDomNode.prototype.lastChildElement = function(tagName){return new QDomElement();};

/**
  * @name lineNumber
  * @function
  * @memberOf QDomNode.prototype
  * @returns {Numeric}
  */
QDomNode.prototype.lineNumber = function(){return new Numeric();};

/**
  * @name localName
  * @function
  * @memberOf QDomNode.prototype
  * @returns {String}
  */
QDomNode.prototype.localName = function(){return new String();};

/**
  * @name namedItem
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} name
  * @returns {QDomNode}
  */
QDomNode.prototype.namedItem = function(name){return new QDomNode();};

/**
  * @name namespaceURI
  * @function
  * @memberOf QDomNode.prototype
  * @returns {String}
  */
QDomNode.prototype.namespaceURI = function(){return new String();};

/**
  * @name nextSibling
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNode}
  */
QDomNode.prototype.nextSibling = function(){return new QDomNode();};

/**
  * @name nextSiblingElement
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} taName
  * @returns {QDomElement}
  */
QDomNode.prototype.nextSiblingElement = function(taName){return new QDomElement();};

/**
  * @name nodeName
  * @function
  * @memberOf QDomNode.prototype
  * @returns {String}
  */
QDomNode.prototype.nodeName = function(){return new String();};

/**
  * @name nodeType
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNode.NodeType}
  */
QDomNode.prototype.nodeType = function(){return new QDomNode.NodeType();};

/**
  * @name nodeValue
  * @function
  * @memberOf QDomNode.prototype
  * @returns {String}
  */
QDomNode.prototype.nodeValue = function(){return new String();};

/**
  * @name normalize
  * @function
  * @memberOf QDomNode.prototype
  * @returns {undefined}
  */
QDomNode.prototype.normalize = function(){return undefined;};

/**
  * @name operator_equal
  * @function
  * @memberOf QDomNode.prototype
  * @param {QDomNode} arg__1
  * @returns {Boolean}
  */
QDomNode.prototype.operator_equal = function(arg__1){return new Boolean();};

/**
  * @name ownerDocument
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomDocument}
  */
QDomNode.prototype.ownerDocument = function(){return new QDomDocument();};

/**
  * @name parentNode
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNode}
  */
QDomNode.prototype.parentNode = function(){return new QDomNode();};

/**
  * @name prefix
  * @function
  * @memberOf QDomNode.prototype
  * @returns {String}
  */
QDomNode.prototype.prefix = function(){return new String();};

/**
  * @name previousSibling
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNode}
  */
QDomNode.prototype.previousSibling = function(){return new QDomNode();};

/**
  * @name previousSiblingElement
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} tagName
  * @returns {QDomElement}
  */
QDomNode.prototype.previousSiblingElement = function(tagName){return new QDomElement();};

/**
  * @name removeChild
  * @function
  * @memberOf QDomNode.prototype
  * @param {QDomNode} oldChild
  * @returns {QDomNode}
  */
QDomNode.prototype.removeChild = function(oldChild){return new QDomNode();};

/**
  * @name replaceChild
  * @function
  * @memberOf QDomNode.prototype
  * @param {QDomNode} newChild
  * @param {QDomNode} oldChild
  * @returns {QDomNode}
  */
QDomNode.prototype.replaceChild = function(newChild, oldChild){return new QDomNode();};

/**
  * @name save
  * @function
  * @memberOf QDomNode.prototype
  * @param {QTextStream} arg__1
  * @param {Numeric} arg__2
  * @returns {undefined}
  */
QDomNode.prototype.save = function(arg__1, arg__2){return undefined;};

/**
  * @name setNodeValue
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} arg__1
  * @returns {undefined}
  */
QDomNode.prototype.setNodeValue = function(arg__1){return undefined;};

/**
  * @name setPrefix
  * @function
  * @memberOf QDomNode.prototype
  * @param {String} pre
  * @returns {undefined}
  */
QDomNode.prototype.setPrefix = function(pre){return undefined;};

/**
  * @name toAttr
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomAttr}
  */
QDomNode.prototype.toAttr = function(){return new QDomAttr();};

/**
  * @name toCDATASection
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomCDATASection}
  */
QDomNode.prototype.toCDATASection = function(){return new QDomCDATASection();};

/**
  * @name toCharacterData
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomCharacterData}
  */
QDomNode.prototype.toCharacterData = function(){return new QDomCharacterData();};

/**
  * @name toComment
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomComment}
  */
QDomNode.prototype.toComment = function(){return new QDomComment();};

/**
  * @name toDocument
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomDocument}
  */
QDomNode.prototype.toDocument = function(){return new QDomDocument();};

/**
  * @name toDocumentFragment
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomDocumentFragment}
  */
QDomNode.prototype.toDocumentFragment = function(){return new QDomDocumentFragment();};

/**
  * @name toDocumentType
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomDocumentType}
  */
QDomNode.prototype.toDocumentType = function(){return new QDomDocumentType();};

/**
  * @name toElement
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomElement}
  */
QDomNode.prototype.toElement = function(){return new QDomElement();};

/**
  * @name toEntity
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomEntity}
  */
QDomNode.prototype.toEntity = function(){return new QDomEntity();};

/**
  * @name toEntityReference
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomEntityReference}
  */
QDomNode.prototype.toEntityReference = function(){return new QDomEntityReference();};

/**
  * @name toNotation
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomNotation}
  */
QDomNode.prototype.toNotation = function(){return new QDomNotation();};

/**
  * @name toProcessingInstruction
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomProcessingInstruction}
  */
QDomNode.prototype.toProcessingInstruction = function(){return new QDomProcessingInstruction();};

/**
  * @name toText
  * @function
  * @memberOf QDomNode.prototype
  * @returns {QDomText}
  */
QDomNode.prototype.toText = function(){return new QDomText();};

/**
  * @name writeTo
  * @function
  * @memberOf QDomNode.prototype
  * @param {QTextStream} arg__1
  * @returns {undefined}
  */
QDomNode.prototype.writeTo = function(arg__1){return undefined;};

