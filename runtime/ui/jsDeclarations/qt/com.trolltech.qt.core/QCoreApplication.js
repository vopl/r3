/**
  * @name QCoreApplication
  * @constructor
  * @extends QObject
  * @param {Numeric} argc
  * @param {String} argv
  * @param {Numeric} arg__3
  */
function QCoreApplication(argc, argv, arg__3){return undefined;};

QCoreApplication.prototype = new QObject();

/**
  * @name addLibraryPath
  * @function
  * @memberOf QCoreApplication
  * @param {String} arg__1
  * @returns {undefined}
  */
QCoreApplication.addLibraryPath = function(arg__1){return undefined;};

/**
  * @name applicationDirPath
  * @function
  * @memberOf QCoreApplication
  * @returns {String}
  */
QCoreApplication.applicationDirPath = function(){return new String();};

/**
  * @name applicationFilePath
  * @function
  * @memberOf QCoreApplication
  * @returns {String}
  */
QCoreApplication.applicationFilePath = function(){return new String();};

/**
  * @name applicationPid
  * @function
  * @memberOf QCoreApplication
  * @returns {Numeric}
  */
QCoreApplication.applicationPid = function(){return new Numeric();};

/**
  * @name closingDown
  * @function
  * @memberOf QCoreApplication
  * @returns {Boolean}
  */
QCoreApplication.closingDown = function(){return new Boolean();};

/**
  * @name exec
  * @function
  * @memberOf QCoreApplication
  * @returns {Numeric}
  */
QCoreApplication.exec = function(){return new Numeric();};

/**
  * @name exit
  * @function
  * @memberOf QCoreApplication
  * @param {Numeric} retcode
  * @returns {undefined}
  */
QCoreApplication.exit = function(retcode){return undefined;};

/**
  * @name flush
  * @function
  * @memberOf QCoreApplication
  * @returns {undefined}
  */
QCoreApplication.flush = function(){return undefined;};

/**
  * @name hasPendingEvents
  * @function
  * @memberOf QCoreApplication
  * @returns {Boolean}
  */
QCoreApplication.hasPendingEvents = function(){return new Boolean();};

/**
  * @name installTranslator
  * @function
  * @memberOf QCoreApplication
  * @param {QTranslator} messageFile
  * @returns {undefined}
  */
QCoreApplication.installTranslator = function(messageFile){return undefined;};

/**
  * @name instance
  * @function
  * @memberOf QCoreApplication
  * @returns {QCoreApplication}
  */
QCoreApplication.instance = function(){return new QCoreApplication();};

/**
  * @name libraryPaths
  * @function
  * @memberOf QCoreApplication
  * @returns {Array}
  */
QCoreApplication.libraryPaths = function(){return new Array();};

/**
  * @name postEvent
  * @function
  * @memberOf QCoreApplication
  * @param {QObject} receiver
  * @param {QEvent} event
  * @returns {undefined}
  */
QCoreApplication.postEvent = function(receiver, event){return undefined;};

/**
  * @name processEvents
  * @function
  * @memberOf QCoreApplication
  * @param {QEventLoop.ProcessEventsFlags} flags
  * @returns {undefined}
  */
QCoreApplication.processEvents = function(flags){return undefined;};

/**
  * @name removeLibraryPath
  * @function
  * @memberOf QCoreApplication
  * @param {String} arg__1
  * @returns {undefined}
  */
QCoreApplication.removeLibraryPath = function(arg__1){return undefined;};

/**
  * @name removePostedEvents
  * @function
  * @memberOf QCoreApplication
  * @param {QObject} receiver
  * @returns {undefined}
  */
QCoreApplication.removePostedEvents = function(receiver){return undefined;};

/**
  * @name removeTranslator
  * @function
  * @memberOf QCoreApplication
  * @param {QTranslator} messageFile
  * @returns {undefined}
  */
QCoreApplication.removeTranslator = function(messageFile){return undefined;};

/**
  * @name sendEvent
  * @function
  * @memberOf QCoreApplication
  * @param {QObject} receiver
  * @param {QEvent} event
  * @returns {Boolean}
  */
QCoreApplication.sendEvent = function(receiver, event){return new Boolean();};

/**
  * @name sendPostedEvents
  * @function
  * @memberOf QCoreApplication
  * @returns {undefined}
  */
QCoreApplication.sendPostedEvents = function(){return undefined;};

/**
  * @name setAttribute
  * @function
  * @memberOf QCoreApplication
  * @param {Qt.ApplicationAttribute} attribute
  * @param {Boolean} on
  * @returns {undefined}
  */
QCoreApplication.setAttribute = function(attribute, on){return undefined;};

/**
  * @name setLibraryPaths
  * @function
  * @memberOf QCoreApplication
  * @param {Array} arg__1
  * @returns {undefined}
  */
QCoreApplication.setLibraryPaths = function(arg__1){return undefined;};

/**
  * @name startingUp
  * @function
  * @memberOf QCoreApplication
  * @returns {Boolean}
  */
QCoreApplication.startingUp = function(){return new Boolean();};

/**
  * @name testAttribute
  * @function
  * @memberOf QCoreApplication
  * @param {Qt.ApplicationAttribute} attribute
  * @returns {Boolean}
  */
QCoreApplication.testAttribute = function(attribute){return new Boolean();};

/**
  * @name translate
  * @function
  * @memberOf QCoreApplication
  * @param {String} context
  * @param {String} key
  * @param {String} disambiguation
  * @param {QCoreApplication.Encoding} encoding
  * @returns {String}
  */
QCoreApplication.translate = function(context, key, disambiguation, encoding){return new String();};

/**
  * @default 0x0
  * @constant
  * @memberOf QCoreApplication
  * @name CodecForTr
  * @see QCoreApplication#Encoding
  * @type Number
  */
QCoreApplication.CodecForTr = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCoreApplication
  * @name UnicodeUTF8
  * @see QCoreApplication#Encoding
  * @type Number
  */
QCoreApplication.UnicodeUTF8 = 0x1;

/**
  * @constructor 
  * @memberOf QCoreApplication
  * @name Encoding
  */
QCoreApplication.Encoding = function(value){;};



/**
  * @name notify
  * @function
  * @memberOf QCoreApplication.prototype
  * @param {QObject} arg__1
  * @param {QEvent} arg__2
  * @returns {Boolean}
  */
QCoreApplication.prototype.notify = function(arg__1, arg__2){return new Boolean();};

/**
  * @name applicationName
  * @memberOf QCoreApplication.prototype
  * @type String
  */
QCoreApplication.prototype.applicationName = new String();

/**
  * @name applicationVersion
  * @memberOf QCoreApplication.prototype
  * @type String
  */
QCoreApplication.prototype.applicationVersion = new String();

/**
  * @name organizationName
  * @memberOf QCoreApplication.prototype
  * @type String
  */
QCoreApplication.prototype.organizationName = new String();

/**
  * @name organizationDomain
  * @memberOf QCoreApplication.prototype
  * @type String
  */
QCoreApplication.prototype.organizationDomain = new String();


