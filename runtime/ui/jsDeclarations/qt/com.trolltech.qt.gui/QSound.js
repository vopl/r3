/**
  * @name QSound
  * @constructor
  * @extends QObject
  * @param {String} filename
  * @param {QObject} parent
  */
function QSound(filename, parent){return undefined;};

QSound.prototype = new QObject();

/**
  * @name isAvailable
  * @function
  * @memberOf QSound
  * @returns {Boolean}
  */
QSound.isAvailable = function(){return new Boolean();};

/**
  * @name play
  * @function
  * @memberOf QSound
  * @param {String} filename
  * @returns {undefined}
  */
QSound.play = function(filename){return undefined;};

/**
  * @name fileName
  * @function
  * @memberOf QSound.prototype
  * @returns {String}
  */
QSound.prototype.fileName = function(){return new String();};

/**
  * @name isFinished
  * @function
  * @memberOf QSound.prototype
  * @returns {Boolean}
  */
QSound.prototype.isFinished = function(){return new Boolean();};

/**
  * @name loops
  * @function
  * @memberOf QSound.prototype
  * @returns {Numeric}
  */
QSound.prototype.loops = function(){return new Numeric();};

/**
  * @name loopsRemaining
  * @function
  * @memberOf QSound.prototype
  * @returns {Numeric}
  */
QSound.prototype.loopsRemaining = function(){return new Numeric();};

/**
  * @name setLoops
  * @function
  * @memberOf QSound.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
QSound.prototype.setLoops = function(arg__1){return undefined;};

