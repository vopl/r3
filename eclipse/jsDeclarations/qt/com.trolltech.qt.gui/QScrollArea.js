/**
  * @name QScrollArea
  * @constructor
  * @extends QAbstractScrollArea
  * @param {QWidget} parent
  */
function QScrollArea(parent){return undefined;};

QScrollArea.prototype = new QAbstractScrollArea();

/**
  * @name ensureVisible
  * @function
  * @memberOf QScrollArea.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} xmargin
  * @param {Numeric} ymargin
  * @returns {undefined}
  */
QScrollArea.prototype.ensureVisible = function(x, y, xmargin, ymargin){return undefined;};

/**
  * @name ensureWidgetVisible
  * @function
  * @memberOf QScrollArea.prototype
  * @param {QWidget} childWidget
  * @param {Numeric} xmargin
  * @param {Numeric} ymargin
  * @returns {undefined}
  */
QScrollArea.prototype.ensureWidgetVisible = function(childWidget, xmargin, ymargin){return undefined;};

/**
  * @name setWidget
  * @function
  * @memberOf QScrollArea.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QScrollArea.prototype.setWidget = function(widget){return undefined;};

/**
  * @name takeWidget
  * @function
  * @memberOf QScrollArea.prototype
  * @returns {QWidget}
  */
QScrollArea.prototype.takeWidget = function(){return new QWidget();};

/**
  * @name widget
  * @function
  * @memberOf QScrollArea.prototype
  * @returns {QWidget}
  */
QScrollArea.prototype.widget = function(){return new QWidget();};

/**
  * @name widgetResizable
  * @memberOf QScrollArea.prototype
  * @type Boolean
  */
QScrollArea.prototype.widgetResizable = new Boolean();

/**
  * @name alignment
  * @memberOf QScrollArea.prototype
  * @type Qt.Alignment
  */
QScrollArea.prototype.alignment = new Qt.Alignment();


