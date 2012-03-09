/**
  * @name QDial
  * @constructor
  * @extends QAbstractSlider
  * @param {QWidget} parent
  */
function QDial(parent){return undefined;};

QDial.prototype = new QAbstractSlider();

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QDial.prototype
  * @returns {QSize}
  */
QDial.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setNotchTarget
  * @function
  * @memberOf QDial.prototype
  * @param {Numeric} target
  * @returns {undefined}
  */
QDial.prototype.setNotchTarget = function(target){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QDial.prototype
  * @returns {QSize}
  */
QDial.prototype.sizeHint = function(){return new QSize();};

/**
  * @name wrapping
  * @memberOf QDial.prototype
  * @type Boolean
  */
QDial.prototype.wrapping = new Boolean();

/**
  * @name notchSize
  * @memberOf QDial.prototype
  * @type Numeric
  */
QDial.prototype.notchSize = new Numeric();

/**
  * @name notchTarget
  * @memberOf QDial.prototype
  * @type Numeric
  */
QDial.prototype.notchTarget = new Numeric();

/**
  * @name notchesVisible
  * @memberOf QDial.prototype
  * @type Boolean
  */
QDial.prototype.notchesVisible = new Boolean();


