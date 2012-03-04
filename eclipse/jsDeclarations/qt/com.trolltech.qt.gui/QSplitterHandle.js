/**
  * @name QSplitterHandle
  * @constructor
  * @extends QWidget
  * @param {QPrinter.Orientation} o
  * @param {QSplitter} parent
  */
function QSplitterHandle(o, parent){return undefined;};

QSplitterHandle.prototype = new QWidget();

/**
  * @name opaqueResize
  * @function
  * @memberOf QSplitterHandle.prototype
  * @returns {Boolean}
  */
QSplitterHandle.prototype.opaqueResize = function(){return new Boolean();};

/**
  * @name orientation
  * @function
  * @memberOf QSplitterHandle.prototype
  * @returns {QPrinter.Orientation}
  */
QSplitterHandle.prototype.orientation = function(){return new QPrinter.Orientation();};

/**
  * @name setOrientation
  * @function
  * @memberOf QSplitterHandle.prototype
  * @param {QPrinter.Orientation} o
  * @returns {undefined}
  */
QSplitterHandle.prototype.setOrientation = function(o){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QSplitterHandle.prototype
  * @returns {QSize}
  */
QSplitterHandle.prototype.sizeHint = function(){return new QSize();};

/**
  * @name splitter
  * @function
  * @memberOf QSplitterHandle.prototype
  * @returns {QSplitter}
  */
QSplitterHandle.prototype.splitter = function(){return new QSplitter();};

