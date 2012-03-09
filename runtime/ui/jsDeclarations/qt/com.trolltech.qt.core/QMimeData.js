/**
  * @name QMimeData
  * @constructor
  * @extends QObject
  */
function QMimeData(){return undefined;};

QMimeData.prototype = new QObject();

/**
  * @name clear
  * @function
  * @memberOf QMimeData.prototype
  * @returns {undefined}
  */
QMimeData.prototype.clear = function(){return undefined;};

/**
  * @name colorData
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Object}
  */
QMimeData.prototype.colorData = function(){return new Object();};

/**
  * @name data
  * @function
  * @memberOf QMimeData.prototype
  * @param {String} mimetype
  * @returns {QByteArray}
  */
QMimeData.prototype.data = function(mimetype){return new QByteArray();};

/**
  * @name formats
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Array}
  */
QMimeData.prototype.formats = function(){return new Array();};

/**
  * @name hasColor
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Boolean}
  */
QMimeData.prototype.hasColor = function(){return new Boolean();};

/**
  * @name hasFormat
  * @function
  * @memberOf QMimeData.prototype
  * @param {String} mimetype
  * @returns {Boolean}
  */
QMimeData.prototype.hasFormat = function(mimetype){return new Boolean();};

/**
  * @name hasHtml
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Boolean}
  */
QMimeData.prototype.hasHtml = function(){return new Boolean();};

/**
  * @name hasImage
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Boolean}
  */
QMimeData.prototype.hasImage = function(){return new Boolean();};

/**
  * @name hasText
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Boolean}
  */
QMimeData.prototype.hasText = function(){return new Boolean();};

/**
  * @name hasUrls
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Boolean}
  */
QMimeData.prototype.hasUrls = function(){return new Boolean();};

/**
  * @name html
  * @function
  * @memberOf QMimeData.prototype
  * @returns {String}
  */
QMimeData.prototype.html = function(){return new String();};

/**
  * @name imageData
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Object}
  */
QMimeData.prototype.imageData = function(){return new Object();};

/**
  * @name removeFormat
  * @function
  * @memberOf QMimeData.prototype
  * @param {String} mimetype
  * @returns {undefined}
  */
QMimeData.prototype.removeFormat = function(mimetype){return undefined;};

/**
  * @name setColorData
  * @function
  * @memberOf QMimeData.prototype
  * @param {Object} color
  * @returns {undefined}
  */
QMimeData.prototype.setColorData = function(color){return undefined;};

/**
  * @name setData
  * @function
  * @memberOf QMimeData.prototype
  * @param {String} mimetype
  * @param {QByteArray} data
  * @returns {undefined}
  */
QMimeData.prototype.setData = function(mimetype, data){return undefined;};

/**
  * @name setHtml
  * @function
  * @memberOf QMimeData.prototype
  * @param {String} html
  * @returns {undefined}
  */
QMimeData.prototype.setHtml = function(html){return undefined;};

/**
  * @name setImageData
  * @function
  * @memberOf QMimeData.prototype
  * @param {Object} image
  * @returns {undefined}
  */
QMimeData.prototype.setImageData = function(image){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QMimeData.prototype
  * @param {String} text
  * @returns {undefined}
  */
QMimeData.prototype.setText = function(text){return undefined;};

/**
  * @name setUrls
  * @function
  * @memberOf QMimeData.prototype
  * @param {Array} urls
  * @returns {undefined}
  */
QMimeData.prototype.setUrls = function(urls){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QMimeData.prototype
  * @returns {String}
  */
QMimeData.prototype.text = function(){return new String();};

/**
  * @name urls
  * @function
  * @memberOf QMimeData.prototype
  * @returns {Array}
  */
QMimeData.prototype.urls = function(){return new Array();};

