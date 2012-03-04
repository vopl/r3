/**
  * @name QSignalMapper
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QSignalMapper(parent){return undefined;};

QSignalMapper.prototype = new QObject();

/**
  * @name mappingById
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {Numeric} id
  * @returns {QObject}
  */
QSignalMapper.prototype.mappingById = function(id){return new QObject();};

/**
  * @name mappingByObject
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {QObject} object
  * @returns {QObject}
  */
QSignalMapper.prototype.mappingByObject = function(object){return new QObject();};

/**
  * @name mappingByString
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {String} text
  * @returns {QObject}
  */
QSignalMapper.prototype.mappingByString = function(text){return new QObject();};

/**
  * @name removeMappings
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {QObject} sender
  * @returns {undefined}
  */
QSignalMapper.prototype.removeMappings = function(sender){return undefined;};

/**
  * @name setMappingById
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {QObject} sender
  * @param {Numeric} id
  * @returns {undefined}
  */
QSignalMapper.prototype.setMappingById = function(sender, id){return undefined;};

/**
  * @name setMappingByObject
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {QObject} sender
  * @param {QObject} object
  * @returns {undefined}
  */
QSignalMapper.prototype.setMappingByObject = function(sender, object){return undefined;};

/**
  * @name setMappingByString
  * @function
  * @memberOf QSignalMapper.prototype
  * @param {QObject} sender
  * @param {String} text
  * @returns {undefined}
  */
QSignalMapper.prototype.setMappingByString = function(sender, text){return undefined;};

