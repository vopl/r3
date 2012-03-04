/**
  * @name QFontComboBox
  * @constructor
  * @extends QComboBox
  * @param {QWidget} parent
  */
function QFontComboBox(parent){return undefined;};

QFontComboBox.prototype = new QComboBox();

/**
  * @default 0
  * @constant
  * @memberOf QFontComboBox
  * @name AllFonts
  * @see QFontComboBox#FontFilters
  * @see QFontComboBox#FontFilter
  * @type Number
  */
QFontComboBox.AllFonts = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QFontComboBox
  * @name ScalableFonts
  * @see QFontComboBox#FontFilters
  * @see QFontComboBox#FontFilter
  * @type Number
  */
QFontComboBox.ScalableFonts = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QFontComboBox
  * @name NonScalableFonts
  * @see QFontComboBox#FontFilters
  * @see QFontComboBox#FontFilter
  * @type Number
  */
QFontComboBox.NonScalableFonts = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QFontComboBox
  * @name MonospacedFonts
  * @see QFontComboBox#FontFilters
  * @see QFontComboBox#FontFilter
  * @type Number
  */
QFontComboBox.MonospacedFonts = 0x4;

/**
  * @default 0x8
  * @constant
  * @memberOf QFontComboBox
  * @name ProportionalFonts
  * @see QFontComboBox#FontFilters
  * @see QFontComboBox#FontFilter
  * @type Number
  */
QFontComboBox.ProportionalFonts = 0x8;

/**
  * @constructor 
  * @memberOf QFontComboBox
  * @name FontFilter
  */
QFontComboBox.FontFilter = function(value){;};

/**
  * @constructor 
  * @memberOf QFontComboBox
  * @name FontFilters
  */
QFontComboBox.FontFilters = function(value1, value2 /*, ...*/){;};


/**
  * @name writingSystem
  * @memberOf QFontComboBox.prototype
  * @type String
  */
QFontComboBox.prototype.writingSystem = new String();

/**
  * @name fontFilters
  * @memberOf QFontComboBox.prototype
  * @type QFontComboBox.FontFilters
  */
QFontComboBox.prototype.fontFilters = new QFontComboBox.FontFilters();

/**
  * @name currentFont
  * @memberOf QFontComboBox.prototype
  * @type QFont
  */
QFontComboBox.prototype.currentFont = new QFont();


