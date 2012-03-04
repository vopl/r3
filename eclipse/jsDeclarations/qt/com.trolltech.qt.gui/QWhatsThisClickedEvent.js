/**
  * @name QWhatsThisClickedEvent
  * @constructor
  * @extends QEvent
  * @param {String} href
  */
function QWhatsThisClickedEvent(href){return undefined;};

QWhatsThisClickedEvent.prototype = new QEvent();

/**
  * @name href
  * @function
  * @memberOf QWhatsThisClickedEvent.prototype
  * @returns {String}
  */
QWhatsThisClickedEvent.prototype.href = function(){return new String();};

