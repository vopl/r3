/**
  * @name QShortcutEvent
  * @constructor
  * @extends QEvent
  * @param {QKeySequence} key
  * @param {Numeric} id
  * @param {Boolean} ambiguous
  */
function QShortcutEvent(key, id, ambiguous){return undefined;};

QShortcutEvent.prototype = new QEvent();

/**
  * @name isAmbiguous
  * @function
  * @memberOf QShortcutEvent.prototype
  * @returns {Boolean}
  */
QShortcutEvent.prototype.isAmbiguous = function(){return new Boolean();};

/**
  * @name key
  * @function
  * @memberOf QShortcutEvent.prototype
  * @returns {QKeySequence}
  */
QShortcutEvent.prototype.key = function(){return new QKeySequence();};

/**
  * @name shortcutId
  * @function
  * @memberOf QShortcutEvent.prototype
  * @returns {Numeric}
  */
QShortcutEvent.prototype.shortcutId = function(){return new Numeric();};

