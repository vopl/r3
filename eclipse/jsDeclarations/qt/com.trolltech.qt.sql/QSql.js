/**
  * @namespace QSql from package com.trolltech.qt.sql
  */
var QSql = {};

/**
  * @default 0
  * @constant
  * @memberOf QSql
  * @name HighPrecision
  * @see QSql#NumericalPrecisionPolicy
  * @type Number
  */
QSql.HighPrecision = 0x0;

/**
  * @default 0x01
  * @constant
  * @memberOf QSql
  * @name LowPrecisionInt32
  * @see QSql#NumericalPrecisionPolicy
  * @type Number
  */
QSql.LowPrecisionInt32 = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QSql
  * @name LowPrecisionInt64
  * @see QSql#NumericalPrecisionPolicy
  * @type Number
  */
QSql.LowPrecisionInt64 = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QSql
  * @name LowPrecisionDouble
  * @see QSql#NumericalPrecisionPolicy
  * @type Number
  */
QSql.LowPrecisionDouble = 0x4;

/**
  * @constructor 
  * @memberOf QSql
  * @name NumericalPrecisionPolicy
  */
QSql.NumericalPrecisionPolicy = function(value){;};



/**
  * @default -2
  * @constant
  * @memberOf QSql
  * @name AfterLastRow
  * @see QSql#Location
  * @type Number
  */
QSql.AfterLastRow = 0xfffffffe;

/**
  * @default -1
  * @constant
  * @memberOf QSql
  * @name BeforeFirstRow
  * @see QSql#Location
  * @type Number
  */
QSql.BeforeFirstRow = 0xffffffff;

/**
  * @constructor 
  * @memberOf QSql
  * @name Location
  */
QSql.Location = function(value){;};



/**
  * @default 0x00000001
  * @constant
  * @memberOf QSql
  * @name In
  * @see QSql#ParamType
  * @see QSql#ParamTypeFlag
  * @type Number
  */
QSql.In = 0x1;

/**
  * @default 0x00000002
  * @constant
  * @memberOf QSql
  * @name Out
  * @see QSql#ParamType
  * @see QSql#ParamTypeFlag
  * @type Number
  */
QSql.Out = 0x2;

/**
  * @default In|Out
  * @constant
  * @memberOf QSql
  * @name InOut
  * @see QSql#ParamType
  * @see QSql#ParamTypeFlag
  * @type Number
  */
QSql.InOut = 0x3;

/**
  * @default 0x00000004
  * @constant
  * @memberOf QSql
  * @name Binary
  * @see QSql#ParamType
  * @see QSql#ParamTypeFlag
  * @type Number
  */
QSql.Binary = 0x4;

/**
  * @constructor 
  * @memberOf QSql
  * @name ParamTypeFlag
  */
QSql.ParamTypeFlag = function(value){;};

/**
  * @constructor 
  * @memberOf QSql
  * @name ParamType
  */
QSql.ParamType = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x01
  * @constant
  * @memberOf QSql
  * @name Tables
  * @see QSql#TableType
  * @type Number
  */
QSql.Tables = 0x1;

/**
  * @default 0x02
  * @constant
  * @memberOf QSql
  * @name SystemTables
  * @see QSql#TableType
  * @type Number
  */
QSql.SystemTables = 0x2;

/**
  * @default 0x04
  * @constant
  * @memberOf QSql
  * @name Views
  * @see QSql#TableType
  * @type Number
  */
QSql.Views = 0x4;

/**
  * @default 0xff
  * @constant
  * @memberOf QSql
  * @name AllTables
  * @see QSql#TableType
  * @type Number
  */
QSql.AllTables = 0xff;

/**
  * @constructor 
  * @memberOf QSql
  * @name TableType
  */
QSql.TableType = function(value){;};



