/**
  * @name QDirIterator
  * @constructor
  * @param {QDir} dir
  * @param {QDirIterator.IteratorFlags} flags
  */
function QDirIterator(dir, flags){return undefined;};

/**
  * @name QDirIterator^1
  * @constructor
  * @param {String} path
  * @param {QDir.Filters} filter
  * @param {QDirIterator.IteratorFlags} flags
  */
function QDirIterator(path, filter, flags){return undefined;};

/**
  * @name QDirIterator^2
  * @constructor
  * @param {String} path
  * @param {QDirIterator.IteratorFlags} flags
  */
function QDirIterator(path, flags){return undefined;};

/**
  * @name QDirIterator^3
  * @constructor
  * @param {String} path
  * @param {Array} nameFilters
  * @param {QDir.Filters} filters
  * @param {QDirIterator.IteratorFlags} flags
  */
function QDirIterator(path, nameFilters, filters, flags){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QDirIterator
  * @name NoIteratorFlags
  * @see QDirIterator#IteratorFlags
  * @see QDirIterator#IteratorFlag
  * @type Number
  */
QDirIterator.NoIteratorFlags = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDirIterator
  * @name FollowSymlinks
  * @see QDirIterator#IteratorFlags
  * @see QDirIterator#IteratorFlag
  * @type Number
  */
QDirIterator.FollowSymlinks = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QDirIterator
  * @name Subdirectories
  * @see QDirIterator#IteratorFlags
  * @see QDirIterator#IteratorFlag
  * @type Number
  */
QDirIterator.Subdirectories = 0x2;

/**
  * @constructor 
  * @memberOf QDirIterator
  * @name IteratorFlag
  */
QDirIterator.IteratorFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QDirIterator
  * @name IteratorFlags
  */
QDirIterator.IteratorFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name fileInfo
  * @function
  * @memberOf QDirIterator.prototype
  * @returns {QFileInfo}
  */
QDirIterator.prototype.fileInfo = function(){return new QFileInfo();};

/**
  * @name fileName
  * @function
  * @memberOf QDirIterator.prototype
  * @returns {String}
  */
QDirIterator.prototype.fileName = function(){return new String();};

/**
  * @name filePath
  * @function
  * @memberOf QDirIterator.prototype
  * @returns {String}
  */
QDirIterator.prototype.filePath = function(){return new String();};

/**
  * @name hasNext
  * @function
  * @memberOf QDirIterator.prototype
  * @returns {Boolean}
  */
QDirIterator.prototype.hasNext = function(){return new Boolean();};

/**
  * @name next
  * @function
  * @memberOf QDirIterator.prototype
  * @returns {String}
  */
QDirIterator.prototype.next = function(){return new String();};

/**
  * @name path
  * @function
  * @memberOf QDirIterator.prototype
  * @returns {String}
  */
QDirIterator.prototype.path = function(){return new String();};

