/**
  * @name QWebPluginFactory
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QWebPluginFactory(parent){return undefined;};

QWebPluginFactory.prototype = new QObject();

/**
  * @constructor 
  * @memberOf QWebPluginFactory
  * @name Extension
  */
QWebPluginFactory.Extension = function(value){;};



/**
  * @name create
  * @function
  * @memberOf QWebPluginFactory.prototype
  * @param {String} mimeType
  * @param {QUrl} arg__2
  * @param {Array} argumentNames
  * @param {Array} argumentValues
  * @returns {QObject}
  */
QWebPluginFactory.prototype.create = function(mimeType, arg__2, argumentNames, argumentValues){return new QObject();};

/**
  * @name extension
  * @function
  * @memberOf QWebPluginFactory.prototype
  * @param {QWebPluginFactory.Extension} extension
  * @param {QWebPluginFactory_ExtensionOption} option
  * @param {QWebPluginFactory_ExtensionReturn} output
  * @returns {Boolean}
  */
QWebPluginFactory.prototype.extension = function(extension, option, output){return new Boolean();};

/**
  * @name plugins
  * @function
  * @memberOf QWebPluginFactory.prototype
  * @returns {Array}
  */
QWebPluginFactory.prototype.plugins = function(){return new Array();};

/**
  * @name refreshPlugins
  * @function
  * @memberOf QWebPluginFactory.prototype
  * @returns {undefined}
  */
QWebPluginFactory.prototype.refreshPlugins = function(){return undefined;};

/**
  * @name supportsExtension
  * @function
  * @memberOf QWebPluginFactory.prototype
  * @param {QWebPluginFactory.Extension} extension
  * @returns {Boolean}
  */
QWebPluginFactory.prototype.supportsExtension = function(extension){return new Boolean();};

