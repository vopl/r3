/**
  * @name MediaController
  * @constructor
  * @extends QObject
  * @param {MediaObject} parent
  */
function MediaController(parent){return undefined;};

MediaController.prototype = new QObject();

/**
  * @default 1
  * @constant
  * @memberOf MediaController
  * @name Angles
  * @see MediaController#Features
  * @see MediaController#Feature
  * @type Number
  */
MediaController.Angles = 0x1;

/**
  * @default 2
  * @constant
  * @memberOf MediaController
  * @name Chapters
  * @see MediaController#Features
  * @see MediaController#Feature
  * @type Number
  */
MediaController.Chapters = 0x2;

/**
  * @default 4
  * @constant
  * @memberOf MediaController
  * @name Titles
  * @see MediaController#Features
  * @see MediaController#Feature
  * @type Number
  */
MediaController.Titles = 0x4;

/**
  * @constructor 
  * @memberOf MediaController
  * @name Feature
  */
MediaController.Feature = function(value){;};

/**
  * @constructor 
  * @memberOf MediaController
  * @name Features
  */
MediaController.Features = function(value1, value2 /*, ...*/){;};


/**
  * @name autoplayTitles
  * @function
  * @memberOf MediaController.prototype
  * @returns {Boolean}
  */
MediaController.prototype.autoplayTitles = function(){return new Boolean();};

/**
  * @name availableAngles
  * @function
  * @memberOf MediaController.prototype
  * @returns {Numeric}
  */
MediaController.prototype.availableAngles = function(){return new Numeric();};

/**
  * @name availableAudioChannels
  * @function
  * @memberOf MediaController.prototype
  * @returns {Array}
  */
MediaController.prototype.availableAudioChannels = function(){return new Array();};

/**
  * @name availableChapters
  * @function
  * @memberOf MediaController.prototype
  * @returns {Numeric}
  */
MediaController.prototype.availableChapters = function(){return new Numeric();};

/**
  * @name availableSubtitles
  * @function
  * @memberOf MediaController.prototype
  * @returns {Array}
  */
MediaController.prototype.availableSubtitles = function(){return new Array();};

/**
  * @name availableTitles
  * @function
  * @memberOf MediaController.prototype
  * @returns {Numeric}
  */
MediaController.prototype.availableTitles = function(){return new Numeric();};

/**
  * @name currentAngle
  * @function
  * @memberOf MediaController.prototype
  * @returns {Numeric}
  */
MediaController.prototype.currentAngle = function(){return new Numeric();};

/**
  * @name currentAudioChannel
  * @function
  * @memberOf MediaController.prototype
  * @returns {AudioChannelDescription}
  */
MediaController.prototype.currentAudioChannel = function(){return new AudioChannelDescription();};

/**
  * @name currentChapter
  * @function
  * @memberOf MediaController.prototype
  * @returns {Numeric}
  */
MediaController.prototype.currentChapter = function(){return new Numeric();};

/**
  * @name currentSubtitle
  * @function
  * @memberOf MediaController.prototype
  * @returns {SubtitleDescription}
  */
MediaController.prototype.currentSubtitle = function(){return new SubtitleDescription();};

/**
  * @name currentTitle
  * @function
  * @memberOf MediaController.prototype
  * @returns {Numeric}
  */
MediaController.prototype.currentTitle = function(){return new Numeric();};

/**
  * @name setCurrentAudioChannel
  * @function
  * @memberOf MediaController.prototype
  * @param {AudioChannelDescription} stream
  * @returns {undefined}
  */
MediaController.prototype.setCurrentAudioChannel = function(stream){return undefined;};

/**
  * @name setCurrentSubtitle
  * @function
  * @memberOf MediaController.prototype
  * @param {SubtitleDescription} stream
  * @returns {undefined}
  */
MediaController.prototype.setCurrentSubtitle = function(stream){return undefined;};

/**
  * @name supportedFeatures
  * @function
  * @memberOf MediaController.prototype
  * @returns {MediaController.Features}
  */
MediaController.prototype.supportedFeatures = function(){return new MediaController.Features();};

