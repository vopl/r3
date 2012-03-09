/**
  * @name PlatformPlugin
  * @constructor
  */
function PlatformPlugin(){return undefined;};

/**
  * @name applicationName
  * @function
  * @memberOf PlatformPlugin.prototype
  * @returns {String}
  */
PlatformPlugin.prototype.applicationName = function(){return new String();};

/**
  * @name createBackend
  * @function
  * @memberOf PlatformPlugin.prototype
  * @returns {QObject}
  */
PlatformPlugin.prototype.createBackend = function(){return new QObject();};

/**
  * @name createMediaStream
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {QUrl} url
  * @param {QObject} parent
  * @returns {AbstractMediaStream}
  */
PlatformPlugin.prototype.createMediaStream = function(url, parent){return new AbstractMediaStream();};

/**
  * @name icon
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {String} name
  * @returns {QIcon}
  */
PlatformPlugin.prototype.icon = function(name){return new QIcon();};

/**
  * @name isMimeTypeAvailable
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {String} mimeType
  * @returns {Boolean}
  */
PlatformPlugin.prototype.isMimeTypeAvailable = function(mimeType){return new Boolean();};

/**
  * @name loadVolume
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {String} outputName
  * @returns {Numeric}
  */
PlatformPlugin.prototype.loadVolume = function(outputName){return new Numeric();};

/**
  * @name notification
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {String} notificationName
  * @param {String} text
  * @param {Array} actions
  * @param {QObject} receiver
  * @param {String} actionSlot
  * @returns {undefined}
  */
PlatformPlugin.prototype.notification = function(notificationName, text, actions, receiver, actionSlot){return undefined;};

/**
  * @name objectDescriptionIndexes
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {Phonon.ObjectDescriptionType} type
  * @returns {Array}
  */
PlatformPlugin.prototype.objectDescriptionIndexes = function(type){return new Array();};

/**
  * @name objectDescriptionProperties
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {Phonon.ObjectDescriptionType} type
  * @param {Numeric} index
  * @returns {Object}
  */
PlatformPlugin.prototype.objectDescriptionProperties = function(type, index){return new Object();};

/**
  * @name saveVolume
  * @function
  * @memberOf PlatformPlugin.prototype
  * @param {String} outputName
  * @param {Numeric} volume
  * @returns {undefined}
  */
PlatformPlugin.prototype.saveVolume = function(outputName, volume){return undefined;};

