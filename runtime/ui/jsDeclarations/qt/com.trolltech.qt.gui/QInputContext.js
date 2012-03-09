/**
  * @name QInputContext
  * @constructor
  * @extends QObject
  * @param {QObject} parent
  */
function QInputContext(parent){return undefined;};

QInputContext.prototype = new QObject();

/**
  * @default 0x0
  * @constant
  * @memberOf QInputContext
  * @name PreeditFormat
  * @see QInputContext#StandardFormat
  * @type Number
  */
QInputContext.PreeditFormat = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QInputContext
  * @name SelectionFormat
  * @see QInputContext#StandardFormat
  * @type Number
  */
QInputContext.SelectionFormat = 0x1;

/**
  * @constructor 
  * @memberOf QInputContext
  * @name StandardFormat
  */
QInputContext.StandardFormat = function(value){;};



/**
  * @name actions
  * @function
  * @memberOf QInputContext.prototype
  * @returns {Array}
  */
QInputContext.prototype.actions = function(){return new Array();};

/**
  * @name filterEvent
  * @function
  * @memberOf QInputContext.prototype
  * @param {QEvent} event
  * @returns {Boolean}
  */
QInputContext.prototype.filterEvent = function(event){return new Boolean();};

/**
  * @name focusWidget
  * @function
  * @memberOf QInputContext.prototype
  * @returns {QWidget}
  */
QInputContext.prototype.focusWidget = function(){return new QWidget();};

/**
  * @name font
  * @function
  * @memberOf QInputContext.prototype
  * @returns {QFont}
  */
QInputContext.prototype.font = function(){return new QFont();};

/**
  * @name identifierName
  * @function
  * @memberOf QInputContext.prototype
  * @returns {String}
  */
QInputContext.prototype.identifierName = function(){return new String();};

/**
  * @name isComposing
  * @function
  * @memberOf QInputContext.prototype
  * @returns {Boolean}
  */
QInputContext.prototype.isComposing = function(){return new Boolean();};

/**
  * @name language
  * @function
  * @memberOf QInputContext.prototype
  * @returns {String}
  */
QInputContext.prototype.language = function(){return new String();};

/**
  * @name mouseHandler
  * @function
  * @memberOf QInputContext.prototype
  * @param {Numeric} x
  * @param {QMouseEvent} event
  * @returns {undefined}
  */
QInputContext.prototype.mouseHandler = function(x, event){return undefined;};

/**
  * @name reset
  * @function
  * @memberOf QInputContext.prototype
  * @returns {undefined}
  */
QInputContext.prototype.reset = function(){return undefined;};

/**
  * @name sendEvent
  * @function
  * @memberOf QInputContext.prototype
  * @param {Object} event
  * @returns {undefined}
  */
QInputContext.prototype.sendEvent = function(event){return undefined;};

/**
  * @name standardFormat
  * @function
  * @memberOf QInputContext.prototype
  * @param {QInputContext.StandardFormat} s
  * @returns {QTextFormat}
  */
QInputContext.prototype.standardFormat = function(s){return new QTextFormat();};

/**
  * @name update
  * @function
  * @memberOf QInputContext.prototype
  * @returns {undefined}
  */
QInputContext.prototype.update = function(){return undefined;};

/**
  * @name widgetDestroyed
  * @function
  * @memberOf QInputContext.prototype
  * @param {QWidget} w
  * @returns {undefined}
  */
QInputContext.prototype.widgetDestroyed = function(w){return undefined;};

