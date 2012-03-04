/**
  * @name AudioOutput
  * @constructor
  * @extends AbstractAudioOutput
  * @param {Phonon.Category} category
  * @param {QObject} parent
  */
function AudioOutput(category, parent){return undefined;};

/**
  * @name AudioOutput^1
  * @constructor
  * @extends AbstractAudioOutput
  * @param {QObject} parent
  */
function AudioOutput(parent){return undefined;};

AudioOutput.prototype = new AbstractAudioOutput();

/**
  * @name category
  * @function
  * @memberOf AudioOutput.prototype
  * @returns {Phonon.Category}
  */
AudioOutput.prototype.category = function(){return new Phonon.Category();};

/**
  * @name name
  * @memberOf AudioOutput.prototype
  * @type String
  */
AudioOutput.prototype.name = new String();

/**
  * @name volume
  * @memberOf AudioOutput.prototype
  * @type Numeric
  */
AudioOutput.prototype.volume = new Numeric();

/**
  * @name volumeDecibel
  * @memberOf AudioOutput.prototype
  * @type Numeric
  */
AudioOutput.prototype.volumeDecibel = new Numeric();

/**
  * @name outputDevice
  * @memberOf AudioOutput.prototype
  * @type AudioOutputDevice
  */
AudioOutput.prototype.outputDevice = new AudioOutputDevice();

/**
  * @name muted
  * @memberOf AudioOutput.prototype
  * @type Boolean
  */
AudioOutput.prototype.muted = new Boolean();


