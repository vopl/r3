/**
  * @name QGraphicsColorizeEffect
  * @constructor
  * @extends QGraphicsEffect
  * @param {QObject} parent
  */
function QGraphicsColorizeEffect(parent){return undefined;};

QGraphicsColorizeEffect.prototype = new QGraphicsEffect();

/**
  * @name color
  * @memberOf QGraphicsColorizeEffect.prototype
  * @type QColor
  */
QGraphicsColorizeEffect.prototype.color = new QColor();

/**
  * @name strength
  * @memberOf QGraphicsColorizeEffect.prototype
  * @type Numeric
  */
QGraphicsColorizeEffect.prototype.strength = new Numeric();


