/**
  * @name QShortcut
  * @constructor
  * @extends QObject
  * @param {QWidget} parent
  */
function QShortcut(parent){return undefined;};

/**
  * @name QShortcut^1
  * @constructor
  * @extends QObject
  * @param {QKeySequence} key
  * @param {QWidget} parent
  * @param {String} member
  * @param {String} ambiguousMember
  * @param {Qt.ShortcutContext} context
  */
function QShortcut(key, parent, member, ambiguousMember, context){return undefined;};

QShortcut.prototype = new QObject();

/**
  * @name id
  * @function
  * @memberOf QShortcut.prototype
  * @returns {Numeric}
  */
QShortcut.prototype.id = function(){return new Numeric();};

/**
  * @name parentWidget
  * @function
  * @memberOf QShortcut.prototype
  * @returns {QWidget}
  */
QShortcut.prototype.parentWidget = function(){return new QWidget();};

/**
  * @name key
  * @memberOf QShortcut.prototype
  * @type QKeySequence
  */
QShortcut.prototype.key = new QKeySequence();

/**
  * @name whatsThis
  * @memberOf QShortcut.prototype
  * @type String
  */
QShortcut.prototype.whatsThis = new String();

/**
  * @name enabled
  * @memberOf QShortcut.prototype
  * @type Boolean
  */
QShortcut.prototype.enabled = new Boolean();

/**
  * @name autoRepeat
  * @memberOf QShortcut.prototype
  * @type Boolean
  */
QShortcut.prototype.autoRepeat = new Boolean();

/**
  * @name context
  * @memberOf QShortcut.prototype
  * @type Qt.ShortcutContext
  */
QShortcut.prototype.context = new Qt.ShortcutContext();


