/**
  * @name QGraphicsSceneEvent
  * @constructor
  * @extends QEvent
  * @param {QApplication.Type} type
  */
function QGraphicsSceneEvent(type){return undefined;};

QGraphicsSceneEvent.prototype = new QEvent();

/**
  * @name widget
  * @function
  * @memberOf QGraphicsSceneEvent.prototype
  * @returns {QWidget}
  */
QGraphicsSceneEvent.prototype.widget = function(){return new QWidget();};

