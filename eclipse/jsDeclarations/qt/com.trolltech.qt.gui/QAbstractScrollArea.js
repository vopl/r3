/**
  * @name QAbstractScrollArea
  * @constructor
  * @extends QFrame
  * @param {QWidget} parent
  */
function QAbstractScrollArea(parent){return undefined;};

QAbstractScrollArea.prototype = new QFrame();

/**
  * @name addScrollBarWidget
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @param {QWidget} widget
  * @param {Qt.Alignment} alignment
  * @returns {undefined}
  */
QAbstractScrollArea.prototype.addScrollBarWidget = function(widget, alignment){return undefined;};

/**
  * @name cornerWidget
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @returns {QWidget}
  */
QAbstractScrollArea.prototype.cornerWidget = function(){return new QWidget();};

/**
  * @name horizontalScrollBar
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @returns {QScrollBar}
  */
QAbstractScrollArea.prototype.horizontalScrollBar = function(){return new QScrollBar();};

/**
  * @name maximumViewportSize
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @returns {QSize}
  */
QAbstractScrollArea.prototype.maximumViewportSize = function(){return new QSize();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @returns {QSize}
  */
QAbstractScrollArea.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name scrollBarWidgets
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @param {Qt.Alignment} alignment
  * @returns {Array}
  */
QAbstractScrollArea.prototype.scrollBarWidgets = function(alignment){return new Array();};

/**
  * @name setCornerWidget
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QAbstractScrollArea.prototype.setCornerWidget = function(widget){return undefined;};

/**
  * @name setHorizontalScrollBar
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @param {QScrollBar} scrollbar
  * @returns {undefined}
  */
QAbstractScrollArea.prototype.setHorizontalScrollBar = function(scrollbar){return undefined;};

/**
  * @name setVerticalScrollBar
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @param {QScrollBar} scrollbar
  * @returns {undefined}
  */
QAbstractScrollArea.prototype.setVerticalScrollBar = function(scrollbar){return undefined;};

/**
  * @name setViewport
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QAbstractScrollArea.prototype.setViewport = function(widget){return undefined;};

/**
  * @name verticalScrollBar
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @returns {QScrollBar}
  */
QAbstractScrollArea.prototype.verticalScrollBar = function(){return new QScrollBar();};

/**
  * @name viewport
  * @function
  * @memberOf QAbstractScrollArea.prototype
  * @returns {QWidget}
  */
QAbstractScrollArea.prototype.viewport = function(){return new QWidget();};

/**
  * @name verticalScrollBarPolicy
  * @memberOf QAbstractScrollArea.prototype
  * @type Qt.ScrollBarPolicy
  */
QAbstractScrollArea.prototype.verticalScrollBarPolicy = new Qt.ScrollBarPolicy();

/**
  * @name horizontalScrollBarPolicy
  * @memberOf QAbstractScrollArea.prototype
  * @type Qt.ScrollBarPolicy
  */
QAbstractScrollArea.prototype.horizontalScrollBarPolicy = new Qt.ScrollBarPolicy();


