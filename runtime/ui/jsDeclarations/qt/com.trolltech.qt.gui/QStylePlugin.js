/**
  * @name QStylePlugin
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QStylePlugin(parent){return undefined;};

QStylePlugin.prototype = new QObject();

/**
  * @name create
  * @function
  * @memberOf QStylePlugin.prototype
  * @param {String} key
  * @returns {QStyle}
  */
QStylePlugin.prototype.create = function(key){return new QStyle();};

/**
  * @name keys
  * @function
  * @memberOf QStylePlugin.prototype
  * @returns {Array}
  */
QStylePlugin.prototype.keys = function(){return new Array();};

