/**
  * @name QChildEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  * @param {QObject} child
  */
function QChildEvent(type, child){return undefined;};

QChildEvent.prototype = new QEvent();

/**
  * @name added
  * @function
  * @memberOf QChildEvent.prototype
  * @returns {Boolean}
  */
QChildEvent.prototype.added = function(){return new Boolean();};

/**
  * @name child
  * @function
  * @memberOf QChildEvent.prototype
  * @returns {QObject}
  */
QChildEvent.prototype.child = function(){return new QObject();};

/**
  * @name polished
  * @function
  * @memberOf QChildEvent.prototype
  * @returns {Boolean}
  */
QChildEvent.prototype.polished = function(){return new Boolean();};

/**
  * @name removed
  * @function
  * @memberOf QChildEvent.prototype
  * @returns {Boolean}
  */
QChildEvent.prototype.removed = function(){return new Boolean();};

