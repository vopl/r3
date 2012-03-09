/**
  * @name QSocketNotifier
  * @constructor
  * @extends QObject
  * @param {Numeric} socket
  * @param {QApplication.Type} arg__2
  * @param {QObject} parent
  */
function QSocketNotifier(socket, arg__2, parent){return undefined;};

QSocketNotifier.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QSocketNotifier
  * @name Read
  * @see QSocketNotifier#Type
  * @type Number
  */
QSocketNotifier.Read = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSocketNotifier
  * @name Write
  * @see QSocketNotifier#Type
  * @type Number
  */
QSocketNotifier.Write = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSocketNotifier
  * @name Exception
  * @see QSocketNotifier#Type
  * @type Number
  */
QSocketNotifier.Exception = 0x2;

/**
  * @constructor 
  * @memberOf QSocketNotifier
  * @name Type
  */
QSocketNotifier.Type = function(value){;};



/**
  * @name isEnabled
  * @function
  * @memberOf QSocketNotifier.prototype
  * @returns {Boolean}
  */
QSocketNotifier.prototype.isEnabled = function(){return new Boolean();};

/**
  * @name socket
  * @function
  * @memberOf QSocketNotifier.prototype
  * @returns {Numeric}
  */
QSocketNotifier.prototype.socket = function(){return new Numeric();};

/**
  * @name type
  * @function
  * @memberOf QSocketNotifier.prototype
  * @returns {QApplication.Type}
  */
QSocketNotifier.prototype.type = function(){return new QApplication.Type();};

