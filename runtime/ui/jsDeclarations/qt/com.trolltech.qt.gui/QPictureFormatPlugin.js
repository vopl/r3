/**
  * @name QPictureFormatPlugin
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QPictureFormatPlugin(parent){return undefined;};

QPictureFormatPlugin.prototype = new QObject();

/**
  * @name installIOHandler
  * @function
  * @memberOf QPictureFormatPlugin.prototype
  * @param {String} format
  * @returns {Boolean}
  */
QPictureFormatPlugin.prototype.installIOHandler = function(format){return new Boolean();};

/**
  * @name keys
  * @function
  * @memberOf QPictureFormatPlugin.prototype
  * @returns {Array}
  */
QPictureFormatPlugin.prototype.keys = function(){return new Array();};

/**
  * @name loadPicture
  * @function
  * @memberOf QPictureFormatPlugin.prototype
  * @param {String} format
  * @param {String} filename
  * @param {QPicture} pic
  * @returns {Boolean}
  */
QPictureFormatPlugin.prototype.loadPicture = function(format, filename, pic){return new Boolean();};

/**
  * @name savePicture
  * @function
  * @memberOf QPictureFormatPlugin.prototype
  * @param {String} format
  * @param {String} filename
  * @param {QPicture} pic
  * @returns {Boolean}
  */
QPictureFormatPlugin.prototype.savePicture = function(format, filename, pic){return new Boolean();};

