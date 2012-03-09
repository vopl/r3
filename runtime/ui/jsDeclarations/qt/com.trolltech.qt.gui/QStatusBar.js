/**
  * @name QStatusBar
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QStatusBar(parent){return undefined;};

QStatusBar.prototype = new QWidget();

/**
  * @name addPermanentWidget
  * @function
  * @memberOf QStatusBar.prototype
  * @param {QWidget} widget
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QStatusBar.prototype.addPermanentWidget = function(widget, stretch){return undefined;};

/**
  * @name addWidget
  * @function
  * @memberOf QStatusBar.prototype
  * @param {QWidget} widget
  * @param {Numeric} stretch
  * @returns {undefined}
  */
QStatusBar.prototype.addWidget = function(widget, stretch){return undefined;};

/**
  * @name currentMessage
  * @function
  * @memberOf QStatusBar.prototype
  * @returns {String}
  */
QStatusBar.prototype.currentMessage = function(){return new String();};

/**
  * @name insertPermanentWidget
  * @function
  * @memberOf QStatusBar.prototype
  * @param {Numeric} index
  * @param {QWidget} widget
  * @param {Numeric} stretch
  * @returns {Numeric}
  */
QStatusBar.prototype.insertPermanentWidget = function(index, widget, stretch){return new Numeric();};

/**
  * @name insertWidget
  * @function
  * @memberOf QStatusBar.prototype
  * @param {Numeric} index
  * @param {QWidget} widget
  * @param {Numeric} stretch
  * @returns {Numeric}
  */
QStatusBar.prototype.insertWidget = function(index, widget, stretch){return new Numeric();};

/**
  * @name removeWidget
  * @function
  * @memberOf QStatusBar.prototype
  * @param {QWidget} widget
  * @returns {undefined}
  */
QStatusBar.prototype.removeWidget = function(widget){return undefined;};

/**
  * @name sizeGripEnabled
  * @memberOf QStatusBar.prototype
  * @type Boolean
  */
QStatusBar.prototype.sizeGripEnabled = new Boolean();


