/**
  * @class QTextCodec from package com.trolltech.qt.core
  */
var QTextCodec = {};

/**
  * @name availableCodecs
  * @function
  * @memberOf QTextCodec
  * @returns {Array}
  */
QTextCodec.availableCodecs = function(){return new Array();};

/**
  * @name availableMibs
  * @function
  * @memberOf QTextCodec
  * @returns {Array}
  */
QTextCodec.availableMibs = function(){return new Array();};

/**
  * @name codecForCStrings
  * @function
  * @memberOf QTextCodec
  * @returns {QTextCodec}
  */
QTextCodec.codecForCStrings = function(){return new QTextCodec();};

/**
  * @name codecForHtml
  * @function
  * @memberOf QTextCodec
  * @param {QByteArray} ba
  * @returns {QTextCodec}
  */
QTextCodec.codecForHtml = function(ba){return new QTextCodec();};

/**
  * @name codecForLocale
  * @function
  * @memberOf QTextCodec
  * @returns {QTextCodec}
  */
QTextCodec.codecForLocale = function(){return new QTextCodec();};

/**
  * @name codecForMib
  * @function
  * @memberOf QTextCodec
  * @param {Numeric} mib
  * @returns {QTextCodec}
  */
QTextCodec.codecForMib = function(mib){return new QTextCodec();};

/**
  * @name codecForName
  * @function
  * @memberOf QTextCodec
  * @param {QByteArray} name
  * @returns {QTextCodec}
  */
QTextCodec.codecForName = function(name){return new QTextCodec();};

/**
  * @name codecForUtfText
  * @function
  * @memberOf QTextCodec
  * @param {QByteArray} ba
  * @returns {QTextCodec}
  */
QTextCodec.codecForUtfText = function(ba){return new QTextCodec();};

/**
  * @name setCodecForCStrings
  * @function
  * @memberOf QTextCodec
  * @param {QTextCodec} c
  * @returns {undefined}
  */
QTextCodec.setCodecForCStrings = function(c){return undefined;};

/**
  * @name setCodecForLocale
  * @function
  * @memberOf QTextCodec
  * @param {QTextCodec} c
  * @returns {undefined}
  */
QTextCodec.setCodecForLocale = function(c){return undefined;};

/**
  * @name setCodecForTr
  * @function
  * @memberOf QTextCodec
  * @param {QTextCodec} c
  * @returns {undefined}
  */
QTextCodec.setCodecForTr = function(c){return undefined;};

/**
  * @default 0x80000000
  * @constant
  * @memberOf QTextCodec
  * @name ConvertInvalidToNull
  * @see QTextCodec#ConversionFlags
  * @see QTextCodec#ConversionFlag
  * @type Number
  */
QTextCodec.ConvertInvalidToNull = 0x80000000;

/**
  * @default 0x0
  * @constant
  * @memberOf QTextCodec
  * @name DefaultConversion
  * @see QTextCodec#ConversionFlags
  * @see QTextCodec#ConversionFlag
  * @type Number
  */
QTextCodec.DefaultConversion = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTextCodec
  * @name IgnoreHeader
  * @see QTextCodec#ConversionFlags
  * @see QTextCodec#ConversionFlag
  * @type Number
  */
QTextCodec.IgnoreHeader = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QTextCodec
  * @name FreeFunction
  * @see QTextCodec#ConversionFlags
  * @see QTextCodec#ConversionFlag
  * @type Number
  */
QTextCodec.FreeFunction = 0x2;

/**
  * @constructor 
  * @memberOf QTextCodec
  * @name ConversionFlag
  */
QTextCodec.ConversionFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QTextCodec
  * @name ConversionFlags
  */
QTextCodec.ConversionFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name aliases
  * @function
  * @memberOf QTextCodec.prototype
  * @returns {Array}
  */
QTextCodec.prototype.aliases = function(){return new Array();};

/**
  * @name canEncode
  * @function
  * @memberOf QTextCodec.prototype
  * @param {String} arg__1
  * @returns {Boolean}
  */
QTextCodec.prototype.canEncode = function(arg__1){return new Boolean();};

/**
  * @name fromUnicode
  * @function
  * @memberOf QTextCodec.prototype
  * @param {String} uc
  * @returns {QByteArray}
  */
QTextCodec.prototype.fromUnicode = function(uc){return new QByteArray();};

/**
  * @name makeDecoder
  * @function
  * @memberOf QTextCodec.prototype
  * @returns {QTextDecoder}
  */
QTextCodec.prototype.makeDecoder = function(){return new QTextDecoder();};

/**
  * @name makeEncoder
  * @function
  * @memberOf QTextCodec.prototype
  * @returns {QTextEncoder}
  */
QTextCodec.prototype.makeEncoder = function(){return new QTextEncoder();};

/**
  * @name mibEnum
  * @function
  * @memberOf QTextCodec.prototype
  * @returns {Numeric}
  */
QTextCodec.prototype.mibEnum = function(){return new Numeric();};

/**
  * @name name
  * @function
  * @memberOf QTextCodec.prototype
  * @returns {QByteArray}
  */
QTextCodec.prototype.name = function(){return new QByteArray();};

/**
  * @name toUnicode
  * @function
  * @memberOf QTextCodec.prototype
  * @param {QByteArray} arg__1
  * @returns {String}
  */
QTextCodec.prototype.toUnicode = function(arg__1){return new String();};

