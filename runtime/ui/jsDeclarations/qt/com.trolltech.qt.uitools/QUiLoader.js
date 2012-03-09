/**
  * @name QUiLoader
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QUiLoader(parent){return undefined;};

QUiLoader.prototype = new QObject();

/**
  * @name addPluginPath
  * @function
  * @memberOf QUiLoader.prototype
  * @param {String} path
  * @returns {undefined}
  */
QUiLoader.prototype.addPluginPath = function(path){return undefined;};

/**
  * @name availableLayouts
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {Array}
  */
QUiLoader.prototype.availableLayouts = function(){return new Array();};

/**
  * @name availableWidgets
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {Array}
  */
QUiLoader.prototype.availableWidgets = function(){return new Array();};

/**
  * @name clearPluginPaths
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {undefined}
  */
QUiLoader.prototype.clearPluginPaths = function(){return undefined;};

/**
  * @name createAction
  * @function
  * @memberOf QUiLoader.prototype
  * @param {QObject} parent
  * @param {String} name
  * @returns {QAction}
  */
QUiLoader.prototype.createAction = function(parent, name){return new QAction();};

/**
  * @name createActionGroup
  * @function
  * @memberOf QUiLoader.prototype
  * @param {QObject} parent
  * @param {String} name
  * @returns {QActionGroup}
  */
QUiLoader.prototype.createActionGroup = function(parent, name){return new QActionGroup();};

/**
  * @name createLayout
  * @function
  * @memberOf QUiLoader.prototype
  * @param {String} className
  * @param {QObject} parent
  * @param {String} name
  * @returns {QLayout}
  */
QUiLoader.prototype.createLayout = function(className, parent, name){return new QLayout();};

/**
  * @name createWidget
  * @function
  * @memberOf QUiLoader.prototype
  * @param {String} className
  * @param {QWidget} parent
  * @param {String} name
  * @returns {QWidget}
  */
QUiLoader.prototype.createWidget = function(className, parent, name){return new QWidget();};

/**
  * @name isLanguageChangeEnabled
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {Boolean}
  */
QUiLoader.prototype.isLanguageChangeEnabled = function(){return new Boolean();};

/**
  * @name isScriptingEnabled
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {Boolean}
  */
QUiLoader.prototype.isScriptingEnabled = function(){return new Boolean();};

/**
  * @name isTranslationEnabled
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {Boolean}
  */
QUiLoader.prototype.isTranslationEnabled = function(){return new Boolean();};

/**
  * @name load
  * @function
  * @memberOf QUiLoader.prototype
  * @param {QIODevice} device
  * @param {QWidget} parentWidget
  * @returns {QWidget}
  */
QUiLoader.prototype.load = function(device, parentWidget){return new QWidget();};

/**
  * @name pluginPaths
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {Array}
  */
QUiLoader.prototype.pluginPaths = function(){return new Array();};

/**
  * @name setLanguageChangeEnabled
  * @function
  * @memberOf QUiLoader.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QUiLoader.prototype.setLanguageChangeEnabled = function(enabled){return undefined;};

/**
  * @name setScriptingEnabled
  * @function
  * @memberOf QUiLoader.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QUiLoader.prototype.setScriptingEnabled = function(enabled){return undefined;};

/**
  * @name setTranslationEnabled
  * @function
  * @memberOf QUiLoader.prototype
  * @param {Boolean} enabled
  * @returns {undefined}
  */
QUiLoader.prototype.setTranslationEnabled = function(enabled){return undefined;};

/**
  * @name setWorkingDirectory
  * @function
  * @memberOf QUiLoader.prototype
  * @param {QDir} dir
  * @returns {undefined}
  */
QUiLoader.prototype.setWorkingDirectory = function(dir){return undefined;};

/**
  * @name workingDirectory
  * @function
  * @memberOf QUiLoader.prototype
  * @returns {QDir}
  */
QUiLoader.prototype.workingDirectory = function(){return new QDir();};

