/**
  * @name QUrlInfo
  * @constructor
  */
function QUrlInfo(){return undefined;};

/**
  * @name QUrlInfo^1
  * @constructor
  * @param {String} name
  * @param {Numeric} permissions
  * @param {String} owner
  * @param {String} group
  * @param {Numeric} size
  * @param {QDateTime} lastModified
  * @param {QDateTime} lastRead
  * @param {Boolean} isDir
  * @param {Boolean} isFile
  * @param {Boolean} isSymLink
  * @param {Boolean} isWritable
  * @param {Boolean} isReadable
  * @param {Boolean} isExecutable
  */
function QUrlInfo(name, permissions, owner, group, size, lastModified, lastRead, isDir, isFile, isSymLink, isWritable, isReadable, isExecutable){return undefined;};

/**
  * @name QUrlInfo^2
  * @constructor
  * @param {QUrl} url
  * @param {Numeric} permissions
  * @param {String} owner
  * @param {String} group
  * @param {Numeric} size
  * @param {QDateTime} lastModified
  * @param {QDateTime} lastRead
  * @param {Boolean} isDir
  * @param {Boolean} isFile
  * @param {Boolean} isSymLink
  * @param {Boolean} isWritable
  * @param {Boolean} isReadable
  * @param {Boolean} isExecutable
  */
function QUrlInfo(url, permissions, owner, group, size, lastModified, lastRead, isDir, isFile, isSymLink, isWritable, isReadable, isExecutable){return undefined;};

/**
  * @name QUrlInfo^3
  * @constructor
  * @param {QUrlInfo} ui
  */
function QUrlInfo(ui){return undefined;};

/**
  * @name equal
  * @function
  * @memberOf QUrlInfo
  * @param {QUrlInfo} i1
  * @param {QUrlInfo} i2
  * @param {Numeric} sortBy
  * @returns {Boolean}
  */
QUrlInfo.equal = function(i1, i2, sortBy){return new Boolean();};

/**
  * @name greaterThan
  * @function
  * @memberOf QUrlInfo
  * @param {QUrlInfo} i1
  * @param {QUrlInfo} i2
  * @param {Numeric} sortBy
  * @returns {Boolean}
  */
QUrlInfo.greaterThan = function(i1, i2, sortBy){return new Boolean();};

/**
  * @name lessThan
  * @function
  * @memberOf QUrlInfo
  * @param {QUrlInfo} i1
  * @param {QUrlInfo} i2
  * @param {Numeric} sortBy
  * @returns {Boolean}
  */
QUrlInfo.lessThan = function(i1, i2, sortBy){return new Boolean();};

/**
  * @default 00001
  * @constant
  * @memberOf QUrlInfo
  * @name ExeOther
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.ExeOther = 0x1;

/**
  * @default 00002
  * @constant
  * @memberOf QUrlInfo
  * @name WriteOther
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.WriteOther = 0x2;

/**
  * @default 00004
  * @constant
  * @memberOf QUrlInfo
  * @name ReadOther
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.ReadOther = 0x4;

/**
  * @default 00010
  * @constant
  * @memberOf QUrlInfo
  * @name ExeGroup
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.ExeGroup = 0x8;

/**
  * @default 00020
  * @constant
  * @memberOf QUrlInfo
  * @name WriteGroup
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.WriteGroup = 0x10;

/**
  * @default 00040
  * @constant
  * @memberOf QUrlInfo
  * @name ReadGroup
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.ReadGroup = 0x20;

/**
  * @default 00100
  * @constant
  * @memberOf QUrlInfo
  * @name ExeOwner
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.ExeOwner = 0x40;

/**
  * @default 00200
  * @constant
  * @memberOf QUrlInfo
  * @name WriteOwner
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.WriteOwner = 0x80;

/**
  * @default 00400
  * @constant
  * @memberOf QUrlInfo
  * @name ReadOwner
  * @see QUrlInfo#PermissionSpec
  * @type Number
  */
QUrlInfo.ReadOwner = 0x100;

/**
  * @constructor 
  * @memberOf QUrlInfo
  * @name PermissionSpec
  */
QUrlInfo.PermissionSpec = function(value){;};



/**
  * @name group
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {String}
  */
QUrlInfo.prototype.group = function(){return new String();};

/**
  * @name isDir
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isDir = function(){return new Boolean();};

/**
  * @name isExecutable
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isExecutable = function(){return new Boolean();};

/**
  * @name isFile
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isFile = function(){return new Boolean();};

/**
  * @name isReadable
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isReadable = function(){return new Boolean();};

/**
  * @name isSymLink
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isSymLink = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isValid = function(){return new Boolean();};

/**
  * @name isWritable
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Boolean}
  */
QUrlInfo.prototype.isWritable = function(){return new Boolean();};

/**
  * @name lastModified
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {QDateTime}
  */
QUrlInfo.prototype.lastModified = function(){return new QDateTime();};

/**
  * @name lastRead
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {QDateTime}
  */
QUrlInfo.prototype.lastRead = function(){return new QDateTime();};

/**
  * @name name
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {String}
  */
QUrlInfo.prototype.name = function(){return new String();};

/**
  * @name operator_equal
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {QUrlInfo} i
  * @returns {Boolean}
  */
QUrlInfo.prototype.operator_equal = function(i){return new Boolean();};

/**
  * @name owner
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {String}
  */
QUrlInfo.prototype.owner = function(){return new String();};

/**
  * @name permissions
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Numeric}
  */
QUrlInfo.prototype.permissions = function(){return new Numeric();};

/**
  * @name setDir
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QUrlInfo.prototype.setDir = function(b){return undefined;};

/**
  * @name setFile
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QUrlInfo.prototype.setFile = function(b){return undefined;};

/**
  * @name setGroup
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {String} s
  * @returns {undefined}
  */
QUrlInfo.prototype.setGroup = function(s){return undefined;};

/**
  * @name setLastModified
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {QDateTime} dt
  * @returns {undefined}
  */
QUrlInfo.prototype.setLastModified = function(dt){return undefined;};

/**
  * @name setLastRead
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {QDateTime} dt
  * @returns {undefined}
  */
QUrlInfo.prototype.setLastRead = function(dt){return undefined;};

/**
  * @name setName
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {String} name
  * @returns {undefined}
  */
QUrlInfo.prototype.setName = function(name){return undefined;};

/**
  * @name setOwner
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {String} s
  * @returns {undefined}
  */
QUrlInfo.prototype.setOwner = function(s){return undefined;};

/**
  * @name setPermissions
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Numeric} p
  * @returns {undefined}
  */
QUrlInfo.prototype.setPermissions = function(p){return undefined;};

/**
  * @name setReadable
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QUrlInfo.prototype.setReadable = function(b){return undefined;};

/**
  * @name setSize
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Numeric} size
  * @returns {undefined}
  */
QUrlInfo.prototype.setSize = function(size){return undefined;};

/**
  * @name setSymLink
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QUrlInfo.prototype.setSymLink = function(b){return undefined;};

/**
  * @name setWritable
  * @function
  * @memberOf QUrlInfo.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QUrlInfo.prototype.setWritable = function(b){return undefined;};

/**
  * @name size
  * @function
  * @memberOf QUrlInfo.prototype
  * @returns {Numeric}
  */
QUrlInfo.prototype.size = function(){return new Numeric();};

