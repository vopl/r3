/**
  * @name QXmlNodeModelIndex
  * @constructor
  */
function QXmlNodeModelIndex(){return undefined;};

/**
  * @name QXmlNodeModelIndex^1
  * @constructor
  * @param {QXmlNodeModelIndex} other
  */
function QXmlNodeModelIndex(other){return undefined;};

/**
  * @default 1
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Attribute
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.Attribute = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Comment
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.Comment = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Document
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.Document = 0x4;

/**
  * @default 8
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Element
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.Element = 0x8;

/**
  * @default 16
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Namespace
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.Namespace = 0x10;

/**
  * @default 32
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name ProcessingInstruction
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.ProcessingInstruction = 0x20;

/**
  * @default 64
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Text
  * @see QXmlNodeModelIndex#NodeKind
  * @type Number
  */
QXmlNodeModelIndex.Text = 0x40;

/**
  * @constructor 
  * @memberOf QXmlNodeModelIndex
  * @name NodeKind
  */
QXmlNodeModelIndex.NodeKind = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Precedes
  * @see QXmlNodeModelIndex#DocumentOrder
  * @type Number
  */
QXmlNodeModelIndex.Precedes = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Is
  * @see QXmlNodeModelIndex#DocumentOrder
  * @type Number
  */
QXmlNodeModelIndex.Is = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QXmlNodeModelIndex
  * @name Follows
  * @see QXmlNodeModelIndex#DocumentOrder
  * @type Number
  */
QXmlNodeModelIndex.Follows = 0x1;

/**
  * @constructor 
  * @memberOf QXmlNodeModelIndex
  * @name DocumentOrder
  */
QXmlNodeModelIndex.DocumentOrder = function(value){;};



/**
  * @name additionalData
  * @function
  * @memberOf QXmlNodeModelIndex.prototype
  * @returns {Numeric}
  */
QXmlNodeModelIndex.prototype.additionalData = function(){return new Numeric();};

/**
  * @name data
  * @function
  * @memberOf QXmlNodeModelIndex.prototype
  * @returns {Numeric}
  */
QXmlNodeModelIndex.prototype.data = function(){return new Numeric();};

/**
  * @name isNull
  * @function
  * @memberOf QXmlNodeModelIndex.prototype
  * @returns {Boolean}
  */
QXmlNodeModelIndex.prototype.isNull = function(){return new Boolean();};

/**
  * @name model
  * @function
  * @memberOf QXmlNodeModelIndex.prototype
  * @returns {QAbstractXmlNodeModel}
  */
QXmlNodeModelIndex.prototype.model = function(){return new QAbstractXmlNodeModel();};

/**
  * @name operator_equal
  * @function
  * @memberOf QXmlNodeModelIndex.prototype
  * @param {QXmlNodeModelIndex} other
  * @returns {Boolean}
  */
QXmlNodeModelIndex.prototype.operator_equal = function(other){return new Boolean();};

