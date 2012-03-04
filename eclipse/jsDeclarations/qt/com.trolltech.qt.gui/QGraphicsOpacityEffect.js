/**
  * @name QGraphicsOpacityEffect
  * @constructor
  * @extends QGraphicsEffect
  * @param {QObject} parent
  */
function QGraphicsOpacityEffect(parent){return undefined;};

QGraphicsOpacityEffect.prototype = new QGraphicsEffect();

/**
  * @name opacity
  * @memberOf QGraphicsOpacityEffect.prototype
  * @type Numeric
  */
QGraphicsOpacityEffect.prototype.opacity = new Numeric();

/**
  * @name opacityMask
  * @memberOf QGraphicsOpacityEffect.prototype
  * @type QBrush
  */
QGraphicsOpacityEffect.prototype.opacityMask = new QBrush();


