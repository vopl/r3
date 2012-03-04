/**
  * @name QTouchEvent
  * @constructor
  * @extends QInputEvent
  * @param {QApplication.Type} eventType
  * @param {QTouchEvent.DeviceType} deviceType
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {Qt.TouchPointStates} touchPointStates
  * @param {Array} touchPoints
  */
function QTouchEvent(eventType, deviceType, modifiers, touchPointStates, touchPoints){return undefined;};

QTouchEvent.prototype = new QInputEvent();

/**
  * @default 0x0
  * @constant
  * @memberOf QTouchEvent
  * @name TouchScreen
  * @see QTouchEvent#DeviceType
  * @type Number
  */
QTouchEvent.TouchScreen = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QTouchEvent
  * @name TouchPad
  * @see QTouchEvent#DeviceType
  * @type Number
  */
QTouchEvent.TouchPad = 0x1;

/**
  * @constructor 
  * @memberOf QTouchEvent
  * @name DeviceType
  */
QTouchEvent.DeviceType = function(value){;};



/**
  * @name deviceType
  * @function
  * @memberOf QTouchEvent.prototype
  * @returns {QTouchEvent.DeviceType}
  */
QTouchEvent.prototype.deviceType = function(){return new QTouchEvent.DeviceType();};

/**
  * @name setDeviceType
  * @function
  * @memberOf QTouchEvent.prototype
  * @param {QTouchEvent.DeviceType} adeviceType
  * @returns {undefined}
  */
QTouchEvent.prototype.setDeviceType = function(adeviceType){return undefined;};

/**
  * @name setTouchPointStates
  * @function
  * @memberOf QTouchEvent.prototype
  * @param {Qt.TouchPointStates} aTouchPointStates
  * @returns {undefined}
  */
QTouchEvent.prototype.setTouchPointStates = function(aTouchPointStates){return undefined;};

/**
  * @name setTouchPoints
  * @function
  * @memberOf QTouchEvent.prototype
  * @param {Array} atouchPoints
  * @returns {undefined}
  */
QTouchEvent.prototype.setTouchPoints = function(atouchPoints){return undefined;};

/**
  * @name setWidget
  * @function
  * @memberOf QTouchEvent.prototype
  * @param {QWidget} awidget
  * @returns {undefined}
  */
QTouchEvent.prototype.setWidget = function(awidget){return undefined;};

/**
  * @name touchPointStates
  * @function
  * @memberOf QTouchEvent.prototype
  * @returns {Qt.TouchPointStates}
  */
QTouchEvent.prototype.touchPointStates = function(){return new Qt.TouchPointStates();};

/**
  * @name touchPoints
  * @function
  * @memberOf QTouchEvent.prototype
  * @returns {Array}
  */
QTouchEvent.prototype.touchPoints = function(){return new Array();};

/**
  * @name widget
  * @function
  * @memberOf QTouchEvent.prototype
  * @returns {QWidget}
  */
QTouchEvent.prototype.widget = function(){return new QWidget();};

