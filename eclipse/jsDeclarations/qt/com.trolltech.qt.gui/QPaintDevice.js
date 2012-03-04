/**
  * @class QPaintDevice from package com.trolltech.qt.gui
  */
var QPaintDevice = {};

/**
  * @default 1
  * @constant
  * @memberOf QPaintDevice
  * @name PdmWidth
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmWidth = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPaintDevice
  * @name PdmHeight
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmHeight = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QPaintDevice
  * @name PdmWidthMM
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmWidthMM = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QPaintDevice
  * @name PdmHeightMM
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmHeightMM = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QPaintDevice
  * @name PdmNumColors
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmNumColors = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QPaintDevice
  * @name PdmDepth
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmDepth = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf QPaintDevice
  * @name PdmDpiX
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmDpiX = 0x7;

/**
  * @default 0x8
  * @constant
  * @memberOf QPaintDevice
  * @name PdmDpiY
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmDpiY = 0x8;

/**
  * @default 0x9
  * @constant
  * @memberOf QPaintDevice
  * @name PdmPhysicalDpiX
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmPhysicalDpiX = 0x9;

/**
  * @default 0xa
  * @constant
  * @memberOf QPaintDevice
  * @name PdmPhysicalDpiY
  * @see QPaintDevice#PaintDeviceMetric
  * @type Number
  */
QPaintDevice.PdmPhysicalDpiY = 0xa;

/**
  * @constructor 
  * @memberOf QPaintDevice
  * @name PaintDeviceMetric
  */
QPaintDevice.PaintDeviceMetric = function(value){;};



/**
  * @name colorCount
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.colorCount = function(){return new Numeric();};

/**
  * @name depth
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.depth = function(){return new Numeric();};

/**
  * @name devType
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.devType = function(){return new Numeric();};

/**
  * @name height
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.height = function(){return new Numeric();};

/**
  * @name heightMM
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.heightMM = function(){return new Numeric();};

/**
  * @name logicalDpiX
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.logicalDpiX = function(){return new Numeric();};

/**
  * @name logicalDpiY
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.logicalDpiY = function(){return new Numeric();};

/**
  * @name numColors
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.numColors = function(){return new Numeric();};

/**
  * @name paintEngine
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {QPaintEngine}
  */
QPaintDevice.prototype.paintEngine = function(){return new QPaintEngine();};

/**
  * @name paintingActive
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Boolean}
  */
QPaintDevice.prototype.paintingActive = function(){return new Boolean();};

/**
  * @name physicalDpiX
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.physicalDpiX = function(){return new Numeric();};

/**
  * @name physicalDpiY
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.physicalDpiY = function(){return new Numeric();};

/**
  * @name width
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.width = function(){return new Numeric();};

/**
  * @name widthMM
  * @function
  * @memberOf QPaintDevice.prototype
  * @returns {Numeric}
  */
QPaintDevice.prototype.widthMM = function(){return new Numeric();};

