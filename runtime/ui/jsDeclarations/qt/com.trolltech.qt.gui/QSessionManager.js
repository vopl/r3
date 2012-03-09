/**
  * @class QSessionManager from package com.trolltech.qt.gui
  * @extends QObject
  */
var QSessionManager = {};

QSessionManager.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QSessionManager
  * @name RestartIfRunning
  * @see QSessionManager#RestartHint
  * @type Number
  */
QSessionManager.RestartIfRunning = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QSessionManager
  * @name RestartAnyway
  * @see QSessionManager#RestartHint
  * @type Number
  */
QSessionManager.RestartAnyway = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QSessionManager
  * @name RestartImmediately
  * @see QSessionManager#RestartHint
  * @type Number
  */
QSessionManager.RestartImmediately = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QSessionManager
  * @name RestartNever
  * @see QSessionManager#RestartHint
  * @type Number
  */
QSessionManager.RestartNever = 0x3;

/**
  * @constructor 
  * @memberOf QSessionManager
  * @name RestartHint
  */
QSessionManager.RestartHint = function(value){;};



/**
  * @name allowsErrorInteraction
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {Boolean}
  */
QSessionManager.prototype.allowsErrorInteraction = function(){return new Boolean();};

/**
  * @name allowsInteraction
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {Boolean}
  */
QSessionManager.prototype.allowsInteraction = function(){return new Boolean();};

/**
  * @name cancel
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {undefined}
  */
QSessionManager.prototype.cancel = function(){return undefined;};

/**
  * @name discardCommand
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {Array}
  */
QSessionManager.prototype.discardCommand = function(){return new Array();};

/**
  * @name isPhase2
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {Boolean}
  */
QSessionManager.prototype.isPhase2 = function(){return new Boolean();};

/**
  * @name release
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {undefined}
  */
QSessionManager.prototype.release = function(){return undefined;};

/**
  * @name requestPhase2
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {undefined}
  */
QSessionManager.prototype.requestPhase2 = function(){return undefined;};

/**
  * @name restartCommand
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {Array}
  */
QSessionManager.prototype.restartCommand = function(){return new Array();};

/**
  * @name restartHint
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {QSessionManager.RestartHint}
  */
QSessionManager.prototype.restartHint = function(){return new QSessionManager.RestartHint();};

/**
  * @name sessionId
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {String}
  */
QSessionManager.prototype.sessionId = function(){return new String();};

/**
  * @name sessionKey
  * @function
  * @memberOf QSessionManager.prototype
  * @returns {String}
  */
QSessionManager.prototype.sessionKey = function(){return new String();};

/**
  * @name setDiscardCommand
  * @function
  * @memberOf QSessionManager.prototype
  * @param {Array} arg__1
  * @returns {undefined}
  */
QSessionManager.prototype.setDiscardCommand = function(arg__1){return undefined;};

/**
  * @name setManagerProperty
  * @function
  * @memberOf QSessionManager.prototype
  * @param {String} name
  * @param {String} value
  * @returns {undefined}
  */
QSessionManager.prototype.setManagerProperty = function(name, value){return undefined;};

/**
  * @name setRestartCommand
  * @function
  * @memberOf QSessionManager.prototype
  * @param {Array} arg__1
  * @returns {undefined}
  */
QSessionManager.prototype.setRestartCommand = function(arg__1){return undefined;};

/**
  * @name setRestartHint
  * @function
  * @memberOf QSessionManager.prototype
  * @param {QSessionManager.RestartHint} arg__1
  * @returns {undefined}
  */
QSessionManager.prototype.setRestartHint = function(arg__1){return undefined;};

