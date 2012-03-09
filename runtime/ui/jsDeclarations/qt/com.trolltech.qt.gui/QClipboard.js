/**
  * @class QClipboard from package com.trolltech.qt.gui
  * @extends QObject
  */
var QClipboard = {};

QClipboard.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QClipboard
  * @name Clipboard
  * @see QClipboard#Mode
  * @type Number
  */
QClipboard.Clipboard = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QClipboard
  * @name Selection
  * @see QClipboard#Mode
  * @type Number
  */
QClipboard.Selection = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QClipboard
  * @name FindBuffer
  * @see QClipboard#Mode
  * @type Number
  */
QClipboard.FindBuffer = 0x2;

/**
  * @constructor 
  * @memberOf QClipboard
  * @name Mode
  */
QClipboard.Mode = function(value){;};



/**
  * @name clear
  * @function
  * @memberOf QClipboard.prototype
  * @param {QLCDNumber.Mode} mode
  * @returns {undefined}
  */
QClipboard.prototype.clear = function(mode){return undefined;};

/**
  * @name image
  * @function
  * @memberOf QClipboard.prototype
  * @param {QLCDNumber.Mode} mode
  * @returns {QImage}
  */
QClipboard.prototype.image = function(mode){return new QImage();};

/**
  * @name mimeData
  * @function
  * @memberOf QClipboard.prototype
  * @param {QLCDNumber.Mode} mode
  * @returns {QMimeData}
  */
QClipboard.prototype.mimeData = function(mode){return new QMimeData();};

/**
  * @name ownsClipboard
  * @function
  * @memberOf QClipboard.prototype
  * @returns {Boolean}
  */
QClipboard.prototype.ownsClipboard = function(){return new Boolean();};

/**
  * @name ownsFindBuffer
  * @function
  * @memberOf QClipboard.prototype
  * @returns {Boolean}
  */
QClipboard.prototype.ownsFindBuffer = function(){return new Boolean();};

/**
  * @name ownsSelection
  * @function
  * @memberOf QClipboard.prototype
  * @returns {Boolean}
  */
QClipboard.prototype.ownsSelection = function(){return new Boolean();};

/**
  * @name pixmap
  * @function
  * @memberOf QClipboard.prototype
  * @param {QLCDNumber.Mode} mode
  * @returns {QPixmap}
  */
QClipboard.prototype.pixmap = function(mode){return new QPixmap();};

/**
  * @name setImage
  * @function
  * @memberOf QClipboard.prototype
  * @param {QImage} arg__1
  * @param {QLCDNumber.Mode} mode
  * @returns {undefined}
  */
QClipboard.prototype.setImage = function(arg__1, mode){return undefined;};

/**
  * @name setMimeData
  * @function
  * @memberOf QClipboard.prototype
  * @param {QMimeData} data
  * @param {QLCDNumber.Mode} mode
  * @returns {undefined}
  */
QClipboard.prototype.setMimeData = function(data, mode){return undefined;};

/**
  * @name setPixmap
  * @function
  * @memberOf QClipboard.prototype
  * @param {QPixmap} arg__1
  * @param {QLCDNumber.Mode} mode
  * @returns {undefined}
  */
QClipboard.prototype.setPixmap = function(arg__1, mode){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QClipboard.prototype
  * @param {String} arg__1
  * @param {QLCDNumber.Mode} mode
  * @returns {undefined}
  */
QClipboard.prototype.setText = function(arg__1, mode){return undefined;};

/**
  * @name supportsFindBuffer
  * @function
  * @memberOf QClipboard.prototype
  * @returns {Boolean}
  */
QClipboard.prototype.supportsFindBuffer = function(){return new Boolean();};

/**
  * @name supportsSelection
  * @function
  * @memberOf QClipboard.prototype
  * @returns {Boolean}
  */
QClipboard.prototype.supportsSelection = function(){return new Boolean();};

/**
  * @name text
  * @function
  * @memberOf QClipboard.prototype
  * @param {QLCDNumber.Mode} mode
  * @returns {String}
  */
QClipboard.prototype.text = function(mode){return new String();};

