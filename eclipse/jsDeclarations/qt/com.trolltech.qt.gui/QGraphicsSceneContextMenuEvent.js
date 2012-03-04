/**
  * @name QGraphicsSceneContextMenuEvent
  * @constructor
  * @extends QGraphicsSceneEvent
  * @param {QApplication.Type} type
  */
function QGraphicsSceneContextMenuEvent(type){return undefined;};

QGraphicsSceneContextMenuEvent.prototype = new QGraphicsSceneEvent();

/**
  * @default 0x0
  * @constant
  * @memberOf QGraphicsSceneContextMenuEvent
  * @name Mouse
  * @see QGraphicsSceneContextMenuEvent#Reason
  * @type Number
  */
QGraphicsSceneContextMenuEvent.Mouse = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QGraphicsSceneContextMenuEvent
  * @name Keyboard
  * @see QGraphicsSceneContextMenuEvent#Reason
  * @type Number
  */
QGraphicsSceneContextMenuEvent.Keyboard = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QGraphicsSceneContextMenuEvent
  * @name Other
  * @see QGraphicsSceneContextMenuEvent#Reason
  * @type Number
  */
QGraphicsSceneContextMenuEvent.Other = 0x2;

/**
  * @constructor 
  * @memberOf QGraphicsSceneContextMenuEvent
  * @name Reason
  */
QGraphicsSceneContextMenuEvent.Reason = function(value){;};



/**
  * @name modifiers
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @returns {Qt.KeyboardModifiers}
  */
QGraphicsSceneContextMenuEvent.prototype.modifiers = function(){return new Qt.KeyboardModifiers();};

/**
  * @name pos
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @returns {QPointF}
  */
QGraphicsSceneContextMenuEvent.prototype.pos = function(){return new QPointF();};

/**
  * @name reason
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @returns {QGraphicsSceneContextMenuEvent.Reason}
  */
QGraphicsSceneContextMenuEvent.prototype.reason = function(){return new QGraphicsSceneContextMenuEvent.Reason();};

/**
  * @name scenePos
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @returns {QPointF}
  */
QGraphicsSceneContextMenuEvent.prototype.scenePos = function(){return new QPointF();};

/**
  * @name screenPos
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @returns {QPoint}
  */
QGraphicsSceneContextMenuEvent.prototype.screenPos = function(){return new QPoint();};

/**
  * @name setModifiers
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @param {Qt.KeyboardModifiers} modifiers
  * @returns {undefined}
  */
QGraphicsSceneContextMenuEvent.prototype.setModifiers = function(modifiers){return undefined;};

/**
  * @name setPos
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QGraphicsSceneContextMenuEvent.prototype.setPos = function(pos){return undefined;};

/**
  * @name setReason
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @param {QGraphicsSceneContextMenuEvent.Reason} reason
  * @returns {undefined}
  */
QGraphicsSceneContextMenuEvent.prototype.setReason = function(reason){return undefined;};

/**
  * @name setScenePos
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @param {QPointF} pos
  * @returns {undefined}
  */
QGraphicsSceneContextMenuEvent.prototype.setScenePos = function(pos){return undefined;};

/**
  * @name setScreenPos
  * @function
  * @memberOf QGraphicsSceneContextMenuEvent.prototype
  * @param {QPoint} pos
  * @returns {undefined}
  */
QGraphicsSceneContextMenuEvent.prototype.setScreenPos = function(pos){return undefined;};

