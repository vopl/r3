/**
  * @name QPrintPreviewWidget
  * @constructor
  * @extends QWidget
  * @param {QPrinter} printer
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QPrintPreviewWidget(printer, parent, flags){return undefined;};

/**
  * @name QPrintPreviewWidget^1
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} flags
  */
function QPrintPreviewWidget(parent, flags){return undefined;};

QPrintPreviewWidget.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QPrintPreviewWidget
  * @name CustomZoom
  * @see QPrintPreviewWidget#ZoomMode
  * @type Number
  */
QPrintPreviewWidget.CustomZoom = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrintPreviewWidget
  * @name FitToWidth
  * @see QPrintPreviewWidget#ZoomMode
  * @type Number
  */
QPrintPreviewWidget.FitToWidth = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrintPreviewWidget
  * @name FitInView
  * @see QPrintPreviewWidget#ZoomMode
  * @type Number
  */
QPrintPreviewWidget.FitInView = 0x2;

/**
  * @constructor 
  * @memberOf QPrintPreviewWidget
  * @name ZoomMode
  */
QPrintPreviewWidget.ZoomMode = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QPrintPreviewWidget
  * @name SinglePageView
  * @see QPrintPreviewWidget#ViewMode
  * @type Number
  */
QPrintPreviewWidget.SinglePageView = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QPrintPreviewWidget
  * @name FacingPagesView
  * @see QPrintPreviewWidget#ViewMode
  * @type Number
  */
QPrintPreviewWidget.FacingPagesView = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QPrintPreviewWidget
  * @name AllPagesView
  * @see QPrintPreviewWidget#ViewMode
  * @type Number
  */
QPrintPreviewWidget.AllPagesView = 0x2;

/**
  * @constructor 
  * @memberOf QPrintPreviewWidget
  * @name ViewMode
  */
QPrintPreviewWidget.ViewMode = function(value){;};



/**
  * @name currentPage
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {Numeric}
  */
QPrintPreviewWidget.prototype.currentPage = function(){return new Numeric();};

/**
  * @name numPages
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {Numeric}
  */
QPrintPreviewWidget.prototype.numPages = function(){return new Numeric();};

/**
  * @name orientation
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {QPrinter.Orientation}
  */
QPrintPreviewWidget.prototype.orientation = function(){return new QPrinter.Orientation();};

/**
  * @name pageCount
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {Numeric}
  */
QPrintPreviewWidget.prototype.pageCount = function(){return new Numeric();};

/**
  * @name setVisible
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @param {Boolean} visible
  * @returns {undefined}
  */
QPrintPreviewWidget.prototype.setVisible = function(visible){return undefined;};

/**
  * @name viewMode
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {QListView.ViewMode}
  */
QPrintPreviewWidget.prototype.viewMode = function(){return new QListView.ViewMode();};

/**
  * @name zoomFactor
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {Numeric}
  */
QPrintPreviewWidget.prototype.zoomFactor = function(){return new Numeric();};

/**
  * @name zoomMode
  * @function
  * @memberOf QPrintPreviewWidget.prototype
  * @returns {QPrintPreviewWidget.ZoomMode}
  */
QPrintPreviewWidget.prototype.zoomMode = function(){return new QPrintPreviewWidget.ZoomMode();};

