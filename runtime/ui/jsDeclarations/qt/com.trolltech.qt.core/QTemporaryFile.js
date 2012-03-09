/**
  * @name QTemporaryFile
  * @constructor
  * @extends QFile
  */
function QTemporaryFile(){return undefined;};

/**
  * @name QTemporaryFile^1
  * @constructor
  * @extends QFile
  * @param {QObject} parent
  */
function QTemporaryFile(parent){return undefined;};

/**
  * @name QTemporaryFile^2
  * @constructor
  * @extends QFile
  * @param {String} templateName
  */
function QTemporaryFile(templateName){return undefined;};

/**
  * @name QTemporaryFile^3
  * @constructor
  * @extends QFile
  * @param {String} templateName
  * @param {QObject} parent
  */
function QTemporaryFile(templateName, parent){return undefined;};

QTemporaryFile.prototype = new QFile();

/**
  * @name createLocalFile
  * @function
  * @memberOf QTemporaryFile
  * @param {QFile} file
  * @returns {QTemporaryFile}
  */
QTemporaryFile.createLocalFile = function(file){return new QTemporaryFile();};

/**
  * @name autoRemove
  * @function
  * @memberOf QTemporaryFile.prototype
  * @returns {Boolean}
  */
QTemporaryFile.prototype.autoRemove = function(){return new Boolean();};

/**
  * @name fileTemplate
  * @function
  * @memberOf QTemporaryFile.prototype
  * @returns {String}
  */
QTemporaryFile.prototype.fileTemplate = function(){return new String();};

/**
  * @name open
  * @function
  * @memberOf QTemporaryFile.prototype
  * @returns {Boolean}
  */
QTemporaryFile.prototype.open = function(){return new Boolean();};

/**
  * @name setAutoRemove
  * @function
  * @memberOf QTemporaryFile.prototype
  * @param {Boolean} b
  * @returns {undefined}
  */
QTemporaryFile.prototype.setAutoRemove = function(b){return undefined;};

/**
  * @name setFileTemplate
  * @function
  * @memberOf QTemporaryFile.prototype
  * @param {String} name
  * @returns {undefined}
  */
QTemporaryFile.prototype.setFileTemplate = function(name){return undefined;};

/**
  * @name uniqueFilename
  * @function
  * @memberOf QTemporaryFile.prototype
  * @returns {String}
  */
QTemporaryFile.prototype.uniqueFilename = function(){return new String();};

