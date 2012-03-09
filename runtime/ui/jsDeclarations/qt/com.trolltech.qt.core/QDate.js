/**
  * @name QDate
  * @constructor
  */
function QDate(){return undefined;};

/**
  * @name QDate^1
  * @constructor
  * @param {Numeric} y
  * @param {Numeric} m
  * @param {Numeric} d
  */
function QDate(y, m, d){return undefined;};

/**
  * @name currentDate
  * @function
  * @memberOf QDate
  * @returns {QDate}
  */
QDate.currentDate = function(){return new QDate();};

/**
  * @name fromJulianDay
  * @function
  * @memberOf QDate
  * @param {Numeric} jd
  * @returns {QDate}
  */
QDate.fromJulianDay = function(jd){return new QDate();};

/**
  * @name fromString
  * @function
  * @memberOf QDate
  * @param {String} s
  * @param {QDate.DateFormat} f
  * @returns {QDate}
  */
QDate.fromString = function(s, f){return new QDate();};

/**
  * @name gregorianToJulian
  * @function
  * @memberOf QDate
  * @param {Numeric} y
  * @param {Numeric} m
  * @param {Numeric} d
  * @returns {Numeric}
  */
QDate.gregorianToJulian = function(y, m, d){return new Numeric();};

/**
  * @name isLeapYear
  * @function
  * @memberOf QDate
  * @param {Numeric} year
  * @returns {Boolean}
  */
QDate.isLeapYear = function(year){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QDate
  * @param {Numeric} y
  * @param {Numeric} m
  * @param {Numeric} d
  * @returns {Boolean}
  */
QDate.isValid = function(y, m, d){return new Boolean();};

/**
  * @name longDayName
  * @function
  * @memberOf QDate
  * @param {Numeric} weekday
  * @returns {String}
  */
QDate.longDayName = function(weekday){return new String();};

/**
  * @name longMonthName
  * @function
  * @memberOf QDate
  * @param {Numeric} month
  * @returns {String}
  */
QDate.longMonthName = function(month){return new String();};

/**
  * @name shortDayName
  * @function
  * @memberOf QDate
  * @param {Numeric} weekday
  * @returns {String}
  */
QDate.shortDayName = function(weekday){return new String();};

/**
  * @name shortMonthName
  * @function
  * @memberOf QDate
  * @param {Numeric} month
  * @returns {String}
  */
QDate.shortMonthName = function(month){return new String();};

/**
  * @default 0
  * @constant
  * @memberOf QDate
  * @name DateFormat
  * @see QDate#MonthNameType
  * @type Number
  */
QDate.DateFormat = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QDate
  * @name StandaloneFormat
  * @see QDate#MonthNameType
  * @type Number
  */
QDate.StandaloneFormat = 0x1;

/**
  * @constructor 
  * @memberOf QDate
  * @name MonthNameType
  */
QDate.MonthNameType = function(value){;};



/**
  * @name addDays
  * @function
  * @memberOf QDate.prototype
  * @param {Numeric} days
  * @returns {QDate}
  */
QDate.prototype.addDays = function(days){return new QDate();};

/**
  * @name addMonths
  * @function
  * @memberOf QDate.prototype
  * @param {Numeric} months
  * @returns {QDate}
  */
QDate.prototype.addMonths = function(months){return new QDate();};

/**
  * @name addYears
  * @function
  * @memberOf QDate.prototype
  * @param {Numeric} years
  * @returns {QDate}
  */
QDate.prototype.addYears = function(years){return new QDate();};

/**
  * @name day
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.day = function(){return new Numeric();};

/**
  * @name dayOfWeek
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.dayOfWeek = function(){return new Numeric();};

/**
  * @name dayOfYear
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.dayOfYear = function(){return new Numeric();};

/**
  * @name daysInMonth
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.daysInMonth = function(){return new Numeric();};

/**
  * @name daysInYear
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.daysInYear = function(){return new Numeric();};

/**
  * @name daysTo
  * @function
  * @memberOf QDate.prototype
  * @param {QDate} arg__1
  * @returns {Numeric}
  */
QDate.prototype.daysTo = function(arg__1){return new Numeric();};

/**
  * @name getDate
  * @function
  * @memberOf QDate.prototype
  * @param {Numeric} year
  * @param {Numeric} month
  * @param {Numeric} day
  * @returns {undefined}
  */
QDate.prototype.getDate = function(year, month, day){return undefined;};

/**
  * @name isNull
  * @function
  * @memberOf QDate.prototype
  * @returns {Boolean}
  */
QDate.prototype.isNull = function(){return new Boolean();};

/**
  * @name isValid
  * @function
  * @memberOf QDate.prototype
  * @returns {Boolean}
  */
QDate.prototype.isValid = function(){return new Boolean();};

/**
  * @name month
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.month = function(){return new Numeric();};

/**
  * @name operator_equal
  * @function
  * @memberOf QDate.prototype
  * @param {QDate} other
  * @returns {Boolean}
  */
QDate.prototype.operator_equal = function(other){return new Boolean();};

/**
  * @name operator_less
  * @function
  * @memberOf QDate.prototype
  * @param {QDate} other
  * @returns {Boolean}
  */
QDate.prototype.operator_less = function(other){return new Boolean();};

/**
  * @name readFrom
  * @function
  * @memberOf QDate.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QDate.prototype.readFrom = function(arg__1){return undefined;};

/**
  * @name setDate
  * @function
  * @memberOf QDate.prototype
  * @param {Numeric} year
  * @param {Numeric} month
  * @param {Numeric} day
  * @returns {Boolean}
  */
QDate.prototype.setDate = function(year, month, day){return new Boolean();};

/**
  * @name toJulianDay
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.toJulianDay = function(){return new Numeric();};

/**
  * @name toString
  * @function
  * @memberOf QDate.prototype
  * @param {QDate.DateFormat} f
  * @returns {String}
  */
QDate.prototype.toString = function(f){return new String();};

/**
  * @name weekNumber
  * @function
  * @memberOf QDate.prototype
  * @param {Numeric} yearNum
  * @returns {Numeric}
  */
QDate.prototype.weekNumber = function(yearNum){return new Numeric();};

/**
  * @name writeTo
  * @function
  * @memberOf QDate.prototype
  * @param {QDataStream} arg__1
  * @returns {undefined}
  */
QDate.prototype.writeTo = function(arg__1){return undefined;};

/**
  * @name year
  * @function
  * @memberOf QDate.prototype
  * @returns {Numeric}
  */
QDate.prototype.year = function(){return new Numeric();};

