/**
  * @name QNetworkInterface
  * @constructor
  */
function QNetworkInterface(){return undefined;};

/**
  * @name QNetworkInterface^1
  * @constructor
  * @param {QNetworkInterface} other
  */
function QNetworkInterface(other){return undefined;};

/**
  * @name allAddresses
  * @function
  * @memberOf QNetworkInterface
  * @returns {Array}
  */
QNetworkInterface.allAddresses = function(){return new Array();};

/**
  * @name allInterfaces
  * @function
  * @memberOf QNetworkInterface
  * @returns {Array}
  */
QNetworkInterface.allInterfaces = function(){return new Array();};

/**
  * @name interfaceFromIndex
  * @function
  * @memberOf QNetworkInterface
  * @param {Numeric} index
  * @returns {QNetworkInterface}
  */
QNetworkInterface.interfaceFromIndex = function(index){return new QNetworkInterface();};

/**
  * @name interfaceFromName
  * @function
  * @memberOf QNetworkInterface
  * @param {String} name
  * @returns {QNetworkInterface}
  */
QNetworkInterface.interfaceFromName = function(name){return new QNetworkInterface();};

/**
  * @default 0x1
  * @constant
  * @memberOf QNetworkInterface
  * @name IsUp
  * @see QNetworkInterface#InterfaceFlags
  * @see QNetworkInterface#InterfaceFlag
  * @type Number
  */
QNetworkInterface.IsUp = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QNetworkInterface
  * @name IsRunning
  * @see QNetworkInterface#InterfaceFlags
  * @see QNetworkInterface#InterfaceFlag
  * @type Number
  */
QNetworkInterface.IsRunning = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QNetworkInterface
  * @name CanBroadcast
  * @see QNetworkInterface#InterfaceFlags
  * @see QNetworkInterface#InterfaceFlag
  * @type Number
  */
QNetworkInterface.CanBroadcast = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QNetworkInterface
  * @name IsLoopBack
  * @see QNetworkInterface#InterfaceFlags
  * @see QNetworkInterface#InterfaceFlag
  * @type Number
  */
QNetworkInterface.IsLoopBack = 0x8;

/**
  * @default 0x10
  * @constant
  * @memberOf QNetworkInterface
  * @name IsPointToPoint
  * @see QNetworkInterface#InterfaceFlags
  * @see QNetworkInterface#InterfaceFlag
  * @type Number
  */
QNetworkInterface.IsPointToPoint = 0x10;

/**
  * @default 0x20
  * @constant
  * @memberOf QNetworkInterface
  * @name CanMulticast
  * @see QNetworkInterface#InterfaceFlags
  * @see QNetworkInterface#InterfaceFlag
  * @type Number
  */
QNetworkInterface.CanMulticast = 0x20;

/**
  * @constructor 
  * @memberOf QNetworkInterface
  * @name InterfaceFlag
  */
QNetworkInterface.InterfaceFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QNetworkInterface
  * @name InterfaceFlags
  */
QNetworkInterface.InterfaceFlags = function(value1, value2 /*, ...*/){;};


/**
  * @name addressEntries
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {Array}
  */
QNetworkInterface.prototype.addressEntries = function(){return new Array();};

/**
  * @name flags
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {QNetworkInterface.InterfaceFlags}
  */
QNetworkInterface.prototype.flags = function(){return new QNetworkInterface.InterfaceFlags();};

/**
  * @name hardwareAddress
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {String}
  */
QNetworkInterface.prototype.hardwareAddress = function(){return new String();};

/**
  * @name humanReadableName
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {String}
  */
QNetworkInterface.prototype.humanReadableName = function(){return new String();};

/**
  * @name index
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {Numeric}
  */
QNetworkInterface.prototype.index = function(){return new Numeric();};

/**
  * @name isValid
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {Boolean}
  */
QNetworkInterface.prototype.isValid = function(){return new Boolean();};

/**
  * @name name
  * @function
  * @memberOf QNetworkInterface.prototype
  * @returns {String}
  */
QNetworkInterface.prototype.name = function(){return new String();};

