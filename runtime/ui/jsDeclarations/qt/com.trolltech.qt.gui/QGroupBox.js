/**
  * @name QGroupBox
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QGroupBox(parent){return undefined;};

/**
  * @name QGroupBox^1
  * @constructor
  * @extends QWidget
  * @param {String} title
  * @param {QWidget} parent
  */
function QGroupBox(title, parent){return undefined;};

QGroupBox.prototype = new QWidget();

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QGroupBox.prototype
  * @returns {QSize}
  */
QGroupBox.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name setAlignment
  * @function
  * @memberOf QGroupBox.prototype
  * @param {Numeric} alignment
  * @returns {undefined}
  */
QGroupBox.prototype.setAlignment = function(alignment){return undefined;};

/**
  * @name title
  * @memberOf QGroupBox.prototype
  * @type String
  */
QGroupBox.prototype.title = new String();

/**
  * @name alignment
  * @memberOf QGroupBox.prototype
  * @type Qt.Alignment
  */
QGroupBox.prototype.alignment = new Qt.Alignment();

/**
  * @name flat
  * @memberOf QGroupBox.prototype
  * @type Boolean
  */
QGroupBox.prototype.flat = new Boolean();

/**
  * @name checkable
  * @memberOf QGroupBox.prototype
  * @type Boolean
  */
QGroupBox.prototype.checkable = new Boolean();

/**
  * @name checked
  * @memberOf QGroupBox.prototype
  * @type Boolean
  */
QGroupBox.prototype.checked = new Boolean();


