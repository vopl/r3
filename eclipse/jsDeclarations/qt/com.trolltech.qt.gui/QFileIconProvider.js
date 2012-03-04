/**
  * @name QFileIconProvider
  * @constructor
  */
function QFileIconProvider(){return undefined;};

/**
  * @default 0x0
  * @constant
  * @memberOf QFileIconProvider
  * @name Computer
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.Computer = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFileIconProvider
  * @name Desktop
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.Desktop = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFileIconProvider
  * @name Trashcan
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.Trashcan = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QFileIconProvider
  * @name Network
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.Network = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QFileIconProvider
  * @name Drive
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.Drive = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QFileIconProvider
  * @name Folder
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.Folder = 0x5;

/**
  * @default 0x6
  * @constant
  * @memberOf QFileIconProvider
  * @name File
  * @see QFileIconProvider#IconType
  * @type Number
  */
QFileIconProvider.File = 0x6;

/**
  * @constructor 
  * @memberOf QFileIconProvider
  * @name IconType
  */
QFileIconProvider.IconType = function(value){;};



/**
  * @name icon
  * @function
  * @memberOf QFileIconProvider.prototype
  * @param {QFileIconProvider.IconType} type
  * @returns {QIcon}
  */
QFileIconProvider.prototype.icon = function(type){return new QIcon();};

/**
  * @name type
  * @function
  * @memberOf QFileIconProvider.prototype
  * @param {QFileInfo} info
  * @returns {String}
  */
QFileIconProvider.prototype.type = function(info){return new String();};

