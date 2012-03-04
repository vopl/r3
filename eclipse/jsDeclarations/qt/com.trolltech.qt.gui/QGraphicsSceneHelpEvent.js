/**
  * @name QGraphicsSceneHelpEvent
  * @constructor
  * @extends QGraphicsSceneEvent
  * @param {QApplication.Type} type
  */
function QGraphicsSceneHelpEvent(type){return undefined;};

QGraphicsSceneHelpEvent.prototype = new QGraphicsSceneEvent();

/**
  * @name scenePos
  * @function
  * @memberOf QGraphicsSceneHelpEvent.prototype
  * @returns {QPointF}
  */
QGraphicsSceneHelpEvent.prototype.scenePos = function(){return new QPointF();};

/**
  * @name screenPos
  * @function
  * @memberOf QGraphicsSceneHelpEvent.prototype
  * @returns {QPoint}
  */
QGraphicsSceneHelpEvent.prototype.screenPos = function(){return new QPoint();};

/**
  * @name setScenePos
  * @function
  * @memberOf QGraphicsSceneHelpEvent.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QGraphicsSceneHelpEvent.prototype.setScenePos = function(pos){return undefined;};

/**
  * @name setScreenPos
  * @function
  * @memberOf QGraphicsSceneHelpEvent.prototype
  * @param {QPoint} pos
  * @returns {undefined}
  */
QGraphicsSceneHelpEvent.prototype.setScreenPos = function(pos){return undefined;};

