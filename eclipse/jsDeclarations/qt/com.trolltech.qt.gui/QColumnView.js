/**
  * @name QColumnView
  * @constructor
  * @extends QAbstractItemView
  * @param {QWidget} parent
  */
function QColumnView(parent){return undefined;};

QColumnView.prototype = new QAbstractItemView();

/**
  * @name columnWidths
  * @function
  * @memberOf QColumnView.prototype
  * @returns {Array}
  */
QColumnView.prototype.columnWidths = function(){return new Array();};

/**
  * @name previewWidget
  * @function
  * @memberOf QColumnView.prototype
  * @returns {QWidget}
  */
QColumnView.prototype.previewWidget = function(){return new QWidget();};

/**
  * @name setColumnWidths
  * @function
  * @memberOf QColumnView.prototype
  * @param {Array} list
  * @returns {undefined}
  */
QColumnView.prototype.setColumnWidths = function(list){return undefined;};

/**
  * @name setPreviewWidget
  * @function
  * @memberOf QColumnView.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QColumnView.prototype.setPreviewWidget = function(widget){return undefined;};

/**
  * @name resizeGripsVisible
  * @memberOf QColumnView.prototype
  * @type Boolean
  */
QColumnView.prototype.resizeGripsVisible = new Boolean();


