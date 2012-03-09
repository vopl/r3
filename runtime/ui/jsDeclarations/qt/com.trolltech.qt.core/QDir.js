/**
  * @name QDir
  * @constructor
  * @param {QDir} arg__1
  */
function QDir(arg__1){return undefined;};

/**
  * @name QDir^1
  * @constructor
  * @param {String} path
  */
function QDir(path){return undefined;};

/**
  * @name QDir^2
  * @constructor
  * @param {String} path
  * @param {String} nameFilter
  * @param {QDir.SortFlags} sort
  * @param {QDir.Filters} filter
  */
function QDir(path, nameFilter, sort, filter){return undefined;};

/**
  * @name addSearchPath
  * @function
  * @memberOf QDir
  * @param {String} prefix
  * @param {String} path
  * @returns {undefined}
  */
QDir.addSearchPath = function(prefix, path){return undefined;};

/**
  * @name cleanPath
  * @function
  * @memberOf QDir
  * @param {String} path
  * @returns {String}
  */
QDir.cleanPath = function(path){return new String();};

/**
  * @name convertSeparators
  * @function
  * @memberOf QDir
  * @param {String} pathName
  * @returns {String}
  */
QDir.convertSeparators = function(pathName){return new String();};

/**
  * @name current
  * @function
  * @memberOf QDir
  * @returns {QDir}
  */
QDir.current = function(){return new QDir();};

/**
  * @name currentPath
  * @function
  * @memberOf QDir
  * @returns {String}
  */
QDir.currentPath = function(){return new String();};

/**
  * @name drives
  * @function
  * @memberOf QDir
  * @returns {Array}
  */
QDir.drives = function(){return new Array();};

/**
  * @name fromNativeSeparators
  * @function
  * @memberOf QDir
  * @param {String} pathName
  * @returns {String}
  */
QDir.fromNativeSeparators = function(pathName){return new String();};

/**
  * @name home
  * @function
  * @memberOf QDir
  * @returns {QDir}
  */
QDir.home = function(){return new QDir();};

/**
  * @name homePath
  * @function
  * @memberOf QDir
  * @returns {String}
  */
QDir.homePath = function(){return new String();};

/**
  * @name isAbsolutePath
  * @function
  * @memberOf QDir
  * @param {String} path
  * @returns {Boolean}
  */
QDir.isAbsolutePath = function(path){return new Boolean();};

/**
  * @name isRelativePath
  * @function
  * @memberOf QDir
  * @param {String} path
  * @returns {Boolean}
  */
QDir.isRelativePath = function(path){return new Boolean();};

/**
  * @name match
  * @function
  * @memberOf QDir
  * @param {String} filter
  * @param {String} fileName
  * @returns {Boolean}
  */
QDir.match = function(filter, fileName){return new Boolean();};

/**
  * @name nameFiltersFromString
  * @function
  * @memberOf QDir
  * @param {String} nameFilter
  * @returns {Array}
  */
QDir.nameFiltersFromString = function(nameFilter){return new Array();};

/**
  * @name root
  * @function
  * @memberOf QDir
  * @returns {QDir}
  */
QDir.root = function(){return new QDir();};

/**
  * @name rootPath
  * @function
  * @memberOf QDir
  * @returns {String}
  */
QDir.rootPath = function(){return new String();};

/**
  * @name searchPaths
  * @function
  * @memberOf QDir
  * @param {String} prefix
  * @returns {Array}
  */
QDir.searchPaths = function(prefix){return new Array();};

/**
  * @name separator
  * @function
  * @memberOf QDir
  * @returns {String}
  */
QDir.separator = function(){return new String();};

/**
  * @name setCurrent
  * @function
  * @memberOf QDir
  * @param {String} path
  * @returns {Boolean}
  */
QDir.setCurrent = function(path){return new Boolean();};

/**
  * @name setSearchPaths
  * @function
  * @memberOf QDir
  * @param {String} prefix
  * @param {Array} searchPaths
  * @returns {undefined}
  */
QDir.setSearchPaths = function(prefix, searchPaths){return undefined;};

/**
  * @name temp
  * @function
  * @memberOf QDir
  * @returns {QDir}
  */
QDir.temp = function(){return new QDir();};

/**
  * @name tempPath
  * @function
  * @memberOf QDir
  * @returns {String}
  */
QDir.tempPath = function(){return new String();};

/**
  * @name toNativeSeparators
  * @function
  * @memberOf QDir
  * @param {String} pathName
  * @returns {String}
  */
QDir.toNativeSeparators = function(pathName){return new String();};

/**
  * @default -1
  * @constant
  * @memberOf QDir
  * @name NoFilter
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.NoFilter = 0xffffffff;

/**
  * @default 0x001
  * @constant
  * @memberOf QDir
  * @name Dirs
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Dirs = 0x1;

/**
  * @default 0x002
  * @constant
  * @memberOf QDir
  * @name Files
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Files = 0x2;

/**
  * @default 0x004
  * @constant
  * @memberOf QDir
  * @name Drives
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Drives = 0x4;

/**
  * @default Dirs|Files|Drives
  * @constant
  * @memberOf QDir
  * @name AllEntries
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.AllEntries = 0x7;

/**
  * @default 0x008
  * @constant
  * @memberOf QDir
  * @name NoSymLinks
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.NoSymLinks = 0x8;

/**
  * @default 0x00f
  * @constant
  * @memberOf QDir
  * @name TypeMask
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.TypeMask = 0xf;

/**
  * @default 0x010
  * @constant
  * @memberOf QDir
  * @name Readable
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Readable = 0x10;

/**
  * @default 0x020
  * @constant
  * @memberOf QDir
  * @name Writable
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Writable = 0x20;

/**
  * @default 0x040
  * @constant
  * @memberOf QDir
  * @name Executable
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Executable = 0x40;

/**
  * @default 0x070
  * @constant
  * @memberOf QDir
  * @name PermissionMask
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.PermissionMask = 0x70;

/**
  * @default 0x080
  * @constant
  * @memberOf QDir
  * @name Modified
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Modified = 0x80;

/**
  * @default 0x100
  * @constant
  * @memberOf QDir
  * @name Hidden
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.Hidden = 0x100;

/**
  * @default 0x200
  * @constant
  * @memberOf QDir
  * @name System
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.System = 0x200;

/**
  * @default 0x3F0
  * @constant
  * @memberOf QDir
  * @name AccessMask
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.AccessMask = 0x3f0;

/**
  * @default 0x400
  * @constant
  * @memberOf QDir
  * @name AllDirs
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.AllDirs = 0x400;

/**
  * @default 0x800
  * @constant
  * @memberOf QDir
  * @name CaseSensitive
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.CaseSensitive = 0x800;

/**
  * @default 0x1000
  * @constant
  * @memberOf QDir
  * @name NoDotAndDotDot
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.NoDotAndDotDot = 0x1000;

/**
  * @default 0x2000
  * @constant
  * @memberOf QDir
  * @name NoDot
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.NoDot = 0x2000;

/**
  * @default 0x4000
  * @constant
  * @memberOf QDir
  * @name NoDotDot
  * @see QDir#Filters
  * @see QDir#Filter
  * @type Number
  */
QDir.NoDotDot = 0x4000;

/**
  * @constructor 
  * @memberOf QDir
  * @name Filter
  */
QDir.Filter = function(value){;};

/**
  * @constructor 
  * @memberOf QDir
  * @name Filters
  */
QDir.Filters = function(value1, value2 /*, ...*/){;};


/**
  * @default -1
  * @constant
  * @memberOf QDir
  * @name NoSort
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.NoSort = 0xffffffff;

/**
  * @default 0x00
  * @constant
  * @memberOf QDir
  * @name Name
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.Name = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QDir
  * @name Time
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.Time = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QDir
  * @name Size
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.Size = 0x2;

/**
  * @default 0x03
  * @constant
  * @memberOf QDir
  * @name Unsorted
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.Unsorted = 0x3;

/**
  * @default 0x04
  * @constant
  * @memberOf QDir
  * @name DirsFirst
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.DirsFirst = 0x4;

/**
  * @default 0x08
  * @constant
  * @memberOf QDir
  * @name Reversed
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.Reversed = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QDir
  * @name IgnoreCase
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.IgnoreCase = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf QDir
  * @name DirsLast
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.DirsLast = 0x20;

/**
  * @default 0x40
  * @constant
  * @memberOf QDir
  * @name LocaleAware
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.LocaleAware = 0x40;

/**
  * @default 0x80
  * @constant
  * @memberOf QDir
  * @name Type
  * @see QDir#SortFlags
  * @see QDir#SortFlag
  * @type Number
  */
QDir.Type = 0x80;

/**
  * @constructor 
  * @memberOf QDir
  * @name SortFlag
  */
QDir.SortFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QDir
  * @name SortFlags
  */
QDir.SortFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name absoluteFilePath
  * @function
  * @memberOf QDir.prototype
  * @param {String} fileName
  * @returns {String}
  */
QDir.prototype.absoluteFilePath = function(fileName){return new String();};

/**
  * @name absolutePath
  * @function
  * @memberOf QDir.prototype
  * @returns {String}
  */
QDir.prototype.absolutePath = function(){return new String();};

/**
  * @name canonicalPath
  * @function
  * @memberOf QDir.prototype
  * @returns {String}
  */
QDir.prototype.canonicalPath = function(){return new String();};

/**
  * @name cd
  * @function
  * @memberOf QDir.prototype
  * @param {String} dirName
  * @returns {Boolean}
  */
QDir.prototype.cd = function(dirName){return new Boolean();};

/**
  * @name cdUp
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.cdUp = function(){return new Boolean();};

/**
  * @name count
  * @function
  * @memberOf QDir.prototype
  * @returns {Numeric}
  */
QDir.prototype.count = function(){return new Numeric();};

/**
  * @name dirName
  * @function
  * @memberOf QDir.prototype
  * @returns {String}
  */
QDir.prototype.dirName = function(){return new String();};

/**
  * @name entryInfoList
  * @function
  * @memberOf QDir.prototype
  * @param {QDir.Filters} filters
  * @param {QDir.SortFlags} sort
  * @returns {Array}
  */
QDir.prototype.entryInfoList = function(filters, sort){return new Array();};

/**
  * @name entryList
  * @function
  * @memberOf QDir.prototype
  * @param {QDir.Filters} filters
  * @param {QDir.SortFlags} sort
  * @returns {Array}
  */
QDir.prototype.entryList = function(filters, sort){return new Array();};

/**
  * @name exists
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.exists = function(){return new Boolean();};

/**
  * @name filePath
  * @function
  * @memberOf QDir.prototype
  * @param {String} fileName
  * @returns {String}
  */
QDir.prototype.filePath = function(fileName){return new String();};

/**
  * @name filter
  * @function
  * @memberOf QDir.prototype
  * @returns {QDir.Filters}
  */
QDir.prototype.filter = function(){return new QDir.Filters();};

/**
  * @name isAbsolute
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.isAbsolute = function(){return new Boolean();};

/**
  * @name isReadable
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.isReadable = function(){return new Boolean();};

/**
  * @name isRelative
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.isRelative = function(){return new Boolean();};

/**
  * @name isRoot
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.isRoot = function(){return new Boolean();};

/**
  * @name makeAbsolute
  * @function
  * @memberOf QDir.prototype
  * @returns {Boolean}
  */
QDir.prototype.makeAbsolute = function(){return new Boolean();};

/**
  * @name mkdir
  * @function
  * @memberOf QDir.prototype
  * @param {String} dirName
  * @returns {Boolean}
  */
QDir.prototype.mkdir = function(dirName){return new Boolean();};

/**
  * @name mkpath
  * @function
  * @memberOf QDir.prototype
  * @param {String} dirPath
  * @returns {Boolean}
  */
QDir.prototype.mkpath = function(dirPath){return new Boolean();};

/**
  * @name nameFilters
  * @function
  * @memberOf QDir.prototype
  * @returns {Array}
  */
QDir.prototype.nameFilters = function(){return new Array();};

/**
  * @name operator_equal
  * @function
  * @memberOf QDir.prototype
  * @param {QDir} dir
  * @returns {Boolean}
  */
QDir.prototype.operator_equal = function(dir){return new Boolean();};

/**
  * @name operator_subscript
  * @function
  * @memberOf QDir.prototype
  * @param {Numeric} arg__1
  * @returns {String}
  */
QDir.prototype.operator_subscript = function(arg__1){return new String();};

/**
  * @name path
  * @function
  * @memberOf QDir.prototype
  * @returns {String}
  */
QDir.prototype.path = function(){return new String();};

/**
  * @name refresh
  * @function
  * @memberOf QDir.prototype
  * @returns {undefined}
  */
QDir.prototype.refresh = function(){return undefined;};

/**
  * @name relativeFilePath
  * @function
  * @memberOf QDir.prototype
  * @param {String} fileName
  * @returns {String}
  */
QDir.prototype.relativeFilePath = function(fileName){return new String();};

/**
  * @name remove
  * @function
  * @memberOf QDir.prototype
  * @param {String} fileName
  * @returns {Boolean}
  */
QDir.prototype.remove = function(fileName){return new Boolean();};

/**
  * @name rename
  * @function
  * @memberOf QDir.prototype
  * @param {String} oldName
  * @param {String} newName
  * @returns {Boolean}
  */
QDir.prototype.rename = function(oldName, newName){return new Boolean();};

/**
  * @name rmdir
  * @function
  * @memberOf QDir.prototype
  * @param {String} dirName
  * @returns {Boolean}
  */
QDir.prototype.rmdir = function(dirName){return new Boolean();};

/**
  * @name rmpath
  * @function
  * @memberOf QDir.prototype
  * @param {String} dirPath
  * @returns {Boolean}
  */
QDir.prototype.rmpath = function(dirPath){return new Boolean();};

/**
  * @name setFilter
  * @function
  * @memberOf QDir.prototype
  * @param {QDir.Filters} filter
  * @returns {undefined}
  */
QDir.prototype.setFilter = function(filter){return undefined;};

/**
  * @name setNameFilters
  * @function
  * @memberOf QDir.prototype
  * @param {Array} nameFilters
  * @returns {undefined}
  */
QDir.prototype.setNameFilters = function(nameFilters){return undefined;};

/**
  * @name setPath
  * @function
  * @memberOf QDir.prototype
  * @param {String} path
  * @returns {undefined}
  */
QDir.prototype.setPath = function(path){return undefined;};

/**
  * @name setSorting
  * @function
  * @memberOf QDir.prototype
  * @param {QDir.SortFlags} sort
  * @returns {undefined}
  */
QDir.prototype.setSorting = function(sort){return undefined;};

/**
  * @name sorting
  * @function
  * @memberOf QDir.prototype
  * @returns {QDir.SortFlags}
  */
QDir.prototype.sorting = function(){return new QDir.SortFlags();};

