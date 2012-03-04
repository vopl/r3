/**
  * @name QKeyEvent
  * @constructor
  * @extends QInputEvent
  * @param {QApplication.Type} type
  * @param {Numeric} key
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {String} text
  * @param {Boolean} autorep
  * @param {Numeric} count
  */
function QKeyEvent(type, key, modifiers, text, autorep, count){return undefined;};

QKeyEvent.prototype = new QInputEvent();

/**
  * @name createExtendedKeyEvent
  * @function
  * @memberOf QKeyEvent
  * @param {QApplication.Type} type
  * @param {Numeric} key
  * @param {Qt.KeyboardModifiers} modifiers
  * @param {Numeric} nativeScanCode
  * @param {Numeric} nativeVirtualKey
  * @param {Numeric} nativeModifiers
  * @param {String} text
  * @param {Boolean} autorep
  * @param {Numeric} count
  * @returns {QKeyEvent}
  */
QKeyEvent.createExtendedKeyEvent = function(type, key, modifiers, nativeScanCode, nativeVirtualKey, nativeModifiers, text, autorep, count){return new QKeyEvent();};

/**
  * @name count
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Numeric}
  */
QKeyEvent.prototype.count = function(){return new Numeric();};

/**
  * @name hasExtendedInfo
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Boolean}
  */
QKeyEvent.prototype.hasExtendedInfo = function(){return new Boolean();};

/**
  * @name isAutoRepeat
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Boolean}
  */
QKeyEvent.prototype.isAutoRepeat = function(){return new Boolean();};

/**
  * @name key
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Numeric}
  */
QKeyEvent.prototype.key = function(){return new Numeric();};

/**
  * @name matches
  * @function
  * @memberOf QKeyEvent.prototype
  * @param {QKeySequence.StandardKey} key
  * @returns {Boolean}
  */
QKeyEvent.prototype.matches = function(key){return new Boolean();};

/**
  * @name nativeModifiers
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Numeric}
  */
QKeyEvent.prototype.nativeModifiers = function(){return new Numeric();};

/**
  * @name nativeScanCode
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Numeric}
  */
QKeyEvent.prototype.nativeScanCode = function(){return new Numeric();};

/**
  * @name nativeVirtualKey
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {Numeric}
  */
QKeyEvent.prototype.nativeVirtualKey = function(){return new Numeric();};

/**
  * @name text
  * @function
  * @memberOf QKeyEvent.prototype
  * @returns {String}
  */
QKeyEvent.prototype.text = function(){return new String();};

