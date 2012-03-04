/**
  * @name QAbstractButton
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QAbstractButton(parent){return undefined;};

QAbstractButton.prototype = new QWidget();

/**
  * @name group
  * @function
  * @memberOf QAbstractButton.prototype
  * @returns {QButtonGroup}
  */
QAbstractButton.prototype.group = function(){return new QButtonGroup();};

/**
  * @name text
  * @memberOf QAbstractButton.prototype
  * @type String
  */
QAbstractButton.prototype.text = new String();

/**
  * @name icon
  * @memberOf QAbstractButton.prototype
  * @type QIcon
  */
QAbstractButton.prototype.icon = new QIcon();

/**
  * @name iconSize
  * @memberOf QAbstractButton.prototype
  * @type QSize
  */
QAbstractButton.prototype.iconSize = new QSize();

/**
  * @name shortcut
  * @memberOf QAbstractButton.prototype
  * @type QKeySequence
  */
QAbstractButton.prototype.shortcut = new QKeySequence();

/**
  * @name checkable
  * @memberOf QAbstractButton.prototype
  * @type Boolean
  */
QAbstractButton.prototype.checkable = new Boolean();

/**
  * @name checked
  * @memberOf QAbstractButton.prototype
  * @type Boolean
  */
QAbstractButton.prototype.checked = new Boolean();

/**
  * @name autoRepeat
  * @memberOf QAbstractButton.prototype
  * @type Boolean
  */
QAbstractButton.prototype.autoRepeat = new Boolean();

/**
  * @name autoExclusive
  * @memberOf QAbstractButton.prototype
  * @type Boolean
  */
QAbstractButton.prototype.autoExclusive = new Boolean();

/**
  * @name autoRepeatDelay
  * @memberOf QAbstractButton.prototype
  * @type Numeric
  */
QAbstractButton.prototype.autoRepeatDelay = new Numeric();

/**
  * @name autoRepeatInterval
  * @memberOf QAbstractButton.prototype
  * @type Numeric
  */
QAbstractButton.prototype.autoRepeatInterval = new Numeric();

/**
  * @name down
  * @memberOf QAbstractButton.prototype
  * @type Boolean
  */
QAbstractButton.prototype.down = new Boolean();


