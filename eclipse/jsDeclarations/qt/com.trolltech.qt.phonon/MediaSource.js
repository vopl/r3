/**
  * @name MediaSource
  * @constructor
  */
function MediaSource(){return undefined;};

/**
  * @name MediaSource^1
  * @constructor
  * @param {AbstractMediaStream} stream
  */
function MediaSource(stream){return undefined;};

/**
  * @name MediaSource^2
  * @constructor
  * @param {Phonon.DiscType} discType
  * @param {String} deviceName
  */
function MediaSource(discType, deviceName){return undefined;};

/**
  * @name MediaSource^3
  * @constructor
  * @param {QIODevice} ioDevice
  */
function MediaSource(ioDevice){return undefined;};

/**
  * @name MediaSource^4
  * @constructor
  * @param {MediaSource} rhs
  */
function MediaSource(rhs){return undefined;};

/**
  * @name MediaSource^5
  * @constructor
  * @param {String} fileName
  */
function MediaSource(fileName){return undefined;};

/**
  * @name MediaSource^6
  * @constructor
  * @param {QUrl} url
  */
function MediaSource(url){return undefined;};

/**
  * @default -1
  * @constant
  * @memberOf MediaSource
  * @name Invalid
  * @see MediaSource#Type
  * @type Number
  */
MediaSource.Invalid = 0xffffffff;

/**
  * @default 0x0
  * @constant
  * @memberOf MediaSource
  * @name LocalFile
  * @see MediaSource#Type
  * @type Number
  */
MediaSource.LocalFile = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf MediaSource
  * @name Url
  * @see MediaSource#Type
  * @type Number
  */
MediaSource.Url = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf MediaSource
  * @name Disc
  * @see MediaSource#Type
  * @type Number
  */
MediaSource.Disc = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf MediaSource
  * @name Stream
  * @see MediaSource#Type
  * @type Number
  */
MediaSource.Stream = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf MediaSource
  * @name Empty
  * @see MediaSource#Type
  * @type Number
  */
MediaSource.Empty = 0x4;

/**
  * @constructor 
  * @memberOf MediaSource
  * @name Type
  */
MediaSource.Type = function(value){;};



/**
  * @name autoDelete
  * @function
  * @memberOf MediaSource.prototype
  * @returns {Boolean}
  */
MediaSource.prototype.autoDelete = function(){return new Boolean();};

/**
  * @name deviceName
  * @function
  * @memberOf MediaSource.prototype
  * @returns {String}
  */
MediaSource.prototype.deviceName = function(){return new String();};

/**
  * @name discType
  * @function
  * @memberOf MediaSource.prototype
  * @returns {Phonon.DiscType}
  */
MediaSource.prototype.discType = function(){return new Phonon.DiscType();};

/**
  * @name fileName
  * @function
  * @memberOf MediaSource.prototype
  * @returns {String}
  */
MediaSource.prototype.fileName = function(){return new String();};

/**
  * @name operator_equal
  * @function
  * @memberOf MediaSource.prototype
  * @param {MediaSource} rhs
  * @returns {Boolean}
  */
MediaSource.prototype.operator_equal = function(rhs){return new Boolean();};

/**
  * @name setAutoDelete
  * @function
  * @memberOf MediaSource.prototype
  * @param {Boolean} enable
  * @returns {undefined}
  */
MediaSource.prototype.setAutoDelete = function(enable){return undefined;};

/**
  * @name stream
  * @function
  * @memberOf MediaSource.prototype
  * @returns {AbstractMediaStream}
  */
MediaSource.prototype.stream = function(){return new AbstractMediaStream();};

/**
  * @name type
  * @function
  * @memberOf MediaSource.prototype
  * @returns {QApplication.Type}
  */
MediaSource.prototype.type = function(){return new QApplication.Type();};

/**
  * @name url
  * @function
  * @memberOf MediaSource.prototype
  * @returns {QUrl}
  */
MediaSource.prototype.url = function(){return new QUrl();};

