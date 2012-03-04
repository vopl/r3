/**
  * @name QProcess
  * @constructor
  * @extends QIODevice
  * @param {QObject} parent
  */
function QProcess(parent){return undefined;};

QProcess.prototype = new QIODevice();

/**
  * @name execute
  * @function
  * @memberOf QProcess
  * @param {String} program
  * @returns {Numeric}
  */
QProcess.execute = function(program){return new Numeric();};

/**
  * @name startDetached
  * @function
  * @memberOf QProcess
  * @param {String} program
  * @returns {Boolean}
  */
QProcess.startDetached = function(program){return new Boolean();};

/**
  * @name systemEnvironment
  * @function
  * @memberOf QProcess
  * @returns {Array}
  */
QProcess.systemEnvironment = function(){return new Array();};

/**
  * @default 0x0
  * @constant
  * @memberOf QProcess
  * @name FailedToStart
  * @see QProcess#ProcessError
  * @type Number
  */
QProcess.FailedToStart = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QProcess
  * @name Crashed
  * @see QProcess#ProcessError
  * @type Number
  */
QProcess.Crashed = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QProcess
  * @name Timedout
  * @see QProcess#ProcessError
  * @type Number
  */
QProcess.Timedout = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QProcess
  * @name ReadError
  * @see QProcess#ProcessError
  * @type Number
  */
QProcess.ReadError = 0x3;

/**
  * @default 0x4
  * @constant
  * @memberOf QProcess
  * @name WriteError
  * @see QProcess#ProcessError
  * @type Number
  */
QProcess.WriteError = 0x4;

/**
  * @default 0x5
  * @constant
  * @memberOf QProcess
  * @name UnknownError
  * @see QProcess#ProcessError
  * @type Number
  */
QProcess.UnknownError = 0x5;

/**
  * @constructor 
  * @memberOf QProcess
  * @name ProcessError
  */
QProcess.ProcessError = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QProcess
  * @name SeparateChannels
  * @see QProcess#ProcessChannelMode
  * @type Number
  */
QProcess.SeparateChannels = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QProcess
  * @name MergedChannels
  * @see QProcess#ProcessChannelMode
  * @type Number
  */
QProcess.MergedChannels = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QProcess
  * @name ForwardedChannels
  * @see QProcess#ProcessChannelMode
  * @type Number
  */
QProcess.ForwardedChannels = 0x2;

/**
  * @constructor 
  * @memberOf QProcess
  * @name ProcessChannelMode
  */
QProcess.ProcessChannelMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QProcess
  * @name StandardOutput
  * @see QProcess#ProcessChannel
  * @type Number
  */
QProcess.StandardOutput = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QProcess
  * @name StandardError
  * @see QProcess#ProcessChannel
  * @type Number
  */
QProcess.StandardError = 0x1;

/**
  * @constructor 
  * @memberOf QProcess
  * @name ProcessChannel
  */
QProcess.ProcessChannel = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QProcess
  * @name NotRunning
  * @see QProcess#ProcessState
  * @type Number
  */
QProcess.NotRunning = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QProcess
  * @name Starting
  * @see QProcess#ProcessState
  * @type Number
  */
QProcess.Starting = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QProcess
  * @name Running
  * @see QProcess#ProcessState
  * @type Number
  */
QProcess.Running = 0x2;

/**
  * @constructor 
  * @memberOf QProcess
  * @name ProcessState
  */
QProcess.ProcessState = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QProcess
  * @name NormalExit
  * @see QProcess#ExitStatus
  * @type Number
  */
QProcess.NormalExit = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QProcess
  * @name CrashExit
  * @see QProcess#ExitStatus
  * @type Number
  */
QProcess.CrashExit = 0x1;

/**
  * @constructor 
  * @memberOf QProcess
  * @name ExitStatus
  */
QProcess.ExitStatus = function(value){;};



/**
  * @name closeReadChannel
  * @function
  * @memberOf QProcess.prototype
  * @param {QProcess.ProcessChannel} channel
  * @returns {undefined}
  */
QProcess.prototype.closeReadChannel = function(channel){return undefined;};

/**
  * @name closeWriteChannel
  * @function
  * @memberOf QProcess.prototype
  * @returns {undefined}
  */
QProcess.prototype.closeWriteChannel = function(){return undefined;};

/**
  * @name environment
  * @function
  * @memberOf QProcess.prototype
  * @returns {Array}
  */
QProcess.prototype.environment = function(){return new Array();};

/**
  * @name error
  * @function
  * @memberOf QProcess.prototype
  * @returns {QProcess.ProcessError}
  */
QProcess.prototype.error = function(){return new QProcess.ProcessError();};

/**
  * @name exitCode
  * @function
  * @memberOf QProcess.prototype
  * @returns {Numeric}
  */
QProcess.prototype.exitCode = function(){return new Numeric();};

/**
  * @name exitStatus
  * @function
  * @memberOf QProcess.prototype
  * @returns {QProcess.ExitStatus}
  */
QProcess.prototype.exitStatus = function(){return new QProcess.ExitStatus();};

/**
  * @name processChannelMode
  * @function
  * @memberOf QProcess.prototype
  * @returns {QProcess.ProcessChannelMode}
  */
QProcess.prototype.processChannelMode = function(){return new QProcess.ProcessChannelMode();};

/**
  * @name processEnvironment
  * @function
  * @memberOf QProcess.prototype
  * @returns {QProcessEnvironment}
  */
QProcess.prototype.processEnvironment = function(){return new QProcessEnvironment();};

/**
  * @name readAllStandardError
  * @function
  * @memberOf QProcess.prototype
  * @returns {QByteArray}
  */
QProcess.prototype.readAllStandardError = function(){return new QByteArray();};

/**
  * @name readAllStandardOutput
  * @function
  * @memberOf QProcess.prototype
  * @returns {QByteArray}
  */
QProcess.prototype.readAllStandardOutput = function(){return new QByteArray();};

/**
  * @name readChannel
  * @function
  * @memberOf QProcess.prototype
  * @returns {QProcess.ProcessChannel}
  */
QProcess.prototype.readChannel = function(){return new QProcess.ProcessChannel();};

/**
  * @name setEnvironment
  * @function
  * @memberOf QProcess.prototype
  * @param {Array} environment
  * @returns {undefined}
  */
QProcess.prototype.setEnvironment = function(environment){return undefined;};

/**
  * @name setProcessChannelMode
  * @function
  * @memberOf QProcess.prototype
  * @param {QProcess.ProcessChannelMode} mode
  * @returns {undefined}
  */
QProcess.prototype.setProcessChannelMode = function(mode){return undefined;};

/**
  * @name setProcessEnvironment
  * @function
  * @memberOf QProcess.prototype
  * @param {QProcessEnvironment} environment
  * @returns {undefined}
  */
QProcess.prototype.setProcessEnvironment = function(environment){return undefined;};

/**
  * @name setReadChannel
  * @function
  * @memberOf QProcess.prototype
  * @param {QProcess.ProcessChannel} channel
  * @returns {undefined}
  */
QProcess.prototype.setReadChannel = function(channel){return undefined;};

/**
  * @name setStandardErrorFile
  * @function
  * @memberOf QProcess.prototype
  * @param {String} fileName
  * @param {QIODevice.OpenMode} mode
  * @returns {undefined}
  */
QProcess.prototype.setStandardErrorFile = function(fileName, mode){return undefined;};

/**
  * @name setStandardInputFile
  * @function
  * @memberOf QProcess.prototype
  * @param {String} fileName
  * @returns {undefined}
  */
QProcess.prototype.setStandardInputFile = function(fileName){return undefined;};

/**
  * @name setStandardOutputFile
  * @function
  * @memberOf QProcess.prototype
  * @param {String} fileName
  * @param {QIODevice.OpenMode} mode
  * @returns {undefined}
  */
QProcess.prototype.setStandardOutputFile = function(fileName, mode){return undefined;};

/**
  * @name setStandardOutputProcess
  * @function
  * @memberOf QProcess.prototype
  * @param {QProcess} destination
  * @returns {undefined}
  */
QProcess.prototype.setStandardOutputProcess = function(destination){return undefined;};

/**
  * @name setWorkingDirectory
  * @function
  * @memberOf QProcess.prototype
  * @param {String} dir
  * @returns {undefined}
  */
QProcess.prototype.setWorkingDirectory = function(dir){return undefined;};

/**
  * @name start
  * @function
  * @memberOf QProcess.prototype
  * @param {String} program
  * @param {QIODevice.OpenMode} mode
  * @returns {undefined}
  */
QProcess.prototype.start = function(program, mode){return undefined;};

/**
  * @name state
  * @function
  * @memberOf QProcess.prototype
  * @returns {QProcess.ProcessState}
  */
QProcess.prototype.state = function(){return new QProcess.ProcessState();};

/**
  * @name waitForFinished
  * @function
  * @memberOf QProcess.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QProcess.prototype.waitForFinished = function(msecs){return new Boolean();};

/**
  * @name waitForStarted
  * @function
  * @memberOf QProcess.prototype
  * @param {Numeric} msecs
  * @returns {Boolean}
  */
QProcess.prototype.waitForStarted = function(msecs){return new Boolean();};

/**
  * @name workingDirectory
  * @function
  * @memberOf QProcess.prototype
  * @returns {String}
  */
QProcess.prototype.workingDirectory = function(){return new String();};

