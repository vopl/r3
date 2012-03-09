/**
  * @name VideoPlayer
  * @constructor
  * @extends QWidget
  * @param {Phonon.Category} category
  * @param {QWidget} parent
  */
function VideoPlayer(category, parent){return undefined;};

/**
  * @name VideoPlayer^1
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function VideoPlayer(parent){return undefined;};

VideoPlayer.prototype = new QWidget();

/**
  * @name audioOutput
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {AudioOutput}
  */
VideoPlayer.prototype.audioOutput = function(){return new AudioOutput();};

/**
  * @name currentTime
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {Numeric}
  */
VideoPlayer.prototype.currentTime = function(){return new Numeric();};

/**
  * @name isPaused
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {Boolean}
  */
VideoPlayer.prototype.isPaused = function(){return new Boolean();};

/**
  * @name isPlaying
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {Boolean}
  */
VideoPlayer.prototype.isPlaying = function(){return new Boolean();};

/**
  * @name mediaObject
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {MediaObject}
  */
VideoPlayer.prototype.mediaObject = function(){return new MediaObject();};

/**
  * @name totalTime
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {Numeric}
  */
VideoPlayer.prototype.totalTime = function(){return new Numeric();};

/**
  * @name videoWidget
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {VideoWidget}
  */
VideoPlayer.prototype.videoWidget = function(){return new VideoWidget();};

/**
  * @name volume
  * @function
  * @memberOf VideoPlayer.prototype
  * @returns {Numeric}
  */
VideoPlayer.prototype.volume = function(){return new Numeric();};

