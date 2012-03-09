/**
  * @name VideoWidget
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function VideoWidget(parent){return undefined;};

VideoWidget.prototype = new QWidget();

/**
  * @default 0
  * @constant
  * @memberOf VideoWidget
  * @name AspectRatioAuto
  * @see VideoWidget#AspectRatio
  * @type Number
  */
VideoWidget.AspectRatioAuto = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf VideoWidget
  * @name AspectRatioWidget
  * @see VideoWidget#AspectRatio
  * @type Number
  */
VideoWidget.AspectRatioWidget = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf VideoWidget
  * @name AspectRatio4_3
  * @see VideoWidget#AspectRatio
  * @type Number
  */
VideoWidget.AspectRatio4_3 = 0x2;

/**
  * @default 3
  * @constant
  * @memberOf VideoWidget
  * @name AspectRatio16_9
  * @see VideoWidget#AspectRatio
  * @type Number
  */
VideoWidget.AspectRatio16_9 = 0x3;

/**
  * @constructor 
  * @memberOf VideoWidget
  * @name AspectRatio
  */
VideoWidget.AspectRatio = function(value){;};



/**
  * @default 0
  * @constant
  * @memberOf VideoWidget
  * @name FitInView
  * @see VideoWidget#ScaleMode
  * @type Number
  */
VideoWidget.FitInView = 0x0;

/**
  * @default 1
  * @constant
  * @memberOf VideoWidget
  * @name ScaleAndCrop
  * @see VideoWidget#ScaleMode
  * @type Number
  */
VideoWidget.ScaleAndCrop = 0x1;

/**
  * @constructor 
  * @memberOf VideoWidget
  * @name ScaleMode
  */
VideoWidget.ScaleMode = function(value){;};



/**
  * @name snapshot
  * @function
  * @memberOf VideoWidget.prototype
  * @returns {QImage}
  */
VideoWidget.prototype.snapshot = function(){return new QImage();};

/**
  * @name fullScreen
  * @memberOf VideoWidget.prototype
  * @type Boolean
  */
VideoWidget.prototype.fullScreen = new Boolean();

/**
  * @name aspectRatio
  * @memberOf VideoWidget.prototype
  * @type VideoWidget.AspectRatio
  */
VideoWidget.prototype.aspectRatio = new VideoWidget.AspectRatio();

/**
  * @name scaleMode
  * @memberOf VideoWidget.prototype
  * @type VideoWidget.ScaleMode
  */
VideoWidget.prototype.scaleMode = new VideoWidget.ScaleMode();

/**
  * @name brightness
  * @memberOf VideoWidget.prototype
  * @type Numeric
  */
VideoWidget.prototype.brightness = new Numeric();

/**
  * @name contrast
  * @memberOf VideoWidget.prototype
  * @type Numeric
  */
VideoWidget.prototype.contrast = new Numeric();

/**
  * @name hue
  * @memberOf VideoWidget.prototype
  * @type Numeric
  */
VideoWidget.prototype.hue = new Numeric();

/**
  * @name saturation
  * @memberOf VideoWidget.prototype
  * @type Numeric
  */
VideoWidget.prototype.saturation = new Numeric();


