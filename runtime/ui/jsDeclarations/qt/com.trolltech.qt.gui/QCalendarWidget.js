/**
  * @name QCalendarWidget
  * @constructor
  * @extends QWidget
  * @param {QWidget} parent
  */
function QCalendarWidget(parent){return undefined;};

QCalendarWidget.prototype = new QWidget();

/**
  * @default 0x0
  * @constant
  * @memberOf QCalendarWidget
  * @name NoHorizontalHeader
  * @see QCalendarWidget#HorizontalHeaderFormat
  * @type Number
  */
QCalendarWidget.NoHorizontalHeader = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCalendarWidget
  * @name SingleLetterDayNames
  * @see QCalendarWidget#HorizontalHeaderFormat
  * @type Number
  */
QCalendarWidget.SingleLetterDayNames = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QCalendarWidget
  * @name ShortDayNames
  * @see QCalendarWidget#HorizontalHeaderFormat
  * @type Number
  */
QCalendarWidget.ShortDayNames = 0x2;

/**
  * @default 0x3
  * @constant
  * @memberOf QCalendarWidget
  * @name LongDayNames
  * @see QCalendarWidget#HorizontalHeaderFormat
  * @type Number
  */
QCalendarWidget.LongDayNames = 0x3;

/**
  * @constructor 
  * @memberOf QCalendarWidget
  * @name HorizontalHeaderFormat
  */
QCalendarWidget.HorizontalHeaderFormat = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QCalendarWidget
  * @name NoVerticalHeader
  * @see QCalendarWidget#VerticalHeaderFormat
  * @type Number
  */
QCalendarWidget.NoVerticalHeader = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCalendarWidget
  * @name ISOWeekNumbers
  * @see QCalendarWidget#VerticalHeaderFormat
  * @type Number
  */
QCalendarWidget.ISOWeekNumbers = 0x1;

/**
  * @constructor 
  * @memberOf QCalendarWidget
  * @name VerticalHeaderFormat
  */
QCalendarWidget.VerticalHeaderFormat = function(value){;};



/**
  * @default 0x0
  * @constant
  * @memberOf QCalendarWidget
  * @name NoSelection
  * @see QCalendarWidget#SelectionMode
  * @type Number
  */
QCalendarWidget.NoSelection = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QCalendarWidget
  * @name SingleSelection
  * @see QCalendarWidget#SelectionMode
  * @type Number
  */
QCalendarWidget.SingleSelection = 0x1;

/**
  * @constructor 
  * @memberOf QCalendarWidget
  * @name SelectionMode
  */
QCalendarWidget.SelectionMode = function(value){;};



/**
  * @name dateTextFormat
  * @function
  * @memberOf QCalendarWidget.prototype
  * @returns {Object}
  */
QCalendarWidget.prototype.dateTextFormat = function(){return new Object();};

/**
  * @name headerTextFormat
  * @function
  * @memberOf QCalendarWidget.prototype
  * @returns {QTextCharFormat}
  */
QCalendarWidget.prototype.headerTextFormat = function(){return new QTextCharFormat();};

/**
  * @name monthShown
  * @function
  * @memberOf QCalendarWidget.prototype
  * @returns {Numeric}
  */
QCalendarWidget.prototype.monthShown = function(){return new Numeric();};

/**
  * @name setDateTextFormat
  * @function
  * @memberOf QCalendarWidget.prototype
  * @param {QDate} date
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QCalendarWidget.prototype.setDateTextFormat = function(date, format){return undefined;};

/**
  * @name setHeaderTextFormat
  * @function
  * @memberOf QCalendarWidget.prototype
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QCalendarWidget.prototype.setHeaderTextFormat = function(format){return undefined;};

/**
  * @name setWeekdayTextFormat
  * @function
  * @memberOf QCalendarWidget.prototype
  * @param {Qt.DayOfWeek} dayOfWeek
  * @param {QTextCharFormat} format
  * @returns {undefined}
  */
QCalendarWidget.prototype.setWeekdayTextFormat = function(dayOfWeek, format){return undefined;};

/**
  * @name weekdayTextFormat
  * @function
  * @memberOf QCalendarWidget.prototype
  * @param {Qt.DayOfWeek} dayOfWeek
  * @returns {QTextCharFormat}
  */
QCalendarWidget.prototype.weekdayTextFormat = function(dayOfWeek){return new QTextCharFormat();};

/**
  * @name yearShown
  * @function
  * @memberOf QCalendarWidget.prototype
  * @returns {Numeric}
  */
QCalendarWidget.prototype.yearShown = function(){return new Numeric();};

/**
  * @name selectedDate
  * @memberOf QCalendarWidget.prototype
  * @type QDate
  */
QCalendarWidget.prototype.selectedDate = new QDate();

/**
  * @name minimumDate
  * @memberOf QCalendarWidget.prototype
  * @type QDate
  */
QCalendarWidget.prototype.minimumDate = new QDate();

/**
  * @name maximumDate
  * @memberOf QCalendarWidget.prototype
  * @type QDate
  */
QCalendarWidget.prototype.maximumDate = new QDate();

/**
  * @name firstDayOfWeek
  * @memberOf QCalendarWidget.prototype
  * @type Qt.DayOfWeek
  */
QCalendarWidget.prototype.firstDayOfWeek = new Qt.DayOfWeek();

/**
  * @name gridVisible
  * @memberOf QCalendarWidget.prototype
  * @type Boolean
  */
QCalendarWidget.prototype.gridVisible = new Boolean();

/**
  * @name selectionMode
  * @memberOf QCalendarWidget.prototype
  * @type QAbstractItemView.SelectionMode
  */
QCalendarWidget.prototype.selectionMode = new QAbstractItemView.SelectionMode();

/**
  * @name horizontalHeaderFormat
  * @memberOf QCalendarWidget.prototype
  * @type QCalendarWidget.HorizontalHeaderFormat
  */
QCalendarWidget.prototype.horizontalHeaderFormat = new QCalendarWidget.HorizontalHeaderFormat();

/**
  * @name verticalHeaderFormat
  * @memberOf QCalendarWidget.prototype
  * @type QCalendarWidget.VerticalHeaderFormat
  */
QCalendarWidget.prototype.verticalHeaderFormat = new QCalendarWidget.VerticalHeaderFormat();

/**
  * @name headerVisible
  * @memberOf QCalendarWidget.prototype
  * @type Boolean
  */
QCalendarWidget.prototype.headerVisible = new Boolean();

/**
  * @name navigationBarVisible
  * @memberOf QCalendarWidget.prototype
  * @type Boolean
  */
QCalendarWidget.prototype.navigationBarVisible = new Boolean();

/**
  * @name dateEditEnabled
  * @memberOf QCalendarWidget.prototype
  * @type Boolean
  */
QCalendarWidget.prototype.dateEditEnabled = new Boolean();

/**
  * @name dateEditAcceptDelay
  * @memberOf QCalendarWidget.prototype
  * @type Numeric
  */
QCalendarWidget.prototype.dateEditAcceptDelay = new Numeric();


