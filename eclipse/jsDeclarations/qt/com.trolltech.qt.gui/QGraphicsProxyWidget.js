/**
  * @name QGraphicsProxyWidget
  * @constructor
  * @extends QGraphicsWidget
  * @param {QGraphicsItem} parent
  * @param {Qt.WindowFlags} wFlags
  */
function QGraphicsProxyWidget(parent, wFlags){return undefined;};

QGraphicsProxyWidget.prototype = new QGraphicsWidget();

/**
  * @name createProxyForChildWidget
  * @function
  * @memberOf QGraphicsProxyWidget.prototype
  * @param {QWidget} child
  * @returns {QGraphicsProxyWidget}
  */
QGraphicsProxyWidget.prototype.createProxyForChildWidget = function(child){return new QGraphicsProxyWidget();};

/**
  * @name setWidget
  * @function
  * @memberOf QGraphicsProxyWidget.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QGraphicsProxyWidget.prototype.setWidget = function(widget){return undefined;};

/**
  * @name subWidgetRect
  * @function
  * @memberOf QGraphicsProxyWidget.prototype
  * @param {QWidget} widget
  * @returns {QRectF}
  */
QGraphicsProxyWidget.prototype.subWidgetRect = function(widget){return new QRectF();};

/**
  * @name widget
  * @function
  * @memberOf QGraphicsProxyWidget.prototype
  * @returns {QWidget}
  */
QGraphicsProxyWidget.prototype.widget = function(){return new QWidget();};

