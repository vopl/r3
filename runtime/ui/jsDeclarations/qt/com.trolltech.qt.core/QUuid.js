/**
  * @name QUuid
  * @constructor
  */
function QUuid(){return undefined;};

/**
  * @name QUuid^1
  * @constructor
  * @param {QByteArray} arg__1
  */
function QUuid(arg__1){return undefined;};

/**
  * @name QUuid^2
  * @constructor
  * @param {String} arg__1
  */
function QUuid(arg__1){return undefined;};

/**
  * @name QUuid^3
  * @constructor
  * @param {Numeric} l
  * @param {Numeric} w1
  * @param {Numeric} w2
  * @param {Numeric} b1
  * @param {Numeric} b2
  * @param {Numeric} b3
  * @param {Numeric} b4
  * @param {Numeric} b5
  * @param {Numeric} b6
  * @param {Numeric} b7
  * @param {Numeric} b8
  */
function QUuid(l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8){return undefined;};

/**
  * @name createUuid
  * @function
  * @memberOf QUuid
  * @returns {QUuid}
  */
QUuid.createUuid = function(){return new QUuid();};

/**
  * @name fromRfc4122
  * @function
  * @memberOf QUuid
  * @param {QByteArray} arg__1
  * @returns {QUuid}
  */
QUuid.fromRfc4122 = function(arg__1){return new QUuid();};

/**
  * @default -1
  * @constant
  * @memberOf QUuid
  * @name VarUnknown
  * @see QUuid#Variant
  * @type Number
  */
QUuid.VarUnknown = 0xffffffff;

/**
  * @default 0
  * @constant
  * @memberOf QUuid
  * @name NCS
  * @see QUuid#Variant
  * @type Number
  */
QUuid.NCS = 0x0;

/**
  * @default 2
  * @constant
  * @memberOf QUuid
  * @name DCE
  * @see QUuid#Variant
  * @type Number
  */
QUuid.DCE = 0x2;

/**
  * @default 6
  * @constant
  * @memberOf QUuid
  * @name Microsoft
  * @see QUuid#Variant
  * @type Number
  */
QUuid.Microsoft = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QUuid
  * @name Reserved
  * @see QUuid#Variant
  * @type Number
  */
QUuid.Reserved = 0x7;

/**
  * @constructor 
  * @memberOf QUuid
  * @name Variant
  */
QUuid.Variant = function(value){;};



/**
  * @default -1
  * @constant
  * @memberOf QUuid
  * @name VerUnknown
  * @see QUuid#Version
  * @type Number
  */
QUuid.VerUnknown = 0xffffffff;

/**
  * @default 1
  * @constant
  * @memberOf QUuid
  * @name Time
  * @see QUuid#Version
  * @type Number
  */
QUuid.Time = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QUuid
  * @name EmbeddedPOSIX
  * @see QUuid#Version
  * @type Number
  */
QUuid.EmbeddedPOSIX = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QUuid
  * @name Name
  * @see QUuid#Version
  * @type Number
  */
QUuid.Name = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QUuid
  * @name Random
  * @see QUuid#Version
  * @type Number
  */
QUuid.Random = 0x4;

/**
  * @constructor 
  * @memberOf QUuid
  * @name Version
  */
QUuid.Version = function(value){;};



/**
  * @name isNull
  * @function
  * @memberOf QUuid.prototype
  * @returns {Boolean}
  */
QUuid.prototype.isNull = function(){return new Boolean();};

/**
  * @name operator_equal
  * @function
  * @memberOf QUuid.prototype
  * @param {QUuid} orig
  * @returns {Boolean}
  */
QUuid.prototype.operator_equal = function(orig){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QUuid.prototype
  * @param {QUuid} other
  * @returns {Boolean}
  */
QUuid.prototype.operator_less = function(other){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QUuid.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QUuid.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name toByteArray
  * @function
  * @memberOf QUuid.prototype
  * @returns {QByteArray}
  */
QUuid.prototype.toByteArray = function(){return new QByteArray();};

/**
  * @name toRfc4122
  * @function
  * @memberOf QUuid.prototype
  * @returns {QByteArray}
  */
QUuid.prototype.toRfc4122 = function(){return new QByteArray();};

/**
  * @name toString
  * @function
  * @memberOf QUuid.prototype
  * @returns {String}
  */
QUuid.prototype.toString = function(){return new String();};

/**
  * @name variant
  * @function
  * @memberOf QUuid.prototype
  * @returns {QUuid.Variant}
  */
QUuid.prototype.variant = function(){return new QUuid.Variant();};

/**
  * @name version
  * @function
  * @memberOf QUuid.prototype
  * @returns {QStyleOptionViewItemV4.Version}
  */
QUuid.prototype.version = function(){return new QStyleOptionViewItemV4.Version();};

/**
  * @name writeTo
  * @function
  * @memberOf QUuid.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QUuid.prototype.writeTo = function(arg__1){return undefined;};

