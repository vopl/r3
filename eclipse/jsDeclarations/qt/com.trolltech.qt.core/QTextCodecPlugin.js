/**
  * @name QTextCodecPlugin
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QTextCodecPlugin(parent){return undefined;};

QTextCodecPlugin.prototype = new QObject();

/**
  * @name aliases
  * @function
  * @memberOf QTextCodecPlugin.prototype
  * @returns {Array}
  */
QTextCodecPlugin.prototype.aliases = function(){return new Array();};

/**
  * @name createForMib
  * @function
  * @memberOf QTextCodecPlugin.prototype
  * @param {Numeric} mib
  * @returns {QTextCodec}
  */
QTextCodecPlugin.prototype.createForMib = function(mib){return new QTextCodec();};

/**
  * @name createForName
  * @function
  * @memberOf QTextCodecPlugin.prototype
  * @param {QByteArray} name
  * @returns {QTextCodec}
  */
QTextCodecPlugin.prototype.createForName = function(name){return new QTextCodec();};

/**
  * @name mibEnums
  * @function
  * @memberOf QTextCodecPlugin.prototype
  * @returns {Array}
  */
QTextCodecPlugin.prototype.mibEnums = function(){return new Array();};

/**
  * @name names
  * @function
  * @memberOf QTextCodecPlugin.prototype
  * @returns {Array}
  */
QTextCodecPlugin.prototype.names = function(){return new Array();};

