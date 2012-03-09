/**
  * @name QAccessiblePlugin
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QAccessiblePlugin(parent){return undefined;};

QAccessiblePlugin.prototype = new QObject();

/**
  * @name create
  * @function
  * @memberOf QAccessiblePlugin.prototype
  * @param {String} key
  * @param {QObject} object
  * @returns {QAccessibleInterface}
  */
QAccessiblePlugin.prototype.create = function(key, object){return new QAccessibleInterface();};

/**
  * @name keys
  * @function
  * @memberOf QAccessiblePlugin.prototype
  * @returns {Array}
  */
QAccessiblePlugin.prototype.keys = function(){return new Array();};

