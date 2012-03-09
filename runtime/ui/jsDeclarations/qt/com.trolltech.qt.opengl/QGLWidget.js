/**
  * @name QGLWidget
  * @constructor
  * @extends QWidget
  * @param {QGLContext} context
  * @param {QWidget} parent
  * @param {QGLWidget} shareWidget
  * @param {Qt.WindowFlags} f
  */
function QGLWidget(context, parent, shareWidget, f){return undefined;};

/**
  * @name QGLWidget^1
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  * @param {QGLWidget} shareWidget
  * @param {Qt.WindowFlags} f
  */
function QGLWidget(parent, shareWidget, f){return undefined;};

/**
  * @name QGLWidget^2
  * @constructor
  * @extends QWidget
  * @param {Object} format
  * @param {QWidget} parent
  * @param {QGLWidget} shareWidget
  * @param {Qt.WindowFlags} f
  */
function QGLWidget(format, parent, shareWidget, f){return undefined;};

QGLWidget.prototype = new QWidget();

/**
  * @name convertToGLFormat
  * @function
  * @memberOf QGLWidget
  * @param {QImage} img
  * @returns {QImage}
  */
QGLWidget.convertToGLFormat = function(img){return new QImage();};

/**
  * @name colormap
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {QGLColormap}
  */
QGLWidget.prototype.colormap = function(){return new QGLColormap();};

/**
  * @name context
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {QGLContext}
  */
QGLWidget.prototype.context = function(){return new QGLContext();};

/**
  * @name doneCurrent
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {undefined}
  */
QGLWidget.prototype.doneCurrent = function(){return undefined;};

/**
  * @name doubleBuffer
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {Boolean}
  */
QGLWidget.prototype.doubleBuffer = function(){return new Boolean();};

/**
  * @name format
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {Object}
  */
QGLWidget.prototype.format = function(){return new Object();};

/**
  * @name grabFrameBuffer
  * @function
  * @memberOf QGLWidget.prototype
  * @param {Boolean} withAlpha
  * @returns {QImage}
  */
QGLWidget.prototype.grabFrameBuffer = function(withAlpha){return new QImage();};

/**
  * @name isSharing
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {Boolean}
  */
QGLWidget.prototype.isSharing = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {Boolean}
  */
QGLWidget.prototype.isValid = function(){return new Boolean();};

/**
  * @name makeCurrent
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {undefined}
  */
QGLWidget.prototype.makeCurrent = function(){return undefined;};

/**
  * @name makeOverlayCurrent
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {undefined}
  */
QGLWidget.prototype.makeOverlayCurrent = function(){return undefined;};

/**
  * @name overlayContext
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {QGLContext}
  */
QGLWidget.prototype.overlayContext = function(){return new QGLContext();};

/**
  * @name qglClearColor
  * @function
  * @memberOf QGLWidget.prototype
  * @param {QColor} c
  * @returns {undefined}
  */
QGLWidget.prototype.qglClearColor = function(c){return undefined;};

/**
  * @name qglColor
  * @function
  * @memberOf QGLWidget.prototype
  * @param {QColor} c
  * @returns {undefined}
  */
QGLWidget.prototype.qglColor = function(c){return undefined;};

/**
  * @name renderPixmap
  * @function
  * @memberOf QGLWidget.prototype
  * @param {Numeric} w
  * @param {Numeric} h
  * @param {Boolean} useContext
  * @returns {QPixmap}
  */
QGLWidget.prototype.renderPixmap = function(w, h, useContext){return new QPixmap();};

/**
  * @name renderText
  * @function
  * @memberOf QGLWidget.prototype
  * @param {Numeric} x
  * @param {Numeric} y
  * @param {Numeric} z
  * @param {String} str
  * @param {QFont} fnt
  * @param {Numeric} listBase
  * @returns {undefined}
  */
QGLWidget.prototype.renderText = function(x, y, z, str, fnt, listBase){return undefined;};

/**
  * @name setColormap
  * @function
  * @memberOf QGLWidget.prototype
  * @param {QGLColormap} map
  * @returns {undefined}
  */
QGLWidget.prototype.setColormap = function(map){return undefined;};

/**
  * @name swapBuffers
  * @function
  * @memberOf QGLWidget.prototype
  * @returns {undefined}
  */
QGLWidget.prototype.swapBuffers = function(){return undefined;};

