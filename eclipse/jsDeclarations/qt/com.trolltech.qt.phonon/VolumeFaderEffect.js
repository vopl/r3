/**
  * @name VolumeFaderEffect
  * @constructor
  * @extends Effect
  * @param {QObject} parent
  */
function VolumeFaderEffect(parent){return undefined;};

VolumeFaderEffect.prototype = new Effect();

/**
  * @default 0x0
  * @constant
  * @memberOf VolumeFaderEffect
  * @name Fade3Decibel
  * @see VolumeFaderEffect#FadeCurve
  * @type Number
  */
VolumeFaderEffect.Fade3Decibel = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf VolumeFaderEffect
  * @name Fade6Decibel
  * @see VolumeFaderEffect#FadeCurve
  * @type Number
  */
VolumeFaderEffect.Fade6Decibel = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf VolumeFaderEffect
  * @name Fade9Decibel
  * @see VolumeFaderEffect#FadeCurve
  * @type Number
  */
VolumeFaderEffect.Fade9Decibel = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf VolumeFaderEffect
  * @name Fade12Decibel
  * @see VolumeFaderEffect#FadeCurve
  * @type Number
  */
VolumeFaderEffect.Fade12Decibel = 0x3;

/**
  * @constructor 
  * @memberOf VolumeFaderEffect
  * @name FadeCurve
  */
VolumeFaderEffect.FadeCurve = function(value){;};



/**
  * @name volume
  * @memberOf VolumeFaderEffect.prototype
  * @type Numeric
  */
VolumeFaderEffect.prototype.volume = new Numeric();

/**
  * @name volumeDecibel
  * @memberOf VolumeFaderEffect.prototype
  * @type Numeric
  */
VolumeFaderEffect.prototype.volumeDecibel = new Numeric();

/**
  * @name fadeCurve
  * @memberOf VolumeFaderEffect.prototype
  * @type VolumeFaderEffect.FadeCurve
  */
VolumeFaderEffect.prototype.fadeCurve = new VolumeFaderEffect.FadeCurve();


