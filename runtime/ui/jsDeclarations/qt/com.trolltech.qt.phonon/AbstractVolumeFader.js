/**
  * @name AbstractVolumeFader
  * @constructor
  */
function AbstractVolumeFader(){return undefined;};

/**
  * @name fadeCurve
  * @function
  * @memberOf AbstractVolumeFader.prototype
  * @returns {VolumeFaderEffect.FadeCurve}
  */
AbstractVolumeFader.prototype.fadeCurve = function(){return new VolumeFaderEffect.FadeCurve();};

/**
  * @name fadeTo
  * @function
  * @memberOf AbstractVolumeFader.prototype
  * @param {Numeric} arg__1
  * @param {Numeric} arg__2
  * @returns {undefined}
  */
AbstractVolumeFader.prototype.fadeTo = function(arg__1, arg__2){return undefined;};

/**
  * @name setFadeCurve
  * @function
  * @memberOf AbstractVolumeFader.prototype
  * @param {VolumeFaderEffect.FadeCurve} arg__1
  * @returns {undefined}
  */
AbstractVolumeFader.prototype.setFadeCurve = function(arg__1){return undefined;};

/**
  * @name setVolume
  * @function
  * @memberOf AbstractVolumeFader.prototype
  * @param {Numeric} arg__1
  * @returns {undefined}
  */
AbstractVolumeFader.prototype.setVolume = function(arg__1){return undefined;};

/**
  * @name volume
  * @function
  * @memberOf AbstractVolumeFader.prototype
  * @returns {Numeric}
  */
AbstractVolumeFader.prototype.volume = function(){return new Numeric();};

