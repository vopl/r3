/**
  * @name QGraphicsSimpleTextItem
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsSimpleTextItem(parent, scene){return undefined;};

/**
  * @name QGraphicsSimpleTextItem^1
  * @constructor
  * @extends QAbstractGraphicsShapeItem
  * @param {String} text
  * @param {QGraphicsItem} parent
  * @param {QGraphicsScene} scene
  */
function QGraphicsSimpleTextItem(text, parent, scene){return undefined;};

QGraphicsSimpleTextItem.prototype = new QAbstractGraphicsShapeItem();

/**
  * @name font
  * @function
  * @memberOf QGraphicsSimpleTextItem.prototype
  * @returns {QFont}
  */
QGraphicsSimpleTextItem.prototype.font = function(){return new QFont();};

/**
  * @name setFont
  * @function
  * @memberOf QGraphicsSimpleTextItem.prototype
  * @param {QFont} font
  * @returns {undefined}
  */
QGraphicsSimpleTextItem.prototype.setFont = function(font){return undefined;};

/**
  * @name setText
  * @function
  * @memberOf QGraphicsSimpleTextItem.prototype
  * @param {String} text
  * @returns {undefined}
  */
QGraphicsSimpleTextItem.prototype.setText = function(text){return undefined;};

/**
  * @name text
  * @function
  * @memberOf QGraphicsSimpleTextItem.prototype
  * @returns {String}
  */
QGraphicsSimpleTextItem.prototype.text = function(){return new String();};

