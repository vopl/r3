/**
  * @name QFile
  * @constructor
  * @extends QIODevice
  */
function QFile(){return undefined;};

/**
  * @name QFile^1
  * @constructor
  * @extends QIODevice
  * @param {QObject} parent
  */
function QFile(parent){return undefined;};

/**
  * @name QFile^2
  * @constructor
  * @extends QIODevice
  * @param {String} name
  */
function QFile(name){return undefined;};

/**
  * @name QFile^3
  * @constructor
  * @extends QIODevice
  * @param {String} name
  * @param {QObject} parent
  */
function QFile(name, parent){return undefined;};

QFile.prototype = new QIODevice();

/**
  * @name copy
  * @function
  * @memberOf QFile
  * @param {String} fileName
  * @param {String} newName
  * @returns {Boolean}
  */
QFile.copy = function(fileName, newName){return new Boolean();};

/**
  * @name decodeName
  * @function
  * @memberOf QFile
  * @param {QByteArray} localFileName
  * @returns {String}
  */
QFile.decodeName = function(localFileName){return new String();};

/**
  * @name encodeName
  * @function
  * @memberOf QFile
  * @param {String} fileName
  * @returns {QByteArray}
  */
QFile.encodeName = function(fileName){return new QByteArray();};

/**
  * @name exists
  * @function
  * @memberOf QFile
  * @param {String} fileName
  * @returns {Boolean}
  */
QFile.exists = function(fileName){return new Boolean();};

/**
  * @name link
  * @function
  * @memberOf QFile
  * @param {String} oldname
  * @param {String} newName
  * @returns {Boolean}
  */
QFile.link = function(oldname, newName){return new Boolean();};

/**
  * @name permissions
  * @function
  * @memberOf QFile
  * @param {String} filename
  * @returns {QFile.Permissions}
  */
QFile.permissions = function(filename){return new QFile.Permissions();};

/**
  * @name remove
  * @function
  * @memberOf QFile
  * @param {String} fileName
  * @returns {Boolean}
  */
QFile.remove = function(fileName){return new Boolean();};

/**
  * @name rename
  * @function
  * @memberOf QFile
  * @param {String} oldName
  * @param {String} newName
  * @returns {Boolean}
  */
QFile.rename = function(oldName, newName){return new Boolean();};

/**
  * @name resize
  * @function
  * @memberOf QFile
  * @param {String} filename
  * @param {Numeric} sz
  * @returns {Boolean}
  */
QFile.resize = function(filename, sz){return new Boolean();};

/**
  * @name setPermissions
  * @function
  * @memberOf QFile
  * @param {String} filename
  * @param {QFile.Permissions} permissionSpec
  * @returns {Boolean}
  */
QFile.setPermissions = function(filename, permissionSpec){return new Boolean();};

/**
  * @name symLinkTarget
  * @function
  * @memberOf QFile
  * @param {String} fileName
  * @returns {String}
  */
QFile.symLinkTarget = function(fileName){return new String();};

/**
  * @default 0
  * @constant
  * @memberOf QFile
  * @name NoError
  * @see QFile#FileError
  * @type Number
  */
QFile.NoError = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf QFile
  * @name ReadError
  * @see QFile#FileError
  * @type Number
  */
QFile.ReadError = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf QFile
  * @name WriteError
  * @see QFile#FileError
  * @type Number
  */
QFile.WriteError = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf QFile
  * @name FatalError
  * @see QFile#FileError
  * @type Number
  */
QFile.FatalError = 0x3;

/**
  * @default 4
  * @constant
  * @memberOf QFile
  * @name ResourceError
  * @see QFile#FileError
  * @type Number
  */
QFile.ResourceError = 0x4;

/**
  * @default 5
  * @constant
  * @memberOf QFile
  * @name OpenError
  * @see QFile#FileError
  * @type Number
  */
QFile.OpenError = 0x5;

/**
  * @default 6
  * @constant
  * @memberOf QFile
  * @name AbortError
  * @see QFile#FileError
  * @type Number
  */
QFile.AbortError = 0x6;

/**
  * @default 7
  * @constant
  * @memberOf QFile
  * @name TimeOutError
  * @see QFile#FileError
  * @type Number
  */
QFile.TimeOutError = 0x7;

/**
  * @default 8
  * @constant
  * @memberOf QFile
  * @name UnspecifiedError
  * @see QFile#FileError
  * @type Number
  */
QFile.UnspecifiedError = 0x8;

/**
  * @default 9
  * @constant
  * @memberOf QFile
  * @name RemoveError
  * @see QFile#FileError
  * @type Number
  */
QFile.RemoveError = 0x9;

/**
  * @default 10
  * @constant
  * @memberOf QFile
  * @name RenameError
  * @see QFile#FileError
  * @type Number
  */
QFile.RenameError = 0xa;

/**
  * @default 11
  * @constant
  * @memberOf QFile
  * @name PositionError
  * @see QFile#FileError
  * @type Number
  */
QFile.PositionError = 0xb;

/**
  * @default 12
  * @constant
  * @memberOf QFile
  * @name ResizeError
  * @see QFile#FileError
  * @type Number
  */
QFile.ResizeError = 0xc;

/**
  * @default 13
  * @constant
  * @memberOf QFile
  * @name PermissionsError
  * @see QFile#FileError
  * @type Number
  */
QFile.PermissionsError = 0xd;

/**
  * @default 14
  * @constant
  * @memberOf QFile
  * @name CopyError
  * @see QFile#FileError
  * @type Number
  */
QFile.CopyError = 0xe;

/**
  * @constructor 
  * @memberOf QFile
  * @name FileError
  */
QFile.FileError = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf QFile
  * @name NoOptions
  * @see QFile#MemoryMapFlags
  * @type Number
  */
QFile.NoOptions = 0x0;

/**
  * @constructor 
  * @memberOf QFile
  * @name MemoryMapFlags
  */
QFile.MemoryMapFlags = function(value){;};



/**
  * @default 0x0001
  * @constant
  * @memberOf QFile
  * @name ExeOther
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ExeOther = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QFile
  * @name WriteOther
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.WriteOther = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QFile
  * @name ReadOther
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ReadOther = 0x4;

/**
  * @default 0x0010
  * @constant
  * @memberOf QFile
  * @name ExeGroup
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ExeGroup = 0x10;

/**
  * @default 0x0020
  * @constant
  * @memberOf QFile
  * @name WriteGroup
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.WriteGroup = 0x20;

/**
  * @default 0x0040
  * @constant
  * @memberOf QFile
  * @name ReadGroup
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ReadGroup = 0x40;

/**
  * @default 0x0100
  * @constant
  * @memberOf QFile
  * @name ExeUser
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ExeUser = 0x100;

/**
  * @default 0x0200
  * @constant
  * @memberOf QFile
  * @name WriteUser
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.WriteUser = 0x200;

/**
  * @default 0x0400
  * @constant
  * @memberOf QFile
  * @name ReadUser
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ReadUser = 0x400;

/**
  * @default 0x1000
  * @constant
  * @memberOf QFile
  * @name ExeOwner
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ExeOwner = 0x1000;

/**
  * @default 0x2000
  * @constant
  * @memberOf QFile
  * @name WriteOwner
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.WriteOwner = 0x2000;

/**
  * @default 0x4000
  * @constant
  * @memberOf QFile
  * @name ReadOwner
  * @see QFile#Permissions
  * @see QFile#Permission
  * @type Number
  */
QFile.ReadOwner = 0x4000;

/**
  * @constructor 
  * @memberOf QFile
  * @name Permission
  */
QFile.Permission = function(value){;};

/**
  * @constructor 
  * @memberOf QFile
  * @name Permissions
  */
QFile.Permissions = function(value1, value2 /*, ...*/){;};


/**
  * @name copy
  * @function
  * @memberOf QFile.prototype
  * @param {String} newName
  * @returns {Boolean}
  */
QFile.prototype.copy = function(newName){return new Boolean();};

/**
  * @name error
  * @function
  * @memberOf QFile.prototype
  * @returns {QFile.FileError}
  */
QFile.prototype.error = function(){return new QFile.FileError();};

/**
  * @name exists
  * @function
  * @memberOf QFile.prototype
  * @returns {Boolean}
  */
QFile.prototype.exists = function(){return new Boolean();};

/**
  * @name fileEngine
  * @function
  * @memberOf QFile.prototype
  * @returns {Object}
  */
QFile.prototype.fileEngine = function(){return new Object();};

/**
  * @name fileName
  * @function
  * @memberOf QFile.prototype
  * @returns {String}
  */
QFile.prototype.fileName = function(){return new String();};

/**
  * @name flush
  * @function
  * @memberOf QFile.prototype
  * @returns {Boolean}
  */
QFile.prototype.flush = function(){return new Boolean();};

/**
  * @name handle
  * @function
  * @memberOf QFile.prototype
  * @returns {Numeric}
  */
QFile.prototype.handle = function(){return new Numeric();};

/**
  * @name link
  * @function
  * @memberOf QFile.prototype
  * @param {String} newName
  * @returns {Boolean}
  */
QFile.prototype.link = function(newName){return new Boolean();};

/**
  * @name permissions
  * @function
  * @memberOf QFile.prototype
  * @returns {QFile.Permissions}
  */
QFile.prototype.permissions = function(){return new QFile.Permissions();};

/**
  * @name remove
  * @function
  * @memberOf QFile.prototype
  * @returns {Boolean}
  */
QFile.prototype.remove = function(){return new Boolean();};

/**
  * @name rename
  * @function
  * @memberOf QFile.prototype
  * @param {String} newName
  * @returns {Boolean}
  */
QFile.prototype.rename = function(newName){return new Boolean();};

/**
  * @name resize
  * @function
  * @memberOf QFile.prototype
  * @param {Numeric} sz
  * @returns {Boolean}
  */
QFile.prototype.resize = function(sz){return new Boolean();};

/**
  * @name setFileName
  * @function
  * @memberOf QFile.prototype
  * @param {String} name
  * @returns {undefined}
  */
QFile.prototype.setFileName = function(name){return undefined;};

/**
  * @name setPermissions
  * @function
  * @memberOf QFile.prototype
  * @param {QFile.Permissions} permissionSpec
  * @returns {Boolean}
  */
QFile.prototype.setPermissions = function(permissionSpec){return new Boolean();};

/**
  * @name symLinkTarget
  * @function
  * @memberOf QFile.prototype
  * @returns {String}
  */
QFile.prototype.symLinkTarget = function(){return new String();};

/**
  * @name unsetError
  * @function
  * @memberOf QFile.prototype
  * @returns {undefined}
  */
QFile.prototype.unsetError = function(){return undefined;};

