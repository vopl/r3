/**
  * @name QContextMenuEvent
  * @constructor
  * @extends QInputEvent
  * @param {QGraphicsSceneContextMenuEvent.Reason} reason
  * @param {QPoint} pos
  */
function QContextMenuEvent(reason, pos){return undefined;};

/**
  * @name QContextMenuEvent^1
  * @constructor
  * @extends QInputEvent
  * @param {QGraphicsSceneContextMenuEvent.Reason} reason
  * @param {QPoint} pos
  * @param {QPoint} globalPos
  */
function QContextMenuEvent(reason, pos, globalPos){return undefined;};

/**
  * @name QContextMenuEvent^2
  * @constructor
  * @extends QInputEvent
  * @param {QGraphicsSceneContextMenuEvent.Reason} reason
  * @param {QPoint} pos
  * @param {QPoint} globalPos
  * @param {Qt.KeyboardModifiers} modifiers
  */
function QContextMenuEvent(reason, pos, globalPos, modifiers){return undefined;};

QContextMenuEvent.prototype = new QInputEvent();

/**
  * @default 0x0
  * @constant
  * @memberOf QContextMenuEvent
  * @name Mouse
  * @see QContextMenuEvent#Reason
  * @type Number
  */
QContextMenuEvent.Mouse = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QContextMenuEvent
  * @name Keyboard
  * @see QContextMenuEvent#Reason
  * @type Number
  */
QContextMenuEvent.Keyboard = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QContextMenuEvent
  * @name Other
  * @see QContextMenuEvent#Reason
  * @type Number
  */
QContextMenuEvent.Other = 0x2;

/**
  * @constructor 
  * @memberOf QContextMenuEvent
  * @name Reason
  */
QContextMenuEvent.Reason = function(value){;};



/**
  * @name globalPos
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {QPoint}
  */
QContextMenuEvent.prototype.globalPos = function(){return new QPoint();};

/**
  * @name globalX
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {Numeric}
  */
QContextMenuEvent.prototype.globalX = function(){return new Numeric();};

/**
  * @name globalY
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {Numeric}
  */
QContextMenuEvent.prototype.globalY = function(){return new Numeric();};

/**
  * @name pos
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {QPoint}
  */
QContextMenuEvent.prototype.pos = function(){return new QPoint();};

/**
  * @name reason
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {QGraphicsSceneContextMenuEvent.Reason}
  */
QContextMenuEvent.prototype.reason = function(){return new QGraphicsSceneContextMenuEvent.Reason();};

/**
  * @name x
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {Numeric}
  */
QContextMenuEvent.prototype.x = function(){return new Numeric();};

/**
  * @name y
  * @function
  * @memberOf QContextMenuEvent.prototype
  * @returns {Numeric}
  */
QContextMenuEvent.prototype.y = function(){return new Numeric();};

