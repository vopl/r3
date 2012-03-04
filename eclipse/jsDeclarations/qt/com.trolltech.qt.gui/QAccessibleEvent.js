/**
  * @name QAccessibleEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  * @param {Numeric} child
  */
function QAccessibleEvent(type, child){return undefined;};

QAccessibleEvent.prototype = new QEvent();

/**
  * @name child
  * @function
  * @memberOf QAccessibleEvent.prototype
  * @returns {Numeric}
  */
QAccessibleEvent.prototype.child = function(){return new Numeric();};

/**
  * @name setValue
  * @function
  * @memberOf QAccessibleEvent.prototype
  * @param {String} aText
  * @returns {undefined}
  */
QAccessibleEvent.prototype.setValue = function(aText){return undefined;};

/**
  * @name value
  * @function
  * @memberOf QAccessibleEvent.prototype
  * @returns {String}
  */
QAccessibleEvent.prototype.value = function(){return new String();};

