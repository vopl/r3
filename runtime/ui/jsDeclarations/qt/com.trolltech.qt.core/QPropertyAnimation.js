/**
  * @name QPropertyAnimation
  * @constructor
  * @extends QVariantAnimation
  * @param {QObject} parent
  */
function QPropertyAnimation(parent){return undefined;};

/**
  * @name QPropertyAnimation^1
  * @constructor
  * @extends QVariantAnimation
  * @param {QObject} target
  * @param {QByteArray} propertyName
  * @param {QObject} parent
  */
function QPropertyAnimation(target, propertyName, parent){return undefined;};

QPropertyAnimation.prototype = new QVariantAnimation();

/**
  * @name propertyName
  * @memberOf QPropertyAnimation.prototype
  * @type QByteArray
  */
QPropertyAnimation.prototype.propertyName = new QByteArray();

/**
  * @name targetObject
  * @memberOf QPropertyAnimation.prototype
  * @type QObject
  */
QPropertyAnimation.prototype.targetObject = new QObject();


