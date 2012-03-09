/**
  * @name QStatusTipEvent
  * @constructor
  * @extends QEvent
  * @param {String} tip
  */
function QStatusTipEvent(tip){return undefined;};

QStatusTipEvent.prototype = new QEvent();

/**
  * @name tip
  * @function
  * @memberOf QStatusTipEvent.prototype
  * @returns {String}
  */
QStatusTipEvent.prototype.tip = function(){return new String();};

