/**
  * @name QDragResponseEvent
  * @constructor
  * @extends QEvent
  * @param {Boolean} accepted
  */
function QDragResponseEvent(accepted){return undefined;};

QDragResponseEvent.prototype = new QEvent();

/**
  * @name dragAccepted
  * @function
  * @memberOf QDragResponseEvent.prototype
  * @returns {Boolean}
  */
QDragResponseEvent.prototype.dragAccepted = function(){return new Boolean();};

