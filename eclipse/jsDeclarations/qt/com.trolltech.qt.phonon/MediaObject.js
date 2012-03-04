/**
  * @name MediaObject
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function MediaObject(parent){return undefined;};

MediaObject.prototype = new QObject();

/**
  * @name clearQueue
  * @function
  * @memberOf MediaObject.prototype
  * @returns {undefined}
  */
MediaObject.prototype.clearQueue = function(){return undefined;};

/**
  * @name currentSource
  * @function
  * @memberOf MediaObject.prototype
  * @returns {MediaSource}
  */
MediaObject.prototype.currentSource = function(){return new MediaSource();};

/**
  * @name currentTime
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Numeric}
  */
MediaObject.prototype.currentTime = function(){return new Numeric();};

/**
  * @name enqueue
  * @function
  * @memberOf MediaObject.prototype
  * @param {MediaSource} source
  * @returns {undefined}
  */
MediaObject.prototype.enqueue = function(source){return undefined;};

/**
  * @name enqueueUrls
  * @function
  * @memberOf MediaObject.prototype
  * @param {Array} urls
  * @returns {undefined}
  */
MediaObject.prototype.enqueueUrls = function(urls){return undefined;};

/**
  * @name errorString
  * @function
  * @memberOf MediaObject.prototype
  * @returns {String}
  */
MediaObject.prototype.errorString = function(){return new String();};

/**
  * @name errorType
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Phonon.ErrorType}
  */
MediaObject.prototype.errorType = function(){return new Phonon.ErrorType();};

/**
  * @name hasVideo
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Boolean}
  */
MediaObject.prototype.hasVideo = function(){return new Boolean();};

/**
  * @name isSeekable
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Boolean}
  */
MediaObject.prototype.isSeekable = function(){return new Boolean();};

/**
  * @name metaData
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Object}
  */
MediaObject.prototype.metaData = function(){return new Object();};

/**
  * @name queue
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Array}
  */
MediaObject.prototype.queue = function(){return new Array();};

/**
  * @name remainingTime
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Numeric}
  */
MediaObject.prototype.remainingTime = function(){return new Numeric();};

/**
  * @name setCurrentSource
  * @function
  * @memberOf MediaObject.prototype
  * @param {MediaSource} source
  * @returns {undefined}
  */
MediaObject.prototype.setCurrentSource = function(source){return undefined;};

/**
  * @name setQueue
  * @function
  * @memberOf MediaObject.prototype
  * @param {Array} sources
  * @returns {undefined}
  */
MediaObject.prototype.setQueue = function(sources){return undefined;};

/**
  * @name setQueueToUrls
  * @function
  * @memberOf MediaObject.prototype
  * @param {Array} urls
  * @returns {undefined}
  */
MediaObject.prototype.setQueueToUrls = function(urls){return undefined;};

/**
  * @name state
  * @function
  * @memberOf MediaObject.prototype
  * @returns {QTimeLine.State}
  */
MediaObject.prototype.state = function(){return new QTimeLine.State();};

/**
  * @name totalTime
  * @function
  * @memberOf MediaObject.prototype
  * @returns {Numeric}
  */
MediaObject.prototype.totalTime = function(){return new Numeric();};

/**
  * @name transitionTime
  * @memberOf MediaObject.prototype
  * @type Numeric
  */
MediaObject.prototype.transitionTime = new Numeric();

/**
  * @name prefinishMark
  * @memberOf MediaObject.prototype
  * @type Numeric
  */
MediaObject.prototype.prefinishMark = new Numeric();

/**
  * @name tickInterval
  * @memberOf MediaObject.prototype
  * @type Numeric
  */
MediaObject.prototype.tickInterval = new Numeric();


