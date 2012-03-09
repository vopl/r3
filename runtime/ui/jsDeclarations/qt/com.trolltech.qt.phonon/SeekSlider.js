/**
  * @name SeekSlider
  * @constructor
  * @extends QWidget
  * @param {MediaObject} media
  * @param {QWidget} parent
  */
function SeekSlider(media, parent){return undefined;};

/**
  * @name SeekSlider^1
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function SeekSlider(parent){return undefined;};

SeekSlider.prototype = new QWidget();

/**
  * @name mediaObject
  * @function
  * @memberOf SeekSlider.prototype
  * @returns {MediaObject}
  */
SeekSlider.prototype.mediaObject = function(){return new MediaObject();};

/**
  * @name iconVisible
  * @memberOf SeekSlider.prototype
  * @type Boolean
  */
SeekSlider.prototype.iconVisible = new Boolean();

/**
  * @name tracking
  * @memberOf SeekSlider.prototype
  * @type Boolean
  */
SeekSlider.prototype.tracking = new Boolean();

/**
  * @name pageStep
  * @memberOf SeekSlider.prototype
  * @type Numeric
  */
SeekSlider.prototype.pageStep = new Numeric();

/**
  * @name singleStep
  * @memberOf SeekSlider.prototype
  * @type Numeric
  */
SeekSlider.prototype.singleStep = new Numeric();

/**
  * @name orientation
  * @memberOf SeekSlider.prototype
  * @type QPrinter.Orientation
  */
SeekSlider.prototype.orientation = new QPrinter.Orientation();

/**
  * @name iconSize
  * @memberOf SeekSlider.prototype
  * @type QSize
  */
SeekSlider.prototype.iconSize = new QSize();


