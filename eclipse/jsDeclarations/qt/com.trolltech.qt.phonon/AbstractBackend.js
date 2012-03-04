/**
  * @name AbstractBackend
  * @constructor
  */
function AbstractBackend(){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf AbstractBackend
  * @name MediaObjectClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.MediaObjectClass = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf AbstractBackend
  * @name VolumeFaderEffectClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.VolumeFaderEffectClass = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf AbstractBackend
  * @name AudioOutputClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.AudioOutputClass = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf AbstractBackend
  * @name AudioDataOutputClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.AudioDataOutputClass = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf AbstractBackend
  * @name VisualizationClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.VisualizationClass = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf AbstractBackend
  * @name VideoDataOutputClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.VideoDataOutputClass = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf AbstractBackend
  * @name EffectClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.EffectClass = 0x6;

/**
  * @default 0x7
  * @constant
  * @memberOf AbstractBackend
  * @name VideoWidgetClass
  * @see AbstractBackend#Class
  * @type Number
  */
AbstractBackend.VideoWidgetClass = 0x7;

/**
  * @constructor 
  * @memberOf AbstractBackend
  * @name Class
  */
AbstractBackend.Class = function(value){;};



/**
  * @name availableMimeTypes
  * @function
  * @memberOf AbstractBackend.prototype
  * @returns {Array}
  */
AbstractBackend.prototype.availableMimeTypes = function(){return new Array();};

/**
  * @name connectNodes
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {QObject} arg__1
  * @param {QObject} arg__2
  * @returns {Boolean}
  */
AbstractBackend.prototype.connectNodes = function(arg__1, arg__2){return new Boolean();};

/**
  * @name createObject
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {AbstractBackend.Class} c
  * @param {QObject} parent
  * @param {Array} args
  * @returns {QObject}
  */
AbstractBackend.prototype.createObject = function(c, parent, args){return new QObject();};

/**
  * @name disconnectNodes
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {QObject} arg__1
  * @param {QObject} arg__2
  * @returns {Boolean}
  */
AbstractBackend.prototype.disconnectNodes = function(arg__1, arg__2){return new Boolean();};

/**
  * @name endConnectionChange
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {Array} arg__1
  * @returns {Boolean}
  */
AbstractBackend.prototype.endConnectionChange = function(arg__1){return new Boolean();};

/**
  * @name objectDescriptionIndexes
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {Phonon.ObjectDescriptionType} type
  * @returns {Array}
  */
AbstractBackend.prototype.objectDescriptionIndexes = function(type){return new Array();};

/**
  * @name objectDescriptionProperties
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {Phonon.ObjectDescriptionType} type
  * @param {Numeric} index
  * @returns {Object}
  */
AbstractBackend.prototype.objectDescriptionProperties = function(type, index){return new Object();};

/**
  * @name startConnectionChange
  * @function
  * @memberOf AbstractBackend.prototype
  * @param {Array} arg__1
  * @returns {Boolean}
  */
AbstractBackend.prototype.startConnectionChange = function(arg__1){return new Boolean();};

