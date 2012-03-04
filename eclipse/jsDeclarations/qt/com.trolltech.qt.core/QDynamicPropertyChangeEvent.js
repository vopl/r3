/**
  * @name QDynamicPropertyChangeEvent
  * @constructor
  * @extends QEvent
  * @param {QByteArray} name
  */
function QDynamicPropertyChangeEvent(name){return undefined;};

QDynamicPropertyChangeEvent.prototype = new QEvent();

/**
  * @name propertyName
  * @function
  * @memberOf QDynamicPropertyChangeEvent.prototype
  * @returns {QByteArray}
  */
QDynamicPropertyChangeEvent.prototype.propertyName = function(){return new QByteArray();};

