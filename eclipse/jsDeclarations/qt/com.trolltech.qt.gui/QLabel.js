/**
  * @name QLabel
  * @constructor
  * @extends QFrame
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QLabel(parent, f){return undefined;};

/**
  * @name QLabel^1
  * @constructor
  * @extends QFrame
  * @param {String} text
  * @param {QWidget} parent
  * @param {Qt.WindowFlags} f
  */
function QLabel(text, parent, f){return undefined;};

QLabel.prototype = new QFrame();

/**
  * @name buddy
  * @function
  * @memberOf QLabel.prototype
  * @returns {QWidget}
  */
QLabel.prototype.buddy = function(){return new QWidget();};

/**
  * @name minimumSizeHint
  * @function
  * @memberOf QLabel.prototype
  * @returns {QSize}
  */
QLabel.prototype.minimumSizeHint = function(){return new QSize();};

/**
  * @name movie
  * @function
  * @memberOf QLabel.prototype
  * @returns {QMovie}
  */
QLabel.prototype.movie = function(){return new QMovie();};

/**
  * @name picture_private
  * @function
  * @memberOf QLabel.prototype
  * @returns {QPicture}
  */
QLabel.prototype.picture_private = function(){return new QPicture();};

/**
  * @name selectionStart
  * @function
  * @memberOf QLabel.prototype
  * @returns {Numeric}
  */
QLabel.prototype.selectionStart = function(){return new Numeric();};

/**
  * @name setBuddy
  * @function
  * @memberOf QLabel.prototype
  * @param {QWidget} arg__1
  * @returns {undefined}
  */
QLabel.prototype.setBuddy = function(arg__1){return undefined;};

/**
  * @name setSelection
  * @function
  * @memberOf QLabel.prototype
  * @param {Numeric} arg__1
  * @param {Numeric} arg__2
  * @returns {undefined}
  */
QLabel.prototype.setSelection = function(arg__1, arg__2){return undefined;};

/**
  * @name text
  * @memberOf QLabel.prototype
  * @type String
  */
QLabel.prototype.text = new String();

/**
  * @name textFormat
  * @memberOf QLabel.prototype
  * @type Qt.TextFormat
  */
QLabel.prototype.textFormat = new Qt.TextFormat();

/**
  * @name pixmap
  * @memberOf QLabel.prototype
  * @type QPixmap
  */
QLabel.prototype.pixmap = new QPixmap();

/**
  * @name scaledContents
  * @memberOf QLabel.prototype
  * @type Boolean
  */
QLabel.prototype.scaledContents = new Boolean();

/**
  * @name alignment
  * @memberOf QLabel.prototype
  * @type Qt.Alignment
  */
QLabel.prototype.alignment = new Qt.Alignment();

/**
  * @name wordWrap
  * @memberOf QLabel.prototype
  * @type Boolean
  */
QLabel.prototype.wordWrap = new Boolean();

/**
  * @name margin
  * @memberOf QLabel.prototype
  * @type Numeric
  */
QLabel.prototype.margin = new Numeric();

/**
  * @name indent
  * @memberOf QLabel.prototype
  * @type Numeric
  */
QLabel.prototype.indent = new Numeric();

/**
  * @name openExternalLinks
  * @memberOf QLabel.prototype
  * @type Boolean
  */
QLabel.prototype.openExternalLinks = new Boolean();

/**
  * @name textInteractionFlags
  * @memberOf QLabel.prototype
  * @type Qt.TextInteractionFlags
  */
QLabel.prototype.textInteractionFlags = new Qt.TextInteractionFlags();

/**
  * @name hasSelectedText
  * @memberOf QLabel.prototype
  * @type Boolean
  */
QLabel.prototype.hasSelectedText = new Boolean();

/**
  * @name selectedText
  * @memberOf QLabel.prototype
  * @type String
  */
QLabel.prototype.selectedText = new String();


