/**
  * @name QFileSystemWatcher
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QFileSystemWatcher(parent){return undefined;};

/**
  * @name QFileSystemWatcher^1
  * @constructor
  * @extends QObject
  * @param {Array} paths
  * @param {QObject} parent
  */
function QFileSystemWatcher(paths, parent){return undefined;};

QFileSystemWatcher.prototype = new QObject();

/**
  * @name addPath
  * @function
  * @memberOf QFileSystemWatcher.prototype
  * @param {String} file
  * @returns {undefined}
  */
QFileSystemWatcher.prototype.addPath = function(file){return undefined;};

/**
  * @name addPaths
  * @function
  * @memberOf QFileSystemWatcher.prototype
  * @param {Array} files
  * @returns {undefined}
  */
QFileSystemWatcher.prototype.addPaths = function(files){return undefined;};

/**
  * @name directories
  * @function
  * @memberOf QFileSystemWatcher.prototype
  * @returns {Array}
  */
QFileSystemWatcher.prototype.directories = function(){return new Array();};

/**
  * @name files
  * @function
  * @memberOf QFileSystemWatcher.prototype
  * @returns {Array}
  */
QFileSystemWatcher.prototype.files = function(){return new Array();};

/**
  * @name removePath
  * @function
  * @memberOf QFileSystemWatcher.prototype
  * @param {String} file
  * @returns {undefined}
  */
QFileSystemWatcher.prototype.removePath = function(file){return undefined;};

/**
  * @name removePaths
  * @function
  * @memberOf QFileSystemWatcher.prototype
  * @param {Array} files
  * @returns {undefined}
  */
QFileSystemWatcher.prototype.removePaths = function(files){return undefined;};

