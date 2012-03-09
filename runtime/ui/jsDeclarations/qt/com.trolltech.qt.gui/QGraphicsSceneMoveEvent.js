/**
  * @name QGraphicsSceneMoveEvent
  * @constructor
  * @extends QGraphicsSceneEvent
  */
function QGraphicsSceneMoveEvent(){return undefined;};

QGraphicsSceneMoveEvent.prototype = new QGraphicsSceneEvent();

/**
  * @name newPos
  * @function
  * @memberOf QGraphicsSceneMoveEvent.prototype
  * @returns {QPointF}
  */
QGraphicsSceneMoveEvent.prototype.newPos = function(){return new QPointF();};

/**
  * @name oldPos
  * @function
  * @memberOf QGraphicsSceneMoveEvent.prototype
  * @returns {QPointF}
  */
QGraphicsSceneMoveEvent.prototype.oldPos = function(){return new QPointF();};

/**
  * @name setNewPos
  * @function
  * @memberOf QGraphicsSceneMoveEvent.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QGraphicsSceneMoveEvent.prototype.setNewPos = function(pos){return undefined;};

/**
  * @name setOldPos
  * @function
  * @memberOf QGraphicsSceneMoveEvent.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QGraphicsSceneMoveEvent.prototype.setOldPos = function(pos){return undefined;};

