/**
  * @name QSvgWidget
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QSvgWidget(parent){return undefined;};

/**
  * @name QSvgWidget^1
  * @constructor
  * @extends QWidget
  * @param {String} file
  * @param {QWidget} parent
  */
function QSvgWidget(file, parent){return undefined;};

QSvgWidget.prototype = new QWidget();

/**
  * @name renderer
  * @function
  * @memberOf QSvgWidget.prototype
  * @returns {QSvgRenderer}
  */
QSvgWidget.prototype.renderer = function(){return new QSvgRenderer();};

/**
  * @name sizeHint
  * @function
  * @memberOf QSvgWidget.prototype
  * @returns {QSize}
  */
QSvgWidget.prototype.sizeHint = function(){return new QSize();};

