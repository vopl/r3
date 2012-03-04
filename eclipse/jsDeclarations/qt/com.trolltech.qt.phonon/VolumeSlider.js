/**
  * @name VolumeSlider
  * @constructor
  * @extends QWidget
  * @param {AudioOutput} arg__1
  * @param {QWidget} parent
  */
function VolumeSlider(arg__1, parent){return undefined;};

/**
  * @name VolumeSlider^1
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function VolumeSlider(parent){return undefined;};

VolumeSlider.prototype = new QWidget();

/**
  * @name audioOutput
  * @function
  * @memberOf VolumeSlider.prototype
  * @returns {AudioOutput}
  */
VolumeSlider.prototype.audioOutput = function(){return new AudioOutput();};

/**
  * @name maximumVolume
  * @memberOf VolumeSlider.prototype
  * @type Numeric
  */
VolumeSlider.prototype.maximumVolume = new Numeric();

/**
  * @name orientation
  * @memberOf VolumeSlider.prototype
  * @type QPrinter.Orientation
  */
VolumeSlider.prototype.orientation = new QPrinter.Orientation();

/**
  * @name tracking
  * @memberOf VolumeSlider.prototype
  * @type Boolean
  */
VolumeSlider.prototype.tracking = new Boolean();

/**
  * @name pageStep
  * @memberOf VolumeSlider.prototype
  * @type Numeric
  */
VolumeSlider.prototype.pageStep = new Numeric();

/**
  * @name singleStep
  * @memberOf VolumeSlider.prototype
  * @type Numeric
  */
VolumeSlider.prototype.singleStep = new Numeric();

/**
  * @name muteVisible
  * @memberOf VolumeSlider.prototype
  * @type Boolean
  */
VolumeSlider.prototype.muteVisible = new Boolean();

/**
  * @name iconSize
  * @memberOf VolumeSlider.prototype
  * @type QSize
  */
VolumeSlider.prototype.iconSize = new QSize();


