/**
  * @name QInputContextPlugin
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QInputContextPlugin(parent){return undefined;};

QInputContextPlugin.prototype = new QObject();

/**
  * @name create
  * @function
  * @memberOf QInputContextPlugin.prototype
  * @param {String} key
  * @returns {QInputContext}
  */
QInputContextPlugin.prototype.create = function(key){return new QInputContext();};

/**
  * @name description
  * @function
  * @memberOf QInputContextPlugin.prototype
  * @param {String} key
  * @returns {String}
  */
QInputContextPlugin.prototype.description = function(key){return new String();};

/**
  * @name displayName
  * @function
  * @memberOf QInputContextPlugin.prototype
  * @param {String} key
  * @returns {String}
  */
QInputContextPlugin.prototype.displayName = function(key){return new String();};

/**
  * @name keys
  * @function
  * @memberOf QInputContextPlugin.prototype
  * @returns {Array}
  */
QInputContextPlugin.prototype.keys = function(){return new Array();};

/**
  * @name languages
  * @function
  * @memberOf QInputContextPlugin.prototype
  * @param {String} key
  * @returns {Array}
  */
QInputContextPlugin.prototype.languages = function(key){return new Array();};

