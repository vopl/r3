/**
  * @namespace QtConcurrent from package com.trolltech.qt.core
  */
var QtConcurrent = {};

/**
  * @default 0x1
  * @constant
  * @memberOf QtConcurrent
  * @name UnorderedReduce
  * @see QtConcurrent#ReduceOptions
  * @see QtConcurrent#ReduceOption
  * @type Number
  */
QtConcurrent.UnorderedReduce = 0x1;

/**
  * @default 0x2
  * @constant
  * @memberOf QtConcurrent
  * @name OrderedReduce
  * @see QtConcurrent#ReduceOptions
  * @see QtConcurrent#ReduceOption
  * @type Number
  */
QtConcurrent.OrderedReduce = 0x2;

/**
  * @default 0x4
  * @constant
  * @memberOf QtConcurrent
  * @name SequentialReduce
  * @see QtConcurrent#ReduceOptions
  * @see QtConcurrent#ReduceOption
  * @type Number
  */
QtConcurrent.SequentialReduce = 0x4;

/**
  * @constructor 
  * @memberOf QtConcurrent
  * @name ReduceOption
  */
QtConcurrent.ReduceOption = function(value){;};

/**
  * @constructor 
  * @memberOf QtConcurrent
  * @name ReduceOptions
  */
QtConcurrent.ReduceOptions = function(value1, value2 /*, ...*/){;};


/**
  * @default 0x0
  * @constant
  * @memberOf QtConcurrent
  * @name ThrottleThread
  * @see QtConcurrent#ThreadFunctionResult
  * @type Number
  */
QtConcurrent.ThrottleThread = 0x0;

/**
  * @default 0x1
  * @constant
  * @memberOf QtConcurrent
  * @name ThreadFinished
  * @see QtConcurrent#ThreadFunctionResult
  * @type Number
  */
QtConcurrent.ThreadFinished = 0x1;

/**
  * @constructor 
  * @memberOf QtConcurrent
  * @name ThreadFunctionResult
  */
QtConcurrent.ThreadFunctionResult = function(value){;};



