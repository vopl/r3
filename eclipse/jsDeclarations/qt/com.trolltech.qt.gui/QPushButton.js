/**
  * @name QPushButton
  * @constructor
  * @extends QAbstractButton
  * @param {QWidget} parent
  */
function QPushButton(parent){return undefined;};

/**
  * @name QPushButton^1
  * @constructor
  * @extends QAbstractButton
  * @param {QIcon} icon
  * @param {String} text
  * @param {QWidget} parent
  */
function QPushButton(icon, text, parent){return undefined;};

/**
  * @name QPushButton^2
  * @constructor
  * @extends QAbstractButton
  * @param {String} text
  * @param {QWidget} parent
  */
function QPushButton(text, parent){return undefined;};

QPushButton.prototype = new QAbstractButton();

/**
  * @name menu
  * @function
  * @memberOf QPushButton.prototype
  * @returns {QMenu}
  */
QPushButton.prototype.menu = function(){return new QMenu();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QPushButton.prototype
  * @returns {QSize}
  */
QPushButton.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setMenu
  * @function
  * @memberOf QPushButton.prototype
  * @param {QMenu} menu
  * @returns {undefined}
  */
QPushButton.prototype.setMenu = function(menu){return undefined;};

/**
  * @name sizeHint
  * @function
  * @memberOf QPushButton.prototype
  * @returns {QSize}
  */
QPushButton.prototype.sizeHint = function(){return new QSize();};

/**
  * @name autoDefault
  * @memberOf QPushButton.prototype
  * @type Boolean
  */
QPushButton.prototype.autoDefault = new Boolean();

/**
  * @name default
  * @memberOf QPushButton.prototype
  * @type Boolean
  */
QPushButton.prototype['default'] = new Boolean();

/**
  * @name flat
  * @memberOf QPushButton.prototype
  * @type Boolean
  */
QPushButton.prototype.flat = new Boolean();


