/**
  * @name QSettings
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QSettings(parent){return undefined;};

/**
  * @name QSettings^1
  * @constructor
  * @extends QObject
  * @param {QSettings.Format} format
  * @param {QSettings.Scope} scope
  * @param {String} organization
  * @param {String} application
  * @param {QObject} parent
  */
function QSettings(format, scope, organization, application, parent){return undefined;};

/**
  * @name QSettings^2
  * @constructor
  * @extends QObject
  * @param {QSettings.Scope} scope
  * @param {String} organization
  * @param {String} application
  * @param {QObject} parent
  */
function QSettings(scope, organization, application, parent){return undefined;};

/**
  * @name QSettings^3
  * @constructor
  * @extends QObject
  * @param {String} fileName
  * @param {QSettings.Format} format
  * @param {QObject} parent
  */
function QSettings(fileName, format, parent){return undefined;};

/**
  * @name QSettings^4
  * @constructor
  * @extends QObject
  * @param {String} organization
  * @param {String} application
  * @param {QObject} parent
  */
function QSettings(organization, application, parent){return undefined;};

QSettings.prototype = new QObject();

/**
  * @name defaultFormat
  * @function
  * @memberOf QSettings
  * @returns {QSettings.Format}
  */
QSettings.defaultFormat = function(){return new QSettings.Format();};

/**
  * @name setDefaultFormat
  * @function
  * @memberOf QSettings
  * @param {QSettings.Format} format
  * @returns {undefined}
  */
QSettings.setDefaultFormat = function(format){return undefined;};

/**
  * @name setPath
  * @function
  * @memberOf QSettings
  * @param {QSettings.Format} format
  * @param {QSettings.Scope} scope
  * @param {String} path
  * @returns {undefined}
  */
QSettings.setPath = function(format, scope, path){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QSettings
  * @name NativeFormat
  * @see QSettings#Format
  * @type Number
  */
QSettings.NativeFormat = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSettings
  * @name IniFormat
  * @see QSettings#Format
  * @type Number
  */
QSettings.IniFormat = 0x1;

/**
  * @default 16
  * @constant
  * @memberOf QSettings
  * @name InvalidFormat
  * @see QSettings#Format
  * @type Number
  */
QSettings.InvalidFormat = 0x10;

/**
  * @default 0x11
  * @constant
  * @memberOf QSettings
  * @name CustomFormat1
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat1 = 0x11;

/**
  * @default 0x12
  * @constant
  * @memberOf QSettings
  * @name CustomFormat2
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat2 = 0x12;

/**
  * @default 0x13
  * @constant
  * @memberOf QSettings
  * @name CustomFormat3
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat3 = 0x13;

/**
  * @default 0x14
  * @constant
  * @memberOf QSettings
  * @name CustomFormat4
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat4 = 0x14;

/**
  * @default 0x15
  * @constant
  * @memberOf QSettings
  * @name CustomFormat5
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat5 = 0x15;

/**
  * @default 0x16
  * @constant
  * @memberOf QSettings
  * @name CustomFormat6
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat6 = 0x16;

/**
  * @default 0x17
  * @constant
  * @memberOf QSettings
  * @name CustomFormat7
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat7 = 0x17;

/**
  * @default 0x18
  * @constant
  * @memberOf QSettings
  * @name CustomFormat8
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat8 = 0x18;

/**
  * @default 0x19
  * @constant
  * @memberOf QSettings
  * @name CustomFormat9
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat9 = 0x19;

/**
  * @default 0x1a
  * @constant
  * @memberOf QSettings
  * @name CustomFormat10
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat10 = 0x1a;

/**
  * @default 0x1b
  * @constant
  * @memberOf QSettings
  * @name CustomFormat11
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat11 = 0x1b;

/**
  * @default 0x1c
  * @constant
  * @memberOf QSettings
  * @name CustomFormat12
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat12 = 0x1c;

/**
  * @default 0x1d
  * @constant
  * @memberOf QSettings
  * @name CustomFormat13
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat13 = 0x1d;

/**
  * @default 0x1e
  * @constant
  * @memberOf QSettings
  * @name CustomFormat14
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat14 = 0x1e;

/**
  * @default 0x1f
  * @constant
  * @memberOf QSettings
  * @name CustomFormat15
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat15 = 0x1f;

/**
  * @default 0x20
  * @constant
  * @memberOf QSettings
  * @name CustomFormat16
  * @see QSettings#Format
  * @type Number
  */
QSettings.CustomFormat16 = 0x20;

/**
  * @constructor 
  * @memberOf QSettings
  * @name Format
  */
QSettings.Format = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QSettings
  * @name NoError
  * @see QSettings#Status
  * @type Number
  */
QSettings.NoError = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSettings
  * @name AccessError
  * @see QSettings#Status
  * @type Number
  */
QSettings.AccessError = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSettings
  * @name FormatError
  * @see QSettings#Status
  * @type Number
  */
QSettings.FormatError = 0x2;

/**
  * @constructor 
  * @memberOf QSettings
  * @name Status
  */
QSettings.Status = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QSettings
  * @name UserScope
  * @see QSettings#Scope
  * @type Number
  */
QSettings.UserScope = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSettings
  * @name SystemScope
  * @see QSettings#Scope
  * @type Number
  */
QSettings.SystemScope = 0x1;

/**
  * @constructor 
  * @memberOf QSettings
  * @name Scope
  */
QSettings.Scope = function(value){;};



/**
  * @name allKeys
  * @function
  * @memberOf QSettings.prototype
  * @returns {Array}
  */
QSettings.prototype.allKeys = function(){return new Array();};

/**
  * @name applicationName
  * @function
  * @memberOf QSettings.prototype
  * @returns {String}
  */
QSettings.prototype.applicationName = function(){return new String();};

/**
  * @name beginGroup
  * @function
  * @memberOf QSettings.prototype
  * @param {String} prefix
  * @returns {undefined}
  */
QSettings.prototype.beginGroup = function(prefix){return undefined;};

/**
  * @name beginReadArray
  * @function
  * @memberOf QSettings.prototype
  * @param {String} prefix
  * @returns {Numeric}
  */
QSettings.prototype.beginReadArray = function(prefix){return new Numeric();};

/**
  * @name beginWriteArray
  * @function
  * @memberOf QSettings.prototype
  * @param {String} prefix
  * @param {Numeric} size
  * @returns {undefined}
  */
QSettings.prototype.beginWriteArray = function(prefix, size){return undefined;};

/**
  * @name childGroups
  * @function
  * @memberOf QSettings.prototype
  * @returns {Array}
  */
QSettings.prototype.childGroups = function(){return new Array();};

/**
  * @name childKeys
  * @function
  * @memberOf QSettings.prototype
  * @returns {Array}
  */
QSettings.prototype.childKeys = function(){return new Array();};

/**
  * @name clear
  * @function
  * @memberOf QSettings.prototype
  * @returns {undefined}
  */
QSettings.prototype.clear = function(){return undefined;};

/**
  * @name contains
  * @function
  * @memberOf QSettings.prototype
  * @param {String} key
  * @returns {Boolean}
  */
QSettings.prototype.contains = function(key){return new Boolean();};

/**
  * @name endArray
  * @function
  * @memberOf QSettings.prototype
  * @returns {undefined}
  */
QSettings.prototype.endArray = function(){return undefined;};

/**
  * @name endGroup
  * @function
  * @memberOf QSettings.prototype
  * @returns {undefined}
  */
QSettings.prototype.endGroup = function(){return undefined;};

/**
  * @name fallbacksEnabled
  * @function
  * @memberOf QSettings.prototype
  * @returns {Boolean}
  */
QSettings.prototype.fallbacksEnabled = function(){return new Boolean();};

/**
  * @name fileName
  * @function
  * @memberOf QSettings.prototype
  * @returns {String}
  */
QSettings.prototype.fileName = function(){return new String();};

/**
  * @name format
  * @function
  * @memberOf QSettings.prototype
  * @returns {QSettings.Format}
  */
QSettings.prototype.format = function(){return new QSettings.Format();};

/**
  * @name group
  * @function
  * @memberOf QSettings.prototype
  * @returns {String}
  */
QSettings.prototype.group = function(){return new String();};

/**
  * @name iniCodec
  * @function
  * @memberOf QSettings.prototype
  * @returns {QTextCodec}
  */
QSettings.prototype.iniCodec = function(){return new QTextCodec();};

/**
  * @name isWritable
  * @function
  * @memberOf QSettings.prototype
  * @returns {Boolean}
  */
QSettings.prototype.isWritable = function(){return new Boolean();};

/**
  * @name organizationName
  * @function
  * @memberOf QSettings.prototype
  * @returns {String}
  */
QSettings.prototype.organizationName = function(){return new String();};

/**
  * @name remove
  * @function
  * @memberOf QSettings.prototype
  * @param {String} key
  * @returns {undefined}
  */
QSettings.prototype.remove = function(key){return undefined;};

/**
  * @name scope
  * @function
  * @memberOf QSettings.prototype
  * @returns {QSettings.Scope}
  */
QSettings.prototype.scope = function(){return new QSettings.Scope();};

/**
  * @name setArrayIndex
  * @function
  * @memberOf QSettings.prototype
  * @param {Numeric} i
  * @returns {undefined}
  */
QSettings.prototype.setArrayIndex = function(i){return undefined;};

/**
  * @name setFallbacksEnabled
  * @function
  * @memberOf QSettings.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QSettings.prototype.setFallbacksEnabled = function(b){return undefined;};

/**
  * @name setIniCodec
  * @function
  * @memberOf QSettings.prototype
  * @param {QTextCodec} codec
  * @returns {undefined}
  */
QSettings.prototype.setIniCodec = function(codec){return undefined;};

/**
  * @name setValue
  * @function
  * @memberOf QSettings.prototype
  * @param {String} key
  * @param {Object} value
  * @returns {undefined}
  */
QSettings.prototype.setValue = function(key, value){return undefined;};

/**
  * @name status
  * @function
  * @memberOf QSettings.prototype
  * @returns {QSettings.Status}
  */
QSettings.prototype.status = function(){return new QSettings.Status();};

/**
  * @name sync
  * @function
  * @memberOf QSettings.prototype
  * @returns {undefined}
  */
QSettings.prototype.sync = function(){return undefined;};

/**
  * @name value
  * @function
  * @memberOf QSettings.prototype
  * @param {String} key
  * @param {Object} defaultValue
  * @returns {Object}
  */
QSettings.prototype.value = function(key, defaultValue){return new Object();};

