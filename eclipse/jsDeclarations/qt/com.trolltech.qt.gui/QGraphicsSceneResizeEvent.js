/**
  * @name QGraphicsSceneResizeEvent
  * @constructor
  * @extends QGraphicsSceneEvent
  */
function QGraphicsSceneResizeEvent(){return undefined;};

QGraphicsSceneResizeEvent.prototype = new QGraphicsSceneEvent();

/**
  * @name newSize
  * @function
  * @memberOf QGraphicsSceneResizeEvent.prototype
  * @returns {QSizeF}
  */
QGraphicsSceneResizeEvent.prototype.newSize = function(){return new QSizeF();};

/**
  * @name oldSize
  * @function
  * @memberOf QGraphicsSceneResizeEvent.prototype
  * @returns {QSizeF}
  */
QGraphicsSceneResizeEvent.prototype.oldSize = function(){return new QSizeF();};

/**
  * @name setNewSize
  * @function
  * @memberOf QGraphicsSceneResizeEvent.prototype
  * @param {QSizeF} size
  * @returns {undefined}
  */
QGraphicsSceneResizeEvent.prototype.setNewSize = function(size){return undefined;};

/**
  * @name setOldSize
  * @function
  * @memberOf QGraphicsSceneResizeEvent.prototype
  * @param {QSizeF} size
  * @returns {undefined}
  */
QGraphicsSceneResizeEvent.prototype.setOldSize = function(size){return undefined;};

