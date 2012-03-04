/**
  * @name QImageIOPlugin
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QImageIOPlugin(parent){return undefined;};

QImageIOPlugin.prototype = new QObject();

/**
  * @default 0x1
  * @constant
  * @memberOf QImageIOPlugin
  * @name CanRead
  * @see QImageIOPlugin#Capabilities
  * @see QImageIOPlugin#Capability
  * @type Number
  */
QImageIOPlugin.CanRead = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QImageIOPlugin
  * @name CanWrite
  * @see QImageIOPlugin#Capabilities
  * @see QImageIOPlugin#Capability
  * @type Number
  */
QImageIOPlugin.CanWrite = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QImageIOPlugin
  * @name CanReadIncremental
  * @see QImageIOPlugin#Capabilities
  * @see QImageIOPlugin#Capability
  * @type Number
  */
QImageIOPlugin.CanReadIncremental = 0x4;

/**
  * @constructor 
  * @memberOf QImageIOPlugin
  * @name Capability
  */
QImageIOPlugin.Capability = function(value){;};

/**
  * @constructor 
  * @memberOf QImageIOPlugin
  * @name Capabilities
  */
QImageIOPlugin.Capabilities = function(value1, value2 /*, ...*/){;};


/**
  * @name capabilities
  * @function
  * @memberOf QImageIOPlugin.prototype
  * @param {QIODevice} device
  * @param {QByteArray} format
  * @returns {QImageIOPlugin.Capabilities}
  */
QImageIOPlugin.prototype.capabilities = function(device, format){return new QImageIOPlugin.Capabilities();};

/**
  * @name create
  * @function
  * @memberOf QImageIOPlugin.prototype
  * @param {QIODevice} device
  * @param {QByteArray} format
  * @returns {QImageIOHandler}
  */
QImageIOPlugin.prototype.create = function(device, format){return new QImageIOHandler();};

/**
  * @name keys
  * @function
  * @memberOf QImageIOPlugin.prototype
  * @returns {Array}
  */
QImageIOPlugin.prototype.keys = function(){return new Array();};

