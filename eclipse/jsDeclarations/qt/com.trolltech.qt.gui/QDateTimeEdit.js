/**
  * @name QDateTimeEdit
  * @constructor
  * @extends QAbstractSpinBox
  * @param {QWidget} parent
  */
function QDateTimeEdit(parent){return undefined;};

/**
  * @name QDateTimeEdit^1
  * @constructor
  * @extends QAbstractSpinBox
  * @param {QDate} d
  * @param {QWidget} parent
  */
function QDateTimeEdit(d, parent){return undefined;};

/**
  * @name QDateTimeEdit^2
  * @constructor
  * @extends QAbstractSpinBox
  * @param {QDateTime} dt
  * @param {QWidget} parent
  */
function QDateTimeEdit(dt, parent){return undefined;};

/**
  * @name QDateTimeEdit^3
  * @constructor
  * @extends QAbstractSpinBox
  * @param {QTime} t
  * @param {QWidget} parent
  */
function QDateTimeEdit(t, parent){return undefined;};

QDateTimeEdit.prototype = new QAbstractSpinBox();

/**
  * @default 0x0000
  * @constant
  * @memberOf QDateTimeEdit
  * @name NoSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.NoSection = 0x0;

/**
  * @default 0x0001
  * @constant
  * @memberOf QDateTimeEdit
  * @name AmPmSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.AmPmSection = 0x1;

/**
  * @default 0x0002
  * @constant
  * @memberOf QDateTimeEdit
  * @name MSecSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.MSecSection = 0x2;

/**
  * @default 0x0004
  * @constant
  * @memberOf QDateTimeEdit
  * @name SecondSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.SecondSection = 0x4;

/**
  * @default 0x0008
  * @constant
  * @memberOf QDateTimeEdit
  * @name MinuteSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.MinuteSection = 0x8;

/**
  * @default 0x0010
  * @constant
  * @memberOf QDateTimeEdit
  * @name HourSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.HourSection = 0x10;

/**
  * @default AmPmSection|MSecSection|SecondSection|MinuteSection|HourSection
  * @constant
  * @memberOf QDateTimeEdit
  * @name TimeSections_Mask
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.TimeSections_Mask = 0x1f;

/**
  * @default 0x0100
  * @constant
  * @memberOf QDateTimeEdit
  * @name DaySection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.DaySection = 0x100;

/**
  * @default 0x0200
  * @constant
  * @memberOf QDateTimeEdit
  * @name MonthSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.MonthSection = 0x200;

/**
  * @default 0x0400
  * @constant
  * @memberOf QDateTimeEdit
  * @name YearSection
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.YearSection = 0x400;

/**
  * @default DaySection|MonthSection|YearSection
  * @constant
  * @memberOf QDateTimeEdit
  * @name DateSections_Mask
  * @see QDateTimeEdit#Sections
  * @see QDateTimeEdit#Section
  * @type Number
  */
QDateTimeEdit.DateSections_Mask = 0x700;

/**
  * @constructor 
  * @memberOf QDateTimeEdit
  * @name Section
  */
QDateTimeEdit.Section = function(value){;};

/**
  * @constructor 
  * @memberOf QDateTimeEdit
  * @name Sections
  */
QDateTimeEdit.Sections = function(value1, value2 /*, ...*/){;};


/**
  * @name calendarWidget
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {QCalendarWidget}
  */
QDateTimeEdit.prototype.calendarWidget = function(){return new QCalendarWidget();};

/**
  * @name clearMaximumDate
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {undefined}
  */
QDateTimeEdit.prototype.clearMaximumDate = function(){return undefined;};

/**
  * @name clearMaximumDateTime
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {undefined}
  */
QDateTimeEdit.prototype.clearMaximumDateTime = function(){return undefined;};

/**
  * @name clearMaximumTime
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {undefined}
  */
QDateTimeEdit.prototype.clearMaximumTime = function(){return undefined;};

/**
  * @name clearMinimumDate
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {undefined}
  */
QDateTimeEdit.prototype.clearMinimumDate = function(){return undefined;};

/**
  * @name clearMinimumDateTime
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {undefined}
  */
QDateTimeEdit.prototype.clearMinimumDateTime = function(){return undefined;};

/**
  * @name clearMinimumTime
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @returns {undefined}
  */
QDateTimeEdit.prototype.clearMinimumTime = function(){return undefined;};

/**
  * @name sectionAt
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {Numeric} index
  * @returns {QDateTimeEdit.Section}
  */
QDateTimeEdit.prototype.sectionAt = function(index){return new QDateTimeEdit.Section();};

/**
  * @name sectionText
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {QDateTimeEdit.Section} section
  * @returns {String}
  */
QDateTimeEdit.prototype.sectionText = function(section){return new String();};

/**
  * @name setCalendarWidget
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {QCalendarWidget} calendarWidget
  * @returns {undefined}
  */
QDateTimeEdit.prototype.setCalendarWidget = function(calendarWidget){return undefined;};

/**
  * @name setDateRange
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {QDate} min
  * @param {QDate} max
  * @returns {undefined}
  */
QDateTimeEdit.prototype.setDateRange = function(min, max){return undefined;};

/**
  * @name setDateTimeRange
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {QDateTime} min
  * @param {QDateTime} max
  * @returns {undefined}
  */
QDateTimeEdit.prototype.setDateTimeRange = function(min, max){return undefined;};

/**
  * @name setSelectedSection
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {QDateTimeEdit.Section} section
  * @returns {undefined}
  */
QDateTimeEdit.prototype.setSelectedSection = function(section){return undefined;};

/**
  * @name setTimeRange
  * @function
  * @memberOf QDateTimeEdit.prototype
  * @param {QTime} min
  * @param {QTime} max
  * @returns {undefined}
  */
QDateTimeEdit.prototype.setTimeRange = function(min, max){return undefined;};

/**
  * @name dateTime
  * @memberOf QDateTimeEdit.prototype
  * @type QDateTime
  */
QDateTimeEdit.prototype.dateTime = new QDateTime();

/**
  * @name date
  * @memberOf QDateTimeEdit.prototype
  * @type QDate
  */
QDateTimeEdit.prototype.date = new QDate();

/**
  * @name time
  * @memberOf QDateTimeEdit.prototype
  * @type QTime
  */
QDateTimeEdit.prototype.time = new QTime();

/**
  * @name maximumDateTime
  * @memberOf QDateTimeEdit.prototype
  * @type QDateTime
  */
QDateTimeEdit.prototype.maximumDateTime = new QDateTime();

/**
  * @name minimumDateTime
  * @memberOf QDateTimeEdit.prototype
  * @type QDateTime
  */
QDateTimeEdit.prototype.minimumDateTime = new QDateTime();

/**
  * @name maximumDate
  * @memberOf QDateTimeEdit.prototype
  * @type QDate
  */
QDateTimeEdit.prototype.maximumDate = new QDate();

/**
  * @name minimumDate
  * @memberOf QDateTimeEdit.prototype
  * @type QDate
  */
QDateTimeEdit.prototype.minimumDate = new QDate();

/**
  * @name maximumTime
  * @memberOf QDateTimeEdit.prototype
  * @type QTime
  */
QDateTimeEdit.prototype.maximumTime = new QTime();

/**
  * @name minimumTime
  * @memberOf QDateTimeEdit.prototype
  * @type QTime
  */
QDateTimeEdit.prototype.minimumTime = new QTime();

/**
  * @name currentSection
  * @memberOf QDateTimeEdit.prototype
  * @type QDateTimeEdit.Section
  */
QDateTimeEdit.prototype.currentSection = new QDateTimeEdit.Section();

/**
  * @name displayedSections
  * @memberOf QDateTimeEdit.prototype
  * @type QDateTimeEdit.Sections
  */
QDateTimeEdit.prototype.displayedSections = new QDateTimeEdit.Sections();

/**
  * @name displayFormat
  * @memberOf QDateTimeEdit.prototype
  * @type String
  */
QDateTimeEdit.prototype.displayFormat = new String();

/**
  * @name calendarPopup
  * @memberOf QDateTimeEdit.prototype
  * @type Boolean
  */
QDateTimeEdit.prototype.calendarPopup = new Boolean();

/**
  * @name currentSectionIndex
  * @memberOf QDateTimeEdit.prototype
  * @type Numeric
  */
QDateTimeEdit.prototype.currentSectionIndex = new Numeric();

/**
  * @name sectionCount
  * @memberOf QDateTimeEdit.prototype
  * @type Numeric
  */
QDateTimeEdit.prototype.sectionCount = new Numeric();

/**
  * @name timeSpec
  * @memberOf QDateTimeEdit.prototype
  * @type Qt.TimeSpec
  */
QDateTimeEdit.prototype.timeSpec = new Qt.TimeSpec();


